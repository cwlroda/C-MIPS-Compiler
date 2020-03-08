#include "../include/ast.hpp"
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv){
    const Node* ast = parseAST();

    ast->print_C(std::cout);
    std::cout << std::endl;

    return 0;
}