//
// Created by vladi on 05.05.2025.
//

#ifndef SINGLENODE_H
#define SINGLENODE_H

#include <memory>

namespace single_node {
    template <typename T>
    struct Node {
        T data;
        std::unique_ptr<Node<T>> next;

        Node(const T& value) : data{value}, next{nullptr} {}
    };
}


#endif //SINGLENODE_H
