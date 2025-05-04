//
// Created by vladi on 05.05.2025.
//

#ifndef SINGLELIST_TPP
#define SINGLELIST_TPP

// SingleList.tpp
#include <stdexcept>

using namespace single_node;

// Constructor
template <typename T>
SingleList<T>::SingleList() = default;

// Check index
template <typename T>
void SingleList<T>::checkIndex(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
}

// Insert at beginning
template <typename T>
void SingleList<T>::insertAtBeginning(const T& value) {
    auto newNode = std::make_unique<Node<T>>(value);
    newNode->next = std::move(head);
    head = std::move(newNode);
    ++size;
}

// Insert at end
template <typename T>
void SingleList<T>::insertAtEnd(const T& value) {
    auto newNode = std::make_unique<Node<T>>(value);
    if (!head) {
        head = std::move(newNode);
    } else {
        Node<T>* current = head.get();
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
    }
    ++size;
}

// Insert at index
template <typename T>
void SingleList<T>::insertAtIndex(int index, const T& value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index out of range");
    }
    if (index == 0) {
        insertAtBeginning(value);
    } else if (index == size) {
        insertAtEnd(value);
    } else {
        auto newNode = std::make_unique<Node<T>>(value);
        Node<T>* current = head.get();
        for (int i = 0; i < index - 1; ++i) {
            current = current->next.get();
        }
        newNode->next = std::move(current->next);
        current->next = std::move(newNode);
        ++size;
    }
}

// Remove from beginning
template <typename T>
void SingleList<T>::removeFromBeginning() {
    if (!head) {
        throw std::out_of_range("List is empty!");
    }
    head = std::move(head->next);
    --size;
}

// Remove from end
template <typename T>
void SingleList<T>::removeFromEnd() {
    if (!head) {
        throw std::out_of_range("List is empty!");
    }
    if (!head->next) {
        head.reset();
    } else {
        Node<T>* current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
    }
    --size;
}

// Remove at index
template <typename T>
void SingleList<T>::removeAtIndex(int index) {
    checkIndex(index);
    if (index == 0) {
        removeFromBeginning();
    } else if (index == size - 1) {
        removeFromEnd();
    } else {
        Node<T>* current = head.get();
        for (int i = 0; i < index - 1; ++i) {
            current = current->next.get();
        }
        current->next = std::move(current->next->next);
        --size;
    }
}

// Operator []
template <typename T>
T& SingleList<T>::operator[](int index) {
    checkIndex(index);
    Node<T>* current = head.get();
    for (int i = 0; i < index; ++i) {
        current = current->next.get();
    }
    return current->data;
}

template <typename T>
const T& SingleList<T>::operator[](int index) const {
    checkIndex(index);
    Node<T>* current = head.get();
    for (int i = 0; i < index; ++i) {
        current = current->next.get();
    }
    return current->data;
}

// Size
template <typename T>
int SingleList<T>::getSize() const {
    return size;
}

// Is empty
template <typename T>
bool SingleList<T>::isEmpty() const {
    return size == 0;
}

// Contains
template <typename T>
bool SingleList<T>::contains(const T& value) const {
    Node<T>* current = head.get();
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next.get();
    }
    return false;
}

// Print
template <typename T>
std::ostream& operator<<(std::ostream& os, const SingleList<T>& list) {
    os << "List data: ";
    auto current = list.head.get();
    while (current) {
        os << current->data << " ";
        current = current->next.get();
    }
    os << "\n";
    return os;
}


#endif //SINGLELIST_TPP
