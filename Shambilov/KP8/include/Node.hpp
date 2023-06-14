#ifndef KP8_NODE_HPP
#define KP8_NODE_HPP
#include <iostream>
#include "../include/Node.hpp"
#include "../include/List.hpp"
template<typename T>
class node {
private:
    node<T>* nextNode;
    T data;
public:
    node(const T& = T(), node<T>* = nullptr);
};
#include "../src/Node.cpp"

#endif //KP8_NODE_HPP
