#ifndef KP8_NODE_HPP
#define KP8_NODE_HPP
#include <iostream>
#include "../include/Node.hpp"
#include "../include/List.hpp"

template<typename T>
class Node {
private:
    Node<T>* nextNode;
    T data;
public:
    Node() = default;
    Node(const T& = T(), Node<T>* = nullptr);
    ~Node() = default;
};

#include "../src/Node.cpp"
#endif //KP8_NODE_HPP
