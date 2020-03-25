/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

    #include "../include/ast.hpp"

    #include <cassert>
    #include <fstream>

    extern FILE *yyin;
    extern const TranslationUnit *g_root; // A way of getting the AST out

    extern char *yytext;
	#define YYDEBUG_LEXER_TEXT yytext

    // ! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);

#line 67 "src/parser.tab.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    SEMICOLON = 262,
    INCREMENT = 263,
    DECREMENT = 264,
    LSHIFT = 265,
    RSHIFT = 266,
    LE = 267,
    GE = 268,
    EQUALITY = 269,
    NOTEQUAL = 270,
    ARROW = 271,
    DOT = 272,
    LOGICAL_OR = 273,
    LOGICAL_AND = 274,
    PLUSEQUAL = 275,
    MULEQUAL = 276,
    DIVEQUAL = 277,
    MODEQUAL = 278,
    MINUSEQUAL = 279,
    ANDEQUAL = 280,
    LSHIFTEQUAL = 281,
    RSHIFTEQUAL = 282,
    EQUAL = 283,
    PLUS = 284,
    MINUS = 285,
    ASTERISK = 286,
    DIV = 287,
    MOD = 288,
    TILDE = 289,
    LT = 290,
    GT = 291,
    OREQUAL = 292,
    XOREQUAL = 293,
    BITWISE_OR = 294,
    AMPERSAND = 295,
    EXCLAMATION = 296,
    QUESTION = 297,
    XOR = 298,
    TYPEDEF = 299,
    EXTERN = 300,
    STATIC = 301,
    AUTO = 302,
    REGISTER = 303,
    VOID = 304,
    CHAR = 305,
    SHORT = 306,
    INT = 307,
    LONG = 308,
    FLOAT = 309,
    DOUBLE = 310,
    SIGNED = 311,
    UNSIGNED = 312,
    CONST = 313,
    VOLATILE = 314,
    STRUCT = 315,
    ENUM = 316,
    ELLIPSIS = 317,
    IF = 318,
    ELSE = 319,
    SWITCH = 320,
    CASE = 321,
    DEFAULT = 322,
    FOR = 323,
    DO = 324,
    WHILE = 325,
    CONTINUE = 326,
    BREAK = 327,
    RETURN = 328,
    LB = 329,
    RB = 330,
    LSB = 331,
    RSB = 332,
    LCB = 333,
    RCB = 334,
    COLON = 335,
    COMMA = 336
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "src/parser.y"

    TranslationUnit *trans_unit;
    ExternalDeclaration *ext_decl;
    FunctionDefinition *func_def;
    Declaration *decl;
    DeclarationSpecifier *decl_spec;
    DeclarationList *decl_list;
    CompoundStatement *comp_state;
    StatementList *state_list;
    InitDeclarator *init_declr;
    Initializer *init;
    InitializerList *init_list;
    Declarator *declr;
    DirectDeclarator *dir_declr;
    Pointer *ptr;
    ParameterTypeList *param_type_list;
    ParameterList *param_list;
    ParameterDeclaration *param_decl;
    ConstantExpr *const_expr;
    AbstractDeclarator *abs_declr;
    DirectAbstractDeclarator *dir_abs_declr;
    ConditionalExpr *cond_expr;
    LogicalOrExpr *log_or_expr;
    LogicalAndExpr *log_and_expr;
    InclusiveOrExpr *incl_or_expr;
    ExclusiveOrExpr *excl_or_expr;
    AndExpr *and_expr;
    EqualityExpr *equal_expr;
    RelationalExpr *rel_expr;
    ShiftExpr *shift_expr;
    AdditiveExpr *add_expr;
    MultiplicativeExpr *mul_expr;
    Expr *expr;
    AssignmentExpr *ass_expr;
    AssignmentOperator *ass_op;
    UnaryExpr *un_expr;
    UnaryOperator *un_op;
    PostfixExpr *post_expr;
    PrimaryExpr *pri_expr;
    ArgumentExprList *arg_expr_list;
    CastExpr *cast_expr;
    TypeName *type_name;
    Statement *state;
    LabeledStatement *label_state;
    ExprStatement *expr_state;
    SelectionStatement *select_state;
    IterationStatement *it_state;
    JumpStatement *jump_state;
    StorageClassSpecifier *store_spec;
    TypeSpecifier *type_spec;
    StructSpecifier *struct_spec;
    StructDeclarationList *struct_decl_list;
    StructDeclaration *struct_decl;
    SpecifierQualifierList *spec_qual_list;
    StructDeclaratorList *struct_declr_list;
    StructDeclarator *struct_declr;
    EnumSpecifier *enum_spec;
    EnumeratorList *enum_list;
    Enumerator *enumr;

    std::string *str;

#line 223 "src/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
