#include "ast_functions.hpp"

inline void Tab(std::ofstream& out);

/*-------*
| PYTHON |
*--------*/

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
    if(init_declr != NULL){
        init_declr->print_py(out);
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

        Tab(out);

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
        Tab(out);

        un_expr->print_py(out);
        out << "=";
    }

    if(ass_expr != NULL){
        ass_expr->print_py(out);
    }

    if(!context.in_func && !context.in_if && !context.in_while && context.brackets == 0){
        out << std::endl;
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

        cast_expr->print_py(out);
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
        Tab(out);

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
        Tab(out);

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
        Tab(out);
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

    out << std::endl;
}

inline void SelectionStatement::print_py(std::ofstream& out){
    if(ELSE == NULL){
        if(!context.elif_block){
            Tab(out);
            out << "if(";

            context.in_if = true;
            expr->print_py(out);
            context.in_if = false;

            out << "):" << std::endl;
        }

        if(if_state == NULL){
            context.elif_block = false;
            out << "pass" << std::endl;
        }

        if(if_state->get_comp_state() == NULL){
            context.indent++;
            context.elif_block = false;
            if_state->print_py(out);
            out << std::endl;
            context.indent--;
        }

        else{
            context.elif_block = false;
            if_state->print_py(out);
            out << std::endl;
        }
    }

    else{
        if(!context.elif_block){
            Tab(out);
            out << "if(";

            context.in_if = true;
            expr->print_py(out);
            context.in_if = false;

            out << "):" << std::endl;

            if(if_state == NULL){
                context.elif_block = false;
                out << "pass" << std::endl;
            }

            if(if_state->get_comp_state() == NULL){
                context.indent++;
                context.elif_block = false;
                if_state->print_py(out);
                out << std::endl;
                context.indent--;
            }

            else{
                context.elif_block = false;
                if_state->print_py(out);
                out << std::endl;
            }
        }

        if(context.elif_block){
            if(if_state == NULL){
                context.elif_block = false;
                out << "pass" << std::endl;
            }

            if(if_state->get_comp_state() == NULL){
                context.indent++;
                context.elif_block = false;
                if_state->print_py(out);
                out << std::endl;
                context.indent--;
            }

            else{
                context.elif_block = false;
                if_state->print_py(out);
                out << std::endl;
            }
        }

        if(else_state->get_select_state() != NULL){
            context.elif_block = true;
        }

        if(!context.elif_block){
            Tab(out);
            out << "else:" << std::endl;

            context.in_if = true;

            if(else_state == NULL){
                context.elif_block = false;
                out << "pass" << std::endl;
            }

            if(else_state->get_comp_state() == NULL){
                context.indent++;
                context.elif_block = false;
                else_state->print_py(out);
                out << std::endl;
                context.indent--;
            }

            else{
                context.elif_block = false;
                else_state->print_py(out);
                out << std::endl;
            }

            context.in_if = false;
        }
    }
}

inline void IterationStatement::print_py(std::ofstream& out){
    out << std::endl;
    context.in_while = true;

    Tab(out);

    out << "while(";
    expr->print_py(out);
    out << "):" << std::endl;

    if(state == NULL){
        context.elif_block = false;
        out << "pass" << std::endl;
    }

    if(state->get_comp_state() == NULL){
        context.indent++;
        context.elif_block = false;
        state->print_py(out);
        out << std::endl;
        context.indent--;
    }

    else{
        context.elif_block = false;
        state->print_py(out);
        out << std::endl;
    }

    context.in_while = false;
}

inline void JumpStatement::print_py(std::ofstream& out){
    Tab(out);

    if(type != NULL){
        out << *type << " ";
    }

    if(expr != NULL){
        expr->print_py(out);
    }
}

/*-----*
| MISC |
*-----*/

inline void Tab(std::ofstream& out){
    for(int i=0; i<context.indent; i++){
        out << "\t";
    }
}

/*-----*
| MIPS |
*-----*/

/*-------------*
| DECLARATIONS |
*-------------*/
inline void TranslationUnit::print_asm_main(std::string& filename) const{
    std::ofstream outfile;
    outfile.open(filename.c_str());

    if(!outfile.is_open()){
        std::cerr << "Error opening " << filename << "!" << std::endl;
        exit(EXIT_FAILURE);
    }

    outfile << "\t.file\t1 " << "\"" << filename << "\"" << std::endl;
    outfile << "\t.section .mdebug.abi32" << std::endl;
    outfile << "\t.previous" << std::endl;
    outfile << "\t.nan\tlegacy" << std::endl;
    outfile << "\t.module fp=xx" << std::endl;
    outfile << "\t.module nooddspreg" << std::endl;
    outfile << "\t.abicalls" << std::endl;

    if(trans_unit != NULL){
        trans_unit->print_asm(outfile);
    }

    if(ext_decl != NULL){
        ext_decl->print_asm(outfile);
    }

    outfile.close();
}

inline void TranslationUnit::print_asm(std::ofstream& out){
    if(trans_unit != NULL){
        trans_unit->print_asm(out);
    }
    if(ext_decl != NULL){
        ext_decl->print_asm(out);
    }
}

inline void ExternalDeclaration::print_asm(std::ofstream& out){
    if(decl != NULL){
        context.is_GlobalVar = true;

        out << std::endl;
        decl->print_asm(out);
        out << "\t.data" << std::endl;
        out << "\t.globl\t" << context.GlobalDirectDeclarator << std::endl;
        out << "\t.align\t2" << std::endl;
        out << "\t.type\t" << context.GlobalDirectDeclarator << ", @object" << std::endl;
        out << "\t.size\t" << context.GlobalDirectDeclarator << ", ";

        if(context.what_typeSpec == "char"){
            out << "1";
        }
        else{
            out << "4";
        }
        out << std::endl;

        out << context.GlobalDirectDeclarator << ":" << std::endl;
        if(context.what_typeSpec == "char"){
            out << "\t.byte\t";
        }
        else{
            out << "\t.word\t";
        }
        out << context.GlobalVarNum << std::endl;

        context.is_GlobalVar = false;
        context.what_typeSpec = "0";
        context.GlobalDirectDeclarator = "0";
    }

    else if(func_def != NULL){
        context.in_func = true;
        out << std::endl;
        func_def->print_asm(out);
        
        context.FuncName = "0";
        context.in_func = false;
    }
}

inline void FunctionDefinition::print_asm(std::ofstream& out){
    if(decl_spec != NULL){
        decl_spec->print_asm(out);
    }

    if(declr != NULL){
        declr->print_asm(out);
    }
    out << "\t.text" << std::endl;
    out << "\t.align\t2" << std::endl;
    out << "\t.globl\t" << context.FuncName << std::endl;
    out << "\t.set\tnomips16" << std::endl;
    out << "\t/set\tnomicromips" << std::endl;
    out << "\t.ent\t" << context.FuncName << std::endl;
    out << "\t.type\t" << context.FuncName << ", @function" << std::endl;

    out << context.FuncName << ":" << std::endl;

    out << "\taddiu\t$sp,$sp,-48" << std::endl;
    out << "\tsw\t$31,44($sp)" << std::endl;
    out << "\tsw\t$fp,40($sp)" << std::endl;
    out << "\tmove $fp,$sp" << std::endl;


    /* if(decl_list != NULL){
        decl_list->print_asm(out);
    } */

    /* Compound statement */

    out << "\tmove\t$sp,$fp" << std::endl;
    out << "\tlw\t$31,44($sp)" << std::endl;
    out << "\tlw\t$fp,40($sp)" << std::endl;
    out << "\taddiu\t$sp,$sp,48" << std::endl;
    out << "\tj\t$31" << std::endl;
    out << "\tnop" << std::endl;

}

inline void Declaration::print_asm(std::ofstream& out){
    decl_spec -> print_asm(out);
    if(init_declr != NULL){
        init_declr->print_asm(out);
    }
}

inline void DeclarationSpecifier::print_asm(std::ofstream& out){
    type_spec -> print_asm(out);
    if(decl_spec!=NULL){
        decl_spec->print_asm(out);
    }
}

inline void TypeSpecifier::print_asm(std::ofstream& out){
    // if(struct_spec != NULL){
    //     struct_spec -> print_asm(out);
    // }
    // else if(enum_spec != NULL){
    //     enum_spec -> print_asm(out);
    // }
    // else{
        context.what_typeSpec = *type;
    //}
}

inline void InitDeclarator::print_asm(std::ofstream& out){
    declr->print_asm(out);

    if(init != NULL){
        init->print_asm(out);
    }
    out << std::endl;
}

inline void Declarator::print_asm(std::ofstream& out){
    if(dir_declr != NULL){
        dir_declr->print_asm(out);
    }
}

inline void DirectDeclarator::print_asm(std::ofstream& out){
    if(dir_declr != NULL){
        dir_declr->print_asm(out);
    }

    if(context.is_GlobalVar == true){
        context.GlobalDirectDeclarator = *iden;
    }

    if(context.in_func == true && iden != NULL){
        context.FuncName = *iden;
    }
}

inline void Initializer::print_asm(std::ofstream& out){
    if(init_list != NULL){
        init_list -> print_asm(out);
    }
    if(assign_expr != NULL){
        assign_expr -> print_asm(out);
    }
}

inline void InitializerList::print_asm(std::ofstream& out){
    if(init_list != NULL){
        init_list->print_py(out);
    }

    if(init != NULL){
        init->print_py(out);
    }
}

inline void AssignmentExpr::print_asm(std::ofstream& out){
    if(cond_expr != NULL){
        cond_expr->print_asm(out);
    }
    
    // if(un_expr != NULL){
    //     un_expr -> print_asm(out);
    //     ass_op -> print_asm(out);
    //     ass_expr -> print_asm(out);
    // }
}

inline void UnaryExpr::print_asm(std::ofstream& out){
    if(post_expr != NULL){
        post_expr->print_asm(out);
    }
    // else{
    //     if(un_op != NULL){
    //         std::string type = un_op->print_asm(out);
    //         cast_expr->print_asm(out);
    //     }
    //     if(type_name != NULL){
    //         // type_name->print_asm(out);
    //     }
    // }
}

inline void PostfixExpr::print_asm(std::ofstream& out){
    if(pri_expr != NULL){
        pri_expr->print_asm(out);
    }
}

inline void PrimaryExpr::print_asm(std::ofstream& out){
    if(constant != NULL){
        if(context.is_GlobalVar == true){
            context.GlobalVarNum = stoi(*constant);
        }
    }
}

inline void ConditionalExpr::print_asm(std::ofstream& out){
    log_or_expr -> print_asm(out);

    // if(expr != NULL){
    //     expr->print_asm(out);
    //     cond_expr->print_asm(out);
    // }
}

inline void LogicalOrExpr::print_asm(std::ofstream& out){
    log_and_expr -> print_asm(out);
}

inline void LogicalAndExpr::print_asm(std::ofstream& out){
    incl_or_expr -> print_asm(out);
}

inline void InclusiveOrExpr::print_asm(std::ofstream& out){
    excl_or_expr -> print_asm(out);
}

inline void ExclusiveOrExpr::print_asm(std::ofstream& out){
    and_expr -> print_asm(out);
}

inline void AndExpr::print_asm(std::ofstream& out){
    equal_expr -> print_asm(out);
}

inline void EqualityExpr::print_asm(std::ofstream& out){
    rel_expr -> print_asm(out);
}

inline void RelationalExpr::print_asm(std::ofstream& out){
    shift_expr -> print_asm(out);
}

inline void ShiftExpr::print_asm(std::ofstream& out){
    add_expr -> print_asm(out);
}

inline void AdditiveExpr::print_asm(std::ofstream& out){
    mul_expr -> print_asm(out);
}

inline void MultiplicativeExpr::print_asm(std::ofstream& out){
    cast_expr -> print_asm(out);
}

inline void CastExpr::print_asm(std::ofstream& out){
    un_expr -> print_asm(out);
}