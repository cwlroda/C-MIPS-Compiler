%option noyywrap
%option yylineno

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);
extern FILE *yyin;
extern FILE *yyout;

#include "parser.tab.hpp"
%}

%%

"int"               { yylval.string=new std::string(yytext); return INT; }
"return"            { yylval.string=new std::string(yytext); return RETURN; }

[0-9]               { yylval.string=new std::string(yytext); return CONSTANT; }
[a-z]+              { yylval.string=new std::string(yytext); return IDENTIFIER; }

"("                 { return LB; }
")"                 { return RB; }
"{"                 { return LCB; }
"}"                 { return RCB; }
"["                 { return LSB; }
"]"                 { return RSB; }

[ \t\r\n]+		    {;}

.                   { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}
