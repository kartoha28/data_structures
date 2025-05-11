//
// Created by vladi on 12.05.2025.
//

#ifndef QUEUELIST_H
#define QUEUELIST_H

#include <stdexcept>
#include "DoubleList.h"  // Підключаємо реалізований клас списку

template <typename T>
class QueueList {
private:
    DoubleList<T> list;  // Внутрішнє сховище — двозв’язний список
    int maxSize;         // Максимальна кількість елементів у черзі

public:
    // Конструктор
    QueueList(int max_size) : maxSize(max_size) {}

    // Перевірка, чи черга порожня
    bool isEmpty() const {
        return list.isEmpty();
    }

    // Перевірка, чи черга повна
    bool isFull() const {
        return list.getSize() >= maxSize;
    }

    // Додавання елемента в чергу (в кінець)
    void enqueue(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        list.insertAtEnd(value);
    }

    // Видалення елемента з черги (з початку) і його повернення
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        T frontValue = list[0];
        list.removeFromBeginning();
        return frontValue;
    }

    // Перегляд першого елемента (без видалення)
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return list[0];
    }
};

#endif // QUEUELIST_H

