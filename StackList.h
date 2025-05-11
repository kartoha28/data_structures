//
// Created by vladi on 11.05.2025.
//

#ifndef STACKLIST_H
#define STACKLIST_H

#include "SingleList.h"  // Підключаємо клас однозв'язного списку

template <typename T>
class StackList {
private:
    SingleList<T> list;  // Використовуємо список для реалізації стека
    int maxSize;  // Максимальний розмір стека

public:
    // Конструктор
    StackList(int max_size) : maxSize{max_size} {}

    // Перевірка на порожність
    bool isEmpty() const {
        return list.getSize() == 0;
    }

    // Перевірка на заповненість
    bool isFull() const {
        return list.getSize() >= maxSize;
    }

    // Додавання елемента в стек
    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Stack is full");
        }
        list.insertAtBeginning(value);  // Вставляємо елемент на початок списку (стек)
    }

    // Видалення елемента зі стека та його повернення
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        T topValue = list[0];  // Отримуємо значення верхнього елемента
        list.removeFromBeginning();  // Видаляємо перший елемент (верх стека)
        return topValue;  // Повертаємо значення
    }

    // Перегляд верхнього елемента стека
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return list[0];  // Повертаємо перший елемент списку (верх стека)
    }
};

#endif //STACKLIST_H

