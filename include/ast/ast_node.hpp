#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <iostream>

class Node{
    public:
        virtual void print_C(std::ostream &out) const{}
        virtual void print_MIPS() const{}
        virtual void print_Py() const{}
};

typedef const Node *nodePtr;

#endif