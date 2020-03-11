%option noyywrap

%{
    #include "test.hpp"
    // Avoid error "error: 'fileno' was not declared in this scope"
    extern "C"  int fileno(FILE *stream);

    
%}

%%
"sizeof"            { return SIZEOF; }
";"                 { return SEMICOLON; }
"++"                { return INCREMENT;}
"--"                { return DECREMENT;}
"<<"                { return LSHIFT;}
">>"                { return RSHIFT;}
"<="                { return LE;}
">="                { return GE;}
"=="                { return EQUALITY;}
"!="                { return NOTEQUAL;}
"->"                { return ARROW;}
"."                 { return DOT;}
"||"                { return LOGICAL_OR;}
"&&"                { return LOGICAL_AND;}
"+="                { return PLUSEQUAL;}
"*="                { return MULEQUAL;}
"/="                { return DIVEQUAL;}
"%="                { return MODEQUAL;}
"-="                { return MINUSEQUAL;}
"&="                { return ANDEQUAL;}
"<<="               { return LSHIFTEQUAL;}
">>="               { return RSHIFTEQUAL;}
"="                 { return EQUAL;}
"+"                 { return PLUS;}

%%