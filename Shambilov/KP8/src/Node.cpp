#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T& value, Node<T>* next) {
    this->nextNode = next;
    this->data = value;
}
