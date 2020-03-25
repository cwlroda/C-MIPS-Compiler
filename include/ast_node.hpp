#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <vector>
#include <string>

struct Context{
    bool in_func = false; // check if entering function
    bool is_init = false; // check if function/variable is initialised
    bool in_while = false; // check if entering while loop
    bool in_if = false; // check if in if-else body
    bool main_func = false; // check for main function
    bool func_param = false; // check if function has parameters
    bool var_param = false; // check if variable has parameters
    bool elif_block = false; // check for more else-if blocks
    //bool func_decl = false; // check if it is a function declaration or a global variable
    bool is_GlobalVar = false; // check if it is a global variable
    std::string what_typeSpec = "0";
    std::string GlobalDirectDeclarator = "0";
    int GlobalVarNum = 0;
    int indent = 0; // stores indentation level
    int brackets = 0; // stores parentheses nesting level

    std::vector<std::string> GlobalVar; // stores global variables
};

// Declarations
class TranslationUnit;
class ExternalDeclaration;
class FunctionDefinition;
class Declaration;
class DeclarationSpecifier;
class DeclarationList;
class InitDeclaratorList;
class InitDeclarator;
class Initializer;
class InitializerList;
class Declarator;
class DirectDeclarator;
class ParameterTypeList;
class ParameterList;
class ParameterDeclaration;
class AbstractDeclarator;
class DirectAbstractDeclarator;
class SpecifierQualifierList;
class StructSpecifier;
class StructDeclarationList;
class StructDeclaration;
class StructDeclaratorList;
class StructDeclarator;

// Statements
class CompoundStatement;
class StatementList;
class Statement;
class LabeledStatement;
class ExprStatement;
class SelectionStatement;
class IterationStatement;
class JumpStatement;

// Expressions
class Expr;
class ConstantExpr;
class ConditionalExpr;
class LogicalOrExpr;
class LogicalAndExpr;
class InclusiveOrExpr;
class ExclusiveOrExpr;
class AndExpr;
class EqualityExpr;
class RelationalExpr;
class ShiftExpr;
class AdditiveExpr;
class MultiplicativeExpr;
class AssignmentExpr;
class AssignmentOperator;
class UnaryExpr;
class UnaryOperator;
class PostfixExpr;
class PrimaryExpr;
class ArgumentExprList;
class CastExpr;

// Others
class IdentifierList;
class TypeSpecifier;
class TypeName;
class StorageClassSpecifier;
class Pointer;
class EnumSpecifier;
class EnumeratorList;
class Enumerator;

#endif