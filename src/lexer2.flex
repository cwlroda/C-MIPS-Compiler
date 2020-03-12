%option noyywrap
%option yylineno

%{
#include <iostream>
#include <string>
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "test.hpp"
%}

%%

"int"               { return INT; }
"return"            { return RETURN; }
[0-9]*\.[0-9]+([eE][+-]?[0-9]+)?[fFlL]?                 { return FLOATING_CONSTANT; }
[0-9]+\.([eE][+-]?[0-9]+)?[fFlL]?                       { return FLOATING_CONSTANT; }
[0-9]+[eE][+-]?[0-9]+[fFlL]?                            { return FLOATING_CONSTANT; }

[1-9][0-9]*(([uU][lL]?)|([lL]?[Uu])|([uU]?[lL])|([lL][uU]?))? { return INTEGER_CONSTANT; }
0[0-7]*(([uU][lL]?)|([lL]?[Uu])|([uU]?[lL])|([lL][uU]?))? { return INTEGER_CONSTANT; }
0[xX][0-9a-fA-F]+(([uU][lL]?)|([lL]?[Uu])|([uU]?[lL])|([lL][uU]?))? { return INTEGER_CONSTANT; }

L?\'([^\\\'\n]|\\\'|\\\"|\\\?|\\\?|\\\\|\\a|\\b|\\f|\\n|\\r|\\t|\\v|\\[0-7][0-7]?[0-7]?|\\x[0-9a-fA-F]+)+\'   { return CHARACTER_CONSTANT; }
L?\"([^\\\"\n]|\\\'|\\\"|\\\?|\\\?|\\\\|\\a|\\b|\\f|\\n|\\r|\\t|\\v|\\[0-7][0-7]?[0-7]?|\\x[0-9a-fA-F]+)+\"   { return STRING_LITERAL; }

[ \t\r\n]+		    {;}

.                   { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
    fprintf (stderr, "Parse error : %s\n", s);
    exit(1);
}
