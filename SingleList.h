//
// Created by vladi on 05.05.2025.
//

#ifndef SINGLELIST_H
#define SINGLELIST_H

#include "SingleNode.h"
#include <iostream>

using namespace single_node;

template <typename T>
class SingleList {
private:
    std::unique_ptr<Node<T>> head;
    int size = 0;

    void checkIndex(int index) const;

public:
    SingleList();

    void insertAtBeginning(const T& value);
    void insertAtEnd(const T& value);
    void insertAtIndex(int index, const T& value);

    void removeFromBeginning();
    void removeFromEnd();
    void removeAtIndex(int index);

    T& operator[](int index);
    const T& operator[](int index) const;

    int getSize() const;
    bool isEmpty() const;
    bool contains(const T& value) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const SingleList<U>& list);
};

#include "SingleList.tpp"


#endif //SINGLELIST_H
