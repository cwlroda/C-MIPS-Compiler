#include "../include/ast.hpp"

#include <iostream>

int main(int argc, char* argv[]){
    if(argc < 5){
        std::cerr << "Please specify all arguments!" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string mode = argv[1];

    if(mode == "--translate"){
        std::string arg = argv[3];

        if(arg == "-o"){
            const TranslationUnit *ast = parseAST(argv[2]);
            std::string outfile = argv[4];
            ast->print_py_main(outfile);
        }
    }

    else if(mode == "-S"){
        std::string arg = argv[3];

        if(arg == "-o"){
            const TranslationUnit *ast = parseAST(argv[2]);
            std::string outfile = argv[4];
            ast->print_asm_main(outfile);
        }
    }

    else{
        std::cerr << "Invalid mode!" << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}