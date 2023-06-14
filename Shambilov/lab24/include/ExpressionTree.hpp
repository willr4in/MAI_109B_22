#ifndef INC_24LAB_EXPRESSIONTREE_HPP
#define INC_24LAB_EXPRESSIONTREE_HPP
#include "../include/Node.hpp"
#include <iostream>
#include <string>

class ExpressionTree {
private:
    Node* root;

public:
    ExpressionTree();
    ExpressionTree(const std::string& expression);
    ~ExpressionTree();

    Node* getRoot() const;

    void deleteTree(Node* node);
    Node* createTree(const std::string& postfix);
    Node* newNode(char data);
    std::string doPostfix(const std::string& expression);
    void replace(Node* root);

    void printPostfix(Node* root) const;
    void printInfix(Node* root) const;
    void printTree(Node* root, const size_t height = 0) const;
};

#endif //INC_24LAB_EXPRESSIONTREE_HPP
