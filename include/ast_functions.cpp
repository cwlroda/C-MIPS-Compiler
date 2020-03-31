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

            std::vector<std::string>::iterator itr = context.GlobalVarPy.begin();
            while(itr != context.GlobalVarPy.end()){
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
                context.GlobalVarPy.push_back(*iden);
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

        if(param_list != NULL){
            param_list->print_py(out);
        }
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

inline void ConstantExpr::print_asm(std::ofstream& out){
    cond_expr->print_asm(out);
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
    outfile << "\t.abicalls" << std::endl << std::endl;
    context.enumgen = new WithinEnum;
    context.Enums.insert(std::pair<std::string, WithinEnum>("noname", *context.enumgen));
    
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
        context.is_enum = false;
        decl->print_asm(out);
        if(context.is_enum == false){
            out << "\t.data" << std::endl;
            out << "\t.globl\t" << context.var_iden << std::endl;
            out << "\t.align\t2" << std::endl;
            out << "\t.type\t" << context.var_iden << ", @object" << std::endl;
            out << "\t.size\t" << context.var_iden << ", ";
            int size;
            if(context.what_typeSpec == "char"){
                size = 1;
            }
            else{
                size = 4;
            }

            if(context.is_array){
                size *= context.arr_size;
            }

            out << size << std::endl;
            out << context.var_iden << ":" << std::endl;

            int it = 1;

            if(context.is_array){
                it = context.arr_size;
            }

            for(int i=0; i<it; i++){
                if(context.what_typeSpec == "char"){
                    out << "\t.byte\t";
                }
                else{
                    out << "\t.word\t";
                }

                if(context.is_array){
                    out << context.arr_vals[0] << std::endl;
                    context.arr_vals.erase(context.arr_vals.begin());
                }

                else{
                    out << context.var_val << std::endl;
                }
            }

            
        }

        context.is_array = false;
        context.arr_size = 0;
        context.what_typeSpec = "0";
        context.var_iden = "0";
        context.is_enum = false;
    }

    else if(func_def != NULL){
        context.in_func = true;
        context.got_func_name = false;
        out << std::endl;
        func_def->print_asm(out);

        context.FuncName = "0";
        context.in_func = false;
    }

    out << std::endl;
}
inline int FunctionDefinition::CalcMemoryNeeded(std::vector<int> mv){
    if(mv.size() == 0){
        return 8;
    }
    else{
        std::vector<int>::iterator it = mv.begin();
        int count = 0;
        for(it=mv.begin(); it!=mv.end(); it++){
            if(count%2==1 && *it==2){
                mv.insert(it,88);
                it++;
                count++;
            }
            count++;
        }
    }
    int sizee = ((mv.size()+context.parameterlist)+((mv.size()+context.parameterlist)%2==1))/2;
    return 16+8*sizee;
}
inline void FunctionDefinition::print_asm(std::ofstream& out){
    context.frame_offset_counter = 8;
    if(decl_spec != NULL){
        decl_spec->print_asm(out);
    }
    context.getting_functionname = true;
    declr->print_asm(out);
    context.getting_functionname = false;

    out << "\t.text" << std::endl;
    out << "\t.align\t2" << std::endl;
    out << "\t.globl\t" << context.FuncName << std::endl;
    out << "\t.set\tnomips16" << std::endl;
    out << "\t.set\tnomicromips" << std::endl;
    out << "\t.ent\t" << context.FuncName << std::endl;
    out << "\t.type\t" << context.FuncName << ", @function" << std::endl;

    out << context.FuncName << ":" << std::endl;


    if(decl_list != NULL){
        decl_list->print_asm(out);
    }
    std::vector<int> MemoryAlloc;
    comp_state->alloc_mem(MemoryAlloc);
    context.NeededMem = CalcMemoryNeeded(MemoryAlloc);
    out << "\taddiu\t$sp,$sp,-" << context.NeededMem << std::endl;
    out << "\tsw\t\t$31,"<< context.NeededMem - 4<<"($sp)" << std::endl;
    out << "\tsw\t\t$fp,"<< context.NeededMem - 8 <<"($sp)" << std::endl;
    out << "\tmove\t$fp,$sp" << std::endl;
    for(int i=0; i<context.parameterlist; i++){
        if(i<4){
            out << "\tsw\t\t$" << 4+i << "," << context.NeededMem + 4*i<< "($fp)" << std::endl;
        }
    }


    comp_state -> print_asm(out);
    out << "$" << context.FuncName << "END:" << std::endl;
    out << "\tmove\t$16,$2" << std::endl;
    out << "\tmove\t$sp,$fp" << std::endl;
    out << "\tlw\t\t$31,"<< context.NeededMem - 4<<"($sp)" << std::endl;
    out << "\tlw\t\t$fp,"<< context.NeededMem - 8 <<"($sp)" << std::endl;
    out << "\taddiu\t$sp,$sp," << context.NeededMem << std::endl;
    out << "\tj\t\t$31" << std::endl;
    out << "\tnop" << std::endl << std::endl;

    out << "\t.end" << std::endl << std::endl;

    context.frame_offset_counter = 8;
    context.stack_offset = 0;
    context.parameterlist = 0;
    while(context.LocalVar.size()>0){
        context.LocalVar.erase(context.LocalVar.begin());
    }
}

inline void DeclarationList::print_asm(std::ofstream& out){
    if(decl_list!=NULL){
        decl_list->print_asm(out);
    }
    decl->print_asm(out);
}

inline void Declaration::print_asm(std::ofstream& out){
    decl_spec -> print_asm(out);

    if(init_declr != NULL){
        init_declr->print_asm(out);
    }

    if(context.is_LocalVar){
        Bindings* local_var = new Bindings;
        local_var->type = context.what_typeSpec;
        local_var->id = context.var_iden;
        local_var->value = context.var_val;
        local_var->frame_offset = context.frame_offset_counter;
        
        if(context.what_typeSpec == "int"){
            local_var->size = 4;
        }
        else if(context.what_typeSpec == "char"){
            local_var->size = 1;
        }

        if(context.is_array){
            local_var->is_arr = true;
        }

        std::pair<std::string, Bindings*> var (context.var_iden, local_var);
        context.LocalVar.insert(var);

        int it = 1;

        if(context.is_array){
            it = context.arr_size;
        }

        for(int i=0; i<it; i++){
            if(context.is_array){
                out << "\tli\t\t$2," << context.arr_vals[0] << std::endl;
                context.arr_vals.erase(context.arr_vals.begin());
                out << "\tsw\t\t$2," << context.frame_offset_counter << "($fp)" << std::endl;
            }

            else if(context.empty_var){
                out << "\tsw\t\t$0," << local_var->frame_offset << "($fp)" << std::endl;
            }

            else{
                if(context.is_func){
                    out << "\tmove\t\t$2,$16" << std::endl;
                }
                else if(!context.solving_out.empty() && context.solving_out_constant.back() == ""){
                    if(!context.solving_out.back()->is_parameter){
                        out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                    }
                    else{
                        out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                    }
                    out << "\tnop" << std::endl;
                    context.solving_out.pop_back();
                    context.solving_out_constant.pop_back();
                }
                else if(!context.solving_out_constant.empty()){
                    out << "\tli\t\t$2," << context.solving_out_constant.back() << std::endl;
                    context.solving_out_constant.pop_back();
                }

                out << "\tsw\t\t$2," << local_var->frame_offset << "($fp)" << std::endl;
            }

            context.frame_offset_counter += 4;
        }

        context.empty_var = false;
        context.is_solving = false;
        context.is_firststep = false;

        context.solving_out.clear();
        context.solving_out_constant.clear();
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
    if(enum_spec != NULL){
        context.is_enum = true;
        enum_spec -> print_asm(out);
    }
    else{
        context.what_typeSpec = *type;
    }
}

inline void InitDeclarator::print_asm(std::ofstream& out){
    if(declr != NULL){
        declr->print_asm(out);
    }

    if(init != NULL){
        init->print_asm(out);
    }

    else{
        context.empty_var = true;
    }
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

    if(param_list != NULL){
        context.is_LocalVar = true;
        context.parameterlist = 1;
        std::unordered_map<std::string, int> fn_parameter_list;
        param_list -> print_asm(out, fn_parameter_list);
        std::unordered_map<std::string,int>::iterator fn_p_it;
        
        for(fn_p_it=fn_parameter_list.begin();fn_p_it!=fn_parameter_list.end();fn_p_it++){
            Bindings* local_var = new Bindings;
            local_var->id=fn_p_it->first;
            if(context.NeededMem == 0){
                local_var->frame_offset=fn_p_it->second*4+4;
            }
            else{
                local_var->frame_offset=fn_p_it->second*4;
            }
            
            local_var->is_parameter=true;
            std::pair<std::string, Bindings*> var (fn_p_it->first,local_var);
            
            context.LocalVar.insert(var);
        }
        context.is_LocalVar = false;
    }

    if(context.getting_parametername == true){
        context.parametername = *iden;
        context.getting_parametername = false;
    }
    if(context.getting_functionname == true){
        context.function_name = *iden;
        context.getting_functionname = false;
    }

    if(context.is_LocalVar){
        if(brac_type != NULL){
            context.arr_size = std::stoi(*constant);
            context.is_array = true;
        }

        else{
            context.var_iden = *iden;
        }
    }

    if(context.in_func == true && iden != NULL && !context.got_func_name){
        context.FuncName = *iden;
        context.got_func_name = true;
    }
}

inline void ParameterList::print_asm(std::ofstream& out, std::unordered_map<std::string, int>& fn_parameter_list){
    int temp = 1;
    if(param_list != NULL){
        context.parameterlist++;
        temp = context.parameterlist;
        param_list -> print_asm(out, fn_parameter_list);
    }
    context.getting_parametername = true;
    param_decl->print_asm(out);
    context.getting_parametername = false;
    fn_parameter_list.insert(std::pair<std::string, int>(context.parametername, temp));
}

inline void ParameterDeclaration::print_asm(std::ofstream& out){
    decl_spec->print_asm(out);
    if(declr != NULL){
        declr->print_asm(out);
    }
}

inline void Initializer::print_asm(std::ofstream& out){
    if(init_list != NULL){
        init_list -> print_asm(out);
    }
    if(assign_expr != NULL){
        context.is_solving = true;
        context.is_firststep = true;
        assign_expr -> print_asm(out);
        context.is_firststep = false;
        context.is_solving = false;
    }
}

inline void InitializerList::print_asm(std::ofstream& out){
    if(init_list != NULL){
        init_list->print_asm(out);
    }

    if(init != NULL){
        init->print_asm(out);
    }
}

inline void AssignmentExpr::print_asm(std::ofstream& out){
    if(cond_expr != NULL){
        if(context.in_if || context.in_while){
            context.is_cond = true;
        }

        cond_expr->print_asm(out);
        context.is_cond = false;

        

        if(context.function_call > 0){
            if(context.is_func){}
            else if(context.solving_out_constant.back() == ""){
                if(!context.solving_out.back()->is_parameter){
                    out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                else{
                    out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                context.solving_out.pop_back();
                context.solving_out_constant.pop_back();
                out << "\tnop" << std::endl;
            }
            else{
                out << "\tli\t\t$2," << context.solving_out_constant.back() << std::endl;
                context.solving_out_constant.pop_back();
            }
        }
    }

    else{
        if(un_expr != NULL){
            un_expr->print_asm(out);
        }

        int result_var = context.solving_out.back()->frame_offset;
        std::string op = ass_op->get_type();

        if(ass_expr != NULL){
            ass_expr->print_asm(out);
        }

        if(context.is_func){}

        else if(context.return_are_u_single == true){
            if(context.solving_out_constant.back() == ""){
                out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                context.solving_out.pop_back();
                context.solving_out_constant.pop_back();
            }

            else{
                out << "\tli\t\t$2," << context.solving_out_constant.back() << std::endl;
                context.solving_out_constant.pop_back();
            }
        }
        //context.ExprHelper(out);
        if(context.function_call != 0 && !context.sizeof_type && !context.is_func){
            if(context.is_a_parameter){
                out << "\tlw\t\t$2," << context.parameteroffset <<"($fp)" << std::endl;
                out << "\tnop" << std::endl;
            }

            else{
                out << "\tsw\t\t$2," << context.NeededMem + result_var - 4 << "($fp)" << std::endl;
            }
        }

        else{
            if(op == "+="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\taddu\t$2,$3,$2" << std::endl;
            }
            else if(op == "-="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\tsubu\t$2,$3,$2" << std::endl;
            }
            else if(op == "*="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\tmult\t$3,$2" << std::endl;
                out << "\tmflo\t$2" << std::endl;
            }
            else if(op == "/="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\tbeq\t$2,$0,$L" << context.gen_label << std::endl;
                out << "\tdiv\t$0,$3,$2" << std::endl;
                out << "$L" << context.gen_label << ":" << std::endl;
                out << "\tmfhi\t$2" << std::endl;
                out << "\tmflo\t$2" << std::endl;
                context.gen_label++;
            }
            else if(op == "%="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\tbeq\t$2,$0,$L" << context.gen_label << std::endl;
                out << "\tdiv\t$0,$3,$2" << std::endl;
                out << "$L" << context.gen_label << ":" << std::endl;
                out << "\tmflo\t$2" << std::endl;
                out << "\tmfhi\t$2" << std::endl;
                context.gen_label++;
            }
            else if(op == "<<="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\tsll\t$2,$3,$2" << std::endl;
            }
            else if(op == ">>="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\tsra\t$2,$3,$2" << std::endl;
            }
            else if(op == "&="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\tand\t$2,$3,$2" << std::endl;
            }
            else if(op == "^="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\txor\t$2,$3,$2" << std::endl;
            }
            else if(op == "|="){
                out << "\tlw\t\t$3," << result_var << "($fp)" << std::endl;
                out << "\tor\t$2,$3,$2" << std::endl;
            }
            else{
                out << "\tsw\t\t$2," << result_var << "($fp)" << std::endl;
            }
        }

        context.function_call = 0;
        context.sizeof_type = false;
    }
}

inline void UnaryExpr::print_asm(std::ofstream& out){
    if(post_expr != NULL){
        post_expr->print_asm(out);
    }

    else if(un_expr != NULL){
        if(*op == "++"){
            un_expr->print_asm(out);

            if(!context.solving_out.back()->is_parameter){
                out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            else{
                out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            out << "\tnop" << std::endl;
            out << "\taddiu\t$2,$2,1" << std::endl;
            out << "\tsw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            context.solving_out.pop_back();
            context.solving_out_constant.pop_back();
        }
        if(*op == "--"){
            un_expr->print_asm(out);

            if(!context.solving_out.back()->is_parameter){
                out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            else{
                out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            out << "\tnop" << std::endl;
            out << "\taddiu\t$2,$2,-1" << std::endl;
            out << "\tsw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            context.solving_out.pop_back();
            context.solving_out_constant.pop_back();
        }

        if(*op == "sizeof"){
            if(un_expr != NULL){
                un_expr->print_asm(out);
            }

            out << "\tli\t\t$2," << context.solving_out.back()->size << std::endl;
            context.is_sizeof = true;
            context.solving_out.pop_back();
            context.solving_out_constant.pop_back();
        }
    }

    else if(type_name != NULL){
        context.sizeof_type = true;
        type_name->print_asm(out);

        if(context.what_typeSpec == "int"){
            out << "\tli\t\t$2,4" << std::endl;
        }

        else if(context.what_typeSpec == "char"){
            out << "\tli\t\t$2,1" << std::endl;
        }
    }

    else{
        if(un_op != NULL){
            std::string type = un_op->print_asm(out);
            cast_expr->print_asm(out);

            if(type == "+"){

            }

            else if(type == "-"){
                if(!context.solving_out.back()->is_parameter){
                    out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                else{
                    out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                out << "\tnop" << std::endl;
                out << "\tsubu\t$2,$0,$2" << std::endl;
                out << "\tsw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                context.solving_out.pop_back();
                context.solving_out_constant.pop_back();
            }

            else if(type == "~"){
                if(!context.solving_out.back()->is_parameter){
                    out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                else{
                    out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                out << "\tnop" << std::endl;
                out << "\tnor\t\t$2,$0,$2" << std::endl;
                out << "\tsw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                context.solving_out.pop_back();
                context.solving_out_constant.pop_back();
            }

            else if(type == "!"){
                if(!context.solving_out.back()->is_parameter){
                    out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                else{
                    out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                out << "\tnop" << std::endl;
                out << "\tsltu\t$2,$2,1" << std::endl;
                out << "\tandi\t$2,$2,0x00ff" << std::endl;
                out << "\tsw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                context.solving_out.pop_back();
                context.solving_out_constant.pop_back();
            }
        }
    }
}

inline void PostfixExpr::print_asm(std::ofstream& out){
    if(pri_expr != NULL){
        if(expr != NULL){
            context.arr_access = true;
            // get value of expr, store in context.arr_index
        }

        pri_expr->print_asm(out);
        // context.solving_out.back()->frame_offset += val*4;
    }
    if(post_expr != NULL && pri_expr == NULL && op == NULL && iden == NULL){
        context.is_func = true;
        context.function_call = 1;
        context.morethanfour = 4;
        context.functionregister = 4;
        post_expr -> print_asm(out);
        context.morethanfour = 4;
        context.functionregister = 4;
        std::string temp = context.function_name;
        if(arg_expr_list != NULL){
            arg_expr_list -> print_asm(out);
        }
        out << "\tjal\t"<< temp << std::endl;
        out << "\tnop" << std::endl;
        out << "\tmove\t$2,$16" << std::endl;
        context.function_name = "";
    }
    else if(post_expr != NULL){
        post_expr -> print_asm(out);
    }
    if(op != NULL){

        if(*op == "++"){
            post_expr->print_asm(out);

            if(!context.solving_out.back()->is_parameter){
                out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            else{
                out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            out << "\tnop" << std::endl;
            out << "\taddiu\t$2,$2,1"<<std::endl;
            out << "\tsw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            context.solving_out.pop_back();
            context.solving_out_constant.pop_back();
        }
        if(*op == "--"){
            post_expr->print_asm(out);

            if(!context.solving_out.back()->is_parameter){
                out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            else{
                out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            out << "\tnop" << std::endl;
            out << "\taddiu\t$2,$2,-1"<<std::endl;
            out << "\tsw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
            context.solving_out.pop_back();
            context.solving_out_constant.pop_back();
        }
    }
}

inline void ArgumentExprList::print_asm(std::ofstream& out){
    if(arg_expr_list != NULL){
        context.function_call++;
        arg_expr_list -> print_asm(out);
    }
    context.is_solving = true;
    ass_expr -> print_asm(out);
    context.is_solving = false;


    if(context.morethanfour == 0){
        out << "\tsw\t\t$2," << 16+(4*context.stack_offset) << "($sp)" << std::endl;
        context.stack_offset++;
        context.function_call--;
    }
    else {
        out << "\tmove\t$" << context.functionregister <<",$2" << std::endl;
        context.function_call--;
        context.morethanfour--;
        context.functionregister++;
    }

}

inline void PrimaryExpr::print_asm(std::ofstream& out){
    if(constant != NULL){
        if(context.is_array){
            context.arr_vals.push_back(*constant);
        }

        else if(context.is_LocalVar){
            context.var_val = stoi(*constant);
        }

        if(context.is_return){
            context.returnNum = stoi(*constant);
        }
        if(context.is_solving || context.is_cond){
            context.solving_out_constant.push_back(*constant);
        }
    }

    if(iden != NULL){
        if(context.is_solving || context.is_cond || context.arr_access){
            if(context.global_arr){
                
            }

            else{
                bool found = false;
                               
                for(context.Enums_it=context.Enums.begin();context.Enums_it!=context.Enums.end(); context.Enums_it++){
                    if(found == true){
                        break;
                    }
                    std::unordered_map<std::string,int>::iterator sec_it;
                    for(sec_it=context.Enums_it->second.enummap.begin();sec_it!=context.Enums_it->second.enummap.end();sec_it++){
                        if(sec_it->first == *iden){
                            found = true;
                            iden = NULL;
                            context.solving_out_constant.push_back(std::to_string(sec_it->second));
                            break;
                        }
                    }
                }
                if(found == false){
                    context.solving_out.push_back(context.LocalVar[*iden]);
                    context.solving_out_constant.push_back("");
                }
                found = false;
                
            }

        }
        if(context.function_call > 0){
            context.function_name = *iden;
        }
        if(context.is_return){
            context.return_var = true;
        }
    }

    if(expr != NULL){
        bool firststepchecker = false;
        if(context.is_firststep == false){
            context.is_firststep = true;
            firststepchecker = true;
        }

        expr->print_asm(out);
        if(firststepchecker == true){
            context.is_firststep = false;
            firststepchecker = false;
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
    if(log_or_expr != NULL){
        context.return_are_u_single = false; 
        int l2 = context.gen_label;
        context.gen_label++;
        int l3 = context.gen_label;
        context.gen_label++;
        int l4 = context.gen_label;
        context.gen_label++;
        log_or_expr -> print_asm(out);

        context.ExprHelper(out);

        out << "\tbne\t$2,$0,$L" << l2 << std::endl;
        out << "\tnop" << std::endl;
        log_and_expr -> print_asm(out);
        context.ExprHelperRHS(out);
        out << "\tbeq\t$3,$0,$L" << l3 << std::endl;
        out << "\tnop" << std::endl;
        out << std::endl;
        out << "$L" << l2 << ":" << std::endl;
        out << "\tli\t\t$2,1" << std::endl;
        out << "\tb\t$L" << l4 << std::endl;
        out << "nop" << std::endl;
        out << std::endl;
        out << "$L" << l3 << ":" << std::endl;
        out << "\tmove\t$2,$0" << std::endl;
        out << "$L" << l4 << ":" << std::endl;
    }
    else{
        log_and_expr -> print_asm(out);
    }
}

inline void LogicalAndExpr::print_asm(std::ofstream& out){
    if(log_and_expr != NULL){
        context.return_are_u_single = false; 
        int l2 = context.gen_label;
        context.gen_label++;
        int l3 = context.gen_label;
        context.gen_label++;

        log_and_expr -> print_asm(out);
        context.ExprHelper(out);
        out << "\tbeq\t\t$2,$0,$L" << l2 << std::endl;
        out << "\tnop" << std::endl;

        incl_or_expr -> print_asm(out);
        context.ExprHelperRHS(out);
        out << "\tbeq\t\t$3,$0,$L" << l2 << std::endl;
        out << "\tnop" << std::endl << std::endl;
        out << "\tli\t\t$2,1" << std::endl;
        out << "\tb\t\t$L" << l3 << std::endl << std::endl;
        out << "$L" << l2 << ":" << std::endl;
        out << "\tmove\t$2,$0" << std::endl;
        out << "$L" << l3 << ":" << std::endl;
    }
    
    else{
        incl_or_expr -> print_asm(out);
    }
}

inline void InclusiveOrExpr::print_asm(std::ofstream& out){
    if(incl_or_expr != NULL){
        context.return_are_u_single = false; 
        incl_or_expr -> print_asm(out);
        context.ExprHelper(out);
        
        excl_or_expr -> print_asm(out);
        context.ExprHelperRHS(out);
        out << "\tnop" << std::endl;
        out << "\tor\t$2,$2,$3" << std::endl;
    }
    else{
        excl_or_expr -> print_asm(out);
    }
}

inline void ExclusiveOrExpr::print_asm(std::ofstream& out){
    if(excl_or_expr != NULL){
        context.return_are_u_single = false; 
        excl_or_expr -> print_asm(out);
        context.ExprHelper(out);
        and_expr -> print_asm(out);
        context.ExprHelperRHS(out);
        out << "\txor\t$2,$2,$3" << std::endl;
    }
    else{
        and_expr -> print_asm(out);
    }
}

inline void AndExpr::print_asm(std::ofstream& out){
    if(and_expr != NULL){
        context.return_are_u_single = false; 
        and_expr -> print_asm(out);
        context.ExprHelper(out);

        equal_expr -> print_asm(out);
        context.ExprHelperRHS(out);
        out << "\tand\t$2,$2,$3" << std::endl;
    }
    else{
        equal_expr -> print_asm(out);
    }
}

inline void EqualityExpr::print_asm(std::ofstream& out){
    if(equal_expr != NULL){
        context.return_are_u_single = false; 
        if(*op == "=="){
            equal_expr -> print_asm(out);
            context.ExprHelper(out);
            rel_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\txor\t$2,$2,$3" << std::endl;
            out << "\tsltu\t$2,$2,1" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
            
        }
        if(*op == "!="){
            equal_expr -> print_asm(out);
            context.ExprHelper(out);
            rel_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\txor\t$2,$2,$3" << std::endl;
            out << "\tsltu\t$2,$0,$2" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;     
        }
    }
    else{
        rel_expr -> print_asm(out);
    }
}


inline void RelationalExpr::print_asm(std::ofstream& out){
    if(rel_expr != NULL){
        context.return_are_u_single = false; 
        if(*op == "<"){
            rel_expr -> print_asm(out);
            context.ExprHelper(out);
            shift_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tslt\t$2,$2,$3" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
        }
        if(*op == ">"){
            rel_expr -> print_asm(out);
            context.ExprHelper(out);
            shift_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tslt\t$2,$3,$2" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
        }
        if(*op == "<="){
            rel_expr -> print_asm(out);
            context.ExprHelper(out);
            shift_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tslt\t$2,$3,$2" << std::endl;
            out << "\txori\t$2,$2,0x1" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
        }
        if(*op == ">="){
            rel_expr -> print_asm(out);
            context.ExprHelper(out);
            shift_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tslt\t$2,$3,$2" << std::endl;
            out << "\txori\t$2,$2,0x1" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
        }
    }
    else{
        shift_expr -> print_asm(out);
    }
    
}
inline void ShiftExpr::print_asm(std::ofstream& out){
    if(shift_expr != NULL){
        context.return_are_u_single = false; 
        if(*op == "<<"){
            shift_expr -> print_asm(out);
            context.ExprHelper(out);
            add_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tsll\t$2,$2,$3" << std::endl;
        }
        if(*op == ">>"){
            shift_expr -> print_asm(out);
            context.ExprHelper(out);
            add_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tsra\t$2,$2,$3" << std::endl;
        }
    }
    else{
        add_expr -> print_asm(out);
    }
}

inline void AdditiveExpr::print_asm(std::ofstream& out){
    if(add_expr != NULL){
        context.return_are_u_single = false;
        if(*op == "+"){
            add_expr -> print_asm(out);
            context.ExprHelper(out);
            mul_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\taddu\t$2,$2,$3" << std::endl;
        }
        if(*op == "-"){
            add_expr -> print_asm(out);
            context.ExprHelper(out);
            mul_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tsubu\t$2,$2,$3" << std::endl;
        }
    }
    else{
        mul_expr -> print_asm(out);
    }
}
inline void MultiplicativeExpr::print_asm(std::ofstream& out){
    if(mul_expr != NULL){
        context.return_are_u_single = false; 
        if(*op == "*"){
            mul_expr -> print_asm(out);
            context.ExprHelper(out);
            cast_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tmult\t$2,$3" << std::endl;
            out << "\tmflo\t$2" << std::endl;
        }
        if(*op == "/"){
            int l2 = context.gen_label;
            context.gen_label++;
            mul_expr -> print_asm(out);
            context.ExprHelper(out);
            cast_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tbeq\t$3,$0,$L" << l2 << std::endl;
            out << "\tdiv\t$0,$2,$3" << std::endl;
            out << "$L" << l2 << ":" << std::endl;
            out << "\tmfhi\t$2" << std::endl;
            out << "\tmflo\t$2" << std::endl;
        }
        if(*op == "%"){
            int l2 = context.gen_label;
            context.gen_label++;
            mul_expr -> print_asm(out);
            context.ExprHelper(out);
            cast_expr -> print_asm(out);
            context.ExprHelperRHS(out);
            out << "\tbeq\t$3,$0,$L" << l2 << std::endl;
            out << "\tdiv\t$0,$2,$3" << std::endl;
            out << "$L" << l2 << ":" << std::endl;
            out << "\tmflo\t$2" << std::endl;
            out << "\tmfhi\t$2" << std::endl;
        }
    }
    else{
        cast_expr -> print_asm(out);
    }
}

inline void CastExpr::print_asm(std::ofstream& out){
    un_expr -> print_asm(out);
}

inline void CompoundStatement::print_asm(std::ofstream& out){
    if(decl_list != NULL){
        context.is_LocalVar = true;
        decl_list -> print_asm(out);
        context.is_LocalVar = false;
    }
    if(state_list != NULL){
        state_list -> print_asm(out);
    }
}

inline void StatementList::print_asm(std::ofstream& out){
    if(state_list != NULL){
        state_list -> print_asm(out);
    }
    state -> print_asm(out);
}

inline void Statement::print_asm(std::ofstream& out){
    if(label_state != NULL){
        label_state -> print_asm(out);
    }
    if(comp_state != NULL){
        comp_state -> print_asm(out);
    }
    if(expr_state != NULL){
        context.is_firststep = true;
        context.is_solving = true;
        expr_state -> print_asm(out);
        context.is_solving = false;
        context.is_firststep = false;
        context.return_are_u_single = true;
        context.is_sizeof = false;
        context.sizeof_type = false;
    }
    if(select_state != NULL){
        context.in_if = true;
        select_state -> print_asm(out);
        context.in_if = false;
    }
    if(it_state != NULL){
        context.in_while = true;
        it_state -> print_asm(out);
        context.in_while = false;
    }
    if(jump_state != NULL){
        jump_state -> print_asm(out);
    }
}

inline void LabeledStatement::print_asm(std::ofstream& out){
    context.nested_switch.back()++;
    if(const_expr!= NULL){
        //THIS IS CASE STATEMENT
        out << "$S" << context.nested_switch.size() << "C" << context.nested_switch.back() << "cond:" << std::endl;
        context.return_are_u_single = true;
        context.is_solving = true;
        const_expr->print_asm(out);
        context.is_solving = false;
        if(context.return_are_u_single == true){
            out << "\tli\t\t$" << 9 << "," << context.solving_out_constant.back() << std::endl;
            context.solving_out_constant.pop_back();
        }
        context.return_are_u_single = true;
        out << "\tbne\t\t$" << 8 << ",$" << 9 << ",$S" << context.nested_switch.size() << "C" << context.nested_switch.back()+1 << "cond" << std::endl;
        out << "\tnop" << std::endl;
        out << "$S" << context.nested_switch.size() << "C" << context.nested_switch.back() << "body:" << std::endl;
        state->print_asm(out);
        out << "\tb\t\t$S" << context.nested_switch.size() << "END" << std::endl; 
        out << "\tnop" << std::endl;
    }
    else{
        //THIS IS DEFAULT STATEMENT WHICH WILL BE WITHELD TILL THE END OF THE CASES
        context.defaultstatemap[context.nested_switch.size()] = state;
        context.nested_switch.back()--;
    }
}

inline void ExprStatement::print_asm(std::ofstream& out){
    if(expr != NULL){
        expr -> print_asm(out);
    }
}

inline void SelectionStatement::print_asm(std::ofstream& out){
    if(SWITCH != NULL){
        if(expr != NULL){
            context.is_switch = true;
            context.return_are_u_single = true;
            context.is_solving = true;
            context.is_firststep = true;
            expr->print_asm(out);
            context.is_firststep = false;
            context.is_solving = false;
            if(context.return_are_u_single == true){
                if(context.solving_out_constant.back()!=""){
                    out << "\tli\t\t$"  << 8 << "," << context.solving_out_constant.back() << std::endl;
                    context.solving_out_constant.pop_back();
                }
                else{
                    out << "\tlw\t\t$" << 8 << "," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                    out << "\tnop" << std::endl;
                    context.solving_out.pop_back();
                    context.solving_out_constant.pop_back();
                }
            }else{
                out << "\tmove\t$" << 8 << ",$2" << std::endl;
            }
            context.return_are_u_single = true;
            context.is_switch = false;
        }
        context.nested_switch.push_back(0);
        context.defaultstatemap.insert(std::pair<int, Statement*>(context.nested_switch.size(),NULL));
        context.is_solving=true;
        context.is_firststep = true;
        context.return_are_u_single = true;
        if_state->print_asm(out);
        context.return_are_u_single = true;
        context.is_firststep = false;
        context.is_solving = false;
        if(context.defaultstatemap[context.nested_switch.size()]!= NULL){
            out << "$S" << context.nested_switch.size() << "C" << context.nested_switch.back()+1 << "cond:" << std::endl;
            out << "\tnop" << std::endl;
            out << "$DEFAULT" << context.nested_switch.size() << ":" << std::endl;
            context.return_are_u_single = true;
            context.defaultstatemap[context.nested_switch.size()]->print_asm(out);
            context.return_are_u_single = true;
            out << "\tb\t\t$S" << context.nested_switch.size() << "END" << std::endl;
            out << "\tnop" << std::endl;
        }
        out << "$S" << context.nested_switch.size() << "END:" << std::endl;
        context.nested_switch.pop_back();
    }
    
    
    if(IF != NULL){
        if(expr != NULL){
            context.is_solving = true;
            context.is_firststep = true;
            expr->print_asm(out);
            context.is_firststep = false;
            context.is_solving = false;
        }

        if(context.return_are_u_single){
            if(context.solving_out_constant.back() == ""){
                out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                context.solving_out.pop_back();
                context.solving_out_constant.pop_back();
            }

            else{
                out << "\tli\t\t$2," << context.solving_out_constant.back() << std::endl;
                context.solving_out_constant.pop_back();
            }
        }

        std::string if_return = "$L" + std::to_string(context.gen_label);
        std::string else_label = if_return;

        if(ELSE != NULL){
            context.gen_label++;
            if_return = "$L" + std::to_string(context.gen_label);
        }

        context.gen_label++;

        //out << "\tlw\t\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
        out << "\tbeq\t\t$2,$0," << else_label << std::endl;
        out << "\tnop" << std::endl;
        bool firststepchecker = false;
        if(context.is_firststep == false){
            context.is_firststep = true;
            firststepchecker = true;
        }

        if_state->print_asm(out);
        if(firststepchecker == true){
            context.is_firststep = false;
            firststepchecker = false;
        }
        
        if(ELSE != NULL){
            out << "\tb\t\t" << if_return << std::endl;
            out << "\tnop" << std::endl;
        }

        if(else_state != NULL){
            out << else_label << ":" << std::endl;
            bool firststepchecker = false;
            if(context.is_firststep == false){
                context.is_firststep = true;
                firststepchecker = true;
            }
            context.gen_label++;
            else_state->print_asm(out);
            if(firststepchecker == true){
                context.is_firststep = false;
                firststepchecker = false;
            }
        }
        
        out << if_return << ":" << std::endl;
    }
    
}

inline void IterationStatement::print_asm(std::ofstream& out){
    if(*type == "while"){
        std::string while_body = "$L" + std::to_string(context.gen_label);
        context.gen_label++;
        std::string while_cond = "$L" + std::to_string(context.gen_label);
        context.break_number.push_back(while_cond);
        context.gen_label++;

        out << "\tb\t\t" << while_cond << std::endl;
        out << "\tnop" << std::endl << std::endl;
        
        out << while_body << ":" << std::endl;
        bool firststepchecker = false;
        if(context.is_firststep == false){
            context.is_firststep = true;
            firststepchecker = true;
        }
        if(state != NULL){
            context.is_solving = true;
            state -> print_asm(out);
            context.is_solving = false;
        }
        if(firststepchecker == true){
            context.is_firststep = false;
            firststepchecker = false;
        }

        out << while_cond << "CONT:" << std::endl;
        out << "\tnop" << std::endl;
        out << while_cond << ":" << std::endl;

        firststepchecker = false;
        if(context.is_firststep == false){
            context.is_firststep = true;
            firststepchecker = true;
        }
        if(expr != NULL){
            context.is_solving = true;
            expr -> print_asm(out);
            context.is_solving = false;
        }

        if(context.return_are_u_single){
            if(context.solving_out_constant.back() == ""){
                out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                context.solving_out.pop_back();
                context.solving_out_constant.pop_back();
            }

            else{
                out << "\tli\t\t$2," << context.solving_out_constant.back() << std::endl;
                context.solving_out_constant.pop_back();
            }
        }
        
        if(firststepchecker == true){
            context.is_firststep = false;
            firststepchecker = false;
        }

        out << "\tbne\t\t$2,$0," << while_body << std::endl;
        out << "\tnop" << std::endl;
        out << while_cond << "END:" << std::endl;
        context.break_number.pop_back();
    }

    else if(*type == "for"){
        if(for_first != NULL){
            context.is_solving = true;
            bool firststepchecker = false;
            if(context.is_firststep == false){
            context.is_firststep = true;
            firststepchecker = true;
            }
            for_first -> print_asm(out);
            if(firststepchecker == true){
                context.is_firststep = false;
                firststepchecker = false;
            }
            context.is_solving = false;
        }

        std::string second_state = "$L" + std::to_string(context.gen_label);
        context.gen_label++;
        std::string for_body = "$L" + std::to_string(context.gen_label);
        context.break_number.push_back(for_body);
        context.gen_label++;

        out << "\tb\t\t" << second_state << std::endl;
        out << "\tnop" << std::endl << std::endl;

        out << for_body << ":" << std::endl;

        context.is_solving = true;
        bool firststepchecker = false;
        if(context.is_firststep == false){
        context.is_firststep = true;
        firststepchecker = true;
        }
        if(state != NULL){
            state->print_asm(out);
        }
        if(firststepchecker == true){
            context.is_firststep = false;
            firststepchecker = false;
        }
        context.is_solving = false;

        
        
        out << for_body << "CONT:" << std::endl;

        context.is_solving = true;
        firststepchecker = false;
        if(context.is_firststep == false){
            context.is_firststep = true;
            firststepchecker = true;
        }
        if(expr != NULL){
            expr->print_asm(out);
        }
        if(firststepchecker == true){
            context.is_firststep = false;
            firststepchecker = false;
        }
        context.is_solving = false;


        out << second_state << ":" << std::endl;
         firststepchecker = false;
        if(context.is_firststep == false){
            context.is_firststep = true;
            firststepchecker = true;
        }
        if(for_second != NULL){
            for_second -> print_asm(out);
        }
        if(firststepchecker == true){
            context.is_firststep = false;
            firststepchecker = false;
        }


        out << "\tbne\t\t$2,$0," << for_body << std::endl;
        out << "\tnop" << std::endl;
        out << for_body << "END:" << std::endl;
        out << "\tnop" << std::endl;
        context.break_number.pop_back();
    }
}

inline void JumpStatement::print_asm(std::ofstream& out){
    if(*type == "return"){
        context.is_return = true;
        context.return_are_u_single = true;
        if(expr != NULL){
            context.is_solving = true;
            context.is_firststep = true;
            expr -> print_asm(out);
            context.is_firststep = false;
            context.is_solving = false;

            if(context.return_are_u_single && context.return_var){
                if(context.is_func){

                }
                else if(!context.solving_out.back()->is_parameter){
                    out << "\tlw\t\t$2," << context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                else{
                    out << "\tlw\t\t$2," << context.NeededMem -4 + context.solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                out << "\tnop" << std::endl;

                context.solving_out.pop_back();
                context.solving_out_constant.pop_back();
            }

            else if(context.is_sizeof || context.sizeof_type){}

            else if(!context.return_var){
                if(context.returnNum != 0){
                    out << "\tli\t\t$2," << context.returnNum << std::endl;
                }

                else{
                    out << "\tmove\t\t$2,$0" << std::endl;
                }
            }
        }

        context.return_are_u_single = true;
        context.is_return = false;
        context.return_var = false;
        context.returnNum = 0;

        out << "\tb\t\t$" << context.FuncName << "END" << std::endl;
        out << "\tnop" << std::endl;
    }
    if(*type == "break"){
        out << "\tb\t\t" << context.break_number.back() << "END" << std::endl;
        out << "\tnop" << std::endl;
    }
    if(*type == "continue"){
        out << "\tb\t\t" << context.break_number.back() << "CONT" << std::endl;
        out << "\tnop" << std::endl;
    }
    //DO SOMETHING ABOUT TYPE
}

inline void Expr::print_asm(std::ofstream& out){
    assign_expr -> print_asm(out);
}

inline void TypeName::print_asm(std::ofstream& out){
    if(spec_qual_list != NULL){
        spec_qual_list->print_asm(out);
    }
}

inline void SpecifierQualifierList::print_asm(std::ofstream& out){
    if(type_spec != NULL){
        type_spec->print_asm(out);
    }
}








/* ENUM STUFFS */
inline void ConstantExpr::checking_enum(){
    cond_expr->checking_enum();
}
inline void ConditionalExpr::checking_enum(){
    if(log_or_expr!= NULL){
        log_or_expr -> checking_enum();
    }
}
inline void LogicalOrExpr::checking_enum(){
    if(log_or_expr != NULL){
        context.enumoperators.push_back("||");
        log_or_expr -> checking_enum();
    }
        log_and_expr -> checking_enum();
}
inline void LogicalAndExpr::checking_enum(){
    if(log_and_expr != NULL){
        context.enumoperators.push_back("&&");
        log_and_expr -> checking_enum();
    }
        incl_or_expr -> checking_enum();
}
inline void InclusiveOrExpr::checking_enum(){
    if(incl_or_expr != NULL){
        context.enumoperators.push_back("|");
        incl_or_expr -> checking_enum();
    }
        excl_or_expr -> checking_enum();
}
inline void ExclusiveOrExpr::checking_enum(){
    if(excl_or_expr != NULL){
        context.enumoperators.push_back("^");
        excl_or_expr -> checking_enum();
    }
        and_expr -> checking_enum();
}
inline void AndExpr::checking_enum(){
    if(and_expr != NULL){
        context.enumoperators.push_back("&");
        and_expr -> checking_enum();
    }
        equal_expr -> checking_enum();
}
inline void EqualityExpr::checking_enum(){
    if(equal_expr != NULL){
        if(*op == "=="){
            context.enumoperators.push_back("==");
        }
        else if(*op == "!="){
            context.enumoperators.push_back("!=");
        }
        equal_expr -> checking_enum();
    }
        rel_expr -> checking_enum();
}
inline void RelationalExpr::checking_enum(){
    if(rel_expr != NULL){
        context.enumoperators.push_back(*op);
        rel_expr -> checking_enum();
    }
        shift_expr -> checking_enum();
}
inline void ShiftExpr::checking_enum(){
    if(shift_expr != NULL){
        context.enumoperators.push_back(*op);
        shift_expr -> checking_enum();
    }
        add_expr -> checking_enum();
}
inline void AdditiveExpr::checking_enum(){
    if(add_expr != NULL){
        context.enumoperators.push_back(*op);
        add_expr -> checking_enum();
    }
        mul_expr -> checking_enum();
}
inline void MultiplicativeExpr::checking_enum(){
    if(mul_expr != NULL){
        context.enumoperators.push_back(*op);
        mul_expr -> checking_enum();
    }
        cast_expr -> checking_enum();
}
inline void CastExpr::checking_enum(){
    un_expr -> checking_enum();
}
inline void UnaryExpr::checking_enum(){
    post_expr -> checking_enum();
}
inline void PostfixExpr::checking_enum(){
    if(post_expr != NULL){
        context.enumoperators.push_back(*op);
        post_expr -> checking_enum();
    }
    else if(pri_expr != NULL){
        pri_expr -> checking_enum();
    }
}
inline void PrimaryExpr::checking_enum(){
    if(iden != NULL){
        context.enumoperands.push_back(std::pair<std::string, std::string>("variable", *iden));
    }
    else if(constant != NULL){
        context.enumoperands.push_back(std::pair<std::string,std::string>("constant", *constant));
    }
    // else if(expr != NULL){
    //     expr -> checking_enum();
    // }
}

// inline void Expr::checking_enum(){
//     assign_expr -> checking_enum();
// }

// inline void AssignmentExpr::checking_enum(){
//     if(cond_expr != NULL){
//         cond_expr ->checking_enum;
//     }
//     else{
//         context.enumoperators.push_back("=");
//         un_expr -> checking_enum();
//         ass_expr -> checking_enum();
//     }
    
// }

inline void EnumSpecifier::print_asm(std::ofstream& out){
    if(iden != NULL){
        context.enum_name = new std::string(*iden);
        context.Enums_it = context.Enums.find(*iden);
        if(context.Enums_it == context.Enums.end()){
            context.enumgen = new WithinEnum;
            context.Enums.insert(std::pair<std::string, WithinEnum>(*iden,*context.enumgen));
        }
        context.Enums_it = context.Enums.begin();
    }
    else{
        context.enum_name = new std::string("noname");
        context.Enums_it = context.Enums.find("noname");
        if(context.Enums_it == context.Enums.end()){
            context.enum_name = new std::string("noname");
            context.enumgen = new WithinEnum;
            context.Enums.insert(std::pair<std::string,WithinEnum>("noname", *context.enumgen));
        }
        
    }

    // context.is_solving = true;
    // bool firststepchecker = false;
    // if(context.is_firststep == false){
    // context.is_firststep = true;
    // firststepchecker = true;
    // }
    context.enumerator_start = 0;
    enum_list -> print_asm(out);
    context.enumerator_start = 0;
    std::unordered_map<std::string, int>::iterator it;

    // if(firststepchecker == true){
    //     context.is_firststep = false;
    //     firststepchecker = false;
    // }
    // context.is_solving = false;
}

inline void EnumeratorList::print_asm(std::ofstream& out){
    if(enum_list!=NULL){
        enum_list -> print_asm(out);
    }
    context.is_solving = true;
    enume -> print_asm(out);
    context.is_solving = false;
}

inline void Enumerator::print_asm(std::ofstream& out){
    if(const_expr != NULL){
        const_expr -> checking_enum();
        // if(context.Enums[*context.enum_name].enummap.size() == 0){
        //     // if(context.enumoperators.size() == 1){
        //     //     std::pair<std::string, int>tmp(context.enumoperands[0].first, std::stoi(context.enumoperands[1].first));
        //     //     context.Enums[*context.enum_name].enummap.insert(tmp);
        //     //     context.enumoperands.pop_back();
        //     //     context.enumoperands.pop_back();

        //     //     context.enumoperators.pop_back();
        //     // }
            
        //     std::pair<std::string, int>tmp(*iden,std::stoi(context.enumoperands[0].second));
        //     context.enumoperands.pop_back();
        //     context.Enums[*context.enum_name].enummap.insert(std::pair<std::string, int>(*iden,tmp.second));
        //     context.Enums[*context.enum_name].enumcounter= tmp.second;
        //     context.Enums[*context.enum_name].enumcounter++;

            
        // }
        // else{
            if(context.enumoperators.size()==0){
                std::pair<std::string, int>tmp(*iden, std::stoi(context.enumoperands[0].second));
            }
            else{
                while(context.enumoperators.size()!=0){
                    if(context.enumoperators.back() == "++" || context.enumoperators.back() == "--"){ 
                    }
                    else{
                        std::pair<std::string,std::string> operand1;
                        std::pair<std::string,std::string> operand2;

                        operand2 = context.enumoperands.back();
                        context.enumoperands.pop_back();
                        operand1 = context.enumoperands.back();
                        context.enumoperands.pop_back();
                        bool found = false;
                        for(context.Enums_it=context.Enums.begin(); context.Enums_it!=context.Enums.end(); context.Enums_it++){
                            if(found == true){
                                break;
                            }
                            context.searchupdate(operand1, context.Enums_it->second.enummap);
                        }
                        found = false;
                        for(context.Enums_it=context.Enums.begin();context.Enums_it!=context.Enums.end(); context.Enums_it++){
                            if(found == true){
                                break;
                            }
                            context.searchupdate(operand2, context.Enums_it->second.enummap);
                        }
                        found = false;
                        operand1.second = std::to_string(context.int_house_solver(std::stoi(operand1.second), std::stoi(operand2.second), context.enumoperators.back()));
                        context.enumoperands.push_back(operand1);
                        context.enumoperators.pop_back();
                    }
                }
            }
            context.Enums[*context.enum_name].enummap.insert(std::pair<std::string, int>(*iden,std::stoi(context.enumoperands.back().second)));
            context.Enums[*context.enum_name].enumcounter = std::stoi(context.enumoperands.front().second);
            context.Enums[*context.enum_name].enumcounter++;
            context.enumoperands.pop_back();
        // } 
    }
    else{
        context.Enums[*context.enum_name].enummap.insert(std::pair<std::string, int>(*iden, context.Enums[*context.enum_name].enumcounter));
        context.Enums[*context.enum_name].enumcounter++;
    }
}



//ALLOCATING MEMORY//

inline void CompoundStatement::alloc_mem(std::vector<int>& mv){
    if(decl_list != NULL){
        decl_list->alloc_mem(mv);
    }

    if(state_list != NULL){
        state_list->alloc_mem(mv);
    }
}
inline void StatementList::alloc_mem(std::vector<int>& mv){
    if(state_list != NULL){
        state_list -> alloc_mem(mv);
    }
    state -> alloc_mem(mv);
}
inline void Statement::alloc_mem(std::vector<int>& mv){
    if(comp_state != NULL){
        comp_state -> alloc_mem(mv);
    }
    if(expr_state != NULL){
        expr_state -> alloc_mem(mv);
    }
}

inline void ExprStatement::alloc_mem(std::vector<int>& mv){
    if(expr != NULL){
        expr->alloc_mem(mv);
        
    }
}
inline void Expr::alloc_mem(std::vector<int>& mv){
    if(assign_expr != NULL){
        int iterations = 0;
        assign_expr -> alloc_mem(iterations);

        if(iterations > 0 && iterations < 3){
            mv.push_back(1);
            mv.push_back(1);
            mv.push_back(1);
            mv.push_back(1);
        }

        else{
            for(int i=0; i<iterations; i++){
                mv.push_back(1);
                mv.push_back(1);
            }
        }
    }
}
inline void AssignmentExpr::alloc_mem(int& iterations){
    if(cond_expr != NULL){
        cond_expr -> alloc_mem(iterations);
    }
}
inline void ConditionalExpr::alloc_mem(int& iterations){
    if( log_or_expr != NULL){
        log_or_expr -> alloc_mem(iterations);
    }
}
inline void LogicalOrExpr::alloc_mem(int& iterations){
    if( log_and_expr != NULL){
        log_and_expr -> alloc_mem(iterations);
    }
}
inline void LogicalAndExpr::alloc_mem(int& iterations){
    if( incl_or_expr != NULL){
        incl_or_expr -> alloc_mem(iterations);
    }
}
inline void InclusiveOrExpr::alloc_mem(int& iterations){
    if( excl_or_expr != NULL){
        excl_or_expr -> alloc_mem(iterations);
    }
}
inline void ExclusiveOrExpr::alloc_mem(int& iterations){
    if( and_expr != NULL){
        and_expr -> alloc_mem(iterations);
    }
}
inline void AndExpr::alloc_mem(int& iterations){
    if( equal_expr != NULL){
        equal_expr -> alloc_mem(iterations);
    }
}
inline void EqualityExpr::alloc_mem(int& iterations){
    if( rel_expr != NULL){
        rel_expr -> alloc_mem(iterations);
    }
}
inline void RelationalExpr::alloc_mem(int& iterations){
    if( shift_expr != NULL){
        shift_expr -> alloc_mem(iterations);
    }
}
inline void ShiftExpr::alloc_mem(int& iterations){
    if( add_expr != NULL){
        add_expr -> alloc_mem(iterations);
    }
}
inline void AdditiveExpr::alloc_mem(int& iterations){
    if( mul_expr != NULL){
        mul_expr -> alloc_mem(iterations);
    }
}
inline void MultiplicativeExpr::alloc_mem(int& iterations){
    if( cast_expr != NULL){
        cast_expr -> alloc_mem(iterations);
    }
}
inline void CastExpr::alloc_mem(int& iterations){
    if( un_expr != NULL){
        un_expr -> alloc_mem(iterations);
    }
}
inline void UnaryExpr::alloc_mem(int& iterations){
    if( post_expr != NULL){
        post_expr -> alloc_mem(iterations);
    }
}
inline void PostfixExpr::alloc_mem(int& iterations){
    if( arg_expr_list != NULL){
        arg_expr_list -> alloc_mem(iterations);
    }
}
inline void ArgumentExprList::alloc_mem(int& iterations){
    if(arg_expr_list != NULL){
        arg_expr_list->alloc_mem(iterations);
    }

    if( ass_expr != NULL){
        iterations ++;
        ass_expr -> alloc_mem(iterations);
    }
}
inline void DeclarationList::alloc_mem(std::vector<int>& mv){
    if(decl_list!=NULL){
        decl_list->alloc_mem(mv);
    }

    decl->alloc_mem(mv);
}
inline void Declaration::alloc_mem(std::vector<int>& mv){
    decl_spec->alloc_mem(mv);
}

inline void DeclarationSpecifier::alloc_mem(std::vector<int>& mv){
    type_spec->alloc_mem(mv);
}
inline void TypeSpecifier::alloc_mem(std::vector<int>& mv){
    if(*type == "double"){
        mv.push_back(2);
        mv.push_back(3);
    }
    else{
        mv.push_back(1);
    }
}