#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <vector>
#include <string>
#include <unordered_map>

struct Bindings{
    std::string id;
    double value;
    std::string type;
    bool typdef = false;
    int stack_offset = 0;
    int frame_offset = 0;

    bool is_pointer = false;
    bool is_init = false;
    bool is_arr = false;
};
struct WithinEnum{
    std::unordered_map<std::string, int> enummap;
    int enumcounter = 0;
};
WithinEnum* enumgen;
std::unordered_map<std::string, WithinEnum> Enums;
std::unordered_map<std::string, WithinEnum>::iterator Enums_it;
struct Context{
    bool in_func = false; // check if entering function
    bool is_init = false; // check if function/variable is initialised
    bool in_while = false; // check if entering while loop
    bool in_if = false; // check if in if-else body
    bool is_cond = false; // check if expression is a condition
    bool main_func = false; // check for main function
    bool func_param = false; // check if function has parameters
    bool var_param = false; // check if variable has parameters
    bool elif_block = false; // check for more else-if blocks
    //bool func_decl = false; // check if it is a function declaration or a global variable
    bool is_GlobalVar = false; // check if it is a global variable

    std::string what_typeSpec = "0";
    std::string var_iden = "0";
    std::string FuncName = "0";
    bool got_func_name = true;
    int var_val = 0;
    int indent = 0; // stores indentation level
    int brackets = 0; // stores parentheses nesting level

    bool is_LocalVar = false;
    int frame_offset_counter = 0;

    bool is_return = false;
    int returnNum = 0;
    bool return_var = false;
    bool is_solving = false;
    bool is_firststep = true;
    std::vector<std::string> solving_out_constant;
    std::vector<Bindings*> solving_out; 
    int stack_offset = 0;
    int function_call = 0;
    std::string function_name;
    std::vector<std::string> GlobalVarPy; // stores global variables (for Python)
    std::unordered_map<std::string, Bindings*> GlobalVar; // stores global variables
    std::unordered_map<std::string, Bindings*> LocalVar; // stores local variables
    std::vector<std::string> break_number;
    //std::vector<bool> firststepchecker;
    int gen_label = 1;
    bool return_are_u_single = true;
    std::string* enum_name = NULL;
    int enumerator_start = 0;
    std::vector<std::string> enumoperators;
    std::vector<std::pair<std::string, std::string>> enumoperands;


    bool is_array = false; // check if it is an array
    bool store_arr_vals = false; // check if array is initialised
    int arr_size = 0;
    std::vector<std::string> arr_vals;
    bool arr_access = false;
    std::string arr_name;
    int arr_index = -1;
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