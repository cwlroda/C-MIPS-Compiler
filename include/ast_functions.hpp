#ifndef AST_FUNCTIONS_HPP
#define AST_FUNCTIONS_HPP

#include "ast_node.hpp"

#include <iostream>
#include <fstream>

static Context context;

/*-------------*
| DECLARATIONS |
*-------------*/

class TranslationUnit{
    public:
        TranslationUnit(
            ExternalDeclaration *_ext_decl,
            TranslationUnit *_trans_unit
        ):
            ext_decl(_ext_decl),
            trans_unit(_trans_unit)
        {}
        ~TranslationUnit();

        void print_c(std::ofstream& out);
        void print_py_main(std::string& filename) const;
        void print_py(std::ofstream& out);
        void print_asm_main(std::string& filename) const;
        void print_asm(std::ofstream& out);

    private:
        ExternalDeclaration *ext_decl;
        TranslationUnit *trans_unit;
};

class ExternalDeclaration{
    public:
        ExternalDeclaration(
            FunctionDefinition *_func_def,
            Declaration *_decl
        ):
            func_def(_func_def),
            decl(_decl)
        {}
        ~ExternalDeclaration(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        FunctionDefinition *func_def;
        Declaration *decl;
};

class FunctionDefinition{
    public:
        FunctionDefinition(
            DeclarationSpecifier *_decl_spec,
            Declarator *_declr,
            DeclarationList *_decl_list,
            CompoundStatement *_comp_state
        ):
            decl_spec(_decl_spec),
            declr(_declr),
            decl_list(_decl_list),
            comp_state(_comp_state)
        {}
        ~FunctionDefinition(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        int CalcMemoryNeeded(std::vector<int> mv);

    private:
        DeclarationSpecifier *decl_spec;
        Declarator *declr;
        DeclarationList *decl_list;
        CompoundStatement *comp_state;
};

class Declaration{
    public:
        Declaration(
            DeclarationSpecifier *_decl_spec,
            InitDeclarator *_init_declr
        ):
            decl_spec(_decl_spec),
            init_declr(_init_declr)
        {}
        ~Declaration(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(std::vector<int>& mv);

    private:
        DeclarationSpecifier *decl_spec;
        InitDeclarator *init_declr;
};

class DeclarationSpecifier{
    public:
        DeclarationSpecifier(
            TypeSpecifier *_type_spec,
            DeclarationSpecifier *_decl_spec,
            std::string *_typed
        ):
            type_spec(_type_spec),
            decl_spec(_decl_spec),
            typed(_typed)
        {}
        ~DeclarationSpecifier(){}

        void print_c(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(std::vector<int>& mv);

    private:
        TypeSpecifier *type_spec;
        DeclarationSpecifier *decl_spec;
        std::string *typed;
};

class DeclarationList{
    public:
        DeclarationList(
            DeclarationList *_decl_list,
            Declaration *_decl
        ):
            decl_list(_decl_list),
            decl(_decl)
        {}
        ~DeclarationList(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(std::vector<int>& mv);
    private:
        DeclarationList *decl_list;
        Declaration *decl;
};

class InitDeclarator{
    public:
        InitDeclarator(
            Declarator *_declr,
            Initializer *_init
        ):
            declr(_declr),
            init(_init)
        {}
        ~InitDeclarator(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        Declarator *declr;
        Initializer *init;
};

class InitializerList{
    public:
        InitializerList(
            Initializer *_init,
            InitializerList *_init_list
        ):
            init(_init),
            init_list(_init_list)
        {}
        ~InitializerList(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        Initializer *init;
        InitializerList *init_list;
};

class Initializer{
    public:
        Initializer(
            AssignmentExpr *_assign_expr,
            InitializerList *_init_list
        ):
            assign_expr(_assign_expr),
            init_list(_init_list)
        {}
        ~Initializer(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        AssignmentExpr *assign_expr;
        InitializerList *init_list;
};

class Declarator{
    public:
        Declarator(
            Pointer *_ptr,
            DirectDeclarator *_dir_declr
        ):
            ptr(_ptr),
            dir_declr(_dir_declr)
        {}
        ~Declarator(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out, bool is_init, bool in_func);
        void print_asm(std::ofstream& out);

    private:
        Pointer *ptr;
        DirectDeclarator *dir_declr;
};

class DirectDeclarator{
    public:
        DirectDeclarator(
            Declarator *_declr,
            DirectDeclarator *_dir_declr,
            std::string *_constant,
            ParameterList *_param_list,
            std::string *_iden,
            std::string *_brac_type
        ):
            declr(_declr),
            dir_declr(_dir_declr),
            constant(_constant),
            param_list(_param_list),
            iden(_iden),
            brac_type(_brac_type)
        {}
        ~DirectDeclarator(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out, bool is_init, bool in_func);
        void print_asm(std::ofstream& out);

    private:
        Declarator *declr;
        DirectDeclarator *dir_declr;
        std::string *constant;
        ParameterList *param_list;
        std::string *iden;
        std::string *brac_type;
};

class ParameterList{
    public:
        ParameterList(
            ParameterDeclaration *_param_decl,
            ParameterList *_param_list
        ):
            param_decl(_param_decl),
            param_list(_param_list)
        {}
        ~ParameterList(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out, std::unordered_map<std::string, int>& fn_parameter_list);

    private:
        ParameterDeclaration *param_decl;
        ParameterList *param_list;
};

class ParameterDeclaration{
    public:
        ParameterDeclaration(
            DeclarationSpecifier *_decl_spec,
            Declarator *_declr,
            AbstractDeclarator *_abs_declr
        ):
            decl_spec(_decl_spec),
            declr(_declr),
            abs_declr(_abs_declr)
        {}
        ~ParameterDeclaration(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        DeclarationSpecifier *decl_spec;
        Declarator *declr;
        AbstractDeclarator *abs_declr;
};

class AbstractDeclarator{
    public:
        AbstractDeclarator(
            Pointer *_ptr,
            DirectAbstractDeclarator *_dir_abs_declr
        ):
            ptr(_ptr),
            dir_abs_declr(_dir_abs_declr)
        {}
        ~AbstractDeclarator(){}

        void print_c(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        Pointer *ptr;
        DirectAbstractDeclarator *dir_abs_declr;
};

class DirectAbstractDeclarator{
    public:
        DirectAbstractDeclarator(
            AbstractDeclarator *_abs_declr,
            DirectAbstractDeclarator *_dir_abs_declr,
            ConstantExpr *_const_expr,
            ParameterList *_param_list
        ):
            abs_declr(_abs_declr),
            dir_abs_declr(_dir_abs_declr),
            const_expr(_const_expr),
            param_list(_param_list)
        {}
        ~DirectAbstractDeclarator(){}

        void print_c(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        AbstractDeclarator *abs_declr;
        DirectAbstractDeclarator *dir_abs_declr;
        ConstantExpr *const_expr;
        ParameterList *param_list;
};

class SpecifierQualifierList{
    public:
        SpecifierQualifierList(
            TypeSpecifier *_type_spec,
            SpecifierQualifierList *_spec_qual_list
        ):
            type_spec(_type_spec),
            spec_qual_list(_spec_qual_list)
        {}
        ~SpecifierQualifierList(){}

        void print_c(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        TypeSpecifier *type_spec;
        SpecifierQualifierList *spec_qual_list;
};

/*
class StructSpecifier{
    public:
        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
};

class StructDeclarationList{
    public:
        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
};

class StructDeclaration{
    public:
        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
};

class StructDeclaratorList{
    public:
        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
};

class StructDeclarator{
    public:
        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
};
*/

/*------------*
| EXPRESSIONS |
*------------*/

class Expr{
    public:
        Expr(
            AssignmentExpr *_assign_expr,
            Expr *_expr
        ):
            assign_expr(_assign_expr),
            expr(_expr)
        {}
        ~Expr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(std::vector<int>& mv);
        void checking_enum();

    private:
        AssignmentExpr *assign_expr;
        Expr *expr;
};

class ConstantExpr{
    public:
        ConstantExpr(
            ConditionalExpr *_cond_expr
        ):
            cond_expr(_cond_expr)
        {}
        ~ConstantExpr(){}

        void print_c(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void checking_enum();
        

    private:
        ConditionalExpr *cond_expr;
};

class ConditionalExpr{
    public:
        ConditionalExpr(
            LogicalOrExpr *_log_or_expr,
            Expr *_expr,
            ConditionalExpr *_cond_expr
        ):
            log_or_expr(_log_or_expr),
            expr(_expr),
            cond_expr(_cond_expr)
        {}
        ~ConditionalExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();

    private:
        LogicalOrExpr *log_or_expr;
        Expr *expr;
        ConditionalExpr *cond_expr;
};

class LogicalOrExpr{
    public:
        LogicalOrExpr(
            LogicalAndExpr *_log_and_expr,
            LogicalOrExpr *_log_or_expr
        ):
            log_and_expr(_log_and_expr),
            log_or_expr(_log_or_expr)
        {}
        ~LogicalOrExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();

    private:
        LogicalAndExpr *log_and_expr;
        LogicalOrExpr *log_or_expr;
};

class LogicalAndExpr{
    public:
        LogicalAndExpr(
            InclusiveOrExpr *_incl_or_expr,
            LogicalAndExpr *_log_and_expr
        ):
            incl_or_expr(_incl_or_expr),
            log_and_expr(_log_and_expr)
        {}
        ~LogicalAndExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        InclusiveOrExpr *incl_or_expr;
        LogicalAndExpr *log_and_expr;
};

class InclusiveOrExpr{
    public:
        InclusiveOrExpr(
            ExclusiveOrExpr *_excl_or_expr,
            InclusiveOrExpr *_incl_or_expr
        ):
            excl_or_expr(_excl_or_expr),
            incl_or_expr(_incl_or_expr)
        {}
        ~InclusiveOrExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        ExclusiveOrExpr *excl_or_expr;
        InclusiveOrExpr *incl_or_expr;
};

class ExclusiveOrExpr{
    public:
        ExclusiveOrExpr(
            AndExpr *_and_expr,
            ExclusiveOrExpr *_excl_or_expr
        ):
            and_expr(_and_expr),
            excl_or_expr(_excl_or_expr)
        {}
        ~ExclusiveOrExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        AndExpr *and_expr;
        ExclusiveOrExpr *excl_or_expr;
};

class AndExpr{
    public:
        AndExpr(
            EqualityExpr *_equal_expr,
            AndExpr *_and_expr
        ):
            equal_expr(_equal_expr),
            and_expr(_and_expr)
        {}
        ~AndExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        EqualityExpr *equal_expr;
        AndExpr *and_expr;
};

class EqualityExpr{
    public:
        EqualityExpr(
            RelationalExpr *_rel_expr,
            EqualityExpr *_equal_expr,
            std::string *_op
        ):
            rel_expr(_rel_expr),
            equal_expr(_equal_expr),
            op(_op)
        {}
        ~EqualityExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        RelationalExpr *rel_expr;
        EqualityExpr *equal_expr;
        std::string *op;
};

class RelationalExpr{
    public:
        RelationalExpr(
            ShiftExpr *_shift_expr,
            RelationalExpr *_rel_expr,
            std::string *_op
        ):
            shift_expr(_shift_expr),
            rel_expr(_rel_expr),
            op(_op)
        {}
        ~RelationalExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        ShiftExpr *shift_expr;
        RelationalExpr *rel_expr;
        std::string *op;
};

class ShiftExpr{
    public:
        ShiftExpr(
            AdditiveExpr *_add_expr,
            ShiftExpr *_shift_expr,
            std::string *_op
        ):
            add_expr(_add_expr),
            shift_expr(_shift_expr),
            op(_op)
        {}
        ~ShiftExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        AdditiveExpr *add_expr;
        ShiftExpr *shift_expr;
        std::string *op;
};

class AdditiveExpr{
    public:
        AdditiveExpr(
            MultiplicativeExpr *_mul_expr,
            AdditiveExpr *_add_expr,
            std::string *_op
        ):
            mul_expr(_mul_expr),
            add_expr(_add_expr),
            op(_op)
        {}
        ~AdditiveExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        MultiplicativeExpr *mul_expr;
        AdditiveExpr *add_expr;
        std::string *op;
};

class MultiplicativeExpr{
    public:
        MultiplicativeExpr(
            CastExpr *_cast_expr,
            MultiplicativeExpr *_mul_expr,
            std::string *_op
        ):
            cast_expr(_cast_expr),
            mul_expr(_mul_expr),
            op(_op)
        {}
        ~MultiplicativeExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        CastExpr *cast_expr;
        MultiplicativeExpr *mul_expr;
        std::string *op;
};

class AssignmentExpr{
    public:
        AssignmentExpr(
            ConditionalExpr *_cond_expr,
            UnaryExpr *_un_expr,
            AssignmentOperator *_ass_op,
            AssignmentExpr *_ass_expr
        ):
            cond_expr(_cond_expr),
            un_expr(_un_expr),
            ass_op(_ass_op),
            ass_expr(_ass_expr)
        {}
        ~AssignmentExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();

    private:
        ConditionalExpr *cond_expr;
        UnaryExpr *un_expr;
        AssignmentOperator *ass_op;
        AssignmentExpr *ass_expr;
};

class AssignmentOperator{
    public:
        AssignmentOperator(
            std::string *_type
        ):
            type(_type)
        {}
        ~AssignmentOperator(){}

        void print_c(std::ofstream& out);
        void print_asm(std::ofstream& out);
        std::string get_type(){ return *type; }

    private:
        std::string *type;
};

class UnaryExpr{
    public:
        UnaryExpr(
            PostfixExpr *_post_expr,
            UnaryExpr *_un_expr,
            UnaryOperator *_un_op,
            CastExpr *_cast_expr,
            TypeName *_type_name,
            std::string *_op
        ):
            post_expr(_post_expr),
            un_expr(_un_expr),
            un_op(_un_op),
            cast_expr(_cast_expr),
            type_name(_type_name),
            op(_op)
        {}
        ~UnaryExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        PostfixExpr *post_expr;
        UnaryExpr *un_expr;
        UnaryOperator *un_op;
        CastExpr *cast_expr;
        TypeName *type_name;
        std::string *op;
};

class UnaryOperator{
    public:
        UnaryOperator(
            std::string *_op
        ):
            op(_op)
        {}
        ~UnaryOperator(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        std::string print_asm(std::ofstream& out){ return *op; }
        void checking_enum();

    private:
        std::string *op;
};

class PostfixExpr{
    public:
        PostfixExpr(
            PrimaryExpr *_pri_expr,
            Expr *_expr,
            PostfixExpr *_post_expr,
            ArgumentExprList *_arg_expr_list,
            std::string *_op,
            std::string *_iden
        ):
            pri_expr(_pri_expr),
            expr(_expr),
            post_expr(_post_expr),
            arg_expr_list(_arg_expr_list),
            op(_op),
            iden(_iden)
        {}
        ~PostfixExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();
        


    private:
        PrimaryExpr *pri_expr;
        Expr *expr;
        PostfixExpr *post_expr;
        ArgumentExprList *arg_expr_list;
        std::string *op;
        std::string *iden;
};

class PrimaryExpr{
    public:
        PrimaryExpr(
            std::string *_iden,
            std::string *_constant,
            std::string *_str_lit,
            Expr *_expr
        ):
            iden(_iden),
            constant(_constant),
            str_lit(_str_lit),
            expr(_expr)
        {}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void checking_enum();

    private:
        std::string *iden;
        std::string *constant;
        std::string *str_lit;
        Expr *expr;
};

class ArgumentExprList{
    public:
        ArgumentExprList(
            AssignmentExpr *_ass_expr,
            ArgumentExprList *_arg_expr_list
        ):
            ass_expr(_ass_expr),
            arg_expr_list(_arg_expr_list)
        {}
        ~ArgumentExprList(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        

    private:
        AssignmentExpr *ass_expr;
        ArgumentExprList *arg_expr_list;
};

class CastExpr{
    public:
        CastExpr(
            UnaryExpr *_un_expr,
            TypeName *_type_name,
            CastExpr *_cast_expr
        ):
            un_expr(_un_expr),
            type_name(_type_name),
            cast_expr(_cast_expr)
        {}
        ~CastExpr(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(int& iterations);
        void checking_enum();


    private:
        UnaryExpr *un_expr;
        TypeName *type_name;
        CastExpr *cast_expr;
};

/*-----------*
| STATEMENTS |
*-----------*/

class CompoundStatement{
    public:
        CompoundStatement(
            DeclarationList *_decl_list,
            StatementList *_state_list
        ):
            decl_list(_decl_list),
            state_list(_state_list)
        {}
        ~CompoundStatement(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out, bool is_init, bool in_func);
        void print_asm(std::ofstream& out);
        void alloc_mem(std::vector<int>& mv);

    private:
        DeclarationList *decl_list;
        StatementList *state_list;
};

class StatementList{
    public:
        StatementList(
            Statement *_state,
            StatementList *_state_list
        ):
            state(_state),
            state_list(_state_list)
        {}
        ~StatementList(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(std::vector<int>& ac);

    private:
        Statement *state;
        StatementList *state_list;
};

class Statement{
    public:
        Statement(
            LabeledStatement *_label_state,
            CompoundStatement *_comp_state,
            ExprStatement *_expr_state,
            SelectionStatement *_select_state,
            IterationStatement *_it_state,
            JumpStatement *_jump_state
        ):
            label_state(_label_state),
            comp_state(_comp_state),
            expr_state(_expr_state),
            select_state(_select_state),
            it_state(_it_state),
            jump_state(_jump_state)
        {}
        ~Statement(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(std::vector<int>& mv);

        CompoundStatement* get_comp_state(){return comp_state;}
        SelectionStatement* get_select_state(){return select_state;}

    private:
        LabeledStatement *label_state;
        CompoundStatement *comp_state;
        ExprStatement *expr_state;
        SelectionStatement *select_state;
        IterationStatement *it_state;
        JumpStatement *jump_state;
};

class LabeledStatement{
    public:
        LabeledStatement(
            Statement *_state,
            ConstantExpr *_const_expr
        ):
            state(_state),
            const_expr(_const_expr)
        {}
        ~LabeledStatement(){}

        void print_c(std::ofstream& out);
        void print_asm(std::ofstream& out);
        

    private:
        
        ConstantExpr *const_expr;
        Statement *state;
        // identifier
};

class ExprStatement{
    public:
        ExprStatement(
            Expr *_expr
        ):
            expr(_expr)
        {}
        ~ExprStatement(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(std::vector<int>& mv);

    private:
        Expr *expr;
};

class SelectionStatement{
    public:
        SelectionStatement(
            Expr *_expr,
            Statement *_if_state,
            Statement *_else_state,
            std::string *_IF,
            std::string *_ELSE,
            std::string *_SWITCH
        ):
            expr(_expr),
            if_state(_if_state),
            else_state(_else_state),
            IF(_IF),
            ELSE(_ELSE),
            SWITCH(_SWITCH)
        {}
        ~SelectionStatement(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

        Expr* get_expr(){return expr;}

    private:
        Expr *expr;
        Statement *if_state;
        Statement *else_state;
        std::string *IF;
        std::string *ELSE;
        std::string *SWITCH;
};

class IterationStatement{
    public:
        IterationStatement(
            Expr *_expr,
            Statement *_state,
            ExprStatement *_for_first,
            ExprStatement *_for_second,
            std::string *_type
        ):
            expr(_expr),
            state(_state),
            for_first(_for_first),
            for_second(_for_second),
            type(_type)
        {}
        ~IterationStatement(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        Expr *expr;
        Statement *state;
        ExprStatement *for_first;
        ExprStatement *for_second;
        std::string *type;
};

class JumpStatement{
    public:
        JumpStatement(
            std::string *_type,
            Expr *_expr
        ):
            type(_type),
            expr(_expr)
        {}
        ~JumpStatement(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        std::string *type;
        Expr *expr;
};

/*-------*
| OTHERS |
*-------*/

class TypeSpecifier{
    public:
        TypeSpecifier(
            std::string *_type,
            StructSpecifier *_struct_spec,
            EnumSpecifier *_enum_spec
        ):
            type(_type),
            struct_spec(_struct_spec),
            enum_spec(_enum_spec)
        {}
        ~TypeSpecifier(){}

        void print_c(std::ofstream& out);
        void print_asm(std::ofstream& out);
        void alloc_mem(std::vector<int>& mv);

    private:
        std::string *type;
        StructSpecifier *struct_spec;
        EnumSpecifier *enum_spec;
        // identifier
        // type
};

class TypeName{
    public:
        TypeName(
            SpecifierQualifierList *_spec_qual_list,
            AbstractDeclarator *_abs_declr
        ):
            spec_qual_list(_spec_qual_list),
            abs_declr(_abs_declr)
        {}
        ~TypeName(){}

        void print_c(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        SpecifierQualifierList *spec_qual_list;
        AbstractDeclarator *abs_declr;
};

class Pointer{
    public:
        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
    
};

class EnumSpecifier{
    public:
        EnumSpecifier(
            std::string *_iden,
            EnumeratorList *_enum_list
        ):
            iden(_iden),
            enum_list(_enum_list)
        {}
        ~EnumSpecifier(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
    std::string *iden;
    EnumeratorList *enum_list;
};

class EnumeratorList{
    public:
        EnumeratorList(
            EnumeratorList *_enum_list,
            Enumerator *_enume
        ):
            enum_list(_enum_list),
            enume(_enume)
        {}
        ~EnumeratorList(){}

        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);

    private:
        EnumeratorList *enum_list;
        Enumerator *enume;
        
};

class Enumerator{
    public:
        Enumerator(
            std::string *_iden,
            ConstantExpr *_const_expr
        ):
            iden(_iden),
            const_expr(_const_expr)
        {}
        ~Enumerator(){}
        void print_c(std::ofstream& out);
        void print_py(std::ofstream& out);
        void print_asm(std::ofstream& out);
    private:
        std::string *iden;
        ConstantExpr *const_expr;
};

#endif