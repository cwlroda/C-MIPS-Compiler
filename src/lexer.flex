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

"\("                 { ECHO; return LB; }
"\)"                 { ECHO; return RB; }
"\{"                 { ECHO; return LCB; }
"\}"                 { ECHO; return RCB; }
"\["                 { ECHO; return LSB; }
"\]"                 { ECHO; return RSB; }

"\;"                 { ECHO; return SEMICOLON; }

[ \t\r\n]*		    {;}

.                   { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}
