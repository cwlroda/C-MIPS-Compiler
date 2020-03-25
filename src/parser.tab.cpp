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
#line 22 "src/parser.y" /* yacc.c:355  */

    TranslationUnit *trans_unit;
    ExternalDeclaration *ext_decl;
    FunctionDefinition *func_def;
    Declaration *decl;
    DeclarationSpecifier *decl_spec;
    DeclarationList *decl_list;
    CompoundStatement *comp_state;
    StatementList *state_list;
    InitDeclaratorList *init_declr_list;
    InitDeclarator *init_declr;
    Initializer *init;
    InitializerList *init_list;
    Declarator *declr;
    DirectDeclarator *dir_declr;
    Pointer *ptr;
    ParameterTypeList *param_type_list;
    ParameterList *param_list;
    ParameterDeclaration *param_decl;
    IdentifierList *iden_list;
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

    std::string *string;

#line 275 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 292 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1096

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  333

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   336

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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   176,   176,   178,   179,   181,   182,   184,   185,   186,
     187,   189,   190,   192,   193,   194,   195,   197,   198,   200,
     201,   202,   203,   205,   206,   208,   209,   211,   212,   214,
     215,   216,   218,   219,   221,   222,   224,   225,   226,   227,
     228,   229,   230,   232,   233,   235,   236,   238,   239,   241,
     242,   243,   245,   246,   248,   251,   252,   253,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   265,   266,   268,
     269,   271,   272,   274,   275,   277,   278,   280,   281,   283,
     284,   285,   287,   288,   289,   290,   291,   293,   294,   295,
     297,   298,   299,   301,   302,   303,   304,   306,   307,   309,
     310,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   324,   325,   326,   327,   328,   329,   331,   332,
     333,   334,   335,   336,   338,   339,   340,   341,   342,   343,
     344,   345,   347,   348,   349,   350,   352,   353,   355,   356,
     358,   359,   361,   362,   363,   364,   365,   366,   368,   369,
     370,   372,   373,   375,   376,   377,   379,   380,   381,   382,
     384,   385,   386,   388,   389,   390,   391,   392,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   406,
     407,   408,   410,   411,   413,   415,   416,   418,   419,   421,
     422,   423,   425,   426,   427,   429,   430,   432,   433
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
  "QUESTION", "XOR", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER",
  "VOID", "CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE", "SIGNED",
  "UNSIGNED", "CONST", "VOLATILE", "STRUCT", "ENUM", "ELLIPSIS", "IF",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "FOR", "DO", "WHILE", "CONTINUE",
  "BREAK", "RETURN", "LB", "RB", "LSB", "RSB", "LCB", "RCB", "COLON",
  "COMMA", "$accept", "ROOT", "TRANSLATION_UNIT", "EXTERNAL_DECLARATION",
  "FUNCTION_DEFINITION", "DECLARATION", "DECLARATION_SPECIFIER",
  "DECLARATION_LIST", "COMPOUND_STATEMENT", "STATEMENT_LIST",
  "INIT_DECLARATOR_LIST", "INIT_DECLARATOR", "INITIALIZER",
  "INITIALIZER_LIST", "DECLARATOR", "DIRECT_DECLARATOR", "POINTER",
  "PARAMETER_TYPE_LIST", "PARAMETER_LIST", "PARAMETER_DECLARATION",
  "IDENTIFIER_LIST", "CONSTANT_EXPR", "ABSTRACT_DECLARATOR",
  "DIRECT_ABSTRACT_DECLARATOR", "CONDITIONAL_EXPR", "LOGICAL_OR_EXPR",
  "LOGICAL_AND_EXPR", "INCLUSIVE_OR_EXPR", "EXCLUSIVE_OR_EXPR", "AND_EXPR",
  "EQUALITY_EXPR", "RELATIONAL_EXPR", "SHIFT_EXPR", "ADDITIVE_EXPR",
  "MULTIPLICATIVE_EXPR", "EXPR", "ASSIGNMENT_EXPR", "ASSIGNMENT_OPERATOR",
  "UNARY_EXPR", "UNARY_OPERATOR", "POSTFIX_EXPR", "PRIMARY_EXPR",
  "ARGUMENT_EXPR_LIST", "CAST_EXPR", "TYPE_NAME", "STATEMENT",
  "LABELED_STATEMENT", "EXPR_STATEMENT", "SELECTION_STATEMENT",
  "ITERATION_STATEMENT", "JUMP_STATEMENT", "STORAGE_CLASS_SPECIFIER",
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336
};
# endif

#define YYPACT_NINF -199

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-199)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     817,  -199,   -14,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,     5,    30,    13,
      49,   817,  -199,  -199,  -199,    48,   997,   159,    37,  1035,
    1035,  -199,  -199,  -199,   -39,   745,   -24,    72,     3,  -199,
    -199,  -199,    31,  -199,   929,   260,  -199,    48,   997,  -199,
     227,   610,   159,  -199,  -199,   745,   745,   300,  -199,    39,
      72,    70,   141,  -199,  -199,  -199,    13,   571,   997,  -199,
      29,  -199,  -199,   884,  -199,   892,   892,  -199,  -199,  -199,
    -199,  -199,  -199,    42,    47,   931,    77,    78,   525,    88,
     175,   196,   931,   783,  -199,   337,  -199,   414,  -199,    19,
     194,   186,   123,   192,    17,    59,    53,    52,   146,    36,
    -199,   404,   931,   147,   171,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,   208,  -199,  -199,  -199,  -199,    25,   180,   179,
    -199,    95,  -199,  -199,   193,  -199,  -199,   625,  -199,  -199,
    -199,   931,   182,   278,   218,   160,   931,  -199,    72,  -199,
     571,  -199,  -199,  -199,   525,   783,  -199,   931,  -199,  -199,
     931,   931,   223,   525,   876,   248,   931,  -199,  -199,   238,
     126,   247,   -17,  -199,   431,  -199,  -199,   931,   931,   931,
     931,   931,   931,   931,   931,   931,   931,   931,   931,   931,
     931,   931,   931,   931,   931,   931,  -199,   931,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,   931,
    -199,  -199,  -199,   321,   334,   729,   931,   670,   623,  -199,
      44,  -199,   168,  -199,  1016,  -199,   344,  -199,  -199,  -199,
     931,  -199,    39,  -199,  -199,  -199,  -199,   164,  -199,   273,
     127,   130,   525,  -199,   876,   284,   131,  -199,   931,   964,
     185,  -199,  -199,   194,    94,   186,   123,   192,    17,    59,
      59,    53,    53,    53,    53,    52,    52,   146,   146,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,   135,    -4,
    -199,   287,   288,  -199,   282,   168,   139,   662,  -199,  -199,
    -199,  -199,  -199,  -199,   508,  -199,   525,   525,  -199,   744,
     931,   525,  -199,   931,  -199,   931,  -199,  -199,  -199,  -199,
    -199,   289,  -199,   292,  -199,  -199,   301,  -199,   525,   148,
     153,  -199,  -199,  -199,  -199,  -199,   525,  -199,   525,   363,
    -199,  -199,  -199
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    36,    44,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,     0,     0,     0,
       0,     2,     4,     5,     6,     0,     0,    35,     0,    14,
      16,   177,   178,    43,   181,     0,   194,     0,     0,     1,
       3,    12,     0,    25,    27,     0,    17,     0,     0,    10,
       0,     0,    34,    13,    15,     0,   186,     0,   182,     0,
       0,   197,     0,   195,    37,    11,     0,     0,     0,     8,
     132,   133,   134,     0,   152,     0,     0,   120,   121,   119,
     122,   118,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,   143,     0,    99,    67,
      69,    71,    73,    75,    77,    79,    82,    87,    90,     0,
      97,   138,     0,   112,   124,    93,    23,   142,   144,   145,
     146,   147,    27,    18,     9,    52,    42,    51,     0,    45,
      47,     0,   132,    39,     0,    54,   138,     0,   185,   180,
     183,     0,   189,     0,   187,     0,     0,   193,     0,    26,
       0,    28,    29,     7,     0,     0,   116,     0,   113,   114,
       0,     0,     0,     0,     0,     0,     0,   160,   161,   162,
       0,     0,   141,    20,     0,    21,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,     0,   105,   102,
     103,   104,   106,   109,   107,   108,   101,   111,   110,     0,
     115,   130,   131,     0,     0,     0,     0,     0,     0,    49,
      55,    50,    57,    40,     0,    41,     0,    38,   179,   191,
       0,   184,     0,   192,   198,   196,    32,     0,   148,     0,
       0,     0,     0,   150,     0,     0,     0,   135,     0,     0,
      55,   140,    19,    70,     0,    72,    74,    76,    78,    80,
      81,    85,    86,    83,    84,    88,    89,    91,    92,    94,
      95,    96,    98,   100,   129,   128,   127,   136,     0,     0,
      66,     0,     0,    62,     0,    56,     0,     0,    46,    48,
      53,   190,   188,    30,     0,   117,     0,     0,   149,     0,
       0,     0,   139,     0,   126,     0,   125,    65,    58,    61,
      64,     0,    60,     0,    31,    33,   153,   155,     0,     0,
       0,   156,    68,   137,    63,    59,     0,   158,     0,     0,
     154,   159,   157
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -199,  -199,  -199,   351,  -199,    20,     0,   207,    32,   279,
    -199,   307,  -143,  -199,   -13,   -23,     1,   -46,  -199,   151,
    -199,   -72,  -112,  -198,   -49,  -199,   199,   201,   215,   220,
     214,   112,   -62,   108,   144,    -7,   -48,  -199,   -50,  -199,
    -199,  -199,  -199,   -88,   244,   -70,  -199,  -155,  -199,  -199,
    -199,  -199,    10,  -199,   357,   -47,   -45,  -199,   181,  -199,
     354,   285
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    46,    47,    48,    96,    97,
      42,    43,   151,   237,    26,    27,    28,   281,   129,   130,
     131,   134,   282,   222,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   209,   111,   112,
     113,   114,   278,   115,   171,   116,   117,   118,   119,   120,
     121,    29,    30,    31,    57,    58,    59,   143,   144,    32,
      62,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      25,   136,   135,    33,   128,    52,    38,   236,    34,   244,
     140,   138,    44,   162,     2,   221,     1,     2,   165,   152,
      24,    25,   285,   156,   210,   158,   159,   176,     1,    53,
      54,   183,   184,    36,   122,   136,   135,   177,    65,    55,
       1,    24,     1,   196,     2,    56,   142,     1,   172,    39,
     127,     1,   285,   122,    60,    41,     2,   249,    49,   218,
     251,   178,   136,   189,   190,    56,    56,    56,   123,   229,
       2,   185,   186,   306,   234,    61,    69,   197,    64,     2,
     124,   191,   192,    35,   238,   169,   170,    19,   123,   299,
     140,   136,   135,   243,   187,   188,   136,   135,   146,   217,
     153,   218,   152,    56,   176,   269,   270,   271,    37,   154,
     172,    19,    66,    19,   219,   123,   160,   197,   217,   141,
     218,   161,    19,   261,   262,   263,   264,   136,   220,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   284,    56,   170,   272,
     170,   315,   164,   240,   241,   211,   212,   163,   291,   246,
     302,   273,   166,   213,   214,    56,   181,   277,   136,   135,
     225,   254,   298,   250,   303,   197,   226,   193,   194,   195,
     136,   135,   167,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    52,   136,    17,
      18,   247,   296,   168,    38,   297,   301,   197,   197,   279,
     304,   197,   197,   179,   310,   313,   305,   127,   220,   142,
     147,   215,   148,   328,   127,   180,   316,   317,   329,   197,
     125,   321,   182,    50,   197,    51,    67,   136,   135,   233,
     311,   148,   286,   293,   287,   294,   152,   216,   327,   127,
     250,    68,    95,   136,   322,   223,   330,   323,   331,   249,
     224,   218,   230,    70,    71,    72,    73,    74,    75,    76,
     227,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   231,   127,    17,    18,    77,
      78,    79,   319,   320,    80,   259,   260,   265,   266,   232,
      81,    82,   126,   242,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   245,   197,
      17,    18,   248,    83,   274,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   267,   268,   275,    45,    94,
      70,    71,    72,    73,    74,    75,    76,   290,   295,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   300,   309,
      17,    18,   307,   308,   324,   326,    77,    78,    79,   325,
     332,    80,    40,   149,   174,   289,   253,    81,    82,   139,
     255,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   256,   258,    17,    18,   239,
      83,   257,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,   137,   292,   145,    45,   173,    70,    71,    72,
      73,    74,    75,    76,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   235,    70,    71,    72,    73,    74,    75,
      76,   207,   208,    77,    78,    79,     0,     0,    80,     0,
       0,     0,     0,     0,    81,    82,     0,     0,     0,     0,
      77,    78,    79,     0,     0,    80,     0,     0,     0,     0,
       0,    81,    82,     0,     0,     0,     0,    83,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,     0,
       0,     0,    45,   175,    83,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,     0,     0,    45,
     252,   132,    71,    72,    73,     0,    75,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    77,    78,    79,
       0,     0,    80,     0,     0,     0,     0,     0,    81,    82,
       0,     0,     0,     0,    77,    78,    79,     0,     0,    80,
       0,     0,     0,     0,     0,    81,    82,     0,     0,     0,
       0,     0,     0,     0,   132,    71,    72,    73,     0,    75,
      76,     0,    93,     0,     0,     0,   150,   314,    83,     0,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      77,    78,    79,    45,     0,    80,     0,     0,     0,     0,
       0,    81,    82,   132,    71,    72,    73,     0,    75,    76,
       0,     0,     0,     0,     0,     0,   132,    71,    72,    73,
       0,    75,    76,     0,     0,     0,     0,     0,     0,    77,
      78,    79,     0,     0,    80,    93,     0,     0,     0,   150,
      81,    82,    77,    78,    79,     0,     0,    80,     0,     0,
       0,     0,     0,    81,    82,   132,    71,    72,    73,     0,
      75,    76,     0,     1,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,    93,    17,    18,   133,     0,     0,
       0,    77,    78,    79,     0,     0,    80,    93,     0,     0,
     283,     2,    81,    82,   228,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     0,     0,
      17,    18,   132,    71,    72,    73,    93,    75,    76,   312,
       0,     0,     0,     0,   217,   280,   218,   132,    71,    72,
      73,     0,    75,    76,     0,     0,     0,     0,    77,    78,
      79,     0,     0,    80,     0,     0,     0,     0,     0,    81,
      82,     0,     0,    77,    78,    79,     0,     0,    80,     0,
       0,     0,     0,     0,    81,    82,   132,    71,    72,    73,
       0,    75,    76,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    93,   276,    17,    18,     0,     0,     0,
       0,     0,    77,    78,    79,     0,     0,    80,    93,   318,
       1,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,     0,    17,    18,     0,     0,     0,     2,     0,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,    17,    18,   132,
      71,    72,    73,    74,    75,    76,     0,   132,    71,    72,
      73,    19,    75,    76,     0,   132,    71,    72,    73,     0,
      75,    76,     0,     0,     0,    77,    78,    79,     0,     0,
      80,     0,     0,    77,    78,    79,    81,    82,    80,     0,
       0,    77,    78,    79,    81,    82,    80,     0,     0,     0,
       0,     0,    81,    82,   132,    71,    72,    73,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     0,     0,     0,     0,    67,   155,     0,
      77,    78,    79,     0,     0,    80,   157,     0,     0,     0,
       0,    81,    82,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,     0,     0,    17,
      18,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,     0,    45,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   249,   280,
     218,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,    17,    18,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,    45,    17,    18,   288,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,    17,    18
};

static const yytype_int16 yycheck[] =
{
       0,    51,    51,     2,    50,    28,    19,   150,     3,   164,
      57,    56,    25,    85,    31,   127,     3,    31,    88,    67,
       0,    21,   220,    73,   112,    75,    76,    97,     3,    29,
      30,    14,    15,     3,    47,    85,    85,    18,     7,    78,
       3,    21,     3,     7,    31,    35,    59,     3,    93,     0,
      50,     3,   250,    66,    78,     7,    31,    74,    26,    76,
     172,    42,   112,    10,    11,    55,    56,    57,    48,   141,
      31,    12,    13,    77,   146,     3,    44,    81,    75,    31,
      48,    29,    30,    78,   154,    92,    93,    74,    68,   244,
     137,   141,   141,   163,    35,    36,   146,   146,    28,    74,
      68,    76,   150,    93,   174,   193,   194,   195,    78,    80,
     155,    74,    81,    74,   127,    95,    74,    81,    74,    80,
      76,    74,    74,   185,   186,   187,   188,   177,   127,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   218,   137,   155,   197,
     157,   294,    74,   160,   161,     8,     9,    80,   230,   166,
     248,   209,    74,    16,    17,   155,    43,   215,   218,   218,
      75,   178,   242,   172,    80,    81,    81,    31,    32,    33,
     230,   230,     7,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,   220,   248,    60,
      61,    75,    75,     7,   217,    75,    75,    81,    81,   216,
      75,    81,    81,    19,    75,   287,    81,   217,   217,   232,
      79,    74,    81,    75,   224,    39,   296,   297,    75,    81,
       3,   301,    40,    74,    81,    76,    28,   287,   287,    79,
     286,    81,    74,    79,    76,    81,   294,    76,   318,   249,
     249,    44,    45,   303,   303,    75,   326,   305,   328,    74,
      81,    76,    80,     3,     4,     5,     6,     7,     8,     9,
      77,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     7,   286,    60,    61,    29,
      30,    31,   299,   300,    34,   183,   184,   189,   190,    81,
      40,    41,    75,    80,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    70,    81,
      60,    61,    75,    63,     3,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,   191,   192,     3,    78,    79,
       3,     4,     5,     6,     7,     8,     9,     3,    75,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    74,    77,
      60,    61,    75,    75,    75,    64,    29,    30,    31,    77,
       7,    34,    21,    66,    95,   224,   177,    40,    41,    79,
     179,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,   180,   182,    60,    61,   155,
      63,   181,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    55,   232,    60,    78,    79,     3,     4,     5,
       6,     7,     8,     9,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   148,     3,     4,     5,     6,     7,     8,
       9,    37,    38,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    63,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    79,    63,    -1,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      79,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    29,    30,    31,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    74,    -1,    -1,    -1,    78,    79,    63,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      29,    30,    31,    78,    -1,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    -1,    34,    74,    -1,    -1,    -1,    78,
      40,    41,    29,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,     3,     4,     5,     6,    -1,
       8,     9,    -1,     3,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    74,    60,    61,    77,    -1,    -1,
      -1,    29,    30,    31,    -1,    -1,    34,    74,    -1,    -1,
      77,    31,    40,    41,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61,     3,     4,     5,     6,    74,     8,     9,    77,
      -1,    -1,    -1,    -1,    74,    75,    76,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    29,    30,
      31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    40,    41,     3,     4,     5,     6,
      -1,     8,     9,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    74,    75,    60,    61,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    34,    74,    75,
       3,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,     3,
       4,     5,     6,     7,     8,     9,    -1,     3,     4,     5,
       6,    74,     8,     9,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,
      34,    -1,    -1,    29,    30,    31,    40,    41,    34,    -1,
      -1,    29,    30,    31,    40,    41,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    28,    74,    -1,
      29,    30,    31,    -1,    -1,    34,    74,    -1,    -1,    -1,
      -1,    40,    41,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    60,
      61,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    78,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,
      76,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    78,    60,    61,    62,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    -1,    60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    31,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    60,    61,    74,
      83,    84,    85,    86,    87,    88,    96,    97,    98,   133,
     134,   135,   141,    98,     3,    78,     3,    78,    96,     0,
      85,     7,    92,    93,    96,    78,    87,    88,    89,    90,
      74,    76,    97,    88,    88,    78,   134,   136,   137,   138,
      78,     3,   142,   143,    75,     7,    81,    28,    89,    90,
       3,     4,     5,     6,     7,     8,     9,    29,    30,    31,
      34,    40,    41,    63,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    79,    89,    90,    91,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   120,   121,   122,   123,   125,   127,   128,   129,   130,
     131,   132,    96,    87,    90,     3,    75,    88,    99,   100,
     101,   102,     3,    77,   103,   106,   120,   136,   138,    79,
     137,    80,    96,   139,   140,   142,    28,    79,    81,    93,
      78,    94,   118,    90,    80,    74,   120,    74,   120,   120,
      74,    74,   103,    80,    74,   127,    74,     7,     7,   117,
     117,   126,   138,    79,    91,    79,   127,    18,    42,    19,
      39,    43,    40,    14,    15,    12,    13,    35,    36,    10,
      11,    29,    30,    31,    32,    33,     7,    81,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    37,    38,   119,
     125,     8,     9,    16,    17,    74,    76,    74,    76,    96,
      98,   104,   105,    75,    81,    75,    81,    77,    79,   103,
      80,     7,    81,    79,   103,   143,    94,    95,   127,   126,
     117,   117,    80,   127,   129,    70,   117,    75,    75,    74,
      98,   104,    79,   108,   117,   109,   110,   111,   112,   113,
     113,   114,   114,   114,   114,   115,   115,   116,   116,   125,
     125,   125,   118,   118,     3,     3,    75,   118,   124,   117,
      75,    99,   104,    77,   103,   105,    74,    76,    62,   101,
       3,   103,   140,    79,    81,    75,    75,    75,   127,   129,
      74,    75,   125,    80,    75,    81,    77,    75,    75,    77,
      75,    99,    77,   103,    79,    94,   127,   127,    75,   117,
     117,   127,   106,   118,    75,    77,    64,   127,    75,    75,
     127,   127,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    87,    87,    88,    88,    88,    88,    89,    89,    90,
      90,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    99,    99,   100,   100,   101,
     101,   101,   102,   102,   103,   104,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   113,   113,   113,   113,   113,   114,   114,   114,
     115,   115,   115,   116,   116,   116,   116,   117,   117,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   120,   120,   120,   120,   120,   120,   121,   121,
     121,   121,   121,   121,   122,   122,   122,   122,   122,   122,
     122,   122,   123,   123,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   127,   128,   128,
     128,   129,   129,   130,   130,   130,   131,   131,   131,   131,
     132,   132,   132,   133,   133,   133,   133,   133,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   136,   136,   137,   138,   138,   139,   139,   140,
     140,   140,   141,   141,   141,   142,   142,   143,   143
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     3,     3,
       2,     3,     2,     2,     1,     2,     1,     1,     2,     4,
       3,     3,     2,     1,     2,     1,     3,     1,     3,     1,
       3,     4,     1,     3,     2,     1,     1,     3,     4,     3,
       4,     4,     3,     2,     1,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     1,     2,     1,     3,     4,
       3,     3,     2,     4,     3,     3,     2,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     3,     3,
       2,     2,     1,     1,     1,     3,     1,     3,     1,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     1,     5,     7,     5,     5,     7,     6,     7,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     2,     3,     2,     1,     1,     3,     1,
       3,     2,     5,     4,     2,     1,     3,     1,     3
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
#line 176 "src/parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].trans_unit); }
#line 1788 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 178 "src/parser.y" /* yacc.c:1646  */
    { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), (yyvsp[-1].trans_unit)); }
#line 1794 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), NULL); }
#line 1800 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 181 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ext_decl) = new ExternalDeclaration((yyvsp[0].func_def), NULL); }
#line 1806 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ext_decl) = new ExternalDeclaration(NULL, (yyvsp[0].decl)); }
#line 1812 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 184 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition((yyvsp[-3].decl_spec), (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1818 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition((yyvsp[-2].decl_spec), (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1824 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1830 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1836 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-2].decl_spec), (yyvsp[-1].init_declr_list)); }
#line 1842 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-1].decl_spec), NULL); }
#line 1848 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[-1].store_spec), NULL, (yyvsp[0].decl_spec)); }
#line 1854 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[0].store_spec), NULL, NULL); }
#line 1860 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier(NULL, (yyvsp[-1].type_spec), (yyvsp[0].decl_spec)); }
#line 1866 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_spec) = new DeclarationSpecifier(NULL, (yyvsp[0].type_spec), NULL); }
#line 1872 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 197 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_list) = new DeclarationList(NULL, (yyvsp[0].decl)); }
#line 1878 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl_list) = new DeclarationList((yyvsp[-1].decl_list), (yyvsp[0].decl)); }
#line 1884 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement((yyvsp[-2].decl_list), (yyvsp[-1].state_list)); }
#line 1890 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 201 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement((yyvsp[-1].decl_list), NULL); }
#line 1896 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement(NULL, (yyvsp[-1].state_list)); }
#line 1902 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 203 "src/parser.y" /* yacc.c:1646  */
    { (yyval.comp_state) = new CompoundStatement(NULL, NULL); }
#line 1908 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 205 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state_list) = new StatementList((yyvsp[0].state), NULL); }
#line 1914 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 206 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state_list) = new StatementList((yyvsp[0].state), (yyvsp[-1].state_list)); }
#line 1920 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_declr_list) = new InitDeclaratorList(NULL, (yyvsp[0].init_declr)); }
#line 1926 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 209 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_declr_list) = new InitDeclaratorList((yyvsp[-2].init_declr_list), (yyvsp[0].init_declr)); }
#line 1932 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_declr) = new InitDeclarator((yyvsp[0].declr), NULL); }
#line 1938 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_declr) = new InitDeclarator((yyvsp[-2].declr), (yyvsp[0].init)); }
#line 1944 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 214 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init) = new Initializer((yyvsp[0].ass_expr), NULL); }
#line 1950 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 215 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init) = new Initializer(NULL, (yyvsp[-1].init_list)); }
#line 1956 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init) = new Initializer(NULL, (yyvsp[-2].init_list)); }
#line 1962 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_list) = new InitializerList((yyvsp[0].init), NULL); }
#line 1968 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 219 "src/parser.y" /* yacc.c:1646  */
    { (yyval.init_list) = new InitializerList((yyvsp[0].init), (yyvsp[-2].init_list)); }
#line 1974 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 221 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declr) = new Declarator((yyvsp[-1].ptr), (yyvsp[0].dir_declr)); }
#line 1980 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 222 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declr) = new Declarator(NULL, (yyvsp[0].dir_declr)); }
#line 1986 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 224 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, NULL, NULL, NULL, NULL, (yyvsp[0].string), NULL); }
#line 1992 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator((yyvsp[-1].declr), NULL, NULL, NULL, NULL, NULL, NULL); }
#line 1998 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 226 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), (yyvsp[-1].const_expr), NULL, NULL, NULL, NULL); }
#line 2004 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-2].dir_declr), NULL, NULL, NULL, NULL, (yyvsp[-1].string)); }
#line 2010 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 228 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), NULL, (yyvsp[-1].param_type_list), NULL, NULL, NULL); }
#line 2016 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 229 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), NULL, NULL, (yyvsp[-1].iden_list), NULL, NULL); }
#line 2022 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 230 "src/parser.y" /* yacc.c:1646  */
    { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-2].dir_declr), NULL, NULL, NULL, NULL, NULL); }
#line 2028 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 235 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_type_list) = new ParameterTypeList((yyvsp[0].param_list), NULL); }
#line 2034 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 236 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_type_list) = new ParameterTypeList((yyvsp[-2].param_list), (yyvsp[0].string)); }
#line 2040 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 238 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), NULL); }
#line 2046 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 239 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), (yyvsp[-2].param_list)); }
#line 2052 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 241 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), (yyvsp[0].declr), NULL); }
#line 2058 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 242 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), NULL, (yyvsp[0].abs_declr)); }
#line 2064 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 243 "src/parser.y" /* yacc.c:1646  */
    { (yyval.param_decl) = new ParameterDeclaration((yyvsp[0].decl_spec), NULL, NULL); }
#line 2070 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 245 "src/parser.y" /* yacc.c:1646  */
    { (yyval.iden_list) = new IdentifierList(NULL, (yyvsp[0].string)); }
#line 2076 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 246 "src/parser.y" /* yacc.c:1646  */
    { (yyval.iden_list) = new IdentifierList((yyvsp[-2].iden_list), (yyvsp[0].string)); }
#line 2082 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.const_expr) = new ConstantExpr((yyvsp[0].cond_expr)); }
#line 2088 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 265 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cond_expr) = new ConditionalExpr((yyvsp[0].log_or_expr), NULL, NULL); }
#line 2094 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 266 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cond_expr) = new ConditionalExpr((yyvsp[-4].log_or_expr), (yyvsp[-2].expr), (yyvsp[0].cond_expr)); }
#line 2100 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 268 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), NULL); }
#line 2106 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 269 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), (yyvsp[-2].log_or_expr)); }
#line 2112 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 271 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), NULL); }
#line 2118 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 272 "src/parser.y" /* yacc.c:1646  */
    { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), (yyvsp[-2].log_and_expr)); }
#line 2124 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 274 "src/parser.y" /* yacc.c:1646  */
    { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), NULL); }
#line 2130 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 275 "src/parser.y" /* yacc.c:1646  */
    { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), (yyvsp[-2].incl_or_expr)); }
#line 2136 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 277 "src/parser.y" /* yacc.c:1646  */
    { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), NULL); }
#line 2142 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 278 "src/parser.y" /* yacc.c:1646  */
    { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), (yyvsp[-2].excl_or_expr)); }
#line 2148 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 280 "src/parser.y" /* yacc.c:1646  */
    { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), NULL); }
#line 2154 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 281 "src/parser.y" /* yacc.c:1646  */
    { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), (yyvsp[-2].and_expr)); }
#line 2160 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 283 "src/parser.y" /* yacc.c:1646  */
    { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), NULL, NULL); }
#line 2166 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].string)); }
#line 2172 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].string)); }
#line 2178 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 287 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), NULL, NULL); }
#line 2184 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 288 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].string)); }
#line 2190 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 289 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].string)); }
#line 2196 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 290 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].string)); }
#line 2202 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 291 "src/parser.y" /* yacc.c:1646  */
    { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].string)); }
#line 2208 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 293 "src/parser.y" /* yacc.c:1646  */
    { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), NULL, NULL); }
#line 2214 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].string)); }
#line 2220 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].string)); }
#line 2226 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), NULL, NULL); }
#line 2232 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 298 "src/parser.y" /* yacc.c:1646  */
    { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].string)); }
#line 2238 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 299 "src/parser.y" /* yacc.c:1646  */
    { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].string)); }
#line 2244 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 301 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), NULL, NULL); }
#line 2250 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 302 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].string)); }
#line 2256 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 303 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].string)); }
#line 2262 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 304 "src/parser.y" /* yacc.c:1646  */
    { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].string)); }
#line 2268 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 306 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Expr((yyvsp[0].ass_expr), NULL); }
#line 2274 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 307 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Expr((yyvsp[0].ass_expr), (yyvsp[-2].expr)); }
#line 2280 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 309 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_expr) = new AssignmentExpr((yyvsp[0].cond_expr), NULL, NULL, NULL); }
#line 2286 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 310 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_expr) = new AssignmentExpr(NULL, (yyvsp[-2].un_expr), (yyvsp[-1].ass_op), (yyvsp[0].ass_expr)); }
#line 2292 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 312 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2298 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 313 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2304 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 314 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2310 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 315 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2316 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 316 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2322 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2328 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2334 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 319 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2340 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 320 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2346 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 321 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2352 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 322 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].string)); }
#line 2358 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 324 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr((yyvsp[0].post_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2364 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 325 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].string)); }
#line 2370 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 326 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].string)); }
#line 2376 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 327 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, NULL, (yyvsp[-1].un_op), (yyvsp[0].cast_expr), NULL, NULL); }
#line 2382 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 328 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].string)); }
#line 2388 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 329 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_expr) = new UnaryExpr(NULL, NULL, NULL, NULL, (yyvsp[-1].type_name), (yyvsp[-3].string)); }
#line 2394 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].string)); }
#line 2400 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 332 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].string)); }
#line 2406 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 333 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].string)); }
#line 2412 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 334 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].string)); }
#line 2418 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 335 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].string)); }
#line 2424 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 336 "src/parser.y" /* yacc.c:1646  */
    { (yyval.un_op) = new UnaryOperator((yyvsp[0].string)); }
#line 2430 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 338 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr((yyvsp[0].pri_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2436 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 339 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr((yyvsp[-3].pri_expr), (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 2442 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 340 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-3].post_expr), (yyvsp[-1].arg_expr_list), NULL, NULL); }
#line 2448 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 341 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, NULL, NULL); }
#line 2454 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 342 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].string), (yyvsp[0].string)); }
#line 2460 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 343 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].string), (yyvsp[0].string)); }
#line 2466 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 344 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].string), NULL); }
#line 2472 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 345 "src/parser.y" /* yacc.c:1646  */
    { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].string), NULL); }
#line 2478 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 347 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr((yyvsp[0].string), NULL, NULL, NULL); }
#line 2484 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 348 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr(NULL, (yyvsp[0].string), NULL, NULL); }
#line 2490 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 349 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, (yyvsp[0].string), NULL); }
#line 2496 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 350 "src/parser.y" /* yacc.c:1646  */
    { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, NULL, (yyvsp[-1].expr)); }
#line 2502 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 352 "src/parser.y" /* yacc.c:1646  */
    { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), NULL); }
#line 2508 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 353 "src/parser.y" /* yacc.c:1646  */
    { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), (yyvsp[-2].arg_expr_list)); }
#line 2514 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 355 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cast_expr) = new CastExpr((yyvsp[0].un_expr), NULL, NULL); }
#line 2520 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 356 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cast_expr) = new CastExpr(NULL, (yyvsp[-2].type_name), (yyvsp[0].cast_expr)); }
#line 2526 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 361 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement((yyvsp[0].label_state), NULL, NULL, NULL, NULL, NULL); }
#line 2532 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 362 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, (yyvsp[0].comp_state), NULL, NULL, NULL, NULL); }
#line 2538 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 363 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, (yyvsp[0].expr_state), NULL, NULL, NULL); }
#line 2544 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 364 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, NULL, (yyvsp[0].select_state), NULL, NULL); }
#line 2550 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 365 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, (yyvsp[0].it_state), NULL); }
#line 2556 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 366 "src/parser.y" /* yacc.c:1646  */
    { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, NULL, (yyvsp[0].jump_state)); }
#line 2562 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 372 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr_state) = new ExprStatement((yyvsp[-1].expr)); }
#line 2568 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 373 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr_state) = new ExprStatement(NULL); }
#line 2574 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 384 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_state) = new JumpStatement((yyvsp[-1].string), NULL); }
#line 2580 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 385 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_state) = new JumpStatement((yyvsp[-1].string), NULL); }
#line 2586 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 386 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_state) = new JumpStatement((yyvsp[-1].string), (yyvsp[0].expr)); }
#line 2592 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 388 "src/parser.y" /* yacc.c:1646  */
    { (yyval.store_spec) = new StorageClassSpecifier((yyvsp[0].string)); }
#line 2598 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 389 "src/parser.y" /* yacc.c:1646  */
    { (yyval.store_spec) = new StorageClassSpecifier((yyvsp[0].string)); }
#line 2604 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 390 "src/parser.y" /* yacc.c:1646  */
    { (yyval.store_spec) = new StorageClassSpecifier((yyvsp[0].string)); }
#line 2610 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 391 "src/parser.y" /* yacc.c:1646  */
    { (yyval.store_spec) = new StorageClassSpecifier((yyvsp[0].string)); }
#line 2616 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 392 "src/parser.y" /* yacc.c:1646  */
    { (yyval.store_spec) = new StorageClassSpecifier((yyvsp[0].string)); }
#line 2622 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 394 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].string), NULL, NULL); }
#line 2628 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 395 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].string), NULL, NULL); }
#line 2634 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 396 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].string), NULL, NULL); }
#line 2640 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 397 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].string), NULL, NULL); }
#line 2646 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 398 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].string), NULL, NULL); }
#line 2652 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 399 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].string), NULL, NULL); }
#line 2658 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 400 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].string), NULL, NULL); }
#line 2664 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 401 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].string), NULL, NULL); }
#line 2670 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 402 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].string), NULL, NULL); }
#line 2676 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 403 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier(NULL, (yyvsp[0].struct_spec), NULL); }
#line 2682 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 404 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type_spec) = new TypeSpecifier(NULL, NULL, (yyvsp[0].enum_spec)); }
#line 2688 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 415 "src/parser.y" /* yacc.c:1646  */
    { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[-1].type_spec), (yyvsp[0].spec_qual_list)); }
#line 2694 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 416 "src/parser.y" /* yacc.c:1646  */
    { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[0].type_spec), NULL); }
#line 2700 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2704 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 435 "src/parser.y" /* yacc.c:1906  */


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
