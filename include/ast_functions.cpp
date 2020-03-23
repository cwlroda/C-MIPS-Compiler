#include "ast_functions.hpp"

#include <iostream>
#include <fstream>

/*-------------*
| DECLARATIONS |
*-------------*/

inline void TranslationUnit::print_py_main(std::string& filename) const{
    std::ofstream outfile;
    outfile.open(filename.c_str());

    if(!outfile.is_open()){
        std::cerr << "Error opening " << filename << "!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if(trans_unit != NULL){
        trans_unit->print_py(outfile);
    }

    if(ext_decl != NULL){
        ext_decl->print_py(outfile);
    }

    if(context.main_func){
        outfile << std::endl << std::endl;
        outfile << "if __name__ == \"__main__\":" << std::endl;
        outfile << "\t" << "import sys" << std::endl;
        outfile << "\t" << "ret=main()" << std::endl;
        outfile << "\t" << "sys.exit(ret)" << std::endl;
    }

    outfile.close();
}

inline void TranslationUnit::print_py(std::ofstream& out){
    if(trans_unit != NULL){
        trans_unit->print_py(out);
    }

    if(ext_decl != NULL){
        ext_decl->print_py(out);
    }
}

inline void ExternalDeclaration::print_py(std::ofstream& out){
    if(decl != NULL){
        out << std::endl;
        decl->print_py(out);
        out << std::endl;
    }

    if(func_def != NULL){
        context.in_func = true;
        out << std::endl;
        func_def->print_py(out);
        out << std::endl;
        context.in_func = false;
    }
}

inline void FunctionDefinition::print_py(std::ofstream& out){
    if(declr != NULL){
        declr->print_py(out, false, true);

        if(decl_list == NULL){
            out << "):" << std::endl;

            std::vector<std::string>::iterator itr = context.GlobalVar.begin();
            while(itr != context.GlobalVar.end()){
                out << "\t" << "global " << *itr << std::endl;
                itr++;
            }
        }
    }

    if(decl_list != NULL){
        context.func_param = true;
        decl_list->print_py(out);
    }

    if(comp_state != NULL){
        comp_state->print_py(out, false, true);
    }
}

inline void Declaration::print_py(std::ofstream& out){
    if(init_declr_list != NULL){
        init_declr_list->print_py(out);
    }
}

inline void DeclarationList::print_py(std::ofstream& out){
    if(decl_list != NULL){
        decl_list->print_py(out);
    }

    context.in_func = false;

    if(decl != NULL){
        decl->print_py(out);
    }
}

inline void InitDeclaratorList::print_py(std::ofstream& out){
    if(init_declr_list != NULL){
        init_declr_list->print_py(out);
    }

    if(init_declr != NULL){
        init_declr->print_py(out);
    }
}

inline void InitDeclarator::print_py(std::ofstream& out){
    if(init == NULL && declr != NULL){
        declr->print_py(out, false, false);
    }

    else{
        if(declr != NULL){
            declr->print_py(out, true, false);
        }

        if(init != NULL){
            init->print_py(out);
        }
    }

    out << std::endl;
}

inline void InitializerList::print_py(std::ofstream& out){
    if(init_list != NULL){
        init_list->print_py(out);
    }

    if(init != NULL){
        init->print_py(out);
    }
}

inline void Initializer::print_py(std::ofstream& out){
    if(init_list != NULL){
        init_list->print_py(out);
    }

    if(assign_expr != NULL){
        assign_expr->print_py(out);
    }
}

inline void Declarator::print_py(std::ofstream& out, bool is_init, bool in_func){
    if(dir_declr != NULL){
        dir_declr->print_py(out, is_init, in_func);
    }
}

inline void DirectDeclarator::print_py(std::ofstream& out, bool is_init, bool in_func){
    if(dir_declr != NULL){
        dir_declr->print_py(out, is_init, in_func);
    }

    if(!in_func){
        if(context.indent == 0 && !context.var_param){
            if(iden != NULL){
                context.GlobalVar.push_back(*iden);
            }
        }

        for(int i=0; i<context.indent; i++){
            out << "\t";
        }

        if(!is_init && !context.var_param){
            if(iden != NULL){
                out << *iden << "=0" << std::endl;
            }
        }

        else if(!context.var_param){
            if(iden != NULL){
                out << *iden << "=";
            }
        }

        else{
            if(iden != NULL){
                out << *iden;
            }

            context.var_param = false;
        }
    }

    else{
        if(iden != NULL){
            if(*iden == "main"){
                context.main_func = true;
            }

            out << "def " << *iden << "(";
        }

        if(param_type_list != NULL){
            param_type_list->print_py(out);
        }

        if(iden_list != NULL){
            iden_list->print_py(out);
        }
    }
}

inline void ParameterTypeList::print_py(std::ofstream& out){
    if(param_list != NULL){
        param_list->print_py(out);
    }
}

inline void ParameterList::print_py(std::ofstream& out){
    if(param_list != NULL){
        param_list->print_py(out);
        out << ",";
    }

    if(param_decl != NULL){
        param_decl->print_py(out);
    }
}

inline void ParameterDeclaration::print_py(std::ofstream& out){
    if(declr != NULL){
        context.var_param = true;
        declr->print_py(out, false, false);
    }
}

/*------------*
| EXPRESSIONS |
*------------*/

inline void Expr::print_py(std::ofstream& out){
    if(expr != NULL){
        expr->print_py(out);
        out << ",";
    }

    if(assign_expr != NULL){
        assign_expr->print_py(out);
    }
}

inline void ConditionalExpr::print_py(std::ofstream& out){
    if(log_or_expr != NULL){
        log_or_expr->print_py(out);
    }
}

inline void LogicalOrExpr::print_py(std::ofstream& out){
    if(log_or_expr != NULL){
        log_or_expr->print_py(out);
        out << " or ";
    }

    if(log_and_expr != NULL){
        log_and_expr->print_py(out);
    }
}

inline void LogicalAndExpr::print_py(std::ofstream& out){
    if(log_and_expr != NULL){
        log_and_expr->print_py(out);
        out << " and ";
    }

    if(incl_or_expr != NULL){
        incl_or_expr->print_py(out);
    }
}

inline void InclusiveOrExpr::print_py(std::ofstream& out){
    if(incl_or_expr != NULL){
        incl_or_expr->print_py(out);
        out << " | ";
    }

    if(excl_or_expr != NULL){
        excl_or_expr->print_py(out);
    }
}

inline void ExclusiveOrExpr::print_py(std::ofstream& out){
    if(excl_or_expr != NULL){
        excl_or_expr->print_py(out);
        out << " ^ ";
    }

    if(and_expr != NULL){
        and_expr->print_py(out);
    }
}

inline void AndExpr::print_py(std::ofstream& out){
    if(and_expr != NULL){
        and_expr->print_py(out);
        out << " & ";
    }

    if(equal_expr != NULL){
        equal_expr->print_py(out);
    }
}

inline void EqualityExpr::print_py(std::ofstream& out){
    if(equal_expr != NULL){
        equal_expr->print_py(out);
        out << " " << *op << " ";
    }

    if(rel_expr != NULL){
        rel_expr->print_py(out);
    }
}

inline void RelationalExpr::print_py(std::ofstream& out){
    if(rel_expr != NULL){
        rel_expr->print_py(out);
        out << " " << *op << " ";
    }

    if(shift_expr != NULL){
        shift_expr->print_py(out);
    }
}

inline void ShiftExpr::print_py(std::ofstream& out){
    if(shift_expr != NULL){
        shift_expr->print_py(out);
        out << " " << *op << " ";
    }

    if(add_expr != NULL){
        add_expr->print_py(out);
    }
}

inline void AdditiveExpr::print_py(std::ofstream& out){
    if(add_expr != NULL){
        add_expr->print_py(out);
        out << " " << *op << " ";
    }

    if(mul_expr != NULL){
        mul_expr->print_py(out);
    }
}

inline void MultiplicativeExpr::print_py(std::ofstream& out){
    if(mul_expr != NULL){
        mul_expr->print_py(out);
        out << " " << *op << " ";
    }

    if(cast_expr != NULL){
        cast_expr->print_py(out);
    }
}

inline void AssignmentExpr::print_py(std::ofstream& out){
    if(cond_expr != NULL){
        cond_expr->print_py(out);
    }

    if(un_expr != NULL){
        for(int i=0; i<context.indent; i++){
            out << "\t";
        }

        un_expr->print_py(out);
        out << "=";
    }

    if(ass_expr != NULL){
        ass_expr->print_py(out);
    }
}

inline void UnaryExpr::print_py(std::ofstream& out){
    if(post_expr != NULL){
        post_expr->print_py(out);
    }

    else if(cast_expr != NULL){
        if(op != NULL){
            out << " " << *op << " ";
        }

        else if(un_op != NULL){
            un_op->print_py(out);
        }
    }
}

inline void UnaryOperator::print_py(std::ofstream& out){
    if(op != NULL){
        out << " " << *op << " ";
    }
}

inline void PostfixExpr::print_py(std::ofstream& out){
    if(pri_expr != NULL){
        pri_expr->print_py(out);

        if(expr != NULL){
            out << "[";
            expr->print_py(out);
            out << "]";
        }
    }

    if(arg_expr_list != NULL){
        for(int i=0; i<context.indent; i++){
            out << "\t";
        }

        post_expr->print_py(out);
        out << "(";
        arg_expr_list->print_py(out);
        out << ")";
        context.in_func = false;
    }

    if(op != NULL){
        out << " " << *op << " ";

        if(iden != NULL){
            out << *iden << " ";
        }
    }

    if(pri_expr == NULL && arg_expr_list == NULL && op == NULL){
        for(int i=0; i<context.indent; i++){
            out << "\t";
        }

        post_expr->print_py(out);
        out << "()";
    }
}

inline void PrimaryExpr::print_py(std::ofstream& out){
    if(iden != NULL){
        out << *iden;
    }

    if(constant != NULL){
        out << *constant;
    }

    if(str_lit != NULL){
        out << " \"" << *str_lit << "\" ";
    }

    if(expr != NULL){
        out << "(";
        context.brackets++;

        expr->print_py(out);

        out << ")";
        context.brackets--;
    }
}

inline void ArgumentExprList::print_py(std::ofstream& out){
    context.in_func = true;

    if(arg_expr_list != NULL){
        arg_expr_list->print_py(out);
        out << ",";
    }

    if(ass_expr != NULL){
        ass_expr->print_py(out);
    }
}

inline void CastExpr::print_py(std::ofstream& out){
    if(un_expr != NULL){
        un_expr->print_py(out);
    }
}

/*-----------*
| STATEMENTS |
*-----------*/

inline void CompoundStatement::print_py(std::ofstream& out, bool is_init, bool in_func){
    context.indent++;

    if(decl_list == NULL && state_list == NULL){
        for(int i=0; i<context.indent; i++){
            out << "\t";
        }

        out << "pass" << std::endl;
    }

    else if(decl_list != NULL && state_list == NULL){
        decl_list->print_py(out);
    }

    else if(decl_list == NULL && state_list != NULL){
        state_list->print_py(out);
    }

    else if(decl_list != NULL && state_list != NULL){
        decl_list->print_py(out);
        state_list->print_py(out);
    }

    context.indent--;
}

inline void StatementList::print_py(std::ofstream& out){
    if(state_list != NULL){
        state_list->print_py(out);
    }

    if(state != NULL){
        state->print_py(out);
    }
}

inline void Statement::print_py(std::ofstream& out){
    if(comp_state != NULL){
        comp_state->print_py(out, false, true);
    }

    if(expr_state != NULL){
        expr_state->print_py(out);
    }

    if(select_state != NULL){
        select_state->print_py(out);
    }

    if(it_state != NULL){
        it_state->print_py(out);
    }

    if(jump_state != NULL){
        jump_state->print_py(out);
    }
}

inline void ExprStatement::print_py(std::ofstream& out){
    if(expr != NULL){
        expr->print_py(out);
    }
}

inline void SelectionStatement::print_py(std::ofstream& out){
    
}

inline void IterationStatement::print_py(std::ofstream& out){
    if(*type == "while"){
        out << std::endl;
        context.in_while = true;

        for(int i=0; i<context.indent; i++){
            out << "\t";
        }

        out << "while(";
        expr->print_py(out);
        out << "):" << std::endl;



        context.in_while = false;
    }
}

inline void JumpStatement::print_py(std::ofstream& out){
    for(int i=0; i<context.indent; i++){
        out << "\t";
    }

    if(type != NULL){
        out << *type << " ";
    }

    if(expr != NULL){
        expr->print_py(out);
    }
}

/*-------*
| OTHERS |
*-------*/

inline void IdentifierList::print_py(std::ofstream& out){
    if(iden_list != NULL){
        iden_list->print_py(out);
        out << ",";
    }

    if(iden != NULL){
        out << *iden;
    }
}

inline void StorageClassSpecifier::print_py(std::ofstream& out){
    if(type != NULL){
        out << *type << " ";
    }
}