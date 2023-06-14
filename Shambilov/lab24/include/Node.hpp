#ifndef INC_24LAB_NODE_HPP
#define INC_24LAB_NODE_HPP

class ExpressionTree;

class Node {
    friend class ExpressionTree;

private:
    char data;
    Node* left;
    Node* right;

public:
    Node();
    Node(const char data);
    Node(const char data, Node* left, Node* right);
};

#include "../src/ExpressionTree.cpp"

#endif //INC_24LAB_NODE_HPP
