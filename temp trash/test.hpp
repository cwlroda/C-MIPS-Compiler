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
    INTEGER_CONSTANT = 22,
    FLOATING_CONSTANT = 23,
    CHARACTER_CONSTANT = 24,
    STRING_LITERAL = 25,
    MINUSEQUAL= 26,
    LSHIFTEQUAL=28,
    RSHIFTEQUAL=29,
    EQUAL=30,
    PLUS=31,
    MINUS=32,
    ASTERISK=33,
    DIV=34,
    MOD=35,
    TILDE=36,
    LT=37,
    GT=38,
    OREQUAL=39,
    ANDEQUAL=40,
    XOREQUAL=41,
    BITWISE_OR=42,
    AMPERSAND=43,
    EXCLAMATION=44,
    QUESTION=45,
    XOR=46,
    TYPEEDEF=47,
    EXTERN=48,
    STATIC=49,
    AUTO=50,
    REGISTER=51,
    VOID=52,
    CHAR=53,
    SHORT=54,
    LONG=55,
    FLOAT=56,
    DOUBLE=57,
    SIGNED=58,
    UNSIGNED=59,
    STRUCT=60,
    ENUM=61,
    ELLIPSIS=62,
    IF=63,
    ELSE=64,
    SWITCH=65,
    CASE=66,
    DEFAULT=67,
    FOR=68,
    DO=69,
    WHILE=70,
    CONTINUE=71,
    BREAK=72,
    LB=73,
    RB=74,
    LSB=75,
    RSB=76,
    RCB=77,
    LCB=78,
    COLON=79,
    COMMA=80,
    QUOTE=81,
    DOUBLE_QUOTE=82,
    BACKSLASH=83,
    HEX_ESCAPE=84
};

union TokenValue{
    
    std::string *wordValue;
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


extern TokenValue yylval;

extern int yylex();

#endif