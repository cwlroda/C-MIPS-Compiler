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
        out<< std::endl;
        std::cout << "hi1";
        decl->print_asm(out);
        out<< std::endl;
    }

    if(func_def != NULL){
        
    } 
}

inline void Declaration::print_asm(std::ofstream& out){
    /* decl_spec -> print_asm(out); */
    std::cout << "hi2";
    if(init_declr != NULL){
        init_declr->print_asm(out);
    }
}

inline void InitDeclarator::print_asm(std::ofstream& out){
    if(init == NULL){
        declr->print_asm(out);
    }
    else{
        declr->print_asm(out);
        /* init->print_asm(out); */
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
    out << *iden << ":" << std::endl;
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
        if(expr == NULL){
            pri_expr->print_asm(out);
        }
        else{

        }
    }
}

inline void PrimaryExpr::print_asm(std::ofstream& out){
    if(constant != NULL){
        out << *constant;
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