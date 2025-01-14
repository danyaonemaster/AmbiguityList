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

    list.InsertAtPosition(2, 15);
    std::cout << "������ ���� ���������� �������� �� ������� 2: ";
    list.Show();

    list.DeleteAtPosition(1);
    std::cout << "������ ���� ��������� �������� � ������� 1: ";
    list.Show();

    auto found = list.Find(20);
    if (found) {
        std::cout << "��������� �������: " << found->data << std::endl;
    }
    else {
        std::cout << "������� �� ��������" << std::endl;
    }

    int count = list.Replace(15, 25);
    if (count > 0) {
        std::cout << "����� ���������. ����� ��������: " << count << std::endl;
    }
    else {
        std::cout << "������� �� ��������� ��� �����" << std::endl;
    }

    list.Reverse();
    std::cout << "������������ ������: ";
    list.Show();
}
