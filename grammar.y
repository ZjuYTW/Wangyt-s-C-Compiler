%{
    #include <stdlib.h>
    #include <stdio.h>
    #include "ast.hpp"
    #include "block.hpp"
    #include "parser.hpp"
    using namespace std;
    
    extern char *yytext;
    extern int column;
    extern FILE * yyin;
    extern FILE * yyout;
    root_Node *root;
    extern int yylineno;
    
    int yylex(void);
    void yyerror(const char*);
    %}

%union{
    struct root_Node* rootN;
    struct func_Node* funcN;
    struct ID_Node* IDN;
    struct declaration_Node* declarationN;
    struct declarator_Node* declaratorN;
    struct initializer_Node* initN;
    struct initial_list* initl;
    struct designator* design;
    struct param_Node* paraN;
    struct stat_Node* statN;
    struct block_item* block;
    struct exp_Node* expN;
    enum type_specifier_kind typekind;
    enum assign_kind assignkind;
    enum unary_kind arykind;
}

%type <rootN>  translation_unit external_declaration
%type <funcN>  function_definition
%type  <IDN> identifier_list
%type <declarationN> declaration declaration_list
%type <declaratorN>  declarator init_declarator init_declarator_list
%type <initN>  initializer
%type <initl>  initializer_list
%type <design> designation designator_list designator
%type <paraN>  parameter_declaration parameter_list
%type <statN>  statement labeled_statement compound_statement expression_statement
%type <statN>  selection_statement iteration_statement jump_statement
%type <block>  block_item block_item_list
%type <expN> primary_expression postfix_expression argument_expression_list unary_expression
%type <expN> multiplicative_expression additive_expression shift_expression relational_expression equality_expression
%type <expN> and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression constant_expression
%type <expN> assignment_expression expression
%type  <typekind>  type_specifier
%type  <arykind>   unary_operator
%type  <assignkind> assignment_operator

%token CASE IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN XOR_ASSIGN OR_ASSIGN TYPE_NAME
%token ';' ',' ':' '=' '[' ']' '.' '&' '!' '~' '-' '+' '*' '/' '%' '<' '>' '^' '|' '?' '{' '}' '(' ')'
%token <IDN> IDENTIFIER
%token <expN> CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_DOUBLE TRUE FALSE
%token <typekind>  CHAR INT DOUBLE VOID BOOL
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

Program:
translation_unit {//创建一个根节点
    root = $1;
}
;

/*基本表达式*/
primary_expression:
IDENTIFIER {
    $$ = create_exp_tree($1->line,0);//$1是ID_Node
    $$->info.prim_info.detail.ID = $1;
}
|
TRUE {
    $$ = $1;
}
|
FALSE {
    $$ = $1;
}
| CONSTANT_INT {
    $$ = $1;
    
}
| CONSTANT_DOUBLE {
    $$ = $1;
}

| '(' expression ')'{
    $$ = create_exp_tree($2->line,5);
    $$ ->info.prim_info.detail.exp = $2;
}
;

/*后缀表达式*/
postfix_expression:
primary_expression{
    $$ = create_exp_tree(1);
    $$->info.post_info.type2 = post_NA;
    $$->info.post_info.arg_list = $1;
    $$->info.post_info.post_exp = NULL;
    $$->line = $1->line;
}
|     postfix_expression '[' expression ']'{
    $$ = create_exp_tree(1);
    $$->info.post_info.post_exp = $1;
    $$->info.post_info.arg_list = $3;
    $$->info.post_info.type2 = ARRAY_CALL;
    $$->line = $1->line;
    //数组调用
}
|     postfix_expression '(' ')'
{
    $$ = create_exp_tree(1);
    $$->info.post_info.type2 = FUNC_CALL;
    $$->info.post_info.post_exp = $1;
    $$->info.post_info.arg_list = NULL;
    $$->line = $1->line;
    //函数调用
}
|     postfix_expression '(' argument_expression_list ')'{
    $$ = create_exp_tree(1);
    $$->info.post_info.type2 = FUNC_CALL;
    $$->info.post_info.post_exp = $1;
    $$->info.post_info.arg_list = $3;
    $$->line = $1->line;
    //函数调用
}
|     postfix_expression INC_OP{
    //++
    $$ = create_exp_tree(1);
    $$->info.post_info.type2 = INC;
    $$->info.post_info.post_exp = $1;
    $$->info.post_info.arg_list = NULL;
    $$->line = $1->line;
}
|     postfix_expression DEC_OP{
    //--
    $$ = create_exp_tree(1);
    $$->info.post_info.type2 = DEC;
    $$->info.post_info.post_exp = $1;
    $$->info.post_info.arg_list = NULL;
    $$->line = $1->line;
}
;

argument_expression_list:
assignment_expression{
    $$ = create_exp_tree(14);
    $$->info.argument_info.type2 = SINGLE;
    $$->info.argument_info.argu_exp = NULL;
    $$->info.argument_info.assig_exp = $1;
    $$->line = $1->line;
}
|     argument_expression_list ',' assignment_expression {
    $$ = create_exp_tree(14);
    $$->info.argument_info.type2 = GROUP;
    $$->info.argument_info.argu_exp = $1;
    $$->info.argument_info.assig_exp = $3;
    $$->line = $1->line;
}
;

/*一元表达式*/
unary_expression:
postfix_expression{
    //printf("postfix");
    $$ = create_exp_tree(13);
    $$->info.unary_info.type2 = unary_NA;
    $$->info.unary_info.post_exp = $1;
    $$->info.unary_info.unary_exp = NULL;
    $$->line = $1->line;
}
|     INC_OP unary_expression{
    //++
    $$ = create_exp_tree(13);
    $$->info.unary_info.type2 = t_INC_OP;
    $$->info.unary_info.unary_exp = $2;
    $$->info.unary_info.post_exp = NULL;
    $$->line = $2->line;
}
|     DEC_OP unary_expression{
    //--
    $$ = create_exp_tree(13);
    $$->info.unary_info.type2 = t_DEC_OP;
    $$->info.unary_info.unary_exp = $2;
    $$->info.unary_info.post_exp = NULL;
    $$->line = $2->line;
}
|     unary_operator unary_expression{
    $$ = create_exp_tree(13);
    $$->info.unary_info.type2 = $1;
    $$->info.unary_info.post_exp = NULL;
    $$->info.unary_info.unary_exp = $2;
    $$->line = $2->line;
}
;

/*单目运算符*/
unary_operator:
'+' {
    $$ = POS;
}
| '-' {
    $$ = NEG;
}
| '~' {
    $$ = BIT_NEG;
}
| '!' {
    $$ = FEI;
}
;

/*可乘表达式*/
multiplicative_expression:
unary_expression {
    $$ = create_exp_tree(12);
    $$->info.mul_info.type2 = mul_NA;
    $$->info.mul_info.unary_exp = $1;
    $$->info.mul_info.mul_exp = NULL;
    $$->line = $1->line;
}
| multiplicative_expression '*' unary_expression {
    $$ = create_exp_tree(12);
    $$->info.mul_info.type2 = MUL_OP;
    $$->info.mul_info.unary_exp = $3;
    $$->info.mul_info.mul_exp = $1;
    $$->line = $1->line;
}
| multiplicative_expression '/' unary_expression {
    $$ = create_exp_tree(12);
    $$->info.mul_info.type2 = DIV_OP;
    $$->info.mul_info.unary_exp = $3;
    $$->info.mul_info.mul_exp = $1;
    $$->line = $1->line;
}
| multiplicative_expression '%' unary_expression {
    $$ = create_exp_tree(12);
    $$->info.mul_info.type2 = MOD;
    $$->info.mul_info.unary_exp = $3;
    $$->info.mul_info.mul_exp = $1;
    $$->line = $1->line;
}
;

/*可加表达式*/
additive_expression:
multiplicative_expression  {
    $$ = create_exp_tree(11);
    $$->info.add_info.type2 = add_NA;
    $$->info.add_info.add_exp = NULL;
    $$->info.add_info.mul_exp = $1;
    $$->line = $1->line;
}
| additive_expression '+' multiplicative_expression {
    $$ = create_exp_tree(11);
    $$->info.add_info.type2 = ADD_OP;
    $$->info.add_info.add_exp = $1;
    $$->info.add_info.mul_exp = $3;
    $$->line = $1->line;
}
| additive_expression '-' multiplicative_expression {
    $$ = create_exp_tree(11);
    $$->info.add_info.type2 = MINUS_OP;
    $$->info.add_info.add_exp = $1;
    $$->info.add_info.mul_exp = $3;
    $$->line = $1->line;
}
;

/*左移右移*/
shift_expression:
additive_expression {
    $$ = create_exp_tree(10);
    $$->info.shift_info.type2 = shift_NA;
    $$->info.shift_info.shift_exp = NULL;
    $$->info.shift_info.addtive_exp = $1;
    $$->line = $1->line;
    
}
| shift_expression LEFT_OP additive_expression {
    //<<
    $$ = create_exp_tree(10);
    $$->info.shift_info.type2 = LEFT;
    $$->info.shift_info.shift_exp = $1;
    $$->info.shift_info.addtive_exp = $3;
    $$->line = $1->line;
}
| shift_expression RIGHT_OP additive_expression {
    //>>
    $$ = create_exp_tree(10);
    $$->info.shift_info.type2 = RIGHT;
    $$->info.shift_info.shift_exp = $1;
    $$->info.shift_info.addtive_exp = $3;
    $$->line = $1->line;
}
;

/*关系表达式*/
relational_expression:
shift_expression {
    $$ = create_exp_tree(9);
    $$->info.rela_info.type2 = relation_NA;
    $$->info.rela_info.relation_exp = NULL;
    $$->info.rela_info.shift_exp = $1;
    $$->line = $1->line;
}
| relational_expression '<' shift_expression {
    $$ = create_exp_tree(9);
    $$->info.rela_info.type2 = LES;
    $$->info.rela_info.relation_exp = $1;
    $$->info.rela_info.shift_exp = $3;
    $$->line = $1->line;
}
| relational_expression '>' shift_expression {
    $$ = create_exp_tree(9);
    $$->info.rela_info.type2 = GT;
    $$->info.rela_info.relation_exp = $1;
    $$->info.rela_info.shift_exp = $3;
    $$->line = $1->line;
}
| relational_expression LE_OP shift_expression {
    // <=
    $$ = create_exp_tree(9);
    $$->info.rela_info.type2 = LE;
    $$->info.rela_info.relation_exp = $1;
    $$->info.rela_info.shift_exp = $3;
    $$->line = $1->line;
}
| relational_expression GE_OP shift_expression {
    // >=
    $$ = create_exp_tree(9);
    $$->info.rela_info.type2 = GE;
    $$->info.rela_info.relation_exp = $1;
    $$->info.rela_info.shift_exp = $3;
    $$->line = $1->line;
}
;

/*相等表达式*/
equality_expression:
relational_expression {
    $$ = create_exp_tree(8);
    $$->info.equal_info.type2 = equal_NA;
    $$->info.equal_info.equal_exp = NULL;
    $$->info.equal_info.relation_exp = $1;
    $$->line = $1->line;
}
| equality_expression EQ_OP relational_expression {
    // ==
    $$ = create_exp_tree(8);
    $$->info.equal_info.type2 = EQ;
    $$->info.equal_info.equal_exp = $1;
    $$->info.equal_info.relation_exp = $3;
    $$->line = $1->line;
}
| equality_expression NE_OP relational_expression {
    // !=
    $$ = create_exp_tree(8);
    $$->info.equal_info.type2 = NE;
    $$->info.equal_info.equal_exp = $1;
    $$->info.equal_info.relation_exp = $3;
    $$->line = $1->line;
}
;

and_expression:
equality_expression {
    $$ = create_exp_tree(7);
    $$->info.and_info.and_exp = NULL;
    $$->info.and_info.equal_exp = $1;
    $$->line = $1->line;
}
| and_expression '&' equality_expression {
    $$ = create_exp_tree(7);
    $$->info.and_info.and_exp = $1;
    $$->info.and_info.equal_exp = $3;
    $$->line = $1->line;
}
;

/*异或*/
exclusive_or_expression:
and_expression {
    $$ = create_exp_tree(6);
    $$->info.excl_or_info.exclusive_or_exp = NULL;
    $$->info.excl_or_info.and_exp = $1;
    $$->line = $1->line;
}
| exclusive_or_expression '^' and_expression {
    $$ = create_exp_tree(6);
    $$->info.excl_or_info.exclusive_or_exp = $1;
    $$->info.excl_or_info.and_exp = $3;
    $$->line = $1->line;
}
;

/*或*/
inclusive_or_expression:
exclusive_or_expression {
    $$ = create_exp_tree(5);
    $$->info.incl_or_info.inclusive_or_exp = NULL;
    $$->info.incl_or_info.exclusive_or_exp = $1;
    $$->line = $1->line;
}
| inclusive_or_expression '|' exclusive_or_expression {
    $$ = create_exp_tree(5);
    $$->info.incl_or_info.inclusive_or_exp = $1;
    $$->info.incl_or_info.exclusive_or_exp = $3;
    $$->line = $1->line;
}
;

/*and逻辑表达式*/
logical_and_expression:
inclusive_or_expression {
    $$ = create_exp_tree(4);
    $$->info.logi_and_info.logical_and_exp = NULL;
    $$->info.logi_and_info.inclusive_or_exp = $1;
    $$->line = $1->line;
}
| logical_and_expression AND_OP inclusive_or_expression {
    //&&
    $$ = create_exp_tree(4);
    $$->info.logi_and_info.logical_and_exp = $1;
    $$->info.logi_and_info.inclusive_or_exp = $3;
    $$->line = $1->line;
}
;

/*or 逻辑表达式*/
logical_or_expression:
logical_and_expression {
    $$ = create_exp_tree(3);
    $$->info.logi_or_info.logical_or_exp = NULL;
    $$->info.logi_or_info.logical_and_exp = $1;
    $$->line = $1->line;
}
| logical_or_expression OR_OP logical_and_expression {
    //||
    $$ = create_exp_tree(3);
    $$->info.logi_or_info.logical_or_exp = $1;
    $$->info.logi_or_info.logical_and_exp = $3;
    $$->line = $1->line;
}
;

conditional_expression
:logical_or_expression {
    $$ = create_exp_tree(16);
    $$->info.cond_info.logical_or_exp = $1;
    $$->info.cond_info.exp = NULL;
    $$->info.cond_info.cond_exp = NULL;
    $$->line = $1->line;
}
|logical_or_expression '?' expression ':' conditional_expression{
    $$ = create_exp_tree(16);
    $$->info.cond_info.logical_or_exp = $1;
    $$->info.cond_info.exp = $5;
    $$->info.cond_info.cond_exp = $3;
    $$->line = $1->line;
}
;

/*赋值表达式*/
assignment_expression:
conditional_expression {//logical_or_expression
    //条件表达式
    $$ = create_exp_tree(2);
    $$->info.assign_info.type2 = assign_NA;
    $$->info.assign_info.unary_exp = $1;
    $$->info.assign_info.assign_exp =  NULL;
    $$->line = $1->line;
}
| unary_expression assignment_operator assignment_expression {
    $$ = create_exp_tree(2);
    $$->info.assign_info.type2 = $2;
    $$->info.assign_info.unary_exp = $1;
    $$->info.assign_info.assign_exp =  $3;
    $$->line = $1->line;
}
;

/*赋值运算符*/
assignment_operator:
'=' {
    $$ = t_ASSIGNMENT;
}
| MUL_ASSIGN {
    //*=
    $$ = t_MUL_ASSIGN;
}
| DIV_ASSIGN {
    // /=
    $$ = t_DIV_ASSIGN;
}
| MOD_ASSIGN {
    // %=
    $$ = t_MOD_ASSIGN;
}
| ADD_ASSIGN {
    // +=
    $$ = t_ADD_ASSIGN;
}
| SUB_ASSIGN {
    // -=
    $$ = t_SUB_ASSIGN;
}
| LEFT_ASSIGN {
    // <<=
    $$ = t_LEFT_ASSIGN;
}
| RIGHT_ASSIGN {
    // >>=
    $$ = t_RIGHT_ASSIGN;
}
| AND_ASSIGN {
    // &=
    $$ = t_AND_ASSIGN;
}
| XOR_ASSIGN {
    // ^=
    $$ = t_XOR_ASSIGN;
}
| OR_ASSIGN {
    // |=
    $$ = t_OR_ASSIGN;
}
;

/*表达式*/
expression:
assignment_expression {
    //赋值表达式
    $$ = create_exp_tree(17);
    $$->info.exp_root.next_exp = NULL;
    $$->info.exp_root.assign_exp = $1;
    $$->line = $1->line;
}
| expression ',' assignment_expression {
    //逗号表达式
    $$ = create_exp_tree(17);
    $$->info.exp_root.next_exp = $1;
    $$->info.exp_root.assign_exp = $3;
    $$->line = $3->line;
}
;

constant_expression:
conditional_expression{
    $$ = create_exp_tree(15);
    $$->info.const_info.cond_exp = $1;
    $$->line = $1->line;
}
;

declaration:
type_specifier ';' {
    $$ = create_declaration_tree($1);
}
| type_specifier init_declarator_list ';' {
    $$ = create_declaration_tree($1);
    $$->decl_list = $2;
    $$->line = $2->line;
}
;


init_declarator_list:
init_declarator {
    $$ = $1;
}
| init_declarator_list ',' init_declarator {
    $$ = $1;
    while($1->next != NULL)
    $1 = $1->next;
    $1->next = $3;
}
;

init_declarator:
declarator {
    $$ = $1;
}
| declarator '=' initializer {
    $$ = create_declarator_tree($1,$3);
    $$->line = $1->line;
}
;


/*类型说明符*/
type_specifier:
VOID {
    $$ = t_VOID;
}
| CHAR {
    $$ = t_CHAR;
}
| INT {
    $$ = t_INT;
}
| DOUBLE {
    $$ = t_DOUBLE;
}
| BOOL {
    $$ = t_BOOL;
}
;



declarator:
IDENTIFIER {
    //变量
    $$ = create_declarator_tree(0);
    $$->info.decl_info.detail.ID_info.ID_list = $1;
    $$->line = $1->line;
}
| '(' declarator ')' {
    //.....
    $$ = $2;
}
| declarator '[' constant_expression ']' {
    //数组
    //printf("assignment_expression");
    $$ = create_declarator_tree(1);
    $$->info.decl_info.detail.arr_info.arr_type = arr_C_exp;
    $$->info.decl_info.detail.arr_info.exp = $3;
    $$->info.decl_info.detail.arr_info.decl_tree = $1;
    $$->line = $1->line;
}
| declarator '[' ']' {
    //数组
    $$ = create_declarator_tree(1);
    $$->info.decl_info.detail.arr_info.arr_type = arr_NA;
    $$->info.decl_info.detail.arr_info.exp = NULL;
    $$->info.decl_info.detail.arr_info.decl_tree = $1;
    $$->line = $1->line;
}
| declarator '(' parameter_list ')' {
    //函数
    $$ = create_declarator_tree(2);
    $$->info.decl_info.detail.func_info.func_type = PARAM;
    $$->info.decl_info.detail.func_info.decl_tree = $1;
    $$->info.decl_info.detail.func_info.list.param_list = $3;
    $$->line = $1->line;
}
| declarator '(' identifier_list ')' {
    //函数
    $$ = create_declarator_tree(2);
    $$->info.decl_info.detail.func_info.func_type = IDENT;
    $$->info.decl_info.detail.func_info.decl_tree = $1;
    $$->info.decl_info.detail.func_info.list.ID_list = $3;
    $$->line = $1->line;
}
| declarator '(' ')' {
    //函数
    $$ = create_declarator_tree(2);
    $$->info.decl_info.detail.func_info.func_type = func_NA;
    $$->info.decl_info.detail.func_info.decl_tree = $1;
    $$->info.decl_info.detail.func_info.list.param_list = NULL;
    $$->line = $1->line;
}
;


//参数列表
parameter_list:
parameter_declaration {
    $$ = $1;
}
| parameter_list ',' parameter_declaration {
    $$ = $1;
    while($1->next != NULL)
    $1 = $1->next;
    $1->next = $3;
}
;

parameter_declaration:
type_specifier declarator {
    $$ = create_param_tree($1);
    $$->declarator = $2;
}
| type_specifier {
    $$ = create_param_tree($1);
}
;

identifier_list:
IDENTIFIER {
    $$ = $1;
}
| identifier_list ',' IDENTIFIER {
    $$ = $1;
    while($1->next != NULL)
    $1 = $1->next;
    $1->next = $3;
}
;

//初始化
initializer:
assignment_expression {
    $$ = create_initializer_tree(0);
    $$->info.assign_exp = $1;
}
| '{' initializer_list '}' {
    //列表初始化 {1,1,1}
    $$ = create_initializer_tree(1);
    $$->info.init_list = $2;
}
| '{' initializer_list ',' '}' {//init_list->next
    //列表初始化 {1,1,1,}
    $$ = create_initializer_tree(1);
    $$->info.init_list = $2;
}
;

initializer_list:
initializer {
    $$ = create_initial_list_tree(0);
    $$->initer = $1;
}
| designation initializer {
    $$ = create_initial_list_tree(1);
    $$->initer = $2;
    $$->design_list = $1;
}
| initializer_list ',' initializer {// 在分析时需要判断next == NULL来确定是否到这个list的结尾
    $$ = $1;
    while($1->next != NULL)
    $1 = $1->next;
    $1->next = create_initial_list_tree(0);
    $1->next->initer = $3;
    
}
| initializer_list ',' designation initializer {
    $$ = $1;
    while($1->next != NULL)
    $1 = $1->next;
    $1->next = create_initial_list_tree(1);
    $1->next->initer = $4;
    $1->next->design_list = $3;
}
;

designation:
designator_list '=' {
    $$ = $1;
}
;

designator_list:
designator {
    $$ = $1;
}
| designator_list designator {
    $$ = $1;
    while($1->next != NULL)
    $1=$1->next;
    $1->next = $2;
}
;

designator:
'[' logical_or_expression ']' {
    $$ = create_design_tree(0);
    $$->info.logical_or_exp = $2;
}
| '.' IDENTIFIER {
    $$ = create_design_tree(1);
    $$->info.ID = $2;
}
;

//声明
statement:
labeled_statement {
    $$ = $1;
}
| compound_statement {
    $$ = $1;
}
| expression_statement{
    $$ = $1;
}
| selection_statement {
    $$ = $1;
}
| iteration_statement {
    $$ = $1;
}
| jump_statement {
    $$ = $1;
}
;

//标签声明
labeled_statement:
IDENTIFIER ':' statement {
    $$ = create_stat_tree(0);
    $$->stat_info.label_info.ID = $1;
    $$->stat_info.label_info.exp = NULL;
    $$->stat_info.label_info.stat = $3;
}
| CASE logical_or_expression ':' statement {
    $$ = create_stat_tree(0);
    $$->stat_info.label_info.ID = NULL;
    $$->stat_info.label_info.exp = $2;
    $$->stat_info.label_info.stat = $4;
}
;

//复合语句
compound_statement:
'{' '}' {
    $$ = create_stat_tree(1);
    $$->stat_info.compound_info.type2 = SINGLE;
    $$->stat_info.compound_info.blist = NULL;
}
| '{' block_item_list '}' {
    $$ = create_stat_tree(1);
    $$->stat_info.compound_info.type2 = GROUP;
    $$->stat_info.compound_info.blist = $2;
}
;

block_item_list:
block_item {
    $$ = $1;
    
}
| block_item_list block_item {
    $$ = $1;
    while($1->next != NULL)
    $1 = $1->next;
    $1->next = $2;
}
;

block_item:
declaration {
    $$ = create_block_tree();
    $$->declaration = $1;
}
| statement {
    $$ = create_block_tree();
    $$->statement = $1;
}
;

expression_statement:
';' {
    $$ = create_stat_tree(2);
    $$->stat_info.exp_info.exp = NULL;
}
| expression ';' {
    $$ = create_stat_tree(2);
    $$->stat_info.exp_info.exp = $1;
}
;

//条件语句
selection_statement:
IF '(' expression ')' statement %prec LOWER_THAN_ELSE {
    $$ = create_stat_tree(3);
    $$->stat_info.select_info.type2 = t_IF;
    $$->stat_info.select_info.exp = $3;
    $$->stat_info.select_info.stat1 = $5;
    $$->stat_info.select_info.stat2 = NULL;
}
| IF '(' expression ')' statement ELSE statement {
    $$ = create_stat_tree(3);
    $$->stat_info.select_info.type2 = t_IF_ELSE;
    $$->stat_info.select_info.exp = $3;
    $$->stat_info.select_info.stat1 = $5;
    $$->stat_info.select_info.stat2 = $7;
}
| SWITCH '(' expression ')' statement {
    $$ = create_stat_tree(3);
    $$->stat_info.select_info.type2 = t_SWITCH;
    $$->stat_info.select_info.exp = $3;
    $$->stat_info.select_info.stat1 = $5;
    $$->stat_info.select_info.stat2 = NULL;
}
;

//循环语句
iteration_statement:
WHILE '(' expression ')' statement {
    $$ = create_stat_tree(4);
    $$->stat_info.iter_info.type2 = t_WHILE;
    $$->stat_info.iter_info.exp = $3;
    $$->stat_info.iter_info.stat1 = $5;
    $$->stat_info.iter_info.stat2 = NULL;
    $$->stat_info.iter_info.stat3 = NULL;
    $$->stat_info.iter_info.decl = NULL;
}
| DO statement WHILE '(' expression ')' ';' {
    $$ = create_stat_tree(4);
    $$->stat_info.iter_info.type2 = t_DO_WHILE;
    $$->stat_info.iter_info.exp = $5;
    $$->stat_info.iter_info.stat1 = $2;
    $$->stat_info.iter_info.stat2 = NULL;
    $$->stat_info.iter_info.stat3 = NULL;
    $$->stat_info.iter_info.decl = NULL;
}
| FOR '(' expression_statement expression_statement ')' statement {
    $$ = create_stat_tree(4);
    $$->stat_info.iter_info.type2 = FOR1;
    $$->stat_info.iter_info.exp = NULL;
    $$->stat_info.iter_info.stat1 = $3;
    $$->stat_info.iter_info.stat2 = $4;
    $$->stat_info.iter_info.stat3 = $6;
    $$->stat_info.iter_info.decl = NULL;
}
| FOR '(' expression_statement expression_statement expression ')' statement {
    $$ = create_stat_tree(4);
    $$->stat_info.iter_info.type2 = FOR2;
    $$->stat_info.iter_info.exp = $5;
    $$->stat_info.iter_info.stat1 = $3;
    $$->stat_info.iter_info.stat2 = $4;
    $$->stat_info.iter_info.stat3 = $7;
    $$->stat_info.iter_info.decl = NULL;
}
| FOR '(' declaration expression_statement ')' statement {
    $$ = create_stat_tree(4);
    $$->stat_info.iter_info.type2 = FOR3;
    $$->stat_info.iter_info.exp = NULL;
    $$->stat_info.iter_info.stat1 = $4;
    $$->stat_info.iter_info.stat2 = $6;
    $$->stat_info.iter_info.stat3 = NULL;
    $$->stat_info.iter_info.decl = $3;
}
| FOR '(' declaration expression_statement expression ')' statement {
    $$ = create_stat_tree(4);
    $$->stat_info.iter_info.type2 = FOR4;
    $$->stat_info.iter_info.exp = $5;
    $$->stat_info.iter_info.stat1 = $4;
    $$->stat_info.iter_info.stat2 = $7;
    $$->stat_info.iter_info.stat3 = NULL;
    $$->stat_info.iter_info.decl = $3;
}
;

//跳转指令
jump_statement:
GOTO IDENTIFIER ';' {
    $$ = create_stat_tree(5);
    $$->stat_info.jump_info.type2 = t_GOTO;
    $$->stat_info.jump_info.ID = $2;
    $$->stat_info.jump_info.exp = NULL;
}
| CONTINUE ';' {
    $$ = create_stat_tree(5);
    $$->stat_info.jump_info.type2 = t_CONTINUE;
    $$->stat_info.jump_info.ID = NULL;
    $$->stat_info.jump_info.exp = NULL;
}
| BREAK ';' {
    $$ = create_stat_tree(5);
    $$->stat_info.jump_info.type2 = t_BREAK;
    $$->stat_info.jump_info.ID = NULL;
    $$->stat_info.jump_info.exp = NULL;
}
| RETURN ';' {
    $$ = create_stat_tree(5);
    $$->stat_info.jump_info.type2 = RETURN1;
    $$->stat_info.jump_info.ID = NULL;
    $$->stat_info.jump_info.exp = NULL;
}
| RETURN expression ';' {
    $$ = create_stat_tree(5);
    $$->stat_info.jump_info.type2 = RETURN2;
    $$->stat_info.jump_info.ID = NULL;
    $$->stat_info.jump_info.exp = $2;
}
;

translation_unit:
external_declaration {
    $$ = $1;
}
| translation_unit external_declaration {
    $$ = $1;
    while($1->next != NULL)
    $1 = $1->next;
    $1->next = $2;
}
;

external_declaration:
function_definition {
    $$ = create_root_tree();
    $$->type = Func_T;
    $$->son.func_tree = $1;
    //函数定义
    //printf("function_definition");
}
| declaration {
    $$ = create_root_tree();
    $$->type = Decl_T;
    $$->son.decl_tree = $1;
    //变量声明
    //printf("declaration");
}
;

function_definition:
type_specifier declarator declaration_list compound_statement {
    //这个形式的函数定义好像没有见过，基本用不上
    $$ = create_func_tree($1);
    $$->func_name = $2;
    $$->decl_list = $3;
    $$->stat_list = $4;
    $$->beg_line = $2->line;
    //结束的行数得找一下
}
| type_specifier declarator compound_statement {
    //这个文法对应的函数形式 int func_name(int , int b) {}
    $$ = create_func_tree($1);
    $$->func_name = $2;
    $$->decl_list = NULL;
    $$->stat_list = $3;
    $$->beg_line = $2->line;
    //结束的行数得找一下
}
;

declaration_list:
declaration {
    $$ = $1;
}
| declaration_list declaration {
    $$ = $1;
    while($1->next != NULL)
    $1 = $1->next;
    $1->next = $2;
}
;

%%


void yyerror(char const *s)
{
    fflush(stdout);
    printf("\n%*s\n%*s\n", column, "^", column, s);
}


int main(int argc,char* argv[]) {
    
    yyin = fopen("/Users/egoist/Desktop/test.c","r");
    
    //freopen("output/output.txt","w", stdout);
    yyparse();
    printf("\n");
    //eval(root,0);    //输出语法分析树
    
    parser parser(root);
    
    //freeGramTree(root);
    
    fclose(yyin);
    return 0;
}

