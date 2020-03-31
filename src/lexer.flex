%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);
extern FILE *yyin;

#include "parser.tab.hpp"
%}

%%

"typedef"           { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return TYPEDEF; }
"sizeof"           { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return SIZEOF; }
"int"               { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return INT; }
"char"              { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return CHAR; }
"float"             { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return FLOAT; }
"double"            { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return DOUBLE; }
"unsigned"          { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return UNSIGNED; }
"struct"            { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return STRUCT; }
"enum"              { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return ENUM; }
"if"                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return IF; }
"else"              { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return ELSE; }
"switch"            { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return SWITCH; }
"case"              { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return CASE; }
"default"           { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return DEFAULT; }
"for"               { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return FOR; }
"while"             { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return WHILE; }
"continue"          { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return CONTINUE; }
"break"             { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return BREAK; }
"return"            { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return RETURN; }
"<<="               { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return LSHIFTEQUAL; }
">>="               { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return RSHIFTEQUAL; }
";"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return SEMICOLON; }
"++"                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return INCREMENT; }
"--"                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return DECREMENT; }
"<<"                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return LSHIFT; }
">>"                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return RSHIFT; }
"<="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return LE; }
">="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return GE; }
"=="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return EQUALITY; }
"!="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return NOTEQUAL; }
"->"                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return ARROW; }
"."                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return DOT; }
"||"                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return LOGICAL_OR; }
"&&"                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return LOGICAL_AND; }
"+="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return PLUSEQUAL; }
"*="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return MULEQUAL; }
"/="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return DIVEQUAL; }
"%="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return MODEQUAL; }
"-="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return MINUSEQUAL; }
"&="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return ANDEQUAL; }
"|="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return OREQUAL; }
"^="                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return XOREQUAL; }
"="                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return EQUAL; }
"+"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return PLUS; }
"-"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return MINUS; }
"*"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return ASTERISK; }
"/"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return DIV; }
"%"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return MOD; }
"~"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return TILDE; }
"<"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return LT; }
">"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return GT; }
"|"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return BITWISE_OR; }
"&"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return AMPERSAND; }
"!"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return EXCLAMATION; }
"?"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return QUESTION; }
"\^"                { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return XOR; }
"("                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return LB; }
")"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return RB; }
"["                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return LSB; }
"]"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return RSB; }
"{"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return LCB; }
"}"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return RCB; }
":"                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return COLON; }
","                 { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return COMMA; }

[0-9]+              { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return CONSTANT; }
[A-Za-z_][A-Za-z0-9_]*              { yylval.str=new std::string(yytext); /* ECHO; std::cout << std::endl; */ return IDENTIFIER; }


[ \t\v\n\f\r]*		{;}

.                   { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}
