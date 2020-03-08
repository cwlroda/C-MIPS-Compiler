#ifndef AST_LIST_HPP
#define AST_LIST_HPP

#include "ast_node.hpp"

class Arg : public Node{
    public:
        Arg(std::string &_type, std::string &_id, nodePtr _next):
            type(_type),
            id(_id),
            next(_next)
        {}

        virtual void print_C(std::ostream &out) const{
            if(next != NULL){
                next->print_C(out);
                out << ", ";
            }

            out << type << " " << id;
        }
        virtual void print_MIPS() const{}
        virtual void print_Py() const{}

    private:
        std::string type;
        std::string id;
        nodePtr next;
};

#endif