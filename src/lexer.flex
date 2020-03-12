%option noyywrap
%option yylineno

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);
extern FILE *yyin;

#include "parser.tab.hpp"
%}

%%

"int"               { yylval.string=new std::string(yytext); ECHO; return INT; }
"return"            { yylval.string=new std::string(yytext); ECHO; return RETURN; }

[0-9]+              { yylval.string=new std::string(yytext); ECHO; return CONSTANT; }
[a-z]+              { yylval.string=new std::string(yytext); ECHO; return IDENTIFIER; }

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
"-"                 { return MINUS;}
"*"                 { return ASTERISK;}
"/"                 { return DIV;}
"%"                 { return MOD;}
"~"                 { return TILDE;}
"<"                 { return LT;}
">"                 { return GT;}
"|="                { return OREQUAL;}
"^="                { return XOREQUAL;}
"|"                 { return BITWISE_OR;}
"&"                 { return AMPERSAND;}
"!"                 { return EXCLAMATION;}
"?"                 { return QUESTION;}
"^"                 { return XOR;}
"typedef"           { return TYPEDEF;}
"extern"            { return EXTERN;}
"static"            { return STATIC;}
"auto"              { return AUTO;}
"register"          { return REGISTER;}
"void"              { return VOID;}
"char"              { return CHAR;}
"short"             { return SHORT;}
"int"               { return INT;}
"long"              { return LONG;}
"float"             { return FLOAT;}
"double"            { return DOUBLE;}
"signed"            { return SIGNED;}
"unsigned"          { return UNSIGNED;}
"struct"            { return STRUCT;}
"enum"              { return ENUM;}
"..."               { return ELLIPSIS;}
"if"                { return IF;}
"else"              { return ELSE;}
"switch"            { return SWITCH;}
"case"              { return CASE;}
"default"           { return DEFAULT;}
"for"               { return FOR;}
"do"                { return DO;}
"while"             { return WHILE;}
"continue"          { return CONTINUE;}
"break"             { return BREAK;}
"return"            { return RETURN;}
"("                 { return LB;}
")"                 { return RB;}
"["                 { return LSB;}
"]"                 { return RSB;}
"{"                 { return LCB;}
"}"                 { return RCB;}
":"                 { return COLON;}
","                 { return COMMA;}
[']                 { return QUOTE; }
["]                 { return DOUBLE_QUOTE; }
\\                  { return BACKSLASH; }
\x                  { return HEX_ESCAPE; }
\''.^[\'\\\n]\'     { return C_CHAR_SET; }
\"'.^[\"\\\n]\"     { return S_CHAR_SET; }

L?\'(\\[0-7][0-7]?[0-7]?)|(\x[0-9a-fA-F]+)

[0-9]*\.[0-9]+([eE][+-]?[0-9]+)?[fFlL]?                 { return FLOATING_CONSTANT; }
[0-9]+\.([eE][+-]?[0-9]+)?[fFlL]?                       { return FLOATING_CONSTANT; }
[0-9]+[eE][+-]?[0-9]+[fFlL]?                            { return FLOATING_CONSTANT; }

[1-9][0-9]*(([uU][lL]?)|([lL]?[Uu])|([uU]?[lL])|([lL][uU]?))? { return INTEGER_CONSTANT; }
0[0-7]*(([uU][lL]?)|([lL]?[Uu])|([uU]?[lL])|([lL][uU]?))? { return INTEGER_CONSTANT; }
0[xX][0-9a-fA-F]+(([uU][lL]?)|([lL]?[Uu])|([uU]?[lL])|([lL][uU]?))? { return INTEGER_CONSTANT; }

"("                 { return LB; }
")"                 { return RB; }
"{"                 { return LCB; }
"}"                 { return RCB; }
"["                 { return LSB; }
"]"                 { return RSB; }

"\;"                 { ECHO; return SEMICOLON; }

[ \t\r\n]*		    {;}

.                   { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}
