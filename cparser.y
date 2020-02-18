%code requires{
  #include "include/ast.hpp"

  #include <cassert>
  #include <math.h>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const nodePtr *expr;
  double number;
  std::string *string;
}

%token L_CURLY R_CURLY 
%token L_BRACKET R_BRACKET
%token END_INSTRUCTION
%token NUMBER VARIABLE TEXT
%token INT32 STRING IF

%type <number> NUMBER
%type <string> VAR TEXT IF INT CHAR

%start ROOT

%%

/* The TODO notes a are just a guide, and are non-exhaustive.
   The expectation is that you do each one, then compile and test.
   Testing should be done using patterns that target the specific
   feature; the testbench is there to make sure that you haven't
   broken anything while you added it.
*/

ROOT: PROGRAM_LIST{ g_root = $1; };

PROG: PROG FUNCTION 	{ $$ = new Top_List($2, $1);}
    |	PROG G_VAR    	{ $$ = new Top_List($2, $1); }
    |	PROG G_ARR		{ $$ = new Top_List($2, $1); }
    | 	FUNC            { $$ = new Top_List($1, NULL); }
    | 	G_VAR           { $$ = new Top_List($1, NULL); }
    | 	G_ARR			{ $$ = new Top_List($1, NULL); }

FUNC: TYPE VAR L_BRACKET PARAM R_BRACKET L_CURLY SCOPE R_CURLY  { $$ = new FuncDef(*$1, *$2, $4, $7); }
    | 	TYPE VAR L_BRACKET R_BRACKET L_CURLY SCOPE R_CURLY      { $$ = new FuncDef(*$1, *$2, NULL, $6); }
    | 	TYPE VAR L_BRACKET PARAM R_BRACKET SEMICOLON            { $$ = new FuncDecl(*$1, *$2, $4); }
    | 	TYPE VAR L_BRACKET R_BRACKET SEMICOLON                  { $$ = new FuncDecl(*$1, *$2, NULL); }

TYPE: INT     { $$ = $1; }
    |   CHAR    { $$ = $1; }

PARAM: PARAM, COMMA, TYPE, VAR { $$ = new Arg(*$3, *4, $1); }
    |   TYPE VAR { $$ = new Arg(*$3, *$4, NULL)}


%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
