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
        out << "\t.globl\t" << context.var_iden << std::endl;
        out << "\t.align\t2" << std::endl;
        out << "\t.type\t" << context.var_iden << ", @object" << std::endl;
        out << "\t.size\t" << context.var_iden << ", ";

        if(context.what_typeSpec == "char"){
            out << "1";
        }
        else{
            out << "4";
        }
        out << std::endl;

        out << context.var_iden << ":" << std::endl;
        if(context.what_typeSpec == "char"){
            out << "\t.byte\t";
        }
        else{
            out << "\t.word\t";
        }
        out << context.var_val << std::endl;

        Bindings* global_var = new Bindings;
        global_var->id = context.var_iden;
        global_var->value = context.var_val;
        global_var->type = context.what_typeSpec;

        std::pair<std::string, Bindings*> var (context.var_iden, global_var);
        context.GlobalVar.insert(var);

        context.is_GlobalVar = false;
        context.what_typeSpec = "0";
        context.var_iden = "0";
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
    int sizee = (mv.size()+(mv.size()%2==1))/2;
    return 16+8*sizee;
}
inline void FunctionDefinition::print_asm(std::ofstream& out){
    context.frame_offset_counter = 8;

    if(decl_spec != NULL){
        decl_spec->print_asm(out);
    }
    declr->print_asm(out);

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
    int NeededMem = CalcMemoryNeeded(MemoryAlloc);
    out << "\taddiu\t$sp,$sp,-" << NeededMem << std::endl;
    out << "\tsw\t\t$31,"<< NeededMem - 4<<"($sp)" << std::endl;
    out << "\tsw\t\t$fp,"<<NeededMem - 8 <<"($sp)" << std::endl;
    out << "\tmove\t$fp,$sp" << std::endl;



    comp_state -> print_asm(out);
    out << "$" << context.FuncName << "END:" << std::endl;
    out << "\tmove\t$sp,$fp" << std::endl;
    out << "\tlw\t\t$31,"<< NeededMem - 4<<"($sp)" << std::endl;
    out << "\tlw\t\t$fp,"<<NeededMem - 8 <<"($sp)" << std::endl;
    out << "\taddiu\t$sp,$sp," << NeededMem << std::endl;
    out << "\tj\t\t$31" << std::endl;
    out << "\tnop" << std::endl;

    context.frame_offset_counter = 8;
}

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

        std::pair<std::string, Bindings*> var (context.var_iden, local_var);
        context.LocalVar.insert(var);

        context.frame_offset_counter += 4;
        out << "\tli\t\t$2," << local_var->value << std::endl;
        out << "\tsw\t\t$2," << local_var->frame_offset << "($fp)" << std::endl;
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
        context.var_iden = *iden;
    }

    if(context.is_LocalVar){
        context.var_iden = *iden;
    }

    if(context.in_func == true && iden != NULL && !context.got_func_name){
        context.FuncName = *iden;
        context.got_func_name = true;
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

    else{
        if(un_expr != NULL){
            un_expr->print_asm(out);
        }

        std::string result_var = context.var_iden;

        if(ass_expr != NULL){
            ass_expr->print_asm(out);
        }

        Bindings* result_bindings = context.LocalVar[result_var];

        out << "\tsw\t\t$2," << result_bindings->frame_offset << "($fp)" << std::endl;
    }
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

    if(post_expr != NULL){
        post_expr -> print_asm(out);
    }
    if(op != NULL){

        if(*op == "++"){
            post_expr->print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\taddiu\t$2,$2,1"<<std::endl;
            out << "\tsw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
        }
        if(*op == "--"){
            post_expr->print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\taddiu\t$2,$2,-1"<<std::endl;
            out << "\tsw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
        }
    }
    // if(*op == "++"){
    //    std::cout << "it came here" << std::endl;
    //     out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
    //     out << "\tnop" << std::endl;
    //     out << "\taddiu\t$2,$2,1"<<std::endl;
    //     out << "\tsw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
    //     context.solving_out = NULL;
    // }
    // if(*op == "--"){
    //     out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
    //     out << "\tnop" << std::endl;
    //     out << "\taddiu\t$2,$2,-1"<<std::endl;
    //     out << "\tsw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
    //     context.solving_out = NULL;
    // }

    // if(op != NULL){
    //     context.is_solving = false;
    // }
}

inline void PrimaryExpr::print_asm(std::ofstream& out){
    if(constant != NULL){
        if(context.is_GlobalVar == true){
            context.var_val = stoi(*constant);
        }

        if(context.is_LocalVar == true){
            context.var_val = stoi(*constant);
        }

        if(context.is_return == true){
            context.returnNum = stoi(*constant);
        }
    }

    if(iden != NULL){
        
        if(context.is_solving == true){
            context.solving_out=context.LocalVar[*iden];
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
        int l2 = context.gen_label;
        context.gen_label++;
        int l3 = context.gen_label;
        context.gen_label++;
        int l4 = context.gen_label;
        context.gen_label++;
        
        

        log_or_expr -> print_asm(out);
        out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
        out << "\tnop" << std::endl;
        out << "\tbne\t$2,$0,$L" << l2 << std::endl;
        out << "\tnop" << std::endl;
        context.solving_out = NULL;
        log_and_expr -> print_asm(out);
        out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
        out << "\tnop" << std::endl;
        out << "\tbeq\t$2,$0,$L" << l3 << std::endl;
        out << "\tnop" << std::endl;
        out << std::endl;
        out << "$L" << l2 << ":" << std::endl;
        out << "\tli\t$2,1" << std::endl;
        out << "\tb\t$L" << l4 << std::endl;
        out << "nop" << std::endl;
        out << std::endl;
        out << "$L" << l3 << ":" << std::endl;
        out << "\tmove\t$2,$0" << std::endl;
        out << "$L" << l4 << ":" << std::endl;
        //store
    }
    else{
        log_and_expr -> print_asm(out);
    }
}

inline void LogicalAndExpr::print_asm(std::ofstream& out){
    if(log_and_expr != NULL){
         int l2 = context.gen_label;
        context.gen_label++;
        int l3 = context.gen_label;
        context.gen_label++;

        log_and_expr -> print_asm(out);
        out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
        out << "\tnop" << std::endl;
        out << "\tbeq\t$2,$0,$L" << l2 << std::endl;
        out << "\tnop" << std::endl;
        context.solving_out = NULL;
        incl_or_expr -> print_asm(out);
        out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
        out << "\tnop" << std::endl;
        out << "\tbeq\t$2,$0,$L" << l2 << std::endl;
        out << "\tnop" << std::endl;
        out << std::endl;
        out << "$L" << l2 << ":" << std::endl;
        out << "\tmove\t$2,$0" << std::endl;
        out << "$L" << l3 << ":" << std::endl;
        //store  
    }
    
    else{
        incl_or_expr -> print_asm(out);
    }
}

inline void InclusiveOrExpr::print_asm(std::ofstream& out){
    if(incl_or_expr != NULL){
        incl_or_expr -> print_asm(out);
        out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
        context.solving_out = NULL;
    excl_or_expr -> print_asm(out);
    out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
        context.solving_out = NULL;
        out << "\tnop" << std::endl;
        out << "\tor\t$2,$3,$2" << std::endl;
        //store
    }
    else{
        excl_or_expr -> print_asm(out);
    }
}

inline void ExclusiveOrExpr::print_asm(std::ofstream& out){
    if(excl_or_expr != NULL){
        excl_or_expr -> print_asm(out);
        out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
        context.solving_out = NULL;
        and_expr -> print_asm(out);
        out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
        context.solving_out = NULL;
        out << "\tnop" << std::endl;
        out << "\txor\t$2,$3,$2" << std::endl;
        //store
    }
    else{
        and_expr -> print_asm(out);
    }
    
}

inline void AndExpr::print_asm(std::ofstream& out){
    if(and_expr != NULL){
        and_expr -> print_asm(out);
        out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
        context.solving_out = NULL;
        equal_expr -> print_asm(out);
        out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
        context.solving_out = NULL;
        out << "\tnop" << std::endl;
        out << "\tand\t$2,$3,$2" << std::endl;
        //store
    }
    else{
        equal_expr -> print_asm(out);
    }
    
}

inline void EqualityExpr::print_asm(std::ofstream& out){
    if(equal_expr != NULL){
        if(*op == "=="){
            equal_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            rel_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\txor\t$2,$3,$2" << std::endl;
            out << "\tsltu\t$2,$2,1" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
            //store
            context.solving_out = NULL;
        }
        if(*op == "!="){
            equal_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            rel_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\txor\t$2,$3,$2" << std::endl;
            out << "\tsltu\t$2,$0,$2" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
            //store
            context.solving_out = NULL;
        }
    }
    else{
        rel_expr -> print_asm(out);
    }
    
}


inline void RelationalExpr::print_asm(std::ofstream& out){
 if(rel_expr != NULL){
        if(*op == "<"){
            rel_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            shift_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tslt\t$2,$3,$2" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
            //store
        }
        if(*op == ">"){
            rel_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            shift_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tslt\t$2,$2,$3" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
            //store
        }
        if(*op == "<="){
            rel_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            shift_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tslt\t$2,$2,$3" << std::endl;
            out << "\txori\t$2,$2,0x1" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
            //store
        }
        if(*op == ">="){
            rel_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            shift_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tslt\t$2,$3,$2" << std::endl;
            out << "\txori\t$2,$2,0x1" << std::endl;
            out << "\tandi\t$2,$2,0x00ff" << std::endl;
            //store
        }
    }
    else{
        shift_expr -> print_asm(out);
    }
    
}
inline void ShiftExpr::print_asm(std::ofstream& out){
if(shift_expr != NULL){
        if(*op == "<<"){
            shift_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            add_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tsll\t$2,$3,$2" << std::endl;
            //store
        }
        if(*op == ">>"){
            shift_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            add_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tsra\t$2,$3,$2" << std::endl;
            //store
        }
        
    }
    else{
        add_expr -> print_asm(out);
    }
    
}

inline void AdditiveExpr::print_asm(std::ofstream& out){
if(add_expr != NULL){
        if(*op == "+"){
            add_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            mul_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\taddu\t$2,$3,$2" << std::endl;
            //store
        }
        if(*op == "-"){
            add_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            mul_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tsubu\t$2,$3,$2" << std::endl;
            //store
        }
    }
    else{
        mul_expr -> print_asm(out);
    }
    
}

inline void MultiplicativeExpr::print_asm(std::ofstream& out){
if(mul_expr != NULL){
        if(*op == "*"){
            mul_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            cast_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tmult\t$2,$3,$2" << std::endl;
            out << "\tmflo\t$2" << std::endl;
            //store
        }
        if(*op == "/"){
            int l2 = context.gen_label;
            context.gen_label++;
            mul_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            cast_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tbeq\t$2,$0,$L" << l2 << std::endl;
            out << "\tdiv\t$0,$3,$2" << std::endl;
            out << "$L" << l2 << ":" << std::endl;
            out << "\tmfhi\t$2" << std::endl;
            out << "\tmflo\t$2" << std::endl;
            //store
        }
        if(*op == "%"){
            int l2 = context.gen_label;
            context.gen_label++;
            mul_expr -> print_asm(out);
            out << "\tlw\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
            context.solving_out = NULL;
            cast_expr -> print_asm(out);
            out << "\tlw\t$2," << context.solving_out->frame_offset << "($fp)" << std::endl;
            out << "\tnop" << std::endl;
            out << "\tbeq\t$2,$0,$L" << l2 << std::endl;
            out << "\tdiv\t$0,$3,$2" << std::endl;
            out << "$L" << l2 << ":" << std::endl;
            out << "\tmflo\t$2" << std::endl;
            out << "\tmfhi\t$2" << std::endl;
            //store
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
        expr_state -> print_asm(out);
    }
    if(select_state != NULL){
        context.in_if = true;
        select_state -> print_asm(out);
        context.in_if = false;
    }
    if(it_state != NULL){
        it_state -> print_asm(out);
    }
    if(jump_state != NULL){
        jump_state -> print_asm(out);
    }
}

inline void LabeledStatement::print_asm(std::ofstream& out){

}

inline void ExprStatement::print_asm(std::ofstream& out){
    if(expr != NULL){
        expr -> print_asm(out);
    }
}

inline void SelectionStatement::print_asm(std::ofstream& out){
    if(expr != NULL){
        expr->print_asm(out);
    }

    
    std::string if_return = "$L" + std::to_string(context.gen_label);
    std::string else_label = if_return;

    if(ELSE != NULL){
        context.gen_label++;
        if_return = "$L" + std::to_string(context.gen_label);
    }

    context.gen_label++;

    //out << "\tlw\t\t$3," << context.solving_out->frame_offset << "($fp)" << std::endl;
    out << "\tli\t\t$2," /* << value of expr */ << std::endl;
    out << "\tbne\t\t$3,$2," << else_label << std::endl;
    out << "\tnop" << std::endl;

    if_state->print_asm(out);
    out << "\tb\t\t" << if_return << std::endl;
    out << "\tnop" << std::endl;

    if(else_state != NULL){
        out << else_label << ":" << std::endl;
        context.gen_label++;
        else_state->print_asm(out);
    }

    out << if_return << ":" << std::endl;
}

inline void IterationStatement::print_asm(std::ofstream& out){
    if(expr != NULL){
        expr -> print_asm(out);
    }
    state -> print_asm(out);
    if(for_first != NULL){
        for_first -> print_asm(out);
    }
    if(for_second != NULL){
        for_second -> print_asm(out);
    }
    //DO SOMETHING ABOUT TYPE
    if(add_type != NULL){
        //DO SOMETHING ABOUT ADD_TYPE
    }
}

inline void JumpStatement::print_asm(std::ofstream& out){
    if(*type == "return"){
        context.is_return = true;
        expr -> print_asm(out);
        if(context.returnNum != 0){
            out << "\tli\t\t$2," << context.returnNum << std::endl;
        }
        else{
            out << "\tmove\t\t$2,$0" << std::endl;
        }
        context.is_return = false;
        context.returnNum = 0;

        out << "\tj\t\t$" << context.FuncName << "END" << std::endl;
    }
    //DO SOMETHING ABOUT TYPE
}

inline void Expr::print_asm(std::ofstream& out){
    assign_expr -> print_asm(out);
}
