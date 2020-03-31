#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <iostream>
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
    int size = 0;

    bool is_pointer = false;
    bool is_init = false;
    bool is_arr = false;
    bool is_parameter = false;
};
struct WithinEnum{
    std::unordered_map<std::string, int> enummap;
    int enumcounter = 0;
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
     bool empty_var = false; // check if variable has no value upon declaration

    std::string what_typeSpec = "0";
    std::string var_iden = "0";
    std::string FuncName = "0";
    bool got_func_name = true;
    int var_val = 0;
    int indent = 0; // stores indentation level
    int brackets = 0; // stores parentheses nesting level

    bool is_LocalVar = false;
    int frame_offset_counter = 0;
    int NeededMem = 0;
    
    bool is_return = false;
    int returnNum = 0;
    bool return_var = false;
    bool is_solving = false;
    bool is_firststep = true;
    //function parameter stuffs
    int parameterlist = 0;
    bool getting_parameters = false;
    int morethanfour = 4;
    int functionregister = 4; //for extra memory allocation
    std::string parametername;
    bool getting_parametername = false;
    bool getting_functionname = false;
    std::string functionname;
    int parameteroffset = 0;

    bool is_func = false; // check if need the return value of function
    bool is_a_parameter = false;
    
    bool is_sizeof = false;
    bool sizeof_type = false; // checks if sizeof contains a type
    //switch statement stuffs
    std::vector<int> nested_switch; //for every nested switch statement, push back this
    // for every case in the switch statement, the last element of this will increment
    std::unordered_map<int, Statement*> defaultstatemap; 
    int saved_register_counter = 8;
    bool is_switch = false;
    
    //solving expressions
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
    std::vector<std::pair<std::string, std::string> > enumoperands;
    WithinEnum* enumgen;
    std::unordered_map<std::string, WithinEnum> Enums;
    std::unordered_map<std::string, WithinEnum>::iterator Enums_it;
    bool is_enum = false;

    bool is_array = false; // check if it is an array
    bool store_arr_vals = false; // check if array is initialised
    int arr_size = 0;
    std::vector<std::string> arr_vals;
    bool arr_access = false;
    std::string arr_name;
    int arr_index = -1;
    bool global_arr = false;

    bool searchupdate(std::pair<std::string, std::string>& operand, std::unordered_map<std::string, int> variable_map){
        if(operand.first == "variable"){
            bool found = false;
            std::unordered_map<std::string,int>::iterator it;  
            for(it=variable_map.begin(); it!=variable_map.end(); it++){
                if(it->first == operand.second){
                    found = true;
                    operand.first = "constant";
                    operand.second = std::to_string(it->second);
                    break;
                }
            }
            return true;
        }
    }

    int int_house_solver(int first, int second, std::string operatorr){
        if(operatorr == "||"){
            first = first||second;
        }
        if(operatorr == "&&"){
            first = first&&second;
        }
        if(operatorr == "|"){
            first = first|second;
        }
        if(operatorr == "^"){
            first = first^second;
        }
        if(operatorr == "&"){
            first = first&second;
        }
        if(operatorr == "=="){
            first = first==second;
        }
        if(operatorr == "<"){
            first = first<second;
        }
        if(operatorr == ">"){
            first = first>second;
        }
        if(operatorr == "<="){
            first = first<=second;
        }
        if(operatorr == ">="){
            first = first>=second;
        }
        if(operatorr == "<<"){
            first = first<<second;
        }
        if(operatorr == ">>"){
            first = first>>second;
        }
        if(operatorr == "+"){
            first = first+second;
        }
        if(operatorr == "-"){
            first = first-second;
        }
        if(operatorr == "*"){
            first = first*second;
        }
        if(operatorr == "/"){
            first = first/second;
        }
        if(operatorr == "%"){
            first = first%second;
        }
        return first;
    }

    void ExprHelper(std::ostream& out){
        if((is_firststep == true || is_cond)){
            if(solving_out_constant.back() == ""){
                if(!solving_out.back()->is_parameter){
                    out << "\tlw\t\t$2," << solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                else{
                    out << "\tlw\t\t$2," << NeededMem -8 + solving_out.back()->frame_offset << "($fp)" << std::endl;
                }
                solving_out.pop_back();
                solving_out_constant.pop_back();
                out << "\tnop" << std::endl;
            }
            else{
                out << "\tli\t\t$2," << solving_out_constant.back() << std::endl;
                solving_out_constant.pop_back();
            }

            is_firststep = false;
        }
    }

    void ExprHelperRHS(std::ostream& out){
        if(solving_out_constant.back() == ""){
            if(!solving_out.back()->is_parameter){
                out << "\tlw\t\t$3," << solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            else{
                out << "\tlw\t\t$3," << NeededMem -8 + solving_out.back()->frame_offset << "($fp)" << std::endl;
            }
            solving_out.pop_back();
            solving_out_constant.pop_back();
            out << "\tnop" << std::endl;
        }
        else{
            out << "\tli\t\t$3," << solving_out_constant.back() << std::endl;
            solving_out_constant.pop_back();
        }
    }
};


#endif