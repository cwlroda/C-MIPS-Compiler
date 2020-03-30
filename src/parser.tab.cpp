/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
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
#line 1 "src/parser.y" /* yacc.c:355  */

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

#line 116 "src/parser.tab.cpp" /* yacc.c:355  */

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
    CHAR = 299,
    INT = 300,
    FLOAT = 301,
    DOUBLE = 302,
    UNSIGNED = 303,
    TYPEDEF = 304,
    STRUCT = 305,
    ENUM = 306,
    IF = 307,
    ELSE = 308,
    SWITCH = 309,
    CASE = 310,
    DEFAULT = 311,
    FOR = 312,
    WHILE = 313,
    CONTINUE = 314,
    BREAK = 315,
    RETURN = 316,
    LB = 317,
    RB = 318,
    LSB = 319,
    RSB = 320,
    LCB = 321,
    RCB = 322,
    COLON = 323,
    COMMA = 324
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "src/parser.y" /* yacc.c:355  */

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
    TypeSpecifier *type_spec;
    StructSpecifier *struct_spec;
    StructDeclarationList *struct_decl_list;
    StructDeclaration *struct_decl;
    SpecifierQualifierList *spec_qual_list;
    StructDeclaratorList *struct_declr_list;
    StructDeclarator *struct_declr;
    EnumSpecifier *enum_spec;
    EnumeratorList *enum_list;
    Enumerator *enume;

    std::string *str;

#line 259 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 276 "src/parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   876

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  306

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   169,   169,   171,   172,   174,   175,   177,   178,   179,
     180,   182,   183,   185,   186,   187,   188,   190,   191,   193,
     194,   195,   196,   198,   199,   201,   202,   204,   205,   207,
     208,   210,   211,   213,   214,   215,   216,   217,   219,   220,
     222,   223,   225,   226,   227,   229,   231,   232,   233,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   245,   246,
     248,   249,   251,   252,   254,   255,   257,   258,   260,   261,
     263,   264,   265,   267,   268,   269,   270,   271,   273,   274,
     275,   277,   278,   279,   281,   282,   283,   284,   286,   287,
     289,   290,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   304,   305,   306,   307,   308,   309,   311,
     312,   313,   314,   315,   316,   318,   319,   320,   321,   322,
     323,   324,   325,   327,   328,   329,   330,   333,   334,   336,
     337,   339,   340,   342,   343,   344,   345,   346,   347,   349,
     350,   351,   353,   354,   356,   357,   358,   360,   361,   362,
     364,   365,   366,   368,   369,   370,   371,   372,   373,   374,
     376,   377,   378,   380,   381,   383,   385,   386,   388,   389,
     391,   392,   393,   395,   396,   397,   399,   400,   402,   403
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "SEMICOLON", "INCREMENT", "DECREMENT",
  "LSHIFT", "RSHIFT", "LE", "GE", "EQUALITY", "NOTEQUAL", "ARROW", "DOT",
  "LOGICAL_OR", "LOGICAL_AND", "PLUSEQUAL", "MULEQUAL", "DIVEQUAL",
  "MODEQUAL", "MINUSEQUAL", "ANDEQUAL", "LSHIFTEQUAL", "RSHIFTEQUAL",
  "EQUAL", "PLUS", "MINUS", "ASTERISK", "DIV", "MOD", "TILDE", "LT", "GT",
  "OREQUAL", "XOREQUAL", "BITWISE_OR", "AMPERSAND", "EXCLAMATION",
  "QUESTION", "XOR", "CHAR", "INT", "FLOAT", "DOUBLE", "UNSIGNED",
  "TYPEDEF", "STRUCT", "ENUM", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT",
  "FOR", "WHILE", "CONTINUE", "BREAK", "RETURN", "LB", "RB", "LSB", "RSB",
  "LCB", "RCB", "COLON", "COMMA", "$accept", "ROOT", "TRANSLATION_UNIT",
  "EXTERNAL_DECLARATION", "FUNCTION_DEFINITION", "DECLARATION",
  "DECLARATION_SPECIFIER", "DECLARATION_LIST", "COMPOUND_STATEMENT",
  "STATEMENT_LIST", "INIT_DECLARATOR", "INITIALIZER", "INITIALIZER_LIST",
  "DECLARATOR", "DIRECT_DECLARATOR", "POINTER", "PARAMETER_LIST",
  "PARAMETER_DECLARATION", "CONSTANT_EXPR", "ABSTRACT_DECLARATOR",
  "DIRECT_ABSTRACT_DECLARATOR", "CONDITIONAL_EXPR", "LOGICAL_OR_EXPR",
  "LOGICAL_AND_EXPR", "INCLUSIVE_OR_EXPR", "EXCLUSIVE_OR_EXPR", "AND_EXPR",
  "EQUALITY_EXPR", "RELATIONAL_EXPR", "SHIFT_EXPR", "ADDITIVE_EXPR",
  "MULTIPLICATIVE_EXPR", "EXPR", "ASSIGNMENT_EXPR", "ASSIGNMENT_OPERATOR",
  "UNARY_EXPR", "UNARY_OPERATOR", "POSTFIX_EXPR", "PRIMARY_EXPR",
  "ARGUMENT_EXPR_LIST", "CAST_EXPR", "TYPE_NAME", "STATEMENT",
  "LABELED_STATEMENT", "EXPR_STATEMENT", "SELECTION_STATEMENT",
  "ITERATION_STATEMENT", "JUMP_STATEMENT", "TYPE_SPECIFIER",
  "STRUCT_SPECIFIER", "STRUCT_DECLARATION_LIST", "STRUCT_DECLARATION",
  "SPECIFIER_QUALIFIER_LIST", "STRUCT_DECLARATOR_LIST",
  "STRUCT_DECLARATOR", "ENUM_SPECIFIER", "ENUMERATOR_LIST", "ENUMERATOR", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324
};
# endif

#define YYPACT_NINF -166

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-166)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     785,  -166,    20,  -166,  -166,  -166,  -166,  -166,   823,    22,
      32,    19,    36,   785,  -166,  -166,  -166,   118,   530,    62,
      40,   823,  -166,  -166,  -166,  -166,     3,   168,    30,    77,
      26,  -166,  -166,  -166,   133,   273,   238,  -166,   118,   530,
    -166,   342,   101,    62,  -166,   168,   168,   334,  -166,    15,
      77,    91,    74,  -166,  -166,  -166,   485,   530,  -166,    60,
    -166,  -166,   717,  -166,   756,   756,  -166,  -166,  -166,  -166,
    -166,  -166,    86,    89,   764,   106,   115,   134,   194,   198,
     764,   655,  -166,   303,  -166,   368,  -166,     6,   190,   187,
     189,   212,    25,    98,    51,   162,   155,     9,  -166,   838,
     764,   114,   193,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
     225,  -166,  -166,  -166,    35,     5,  -166,   197,   623,  -166,
    -166,  -166,   764,   191,   251,   195,   128,   764,  -166,    77,
    -166,   485,  -166,  -166,  -166,   446,   655,  -166,   764,  -166,
    -166,   764,   764,   202,  -166,  -166,   446,   704,   764,  -166,
    -166,    23,    66,   208,    -8,  -166,   407,  -166,  -166,   764,
     764,   764,   764,   764,   764,   764,   764,   764,   764,   764,
     764,   764,   764,   764,   764,   764,   764,   764,  -166,   764,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,   764,  -166,  -166,  -166,   262,   271,   603,   764,   554,
     524,  -166,    39,  -166,   138,  -166,   823,  -166,  -166,  -166,
     764,  -166,    15,  -166,  -166,  -166,  -166,   141,  -166,   213,
      73,    81,   446,  -166,   704,   109,  -166,  -166,   764,   793,
     169,  -166,  -166,   190,   171,   187,   189,   212,    25,    98,
      98,    51,    51,    51,    51,   162,   162,   155,   155,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,   110,    43,
    -166,   112,   214,  -166,   210,   138,   762,   532,  -166,  -166,
    -166,  -166,   485,  -166,   446,   446,  -166,   616,   446,  -166,
     764,  -166,   764,  -166,  -166,  -166,  -166,  -166,   120,  -166,
     215,  -166,   228,  -166,   446,   121,  -166,  -166,  -166,  -166,
    -166,   446,  -166,   446,  -166,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    33,    39,   153,   154,   155,   156,   157,    14,     0,
       0,     0,     0,     2,     4,     5,     6,     0,     0,    32,
       0,    16,   158,   159,    38,    13,   162,     0,   175,     0,
       0,     1,     3,    12,     0,    25,     0,    17,     0,     0,
      10,     0,     0,    31,    15,     0,   167,     0,   163,     0,
       0,   178,     0,   176,    34,    11,     0,     0,     8,   123,
     124,   125,     0,   143,     0,     0,   111,   112,   110,   113,
     109,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,   134,     0,    90,    58,    60,    62,
      64,    66,    68,    70,    73,    78,    81,     0,    88,   129,
       0,   103,   115,    84,    23,   133,   135,   136,   137,   138,
      25,    18,     9,    37,    44,     0,    40,     0,     0,   166,
     161,   164,     0,   170,     0,   168,     0,     0,   174,     0,
     123,     0,    26,    27,     7,     0,     0,   107,     0,   104,
     105,     0,     0,     0,    45,   129,     0,     0,     0,   150,
     151,     0,     0,     0,   132,    20,     0,    21,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,     0,
      96,    93,    94,    95,    97,   100,    98,    99,    92,   102,
     101,     0,   106,   121,   122,     0,     0,     0,     0,     0,
       0,    42,    46,    43,    48,    36,     0,    35,   160,   172,
       0,   165,     0,   173,   179,   177,    29,     0,   139,     0,
       0,     0,     0,   141,     0,     0,   152,   126,     0,     0,
      46,   131,    19,    61,     0,    63,    65,    67,    69,    71,
      72,    76,    77,    74,    75,    79,    80,    82,    83,    85,
      86,    87,    89,    91,   120,   119,   118,   127,     0,     0,
      57,     0,     0,    53,     0,    47,     0,     0,    41,   171,
     169,    28,     0,   108,     0,     0,   140,     0,     0,   130,
       0,   117,     0,   116,    56,    49,    52,    55,     0,    51,
       0,    30,   144,   146,     0,     0,   147,    59,   128,    54,
      50,     0,   148,     0,   145,   149
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,   278,  -166,    34,     0,   201,    14,   219,
    -166,  -126,  -166,    -5,   -17,    -1,   -39,    97,   -96,   -94,
    -165,   -63,  -166,   154,   153,   163,   152,   164,    83,    55,
      79,    82,   -66,   -52,  -166,    -7,  -166,  -166,  -166,  -166,
     -90,   180,   -40,  -166,  -140,  -166,  -166,  -166,   -18,  -166,
     281,   -28,   -29,  -166,   117,  -166,   277,   206
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    37,    38,    39,    84,    85,
      34,   132,   217,    18,    19,    20,   261,   116,   143,   262,
     204,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   191,    99,   100,   101,   102,   258,
     103,   153,   104,   105,   106,   107,   108,   109,    21,    22,
      47,    48,    49,   124,   125,    23,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      17,    24,   115,    43,   133,   216,    30,   224,    25,    46,
     192,   144,    35,    17,   151,   152,   178,   119,     1,   121,
     203,    44,     1,     2,   159,    26,   209,    46,    46,    46,
     226,   214,    40,   110,    16,    28,    31,   265,     1,   165,
     166,   114,     1,     1,   123,   158,     2,    16,   160,    58,
       2,     2,   154,   112,   229,   137,   200,   139,   140,   144,
     231,   171,   172,    46,   144,   265,     2,   145,   205,    45,
     152,   134,   152,   111,   206,   220,   221,    11,   179,   133,
      51,    11,   225,   122,   277,   249,   250,   251,    27,    54,
     121,   111,   179,   145,   234,   218,    50,   199,    29,   200,
      46,   199,    11,   200,   264,   117,   223,   154,   283,   201,
     167,   168,   179,   202,   269,   145,   158,   111,    46,   127,
     145,     1,   193,   194,    41,    33,    42,   252,   135,   227,
     195,   196,   259,   169,   170,   179,   274,   144,   279,   253,
      55,   128,   179,   129,   275,   257,   291,   144,   141,     2,
     179,   142,   145,   230,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   290,   278,   281,   146,   284,   197,   147,   179,   282,
      11,   206,   276,   299,   303,    43,   175,   176,   177,   206,
     179,   173,   174,   145,    30,   213,   148,   129,   202,   114,
     266,   149,   267,   145,   144,   150,   114,   123,   271,   161,
     272,   295,     3,     4,     5,     6,     7,   297,     9,    10,
     133,   145,   241,   242,   243,   244,   162,   288,   230,   114,
     298,   229,   163,   200,   292,   293,    57,    83,   296,   280,
     179,    59,    60,    61,    62,    63,    64,    65,   239,   240,
     245,   246,   164,    56,   302,   247,   248,   198,   211,   210,
     145,   304,   207,   305,   212,   254,   114,    66,    67,    68,
     222,   228,    69,   145,   255,   286,   273,   285,    70,    71,
     300,   301,     3,     4,     5,     6,     7,     8,     9,    10,
      72,    32,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    56,   156,   268,    36,    82,    59,    60,    61,    62,
      63,    64,    65,   233,   235,   237,   219,     3,     4,     5,
       6,     7,     8,     9,    10,   236,   118,   126,   238,   270,
       0,     0,    66,    67,    68,   215,     0,    69,     0,    36,
       0,     0,     0,    70,    71,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    72,     0,    73,    74,    75,
      76,    77,    78,    79,    80,    81,     0,     0,     0,    36,
     155,    59,    60,    61,    62,    63,    64,    65,     3,     4,
       5,     6,     7,     0,     9,    10,     3,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    66,    67,    68,
       0,   120,    69,     0,     0,   113,     0,     0,    70,    71,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
      72,     0,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    36,   157,    66,    67,    68,     0,
       0,    69,     0,     0,     0,     0,     0,    70,    71,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,    72,
       0,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    36,   232,    66,    67,    68,     0,     0,
      69,     0,     0,     0,     0,     0,    70,    71,   130,    60,
      61,    62,     0,    64,    65,     0,     0,     0,    72,     0,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    36,     0,    66,    67,    68,     0,     0,    69,
       0,     0,     0,     0,     0,    70,    71,   130,    60,    61,
      62,     0,    64,    65,     0,   130,    60,    61,    62,     0,
      64,    65,     0,     0,     0,     0,     0,    81,     0,     0,
       0,   131,     0,    66,    67,    68,     0,     1,    69,     0,
       0,    66,    67,    68,    70,    71,    69,     0,     0,     0,
       0,     0,    70,    71,     3,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     2,    81,     0,     0,   263,
       0,     0,     0,     0,    81,     0,    36,   289,     3,     4,
       5,     6,     7,     8,     9,    10,   130,    60,    61,    62,
       0,    64,    65,     0,     0,     0,   199,   260,   200,   130,
      60,    61,    62,     0,    64,    65,     0,     0,     0,     0,
       0,     0,    66,    67,    68,     0,     0,    69,     0,     0,
       0,     0,     0,    70,    71,    66,    67,    68,     0,     0,
      69,     0,     0,     0,     0,     0,    70,    71,   130,    60,
      61,    62,     0,    64,    65,    81,   256,     3,     4,     5,
       6,     7,     0,     9,    10,     0,     0,     0,    81,   294,
       0,     0,     0,     0,    66,    67,    68,     0,     0,    69,
     208,     0,     0,     0,     0,    70,    71,     0,     0,     3,
       4,     5,     6,     7,     0,     9,    10,   130,    60,    61,
      62,    63,    64,    65,     0,     0,     0,    81,     0,     0,
     130,    60,    61,    62,     0,    64,    65,     0,     0,     0,
       0,     0,     0,    66,    67,    68,     0,     0,    69,     0,
       0,     0,     0,     0,    70,    71,    66,    67,    68,     0,
       0,    69,     0,     0,     0,     0,     0,    70,    71,   130,
      60,    61,    62,     0,    64,    65,    81,   130,    60,    61,
      62,     0,    64,    65,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,    66,    67,    68,     1,     0,
      69,     0,     0,    66,    67,    68,    70,    71,    69,     0,
       0,     0,     0,     0,    70,    71,     3,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     2,     0,   138,     0,
       0,     0,     0,     0,     2,   287,    81,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     3,     4,     5,
       6,     7,     8,     9,    10,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,   229,   260,   200,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     3,     4,     5,
       6,     7,     8,     9,    10,   189,   190
};

static const yytype_int16 yycheck[] =
{
       0,     2,    41,    20,    56,   131,    11,   147,     8,    27,
     100,    74,    17,    13,    80,    81,     7,    46,     3,    47,
     114,    21,     3,    31,    18,     3,   122,    45,    46,    47,
       7,   127,    18,    38,     0,     3,     0,   202,     3,    14,
      15,    41,     3,     3,    49,    85,    31,    13,    42,    35,
      31,    31,    81,    39,    62,    62,    64,    64,    65,   122,
     154,    10,    11,    81,   127,   230,    31,    74,    63,    66,
     136,    57,   138,    39,    69,   141,   142,    62,    69,   131,
       3,    62,   148,    68,   224,   175,   176,   177,    66,    63,
     118,    57,    69,   100,   160,   135,    66,    62,    66,    64,
     118,    62,    62,    64,   200,     4,   146,   136,    65,   114,
      12,    13,    69,   114,   210,   122,   156,    83,   136,    28,
     127,     3,     8,     9,    62,     7,    64,   179,    68,    63,
      16,    17,   198,    35,    36,    69,    63,   200,   228,   191,
       7,    67,    69,    69,    63,   197,   272,   210,    62,    31,
      69,    62,   159,   154,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   267,    63,    63,    68,    63,    62,    62,    69,    69,
      62,    69,   222,    63,    63,   202,    31,    32,    33,    69,
      69,    29,    30,   200,   199,    67,    62,    69,   199,   199,
      62,     7,    64,   210,   267,     7,   206,   212,    67,    19,
      69,   277,    44,    45,    46,    47,    48,   280,    50,    51,
     272,   228,   167,   168,   169,   170,    39,   266,   229,   229,
     282,    62,    43,    64,   274,   275,    35,    36,   278,    68,
      69,     3,     4,     5,     6,     7,     8,     9,   165,   166,
     171,   172,    40,    28,   294,   173,   174,    64,     7,    68,
     267,   301,    65,   303,    69,     3,   266,    29,    30,    31,
      68,    63,    34,   280,     3,    65,    63,    63,    40,    41,
      65,    53,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    13,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    28,    83,   206,    66,    67,     3,     4,     5,     6,
       7,     8,     9,   159,   161,   163,   136,    44,    45,    46,
      47,    48,    49,    50,    51,   162,    45,    50,   164,   212,
      -1,    -1,    29,    30,    31,   129,    -1,    34,    -1,    66,
      -1,    -1,    -1,    40,    41,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    66,
      67,     3,     4,     5,     6,     7,     8,     9,    44,    45,
      46,    47,    48,    -1,    50,    51,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    29,    30,    31,
      -1,    67,    34,    -1,    -1,    63,    -1,    -1,    40,    41,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    66,    67,    29,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      -1,    -1,    -1,    66,    67,    29,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    52,    -1,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    66,    -1,    29,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,     3,     4,     5,
       6,    -1,     8,     9,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    66,    -1,    29,    30,    31,    -1,     3,    34,    -1,
      -1,    29,    30,    31,    40,    41,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    31,    62,    -1,    -1,    65,
      -1,    -1,    -1,    -1,    62,    -1,    66,    65,    44,    45,
      46,    47,    48,    49,    50,    51,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    62,    63,    64,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    29,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,     3,     4,
       5,     6,    -1,     8,     9,    62,    63,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      67,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48,    -1,    50,    51,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    62,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    29,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,     3,
       4,     5,     6,    -1,     8,     9,    62,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,     3,    -1,
      34,    -1,    -1,    29,    30,    31,    40,    41,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    44,    45,    46,    47,
      48,    49,    50,    51,    -1,    -1,    31,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    31,    63,    62,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    44,    45,    46,
      47,    48,    49,    50,    51,    37,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    31,    44,    45,    46,    47,    48,    49,    50,
      51,    62,    71,    72,    73,    74,    75,    76,    83,    84,
      85,   118,   119,   125,    85,    76,     3,    66,     3,    66,
      83,     0,    73,     7,    80,    83,    66,    75,    76,    77,
      78,    62,    64,    84,    76,    66,   118,   120,   121,   122,
      66,     3,   126,   127,    63,     7,    28,    77,    78,     3,
       4,     5,     6,     7,     8,     9,    29,    30,    31,    34,
      40,    41,    52,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    67,    77,    78,    79,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   105,
     106,   107,   108,   110,   112,   113,   114,   115,   116,   117,
      83,    75,    78,    63,    76,    86,    87,     4,   120,   122,
      67,   121,    68,    83,   123,   124,   126,    28,    67,    69,
       3,    66,    81,   103,    78,    68,    62,   105,    62,   105,
     105,    62,    62,    88,    91,   105,    68,    62,    62,     7,
       7,   102,   102,   111,   122,    67,    79,    67,   112,    18,
      42,    19,    39,    43,    40,    14,    15,    12,    13,    35,
      36,    10,    11,    29,    30,    31,    32,    33,     7,    69,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    37,
      38,   104,   110,     8,     9,    16,    17,    62,    64,    62,
      64,    83,    85,    89,    90,    63,    69,    65,    67,    88,
      68,     7,    69,    67,    88,   127,    81,    82,   112,   111,
     102,   102,    68,   112,   114,   102,     7,    63,    63,    62,
      85,    89,    67,    93,   102,    94,    95,    96,    97,    98,
      98,    99,    99,    99,    99,   100,   100,   101,   101,   110,
     110,   110,   103,   103,     3,     3,    63,   103,   109,   102,
      63,    86,    89,    65,    88,    90,    62,    64,    87,    88,
     124,    67,    69,    63,    63,    63,   112,   114,    63,   110,
      68,    63,    69,    65,    63,    63,    65,    63,    86,    65,
      88,    81,   112,   112,    63,   102,   112,    91,   103,    63,
      65,    53,   112,    63,   112,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    85,    85,
      86,    86,    87,    87,    87,    88,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    98,    98,    98,    98,    98,    99,    99,
      99,   100,   100,   100,   101,   101,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   106,
     106,   106,   106,   106,   106,   107,   107,   107,   107,   107,
     107,   107,   107,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   112,   112,   112,   112,   113,
     113,   113,   114,   114,   115,   115,   115,   116,   116,   116,
     117,   117,   117,   118,   118,   118,   118,   118,   118,   118,
     119,   119,   119,   120,   120,   121,   122,   122,   123,   123,
     124,   124,   124,   125,   125,   125,   126,   126,   127,   127
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     3,     3,
       2,     3,     2,     2,     1,     2,     1,     1,     2,     4,
       3,     3,     2,     1,     2,     1,     3,     1,     3,     1,
       3,     2,     1,     1,     3,     4,     4,     3,     2,     1,
       1,     3,     2,     2,     1,     1,     1,     2,     1,     3,
       4,     3,     3,     2,     4,     3,     3,     2,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     3,
       3,     2,     2,     1,     1,     1,     3,     1,     3,     1,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     1,     5,     7,     5,     5,     6,     7,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     2,     3,     2,     1,     1,     3,
       1,     3,     2,     5,     4,     2,     1,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 169 "src/parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].trans_unit); }
#line 1704 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), (yyvsp[-1].trans_unit)); }
#line 1710 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 172 "src/parser.y" /* yacc.c:1646  */
    { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), NULL); }
#line 1716 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 174 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ext_decl) = new ExternalDeclaration((yyvsp[0].func_def), NULL); }
#line 1722 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 175 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ext_decl) = new ExternalDeclaration(NULL, (yyvsp[0].decl)); }
#line 1728 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 177 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition((yyvsp[-3].decl_spec), (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1734 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 178 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition((yyvsp[-2].decl_spec), (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1740 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1746 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1752 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-2].decl_spec), (yyvsp[-1].init_declr)); }
#line 1758 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-1].decl_spec), NULL); }
#line 1764 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier(NULL, (yyvsp[0].decl_spec), (yyvsp[-1].str)); }
#line 1770 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier(NULL, NULL, (yyvsp[0].str)); }
#line 1776 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[-1].type_spec), (yyvsp[0].decl_spec), NULL); }
#line 1782 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 188 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[0].type_spec), NULL, NULL); }
#line 1788 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_list) = new DeclarationList(NULL, (yyvsp[0].decl)); }
#line 1794 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_list) = new DeclarationList((yyvsp[-1].decl_list), (yyvsp[0].decl)); }
#line 1800 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement((yyvsp[-2].decl_list), (yyvsp[-1].state_list)); }
#line 1806 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement((yyvsp[-1].decl_list), NULL); }
#line 1812 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement(NULL, (yyvsp[-1].state_list)); }
#line 1818 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement(NULL, NULL); }
#line 1824 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state_list) = new StatementList((yyvsp[0].state), NULL); }
#line 1830 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 199 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state_list) = new StatementList((yyvsp[0].state), (yyvsp[-1].state_list)); }
#line 1836 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 201 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_declr) = new InitDeclarator((yyvsp[0].declr), NULL); }
#line 1842 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_declr) = new InitDeclarator((yyvsp[-2].declr), (yyvsp[0].init)); }
#line 1848 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init) = new Initializer((yyvsp[0].ass_expr), NULL); }
#line 1854 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init) = new Initializer(NULL, (yyvsp[-1].init_list)); }
#line 1860 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_list) = new InitializerList((yyvsp[0].init), NULL); }
#line 1866 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_list) = new InitializerList((yyvsp[0].init), (yyvsp[-2].init_list)); }
#line 1872 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 210 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declr) = new Declarator((yyvsp[-1].ptr), (yyvsp[0].dir_declr)); }
#line 1878 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declr) = new Declarator(NULL, (yyvsp[0].dir_declr)); }
#line 1884 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 213 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, NULL, NULL, NULL, (yyvsp[0].str), NULL); }
#line 1890 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 214 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator((yyvsp[-1].declr), NULL, NULL, NULL, NULL, NULL); }
#line 1896 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 215 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), (yyvsp[-1].str), NULL, NULL, (yyvsp[-2].str)); }
#line 1902 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), NULL, (yyvsp[-1].param_list), NULL, NULL); }
#line 1908 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 217 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-2].dir_declr), NULL, NULL, NULL, NULL); }
#line 1914 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 222 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), NULL); }
#line 1920 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 223 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), (yyvsp[-2].param_list)); }
#line 1926 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), (yyvsp[0].declr), NULL); }
#line 1932 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 226 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), NULL, (yyvsp[0].abs_declr)); }
#line 1938 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_decl) = new ParameterDeclaration((yyvsp[0].decl_spec), NULL, NULL); }
#line 1944 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 229 "src/parser.y" /* yacc.c:1646  */
    { (yyval.const_expr) = new ConstantExpr((yyvsp[0].cond_expr)); }
#line 1950 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 245 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cond_expr) = new ConditionalExpr((yyvsp[0].log_or_expr), NULL, NULL); }
#line 1956 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 246 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cond_expr) = new ConditionalExpr((yyvsp[-4].log_or_expr), (yyvsp[-2].expr), (yyvsp[0].cond_expr)); }
#line 1962 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), NULL); }
#line 1968 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 249 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), (yyvsp[-2].log_or_expr)); }
#line 1974 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 251 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), NULL); }
#line 1980 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 252 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), (yyvsp[-2].log_and_expr)); }
#line 1986 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), NULL); }
#line 1992 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 255 "src/parser.y" /* yacc.c:1646  */
    { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), (yyvsp[-2].incl_or_expr)); }
#line 1998 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 257 "src/parser.y" /* yacc.c:1646  */
    { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), NULL); }
#line 2004 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 258 "src/parser.y" /* yacc.c:1646  */
    { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), (yyvsp[-2].excl_or_expr)); }
#line 2010 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 260 "src/parser.y" /* yacc.c:1646  */
    { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), NULL); }
#line 2016 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 261 "src/parser.y" /* yacc.c:1646  */
    { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), (yyvsp[-2].and_expr)); }
#line 2022 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), NULL, NULL); }
#line 2028 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 264 "src/parser.y" /* yacc.c:1646  */
    { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].str)); }
#line 2034 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 265 "src/parser.y" /* yacc.c:1646  */
    { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].str)); }
#line 2040 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 267 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), NULL, NULL); }
#line 2046 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 268 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2052 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 269 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2058 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 270 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2064 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 271 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2070 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 273 "src/parser.y" /* yacc.c:1646  */
    { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), NULL, NULL); }
#line 2076 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 274 "src/parser.y" /* yacc.c:1646  */
    { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].str)); }
#line 2082 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 275 "src/parser.y" /* yacc.c:1646  */
    { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].str)); }
#line 2088 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 277 "src/parser.y" /* yacc.c:1646  */
    { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), NULL, NULL); }
#line 2094 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 278 "src/parser.y" /* yacc.c:1646  */
    { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].str)); }
#line 2100 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 279 "src/parser.y" /* yacc.c:1646  */
    { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].str)); }
#line 2106 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 281 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), NULL, NULL); }
#line 2112 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 282 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2118 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 283 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2124 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2130 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 286 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Expr((yyvsp[0].ass_expr), NULL); }
#line 2136 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 287 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Expr((yyvsp[0].ass_expr), (yyvsp[-2].expr)); }
#line 2142 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 289 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_expr) = new AssignmentExpr((yyvsp[0].cond_expr), NULL, NULL, NULL); }
#line 2148 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 290 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_expr) = new AssignmentExpr(NULL, (yyvsp[-2].un_expr), (yyvsp[-1].ass_op), (yyvsp[0].ass_expr)); }
#line 2154 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 292 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2160 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 293 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2166 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2172 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2178 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 296 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2184 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2190 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 298 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2196 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 299 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2202 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 300 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2208 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 301 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2214 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 302 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2220 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 304 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr((yyvsp[0].post_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2226 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 305 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2232 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 306 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2238 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 307 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, NULL, (yyvsp[-1].un_op), (yyvsp[0].cast_expr), NULL, NULL); }
#line 2244 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 308 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2250 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 309 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, NULL, NULL, NULL, (yyvsp[-1].type_name), (yyvsp[-3].str)); }
#line 2256 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 311 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2262 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 312 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2268 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 313 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2274 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 314 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2280 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 315 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2286 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 316 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2292 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr((yyvsp[0].pri_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2298 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 319 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr((yyvsp[-3].pri_expr), (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 2304 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 320 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-3].post_expr), (yyvsp[-1].arg_expr_list), NULL, NULL); }
#line 2310 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 321 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, NULL, NULL); }
#line 2316 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 322 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2322 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2328 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 324 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].str), NULL); }
#line 2334 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 325 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].str), NULL); }
#line 2340 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 327 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr((yyvsp[0].str), NULL, NULL, NULL); }
#line 2346 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 328 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr(NULL, (yyvsp[0].str), NULL, NULL); }
#line 2352 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 329 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, (yyvsp[0].str), NULL); }
#line 2358 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, NULL, (yyvsp[-1].expr)); }
#line 2364 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 333 "src/parser.y" /* yacc.c:1646  */
    { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), NULL); }
#line 2370 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 334 "src/parser.y" /* yacc.c:1646  */
    { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), (yyvsp[-2].arg_expr_list)); }
#line 2376 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 336 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cast_expr) = new CastExpr((yyvsp[0].un_expr), NULL, NULL); }
#line 2382 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cast_expr) = new CastExpr(NULL, (yyvsp[-2].type_name), (yyvsp[0].cast_expr)); }
#line 2388 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 342 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement((yyvsp[0].label_state), NULL, NULL, NULL, NULL, NULL); }
#line 2394 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 343 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, (yyvsp[0].comp_state), NULL, NULL, NULL, NULL); }
#line 2400 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 344 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, (yyvsp[0].expr_state), NULL, NULL, NULL); }
#line 2406 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 345 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, NULL, (yyvsp[0].select_state), NULL, NULL); }
#line 2412 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 346 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, (yyvsp[0].it_state), NULL); }
#line 2418 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 347 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, NULL, (yyvsp[0].jump_state)); }
#line 2424 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 350 "src/parser.y" /* yacc.c:1646  */
    { (yyval.label_state) = new LabeledStatement((yyvsp[0].state), (yyvsp[-2].const_expr)); }
#line 2430 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 351 "src/parser.y" /* yacc.c:1646  */
    { (yyval.label_state) = new LabeledStatement((yyvsp[0].state), NULL); }
#line 2436 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 353 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr_state) = new ExprStatement((yyvsp[-1].expr)); }
#line 2442 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 354 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr_state) = new ExprStatement(NULL); }
#line 2448 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 356 "src/parser.y" /* yacc.c:1646  */
    { (yyval.select_state) = new SelectionStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, (yyvsp[-4].str), NULL, NULL); }
#line 2454 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 357 "src/parser.y" /* yacc.c:1646  */
    { (yyval.select_state) = new SelectionStatement((yyvsp[-4].expr), (yyvsp[-2].state), (yyvsp[0].state), (yyvsp[-6].str), (yyvsp[-1].str), NULL); }
#line 2460 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 358 "src/parser.y" /* yacc.c:1646  */
    { (yyval.select_state) = new SelectionStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, NULL, NULL, (yyvsp[-4].str)); }
#line 2466 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 360 "src/parser.y" /* yacc.c:1646  */
    { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, NULL, (yyvsp[-4].str)); }
#line 2472 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 361 "src/parser.y" /* yacc.c:1646  */
    { (yyval.it_state) = new IterationStatement(NULL, (yyvsp[0].state), (yyvsp[-3].expr_state), (yyvsp[-2].expr_state), (yyvsp[-5].str)); }
#line 2478 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 362 "src/parser.y" /* yacc.c:1646  */
    { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[0].state), (yyvsp[-4].expr_state), (yyvsp[-3].expr_state), (yyvsp[-6].str)); }
#line 2484 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 364 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_state) = new JumpStatement((yyvsp[-1].str), NULL); }
#line 2490 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 365 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_state) = new JumpStatement((yyvsp[-1].str), NULL); }
#line 2496 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 366 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_state) = new JumpStatement((yyvsp[-2].str), (yyvsp[-1].expr)); }
#line 2502 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 368 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2508 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 369 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2514 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 370 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2520 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 371 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2526 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 372 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2532 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 373 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier(NULL, (yyvsp[0].struct_spec), NULL); }
#line 2538 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 374 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier(NULL, NULL, (yyvsp[0].enum_spec)); }
#line 2544 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 385 "src/parser.y" /* yacc.c:1646  */
    { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[-1].type_spec), (yyvsp[0].spec_qual_list)); }
#line 2550 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 386 "src/parser.y" /* yacc.c:1646  */
    { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[0].type_spec), NULL); }
#line 2556 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 395 "src/parser.y" /* yacc.c:1646  */
    { (yyval.enum_spec) = new EnumSpecifier((yyvsp[-3].str), (yyvsp[-1].enum_list)); }
#line 2562 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 396 "src/parser.y" /* yacc.c:1646  */
    { (yyval.enum_spec) = new EnumSpecifier(NULL, (yyvsp[-1].enum_list)); }
#line 2568 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 397 "src/parser.y" /* yacc.c:1646  */
    { (yyval.enum_spec) = new EnumSpecifier((yyvsp[0].str), NULL); }
#line 2574 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 399 "src/parser.y" /* yacc.c:1646  */
    { (yyval.enum_list) = new EnumeratorList(NULL, (yyvsp[0].enume)); }
#line 2580 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 400 "src/parser.y" /* yacc.c:1646  */
    { (yyval.enum_list) = new EnumeratorList((yyvsp[-2].enum_list), (yyvsp[0].enume)); }
#line 2586 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 402 "src/parser.y" /* yacc.c:1646  */
    { (yyval.enume) = new Enumerator((yyvsp[0].str), NULL); }
#line 2592 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 403 "src/parser.y" /* yacc.c:1646  */
    { (yyval.enume) = new Enumerator((yyvsp[-2].str), (yyvsp[0].const_expr)); }
#line 2598 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2602 "src/parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 405 "src/parser.y" /* yacc.c:1906  */


const TranslationUnit *g_root; // Definition of variable (to match declaration earlier)

const TranslationUnit *parseAST(const char* file){
    g_root=0;
    yyin = fopen(file, "r");

    if(yyin){
        yyparse();
    }

    fclose(yyin);
    return g_root;
}
