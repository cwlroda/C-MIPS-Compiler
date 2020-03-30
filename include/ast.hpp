#ifndef AST_HPP
#define AST_HPP

#include "ast_functions.hpp"
#include "ast_functions.cpp"


extern bool preif;
extern const TranslationUnit *parseAST(const char* file);
extern Context context;

#endif