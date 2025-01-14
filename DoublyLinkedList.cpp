#include <iostream>
#include "DoublyLinkedList.h"

template <typename T>
DoublyLinkedList<T>::Node::Node(T value) : data(value), prev(nullptr), next(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    DeleteAll();
}

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
