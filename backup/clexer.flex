%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "cparser.tab.hpp"
%}

%%
[\{]             { return T_LCURLY; }
[\}]             { return T_RCURLY; }
[\;]             { return T_SEMICOLON; }
[\,]             { return T_COMMA; }

[\(]             { return T_LBRACKET; }
[\)]             { return T_RBRACKET; }

"int"             { return T_INT; }
"char"            { return T_CHAR; }
"if"              { return T_IF; }
"else"            { return T_ELSE; }





[a-zA-Z][a-zA-Z0-9]*   { yylval.string=new std::string(yytext); return T_VAR; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
