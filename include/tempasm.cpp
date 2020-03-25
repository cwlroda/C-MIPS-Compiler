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
        decl->print_asm(out);
        out<< std::endl;
    }

    if(func_def != NULL){
        
    } 
}

inline void Declaration::print_asm(std::ofstream& out){
    decl_spec -> print_asm(out);
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
    out <<*iden << std::endl;
}

inline void Initializer::print_asm(std::ofstream& out){
    if(init_list != NULL){
        init_list -> print_asm(out);
    }
    if(assign_expr != NULL){
        assign_expr -> print_asm(out);
    }
}
