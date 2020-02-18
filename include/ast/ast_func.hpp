#ifndef AST_FUNC_HPP
#define AST_FUNC_HPP

#include "ast_node.hpp"

class FuncDef : public Node{
    public:
        FuncDef(const std::string &_type, const std::string &_id, nodePtr _params, nodePtr _body):
            type(_type),
            id(_id),
            params(_params),
            body(_body)
        {}
        virtual void print_C(std::ostream &out) const override{
            out << type << " " << id <<"(";
            if(params != NULL){
                params->print_C(out);
            }
        }
        virtual void print_MIPS() const override{}
        virtual void print_Py() const override{}

    private:
        std::string type;
        std::string id;
        nodePtr params;
        nodePtr body;
}

#endif