#ifndef test_hpp
#define test_hpp

#include <string>

enum TokenType{
    None = 0,
    INT = 1,
    RETURN = 2,
    CONSTANT = 3,
    IDENTIFIER = 4,
    SEMICOLON = 5,
    INCREMENT = 6,
    DECREMENT = 7,
    LSHIFT = 8,
    RSHIFT = 9,
    LE = 10,
    GE = 11,
    EQUALITY = 12,
    NOTEQUAL = 13,
    ARROW = 14,
    DOT = 15,
    LOGICAL_OR = 16,
    LOGICAL_AND = 17,
    PLUSEQUAL = 18,
    MULEQUAL = 19,
    DIVEQUAL = 20, 
    MODEQUAL = 21,
    FLOATING_CONSTANT = 22,
    INTEGER_CONSTANT = 23,
    CHARACTER_CONSTANT = 24,
    STRING_LITERAL = 25,
};


// This is a global variable used to move the
// attribute value from the lexer back to the
// main program.
// By convention it is called yylval, as that is
// the name that will be automatically generated
// by Bison (see next lab).

// This is the lexer function defined by flex. Each
// time it is called, a token type value will be
// returned.
extern int yylex();

#endif