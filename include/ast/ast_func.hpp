#ifndef AST_FUNC_HPP
#define AST_FUNC_HPP

#include "ast_node.hpp"

class Top : public Node{
    public:
        Top(nodePtr _curr, nodePtr _next):
            curr(_curr),
            next(_next)
        {}

        virtual void print_C(std::ostream &out) const{
            if(next != NULL){
                next->print_C(out);
                out << std::endl;
            }

            curr->print_C(out);
        }

        virtual void print_MIPS() const{}
        virtual void print_Py() const{}

    private:
        nodePtr curr;
        nodePtr next;
};

class FuncDef : public Node{
    public:
        FuncDef(const std::string &_type, const std::string &_id, nodePtr _params, nodePtr _body):
            type(_type),
            id(_id),
            params(_params),
            body(_body)
        {}

        virtual void print_C(std::ostream &out) const{
            out << type << " " << id << "(";

            if(params != NULL){
                params->print_C(out);
            }

            out << ")" << "{" << std::endl;

            if(body != NULL){
                body->print_C(out);
                out << std::endl;
            }

            out << "}" << std::endl;
        }
        virtual void print_MIPS() const{}
        virtual void print_Py() const{}

    private:
        std::string type;
        std::string id;
        nodePtr params;
        nodePtr body;
};

class FuncDecl : public Node{
    public:
        FuncDecl(const std::string &_type, const std::string &_id, nodePtr _params):
            type(_type),
            id(_id),
            params(_params)
        {std::cout << "hi" << std::endl;}

        virtual void print_C(std::ostream &out) const{
            out << type << " " << id << "(";

            if(params != NULL){
                params->print_C(out);
            }

            out << ")" << ";" << std::endl;
        }
        virtual void print_MIPS() const{}
        virtual void print_Py() const{}

    private:
        std::string type;
        std::string id;
        nodePtr params;
};

#endif