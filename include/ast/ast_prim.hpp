#ifndef AST_PRIM_HPP
#define AST_PRIM_HPP

#include "ast_node.hpp"
#include <iostream>

class Var : public Node{
    public:
        Var(std::string &_var): var(_var){}
        virtual void print_C(std::ostream &out) const override{
            out << var;
        }
        virtual void print_MIPS() const override{}
        virtual void print_Py() const override{}

    private:
        std::string var;
};

class Num : public Node{
    public:
        Num(double _val): val(_val){}
        virtual void print_C(std::ostream &out) const override{
            out << val;
        }
        virtual void print_MIPS() const override{}
        virtual void print_Py() const override{}
    private:
        double val;
};

#endif