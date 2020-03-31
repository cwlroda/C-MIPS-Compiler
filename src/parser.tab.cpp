/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 130 "src/parser.tab.cpp"

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

#line 272 "src/parser.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   880

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  307

#define YYUNDEFTOK  2
#define YYMAXUTOK   324


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
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
     323,   324,   325,   327,   328,   329,   330,   332,   333,   335,
     336,   338,   339,   341,   342,   343,   344,   345,   346,   348,
     349,   350,   352,   353,   355,   356,   357,   359,   360,   361,
     363,   364,   365,   367,   368,   369,   370,   371,   372,   373,
     375,   376,   377,   379,   380,   382,   384,   385,   387,   388,
     390,   391,   392,   394,   395,   396,   398,   399,   401,   402
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
static const yytype_int16 yytoknum[] =
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

#define YYPACT_NINF (-177)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     690,  -177,    -5,  -177,  -177,  -177,  -177,  -177,   355,    13,
      20,    36,    40,   690,  -177,  -177,  -177,    31,   279,    -9,
      45,   355,  -177,  -177,  -177,  -177,   -10,   508,     3,   102,
      51,  -177,  -177,  -177,   131,   198,   248,  -177,    31,   279,
    -177,   287,   149,    -9,  -177,   508,   508,   143,  -177,    29,
     102,   140,    11,  -177,  -177,  -177,   495,   279,  -177,   124,
    -177,  -177,   133,  -177,   776,   776,  -177,  -177,  -177,  -177,
    -177,  -177,   145,   171,   815,   163,   174,   176,   233,   243,
     815,   665,  -177,   313,  -177,   378,  -177,    19,   244,   223,
     222,   227,   146,   120,    33,   185,   169,    12,  -177,   565,
     815,    42,   209,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
     255,  -177,  -177,  -177,    39,     8,  -177,   219,   224,  -177,
    -177,  -177,   815,   217,   280,   232,    59,   815,  -177,   102,
    -177,   495,  -177,  -177,  -177,   456,   714,   815,  -177,  -177,
     815,   815,   218,  -177,  -177,   456,   763,   815,  -177,  -177,
      26,    48,   249,     4,  -177,   417,  -177,  -177,   815,   815,
     815,   815,   815,   815,   815,   815,   815,   815,   815,   815,
     815,   815,   815,   815,   815,   815,   815,  -177,   815,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
     815,  -177,  -177,  -177,   308,   310,   613,   815,   564,   534,
    -177,    46,  -177,   142,  -177,   355,  -177,  -177,  -177,   815,
    -177,    29,  -177,  -177,  -177,  -177,   152,  -177,   276,   277,
      53,    55,   456,  -177,   763,    56,  -177,  -177,   815,   816,
     158,  -177,  -177,   244,   155,   223,   222,   227,   146,   120,
     120,    33,    33,    33,    33,   185,   185,   169,   169,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,    58,    93,
    -177,    74,   278,  -177,   281,   142,   347,   542,  -177,  -177,
    -177,  -177,   495,  -177,  -177,   456,   456,  -177,   626,   456,
    -177,   815,  -177,   815,  -177,  -177,  -177,  -177,  -177,    77,
    -177,   283,  -177,   296,  -177,   456,    79,  -177,  -177,  -177,
    -177,  -177,   456,  -177,   456,  -177,  -177
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
     123,     0,    26,    27,     7,     0,     0,     0,   104,   105,
       0,     0,     0,    45,   129,     0,     0,     0,   150,   151,
       0,     0,     0,   132,    20,     0,    21,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,    96,
      93,    94,    95,    97,   100,    98,    99,    92,   102,   101,
       0,   106,   121,   122,     0,     0,     0,     0,     0,     0,
      42,    46,    43,    48,    36,     0,    35,   160,   172,     0,
     165,     0,   173,   179,   177,    29,     0,   139,     0,     0,
       0,     0,     0,   141,     0,     0,   152,   126,     0,     0,
      46,   131,    19,    61,     0,    63,    65,    67,    69,    71,
      72,    76,    77,    74,    75,    79,    80,    82,    83,    85,
      86,    87,    89,    91,   120,   119,   118,   127,     0,     0,
      57,     0,     0,    53,     0,    47,     0,     0,    41,   171,
     169,    28,     0,   107,   108,     0,     0,   140,     0,     0,
     130,     0,   117,     0,   116,    56,    49,    52,    55,     0,
      51,     0,    30,   144,   146,     0,     0,   147,    59,   128,
      54,    50,     0,   148,     0,   145,   149
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,  -177,   338,  -177,     7,     0,   199,    95,   269,
    -177,  -125,  -177,    -2,   -15,     1,   -39,   150,  -110,   -90,
    -176,   -70,  -177,   208,   196,   215,   216,   214,    94,    -3,
      90,   108,   -53,   -55,  -177,     9,  -177,  -177,  -177,  -177,
     -25,   252,   -63,  -177,  -128,  -177,  -177,  -177,   -16,  -177,
     344,   -33,   -36,  -177,   179,  -177,   361,   284
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    15,    37,    38,    39,    84,    85,
      34,   132,   216,    18,    19,    20,   261,   116,   142,   262,
     203,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   190,    99,   100,   101,   102,   258,
     103,   152,   104,   105,   106,   107,   108,   109,    21,    22,
      47,    48,    49,   124,   125,    23,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,   133,   115,    24,   143,    43,   215,    16,    25,    30,
     119,    46,   208,    17,   121,    35,    26,   213,   224,   177,
      16,    44,   157,    28,   202,   265,     2,   150,   151,    46,
      46,    46,     1,   226,     1,     2,   110,   158,    33,     1,
      31,   114,     1,   170,   171,   153,   111,   123,     1,     1,
     192,   193,   143,    41,   265,    42,    45,   143,   194,   195,
       2,   159,     2,   231,   111,    46,   229,     2,   199,    50,
       2,   204,   217,   138,   139,   191,   133,   205,   128,    27,
     129,   178,   223,   144,   151,   121,    29,   220,   221,   264,
     111,    11,   157,    11,   225,   178,   278,   122,    11,   269,
     153,   198,    46,   199,   196,    51,   234,    11,   198,   144,
     199,   227,   200,    40,    54,   201,   275,   178,   276,   279,
      46,   282,   178,   252,   178,   178,   212,   283,   129,   143,
      58,   144,   166,   167,   112,   253,   144,   285,    55,   143,
     300,   257,   304,   205,   259,   218,   205,   292,   178,   249,
     250,   251,   134,   117,   230,   168,   169,   291,   284,   277,
     164,   165,   178,   241,   242,   243,   244,   144,   127,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,    43,     3,     4,     5,
       6,     7,   135,     9,    10,   136,    30,   143,   114,   201,
     174,   175,   176,   280,   266,   114,   267,   140,   144,   123,
     120,   298,   293,   294,   172,   173,   297,   133,   144,   271,
     229,   272,   199,   281,   178,   296,    56,   289,   299,   114,
     230,   145,   303,   141,    57,    83,   146,   144,   147,   305,
     148,   306,     3,     4,     5,     6,     7,     8,     9,    10,
     149,    59,    60,    61,    62,    63,    64,    65,   239,   240,
     245,   246,   161,   160,    36,   162,   114,   163,     3,     4,
       5,     6,     7,   197,     9,    10,   144,    66,    67,    68,
     247,   248,    69,    56,   206,   209,   222,   210,    70,    71,
     144,   207,     3,     4,     5,     6,     7,     8,     9,    10,
      72,   211,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   254,   228,   255,    36,    82,    59,    60,    61,    62,
      63,    64,    65,     3,     4,     5,     6,     7,     8,     9,
      10,     3,     4,     5,     6,     7,     8,     9,    10,   273,
     274,   286,    66,    67,    68,    36,   287,    69,   301,   302,
     113,    32,   155,    70,    71,   268,   235,     3,     4,     5,
       6,     7,     8,     9,    10,    72,   233,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   236,   238,   237,    36,
     154,    59,    60,    61,    62,    63,    64,    65,   219,   118,
     270,     3,     4,     5,     6,     7,     8,     9,    10,     3,
       4,     5,     6,     7,     8,     9,    10,    66,    67,    68,
     288,   126,    69,   214,     0,     0,     0,     0,    70,    71,
      59,    60,    61,    62,    63,    64,    65,     0,     0,     0,
      72,     0,    73,    74,    75,    76,    77,    78,    79,    80,
      81,     0,     0,     0,    36,   156,    66,    67,    68,     0,
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
      64,    65,     3,     4,     5,     6,     7,    81,     9,    10,
       0,   131,     0,    66,    67,    68,     0,     1,    69,     0,
       0,    66,    67,    68,    70,    71,    69,     0,     0,     0,
       0,     0,    70,    71,     0,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,     2,    81,     0,     0,   263,
       0,     0,   188,   189,    81,     0,     0,   290,     3,     4,
       5,     6,     7,     8,     9,    10,   130,    60,    61,    62,
       0,    64,    65,     0,     0,     0,   198,   260,   199,   130,
      60,    61,    62,     0,    64,    65,     0,     0,     0,     0,
       0,     0,    66,    67,    68,     0,     0,    69,     0,     0,
       0,     0,     0,    70,    71,    66,    67,    68,     0,     0,
      69,     0,     0,     0,     0,     0,    70,    71,   130,    60,
      61,    62,     0,    64,    65,    81,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,   295,
       0,     0,     0,     1,    66,    67,    68,     0,     0,    69,
       0,     0,     0,     0,     0,    70,    71,     0,     0,     3,
       4,     5,     6,     7,     0,     9,    10,   130,    60,    61,
      62,     2,    64,    65,     0,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    66,    67,    68,     0,     0,    69,     0,
       0,     0,    11,     0,    70,    71,     0,     0,     3,     4,
       5,     6,     7,     0,     9,    10,   130,    60,    61,    62,
      63,    64,    65,     0,     0,     0,   137,     0,     0,   130,
      60,    61,    62,     0,    64,    65,     0,     0,     0,     0,
       0,     0,    66,    67,    68,     0,     0,    69,     0,     0,
       0,     0,     0,    70,    71,    66,    67,    68,     0,     0,
      69,     0,     0,     0,     0,     0,    70,    71,   130,    60,
      61,    62,     0,    64,    65,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,    66,    67,    68,     2,     0,    69,
       0,     0,     0,     0,     0,    70,    71,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,   229,   260,
     199
};

static const yytype_int16 yycheck[] =
{
       0,    56,    41,     2,    74,    20,   131,     0,     8,    11,
      46,    27,   122,    13,    47,    17,     3,   127,   146,     7,
      13,    21,    85,     3,   114,   201,    31,    80,    81,    45,
      46,    47,     3,     7,     3,    31,    38,    18,     7,     3,
       0,    41,     3,    10,    11,    81,    39,    49,     3,     3,
       8,     9,   122,    62,   230,    64,    66,   127,    16,    17,
      31,    42,    31,   153,    57,    81,    62,    31,    64,    66,
      31,    63,   135,    64,    65,   100,   131,    69,    67,    66,
      69,    69,   145,    74,   137,   118,    66,   140,   141,   199,
      83,    62,   155,    62,   147,    69,   224,    68,    62,   209,
     136,    62,   118,    64,    62,     3,   159,    62,    62,   100,
      64,    63,   114,    18,    63,   114,    63,    69,    63,    63,
     136,    63,    69,   178,    69,    69,    67,    69,    69,   199,
      35,   122,    12,    13,    39,   190,   127,    63,     7,   209,
      63,   196,    63,    69,   197,   136,    69,   272,    69,   174,
     175,   176,    57,     4,   153,    35,    36,   267,    65,   222,
      14,    15,    69,   166,   167,   168,   169,   158,    28,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   201,    44,    45,    46,
      47,    48,    68,    50,    51,    62,   198,   267,   198,   198,
      31,    32,    33,   228,    62,   205,    64,    62,   199,   211,
      67,   281,   275,   276,    29,    30,   279,   272,   209,    67,
      62,    69,    64,    68,    69,   278,    28,   266,   283,   229,
     229,    68,   295,    62,    35,    36,    62,   228,    62,   302,
       7,   304,    44,    45,    46,    47,    48,    49,    50,    51,
       7,     3,     4,     5,     6,     7,     8,     9,   164,   165,
     170,   171,    39,    19,    66,    43,   266,    40,    44,    45,
      46,    47,    48,    64,    50,    51,   267,    29,    30,    31,
     172,   173,    34,    28,    65,    68,    68,     7,    40,    41,
     281,    67,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    69,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     3,    63,     3,    66,    67,     3,     4,     5,     6,
       7,     8,     9,    44,    45,    46,    47,    48,    49,    50,
      51,    44,    45,    46,    47,    48,    49,    50,    51,    63,
      63,    63,    29,    30,    31,    66,    65,    34,    65,    53,
      63,    13,    83,    40,    41,   205,   160,    44,    45,    46,
      47,    48,    49,    50,    51,    52,   158,    54,    55,    56,
      57,    58,    59,    60,    61,    62,   161,   163,   162,    66,
      67,     3,     4,     5,     6,     7,     8,     9,   136,    45,
     211,    44,    45,    46,    47,    48,    49,    50,    51,    44,
      45,    46,    47,    48,    49,    50,    51,    29,    30,    31,
      63,    50,    34,   129,    -1,    -1,    -1,    -1,    40,    41,
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
       8,     9,    44,    45,    46,    47,    48,    62,    50,    51,
      -1,    66,    -1,    29,    30,    31,    -1,     3,    34,    -1,
      -1,    29,    30,    31,    40,    41,    34,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    31,    62,    -1,    -1,    65,
      -1,    -1,    37,    38,    62,    -1,    -1,    65,    44,    45,
      46,    47,    48,    49,    50,    51,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    62,    63,    64,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    29,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,     3,     4,
       5,     6,    -1,     8,     9,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,     3,    29,    30,    31,    -1,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48,    -1,    50,    51,     3,     4,     5,
       6,    31,     8,     9,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    -1,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    62,    -1,    40,    41,    -1,    -1,    44,    45,
      46,    47,    48,    -1,    50,    51,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    62,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    29,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    40,    41,     3,     4,
       5,     6,    -1,     8,     9,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    31,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    62,    63,
      64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
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
       3,    66,    81,   103,    78,    68,    62,    62,   105,   105,
      62,    62,    88,    91,   105,    68,    62,    62,     7,     7,
     102,   102,   111,   122,    67,    79,    67,   112,    18,    42,
      19,    39,    43,    40,    14,    15,    12,    13,    35,    36,
      10,    11,    29,    30,    31,    32,    33,     7,    69,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    37,    38,
     104,   110,     8,     9,    16,    17,    62,    64,    62,    64,
      83,    85,    89,    90,    63,    69,    65,    67,    88,    68,
       7,    69,    67,    88,   127,    81,    82,   112,   105,   111,
     102,   102,    68,   112,   114,   102,     7,    63,    63,    62,
      85,    89,    67,    93,   102,    94,    95,    96,    97,    98,
      98,    99,    99,    99,    99,   100,   100,   101,   101,   110,
     110,   110,   103,   103,     3,     3,    63,   103,   109,   102,
      63,    86,    89,    65,    88,    90,    62,    64,    87,    88,
     124,    67,    69,    63,    63,    63,    63,   112,   114,    63,
     110,    68,    63,    69,    65,    63,    63,    65,    63,    86,
      65,    88,    81,   112,   112,    63,   102,   112,    91,   103,
      63,    65,    53,   112,    63,   112,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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
static const yytype_int8 yyr2[] =
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
       1,     1,     1,     1,     2,     2,     2,     4,     4,     1,
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

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 169 "src/parser.y"
                       { g_root = (yyvsp[0].trans_unit); }
#line 1799 "src/parser.tab.cpp"
    break;

  case 3:
#line 171 "src/parser.y"
                                                                                                { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), (yyvsp[-1].trans_unit)); }
#line 1805 "src/parser.tab.cpp"
    break;

  case 4:
#line 172 "src/parser.y"
                                                                                                { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), NULL); }
#line 1811 "src/parser.tab.cpp"
    break;

  case 5:
#line 174 "src/parser.y"
                                                                                                { (yyval.ext_decl) = new ExternalDeclaration((yyvsp[0].func_def), NULL); }
#line 1817 "src/parser.tab.cpp"
    break;

  case 6:
#line 175 "src/parser.y"
                                                                                                { (yyval.ext_decl) = new ExternalDeclaration(NULL, (yyvsp[0].decl)); }
#line 1823 "src/parser.tab.cpp"
    break;

  case 7:
#line 177 "src/parser.y"
                                                                                                { (yyval.func_def) = new FunctionDefinition((yyvsp[-3].decl_spec), (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1829 "src/parser.tab.cpp"
    break;

  case 8:
#line 178 "src/parser.y"
                                                                                                { (yyval.func_def) = new FunctionDefinition((yyvsp[-2].decl_spec), (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1835 "src/parser.tab.cpp"
    break;

  case 9:
#line 179 "src/parser.y"
                                                                                                { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1841 "src/parser.tab.cpp"
    break;

  case 10:
#line 180 "src/parser.y"
                                                                                                { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1847 "src/parser.tab.cpp"
    break;

  case 11:
#line 182 "src/parser.y"
                                                                                           { (yyval.decl) = new Declaration((yyvsp[-2].decl_spec), (yyvsp[-1].init_declr)); }
#line 1853 "src/parser.tab.cpp"
    break;

  case 12:
#line 183 "src/parser.y"
                                                                                                { (yyval.decl) = new Declaration((yyvsp[-1].decl_spec), NULL); }
#line 1859 "src/parser.tab.cpp"
    break;

  case 13:
#line 185 "src/parser.y"
                                                                                                { (yyval.decl_spec) = new DeclarationSpecifier(NULL, (yyvsp[0].decl_spec), (yyvsp[-1].str)); }
#line 1865 "src/parser.tab.cpp"
    break;

  case 14:
#line 186 "src/parser.y"
                                                                                                { (yyval.decl_spec) = new DeclarationSpecifier(NULL, NULL, (yyvsp[0].str)); }
#line 1871 "src/parser.tab.cpp"
    break;

  case 15:
#line 187 "src/parser.y"
                                                                                                { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[-1].type_spec), (yyvsp[0].decl_spec), NULL); }
#line 1877 "src/parser.tab.cpp"
    break;

  case 16:
#line 188 "src/parser.y"
                                                                                                { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[0].type_spec), NULL, NULL); }
#line 1883 "src/parser.tab.cpp"
    break;

  case 17:
#line 190 "src/parser.y"
                                                                                                { (yyval.decl_list) = new DeclarationList(NULL, (yyvsp[0].decl)); }
#line 1889 "src/parser.tab.cpp"
    break;

  case 18:
#line 191 "src/parser.y"
                                                                                                { (yyval.decl_list) = new DeclarationList((yyvsp[-1].decl_list), (yyvsp[0].decl)); }
#line 1895 "src/parser.tab.cpp"
    break;

  case 19:
#line 193 "src/parser.y"
                                                                                                { (yyval.comp_state) = new CompoundStatement((yyvsp[-2].decl_list), (yyvsp[-1].state_list)); }
#line 1901 "src/parser.tab.cpp"
    break;

  case 20:
#line 194 "src/parser.y"
                                                                                                { (yyval.comp_state) = new CompoundStatement((yyvsp[-1].decl_list), NULL); }
#line 1907 "src/parser.tab.cpp"
    break;

  case 21:
#line 195 "src/parser.y"
                                                                                                { (yyval.comp_state) = new CompoundStatement(NULL, (yyvsp[-1].state_list)); }
#line 1913 "src/parser.tab.cpp"
    break;

  case 22:
#line 196 "src/parser.y"
                                                                                                { (yyval.comp_state) = new CompoundStatement(NULL, NULL); }
#line 1919 "src/parser.tab.cpp"
    break;

  case 23:
#line 198 "src/parser.y"
                                                                                                { (yyval.state_list) = new StatementList((yyvsp[0].state), NULL); }
#line 1925 "src/parser.tab.cpp"
    break;

  case 24:
#line 199 "src/parser.y"
                                                                                                { (yyval.state_list) = new StatementList((yyvsp[0].state), (yyvsp[-1].state_list)); }
#line 1931 "src/parser.tab.cpp"
    break;

  case 25:
#line 201 "src/parser.y"
                                                                                                { (yyval.init_declr) = new InitDeclarator((yyvsp[0].declr), NULL); }
#line 1937 "src/parser.tab.cpp"
    break;

  case 26:
#line 202 "src/parser.y"
                                                                                                { (yyval.init_declr) = new InitDeclarator((yyvsp[-2].declr), (yyvsp[0].init)); }
#line 1943 "src/parser.tab.cpp"
    break;

  case 27:
#line 204 "src/parser.y"
                                                                                                { (yyval.init) = new Initializer((yyvsp[0].ass_expr), NULL); }
#line 1949 "src/parser.tab.cpp"
    break;

  case 28:
#line 205 "src/parser.y"
                                                                                                { (yyval.init) = new Initializer(NULL, (yyvsp[-1].init_list)); }
#line 1955 "src/parser.tab.cpp"
    break;

  case 29:
#line 207 "src/parser.y"
                                                                                                { (yyval.init_list) = new InitializerList((yyvsp[0].init), NULL); }
#line 1961 "src/parser.tab.cpp"
    break;

  case 30:
#line 208 "src/parser.y"
                                                                                                { (yyval.init_list) = new InitializerList((yyvsp[0].init), (yyvsp[-2].init_list)); }
#line 1967 "src/parser.tab.cpp"
    break;

  case 31:
#line 210 "src/parser.y"
                                                                                                { (yyval.declr) = new Declarator((yyvsp[-1].ptr), (yyvsp[0].dir_declr)); }
#line 1973 "src/parser.tab.cpp"
    break;

  case 32:
#line 211 "src/parser.y"
                                                                                                { (yyval.declr) = new Declarator(NULL, (yyvsp[0].dir_declr)); }
#line 1979 "src/parser.tab.cpp"
    break;

  case 33:
#line 213 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator(NULL, NULL, NULL, NULL, (yyvsp[0].str), NULL); }
#line 1985 "src/parser.tab.cpp"
    break;

  case 34:
#line 214 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator((yyvsp[-1].declr), NULL, NULL, NULL, NULL, NULL); }
#line 1991 "src/parser.tab.cpp"
    break;

  case 35:
#line 215 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), (yyvsp[-1].str), NULL, NULL, (yyvsp[-2].str)); }
#line 1997 "src/parser.tab.cpp"
    break;

  case 36:
#line 216 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), NULL, (yyvsp[-1].param_list), NULL, NULL); }
#line 2003 "src/parser.tab.cpp"
    break;

  case 37:
#line 217 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-2].dir_declr), NULL, NULL, NULL, NULL); }
#line 2009 "src/parser.tab.cpp"
    break;

  case 40:
#line 222 "src/parser.y"
                                                                                                { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), NULL); }
#line 2015 "src/parser.tab.cpp"
    break;

  case 41:
#line 223 "src/parser.y"
                                                                                                { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), (yyvsp[-2].param_list)); }
#line 2021 "src/parser.tab.cpp"
    break;

  case 42:
#line 225 "src/parser.y"
                                                                                                { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), (yyvsp[0].declr), NULL); }
#line 2027 "src/parser.tab.cpp"
    break;

  case 43:
#line 226 "src/parser.y"
                                                                                                { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), NULL, (yyvsp[0].abs_declr)); }
#line 2033 "src/parser.tab.cpp"
    break;

  case 44:
#line 227 "src/parser.y"
                                                                                                { (yyval.param_decl) = new ParameterDeclaration((yyvsp[0].decl_spec), NULL, NULL); }
#line 2039 "src/parser.tab.cpp"
    break;

  case 45:
#line 229 "src/parser.y"
                                                                                                { (yyval.const_expr) = new ConstantExpr((yyvsp[0].cond_expr)); }
#line 2045 "src/parser.tab.cpp"
    break;

  case 58:
#line 245 "src/parser.y"
                                                                                                { (yyval.cond_expr) = new ConditionalExpr((yyvsp[0].log_or_expr), NULL, NULL); }
#line 2051 "src/parser.tab.cpp"
    break;

  case 59:
#line 246 "src/parser.y"
                                                                                                { (yyval.cond_expr) = new ConditionalExpr((yyvsp[-4].log_or_expr), (yyvsp[-2].expr), (yyvsp[0].cond_expr)); }
#line 2057 "src/parser.tab.cpp"
    break;

  case 60:
#line 248 "src/parser.y"
                                                                                                { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), NULL); }
#line 2063 "src/parser.tab.cpp"
    break;

  case 61:
#line 249 "src/parser.y"
                                                                                                { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), (yyvsp[-2].log_or_expr)); }
#line 2069 "src/parser.tab.cpp"
    break;

  case 62:
#line 251 "src/parser.y"
                                                                                                { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), NULL); }
#line 2075 "src/parser.tab.cpp"
    break;

  case 63:
#line 252 "src/parser.y"
                                                                                                { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), (yyvsp[-2].log_and_expr)); }
#line 2081 "src/parser.tab.cpp"
    break;

  case 64:
#line 254 "src/parser.y"
                                                                                                { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), NULL); }
#line 2087 "src/parser.tab.cpp"
    break;

  case 65:
#line 255 "src/parser.y"
                                                                                                { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), (yyvsp[-2].incl_or_expr)); }
#line 2093 "src/parser.tab.cpp"
    break;

  case 66:
#line 257 "src/parser.y"
                                                                                                { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), NULL); }
#line 2099 "src/parser.tab.cpp"
    break;

  case 67:
#line 258 "src/parser.y"
                                                                                                { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), (yyvsp[-2].excl_or_expr)); }
#line 2105 "src/parser.tab.cpp"
    break;

  case 68:
#line 260 "src/parser.y"
                                                                                                { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), NULL); }
#line 2111 "src/parser.tab.cpp"
    break;

  case 69:
#line 261 "src/parser.y"
                                                                                                { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), (yyvsp[-2].and_expr)); }
#line 2117 "src/parser.tab.cpp"
    break;

  case 70:
#line 263 "src/parser.y"
                                                                                                { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), NULL, NULL); }
#line 2123 "src/parser.tab.cpp"
    break;

  case 71:
#line 264 "src/parser.y"
                                                                                                { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].str)); }
#line 2129 "src/parser.tab.cpp"
    break;

  case 72:
#line 265 "src/parser.y"
                                                                                                { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].str)); }
#line 2135 "src/parser.tab.cpp"
    break;

  case 73:
#line 267 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), NULL, NULL); }
#line 2141 "src/parser.tab.cpp"
    break;

  case 74:
#line 268 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2147 "src/parser.tab.cpp"
    break;

  case 75:
#line 269 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2153 "src/parser.tab.cpp"
    break;

  case 76:
#line 270 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2159 "src/parser.tab.cpp"
    break;

  case 77:
#line 271 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2165 "src/parser.tab.cpp"
    break;

  case 78:
#line 273 "src/parser.y"
                                                                                                { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), NULL, NULL); }
#line 2171 "src/parser.tab.cpp"
    break;

  case 79:
#line 274 "src/parser.y"
                                                                                                { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].str)); }
#line 2177 "src/parser.tab.cpp"
    break;

  case 80:
#line 275 "src/parser.y"
                                                                                                { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].str)); }
#line 2183 "src/parser.tab.cpp"
    break;

  case 81:
#line 277 "src/parser.y"
                                                                                                { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), NULL, NULL); }
#line 2189 "src/parser.tab.cpp"
    break;

  case 82:
#line 278 "src/parser.y"
                                                                                                { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].str)); }
#line 2195 "src/parser.tab.cpp"
    break;

  case 83:
#line 279 "src/parser.y"
                                                                                                { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].str)); }
#line 2201 "src/parser.tab.cpp"
    break;

  case 84:
#line 281 "src/parser.y"
                                                                                                { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), NULL, NULL); }
#line 2207 "src/parser.tab.cpp"
    break;

  case 85:
#line 282 "src/parser.y"
                                                                                                { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2213 "src/parser.tab.cpp"
    break;

  case 86:
#line 283 "src/parser.y"
                                                                                                { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2219 "src/parser.tab.cpp"
    break;

  case 87:
#line 284 "src/parser.y"
                                                                                                { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2225 "src/parser.tab.cpp"
    break;

  case 88:
#line 286 "src/parser.y"
                                                                                                { (yyval.expr) = new Expr((yyvsp[0].ass_expr), NULL); }
#line 2231 "src/parser.tab.cpp"
    break;

  case 89:
#line 287 "src/parser.y"
                                                                                                { (yyval.expr) = new Expr((yyvsp[0].ass_expr), (yyvsp[-2].expr)); }
#line 2237 "src/parser.tab.cpp"
    break;

  case 90:
#line 289 "src/parser.y"
                                                                                                { (yyval.ass_expr) = new AssignmentExpr((yyvsp[0].cond_expr), NULL, NULL, NULL); }
#line 2243 "src/parser.tab.cpp"
    break;

  case 91:
#line 290 "src/parser.y"
                                                                                                { (yyval.ass_expr) = new AssignmentExpr(NULL, (yyvsp[-2].un_expr), (yyvsp[-1].ass_op), (yyvsp[0].ass_expr)); }
#line 2249 "src/parser.tab.cpp"
    break;

  case 92:
#line 292 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2255 "src/parser.tab.cpp"
    break;

  case 93:
#line 293 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2261 "src/parser.tab.cpp"
    break;

  case 94:
#line 294 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2267 "src/parser.tab.cpp"
    break;

  case 95:
#line 295 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2273 "src/parser.tab.cpp"
    break;

  case 96:
#line 296 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2279 "src/parser.tab.cpp"
    break;

  case 97:
#line 297 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2285 "src/parser.tab.cpp"
    break;

  case 98:
#line 298 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2291 "src/parser.tab.cpp"
    break;

  case 99:
#line 299 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2297 "src/parser.tab.cpp"
    break;

  case 100:
#line 300 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2303 "src/parser.tab.cpp"
    break;

  case 101:
#line 301 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2309 "src/parser.tab.cpp"
    break;

  case 102:
#line 302 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2315 "src/parser.tab.cpp"
    break;

  case 103:
#line 304 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr((yyvsp[0].post_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2321 "src/parser.tab.cpp"
    break;

  case 104:
#line 305 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2327 "src/parser.tab.cpp"
    break;

  case 105:
#line 306 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2333 "src/parser.tab.cpp"
    break;

  case 106:
#line 307 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, NULL, (yyvsp[-1].un_op), (yyvsp[0].cast_expr), NULL, NULL); }
#line 2339 "src/parser.tab.cpp"
    break;

  case 107:
#line 308 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[-1].un_expr), NULL, NULL, NULL, (yyvsp[-3].str)); }
#line 2345 "src/parser.tab.cpp"
    break;

  case 108:
#line 309 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, NULL, NULL, NULL, (yyvsp[-1].type_name), (yyvsp[-3].str)); }
#line 2351 "src/parser.tab.cpp"
    break;

  case 109:
#line 311 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2357 "src/parser.tab.cpp"
    break;

  case 110:
#line 312 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2363 "src/parser.tab.cpp"
    break;

  case 111:
#line 313 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2369 "src/parser.tab.cpp"
    break;

  case 112:
#line 314 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2375 "src/parser.tab.cpp"
    break;

  case 113:
#line 315 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2381 "src/parser.tab.cpp"
    break;

  case 114:
#line 316 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2387 "src/parser.tab.cpp"
    break;

  case 115:
#line 318 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr((yyvsp[0].pri_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2393 "src/parser.tab.cpp"
    break;

  case 116:
#line 319 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr((yyvsp[-3].pri_expr), (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 2399 "src/parser.tab.cpp"
    break;

  case 117:
#line 320 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-3].post_expr), (yyvsp[-1].arg_expr_list), NULL, NULL); }
#line 2405 "src/parser.tab.cpp"
    break;

  case 118:
#line 321 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, NULL, NULL); }
#line 2411 "src/parser.tab.cpp"
    break;

  case 119:
#line 322 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2417 "src/parser.tab.cpp"
    break;

  case 120:
#line 323 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2423 "src/parser.tab.cpp"
    break;

  case 121:
#line 324 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].str), NULL); }
#line 2429 "src/parser.tab.cpp"
    break;

  case 122:
#line 325 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].str), NULL); }
#line 2435 "src/parser.tab.cpp"
    break;

  case 123:
#line 327 "src/parser.y"
                                                                                                { (yyval.pri_expr) = new PrimaryExpr((yyvsp[0].str), NULL, NULL, NULL); }
#line 2441 "src/parser.tab.cpp"
    break;

  case 124:
#line 328 "src/parser.y"
                                                                                                { (yyval.pri_expr) = new PrimaryExpr(NULL, (yyvsp[0].str), NULL, NULL); }
#line 2447 "src/parser.tab.cpp"
    break;

  case 125:
#line 329 "src/parser.y"
                                                                                                { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, (yyvsp[0].str), NULL); }
#line 2453 "src/parser.tab.cpp"
    break;

  case 126:
#line 330 "src/parser.y"
                                                                                                { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, NULL, (yyvsp[-1].expr)); }
#line 2459 "src/parser.tab.cpp"
    break;

  case 127:
#line 332 "src/parser.y"
                                                                                                { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), NULL); }
#line 2465 "src/parser.tab.cpp"
    break;

  case 128:
#line 333 "src/parser.y"
                                                                                                { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), (yyvsp[-2].arg_expr_list)); }
#line 2471 "src/parser.tab.cpp"
    break;

  case 129:
#line 335 "src/parser.y"
                                                                                                { (yyval.cast_expr) = new CastExpr((yyvsp[0].un_expr), NULL, NULL); }
#line 2477 "src/parser.tab.cpp"
    break;

  case 130:
#line 336 "src/parser.y"
                                                                                                { (yyval.cast_expr) = new CastExpr(NULL, (yyvsp[-2].type_name), (yyvsp[0].cast_expr)); }
#line 2483 "src/parser.tab.cpp"
    break;

  case 132:
#line 339 "src/parser.y"
                                                                                                { (yyval.type_name) = new TypeName((yyvsp[0].spec_qual_list), NULL); }
#line 2489 "src/parser.tab.cpp"
    break;

  case 133:
#line 341 "src/parser.y"
                                                                                                { (yyval.state) = new Statement((yyvsp[0].label_state), NULL, NULL, NULL, NULL, NULL); }
#line 2495 "src/parser.tab.cpp"
    break;

  case 134:
#line 342 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, (yyvsp[0].comp_state), NULL, NULL, NULL, NULL); }
#line 2501 "src/parser.tab.cpp"
    break;

  case 135:
#line 343 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, NULL, (yyvsp[0].expr_state), NULL, NULL, NULL); }
#line 2507 "src/parser.tab.cpp"
    break;

  case 136:
#line 344 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, NULL, NULL, (yyvsp[0].select_state), NULL, NULL); }
#line 2513 "src/parser.tab.cpp"
    break;

  case 137:
#line 345 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, (yyvsp[0].it_state), NULL); }
#line 2519 "src/parser.tab.cpp"
    break;

  case 138:
#line 346 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, NULL, (yyvsp[0].jump_state)); }
#line 2525 "src/parser.tab.cpp"
    break;

  case 140:
#line 349 "src/parser.y"
                                                                                                { (yyval.label_state) = new LabeledStatement((yyvsp[0].state), (yyvsp[-2].const_expr)); }
#line 2531 "src/parser.tab.cpp"
    break;

  case 141:
#line 350 "src/parser.y"
                                                                                                { (yyval.label_state) = new LabeledStatement((yyvsp[0].state), NULL); }
#line 2537 "src/parser.tab.cpp"
    break;

  case 142:
#line 352 "src/parser.y"
                                                                                                { (yyval.expr_state) = new ExprStatement((yyvsp[-1].expr)); }
#line 2543 "src/parser.tab.cpp"
    break;

  case 143:
#line 353 "src/parser.y"
                                                                                                { (yyval.expr_state) = new ExprStatement(NULL); }
#line 2549 "src/parser.tab.cpp"
    break;

  case 144:
#line 355 "src/parser.y"
                                                                                                { (yyval.select_state) = new SelectionStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, (yyvsp[-4].str), NULL, NULL); }
#line 2555 "src/parser.tab.cpp"
    break;

  case 145:
#line 356 "src/parser.y"
                                                                                                { (yyval.select_state) = new SelectionStatement((yyvsp[-4].expr), (yyvsp[-2].state), (yyvsp[0].state), (yyvsp[-6].str), (yyvsp[-1].str), NULL); }
#line 2561 "src/parser.tab.cpp"
    break;

  case 146:
#line 357 "src/parser.y"
                                                                                                { (yyval.select_state) = new SelectionStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, NULL, NULL, (yyvsp[-4].str)); }
#line 2567 "src/parser.tab.cpp"
    break;

  case 147:
#line 359 "src/parser.y"
                                                                                                { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, NULL, (yyvsp[-4].str)); }
#line 2573 "src/parser.tab.cpp"
    break;

  case 148:
#line 360 "src/parser.y"
                                                                                                { (yyval.it_state) = new IterationStatement(NULL, (yyvsp[0].state), (yyvsp[-3].expr_state), (yyvsp[-2].expr_state), (yyvsp[-5].str)); }
#line 2579 "src/parser.tab.cpp"
    break;

  case 149:
#line 361 "src/parser.y"
                                                                                                { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[0].state), (yyvsp[-4].expr_state), (yyvsp[-3].expr_state), (yyvsp[-6].str)); }
#line 2585 "src/parser.tab.cpp"
    break;

  case 150:
#line 363 "src/parser.y"
                                                                                                { (yyval.jump_state) = new JumpStatement((yyvsp[-1].str), NULL); }
#line 2591 "src/parser.tab.cpp"
    break;

  case 151:
#line 364 "src/parser.y"
                                                                                                { (yyval.jump_state) = new JumpStatement((yyvsp[-1].str), NULL); }
#line 2597 "src/parser.tab.cpp"
    break;

  case 152:
#line 365 "src/parser.y"
                                                                                                         { (yyval.jump_state) = new JumpStatement((yyvsp[-2].str), (yyvsp[-1].expr)); }
#line 2603 "src/parser.tab.cpp"
    break;

  case 153:
#line 367 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2609 "src/parser.tab.cpp"
    break;

  case 154:
#line 368 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2615 "src/parser.tab.cpp"
    break;

  case 155:
#line 369 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2621 "src/parser.tab.cpp"
    break;

  case 156:
#line 370 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2627 "src/parser.tab.cpp"
    break;

  case 157:
#line 371 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2633 "src/parser.tab.cpp"
    break;

  case 158:
#line 372 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier(NULL, (yyvsp[0].struct_spec), NULL); }
#line 2639 "src/parser.tab.cpp"
    break;

  case 159:
#line 373 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier(NULL, NULL, (yyvsp[0].enum_spec)); }
#line 2645 "src/parser.tab.cpp"
    break;

  case 166:
#line 384 "src/parser.y"
                                                                                                { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[-1].type_spec), (yyvsp[0].spec_qual_list)); }
#line 2651 "src/parser.tab.cpp"
    break;

  case 167:
#line 385 "src/parser.y"
                                                                                                { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[0].type_spec), NULL); }
#line 2657 "src/parser.tab.cpp"
    break;

  case 173:
#line 394 "src/parser.y"
                                                                                                { (yyval.enum_spec) = new EnumSpecifier((yyvsp[-3].str), (yyvsp[-1].enum_list)); }
#line 2663 "src/parser.tab.cpp"
    break;

  case 174:
#line 395 "src/parser.y"
                                                                                                { (yyval.enum_spec) = new EnumSpecifier(NULL, (yyvsp[-1].enum_list)); }
#line 2669 "src/parser.tab.cpp"
    break;

  case 175:
#line 396 "src/parser.y"
                                                                                                { (yyval.enum_spec) = new EnumSpecifier((yyvsp[0].str), NULL); }
#line 2675 "src/parser.tab.cpp"
    break;

  case 176:
#line 398 "src/parser.y"
                                                                                                { (yyval.enum_list) = new EnumeratorList(NULL, (yyvsp[0].enume)); }
#line 2681 "src/parser.tab.cpp"
    break;

  case 177:
#line 399 "src/parser.y"
                                                                                                { (yyval.enum_list) = new EnumeratorList((yyvsp[-2].enum_list), (yyvsp[0].enume)); }
#line 2687 "src/parser.tab.cpp"
    break;

  case 178:
#line 401 "src/parser.y"
                                                                                                { (yyval.enume) = new Enumerator((yyvsp[0].str), NULL); }
#line 2693 "src/parser.tab.cpp"
    break;

  case 179:
#line 402 "src/parser.y"
                                                                                                { (yyval.enume) = new Enumerator((yyvsp[-2].str), (yyvsp[0].const_expr)); }
#line 2699 "src/parser.tab.cpp"
    break;


#line 2703 "src/parser.tab.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 404 "src/parser.y"


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
