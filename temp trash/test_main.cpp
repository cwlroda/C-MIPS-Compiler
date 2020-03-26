#include "test.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>

TokenValue yylval;
int main(){

    while(1){
        TokenType type = (TokenType)yylex();
        if(type==None){
            break;
        }
        else if(type == IDENTIFIER){
            std::cout << "identifier" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == INT){
            std::cout << "integer" << std::endl;
            std::cout << *yylval.wordValue << std::endl;

        }
        else if(type == RETURN) {
            std::cout << "return" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == INTEGER_CONSTANT){
            std::cout << "constant" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == FLOATING_CONSTANT){
            std::cout << "constant" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == CHARACTER_CONSTANT){
            std::cout << "character constant" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == STRING_LITERAL){
            std::cout << "string literal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == SEMICOLON){
            std::cout << "semicolon" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == INCREMENT){
            std::cout << "increment" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == DECREMENT){
            std::cout << "decrement" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LSHIFT){
            std::cout << "lshift" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == RSHIFT){
            std::cout << "rshift" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LE){
            std::cout << "less equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == GE){
            std::cout << "greater equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == EQUALITY){
            std::cout << "equality" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == NOTEQUAL){
            std::cout << "not equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == ARROW){
            std::cout << "arrow" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == DOT){
            std::cout << "dot" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LOGICAL_OR){
            std::cout << "logical or" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LOGICAL_AND){
            std::cout << "logicl and" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == PLUSEQUAL){
            std::cout << "plus equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == MULEQUAL){
            std::cout << "mul equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == DIVEQUAL){
            std::cout << "div equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == MODEQUAL){
            std::cout << "mod equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == MINUSEQUAL){
            std::cout << "minus equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == ANDEQUAL){
            std::cout << "and equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LSHIFTEQUAL){
            std::cout << "lshift equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == RSHIFTEQUAL){
            std::cout << "rshift equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == EQUAL){
            std::cout << "equal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == PLUS){
            std::cout << "plus" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == MINUS){
            std::cout << "minus" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == ASTERISK){
            std::cout << "asterisk" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == DIV){
            std::cout << "div" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == MOD){
            std::cout << "mod" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == TILDE){
            std::cout << "tilde" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LT){
            std::cout << "less than" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == GT){
            std::cout << "greater than" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == OREQUAL){
            std::cout << "OrEqual" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == XOREQUAL){
            std::cout << "xorequal" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == BITWISE_OR){
            std::cout << "bitwiseor" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == AMPERSAND){
            std::cout << "ampersand" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == EXCLAMATION){
            std::cout << "exclamation" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == QUESTION){
            std::cout << "question" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == XOR){
            std::cout << "xor" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == TYPEEDEF){
            std::cout << "typedef" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == EXTERN){
            std::cout << "extern" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == STATIC){
            std::cout << "static" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == AUTO){
            std::cout << "auto" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == REGISTER){
            std::cout << "register" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == VOID){
            std::cout << "void" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == CHAR){
            std::cout << "char" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == SHORT){
            std::cout << "short" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LONG){
            std::cout << "long" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == FLOAT){
            std::cout << "float" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == DOUBLE){
            std::cout << "double" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == SIGNED){
            std::cout << "signed" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == UNSIGNED){
            std::cout << "unsigned" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == STRUCT){
            std::cout << "struct" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == ENUM){
            std::cout << "enum" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == ELLIPSIS){
            std::cout << "ellipsis" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == IF){
            std::cout << "if" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == ELSE){
            std::cout << "else" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == SWITCH){
            std::cout << "switch" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == CASE){
            std::cout << "case" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == DEFAULT){
            std::cout << "defaultn" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == FOR){
            std::cout << "for" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == DO){
            std::cout << "do" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == WHILE){
            std::cout << "while" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == CONTINUE){
            std::cout << "continue" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == BREAK){
            std::cout << "break" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == RETURN){
            std::cout << "return" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LB){
            std::cout << "lb" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == RB){
            std::cout << "rb" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LSB){
            std::cout << "lsb" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == RSB){
            std::cout << "rsb" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == LCB){
            std::cout << "lcb" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == RCB){
            std::cout << "rcb" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == COLON){
            std::cout << "colon" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == COMMA){
            std::cout << "comma" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == QUOTE){
            std::cout << "quote" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == DOUBLE_QUOTE){
            std::cout << "doublequote" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == BACKSLASH){
            std::cout << "backslash" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
        else if(type == HEX_ESCAPE){
            std::cout << "hexescape" << std::endl;
            std::cout << *yylval.wordValue << std::endl;
        }
    }
    return 0;
}