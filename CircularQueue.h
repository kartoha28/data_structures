//
// Created by vladi on 12.05.2025.
//

#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdexcept>

template <typename T>
class CircularQueue {
private:
    T* data;           // Вказівник на масив
    int front;         // Індекс початку черги
    int rear;          // Індекс кінця черги
    int size;          // Поточна кількість елементів
    int capacity;      // Максимальна кількість елементів

public:
    // Конструктор
    CircularQueue(int max_size) : front(0), rear(-1), size(0), capacity(max_size) {
        data = new T[capacity];
    }

    // Деструктор
    ~CircularQueue() {
        delete[] data;
    }

    // Перевірка, чи черга порожня
    bool isEmpty() const {
        return size == 0;
    }

    // Перевірка, чи черга повна
    bool isFull() const {
        return size == capacity;
    }

    // Додавання елемента в чергу
    void enqueue(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        ++size;
    }

    // Видалення елемента з черги та його повернення
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        T value = data[front];
        front = (front + 1) % capacity;
        --size;
        return value;
    }

    // Перегляд першого елемента
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return data[front];
    }
};

#endif //CIRCULARQUEUE_H
