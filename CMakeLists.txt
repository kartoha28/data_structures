cmake_minimum_required(VERSION 3.29)
project(linked_list)

set(CMAKE_CXX_STANDARD 20)

add_executable(linked_list main.cpp
        SingleNode.h
        DoubleNode.h
        SingleList.h
        SingleList.tpp
        DoubleList.tpp
        DoubleList.h
        Student.cpp
        Student.h
)
