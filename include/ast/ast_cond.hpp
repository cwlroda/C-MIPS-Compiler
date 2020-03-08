#ifndef AST_COND_HPP
#define AST_COND_HPP

#include "ast_node.hpp"

class Return : public Node{
    public:
        Return(nodePtr _expr):
            expr(_expr)
        {}

        virtual void print_C(std::ostream &out) const{
            out << "return";

            if(expr != NULL){
                out << " ";
                expr->print_C(out);
            }

            out << ";";
        }
        virtual void print_MIPS() const{}
        virtual void print_Py() const{}

    private:
        nodePtr expr;
};

#endif