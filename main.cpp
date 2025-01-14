#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;

    list.AddToHead(10);
    list.AddToTail(20);
    list.AddToTail(30);
    list.AddToHead(5);

    std::cout << "������ ���� ��������� ��������: ";
    list.Show();

    list.DeleteFromHead();
    list.DeleteFromTail();

    std::cout << "������ ���� ��������� ��������: ";
    list.Show();

    list.DeleteAll();
    std::cout << "������ ���� ��������: ";
    list.Show();
}
