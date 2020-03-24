%code requires{
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
}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF SEMICOLON
%token INCREMENT DECREMENT LSHIFT RSHIFT LE GE EQUALITY NOTEQUAL ARROW DOT
%token LOGICAL_OR LOGICAL_AND PLUSEQUAL MULEQUAL DIVEQUAL MODEQUAL
%token MINUSEQUAL ANDEQUAL LSHIFTEQUAL RSHIFTEQUAL
%token EQUAL PLUS MINUS ASTERISK DIV MOD TILDE LT GT OREQUAL XOREQUAL
%token BITWISE_OR AMPERSAND EXCLAMATION QUESTION XOR
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED CONST VOLATILE
%token STRUCT ENUM ELLIPSIS
%token IF ELSE SWITCH CASE DEFAULT FOR DO WHILE CONTINUE BREAK RETURN
%token LB RB LSB RSB LCB RCB COLON COMMA

%type <string> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF SEMICOLON
%type <string> INCREMENT DECREMENT LSHIFT RSHIFT LE GE EQUALITY NOTEQUAL ARROW DOT
%type <string> LOGICAL_OR LOGICAL_AND PLUSEQUAL MULEQUAL DIVEQUAL MODEQUAL
%type <string> MINUSEQUAL ANDEQUAL LSHIFTEQUAL RSHIFTEQUAL
%type <string> EQUAL PLUS MINUS ASTERISK DIV MOD TILDE LT GT OREQUAL XOREQUAL
%type <string> BITWISE_OR AMPERSAND EXCLAMATION QUESTION XOR
%type <string> TYPEDEF EXTERN STATIC AUTO REGISTER
%type <string> VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED CONST VOLATILE
%type <string> STRUCT ENUM ELLIPSIS
%type <string> IF ELSE SWITCH CASE DEFAULT FOR DO WHILE CONTINUE BREAK RETURN
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
%type <param_type_list> PARAMETER_TYPE_LIST
%type <param_list> PARAMETER_LIST
%type <param_decl> PARAMETER_DECLARATION
%type <iden_list> IDENTIFIER_LIST
%type <const_expr> CONSTANT_EXPR
%type <abs_declr> ABSTRACT_DECLARATOR
%type <dir_abs_declr> DIRECT_ABSTRACT_DECLARATOR
%type <cond_expr> CONDITIONAL_EXPR
%type <log_or_expr> LOGICAL_OR_EXPR
%type <log_and_expr> LOGICAL_AND_EXPR
%type <incl_or_expr> INCLUSIVE_OR_EXPR
%type <excl_or_expr> EXCLUSIVE_OR_EXPR
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
%type <struct_spec> STRUCT_SPECIFIER
%type <struct_decl_list> STRUCT_DECLARATION_LIST
%type <struct_decl> STRUCT_DECLARATION
%type <spec_qual_list> SPECIFIER_QUALIFIER_LIST
%type <struct_declr_list> STRUCT_DECLARATOR_LIST
%type <struct_declr> STRUCT_DECLARATOR
%type <enum_spec> ENUM_SPECIFIER
%type <enum_list> ENUMERATOR_LIST
%type <enum> ENUMERATOR

%start ROOT

%%

ROOT: TRANSLATION_UNIT { g_root = $1; }

TRANSLATION_UNIT: TRANSLATION_UNIT EXTERNAL_DECLARATION                                         { $$ = new TranslationUnit($2, $1); }
                | EXTERNAL_DECLARATION                                                          { $$ = new TranslationUnit($1, NULL); }

EXTERNAL_DECLARATION: FUNCTION_DEFINITION                                                       { $$ = new ExternalDeclaration($1, NULL); }
                    | DECLARATION                                                               { $$ = new ExternalDeclaration(NULL, $1); }

FUNCTION_DEFINITION: DECLARATION_SPECIFIER DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT       { $$ = new FunctionDefinition($1, $2, $3, $4); }
                |    DECLARATION_SPECIFIER DECLARATOR COMPOUND_STATEMENT                        { $$ = new FunctionDefinition($1, $2, NULL, $3); }
                |    DECLARATOR DECLARATION_LIST COMPOUND_STATEMENT                             { $$ = new FunctionDefinition(NULL, $1, $2, $3); }
                |    DECLARATOR COMPOUND_STATEMENT                                              { $$ = new FunctionDefinition(NULL, $1, NULL, $2); }

DECLARATION: DECLARATION_SPECIFIER INIT_DECLARATOR_LIST SEMICOLON                               { $$ = new Declaration($1, $2); }
        |    DECLARATION_SPECIFIER SEMICOLON                                                    { $$ = new Declaration($1, NULL); }

DECLARATION_SPECIFIER: STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIER                            { $$ = new DeclarationSpecifier($1, NULL, $2); }
                    |  STORAGE_CLASS_SPECIFIER                                                  { $$ = new DeclarationSpecifier($1, NULL, NULL); }
                    |  TYPE_SPECIFIER DECLARATION_SPECIFIER                                     { $$ = new DeclarationSpecifier(NULL, $1, $2); }
                    |  TYPE_SPECIFIER                                                           { $$ = new DeclarationSpecifier(NULL, $1, NULL); }

DECLARATION_LIST: DECLARATION                                                                   { $$ = new DeclarationList(NULL, $1); }
                | DECLARATION_LIST DECLARATION                                                  { $$ = new DeclarationList($1, $2); }

COMPOUND_STATEMENT: LCB DECLARATION_LIST STATEMENT_LIST RCB                                     { $$ = new CompoundStatement($2, $3); }
                |   LCB DECLARATION_LIST RCB                                                    { $$ = new CompoundStatement($2, NULL); }
                |   LCB STATEMENT_LIST RCB                                                      { $$ = new CompoundStatement(NULL, $2); }
                |   LCB RCB                                                                     { $$ = new CompoundStatement(NULL, NULL); }

STATEMENT_LIST: STATEMENT                                                                       { $$ = new StatementList($1, NULL); }
            |   STATEMENT_LIST STATEMENT                                                        { $$ = new StatementList($2, $1); }

INIT_DECLARATOR_LIST: INIT_DECLARATOR                                                           { $$ = new InitDeclaratorList(NULL, $1); }
                    | INIT_DECLARATOR_LIST COMMA INIT_DECLARATOR                                { $$ = new InitDeclaratorList($1, $3); }

INIT_DECLARATOR: DECLARATOR                                                                     { $$ = new InitDeclarator($1, NULL); }
            |    DECLARATOR EQUAL INITIALIZER                                                   { $$ = new InitDeclarator($1, $3); }

INITIALIZER: ASSIGNMENT_EXPR                                                                    { $$ = new Initializer($1, NULL); }
        |    LCB INITIALIZER_LIST RCB                                                           { $$ = new Initializer(NULL, $2); }
        |    LCB INITIALIZER_LIST COMMA RCB                                                     { $$ = new Initializer(NULL, $2); }

INITIALIZER_LIST: INITIALIZER                                                                   { $$ = new InitializerList($1, NULL); }
                | INITIALIZER_LIST COMMA INITIALIZER                                            { $$ = new InitializerList($3, $1); }

DECLARATOR: POINTER DIRECT_DECLARATOR                                                           { $$ = new Declarator($1, $2); }
        |   DIRECT_DECLARATOR                                                                   { $$ = new Declarator(NULL, $1); }

DIRECT_DECLARATOR: IDENTIFIER                                                                   { $$ = new DirectDeclarator(NULL, NULL, NULL, NULL, NULL, $1, NULL); }
                |  LB DECLARATOR RB                                                             { $$ = new DirectDeclarator($2, NULL, NULL, NULL, NULL, NULL, NULL); }
                |  DIRECT_DECLARATOR LSB CONSTANT_EXPR RSB                                      { $$ = new DirectDeclarator(NULL, $1, $3, NULL, NULL, NULL, NULL); }
                |  DIRECT_DECLARATOR LSB RSB                                                    { $$ = new DirectDeclarator(NULL, $1, NULL, NULL, NULL, NULL, $2); }
                |  DIRECT_DECLARATOR LB PARAMETER_TYPE_LIST RB                                  { $$ = new DirectDeclarator(NULL, $1, NULL, $3, NULL, NULL, NULL); }
                |  DIRECT_DECLARATOR LB IDENTIFIER_LIST RB                                      { $$ = new DirectDeclarator(NULL, $1, NULL, NULL, $3, NULL, NULL); }
                |  DIRECT_DECLARATOR LB RB                                                      { $$ = new DirectDeclarator(NULL, $1, NULL, NULL, NULL, NULL, NULL); }

POINTER: ASTERISK POINTER                                                                       
    |    ASTERISK                                                                               

PARAMETER_TYPE_LIST: PARAMETER_LIST                                                             { $$ = new ParameterTypeList($1, NULL); }
                |    PARAMETER_LIST COMMA ELLIPSIS                                              { $$ = new ParameterTypeList($1, $3); }

PARAMETER_LIST: PARAMETER_DECLARATION                                                           { $$ = new ParameterList($1, NULL); }
            |   PARAMETER_LIST COMMA PARAMETER_DECLARATION                                      { $$ = new ParameterList($3, $1); }

PARAMETER_DECLARATION: DECLARATION_SPECIFIER DECLARATOR                                         { $$ = new ParameterDeclaration($1, $2, NULL); }
                    |  DECLARATION_SPECIFIER ABSTRACT_DECLARATOR                                { $$ = new ParameterDeclaration($1, NULL, $2); }
                    |  DECLARATION_SPECIFIER                                                    { $$ = new ParameterDeclaration($1, NULL, NULL); }

IDENTIFIER_LIST: IDENTIFIER                                                                     { $$ = new IdentifierList(NULL, $1); }
            |    IDENTIFIER_LIST COMMA IDENTIFIER                                               { $$ = new IdentifierList($1, $3); }

CONSTANT_EXPR: CONDITIONAL_EXPR                                                                 { $$ = new ConstantExpr($1); }


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

CONDITIONAL_EXPR: LOGICAL_OR_EXPR                                                               { $$ = new ConditionalExpr($1, NULL, NULL); }
                | LOGICAL_OR_EXPR QUESTION EXPR COLON CONDITIONAL_EXPR                          { $$ = new ConditionalExpr($1, $3, $5); }

LOGICAL_OR_EXPR: LOGICAL_AND_EXPR                                                               { $$ = new LogicalOrExpr($1, NULL); }
            |    LOGICAL_OR_EXPR LOGICAL_OR LOGICAL_AND_EXPR                                    { $$ = new LogicalOrExpr($3, $1); }

LOGICAL_AND_EXPR: INCLUSIVE_OR_EXPR                                                             { $$ = new LogicalAndExpr($1, NULL); }
                | LOGICAL_AND_EXPR LOGICAL_AND INCLUSIVE_OR_EXPR                                { $$ = new LogicalAndExpr($3, $1); }

INCLUSIVE_OR_EXPR: EXCLUSIVE_OR_EXPR                                                            { $$ = new InclusiveOrExpr($1, NULL); }
                |  INCLUSIVE_OR_EXPR BITWISE_OR EXCLUSIVE_OR_EXPR                               { $$ = new InclusiveOrExpr($3, $1); }

EXCLUSIVE_OR_EXPR: AND_EXPR                                                                     { $$ = new ExclusiveOrExpr($1, NULL); }
                |  EXCLUSIVE_OR_EXPR XOR AND_EXPR                                               { $$ = new ExclusiveOrExpr($3, $1); }

AND_EXPR: EQUALITY_EXPR                                                                         { $$ = new AndExpr($1, NULL); }
        | AND_EXPR AMPERSAND EQUALITY_EXPR                                                      { $$ = new AndExpr($3, $1); }

EQUALITY_EXPR: RELATIONAL_EXPR                                                                  { $$ = new EqualityExpr($1, NULL, NULL); }
            |  EQUALITY_EXPR EQUALITY RELATIONAL_EXPR                                           { $$ = new EqualityExpr($3, $1, $2); }
            |  EQUALITY_EXPR NOTEQUAL RELATIONAL_EXPR                                           { $$ = new EqualityExpr($3, $1, $2); }

RELATIONAL_EXPR: SHIFT_EXPR                                                                     { $$ = new RelationalExpr($1, NULL, NULL); }
            |    RELATIONAL_EXPR LT SHIFT_EXPR                                                  { $$ = new RelationalExpr($3, $1, $2); }
            |    RELATIONAL_EXPR GT SHIFT_EXPR                                                  { $$ = new RelationalExpr($3, $1, $2); }
            |    RELATIONAL_EXPR LE SHIFT_EXPR                                                  { $$ = new RelationalExpr($3, $1, $2); }
            |    RELATIONAL_EXPR GE SHIFT_EXPR                                                  { $$ = new RelationalExpr($3, $1, $2); }

SHIFT_EXPR: ADDITIVE_EXPR                                                                       { $$ = new ShiftExpr($1, NULL, NULL); }
        |   SHIFT_EXPR LSHIFT ADDITIVE_EXPR                                                     { $$ = new ShiftExpr($3, $1, $2); }
        |   SHIFT_EXPR RSHIFT ADDITIVE_EXPR                                                     { $$ = new ShiftExpr($3, $1, $2); }

ADDITIVE_EXPR: MULTIPLICATIVE_EXPR                                                              { $$ = new AdditiveExpr($1, NULL, NULL); }
            |  ADDITIVE_EXPR PLUS MULTIPLICATIVE_EXPR                                           { $$ = new AdditiveExpr($3, $1, $2); }
            |  ADDITIVE_EXPR MINUS MULTIPLICATIVE_EXPR                                          { $$ = new AdditiveExpr($3, $1, $2); }

MULTIPLICATIVE_EXPR: CAST_EXPR                                                                  { $$ = new MultiplicativeExpr($1, NULL, NULL); }
                |    MULTIPLICATIVE_EXPR ASTERISK CAST_EXPR                                     { $$ = new MultiplicativeExpr($3, $1, $2); }
                |    MULTIPLICATIVE_EXPR DIV CAST_EXPR                                          { $$ = new MultiplicativeExpr($3, $1, $2); }
                |    MULTIPLICATIVE_EXPR MOD CAST_EXPR                                          { $$ = new MultiplicativeExpr($3, $1, $2); }

EXPR: ASSIGNMENT_EXPR                                                                           { $$ = new Expr($1, NULL); }
    | EXPR COMMA ASSIGNMENT_EXPR                                                                { $$ = new Expr($3, $1); }

ASSIGNMENT_EXPR: CONDITIONAL_EXPR                                                               { $$ = new AssignmentExpr($1, NULL, NULL, NULL); }
            |    UNARY_EXPR ASSIGNMENT_OPERATOR ASSIGNMENT_EXPR                                 { $$ = new AssignmentExpr(NULL, $1, $2, $3); }

ASSIGNMENT_OPERATOR: EQUAL                                                                      { $$ = new AssignmentOperator($1); }
                |    MULEQUAL                                                                   { $$ = new AssignmentOperator($1); }
                |    DIVEQUAL                                                                   { $$ = new AssignmentOperator($1); }
                |    MODEQUAL                                                                   { $$ = new AssignmentOperator($1); }
                |    PLUSEQUAL                                                                  { $$ = new AssignmentOperator($1); }
                |    MINUSEQUAL                                                                 { $$ = new AssignmentOperator($1); }
                |    LSHIFTEQUAL                                                                { $$ = new AssignmentOperator($1); }
                |    RSHIFTEQUAL                                                                { $$ = new AssignmentOperator($1); }
                |    ANDEQUAL                                                                   { $$ = new AssignmentOperator($1); }
                |    XOREQUAL                                                                   { $$ = new AssignmentOperator($1); }
                |    OREQUAL                                                                    { $$ = new AssignmentOperator($1); }

UNARY_EXPR: POSTFIX_EXPR                                                                        { $$ = new UnaryExpr($1, NULL, NULL, NULL, NULL, NULL); }
        |   INCREMENT UNARY_EXPR                                                                { $$ = new UnaryExpr(NULL, $2, NULL, NULL, NULL, $1); }
        |   DECREMENT UNARY_EXPR                                                                { $$ = new UnaryExpr(NULL, $2, NULL, NULL, NULL, $1); }
        |   UNARY_OPERATOR CAST_EXPR                                                            { $$ = new UnaryExpr(NULL, NULL, $1, $2, NULL, NULL); }
        |   SIZEOF UNARY_EXPR                                                                   { $$ = new UnaryExpr(NULL, $2, NULL, NULL, NULL, $1); }
        |   SIZEOF LB TYPE_NAME RB                                                              { $$ = new UnaryExpr(NULL, NULL, NULL, NULL, $3, $1); }

UNARY_OPERATOR: AMPERSAND                                                                       { $$ = new UnaryOperator($1); }
            |   ASTERISK                                                                        { $$ = new UnaryOperator($1); }
            |   PLUS                                                                            { $$ = new UnaryOperator($1); }
            |   MINUS                                                                           { $$ = new UnaryOperator($1); }
            |   TILDE                                                                           { $$ = new UnaryOperator($1); }
            |   EXCLAMATION                                                                     { $$ = new UnaryOperator($1); }

POSTFIX_EXPR: PRIMARY_EXPR                                                                      { $$ = new PostfixExpr($1, NULL, NULL, NULL, NULL, NULL); }
            | PRIMARY_EXPR LSB EXPR RSB                                                         { $$ = new PostfixExpr($1, $3, NULL, NULL, NULL, NULL); }
            | POSTFIX_EXPR LB ARGUMENT_EXPR_LIST RB                                             { $$ = new PostfixExpr(NULL, NULL, $1, $3, NULL, NULL); }
            | POSTFIX_EXPR LB RB                                                                { $$ = new PostfixExpr(NULL, NULL, $1, NULL, NULL, NULL); }
            | POSTFIX_EXPR DOT IDENTIFIER                                                       { $$ = new PostfixExpr(NULL, NULL, $1, NULL, $2, $3); }
            | POSTFIX_EXPR ARROW IDENTIFIER                                                     { $$ = new PostfixExpr(NULL, NULL, $1, NULL, $2, $3); }
            | POSTFIX_EXPR INCREMENT                                                            { $$ = new PostfixExpr(NULL, NULL, $1, NULL, $2, NULL); }
            | POSTFIX_EXPR DECREMENT                                                            { $$ = new PostfixExpr(NULL, NULL, $1, NULL, $2, NULL); }

PRIMARY_EXPR: IDENTIFIER                                                                        { $$ = new PrimaryExpr($1, NULL, NULL, NULL); }
            | CONSTANT                                                                          { $$ = new PrimaryExpr(NULL, $1, NULL, NULL); }
            | STRING_LITERAL                                                                    { $$ = new PrimaryExpr(NULL, NULL, $1, NULL); }
            | LB EXPR RB                                                                        { $$ = new PrimaryExpr(NULL, NULL, NULL, $2); }

ARGUMENT_EXPR_LIST: ASSIGNMENT_EXPR                                                             { $$ = new ArgumentExprList($1, NULL); }
                |   ARGUMENT_EXPR_LIST COMMA ASSIGNMENT_EXPR                                    { $$ = new ArgumentExprList($3, $1); }

CAST_EXPR: UNARY_EXPR                                                                           { $$ = new CastExpr($1, NULL, NULL); }
        |  LB TYPE_NAME RB CAST_EXPR                                                            { $$ = new CastExpr(NULL, $2, $4); }

TYPE_NAME: SPECIFIER_QUALIFIER_LIST ABSTRACT_DECLARATOR                                         
        |  SPECIFIER_QUALIFIER_LIST                                                             

STATEMENT: LABELED_STATEMENT                                                                    { $$ = new Statement($1, NULL, NULL, NULL, NULL, NULL); }
        |  COMPOUND_STATEMENT                                                                   { $$ = new Statement(NULL, $1, NULL, NULL, NULL, NULL); }
        |  EXPR_STATEMENT                                                                       { $$ = new Statement(NULL, NULL, $1, NULL, NULL, NULL); }
        |  SELECTION_STATEMENT                                                                  { $$ = new Statement(NULL, NULL, NULL, $1, NULL, NULL); }
        |  ITERATION_STATEMENT                                                                  { $$ = new Statement(NULL, NULL, NULL, NULL, $1, NULL); }
        |  JUMP_STATEMENT                                                                       { $$ = new Statement(NULL, NULL, NULL, NULL, NULL, $1); }

LABELED_STATEMENT: IDENTIFIER COLON STATEMENT                                                   
                |  CASE CONSTANT_EXPR COLON STATEMENT                                           
                |  DEFAULT COLON STATEMENT                                                      

EXPR_STATEMENT: EXPR SEMICOLON                                                                  { $$ = new ExprStatement($1); }
            |   SEMICOLON                                                                       { $$ = new ExprStatement(NULL); }

SELECTION_STATEMENT: IF LB EXPR RB STATEMENT                                                    
                |    IF LB EXPR RB STATEMENT ELSE STATEMENT                                     
                |    SWITCH LB EXPR RB STATEMENT                                                

ITERATION_STATEMENT: WHILE LB EXPR RB STATEMENT                                                 
                |    DO STATEMENT WHILE LB EXPR RB SEMICOLON                                    
                |    FOR LB EXPR_STATEMENT EXPR_STATEMENT RB STATEMENT                          
                |    FOR LB EXPR_STATEMENT EXPR_STATEMENT EXPR RB STATEMENT                     

JUMP_STATEMENT: CONTINUE SEMICOLON                                                              { $$ = new JumpStatement($1, NULL); }
            |   BREAK SEMICOLON                                                                 { $$ = new JumpStatement($1, NULL); }
            |   RETURN EXPR                                                                     { $$ = new JumpStatement($1, $2); }

STORAGE_CLASS_SPECIFIER: TYPEDEF                                                                { $$ = new StorageClassSpecifier($1); }
                    |    EXTERN                                                                 { $$ = new StorageClassSpecifier($1); }
                    |    STATIC                                                                 { $$ = new StorageClassSpecifier($1); }
                    |    AUTO                                                                   { $$ = new StorageClassSpecifier($1); }
                    |    REGISTER                                                               { $$ = new StorageClassSpecifier($1); }

TYPE_SPECIFIER: VOID                                                                            { $$ = new TypeSpecifier($1, NULL, NULL); }
            |   CHAR                                                                            { $$ = new TypeSpecifier($1, NULL, NULL); }
            |   SHORT                                                                           { $$ = new TypeSpecifier($1, NULL, NULL); }
            |   INT                                                                             { $$ = new TypeSpecifier($1, NULL, NULL); }
            |   LONG                                                                            { $$ = new TypeSpecifier($1, NULL, NULL); }
            |   FLOAT                                                                           { $$ = new TypeSpecifier($1, NULL, NULL); }
            |   DOUBLE                                                                          { $$ = new TypeSpecifier($1, NULL, NULL); }
            |   SIGNED                                                                          { $$ = new TypeSpecifier($1, NULL, NULL); }
            |   UNSIGNED                                                                        { $$ = new TypeSpecifier($1, NULL, NULL); }
            |   STRUCT_SPECIFIER                                                                { $$ = new TypeSpecifier(NULL, $1, NULL); }
            |   ENUM_SPECIFIER                                                                  { $$ = new TypeSpecifier(NULL, NULL, $1); }

STRUCT_SPECIFIER: STRUCT IDENTIFIER LCB STRUCT_DECLARATION_LIST RCB                             
                    |   STRUCT LCB STRUCT_DECLARATION_LIST RCB                                  
                    |   STRUCT IDENTIFIER                                                       

STRUCT_DECLARATION_LIST: STRUCT_DECLARATION                                                     
                    |    STRUCT_DECLARATION_LIST STRUCT_DECLARATION                             

STRUCT_DECLARATION: SPECIFIER_QUALIFIER_LIST STRUCT_DECLARATOR_LIST SEMICOLON                   

SPECIFIER_QUALIFIER_LIST: TYPE_SPECIFIER SPECIFIER_QUALIFIER_LIST                               { $$ = new SpecifierQualifierList($1, $2); }
                        | TYPE_SPECIFIER                                                        { $$ = new SpecifierQualifierList($1, NULL); }

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

ENUMERATOR: IDENTIFIER                                                                          
        |   IDENTIFIER EQUAL CONSTANT_EXPR                                                      

%%

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