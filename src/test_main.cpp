#include "test.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>

int main(){

    while(1){
        TokenType type = (TokenType)yylex();
        if(type==None){
            break;
        }
        else if(type == INT){
            std::cout << "integer" << std::endl;

        }
        else if(type == RETURN) {
            std::cout << "return" << std::endl;
        }
        else if(type == FLOATING_CONSTANT){
            std::cout << "floating constant" << std::endl;
        }
        else if(type == INTEGER_CONSTANT){
            std::cout << "integer constant" << std::endl;
        }
        else if(type == CHARACTER_CONSTANT){
            std::cout << "character constant" << std::endl;
        }
        else if(type == STRING_LITERAL){
            std::cout << "string literal" << std::endl;
        }
    }
    return 0;
}