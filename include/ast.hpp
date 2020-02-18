#ifndef AST_HPP
#define AST_HPP

#include "ast/ast_node.hpp"
#include "ast/ast_decl.hpp"
#include "ast/ast_op.hpp"

extern const Node *parseAST(const char file[]);

#endif
