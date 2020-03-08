%code requires{
    #include "../include/ast.hpp"

    #include <cassert>
    #include <fstream>

    extern FILE *yyinput;
    extern const TranslationUnit *g_root; // A way of getting the AST out

    // ! This is to fix problems when generating C++
    // We are declaring the functions provided by Flex, so
    // that Bison generated code can call them.
    int yylex(void);
    void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
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
    TypeQualifierList *type_qual_list;
    ParameterTypeList *param_type_list;
    ParameterList *param_list;
    ParameterDeclaration *param_decl;
    IdentifierList *iden_list;
    ConstantExpr *const_expr;
    TypeQualifier *type_qual;
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
    StructUnionSpecifier *struct_union_spec;
    StructUnion *struct_union;
    StructDeclarationList *struct_decl_list;
    StructDeclaration *struct_decl;
    SpecifierQualifierList *spec_qual_list;
    StructDeclaratorList *struct_declr_list;
    StructDeclarator *struct_declr;
    EnumSpecifier *enum_spec;
    EnumeratorList *enum_list;
    Enumerator *enum;
    TypedefName *type_name;
}

%token CONSTANT STRING_LITERAL IDENTIFIER SIZEOF SEMICOLON
%token INCREMENT DECREMENT LSHIFT RSHIFT LE GE EQUALITY NOTEQUAL ARROW DOT
%token LOGICAL_OR LOGICAL_AND PLUSEQUAL MULEQUAL DIVEQUAL MODEQUAL
%token MINUSEQUAL ANDEQUAL LSHIFTEQUAL RSHIFTEQUAL
%token EQUAL PLUS MINUS ASTERISK DIV MOD TILDE LT GT OREQUAL XOREQUAL
%token BITWISE_OR BITWISE_AND EXCLAMATION QUESTION XOR
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED CONST VOLATILE
%token STRUCT UNION ENUM ELLIPSIS
%token IF ELSE SWITCH CASE DEFAULT FOR DO WHILE GOTO CONTINUE BREAK RETURN TYPE_NAME
%token LB RB LSB RSB LCB RCB COLON COMMA

%type <string> CONSTANT STRING_LITERAL IDENTIFIER SIZEOF SEMICOLON
%type <string> INCREMENT DECREMENT LSHIFT RSHIFT LE GE EQUALITY NOTEQUAL ARROW DOT
%type <string> LOGICAL_OR LOGICAL_AND PLUSEQUAL MULEQUAL DIVEQUAL MODEQUAL
%type <string> MINUSEQUAL ANDEQUAL LSHIFTEQUAL RSHIFTEQUAL
%type <string> EQUAL PLUS MINUS ASTERISK DIV MOD TILDE LT GT OREQUAL XOREQUAL
%type <string> BITWISE_OR BITWISE_AND EXCLAMATION QUESTION XOR
%type <string> TYPEDEF EXTERN STATIC AUTO REGISTER
%type <string> VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED CONST VOLATILE
%type <string> STRUCT UNION ENUM ELLIPSIS
%type <string> IF ELSE SWITCH CASE DEFAULT FOR DO WHILE GOTO CONTINUE BREAK RETURN TYPE_NAME
%type <string> LB RB LSB RSB LCB RCB COLON COMMA

%type <trans_unit> TRANSLATION_UNIT
%type <ext_decl> EXTERNAL_DECLARATION
%type <func_def> FUNCTION_DEFINITION
%type <decl> DECLARATION
%type <decl_spec> DECLARATION_SPECIFIER
%type <decl_list> DECLARATION_LIST
%type <comp_state> COMPOUND_STATEMENT
%type <state_list> STATEMENT_LIST
%type <init_declr_list> INIT_DECLARATOR_LIST
%type <init_declr> INIT_DECLARATOR
%type <init> INITIALIZER
%type <init_list> INITIALIZER_LIST
%type <declr> DECLARATOR
%type <dir_declr> DIRECT_DECLARATOR
%type <ptr> POINTER
%type <type_qual_list> TYPE_QUALIFIER_LIST
%type <param_type_list> PARAMETER_TYPE_LIST
%type <param_list> PARAMETER_LIST
%type <param_decl> PARAMETER_DECLARATION
%type <iden_list> IDENTIFIER_LIST
%type <const_expr> CONSTANT_EXPR
%type <type_qual> TYPE_QUALIFIER
%type <abs_declr> ABSTRACT_DECLARATOR
%type <dir_abs_declr> DIRECT_ABSTRACT_DECLARATOR
%type <cond_expr> CONDITIONAL_EXPR
%type <log_or_expr> LOGICAL_OR_EXPR
%type <log_and_expr> LOGICAL_AND_EXPR
%type <incl_or_expr> INCLUSIVE_OR_EXPR
%type <excl_or_expr> EXCLUSIVE_OR_EXPRESSION
%type <and_expr> AND_EXPR
%type <equal_expr> EQUALITY_EXPR
%type <rel_expr> RELATIONAL_EXPR
%type <shift_expr> SHIFT_EXPR
%type <add_expr> ADDITIVE_EXPR
%type <mul_expr> MULTIPLICATIVE_EXPR
%type <expr> EXPR
%type <ass_expr> ASSIGNMENT_EXPR
%type <ass_op> ASSIGNMENT_OPERATOR
%type <un_expr> UNARY_EXPR
%type <un_op> UNARY_OPERATOR
%type <post_expr> POSTFIX_EXPR
%type <pri_expr> PRIMARY_EXPR
%type <arg_expr_list> ARGUMENT_EXPR_LIST
%type <cast_expr> CAST_EXPR
%type <type_name> TYPE_NAME
%type <state> STATEMENT
%type <label_state> LABELED_STATEMENT
%type <expr_state> EXPR_STATEMENT
%type <select_state> SELECTION_STATEMENT
%type <it_state> ITERATION_STATEMENT
%type <jump_state> JUMP_STATEMENT
%type <store_spec> STORAGE_CLASS_SPECIFIER
%type <type_spec> TYPE_SPECIFIER
%type <struct_union_spec> STRUCT_UNION_SPECIFIER
%type <struct_union> STRUCT_UNION
%type <struct_decl_list> STRUCT_DECLARATION_LIST
%type <struct_decl> STRUCT_DECLARATION
%type <spec_qual_list> SPECIFIER_QUALIFIER_LIST
%type <struct_declr_list> STRUCT_DECLARATOR_LIST
%type <struct_declr> STRUCT_DECLARATOR
%type <enum_spec> ENUM_SPECIFIER
%type <enum_list> ENUMERATOR_LIST
%type <enum> ENUMERATOR
%type <type_name> TYPEDEF_NAME

%start ROOT

%%

ROOT: TRANSLATION_UNIT { g_root = $1; }

TRANSLATION_UNIT: EXTERNAL_DECLARATION
                | TRANSLATION_UNIT EXTERNAL_DECLARATION

EXTERNAL_DECLARATION: FUNCTION_DEFINITION
                    | DECLARATION

FUNCTION_DEFINITION: DECLARATION_SPECIFIER DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT
                |    DECLARATION_SPECIFIER DECLARATOR COMPOUND_STATEMENT
                |    DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT
                |    DECLARATOR COMPOUND_STATEMENT

DECLARATION: DECLARATION_SPECIFIER INIT_DECLARATOR_LIST
        |    DECLARATION_SPECIFIER

DECLARATION_SPECIFIER: STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIER
                    |  STORAGE_CLASS_SPECIFIER
                    |  TYPE_SPECIFIER DECLARATION_SPECIFIER
                    |  TYPE_SPECIFIER
                    |  TYPE_QUALIFIER DECLARATION_SPECIFIER
                    |  TYPE_QUALIFIER

DECLARATION_LIST: DECLARATION
                | DECLARATION_LIST DECLARATION

COMPOUND_STATEMENT: LCB DECLARATION_LIST STATEMENT_LIST RCB
                |   LCB DECLARATION_LIST RCB
                |   LCB STATEMENT_LIST RCB
                |   LCB RCB

STATEMENT_LIST: STATEMENT
            |   STATEMENT_LIST STATEMENT

INIT_DECLARATOR_LIST: INIT_DECLARATOR
                    | INIT_DECLARATOR_LIST COMMA INIT_DECLARATOR

INIT_DECLARATOR: DECLARATOR
            |    DECLARATOR EQUAL INITIALIZER

INITIALIZER: ASSIGNMENT_EXPR
        |    LCB INITIALIZER_LIST RCB
        |    LCB INITIALIZER_LIST COMMA RCB

INITIALIZER_LIST: INITIALIZER
                | INITIALIZER_LIST COMMA INITIALIZER

DECLARATOR: POINTER DIRECT_DECLARATOR
        |   DIRECT_DECLARATOR

DIRECT_DECLARATOR: IDENTIFIER
                |  LB DECLARATOR RB
                |  DIRECT_DECLARATOR LSB CONSTANT_EXPR RSB
                |  DIRECT_DECLARATOR LSB RSB
                |  DIRECT_DECLARATOR LB PARAMETER_TYPE_LIST RB
                |  DIRECT_DECLARATOR LB IDENTIFIER_LIST RB
                |  DIRECT_DECLARATOR LB RB

POINTER: ASTERISK TYPE_QUALIFIER_LIST POINTER
    |    ASTERISK TYPE_QUALIFIER_LIST
    |    ASTERISK POINTER
    |    ASTERISK

TYPE_QUALIFIER_LIST: TYPE_QUALIFIER
                |    TYPE_QUALIFIER_LIST TYPE_QUALIFIER

PARAMETER_TYPE_LIST: PARAMETER_LIST
                |    PARAMETER_LIST COMMA ELLIPSIS

PARAMETER_LIST: PARAMETER_DECLARATION
            |   PARAMETER_LIST COMMA PARAMETER_DECLARATION

PARAMETER_DECLARATION: DECLARATION_SPECIFIER DECLARATOR
                    |  DECLARATION_SPECIFIER ABSTRACT_DECLARATOR
                    |  DECLARATION_SPECIFIER

IDENTIFIER_LIST: IDENTIFIER
            |    IDENTIFIER_LIST COMMA IDENTIFIER

CONSTANT_EXPR: CONDITIONAL_EXPR

TYPE_QUALIFIER: CONST
            |   VOLATILE

ABSTRACT_DECLARATOR: POINTER
                |    POINTER DIRECT_ABSTRACT_DECLARATOR
                |    DIRECT_ABSTRACT_DECLARATOR

DIRECT_ABSTRACT_DECLARATOR: LB ABSTRACT_DECLARATOR RB
                        |   DIRECT_ABSTRACT_DECLARATOR LSB CONSTANT_EXPR RSB
                        |   DIRECT_ABSTRACT_DECLARATOR LSB RSB
                        |   LSB CONSTANT_EXPR RSB
                        |   LSB RSB
                        |   DIRECT_ABSTRACT_DECLARATOR LB PARAMETER_TYPE_LIST RB
                        |   DIRECT_ABSTRACT_DECLARATOR LB RB
                        |   LB PARAMETER_TYPE_LIST RB
                        |   LB RB

CONDITIONAL_EXPR: LOGICAL_OR_EXPR
                | LOGICAL_OR_EXPR QUESTION EXPR COLON CONDITIONAL_EXPR

LOGICAL_OR_EXPR: LOGICAL_AND_EXPR
            |    LOGICAL_OR_EXPR LOGICAL_OR LOGICAL_AND_EXPR

LOGICAL_AND_EXPR: INCLUSIVE_OR_EXPR
                | LOGICAL_AND_EXPR LOGICAL_AND INCLUSIVE_OR_EXPR

INCLUSIVE_OR_EXPR: EXCLUSIVE_OR_EXPRESSION
                |  INCLUSIVE_OR_EXPR BITWISE_OR EXCLUSIVE_OR_EXPRESSION

EXCLUSIVE_OR_EXPRESSION: AND_EXPR
                    |    EXCLUSIVE_OR_EXPRESSION XOR AND_EXPR

AND_EXPR: EQUALITY_EXPR
        | AND_EXPR BITWISE_AND EQUALITY_EXPR

EQUALITY_EXPR: RELATIONAL_EXPR
            |  EQUALITY_EXPR EQUALITY RELATIONAL_EXPR
            |  EQUALITY_EXPR NOTEQUAL RELATIONAL_EXPR

RELATIONAL_EXPR: SHIFT_EXPR
            |    RELATIONAL_EXPR LT SHIFT_EXPR
            |    RELATIONAL_EXPR GT SHIFT_EXPR
            |    RELATIONAL_EXPR LE SHIFT_EXPR
            |    RELATIONAL_EXPR GE SHIFT_EXPR

SHIFT_EXPR: ADDITIVE_EXPR
        |   SHIFT_EXPR LSHIFT ADDITIVE_EXPR
        |   SHIFT_EXPR RSHIFT ADDITIVE_EXPR

ADDITIVE_EXPR: MULTIPLICATIVE_EXPR
            |  ADDITIVE_EXPR PLUS MULTIPLICATIVE_EXPR
            |  ADDITIVE_EXPR MINUS MULTIPLICATIVE_EXPR

MULTIPLICATIVE_EXPR: CAST_EXPR
                |    MULTIPLICATIVE_EXPR ASTERISK CAST_EXPR
                |    MULTIPLICATIVE_EXPR DIV CAST_EXPR
                |    MULTIPLICATIVE_EXPR MOD CAST_EXPR

EXPR: ASSIGNMENT_EXPR
    | EXPR COMMA ASSIGNMENT_EXPR

ASSIGNMENT_EXPR: CONDITIONAL_EXPR
            |    UNARY_EXPR ASSIGNMENT_OPERATOR ASSIGNMENT_EXPR

ASSIGNMENT_OPERATOR: EQUAL
                |    MULEQUAL
                |    DIVEQUAL
                |    MODEQUAL
                |    PLUSEQUAL
                |    MINUSEQUAL
                |    LSHIFTEQUAL
                |    RSHIFTEQUAL
                |    ANDEQUAL
                |    XOREQUAL
                |    OREQUAL

UNARY_EXPR: POSTFIX_EXPR
        |   INCREMENT UNARY_EXPR
        |   DECREMENT UNARY_EXPR
        |   UNARY_OPERATOR CAST_EXPR
        |   SIZEOF UNARY_EXPR
        |   SIZEOF LB TYPE_NAME RB

UNARY_OPERATOR: AMPERSAND
            |   ASTERISK
            |   PLUS
            |   MINUS
            |   TILDE
            |   EXCLAMATION

POSTFIX_EXPR: PRIMARY_EXPR
            | PRIMARY_EXPR LSB EXPR RSB
            | POSTFIX_EXPR LB ARGUMENT_EXPR_LIST RB
            | POSTFIX_EXPR LB RB
            | POSTFIX_EXPR DOT IDENTIFIER
            | POSTFIX_EXPR ARROW IDENTIFIER
            | POSTFIX_EXPR INCREMENT
            | POSTFIX_EXPR DECREMENT

PRIMARY_EXPR: IDENTIFIER
            | CONSTANT
            | STRING_LITERAL
            | LB EXPR RB

ARGUMENT_EXPR_LIST: ASSIGNMENT_EXPR
                |   ARGUMENT_EXPR_LIST COMMA ASSIGNMENT_EXPR

CAST_EXPR: UNARY_EXPR
        |  LB TYPE_NAME RB CAST_EXPR

TYPE_NAME: SPECIFIER_QUALIFIER_LIST ABSTRACT_DECLARATOR
        |  SPECIFIER_QUALIFIER_LIST

STATEMENT: LABELED_STATEMENT
        |  COMPOUND_STATEMENT
        |  EXPR_STATEMENT
        |  SELECTION_STATEMENT
        |  ITERATION_STATEMENT
        |  JUMP_STATEMENT

LABELED_STATEMENT: IDENTIFIER COLON STATEMENT
                |  CASE CONSTANT_EXPR COLON STATEMENT
                |  DEFAULT COLON STATEMENT

EXPR_STATEMENT: EXPR SEMICOLON
            |   SEMICOLON

SELECTION_STATEMENT: IF LB EXPR RB STATEMENT
                |    IF LB EXPR RB STATEMENT ELSE STATEMENT
                |    SWITCH LB EXPR RB STATEMENT

ITERATION_STATEMENT: WHILE LB EXPR RB STATEMENT
                |    DO STATEMENT WHILE LB EXPR RB SEMICOLON
                |    FOR LB EXPR_STATEMENT EXPR_STATEMENT RB STATEMENT
                |    FOR LB EXPR_STATEMENT EXPR_STATEMENT EXPRESSION RB STATEMENT

JUMP_STATEMENT: GOTO IDENTIFIER SEMICOLON
            |   CONTINUE SEMICOLON
            |   BREAK SEMICOLON
            |   RETURN EXPR_STATEMENT

STORAGE_CLASS_SPECIFIER: TYPEDEF
                    |    EXTERN
                    |    STATIC
                    |    AUTO
                    |    REGISTER

TYPE_SPECIFIER: VOID
            |   CHAR
            |   SHORT
            |   INT
            |   LONG
            |   FLOAT
            |   DOUBLE
            |   SIGNED
            |   UNSIGNED
            |   STRUCT_UNION_SPECIFIER
            |   ENUM_SPECIFIER
            |   TYPEDEF_NAME

STRUCT_UNION_SPECIFIER: STRUCT_UNION IDENTIFIER LCB STRUCT_DECLARATION_LIST RCB
                    |   STRUCT_UNION LCB STRUCT_DECLARATION_LIST RCB
                    |   STRUCT_UNION IDENTIFIER

STRUCT_UNION: STRUCT
            | UNION

STRUCT_DECLARATION_LIST: STRUCT_DECLARATION
                    |    STRUCT_DECLARATION_LIST STRUCT_DECLARATION

STRUCT_DECLARATION: SPECIFIER_QUALIFIER_LIST STRUCT_DECLARATOR_LIST SEMICOLON

SPECIFIER_QUALIFIER_LIST: TYPE_SPECIFIER SPECIFIER_QUALIFIER_LIST
                        | TYPE_SPECIFIER
                        | TYPE_QUALIFIER SPECIFIER_QUALIFIER_LIST
                        | TYPE_QUALIFIER

STRUCT_DECLARATOR_LIST: STRUCT_DECLARATOR
                    |   STRUCT_DECLARATOR COMMA STRUCT_DECLARATOR

STRUCT_DECLARATOR: DECLARATOR
                |  DECLARATOR COLON CONSTANT_EXPR
                |  COLON CONSTANT_EXPR

ENUM_SPECIFIER: ENUM IDENTIFIER LCB ENUMERATOR_LIST RCB
                | ENUM LCB ENUMERATOR_LIST RCB
                | ENUM IDENTIFIER

ENUMERATOR_LIST: ENUMERATOR
        |  ENUMERATOR_LIST COMMA ENUMERATOR

ENUMERATOR: ENUM_CONSTANT
        |   ENUM_CONSTANT EQUAL CONSTANT_EXPR

TYPEDEF_NAME: IDENTIFIER

IDENTIFIER: NONDIGIT
        |   IDENTIFIER NONDIGIT
        |   IDENTIFIER DIGIT

CONSTANT: FLOATING_CONSTANT
        | INT_CONSTANT
        | ENUM_CONSTANT
        | CHAR_CONSTANT

FLOATING_CONSTANT: FRACTIONAL_CONSTANT EXPONENT FLOATING_SUFFIX
                |  FRACTIONAL_CONSTANT EXPONENT
                |  FRACTIONAL_CONSTANT FLOATING_SUFFIX
                |  FRACTIONAL_CONSTANT
                |  DIGIT_SEQUENCE EXPONENT FLOATING_SUFFIX
                |  DIGIT_SEQUENCE EXPONENT

FRACTIONAL_CONSTANT: DIGIT_SEQUENCE DOT DIGIT_SEQUENCE
                |    DIGIT_SEQUENCE DOT

EXPONENT: E SIGN DIGIT_SEQUENCE
        | E DIGIT_SEQUENCE

DIGIT_SEQUENCE: DIGIT
            |   DIGIT_SEQUENCE DIGIT

INT_CONSTANT: DECIMAL_CONSTANT INT_SUFFIX
            | DECIMAL_CONSTANT
            | OCT_CONSTANT INT_SUFFIX
            | OCT_CONSTANT
            | HEX_CONSTANT INT_SUFFIX
            | HEX_CONSTANT

DECIMAL_CONSTANT: NONZERO_DIGIT
                | DECIMAL_CONSTANT DIGIT

OCT_CONSTANT: ZERO
            | OCT_CONSTANT OCT_DIGIT

%%

const TranslationUnit *g_root; // Definition of variable (to match declaration earlier)

const TranslationUnit *parseAST(char* a, char* b){
    g_root=0;
    yyinput = fopen(x, "r");

    if(yyinput){
        yyparse();
    }

    fclose(yyinput);
    return g_root;
}
