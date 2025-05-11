//
// Created by vladi on 12.05.2025.
//

#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <stdexcept>

template <typename T>
class QueueArray {
private:
    T* data;
    int capacity;
    int size;

public:
    // Конструктор
    QueueArray(int max_size) : capacity(max_size), size(0) {
        data = new T[capacity];
    }

    // Деструктор
    ~QueueArray() {
        delete[] data;
    }

    // Перевірка на порожність
    bool isEmpty() const {
        return size == 0;
    }

    // Перевірка на повність
    bool isFull() const {
        return size == capacity;
    }

    // Додавання елемента в чергу
    void enqueue(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        data[size++] = value;
    }

    // Видалення елемента з черги зі зсувом усіх елементів
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        T frontValue = data[0];
        for (int i = 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        --size;
        return frontValue;
    }

    // Повернення першого елемента
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return data[0];
    }
};

#endif // QUEUEARRAY_H

