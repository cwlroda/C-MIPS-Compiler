%code requires{
  #include "../include/ast.hpp"

  #include <cassert>
  #include <math.h>

  extern nodePtr g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  nodePtr expr;
  double number;
  std::string *string;
}

%token T_INT T_CHAR T_RETURN
%token T_IF T_ELSE
%token T_PLUS T_MINUS
%token T_LBRACKET T_RBRACKET T_LCURLY T_RCURLY
%token T_VAR
%token T_SEMICOLON T_COMMA

%type <expr> STATEMENT RETURN EXPR
%type <expr> FUNC
%type <expr> PROG PARAM SCOPE
%type <expr> IF_ELSE
%type <string> T_VAR T_INT T_CHAR
%type <string> TYPE

%start ROOT

%%

/* The TODO notes a are just a guide, and are non-exhaustive.
   The expectation is that you do each one, then compile and test.
   Testing should be done using patterns that target the specific
   feature; the testbench is there to make sure that you haven't
   broken anything while you added it.
*/

ROOT: PROG    { g_root = $1; };

PROG: PROG FUNC 	    { $$ = new Top($2, $1);}
    | FUNC            { $$ = new Top($1, NULL); }

FUNC: TYPE T_VAR T_LBRACKET PARAM T_RBRACKET T_LCURLY SCOPE T_RCURLY    { $$ = new FuncDef(*$1, *$2, $4, $7); }
    | TYPE T_VAR T_LBRACKET T_RBRACKET T_LCURLY SCOPE T_RCURLY          { $$ = new FuncDef(*$1, *$2, NULL, $6); }
    | TYPE T_VAR T_LBRACKET PARAM T_RBRACKET T_SEMICOLON                { $$ = new FuncDecl(*$1, *$2, $4); }
    | TYPE T_VAR T_LBRACKET T_RBRACKET T_SEMICOLON                      { $$ = new FuncDecl(*$1, *$2, NULL); }

TYPE: T_INT     { $$ = $1; }
    | T_CHAR    { $$ = $1; }

PARAM: PARAM T_COMMA TYPE T_VAR  { $$ = new Arg(*$3, *$4, $1); }
    |  TYPE T_VAR              { $$ = new Arg(*$1, *$2, NULL); }

SCOPE: SCOPE STATEMENT
    |  STATEMENT

STATEMENT: RETURN     { $$ = $1; }
        |  EXPR       { $$ = $1; }
        |  IF_ELSE    { $$ = $1; }

RETURN: T_RETURN EXPR T_SEMICOLON   { $$ = new Return($2); }
      | T_RETURN T_SEMICOLON        { $$ = new Return(NULL); }

IF_ELSE: T_IF EXPR STATEMENT T_ELSE STATEMENT   { $$ = new IfElse($2, $3, $5); }
      |  T_IF EXPR STATEMENT                    { $$ = new If($2, $3); }

EXPR: EXPR T_PLUS EXPR  { $$ = new Add($1, $3); }
    | EXPR T_MINUS EXPR  { $$ = new Sub($1, $3) }
%%

nodePtr g_root; // Definition of variable (to match declaration earlier)

nodePtr parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
