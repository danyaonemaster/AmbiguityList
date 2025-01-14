#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;

    list.AddToHead(10);
    list.AddToTail(20);
    list.AddToTail(30);
    list.AddToHead(5);

    std::cout << "Список після додавання елементів: ";
    list.Show();

    list.DeleteFromHead();
    list.DeleteFromTail();

    std::cout << "Список після видалення елементів: ";
    list.Show();

    list.DeleteAll();
    std::cout << "Список після очищення: ";
    list.Show();
}
