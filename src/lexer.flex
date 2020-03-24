%option noyywrap
%option yylineno

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);
extern FILE *yyin;

#include "parser.tab.hpp"
%}

%%

"typedef"           { yylval.string=new std::string(yytext); return TYPEDEF; }
"extern"            { yylval.string=new std::string(yytext); return EXTERN; }
"static"            { yylval.string=new std::string(yytext); return STATIC; }
"auto"              { yylval.string=new std::string(yytext); return AUTO; }
"register"          { yylval.string=new std::string(yytext); return REGISTER; }
"int"               { yylval.string=new std::string(yytext); return INT; }
"void"              { yylval.string=new std::string(yytext); return VOID; }
"char"              { yylval.string=new std::string(yytext); return CHAR; }
"short"             { yylval.string=new std::string(yytext); return SHORT; }
"long"              { yylval.string=new std::string(yytext); return LONG; }
"float"             { yylval.string=new std::string(yytext); return FLOAT; }
"double"            { yylval.string=new std::string(yytext); return DOUBLE; }
"signed"            { yylval.string=new std::string(yytext); return SIGNED; }
"unsigned"          { yylval.string=new std::string(yytext); return UNSIGNED; }
"struct"            { yylval.string=new std::string(yytext); return STRUCT; }
"enum"              { yylval.string=new std::string(yytext); return ENUM; }
"..."               { yylval.string=new std::string(yytext); return ELLIPSIS; }
"if"                { yylval.string=new std::string(yytext); return IF; }
"else"              { yylval.string=new std::string(yytext); return ELSE; }
"switch"            { yylval.string=new std::string(yytext); return SWITCH; }
"case"              { yylval.string=new std::string(yytext); return CASE; }
"default"           { yylval.string=new std::string(yytext); return DEFAULT; }
"for"               { yylval.string=new std::string(yytext); return FOR; }
"do"                { yylval.string=new std::string(yytext); return DO; }
"while"             { yylval.string=new std::string(yytext); return WHILE; }
"continue"          { yylval.string=new std::string(yytext); return CONTINUE; }
"break"             { yylval.string=new std::string(yytext); return BREAK; }
"return"            { yylval.string=new std::string(yytext); return RETURN; }

"<<="               { yylval.string=new std::string(yytext); return LSHIFTEQUAL; }
">>="               { yylval.string=new std::string(yytext); return RSHIFTEQUAL; }
";"                 { yylval.string=new std::string(yytext); return SEMICOLON; }
"++"                { yylval.string=new std::string(yytext); return INCREMENT; }
"--"                { yylval.string=new std::string(yytext); return DECREMENT; }
"<<"                { yylval.string=new std::string(yytext); return LSHIFT; }
">>"                { yylval.string=new std::string(yytext); return RSHIFT; }
"<="                { yylval.string=new std::string(yytext); return LE; }
">="                { yylval.string=new std::string(yytext); return GE; }
"=="                { yylval.string=new std::string(yytext); return EQUALITY; }
"!="                { yylval.string=new std::string(yytext); return NOTEQUAL; }
"->"                { yylval.string=new std::string(yytext); return ARROW; }
"."                 { yylval.string=new std::string(yytext); return DOT; }
"||"                { yylval.string=new std::string(yytext); return LOGICAL_OR; }
"&&"                { yylval.string=new std::string(yytext); return LOGICAL_AND; }
"+="                { yylval.string=new std::string(yytext); return PLUSEQUAL; }
"*="                { yylval.string=new std::string(yytext); return MULEQUAL; }
"/="                { yylval.string=new std::string(yytext); return DIVEQUAL; }
"%="                { yylval.string=new std::string(yytext); return MODEQUAL; }
"-="                { yylval.string=new std::string(yytext); return MINUSEQUAL; }
"&="                { yylval.string=new std::string(yytext); return ANDEQUAL; }
"|="                { yylval.string=new std::string(yytext); return OREQUAL; }
"^="                { yylval.string=new std::string(yytext); return XOREQUAL; }
"="                 { yylval.string=new std::string(yytext); return EQUAL; }
"+"                 { yylval.string=new std::string(yytext); return PLUS; }
"-"                 { yylval.string=new std::string(yytext); return MINUS; }
"*"                 { yylval.string=new std::string(yytext); return ASTERISK; }
"/"                 { yylval.string=new std::string(yytext); return DIV; }
"%"                 { yylval.string=new std::string(yytext); return MOD; }
"~"                 { yylval.string=new std::string(yytext); return TILDE; }
"<"                 { yylval.string=new std::string(yytext); return LT; }
">"                 { yylval.string=new std::string(yytext); return GT; }
"|"                 { yylval.string=new std::string(yytext); return BITWISE_OR; }
"&"                 { yylval.string=new std::string(yytext); return AMPERSAND; }
"!"                 { yylval.string=new std::string(yytext); return EXCLAMATION; }
"?"                 { yylval.string=new std::string(yytext); return QUESTION; }
"\^"                { yylval.string=new std::string(yytext); return XOR; }
"("                 { yylval.string=new std::string(yytext); return LB; }
")"                 { yylval.string=new std::string(yytext); return RB; }
"["                 { yylval.string=new std::string(yytext); return LSB; }
"]"                 { yylval.string=new std::string(yytext); return RSB; }
"{"                 { yylval.string=new std::string(yytext); return LCB; }
"}"                 { yylval.string=new std::string(yytext); return RCB; }
":"                 { yylval.string=new std::string(yytext); return COLON; }
","                 { yylval.string=new std::string(yytext); return COMMA; }

[0-9]+              { yylval.string=new std::string(yytext); return CONSTANT; }
[A-Za-z_][A-Za-z0-9_]*              { yylval.string=new std::string(yytext); return IDENTIFIER; }

[ \t\r\n]*		    { ; }

.                   { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}
