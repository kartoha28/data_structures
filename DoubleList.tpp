//
// Created by vladi on 05.05.2025.
//

#ifndef DOUBLELIST_TPP
#define DOUBLELIST_TPP

#include <stdexcept>

template <typename T>
DoubleList<T>::DoubleList() : head{nullptr}, tail{nullptr}, size{0} {}

template <typename T>
void DoubleList<T>::checkIndex(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
}

template <typename T>
void DoubleList<T>::insertAtBeginning(const T& value) {
    auto newNode = std::make_shared<double_node::Node<T>>(value);
    newNode->next = head;
    if (head) {
        head->previous = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
    ++size;
}

template <typename T>
void DoubleList<T>::insertAtEnd(const T& value) {
    auto newNode = std::make_shared<double_node::Node<T>>(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    ++size;
}

template <typename T>
void DoubleList<T>::insertAtIndex(int index, const T& value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0) {
        insertAtBeginning(value);
    } else if (index == size) {
        insertAtEnd(value);
    } else {
        auto newNode = std::make_shared<double_node::Node<T>>(value);
        auto current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        auto prev = current->previous.lock();
        newNode->next = current;
        newNode->previous = prev;
        prev->next = newNode;
        current->previous = newNode;
        ++size;
    }
}

template <typename T>
void DoubleList<T>::removeFromBeginning() {
    if (!head) throw std::out_of_range("List is empty!");

    head = head->next;
    if (head) {
        head->previous.reset();
    } else {
        tail.reset();
    }
    --size;
}

template <typename T>
void DoubleList<T>::removeFromEnd() {
    if (!tail) throw std::out_of_range("List is empty!");

    auto prev = tail->previous.lock();
    if (prev) {
        prev->next.reset();
        tail = prev;
    } else {
        head.reset();
        tail.reset();
    }
    --size;
}

template <typename T>
void DoubleList<T>::removeAtIndex(int index) {
    checkIndex(index);

    if (index == 0) {
        removeFromBeginning();
    } else if (index == size - 1) {
        removeFromEnd();
    } else {
        auto current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }

        auto prev = current->previous.lock();
        auto next = current->next;

        prev->next = next;
        if (next) next->previous = prev;
        --size;
    }
}

template <typename T>
T& DoubleList<T>::operator[](int index) {
    checkIndex(index);
    auto current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
const T& DoubleList<T>::operator[](int index) const {
    checkIndex(index);
    auto current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}


template <typename T>
bool DoubleList<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
bool DoubleList<T>::contains(const T& value) const {
    auto current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
int DoubleList<T>::getSize() const {
    return size;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const DoubleList<T>& list) {
    auto current = list.head;
    os << "List: ";
    while (current) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

#endif // DOUBLELIST_TPP

