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

    list.InsertAtPosition(2, 15);
    std::cout << "Список після вставлення елемента на позицію 2: ";
    list.Show();

    list.DeleteAtPosition(1);
    std::cout << "Список після видалення елемента з позиції 1: ";
    list.Show();

    auto found = list.Find(20);
    if (found) {
        std::cout << "Знайдений елемент: " << found->data << std::endl;
    }
    else {
        std::cout << "Елемент не знайдено" << std::endl;
    }

    int count = list.Replace(15, 25);
    if (count > 0) {
        std::cout << "Заміна завершена. Заміна елементів: " << count << std::endl;
    }
    else {
        std::cout << "Елемент не знайдений для заміни" << std::endl;
    }

    list.Reverse();
    std::cout << "Перевернутий список: ";
    list.Show();
}
