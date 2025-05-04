//
// Created by vladi on 05.05.2025.
//

#ifndef DOUBLENODE_H
#define DOUBLENODE_H

#include <memory>

namespace double_node {
    template <typename T>
    struct Node {
        T data;
        std::shared_ptr<Node<T>> next;
        std::weak_ptr<Node<T>> previous;

        Node(const T& value) : data{value}, next{nullptr}, previous{} {}
    };
}

#endif //DOUBLENODE_H
