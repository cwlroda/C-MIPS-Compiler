#include "ast_functions.hpp"

/*-------*
| *MIPS* |
*--------*/

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

    out << std::endl;
}

inline void FunctionDefinition::print_asm(std::ofstream& out){
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

    out << "\taddiu\t$sp,$sp,-48" << std::endl;
    out << "\tsw\t$31,44($sp)" << std::endl;
    out << "\tsw\t$fp,40($sp)" << std::endl;
    out << "\tmove $fp,$sp" << std::endl;


    if(decl_list != NULL){
        decl_list->print_asm(out);
    }

    comp_state -> print_asm(out);

    out << "\tmove\t$sp,$fp" << std::endl;
    out << "\tlw\t$31,44($sp)" << std::endl;
    out << "\tlw\t$fp,40($sp)" << std::endl;
    out << "\taddiu\t$sp,$sp,48" << std::endl;
    out << "\tj\t$31" << std::endl;
    out << "\tnop" << std::endl;

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
        if(context.is_return == true){
            context.returnNum = stoi(*constant);
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

inline void CompoundStatement::print_asm(std::ofstream& out){
    if(decl_list != NULL){
        decl_list -> print_asm(out);
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
        select_state -> print_asm(out);
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
    expr -> print_asm(out);
    if_state -> print_asm(out);
    if(else_state != NULL){
        else_state -> print_asm(out);
    }
    if(IF != NULL){
        /*DO SOMETHING HERE */
    }
    if(ELSE != NULL){
        /*DO SOMETHING HERE */
    }
    if(IF != NULL){
        /*DO SOMETHING HERE */
    }
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
        out << "\tli\t\t$2," << context.returnNum << std::endl;
    }
    //DO SOMETHING ABOUT TYPE
    
}

inline void Expr::print_asm(std::ofstream& out){
    assign_expr -> print_asm(out);
}
