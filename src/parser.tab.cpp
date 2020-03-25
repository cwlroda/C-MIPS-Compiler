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

#line 286 "src/parser.tab.cpp"

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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1091

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  192
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  325

#define YYUNDEFTOK  2
#define YYMAXUTOK   336


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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   175,   175,   177,   178,   180,   181,   183,   184,   185,
     186,   188,   189,   191,   192,   193,   194,   196,   197,   199,
     200,   201,   202,   204,   205,   207,   208,   210,   211,   212,
     214,   215,   217,   218,   220,   221,   222,   223,   224,   225,
     227,   228,   230,   231,   233,   234,   236,   237,   238,   240,
     242,   243,   244,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   256,   257,   259,   260,   262,   263,   265,   266,
     268,   269,   271,   272,   274,   275,   276,   278,   279,   280,
     281,   282,   284,   285,   286,   288,   289,   290,   292,   293,
     294,   295,   297,   298,   300,   301,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   315,   316,   317,
     318,   319,   320,   322,   323,   324,   325,   326,   327,   329,
     330,   331,   332,   333,   334,   335,   336,   338,   339,   340,
     341,   343,   344,   346,   347,   349,   350,   352,   353,   354,
     355,   356,   357,   359,   360,   361,   363,   364,   366,   367,
     368,   370,   371,   372,   373,   375,   376,   377,   379,   380,
     381,   382,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   396,   397,   398,   400,   401,   403,   405,
     406,   408,   409,   411,   412,   413,   415,   416,   417,   419,
     420,   422,   423
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
  "INIT_DECLARATOR", "INITIALIZER", "INITIALIZER_LIST", "DECLARATOR",
  "DIRECT_DECLARATOR", "POINTER", "PARAMETER_TYPE_LIST", "PARAMETER_LIST",
  "PARAMETER_DECLARATION", "CONSTANT_EXPR", "ABSTRACT_DECLARATOR",
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
static const yytype_int16 yytoknum[] =
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

#define YYPACT_NINF (-194)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     766,  -194,    21,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,     9,    23,    29,    56,
     766,  -194,  -194,  -194,    46,   946,    -7,    44,  1017,  1017,
    -194,  -194,  -194,     5,  1030,    65,   144,    76,  -194,  -194,
    -194,   148,   878,   266,  -194,    46,   946,  -194,   310,   530,
      -7,  -194,  -194,  1030,  1030,   696,  -194,    11,   144,   142,
      -5,  -194,  -194,  -194,   522,   946,  -194,   133,  -194,  -194,
     833,  -194,   841,   841,  -194,  -194,  -194,  -194,  -194,  -194,
     116,   143,   880,   154,   150,   514,   155,   231,   234,   880,
     732,  -194,   343,  -194,   420,  -194,    12,   227,   211,   212,
     216,    26,    45,    61,    84,   189,    30,  -194,   261,   880,
     145,   181,  -194,  -194,  -194,  -194,  -194,  -194,  -194,   230,
    -194,  -194,  -194,     8,   184,   180,  -194,  -194,  -194,   186,
    -194,  -194,   978,  -194,  -194,  -194,   880,   185,   257,   187,
      79,   880,  -194,   144,   522,  -194,  -194,  -194,   514,   732,
    -194,   880,  -194,  -194,   880,   880,   196,   514,   825,   197,
     880,  -194,  -194,    31,    -2,   191,    -8,  -194,   437,  -194,
    -194,   880,   880,   880,   880,   880,   880,   880,   880,   880,
     880,   880,   880,   880,   880,   880,   880,   880,   880,   880,
    -194,   880,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,   880,  -194,  -194,  -194,   274,   275,   680,
     880,   617,   605,  -194,    43,  -194,   149,  -194,   998,  -194,
    -194,  -194,   880,  -194,    11,  -194,  -194,  -194,  -194,   147,
    -194,   205,    27,    40,   514,  -194,   825,   217,    41,  -194,
    -194,   880,   913,   163,  -194,  -194,   227,   106,   211,   212,
     216,    26,    45,    45,    61,    61,    61,    61,    84,    84,
     189,   189,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,    69,   -26,  -194,   215,   218,  -194,   224,   149,   965,
     613,  -194,  -194,  -194,  -194,  -194,   175,  -194,   514,   514,
    -194,   693,   880,   514,  -194,   880,  -194,   880,  -194,  -194,
    -194,  -194,  -194,   219,  -194,   225,  -194,  -194,   228,  -194,
     514,   107,   110,  -194,  -194,  -194,  -194,  -194,   514,  -194,
     514,   296,  -194,  -194,  -194
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,    41,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,     0,     0,     0,     0,
       2,     4,     5,     6,     0,     0,    33,     0,    14,    16,
     171,   172,    40,   175,     0,   188,     0,     0,     1,     3,
      12,     0,    25,     0,    17,     0,     0,    10,     0,     0,
      32,    13,    15,     0,   180,     0,   176,     0,     0,   191,
       0,   189,    35,    11,     0,     0,     8,   127,   128,   129,
       0,   147,     0,     0,   115,   116,   114,   117,   113,   118,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,   138,     0,    94,    62,    64,    66,    68,
      70,    72,    74,    77,    82,    85,     0,    92,   133,     0,
     107,   119,    88,    23,   137,   139,   140,   141,   142,    25,
      18,     9,    39,    48,     0,    42,    44,   127,    37,     0,
      49,   133,     0,   179,   174,   177,     0,   183,     0,   181,
       0,     0,   187,     0,     0,    26,    27,     7,     0,     0,
     111,     0,   108,   109,     0,     0,     0,     0,     0,     0,
       0,   155,   156,     0,     0,     0,   136,    20,     0,    21,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,     0,   100,    97,    98,    99,   101,   104,   102,   103,
      96,   106,   105,     0,   110,   125,   126,     0,     0,     0,
       0,     0,     0,    46,    50,    47,    52,    38,     0,    36,
     173,   185,     0,   178,     0,   186,   192,   190,    30,     0,
     143,     0,     0,     0,     0,   145,     0,     0,     0,   157,
     130,     0,     0,    50,   135,    19,    65,     0,    67,    69,
      71,    73,    75,    76,    80,    81,    78,    79,    83,    84,
      86,    87,    89,    90,    91,    93,    95,   124,   123,   122,
     131,     0,     0,    61,     0,     0,    57,     0,    51,     0,
       0,    43,    45,   184,   182,    28,     0,   112,     0,     0,
     144,     0,     0,     0,   134,     0,   121,     0,   120,    60,
      53,    56,    59,     0,    55,     0,    29,    31,   148,   150,
       0,     0,     0,   151,    63,   132,    58,    54,     0,   153,
       0,     0,   149,   154,   152
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,  -194,   284,  -194,    13,     0,   153,   127,   213,
    -194,  -138,  -194,   -14,   -20,     1,   -43,  -194,    96,   -66,
    -104,  -193,   -47,  -194,   157,   151,   156,   166,   167,    25,
      19,    24,    59,    17,   -46,  -194,   -48,  -194,  -194,  -194,
    -194,   -92,   176,   -58,  -194,  -150,  -194,  -194,  -194,  -194,
      10,  -194,   289,   -40,   -45,  -194,   129,  -194,   300,   226
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    44,    45,    46,    93,    94,
      41,   145,   229,    25,    26,    27,   274,   125,   126,   129,
     275,   216,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   203,   108,   109,   110,   111,
     271,   112,   165,   113,   114,   115,   116,   117,   118,    28,
      29,    30,    55,    56,    57,   138,   139,    31,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   131,   130,    32,    37,   124,   228,    50,   236,   133,
      42,     1,    33,    23,     1,   135,   156,   204,   146,   215,
      24,   278,   150,     2,   152,   153,    35,   159,    51,    52,
     171,   119,     1,    23,   131,   130,   170,   190,   239,     2,
     177,   178,     2,   137,    54,   166,     1,     1,   123,     1,
     278,   298,     2,    40,   172,   191,    38,   179,   180,   120,
       2,   131,   244,    54,    54,    54,   242,    48,   212,    49,
     221,   183,   184,   240,   142,   226,   143,     2,   120,   191,
     181,   182,   211,    53,   212,    18,   291,    34,   131,   130,
     230,   136,   135,   131,   130,   262,   263,   264,   146,   235,
      54,    36,   288,    18,   166,   120,   163,   164,   191,   213,
     170,   191,   191,   185,   186,   289,   293,   211,    18,   212,
      18,   191,   191,   131,   214,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,    54,    58,   296,   265,   277,    59,   307,   294,
     297,    62,    47,   205,   206,    63,   283,   266,   225,    54,
     143,   207,   208,   270,   131,   130,   164,   243,   164,    66,
     141,   232,   233,   121,   131,   130,   290,   238,   127,    68,
      69,    70,   320,    72,    73,   321,   295,   191,   191,   247,
     154,   191,   147,   131,    50,    65,    92,    37,   254,   255,
     256,   257,   252,   253,    74,    75,    76,   258,   259,    77,
     137,   123,   214,   148,   305,    78,    79,   155,   123,   209,
     187,   188,   189,   279,   158,   280,   285,   272,   286,   160,
     308,   309,   131,   130,   157,   313,   303,   242,   161,   212,
     146,   162,   123,   243,   260,   261,   173,   131,   314,    90,
     174,   315,   319,   144,   306,   175,   176,   210,    64,   217,
     322,   218,   323,   219,   223,   222,   241,   237,   224,    67,
      68,    69,    70,    71,    72,    73,   234,   267,   268,   123,
     287,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     299,   292,   318,   300,   316,    74,    75,    76,   201,   202,
      77,   301,   317,   324,    39,   168,    78,    79,   311,   312,
       3,     4,     5,     6,   282,     7,     8,     9,    10,    11,
      12,    13,    14,    15,   248,   231,    16,    17,   246,    80,
     249,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   250,   132,   251,    43,    91,    67,    68,    69,    70,
      71,    72,    73,   284,     3,     4,     5,     6,   140,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,   227,
      16,    17,    74,    75,    76,     0,     0,    77,     0,     0,
       0,     0,     0,    78,    79,   122,     0,     3,     4,     5,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,    80,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,    43,   167,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,     0,     0,    74,
      75,    76,     0,     0,    77,     0,     0,     0,     0,     0,
      78,    79,     0,     0,     0,     0,    74,    75,    76,     0,
       0,    77,     0,     0,     0,     0,     0,    78,    79,     0,
       0,     0,     0,    80,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,    43,   169,
      80,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,    43,   245,    67,    68,    69,
      70,    71,    72,    73,     0,   127,    68,    69,    70,     0,
      72,    73,     0,   127,    68,    69,    70,     0,    72,    73,
       0,     0,     0,    74,    75,    76,     0,     0,    77,     0,
       0,    74,    75,    76,    78,    79,    77,     0,     0,    74,
      75,    76,    78,    79,    77,     0,     0,     0,     0,     0,
      78,    79,     0,     0,     0,     0,     0,    80,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,    43,     0,     0,     0,    90,     0,     0,     0,
     144,     0,     0,     0,    90,     0,     0,   128,   127,    68,
      69,    70,     0,    72,    73,     0,   127,    68,    69,    70,
       1,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,     0,     0,    77,
       0,     0,    74,    75,    76,    78,    79,    77,     2,     0,
       0,     0,     0,    78,    79,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,    16,    17,    90,
       0,     0,   276,   127,    68,    69,    70,    90,    72,    73,
     304,   211,   273,   212,     0,     0,   127,    68,    69,    70,
       0,    72,    73,     0,     0,     0,     0,     0,     0,    74,
      75,    76,     0,     0,    77,     0,     0,     0,     0,     0,
      78,    79,    74,    75,    76,     0,     0,    77,     0,     0,
       0,     0,     0,    78,    79,   127,    68,    69,    70,     0,
      72,    73,     0,     0,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    90,   269,    16,    17,     0,     0,
       0,    74,    75,    76,     0,     0,    77,    90,   310,     1,
       0,     0,    78,    79,     0,   134,     0,     0,     0,     0,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       0,     0,    16,    17,     0,     0,     0,     2,     0,     0,
       0,     0,     0,     0,     0,     0,    90,     0,     0,     0,
       3,     4,     5,     6,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,    16,    17,   127,    68,
      69,    70,    71,    72,    73,     0,   127,    68,    69,    70,
      18,    72,    73,     0,   127,    68,    69,    70,     0,    72,
      73,     0,     0,     0,    74,    75,    76,     0,     0,    77,
       0,     0,    74,    75,    76,    78,    79,    77,     0,     0,
      74,    75,    76,    78,    79,    77,     0,     0,     0,     0,
       0,    78,    79,   127,    68,    69,    70,     0,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,    64,   149,     0,    74,
      75,    76,     0,     0,    77,   151,     0,     0,     0,     0,
      78,    79,     3,     4,     5,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,    16,    17,
       0,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,    43,     3,     4,     5,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   242,   273,   212,
       3,     4,     5,     6,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,     0,     0,    16,    17,     0,     3,
       4,     5,     6,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    43,    16,    17,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,     0,    16,    17,
     302,     0,     3,     4,     5,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,     0,   220,    16,    17,
     281,     3,     4,     5,     6,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     0,     0,    16,    17,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     0,     0,
      16,    17
};

static const yytype_int16 yycheck[] =
{
       0,    49,    49,     2,    18,    48,   144,    27,   158,    54,
      24,     3,     3,     0,     3,    55,    82,   109,    64,   123,
      20,   214,    70,    31,    72,    73,     3,    85,    28,    29,
      18,    45,     3,    20,    82,    82,    94,     7,     7,    31,
      14,    15,    31,    57,    34,    90,     3,     3,    48,     3,
     243,    77,    31,     7,    42,    81,     0,    12,    13,    46,
      31,   109,   166,    53,    54,    55,    74,    74,    76,    76,
     136,    10,    11,    75,    79,   141,    81,    31,    65,    81,
      35,    36,    74,    78,    76,    74,   236,    78,   136,   136,
     148,    80,   132,   141,   141,   187,   188,   189,   144,   157,
      90,    78,    75,    74,   149,    92,    89,    90,    81,   123,
     168,    81,    81,    29,    30,    75,    75,    74,    74,    76,
      74,    81,    81,   171,   123,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   132,    78,    75,   191,   212,     3,   286,   241,
      81,    75,    25,     8,     9,     7,   222,   203,    79,   149,
      81,    16,    17,   209,   212,   212,   149,   166,   151,    42,
      28,   154,   155,    46,   222,   222,   234,   160,     3,     4,
       5,     6,    75,     8,     9,    75,    80,    81,    81,   172,
      74,    81,    65,   241,   214,    42,    43,   211,   179,   180,
     181,   182,   177,   178,    29,    30,    31,   183,   184,    34,
     224,   211,   211,    80,   280,    40,    41,    74,   218,    74,
      31,    32,    33,    74,    74,    76,    79,   210,    81,    74,
     288,   289,   280,   280,    80,   293,   279,    74,     7,    76,
     286,     7,   242,   242,   185,   186,    19,   295,   295,    74,
      39,   297,   310,    78,    79,    43,    40,    76,    28,    75,
     318,    81,   320,    77,     7,    80,    75,    70,    81,     3,
       4,     5,     6,     7,     8,     9,    80,     3,     3,   279,
      75,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      75,    74,    64,    75,    75,    29,    30,    31,    37,    38,
      34,    77,    77,     7,    20,    92,    40,    41,   291,   292,
      44,    45,    46,    47,   218,    49,    50,    51,    52,    53,
      54,    55,    56,    57,   173,   149,    60,    61,   171,    63,
     174,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   175,    53,   176,    78,    79,     3,     4,     5,     6,
       7,     8,     9,   224,    44,    45,    46,    47,    58,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,   143,
      60,    61,    29,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    75,    -1,    44,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    -1,    63,    -1,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      -1,    78,    79,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    29,
      30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    63,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    78,    79,
      63,    -1,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    79,     3,     4,     5,
       6,     7,     8,     9,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,    -1,
      -1,    29,    30,    31,    40,    41,    34,    -1,    -1,    29,
      30,    31,    40,    41,    34,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    74,    -1,    -1,    77,     3,     4,
       5,     6,    -1,     8,     9,    -1,     3,     4,     5,     6,
       3,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      -1,    -1,    29,    30,    31,    40,    41,    34,    31,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    74,
      -1,    -1,    77,     3,     4,     5,     6,    74,     8,     9,
      77,    74,    75,    76,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      40,    41,    29,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    74,    75,    60,    61,    -1,    -1,
      -1,    29,    30,    31,    -1,    -1,    34,    74,    75,     3,
      -1,    -1,    40,    41,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    60,    61,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,     3,     4,
       5,     6,     7,     8,     9,    -1,     3,     4,     5,     6,
      74,     8,     9,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    29,    30,    31,    -1,    -1,    34,
      -1,    -1,    29,    30,    31,    40,    41,    34,    -1,    -1,
      29,    30,    31,    40,    41,    34,    -1,    -1,    -1,    -1,
      -1,    40,    41,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    74,    -1,    29,
      30,    31,    -1,    -1,    34,    74,    -1,    -1,    -1,    -1,
      40,    41,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    78,    44,    45,    46,
      47,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    -1,    60,    61,    -1,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    78,    60,    61,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    60,    61,
      75,    -1,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    79,    60,    61,
      62,    44,    45,    46,    47,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,    60,    61,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      60,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    31,    44,    45,    46,    47,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    60,    61,    74,    83,
      84,    85,    86,    87,    88,    95,    96,    97,   131,   132,
     133,   139,    97,     3,    78,     3,    78,    95,     0,    85,
       7,    92,    95,    78,    87,    88,    89,    90,    74,    76,
      96,    88,    88,    78,   132,   134,   135,   136,    78,     3,
     140,   141,    75,     7,    28,    89,    90,     3,     4,     5,
       6,     7,     8,     9,    29,    30,    31,    34,    40,    41,
      63,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    79,    89,    90,    91,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   118,   119,
     120,   121,   123,   125,   126,   127,   128,   129,   130,    95,
      87,    90,    75,    88,    98,    99,   100,     3,    77,   101,
     104,   118,   134,   136,    79,   135,    80,    95,   137,   138,
     140,    28,    79,    81,    78,    93,   116,    90,    80,    74,
     118,    74,   118,   118,    74,    74,   101,    80,    74,   125,
      74,     7,     7,   115,   115,   124,   136,    79,    91,    79,
     125,    18,    42,    19,    39,    43,    40,    14,    15,    12,
      13,    35,    36,    10,    11,    29,    30,    31,    32,    33,
       7,    81,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    37,    38,   117,   123,     8,     9,    16,    17,    74,
      76,    74,    76,    95,    97,   102,   103,    75,    81,    77,
      79,   101,    80,     7,    81,    79,   101,   141,    93,    94,
     125,   124,   115,   115,    80,   125,   127,    70,   115,     7,
      75,    75,    74,    97,   102,    79,   106,   115,   107,   108,
     109,   110,   111,   111,   112,   112,   112,   112,   113,   113,
     114,   114,   123,   123,   123,   116,   116,     3,     3,    75,
     116,   122,   115,    75,    98,   102,    77,   101,   103,    74,
      76,    62,   100,   101,   138,    79,    81,    75,    75,    75,
     125,   127,    74,    75,   123,    80,    75,    81,    77,    75,
      75,    77,    75,    98,    77,   101,    79,    93,   125,   125,
      75,   115,   115,   125,   104,   116,    75,    77,    64,   125,
      75,    75,   125,   125,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    87,    87,    88,    88,    88,    88,    89,    89,    90,
      90,    90,    90,    91,    91,    92,    92,    93,    93,    93,
      94,    94,    95,    95,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   100,   101,
     102,   102,   102,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   109,   109,   110,   110,   110,   111,   111,   111,
     111,   111,   112,   112,   112,   113,   113,   113,   114,   114,
     114,   114,   115,   115,   116,   116,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   118,   118,   118,
     118,   118,   118,   119,   119,   119,   119,   119,   119,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   126,   126,   126,   127,   127,   128,   128,
     128,   129,   129,   129,   129,   130,   130,   130,   131,   131,
     131,   131,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   133,   133,   133,   134,   134,   135,   136,
     136,   137,   137,   138,   138,   138,   139,   139,   139,   140,
     140,   141,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     3,     3,
       2,     3,     2,     2,     1,     2,     1,     1,     2,     4,
       3,     3,     2,     1,     2,     1,     3,     1,     3,     4,
       1,     3,     2,     1,     1,     3,     4,     3,     4,     3,
       2,     1,     1,     3,     1,     3,     2,     2,     1,     1,
       1,     2,     1,     3,     4,     3,     3,     2,     4,     3,
       3,     2,     1,     5,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     3,     3,     3,     2,     2,     1,     1,     1,
       3,     1,     3,     1,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     1,     5,     7,
       5,     5,     7,     6,     7,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 175 "src/parser.y"
                       { g_root = (yyvsp[0].trans_unit); }
#line 1873 "src/parser.tab.cpp"
    break;

  case 3:
#line 177 "src/parser.y"
                                                                                                { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), (yyvsp[-1].trans_unit)); }
#line 1879 "src/parser.tab.cpp"
    break;

  case 4:
#line 178 "src/parser.y"
                                                                                                { (yyval.trans_unit) = new TranslationUnit((yyvsp[0].ext_decl), NULL); }
#line 1885 "src/parser.tab.cpp"
    break;

  case 5:
#line 180 "src/parser.y"
                                                                                                { (yyval.ext_decl) = new ExternalDeclaration((yyvsp[0].func_def), NULL); }
#line 1891 "src/parser.tab.cpp"
    break;

  case 6:
#line 181 "src/parser.y"
                                                                                                { (yyval.ext_decl) = new ExternalDeclaration(NULL, (yyvsp[0].decl)); }
#line 1897 "src/parser.tab.cpp"
    break;

  case 7:
#line 183 "src/parser.y"
                                                                                                { (yyval.func_def) = new FunctionDefinition((yyvsp[-3].decl_spec), (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1903 "src/parser.tab.cpp"
    break;

  case 8:
#line 184 "src/parser.y"
                                                                                                { (yyval.func_def) = new FunctionDefinition((yyvsp[-2].decl_spec), (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1909 "src/parser.tab.cpp"
    break;

  case 9:
#line 185 "src/parser.y"
                                                                                                { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-2].declr), (yyvsp[-1].decl_list), (yyvsp[0].comp_state)); }
#line 1915 "src/parser.tab.cpp"
    break;

  case 10:
#line 186 "src/parser.y"
                                                                                                { (yyval.func_def) = new FunctionDefinition(NULL, (yyvsp[-1].declr), NULL, (yyvsp[0].comp_state)); }
#line 1921 "src/parser.tab.cpp"
    break;

  case 11:
#line 188 "src/parser.y"
                                                                                           { (yyval.decl) = new Declaration((yyvsp[-2].decl_spec), (yyvsp[-1].init_declr)); }
#line 1927 "src/parser.tab.cpp"
    break;

  case 12:
#line 189 "src/parser.y"
                                                                                                { (yyval.decl) = new Declaration((yyvsp[-1].decl_spec), NULL); }
#line 1933 "src/parser.tab.cpp"
    break;

  case 13:
#line 191 "src/parser.y"
                                                                                                { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[-1].store_spec), NULL, (yyvsp[0].decl_spec)); }
#line 1939 "src/parser.tab.cpp"
    break;

  case 14:
#line 192 "src/parser.y"
                                                                                                { (yyval.decl_spec) = new DeclarationSpecifier((yyvsp[0].store_spec), NULL, NULL); }
#line 1945 "src/parser.tab.cpp"
    break;

  case 15:
#line 193 "src/parser.y"
                                                                                                { (yyval.decl_spec) = new DeclarationSpecifier(NULL, (yyvsp[-1].type_spec), (yyvsp[0].decl_spec)); }
#line 1951 "src/parser.tab.cpp"
    break;

  case 16:
#line 194 "src/parser.y"
                                                                                                { (yyval.decl_spec) = new DeclarationSpecifier(NULL, (yyvsp[0].type_spec), NULL); }
#line 1957 "src/parser.tab.cpp"
    break;

  case 17:
#line 196 "src/parser.y"
                                                                                                { (yyval.decl_list) = new DeclarationList(NULL, (yyvsp[0].decl)); }
#line 1963 "src/parser.tab.cpp"
    break;

  case 18:
#line 197 "src/parser.y"
                                                                                                { (yyval.decl_list) = new DeclarationList((yyvsp[-1].decl_list), (yyvsp[0].decl)); }
#line 1969 "src/parser.tab.cpp"
    break;

  case 19:
#line 199 "src/parser.y"
                                                                                                { (yyval.comp_state) = new CompoundStatement((yyvsp[-2].decl_list), (yyvsp[-1].state_list)); }
#line 1975 "src/parser.tab.cpp"
    break;

  case 20:
#line 200 "src/parser.y"
                                                                                                { (yyval.comp_state) = new CompoundStatement((yyvsp[-1].decl_list), NULL); }
#line 1981 "src/parser.tab.cpp"
    break;

  case 21:
#line 201 "src/parser.y"
                                                                                                { (yyval.comp_state) = new CompoundStatement(NULL, (yyvsp[-1].state_list)); }
#line 1987 "src/parser.tab.cpp"
    break;

  case 22:
#line 202 "src/parser.y"
                                                                                                { (yyval.comp_state) = new CompoundStatement(NULL, NULL); }
#line 1993 "src/parser.tab.cpp"
    break;

  case 23:
#line 204 "src/parser.y"
                                                                                                { (yyval.state_list) = new StatementList((yyvsp[0].state), NULL); }
#line 1999 "src/parser.tab.cpp"
    break;

  case 24:
#line 205 "src/parser.y"
                                                                                                { (yyval.state_list) = new StatementList((yyvsp[0].state), (yyvsp[-1].state_list)); }
#line 2005 "src/parser.tab.cpp"
    break;

  case 25:
#line 207 "src/parser.y"
                                                                                                { (yyval.init_declr) = new InitDeclarator((yyvsp[0].declr), NULL); }
#line 2011 "src/parser.tab.cpp"
    break;

  case 26:
#line 208 "src/parser.y"
                                                                                                { (yyval.init_declr) = new InitDeclarator((yyvsp[-2].declr), (yyvsp[0].init)); }
#line 2017 "src/parser.tab.cpp"
    break;

  case 27:
#line 210 "src/parser.y"
                                                                                                { (yyval.init) = new Initializer((yyvsp[0].ass_expr), NULL); }
#line 2023 "src/parser.tab.cpp"
    break;

  case 28:
#line 211 "src/parser.y"
                                                                                                { (yyval.init) = new Initializer(NULL, (yyvsp[-1].init_list)); }
#line 2029 "src/parser.tab.cpp"
    break;

  case 29:
#line 212 "src/parser.y"
                                                                                                { (yyval.init) = new Initializer(NULL, (yyvsp[-2].init_list)); }
#line 2035 "src/parser.tab.cpp"
    break;

  case 30:
#line 214 "src/parser.y"
                                                                                                { (yyval.init_list) = new InitializerList((yyvsp[0].init), NULL); }
#line 2041 "src/parser.tab.cpp"
    break;

  case 31:
#line 215 "src/parser.y"
                                                                                                { (yyval.init_list) = new InitializerList((yyvsp[0].init), (yyvsp[-2].init_list)); }
#line 2047 "src/parser.tab.cpp"
    break;

  case 32:
#line 217 "src/parser.y"
                                                                                                { (yyval.declr) = new Declarator((yyvsp[-1].ptr), (yyvsp[0].dir_declr)); }
#line 2053 "src/parser.tab.cpp"
    break;

  case 33:
#line 218 "src/parser.y"
                                                                                                { (yyval.declr) = new Declarator(NULL, (yyvsp[0].dir_declr)); }
#line 2059 "src/parser.tab.cpp"
    break;

  case 34:
#line 220 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator(NULL, NULL, NULL, NULL, (yyvsp[0].str), NULL); }
#line 2065 "src/parser.tab.cpp"
    break;

  case 35:
#line 221 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator((yyvsp[-1].declr), NULL, NULL, NULL, NULL, NULL); }
#line 2071 "src/parser.tab.cpp"
    break;

  case 36:
#line 222 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), (yyvsp[-1].const_expr), NULL, NULL, NULL); }
#line 2077 "src/parser.tab.cpp"
    break;

  case 37:
#line 223 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-2].dir_declr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2083 "src/parser.tab.cpp"
    break;

  case 38:
#line 224 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-3].dir_declr), NULL, (yyvsp[-1].param_type_list), NULL, NULL); }
#line 2089 "src/parser.tab.cpp"
    break;

  case 39:
#line 225 "src/parser.y"
                                                                                                { (yyval.dir_declr) = new DirectDeclarator(NULL, (yyvsp[-2].dir_declr), NULL, NULL, NULL, NULL); }
#line 2095 "src/parser.tab.cpp"
    break;

  case 42:
#line 230 "src/parser.y"
                                                                                                { (yyval.param_type_list) = new ParameterTypeList((yyvsp[0].param_list), NULL); }
#line 2101 "src/parser.tab.cpp"
    break;

  case 43:
#line 231 "src/parser.y"
                                                                                                { (yyval.param_type_list) = new ParameterTypeList((yyvsp[-2].param_list), (yyvsp[0].str)); }
#line 2107 "src/parser.tab.cpp"
    break;

  case 44:
#line 233 "src/parser.y"
                                                                                                { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), NULL); }
#line 2113 "src/parser.tab.cpp"
    break;

  case 45:
#line 234 "src/parser.y"
                                                                                                { (yyval.param_list) = new ParameterList((yyvsp[0].param_decl), (yyvsp[-2].param_list)); }
#line 2119 "src/parser.tab.cpp"
    break;

  case 46:
#line 236 "src/parser.y"
                                                                                                { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), (yyvsp[0].declr), NULL); }
#line 2125 "src/parser.tab.cpp"
    break;

  case 47:
#line 237 "src/parser.y"
                                                                                                { (yyval.param_decl) = new ParameterDeclaration((yyvsp[-1].decl_spec), NULL, (yyvsp[0].abs_declr)); }
#line 2131 "src/parser.tab.cpp"
    break;

  case 48:
#line 238 "src/parser.y"
                                                                                                { (yyval.param_decl) = new ParameterDeclaration((yyvsp[0].decl_spec), NULL, NULL); }
#line 2137 "src/parser.tab.cpp"
    break;

  case 49:
#line 240 "src/parser.y"
                                                                                                { (yyval.const_expr) = new ConstantExpr((yyvsp[0].cond_expr)); }
#line 2143 "src/parser.tab.cpp"
    break;

  case 62:
#line 256 "src/parser.y"
                                                                                                { (yyval.cond_expr) = new ConditionalExpr((yyvsp[0].log_or_expr), NULL, NULL); }
#line 2149 "src/parser.tab.cpp"
    break;

  case 63:
#line 257 "src/parser.y"
                                                                                                { (yyval.cond_expr) = new ConditionalExpr((yyvsp[-4].log_or_expr), (yyvsp[-2].expr), (yyvsp[0].cond_expr)); }
#line 2155 "src/parser.tab.cpp"
    break;

  case 64:
#line 259 "src/parser.y"
                                                                                                { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), NULL); }
#line 2161 "src/parser.tab.cpp"
    break;

  case 65:
#line 260 "src/parser.y"
                                                                                                { (yyval.log_or_expr) = new LogicalOrExpr((yyvsp[0].log_and_expr), (yyvsp[-2].log_or_expr)); }
#line 2167 "src/parser.tab.cpp"
    break;

  case 66:
#line 262 "src/parser.y"
                                                                                                { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), NULL); }
#line 2173 "src/parser.tab.cpp"
    break;

  case 67:
#line 263 "src/parser.y"
                                                                                                { (yyval.log_and_expr) = new LogicalAndExpr((yyvsp[0].incl_or_expr), (yyvsp[-2].log_and_expr)); }
#line 2179 "src/parser.tab.cpp"
    break;

  case 68:
#line 265 "src/parser.y"
                                                                                                { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), NULL); }
#line 2185 "src/parser.tab.cpp"
    break;

  case 69:
#line 266 "src/parser.y"
                                                                                                { (yyval.incl_or_expr) = new InclusiveOrExpr((yyvsp[0].excl_or_expr), (yyvsp[-2].incl_or_expr)); }
#line 2191 "src/parser.tab.cpp"
    break;

  case 70:
#line 268 "src/parser.y"
                                                                                                { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), NULL); }
#line 2197 "src/parser.tab.cpp"
    break;

  case 71:
#line 269 "src/parser.y"
                                                                                                { (yyval.excl_or_expr) = new ExclusiveOrExpr((yyvsp[0].and_expr), (yyvsp[-2].excl_or_expr)); }
#line 2203 "src/parser.tab.cpp"
    break;

  case 72:
#line 271 "src/parser.y"
                                                                                                { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), NULL); }
#line 2209 "src/parser.tab.cpp"
    break;

  case 73:
#line 272 "src/parser.y"
                                                                                                { (yyval.and_expr) = new AndExpr((yyvsp[0].equal_expr), (yyvsp[-2].and_expr)); }
#line 2215 "src/parser.tab.cpp"
    break;

  case 74:
#line 274 "src/parser.y"
                                                                                                { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), NULL, NULL); }
#line 2221 "src/parser.tab.cpp"
    break;

  case 75:
#line 275 "src/parser.y"
                                                                                                { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].str)); }
#line 2227 "src/parser.tab.cpp"
    break;

  case 76:
#line 276 "src/parser.y"
                                                                                                { (yyval.equal_expr) = new EqualityExpr((yyvsp[0].rel_expr), (yyvsp[-2].equal_expr), (yyvsp[-1].str)); }
#line 2233 "src/parser.tab.cpp"
    break;

  case 77:
#line 278 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), NULL, NULL); }
#line 2239 "src/parser.tab.cpp"
    break;

  case 78:
#line 279 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2245 "src/parser.tab.cpp"
    break;

  case 79:
#line 280 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2251 "src/parser.tab.cpp"
    break;

  case 80:
#line 281 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2257 "src/parser.tab.cpp"
    break;

  case 81:
#line 282 "src/parser.y"
                                                                                                { (yyval.rel_expr) = new RelationalExpr((yyvsp[0].shift_expr), (yyvsp[-2].rel_expr), (yyvsp[-1].str)); }
#line 2263 "src/parser.tab.cpp"
    break;

  case 82:
#line 284 "src/parser.y"
                                                                                                { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), NULL, NULL); }
#line 2269 "src/parser.tab.cpp"
    break;

  case 83:
#line 285 "src/parser.y"
                                                                                                { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].str)); }
#line 2275 "src/parser.tab.cpp"
    break;

  case 84:
#line 286 "src/parser.y"
                                                                                                { (yyval.shift_expr) = new ShiftExpr((yyvsp[0].add_expr), (yyvsp[-2].shift_expr), (yyvsp[-1].str)); }
#line 2281 "src/parser.tab.cpp"
    break;

  case 85:
#line 288 "src/parser.y"
                                                                                                { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), NULL, NULL); }
#line 2287 "src/parser.tab.cpp"
    break;

  case 86:
#line 289 "src/parser.y"
                                                                                                { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].str)); }
#line 2293 "src/parser.tab.cpp"
    break;

  case 87:
#line 290 "src/parser.y"
                                                                                                { (yyval.add_expr) = new AdditiveExpr((yyvsp[0].mul_expr), (yyvsp[-2].add_expr), (yyvsp[-1].str)); }
#line 2299 "src/parser.tab.cpp"
    break;

  case 88:
#line 292 "src/parser.y"
                                                                                                { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), NULL, NULL); }
#line 2305 "src/parser.tab.cpp"
    break;

  case 89:
#line 293 "src/parser.y"
                                                                                                { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2311 "src/parser.tab.cpp"
    break;

  case 90:
#line 294 "src/parser.y"
                                                                                                { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2317 "src/parser.tab.cpp"
    break;

  case 91:
#line 295 "src/parser.y"
                                                                                                { (yyval.mul_expr) = new MultiplicativeExpr((yyvsp[0].cast_expr), (yyvsp[-2].mul_expr), (yyvsp[-1].str)); }
#line 2323 "src/parser.tab.cpp"
    break;

  case 92:
#line 297 "src/parser.y"
                                                                                                { (yyval.expr) = new Expr((yyvsp[0].ass_expr), NULL); }
#line 2329 "src/parser.tab.cpp"
    break;

  case 93:
#line 298 "src/parser.y"
                                                                                                { (yyval.expr) = new Expr((yyvsp[0].ass_expr), (yyvsp[-2].expr)); }
#line 2335 "src/parser.tab.cpp"
    break;

  case 94:
#line 300 "src/parser.y"
                                                                                                { (yyval.ass_expr) = new AssignmentExpr((yyvsp[0].cond_expr), NULL, NULL, NULL); }
#line 2341 "src/parser.tab.cpp"
    break;

  case 95:
#line 301 "src/parser.y"
                                                                                                { (yyval.ass_expr) = new AssignmentExpr(NULL, (yyvsp[-2].un_expr), (yyvsp[-1].ass_op), (yyvsp[0].ass_expr)); }
#line 2347 "src/parser.tab.cpp"
    break;

  case 96:
#line 303 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2353 "src/parser.tab.cpp"
    break;

  case 97:
#line 304 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2359 "src/parser.tab.cpp"
    break;

  case 98:
#line 305 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2365 "src/parser.tab.cpp"
    break;

  case 99:
#line 306 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2371 "src/parser.tab.cpp"
    break;

  case 100:
#line 307 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2377 "src/parser.tab.cpp"
    break;

  case 101:
#line 308 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2383 "src/parser.tab.cpp"
    break;

  case 102:
#line 309 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2389 "src/parser.tab.cpp"
    break;

  case 103:
#line 310 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2395 "src/parser.tab.cpp"
    break;

  case 104:
#line 311 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2401 "src/parser.tab.cpp"
    break;

  case 105:
#line 312 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2407 "src/parser.tab.cpp"
    break;

  case 106:
#line 313 "src/parser.y"
                                                                                                { (yyval.ass_op) = new AssignmentOperator((yyvsp[0].str)); }
#line 2413 "src/parser.tab.cpp"
    break;

  case 107:
#line 315 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr((yyvsp[0].post_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2419 "src/parser.tab.cpp"
    break;

  case 108:
#line 316 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2425 "src/parser.tab.cpp"
    break;

  case 109:
#line 317 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2431 "src/parser.tab.cpp"
    break;

  case 110:
#line 318 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, NULL, (yyvsp[-1].un_op), (yyvsp[0].cast_expr), NULL, NULL); }
#line 2437 "src/parser.tab.cpp"
    break;

  case 111:
#line 319 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, (yyvsp[0].un_expr), NULL, NULL, NULL, (yyvsp[-1].str)); }
#line 2443 "src/parser.tab.cpp"
    break;

  case 112:
#line 320 "src/parser.y"
                                                                                                { (yyval.un_expr) = new UnaryExpr(NULL, NULL, NULL, NULL, (yyvsp[-1].type_name), (yyvsp[-3].str)); }
#line 2449 "src/parser.tab.cpp"
    break;

  case 113:
#line 322 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2455 "src/parser.tab.cpp"
    break;

  case 114:
#line 323 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2461 "src/parser.tab.cpp"
    break;

  case 115:
#line 324 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2467 "src/parser.tab.cpp"
    break;

  case 116:
#line 325 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2473 "src/parser.tab.cpp"
    break;

  case 117:
#line 326 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2479 "src/parser.tab.cpp"
    break;

  case 118:
#line 327 "src/parser.y"
                                                                                                { (yyval.un_op) = new UnaryOperator((yyvsp[0].str)); }
#line 2485 "src/parser.tab.cpp"
    break;

  case 119:
#line 329 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr((yyvsp[0].pri_expr), NULL, NULL, NULL, NULL, NULL); }
#line 2491 "src/parser.tab.cpp"
    break;

  case 120:
#line 330 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr((yyvsp[-3].pri_expr), (yyvsp[-1].expr), NULL, NULL, NULL, NULL); }
#line 2497 "src/parser.tab.cpp"
    break;

  case 121:
#line 331 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-3].post_expr), (yyvsp[-1].arg_expr_list), NULL, NULL); }
#line 2503 "src/parser.tab.cpp"
    break;

  case 122:
#line 332 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, NULL, NULL); }
#line 2509 "src/parser.tab.cpp"
    break;

  case 123:
#line 333 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2515 "src/parser.tab.cpp"
    break;

  case 124:
#line 334 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-2].post_expr), NULL, (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2521 "src/parser.tab.cpp"
    break;

  case 125:
#line 335 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].str), NULL); }
#line 2527 "src/parser.tab.cpp"
    break;

  case 126:
#line 336 "src/parser.y"
                                                                                                { (yyval.post_expr) = new PostfixExpr(NULL, NULL, (yyvsp[-1].post_expr), NULL, (yyvsp[0].str), NULL); }
#line 2533 "src/parser.tab.cpp"
    break;

  case 127:
#line 338 "src/parser.y"
                                                                                                { (yyval.pri_expr) = new PrimaryExpr((yyvsp[0].str), NULL, NULL, NULL); }
#line 2539 "src/parser.tab.cpp"
    break;

  case 128:
#line 339 "src/parser.y"
                                                                                                { (yyval.pri_expr) = new PrimaryExpr(NULL, (yyvsp[0].str), NULL, NULL); }
#line 2545 "src/parser.tab.cpp"
    break;

  case 129:
#line 340 "src/parser.y"
                                                                                                { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, (yyvsp[0].str), NULL); }
#line 2551 "src/parser.tab.cpp"
    break;

  case 130:
#line 341 "src/parser.y"
                                                                                                { (yyval.pri_expr) = new PrimaryExpr(NULL, NULL, NULL, (yyvsp[-1].expr)); }
#line 2557 "src/parser.tab.cpp"
    break;

  case 131:
#line 343 "src/parser.y"
                                                                                                { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), NULL); }
#line 2563 "src/parser.tab.cpp"
    break;

  case 132:
#line 344 "src/parser.y"
                                                                                                { (yyval.arg_expr_list) = new ArgumentExprList((yyvsp[0].ass_expr), (yyvsp[-2].arg_expr_list)); }
#line 2569 "src/parser.tab.cpp"
    break;

  case 133:
#line 346 "src/parser.y"
                                                                                                { (yyval.cast_expr) = new CastExpr((yyvsp[0].un_expr), NULL, NULL); }
#line 2575 "src/parser.tab.cpp"
    break;

  case 134:
#line 347 "src/parser.y"
                                                                                                { (yyval.cast_expr) = new CastExpr(NULL, (yyvsp[-2].type_name), (yyvsp[0].cast_expr)); }
#line 2581 "src/parser.tab.cpp"
    break;

  case 137:
#line 352 "src/parser.y"
                                                                                                { (yyval.state) = new Statement((yyvsp[0].label_state), NULL, NULL, NULL, NULL, NULL); }
#line 2587 "src/parser.tab.cpp"
    break;

  case 138:
#line 353 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, (yyvsp[0].comp_state), NULL, NULL, NULL, NULL); }
#line 2593 "src/parser.tab.cpp"
    break;

  case 139:
#line 354 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, NULL, (yyvsp[0].expr_state), NULL, NULL, NULL); }
#line 2599 "src/parser.tab.cpp"
    break;

  case 140:
#line 355 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, NULL, NULL, (yyvsp[0].select_state), NULL, NULL); }
#line 2605 "src/parser.tab.cpp"
    break;

  case 141:
#line 356 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, (yyvsp[0].it_state), NULL); }
#line 2611 "src/parser.tab.cpp"
    break;

  case 142:
#line 357 "src/parser.y"
                                                                                                { (yyval.state) = new Statement(NULL, NULL, NULL, NULL, NULL, (yyvsp[0].jump_state)); }
#line 2617 "src/parser.tab.cpp"
    break;

  case 146:
#line 363 "src/parser.y"
                                                                                                { (yyval.expr_state) = new ExprStatement((yyvsp[-1].expr)); }
#line 2623 "src/parser.tab.cpp"
    break;

  case 147:
#line 364 "src/parser.y"
                                                                                                { (yyval.expr_state) = new ExprStatement(NULL); }
#line 2629 "src/parser.tab.cpp"
    break;

  case 148:
#line 366 "src/parser.y"
                                                                                                { (yyval.select_state) = new SelectionStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, (yyvsp[-4].str), NULL, NULL); }
#line 2635 "src/parser.tab.cpp"
    break;

  case 149:
#line 367 "src/parser.y"
                                                                                                { (yyval.select_state) = new SelectionStatement((yyvsp[-4].expr), (yyvsp[-2].state), (yyvsp[0].state), (yyvsp[-6].str), (yyvsp[-1].str), NULL); }
#line 2641 "src/parser.tab.cpp"
    break;

  case 150:
#line 368 "src/parser.y"
                                                                                                { (yyval.select_state) = new SelectionStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, NULL, NULL, (yyvsp[-4].str)); }
#line 2647 "src/parser.tab.cpp"
    break;

  case 151:
#line 370 "src/parser.y"
                                                                                                { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[0].state), NULL, NULL, (yyvsp[-4].str), NULL); }
#line 2653 "src/parser.tab.cpp"
    break;

  case 152:
#line 371 "src/parser.y"
                                                                                                { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[-5].state), NULL, NULL, (yyvsp[-4].str), (yyvsp[-6].str)); }
#line 2659 "src/parser.tab.cpp"
    break;

  case 153:
#line 372 "src/parser.y"
                                                                                                { (yyval.it_state) = new IterationStatement(NULL, (yyvsp[0].state), (yyvsp[-3].expr_state), (yyvsp[-2].expr_state), (yyvsp[-5].str), NULL); }
#line 2665 "src/parser.tab.cpp"
    break;

  case 154:
#line 373 "src/parser.y"
                                                                                                { (yyval.it_state) = new IterationStatement((yyvsp[-2].expr), (yyvsp[0].state), (yyvsp[-4].expr_state), (yyvsp[-3].expr_state), (yyvsp[-6].str), NULL); }
#line 2671 "src/parser.tab.cpp"
    break;

  case 155:
#line 375 "src/parser.y"
                                                                                                { (yyval.jump_state) = new JumpStatement((yyvsp[-1].str), NULL); }
#line 2677 "src/parser.tab.cpp"
    break;

  case 156:
#line 376 "src/parser.y"
                                                                                                { (yyval.jump_state) = new JumpStatement((yyvsp[-1].str), NULL); }
#line 2683 "src/parser.tab.cpp"
    break;

  case 157:
#line 377 "src/parser.y"
                                                                                                         { (yyval.jump_state) = new JumpStatement((yyvsp[-2].str), (yyvsp[-1].expr)); }
#line 2689 "src/parser.tab.cpp"
    break;

  case 158:
#line 379 "src/parser.y"
                                                                                                { (yyval.store_spec) = new StorageClassSpecifier((yyvsp[0].str)); }
#line 2695 "src/parser.tab.cpp"
    break;

  case 159:
#line 380 "src/parser.y"
                                                                                                { (yyval.store_spec) = new StorageClassSpecifier((yyvsp[0].str)); }
#line 2701 "src/parser.tab.cpp"
    break;

  case 160:
#line 381 "src/parser.y"
                                                                                                { (yyval.store_spec) = new StorageClassSpecifier((yyvsp[0].str)); }
#line 2707 "src/parser.tab.cpp"
    break;

  case 161:
#line 382 "src/parser.y"
                                                                                                { (yyval.store_spec) = new StorageClassSpecifier((yyvsp[0].str)); }
#line 2713 "src/parser.tab.cpp"
    break;

  case 162:
#line 384 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2719 "src/parser.tab.cpp"
    break;

  case 163:
#line 385 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2725 "src/parser.tab.cpp"
    break;

  case 164:
#line 386 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2731 "src/parser.tab.cpp"
    break;

  case 165:
#line 387 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2737 "src/parser.tab.cpp"
    break;

  case 166:
#line 388 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2743 "src/parser.tab.cpp"
    break;

  case 167:
#line 389 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2749 "src/parser.tab.cpp"
    break;

  case 168:
#line 390 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2755 "src/parser.tab.cpp"
    break;

  case 169:
#line 391 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2761 "src/parser.tab.cpp"
    break;

  case 170:
#line 392 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier((yyvsp[0].str), NULL, NULL); }
#line 2767 "src/parser.tab.cpp"
    break;

  case 171:
#line 393 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier(NULL, (yyvsp[0].struct_spec), NULL); }
#line 2773 "src/parser.tab.cpp"
    break;

  case 172:
#line 394 "src/parser.y"
                                                                                                { (yyval.type_spec) = new TypeSpecifier(NULL, NULL, (yyvsp[0].enum_spec)); }
#line 2779 "src/parser.tab.cpp"
    break;

  case 179:
#line 405 "src/parser.y"
                                                                                                { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[-1].type_spec), (yyvsp[0].spec_qual_list)); }
#line 2785 "src/parser.tab.cpp"
    break;

  case 180:
#line 406 "src/parser.y"
                                                                                                { (yyval.spec_qual_list) = new SpecifierQualifierList((yyvsp[0].type_spec), NULL); }
#line 2791 "src/parser.tab.cpp"
    break;


#line 2795 "src/parser.tab.cpp"

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
#line 425 "src/parser.y"


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
