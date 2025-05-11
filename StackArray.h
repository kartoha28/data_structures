//
// Created by vladi on 12.05.2025.
//

#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept>

template <typename T>
class StackArray {
private:
    T* stackArray;  // Масив для зберігання елементів
    int top;         // Індекс для верхнього елемента
    int maxSize;     // Максимальний розмір стека

public:
    // Конструктор
    StackArray(int max_size) : maxSize(max_size), top(-1) {
        stackArray = new T[maxSize];  // Виділяємо пам'ять під масив
    }

    // Деструктор
    ~StackArray() {
        delete[] stackArray;  // Звільняємо пам'ять
    }

    // Перевірка на порожність
    bool isEmpty() const {
        return top == -1;  // Якщо top == -1, то стек порожній
    }

    // Перевірка на заповненість
    bool isFull() const {
        return top == maxSize - 1;  // Якщо top == maxSize - 1, стек повний
    }

    // Додавання елемента в стек
    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Stack is full");
        }
        stackArray[++top] = value;  // Збільшуємо top і додаємо елемент
    }

    // Видалення елемента зі стека та його повернення
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return stackArray[top--];  // Повертаємо верхній елемент і зменшуємо top
    }

    // Перегляд верхнього елемента стека
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return stackArray[top];  // Повертаємо верхній елемент
    }
};

#endif //STACKARRAY_H

