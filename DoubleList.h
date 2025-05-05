//
// Created by vladi on 05.05.2025.
//

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>
#include "DoubleNode.h"

template <typename T>
class DoubleList {
private:
    std::shared_ptr<double_node::Node<T>> head;
    std::shared_ptr<double_node::Node<T>> tail;
    int size;

    void checkIndex(int index) const;

public:
    DoubleList();

    void insertAtBeginning(const T& value);
    void insertAtEnd(const T& value);
    void insertAtIndex(int index, const T& value);

    void removeFromBeginning();
    void removeFromEnd();
    void removeAtIndex(int index);

    T operator[](int index) const;
    bool isEmpty() const;
    bool contains(const T& value) const;
    int getSize() const;

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DoubleList<U>& list);
};

#include "DoubleList.tpp"

#endif // DOUBLELIST_H
