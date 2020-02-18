%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "cparser.tab.hpp"
%}

%%
[{]             { return L_CURLY; }
[}]             { return R_CURLY; }
[;]             { return SEMICOLON; }

[(]             { return L_BRACKET; }
[)]             { return R_BRACKET; }

int             { return INT; }
char            { return CHAR; }
if              { return IF; }




[-]?[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return NUMBER; }
[a-zA-Z][a-zA-Z0-9]*   { yylval.string=new std::string(yytext); return VARIABLE; }
["].*["]               { yylval.string=new std::string(yytext); return TEXT; }
[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
