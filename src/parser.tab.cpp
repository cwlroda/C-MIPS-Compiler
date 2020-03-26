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
    ELLIPSIS = 307,
    IF = 308,
    ELSE = 309,
    SWITCH = 310,
    CASE = 311,
    DEFAULT = 312,
    FOR = 313,
    DO = 314,
    WHILE = 315,
    CONTINUE = 316,
    BREAK = 317,
    RETURN = 318,
    LB = 319,
    RB = 320,
    LSB = 321,
    RSB = 322,
    LCB = 323,
    RCB = 324,
    COLON = 325,
    COMMA = 326
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
    Enumerator *enumr;

    std::string *str;

#line 261 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 278 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   894

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  315

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   169,   169,   171,   172,   174,   175,   177,   178,   179,
     180,   182,   183,   185,   186,   187,   188,   190,   191,   193,
     194,   195,   196,   198,   199,   201,   202,   204,   205,   206,
     208,   209,   211,   212,   214,   215,   216,   217,   218,   219,
     221,   222,   224,   225,   227,   228,   229,   231,   233,   234,
     235,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     247,   248,   250,   251,   253,   254,   256,   257,   259,   260,
     262,   263,   265,   266,   267,   269,   270,   271,   272,   273,
     275,   276,   277,   279,   280,   281,   283,   284,   285,   286,
     288,   289,   291,   292,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   306,   307,   308,   309,   310,
     311,   313,   314,   315,   316,   317,   318,   320,   321,   322,
     323,   324,   325,   326,   327,   329,   330,   331,   332,   334,
     335,   337,   338,   340,   341,   343,   344,   345,   346,   347,
     348,   350,   351,   352,   354,   355,   357,   358,   359,   361,
     362,   363,   364,   366,   367,   368,   370,   371,   372,   373,
     374,   375,   376,   378,   379,   380,   382,   383,   385,   387,
     388,   390,   391,   393,   394,   395,   397,   398,   399,   401,
     402,   404,   405
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
  "TYPEDEF", "STRUCT", "ENUM", "ELLIPSIS", "IF", "ELSE", "SWITCH", "CASE",
  "DEFAULT", "FOR", "DO", "WHILE", "CONTINUE", "BREAK", "RETURN", "LB",
  "RB", "LSB", "RSB", "LCB", "RCB", "COLON", "COMMA", "$accept", "ROOT",
  "TRANSLATION_UNIT", "EXTERNAL_DECLARATION", "FUNCTION_DEFINITION",
  "DECLARATION", "DECLARATION_SPECIFIER", "DECLARATION_LIST",
  "COMPOUND_STATEMENT", "STATEMENT_LIST", "INIT_DECLARATOR", "INITIALIZER",
  "INITIALIZER_LIST", "DECLARATOR", "DIRECT_DECLARATOR", "POINTER",
  "PARAMETER_LIST", "PARAMETER_DECLARATION", "CONSTANT_EXPR",
  "ABSTRACT_DECLARATOR", "DIRECT_ABSTRACT_DECLARATOR", "CONDITIONAL_EXPR",
  "LOGICAL_OR_EXPR", "LOGICAL_AND_EXPR", "INCLUSIVE_OR_EXPR",
  "EXCLUSIVE_OR_EXPR", "AND_EXPR", "EQUALITY_EXPR", "RELATIONAL_EXPR",
  "SHIFT_EXPR", "ADDITIVE_EXPR", "MULTIPLICATIVE_EXPR", "EXPR",
  "ASSIGNMENT_EXPR", "ASSIGNMENT_OPERATOR", "UNARY_EXPR", "UNARY_OPERATOR",
  "POSTFIX_EXPR", "PRIMARY_EXPR", "ARGUMENT_EXPR_LIST", "CAST_EXPR",
  "TYPE_NAME", "STATEMENT", "LABELED_STATEMENT", "EXPR_STATEMENT",
  "SELECTION_STATEMENT", "ITERATION_STATEMENT", "JUMP_STATEMENT",
  "TYPE_SPECIFIER", "STRUCT_SPECIFIER", "STRUCT_DECLARATION_LIST",
  "STRUCT_DECLARATION", "SPECIFIER_QUALIFIER_LIST",
  "STRUCT_DECLARATOR_LIST", "STRUCT_DECLARATOR", "ENUM_SPECIFIER",
  "ENUMERATOR_LIST", "ENUMERATOR", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

#define YYPACT_NINF -183

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-183)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     149,  -183,     4,  -183,  -183,  -183,  -183,  -183,   843,    16,
      25,    47,    38,   149,  -183,  -183,  -183,    44,   367,    19,
      46,   843,  -183,  -183,  -183,  -183,    -8,   490,    48,   109,
      58,  -183,  -183,  -183,   102,   296,   259,  -183,    44,   367,
    -183,   676,   524,    19,  -183,   490,   490,   229,  -183,     9,
     109,   128,    11,  -183,  -183,  -183,   219,   367,  -183,   101,
    -183,  -183,   763,  -183,   771,   771,  -183,  -183,  -183,  -183,
    -183,  -183,   122,   127,   812,   104,   142,   516,   146,   208,
     227,   812,   706,  -183,   326,  -183,   393,  -183,    21,   207,
     199,   198,   203,   232,   106,   261,   252,   186,    24,  -183,
     587,   812,    49,   192,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,   224,  -183,  -183,  -183,    40,   -39,  -183,  -183,  -183,
     202,  -183,  -183,   359,  -183,  -183,  -183,   812,   216,   304,
     242,    78,   812,  -183,   109,   219,  -183,  -183,  -183,   516,
     706,  -183,   812,  -183,  -183,   812,   812,   255,   516,   755,
     266,   812,  -183,  -183,    29,   -12,   271,    -2,  -183,   434,
    -183,  -183,   812,   812,   812,   812,   812,   812,   812,   812,
     812,   812,   812,   812,   812,   812,   812,   812,   812,   812,
     812,  -183,   812,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,   812,  -183,  -183,  -183,   334,   335,
     654,   812,   601,   589,  -183,    41,  -183,   113,  -183,   843,
    -183,  -183,  -183,   812,  -183,     9,  -183,  -183,  -183,  -183,
     118,  -183,   274,     5,    50,   516,  -183,   755,   284,    79,
    -183,  -183,   812,   813,   139,  -183,  -183,   207,   -16,   199,
     198,   203,   232,   106,   106,   261,   261,   261,   261,   252,
     252,   186,   186,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,    80,   -25,  -183,   105,   285,  -183,   282,   113,
     821,   597,  -183,  -183,  -183,  -183,   475,  -183,   516,   516,
    -183,   667,   812,   516,  -183,   812,  -183,   812,  -183,  -183,
    -183,  -183,  -183,   110,  -183,   286,  -183,  -183,   297,  -183,
     516,   117,   171,  -183,  -183,  -183,  -183,  -183,   516,  -183,
     516,   345,  -183,  -183,  -183
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,    41,   156,   157,   158,   159,   160,    14,     0,
       0,     0,     0,     2,     4,     5,     6,     0,     0,    33,
       0,    16,   161,   162,    40,    13,   165,     0,   178,     0,
       0,     1,     3,    12,     0,    25,     0,    17,     0,     0,
      10,     0,     0,    32,    15,     0,   170,     0,   166,     0,
       0,   181,     0,   179,    35,    11,     0,     0,     8,   125,
     126,   127,     0,   145,     0,     0,   113,   114,   112,   115,
     111,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,   136,     0,    92,    60,    62,
      64,    66,    68,    70,    72,    75,    80,    83,     0,    90,
     131,     0,   105,   117,    86,    23,   135,   137,   138,   139,
     140,    25,    18,     9,    39,    46,     0,    42,   125,    37,
       0,    47,   131,     0,   169,   164,   167,     0,   173,     0,
     171,     0,     0,   177,     0,     0,    26,    27,     7,     0,
       0,   109,     0,   106,   107,     0,     0,     0,     0,     0,
       0,     0,   153,   154,     0,     0,     0,   134,    20,     0,
      21,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   144,     0,    98,    95,    96,    97,    99,   102,   100,
     101,    94,   104,   103,     0,   108,   123,   124,     0,     0,
       0,     0,     0,     0,    44,    48,    45,    50,    38,     0,
      36,   163,   175,     0,   168,     0,   176,   182,   180,    30,
       0,   141,     0,     0,     0,     0,   143,     0,     0,     0,
     155,   128,     0,     0,    48,   133,    19,    63,     0,    65,
      67,    69,    71,    73,    74,    78,    79,    76,    77,    81,
      82,    84,    85,    87,    88,    89,    91,    93,   122,   121,
     120,   129,     0,     0,    59,     0,     0,    55,     0,    49,
       0,     0,    43,   174,   172,    28,     0,   110,     0,     0,
     142,     0,     0,     0,   132,     0,   119,     0,   118,    58,
      51,    54,    57,     0,    53,     0,    29,    31,   146,   148,
       0,     0,     0,   149,    61,   130,    56,    52,     0,   151,
       0,     0,   147,   152,   150
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,   341,  -183,    17,     0,   249,    63,   275,
    -183,  -128,  -183,    -1,   -15,     2,   -38,   152,   -60,   -88,
    -182,   -41,  -183,   196,   201,   197,   212,   213,   123,    84,
     120,   125,    15,   -36,  -183,   -40,  -183,  -183,  -183,  -183,
     -11,   223,   -71,  -183,  -138,  -183,  -183,  -183,   138,  -183,
     323,   -29,   -37,  -183,   154,  -183,   342,   257
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    37,    38,    39,    85,    86,
      34,   136,   220,    18,    19,    20,   265,   117,   120,   266,
     207,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   194,   100,   101,   102,   103,   262,
     104,   156,   105,   106,   107,   108,   109,   110,    21,    22,
      47,    48,    49,   129,   130,    23,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      17,   121,   122,   116,    24,    43,   150,   219,    25,   124,
      30,   227,     1,    17,   147,   161,    35,    16,   126,    26,
     137,    44,   141,   269,   143,   144,   208,   206,    28,     2,
      16,   181,   209,   121,   122,     2,   230,   111,    31,   162,
       2,   115,   288,     1,     1,   157,   182,     1,   128,     1,
       1,    33,   269,   231,   285,   182,   112,   196,   197,   182,
      45,   122,   233,   163,   203,   198,   199,   212,   221,   235,
     278,     2,   217,    11,   112,     2,   182,   226,     2,   127,
     133,    40,   134,    41,    27,    42,   121,   122,   161,   281,
     195,   121,   122,    29,   126,   182,   154,   155,    58,   137,
     182,   112,   113,   157,   202,   202,   203,   203,    11,    55,
      11,    11,    51,   200,   204,   279,    50,   205,   170,   171,
     138,   182,   122,    54,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   172,   173,   268,   283,   286,   256,   216,   297,   134,
     182,   287,     1,   273,   280,   155,   132,   155,   257,   234,
     223,   224,   121,   122,   261,    46,   229,   253,   254,   255,
     289,   139,   121,   122,   148,   306,   209,   270,   238,   271,
       2,   209,   310,    46,    46,    46,   145,   275,   182,   276,
      43,   146,   122,     3,     4,     5,     6,     7,     8,     9,
      10,    30,   115,   233,   205,   203,   149,   298,   299,   115,
     151,   295,   303,    11,   128,   152,   263,   178,   179,   180,
      46,   284,   118,    60,    61,    62,   164,    64,    65,   309,
     121,   122,   293,   115,   153,   234,   311,   312,   165,   313,
     137,   166,   182,   167,   304,   122,   168,   169,    66,    67,
      68,   305,    56,    69,   245,   246,   247,   248,   201,    70,
      71,    46,    59,    60,    61,    62,    63,    64,    65,   210,
     115,   174,   175,     3,     4,     5,     6,     7,    46,     9,
      10,   176,   177,    82,    57,    84,   213,   135,    66,    67,
      68,   243,   244,    69,   249,   250,   301,   302,   125,    70,
      71,   251,   252,     3,     4,     5,     6,     7,     8,     9,
      10,   214,    72,   215,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    56,   225,   228,    36,    83,    59,
      60,    61,    62,    63,    64,    65,   232,   258,   259,   277,
       3,     4,     5,     6,     7,     8,     9,    10,   282,   291,
     290,   308,   314,   307,    32,    66,    67,    68,   237,   159,
      69,   272,   240,   222,    36,   239,    70,    71,   123,   274,
       3,     4,     5,     6,     7,     8,     9,    10,   241,    72,
     242,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,   218,   131,     0,    36,   158,    59,    60,    61,    62,
      63,    64,    65,     3,     4,     5,     6,     7,     0,     9,
      10,     3,     4,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    66,    67,    68,     0,     0,    69,   211,     0,
       0,     0,     0,    70,    71,    36,     0,    59,    60,    61,
      62,    63,    64,    65,     0,     0,    72,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,    36,   160,    66,    67,    68,     0,     0,    69,     0,
       0,     0,     0,     0,    70,    71,     0,     0,   118,    60,
      61,    62,     0,    64,    65,     0,     0,    72,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,    36,   236,    66,    67,    68,     0,     0,    69,
       0,     0,     0,     0,     0,    70,    71,     0,     0,    59,
      60,    61,    62,    63,    64,    65,     0,   118,    60,    61,
      62,     0,    64,    65,     3,     4,     5,     6,     7,    82,
       9,    10,     0,   135,   296,    66,    67,    68,     0,     0,
      69,     0,     0,    66,    67,    68,    70,    71,    69,     0,
       0,     0,     0,     0,    70,    71,     0,     0,     0,    72,
       0,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,    36,     0,     0,     0,    82,     0,
       0,   119,   118,    60,    61,    62,     0,    64,    65,     0,
     118,    60,    61,    62,     1,    64,    65,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,     0,    66,    67,
      68,     0,     0,    69,   192,   193,    66,    67,    68,    70,
      71,    69,     2,     0,     0,     0,     0,    70,    71,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    82,     0,     0,   267,   118,    60,    61,
      62,    82,    64,    65,   294,   202,   264,   203,     0,     0,
     118,    60,    61,    62,     0,    64,    65,     0,     0,     0,
       0,     0,     0,    66,    67,    68,     0,     0,    69,     0,
       0,     0,     0,     0,    70,    71,    66,    67,    68,     0,
       0,    69,     0,     0,     0,     0,     0,    70,    71,   118,
      60,    61,    62,     0,    64,    65,     0,     0,    82,   260,
       3,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    82,   300,     0,     0,    66,    67,    68,     0,     0,
      69,   114,     0,     0,     0,     0,    70,    71,     0,     0,
       3,     4,     5,     6,     7,     0,     9,    10,   118,    60,
      61,    62,    63,    64,    65,     0,   118,    60,    61,    62,
      82,    64,    65,     0,   118,    60,    61,    62,     0,    64,
      65,     0,     0,     0,    66,    67,    68,     0,     0,    69,
       0,     0,    66,    67,    68,    70,    71,    69,     0,     0,
      66,    67,    68,    70,    71,    69,     0,     0,     0,     0,
       0,    70,    71,     0,     0,   118,    60,    61,    62,    82,
      64,    65,     0,     0,     0,     0,     0,   140,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,    66,    67,    68,     2,     0,    69,     0,     0,     0,
       0,     0,    70,    71,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     3,     4,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    82,   233,   264,   203,
       0,     0,     0,     0,     0,     0,   292,     3,     4,     5,
       6,     7,     8,     9,    10
};

static const yytype_int16 yycheck[] =
{
       0,    42,    42,    41,     2,    20,    77,   135,     8,    46,
      11,   149,     3,    13,    74,    86,    17,     0,    47,     3,
      56,    21,    62,   205,    64,    65,    65,   115,     3,    31,
      13,     7,    71,    74,    74,    31,     7,    38,     0,    18,
      31,    41,    67,     3,     3,    82,    71,     3,    49,     3,
       3,     7,   234,    65,    70,    71,    39,     8,     9,    71,
      68,   101,    64,    42,    66,    16,    17,   127,   139,   157,
      65,    31,   132,    64,    57,    31,    71,   148,    31,    70,
      69,    18,    71,    64,    68,    66,   127,   127,   159,   227,
     101,   132,   132,    68,   123,    71,    81,    82,    35,   135,
      71,    84,    39,   140,    64,    64,    66,    66,    64,     7,
      64,    64,     3,    64,   115,    65,    68,   115,    12,    13,
      57,    71,   162,    65,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    35,    36,   203,    65,    65,   182,    69,   276,    71,
      71,    71,     3,   213,   225,   140,    28,   142,   194,   157,
     145,   146,   203,   203,   200,    27,   151,   178,   179,   180,
      65,    70,   213,   213,    70,    65,    71,    64,   163,    66,
      31,    71,    65,    45,    46,    47,    64,    69,    71,    71,
     205,    64,   232,    44,    45,    46,    47,    48,    49,    50,
      51,   202,   202,    64,   202,    66,    64,   278,   279,   209,
      64,   271,   283,    64,   215,     7,   201,    31,    32,    33,
      82,   232,     3,     4,     5,     6,    19,     8,     9,   300,
     271,   271,   270,   233,     7,   233,    65,   308,    39,   310,
     276,    43,    71,    40,   285,   285,    14,    15,    29,    30,
      31,   287,    28,    34,   170,   171,   172,   173,    66,    40,
      41,   123,     3,     4,     5,     6,     7,     8,     9,    67,
     270,    10,    11,    44,    45,    46,    47,    48,   140,    50,
      51,    29,    30,    64,    35,    36,    70,    68,    29,    30,
      31,   168,   169,    34,   174,   175,   281,   282,    69,    40,
      41,   176,   177,    44,    45,    46,    47,    48,    49,    50,
      51,     7,    53,    71,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    28,    70,    60,    68,    69,     3,
       4,     5,     6,     7,     8,     9,    65,     3,     3,    65,
      44,    45,    46,    47,    48,    49,    50,    51,    64,    67,
      65,    54,     7,    67,    13,    29,    30,    31,   162,    84,
      34,   209,   165,   140,    68,   164,    40,    41,    45,   215,
      44,    45,    46,    47,    48,    49,    50,    51,   166,    53,
     167,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   134,    50,    -1,    68,    69,     3,     4,     5,     6,
       7,     8,     9,    44,    45,    46,    47,    48,    -1,    50,
      51,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    34,    69,    -1,
      -1,    -1,    -1,    40,    41,    68,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    68,    69,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    68,    69,    29,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,     3,     4,     5,
       6,    -1,     8,     9,    44,    45,    46,    47,    48,    64,
      50,    51,    -1,    68,    69,    29,    30,    31,    -1,    -1,
      34,    -1,    -1,    29,    30,    31,    40,    41,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    68,    -1,    -1,    -1,    64,    -1,
      -1,    67,     3,     4,     5,     6,    -1,     8,     9,    -1,
       3,     4,     5,     6,     3,     8,     9,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    29,    30,
      31,    -1,    -1,    34,    37,    38,    29,    30,    31,    40,
      41,    34,    31,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    64,    -1,    -1,    67,     3,     4,     5,
       6,    64,     8,     9,    67,    64,    65,    66,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    29,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    64,    65,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    64,    65,    -1,    -1,    29,    30,    31,    -1,    -1,
      34,    65,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    -1,    50,    51,     3,     4,
       5,     6,     7,     8,     9,    -1,     3,     4,     5,     6,
      64,     8,     9,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      -1,    -1,    29,    30,    31,    40,    41,    34,    -1,    -1,
      29,    30,    31,    40,    41,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,     3,     4,     5,     6,    64,
       8,     9,    -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    31,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    44,    45,    46,    47,    48,
      49,    50,    51,    -1,    -1,    -1,    64,    64,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    44,    45,    46,
      47,    48,    49,    50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    31,    44,    45,    46,    47,    48,    49,    50,
      51,    64,    73,    74,    75,    76,    77,    78,    85,    86,
      87,   120,   121,   127,    87,    78,     3,    68,     3,    68,
      85,     0,    75,     7,    82,    85,    68,    77,    78,    79,
      80,    64,    66,    86,    78,    68,   120,   122,   123,   124,
      68,     3,   128,   129,    65,     7,    28,    79,    80,     3,
       4,     5,     6,     7,     8,     9,    29,    30,    31,    34,
      40,    41,    53,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    69,    79,    80,    81,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     107,   108,   109,   110,   112,   114,   115,   116,   117,   118,
     119,    85,    77,    80,    65,    78,    88,    89,     3,    67,
      90,    93,   107,   122,   124,    69,   123,    70,    85,   125,
     126,   128,    28,    69,    71,    68,    83,   105,    80,    70,
      64,   107,    64,   107,   107,    64,    64,    90,    70,    64,
     114,    64,     7,     7,   104,   104,   113,   124,    69,    81,
      69,   114,    18,    42,    19,    39,    43,    40,    14,    15,
      12,    13,    35,    36,    10,    11,    29,    30,    31,    32,
      33,     7,    71,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    37,    38,   106,   112,     8,     9,    16,    17,
      64,    66,    64,    66,    85,    87,    91,    92,    65,    71,
      67,    69,    90,    70,     7,    71,    69,    90,   129,    83,
      84,   114,   113,   104,   104,    70,   114,   116,    60,   104,
       7,    65,    65,    64,    87,    91,    69,    95,   104,    96,
      97,    98,    99,   100,   100,   101,   101,   101,   101,   102,
     102,   103,   103,   112,   112,   112,   105,   105,     3,     3,
      65,   105,   111,   104,    65,    88,    91,    67,    90,    92,
      64,    66,    89,    90,   126,    69,    71,    65,    65,    65,
     114,   116,    64,    65,   112,    70,    65,    71,    67,    65,
      65,    67,    65,    88,    67,    90,    69,    83,   114,   114,
      65,   104,   104,   114,    93,   105,    65,    67,    54,   114,
      65,    65,   114,   114,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    82,    82,    83,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    89,    89,    89,    90,    91,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,    99,   100,   100,   100,   100,   100,
     101,   101,   101,   102,   102,   102,   103,   103,   103,   103,
     104,   104,   105,   105,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   107,   107,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   114,   114,
     114,   115,   115,   115,   116,   116,   117,   117,   117,   118,
     118,   118,   118,   119,   119,   119,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   122,   122,   123,   124,
     124,   125,   125,   126,   126,   126,   127,   127,   127,   128,
     128,   129,   129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     3,     3,
       2,     3,     2,     2,     1,     2,     1,     1,     2,     4,
       3,     3,     2,     1,     2,     1,     3,     1,     3,     4,
       1,     3,     2,     1,     1,     3,     4,     3,     4,     3,
       2,     1,     1,     3,     2,     2,     1,     1,     1,     2,
       1,     3,     4,     3,     3,     2,     4,     3,     3,     2,
       1,     5,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       3,     3,     3,     2,     2,     1,     1,     1,     3,     1,
       3,     1,     4,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     1,     5,     7,     5,     5,
       7,     6,     7,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     2,     1,     2,     3,     2,
       1,     1,     3,     1,     3,     2,     5,     4,     2,     1,
       3,     1,     3
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
#line 1718 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), (yyvsp[-1].trans_unit)); }
#line 1724 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 172 "src/parser.y" /* yacc.c:1646  */
    { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), NULL); }
#line 1730 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 174 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ext_decl) = new ExternalDeclaration((yyvsp[0].func_def), NULL); }
#line 1736 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 175 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ext_decl) = new ExternalDeclaration(NULL, (yyvsp[0].decl)); }
#line 1742 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 177 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition((yyvsp[-3].decl_spec), (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1748 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 178 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition((yyvsp[-2].decl_spec), (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1754 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1760 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1766 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-2].decl_spec), (yyvsp[-1].init_declr)); }
#line 1772 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-1].decl_spec), NULL); }
#line 1778 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier(NULL, (yyvsp[0].decl_spec), (yyvsp[-1].str)); }
#line 1784 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier(NULL, NULL, (yyvsp[0].str)); }
#line 1790 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[-1].type_spec), (yyvsp[0].decl_spec), NULL); }
#line 1796 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 188 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[0].type_spec), NULL, NULL); }
#line 1802 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_list) = new DeclarationList(NULL, (yyvsp[0].decl)); }
#line 1808 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_list) = new DeclarationList((yyvsp[-1].decl_list), (yyvsp[0].decl)); }
#line 1814 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement((yyvsp[-2].decl_list), (yyvsp[-1].state_list)); }
#line 1820 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement((yyvsp[-1].decl_list), NULL); }
#line 1826 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement(NULL, (yyvsp[-1].state_list)); }
#line 1832 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement(NULL, NULL); }
#line 1838 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state_list) = new StatementList((yyvsp[0].state), NULL); }
#line 1844 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 199 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state_list) = new StatementList((yyvsp[0].state), (yyvsp[-1].state_list)); }
#line 1850 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 201 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_declr) = new InitDeclarator((yyvsp[0].declr), NULL); }
#line 1856 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_declr) = new InitDeclarator((yyvsp[-2].declr), (yyvsp[0].init)); }
#line 1862 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init) = new Initializer((yyvsp[0].ass_expr), NULL); }
#line 1868 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init) = new Initializer(NULL, (yyvsp[-1].init_list)); }
#line 1874 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 206 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init) = new Initializer(NULL, (yyvsp[-2].init_list)); }
#line 1880 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_list) = new InitializerList((yyvsp[0].init), NULL); }
#line 1886 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 209 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_list) = new InitializerList((yyvsp[0].init), (yyvsp[-2].init_list)); }
#line 1892 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declr) = new Declarator((yyvsp[-1].ptr), (yyvsp[0].dir_declr)); }
#line 1898 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declr) = new Declarator(NULL, (yyvsp[0].dir_declr)); }
#line 1904 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 214 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, NULL, NULL, NULL, (yyvsp[0].str), NULL); }
#line 1910 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 215 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator((yyvsp[-1].declr), NULL, NULL, NULL, NULL, NULL); }
#line 1916 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), (yyvsp[-1].const_expr), NULL, NULL, NULL); }
#line 1922 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 217 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-2].dir_declr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 1928 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), NULL, (yyvsp[-1].param_list), NULL, NULL); }
#line 1934 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 219 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-2].dir_declr), NULL, NULL, NULL, NULL); }
#line 1940 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 224 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), NULL); }
#line 1946 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), (yyvsp[-2].param_list)); }
#line 1952 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), (yyvsp[0].declr), NULL); }
#line 1958 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 228 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), NULL, (yyvsp[0].abs_declr)); }
#line 1964 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 229 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_decl) = new ParameterDeclaration((yyvsp[0].decl_spec), NULL, NULL); }
#line 1970 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 231 "src/parser.y" /* yacc.c:1646  */
    { (yyval.const_expr) = new ConstantExpr((yyvsp[0].cond_expr)); }
#line 1976 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 247 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cond_expr) = new ConditionalExpr((yyvsp[0].log_or_expr), NULL, NULL); }
#line 1982 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cond_expr) = new ConditionalExpr((yyvsp[-4].log_or_expr), (yyvsp[-2].expr), (yyvsp[0].cond_expr)); }
#line 1988 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 250 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), NULL); }
#line 1994 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 251 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), (yyvsp[-2].log_or_expr)); }
#line 2000 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 253 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), NULL); }
#line 2006 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), (yyvsp[-2].log_and_expr)); }
#line 2012 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 256 "src/parser.y" /* yacc.c:1646  */
    { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), NULL); }
#line 2018 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 257 "src/parser.y" /* yacc.c:1646  */
    { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), (yyvsp[-2].incl_or_expr)); }
#line 2024 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 259 "src/parser.y" /* yacc.c:1646  */
    { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), NULL); }
#line 2030 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 260 "src/parser.y" /* yacc.c:1646  */
    { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), (yyvsp[-2].excl_or_expr)); }
#line 2036 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 262 "src/parser.y" /* yacc.c:1646  */
    { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), NULL); }
#line 2042 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), (yyvsp[-2].and_expr)); }
#line 2048 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 265 "src/parser.y" /* yacc.c:1646  */
    { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), NULL, NULL); }
#line 2054 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 266 "src/parser.y" /* yacc.c:1646  */
    { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].str)); }
#line 2060 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 267 "src/parser.y" /* yacc.c:1646  */
    { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].str)); }
#line 2066 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 269 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), NULL, NULL); }
#line 2072 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 270 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2078 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 271 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2084 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 272 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2090 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 273 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2096 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 275 "src/parser.y" /* yacc.c:1646  */
    { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), NULL, NULL); }
#line 2102 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 276 "src/parser.y" /* yacc.c:1646  */
    { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].str)); }
#line 2108 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 277 "src/parser.y" /* yacc.c:1646  */
    { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].str)); }
#line 2114 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 279 "src/parser.y" /* yacc.c:1646  */
    { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), NULL, NULL); }
#line 2120 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 280 "src/parser.y" /* yacc.c:1646  */
    { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].str)); }
#line 2126 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 281 "src/parser.y" /* yacc.c:1646  */
    { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].str)); }
#line 2132 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 283 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), NULL, NULL); }
#line 2138 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2144 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2150 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 286 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2156 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 288 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Expr((yyvsp[0].ass_expr), NULL); }
#line 2162 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 289 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Expr((yyvsp[0].ass_expr), (yyvsp[-2].expr)); }
#line 2168 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 291 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_expr) = new AssignmentExpr((yyvsp[0].cond_expr), NULL, NULL, NULL); }
#line 2174 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 292 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_expr) = new AssignmentExpr(NULL, (yyvsp[-2].un_expr), (yyvsp[-1].ass_op), (yyvsp[0].ass_expr)); }
#line 2180 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2186 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2192 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 296 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2198 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2204 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 298 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2210 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 299 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2216 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 300 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2222 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 301 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2228 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 302 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2234 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 303 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2240 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 304 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2246 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 306 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr((yyvsp[0].post_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2252 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 307 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2258 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 308 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2264 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 309 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, NULL, (yyvsp[-1].un_op), (yyvsp[0].cast_expr), NULL, NULL); }
#line 2270 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 310 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2276 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 311 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, NULL, NULL, NULL, (yyvsp[-1].type_name), (yyvsp[-3].str)); }
#line 2282 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 313 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2288 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 314 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2294 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 315 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2300 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 316 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2306 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2312 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2318 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 320 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr((yyvsp[0].pri_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2324 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 321 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr((yyvsp[-3].pri_expr), (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 2330 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 322 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-3].post_expr), (yyvsp[-1].arg_expr_list), NULL, NULL); }
#line 2336 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, NULL, NULL); }
#line 2342 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 324 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2348 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 325 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2354 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 326 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].str), NULL); }
#line 2360 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 327 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].str), NULL); }
#line 2366 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 329 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr((yyvsp[0].str), NULL, NULL, NULL); }
#line 2372 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 330 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr(NULL, (yyvsp[0].str), NULL, NULL); }
#line 2378 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, (yyvsp[0].str), NULL); }
#line 2384 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 332 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, NULL, (yyvsp[-1].expr)); }
#line 2390 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 334 "src/parser.y" /* yacc.c:1646  */
    { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), NULL); }
#line 2396 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 335 "src/parser.y" /* yacc.c:1646  */
    { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), (yyvsp[-2].arg_expr_list)); }
#line 2402 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cast_expr) = new CastExpr((yyvsp[0].un_expr), NULL, NULL); }
#line 2408 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 338 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cast_expr) = new CastExpr(NULL, (yyvsp[-2].type_name), (yyvsp[0].cast_expr)); }
#line 2414 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 343 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement((yyvsp[0].label_state), NULL, NULL, NULL, NULL, NULL); }
#line 2420 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 344 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, (yyvsp[0].comp_state), NULL, NULL, NULL, NULL); }
#line 2426 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 345 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, (yyvsp[0].expr_state), NULL, NULL, NULL); }
#line 2432 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 346 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, NULL, (yyvsp[0].select_state), NULL, NULL); }
#line 2438 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 347 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, (yyvsp[0].it_state), NULL); }
#line 2444 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 348 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, NULL, (yyvsp[0].jump_state)); }
#line 2450 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 354 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr_state) = new ExprStatement((yyvsp[-1].expr)); }
#line 2456 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 355 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr_state) = new ExprStatement(NULL); }
#line 2462 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 357 "src/parser.y" /* yacc.c:1646  */
    { (yyval.select_state) = new SelectionStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, (yyvsp[-4].str), NULL, NULL); }
#line 2468 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 358 "src/parser.y" /* yacc.c:1646  */
    { (yyval.select_state) = new SelectionStatement((yyvsp[-4].expr), (yyvsp[-2].state), (yyvsp[0].state), (yyvsp[-6].str), (yyvsp[-1].str), NULL); }
#line 2474 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 359 "src/parser.y" /* yacc.c:1646  */
    { (yyval.select_state) = new SelectionStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, NULL, NULL, (yyvsp[-4].str)); }
#line 2480 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 361 "src/parser.y" /* yacc.c:1646  */
    { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, NULL, (yyvsp[-4].str), NULL); }
#line 2486 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 362 "src/parser.y" /* yacc.c:1646  */
    { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[-5].state), NULL, NULL, (yyvsp[-4].str), (yyvsp[-6].str)); }
#line 2492 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 363 "src/parser.y" /* yacc.c:1646  */
    { (yyval.it_state) = new IterationStatement(NULL, (yyvsp[0].state), (yyvsp[-3].expr_state), (yyvsp[-2].expr_state), (yyvsp[-5].str), NULL); }
#line 2498 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 364 "src/parser.y" /* yacc.c:1646  */
    { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[0].state), (yyvsp[-4].expr_state), (yyvsp[-3].expr_state), (yyvsp[-6].str), NULL); }
#line 2504 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 366 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_state) = new JumpStatement((yyvsp[-1].str), NULL); }
#line 2510 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 367 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_state) = new JumpStatement((yyvsp[-1].str), NULL); }
#line 2516 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 368 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_state) = new JumpStatement((yyvsp[-2].str), (yyvsp[-1].expr)); }
#line 2522 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 370 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2528 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 371 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2534 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 372 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2540 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 373 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2546 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 374 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2552 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 375 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier(NULL, (yyvsp[0].struct_spec), NULL); }
#line 2558 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 376 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier(NULL, NULL, (yyvsp[0].enum_spec)); }
#line 2564 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 387 "src/parser.y" /* yacc.c:1646  */
    { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[-1].type_spec), (yyvsp[0].spec_qual_list)); }
#line 2570 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 388 "src/parser.y" /* yacc.c:1646  */
    { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[0].type_spec), NULL); }
#line 2576 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2580 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 407 "src/parser.y" /* yacc.c:1906  */


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
