%option noyywrap

%{
    // Avoid error "error: 'fileno' was not declared in this scope"
    extern "C"  int fileno(FILE *stream);

    #include "parser.tab.hpp"
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
"-"                 { return MINUS;}
"*"                 { return ASTERISK;}
"/"                 { return DIV;}
"%"                 { return MOD;}
"~"                 { return TILDE;}
"<"                 { return LT;}
"<"                 { return GT;}
"|="                { return OREQUAL;}
"^="                { return XOREQUAL;}
"|"                 { return BITWISE_OR;}
"&"                 { return BITWISE_AND;}
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
"const"             { return CONST;}
"volatile"          { return VOLATILE;}
"struct"            { return STRUCT;}
"union"             { return UNION;}
"enum"              { return ENUM;}
"ellipsis"          { return ELLIPSIS;}
"if"                { return IF;}
"else"              { return ELSE;}
"switch"            { return SWITCH;}
"case"              { return CASE;}
"default"           { return DEFAULT;}
"for"               { return FOR;}
"do"                { return DO;}
"while"             { return WHILE;}
"goto"              { return GOTO;}
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

.                   { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s){
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
    
}