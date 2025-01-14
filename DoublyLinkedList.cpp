#include "DoublyLinkedList.h"

template <typename T>
void DoublyLinkedList<T>::AddToHead(T value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::AddToTail(T value) {
    Node* newNode = new Node(value);
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromHead() {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromTail() {
    if (tail == nullptr) return;

    Node* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    }
    else {
        head = nullptr;
    }
    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAll() {
    while (head != nullptr) {
        DeleteFromHead();
    }
}

template <typename T>
void DoublyLinkedList<T>::Show() const {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoublyLinkedList<T>::InsertAtPosition(int position, T value) {
    if (position < 0) return;
    Node* newNode = new Node(value);
    Node* temp = head;
    int index = 0;

    while (temp != nullptr && index < position) {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr) {
        AddToTail(value);
    }
    else {
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != nullptr) {
            temp->prev->next = newNode;
        }
        else {
            head = newNode;
        }
        temp->prev = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::DeleteAtPosition(int position) {
    if (position < 0 || head == nullptr) return;
    Node* temp = head;
    int index = 0;

    while (temp != nullptr && index < position) {
        temp = temp->next;
        index++;
    }

    if (temp != nullptr) {
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        else {
            tail = temp->prev;
        }
        delete temp;
    }
}

template <typename T>
typename DoublyLinkedList<T>::Node* DoublyLinkedList<T>::Find(T value) const {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
int DoublyLinkedList<T>::Replace(T oldValue, T newValue) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == oldValue) {
            temp->data = newValue;
            count++;
        }
        temp = temp->next;
    }
    return count > 0 ? count : -1;
}

template <typename T>
void DoublyLinkedList<T>::Reverse() {
    Node* temp = nullptr;
    Node* current = head;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
}

template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
template class DoublyLinkedList<std::string>;

