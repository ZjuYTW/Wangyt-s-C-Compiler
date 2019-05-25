#include "ast.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;

extern char *yytext;

ID_Node* create_ID(int linenum){
    ID_Node* temp = (ID_Node*)malloc(sizeof(ID_Node));
    temp->name = yytext;
    temp->next = NULL;
    temp->line = linenum;
    return temp;
}

exp_Node* create_exp_tree(int linenum,int type){//创建exp_Node中prim类型的节点
    exp_Node* temp = (exp_Node*)malloc(sizeof(exp_Node));
    temp->type = PRIM;
    switch (type) {
        case 0://ID
            temp->info.prim_info.type2 = ID;
            temp->info.prim_info.detail.val = "";
            //在返回后需要手动把ID连上去，也可能到时候再单独写一个函数
            break;
        case 1://TRUE
            temp->info.prim_info.type2 = TRUE;
            temp->info.prim_info.detail.val = "";
        case 2://FASLE
            temp->info.prim_info.type2 = FALSE;
            temp->info.prim_info.detail.val = "";
        case 3://CONSTANT_INT
            temp->info.prim_info.type2 = CONSTAN_INT;
            int value;
            if(strlen(yytext) > 1 && yytext[0] == '0' && yytext[1] != 'x')//如果是8进制的数
                sscanf(yytext, "%o",&value);
            else if(strlen(yytext) > 1 && (yytext[1] == 'x' || yytext[1] == 'X'))//如果是16进制的数
                sscanf(yytext,"%x", &value);
            else//否则10进制
                value = atoi(yytext);
            temp->info.prim_info.detail.val=to_string(value);
            break;
        case 4://CONSTANT_DOUBLE
            temp->info.prim_info.type2 = CONSTANT_DOUBLE;
            temp->info.prim_info.detail.val = yytext;
        case 5://prim_NA
            temp->info.prim_info.type2 = prim_NA;
            temp->info.prim_info.detail.val = "";
            break;
        default:
            return NULL;
    }
    temp->info.prim_info.detail.exp=NULL;
    temp->info.prim_info.detail.ID=NULL;
    temp->line=linenum;
    return temp;
}

exp_Node* create_exp_tree(int type){
    exp_Node* temp=(exp_Node*)malloc(sizeof(exp_Node));
    temp->info.prim_info.detail.val = "";
    temp->info.prim_info.detail.ID = NULL;
    temp->info.prim_info.detail.exp = NULL;
    temp->info.post_info.arg_list = NULL;
    temp->info.assig_info.unary_exp = NULL;
    temp->info.assig_info.assign_exp = NULL;
    temp->info.logi_or_info.logical_or_exp = NULL;
    temp->info.logi_and_info.logical_and_exp = NULL;
    
    
    switch (type) {
        case 0:
            temp->type = PRIM;
            break;
        case 1:
            temp->type = POST;
            break;
        case 2:
            temp->type = ASSIG;
            break;
        case 3:
            temp->type = Logcial_OR;
            break;
        case 4:
            temp->type = Logcial_AND;
            break;
        case 5:
            temp->type = IOR;
            break;
        case 6:
            temp->type = XOR;
            break;
        case 7:
            temp->type = AND;
            break;
        case 8:
            temp->type = EQUAL;
            break;
        case 9:
            temp->type = RELAT;
            break;
        case 10:
            temp->type = SHIFT;
            break;
        case 11:
            temp->type = ADD;
            break;
        case 12:
            temp->type = MUL;
            break;
        case 13:
            temp->type = UNARY;
            break;
        case 14:
            temp->type = ARUG;
            break;
        case 15:
            temp->type = exp_NA;
        default:
            return NULL;
    }
    return temp;
}



root_Node* create_root(){
    root_Node* temp = (root_Node*)malloc(sizeof(root_Node));
    temp->type = root_NA;
    temp->son.func_tree = NULL;
    temp->son.decl_tree = NULL;
    return temp;
}

declaration_Node* create_declration_tree(type_specifier_kind type){
    declaration_Node* temp = (declaration_Node*)malloc(sizeof(declaration_Node));
    temp->type = type;
    temp->decl_list = NULL;
    temp->line = -1;
    temp->next = NULL;
    return temp;
}

declarator_Node* create_declarator_tree(declarator_Node* decl_list, initializer_Node* init){//只用来生成INITED的节点
    declarator_Node *temp = (declarator_Node*)malloc(sizeof(declarator_kind));
    temp->type = INITED;
    temp->next = NULL;
    temp->info.init_info.decl_tree = decl_list;
    temp->info.init_info.initalizer = init;
    
    return temp;
}

declarator_Node* create_declarator_tree(int type){//用来生成DECL类型的节点
    declarator_Node *temp = (declarator_Node*)malloc(sizeof(declarator_Node));
    temp->type = DECL;
    switch (type) {
        case 0:
            temp->info.decl_info.type2 = Identifier;
            break;
        case 1:
            temp->info.decl_info.type2 = ARRAY;
            break;
        case 2:
            temp->info.decl_info.type2 = FUNC;
            break;
        default:
            return NULL;
    }
    temp->next = NULL;
    temp->line = -1;
    return temp;
}

param_Node* create_param_tree(enum type_specifier_kind type){
    param_Node *temp = (param_Node*)malloc(sizeof(param_Node));
    temp->type = type;
    temp->declarator = NULL;
    temp->next = NULL;
    return temp;
}

initializer_Node* create_initializer_tree(int type){
    initializer_Node *temp = (initializer_Node*)malloc(sizeof(initializer_Node));
    switch (type) {
        case 0:
            temp->type = SINGLE;
            break;
        case 1:
            temp->type = GROUP;
        default:
            return NULL;
    }
    temp->info.assig_exp = NULL;
    return temp;
}

initial_list* create_initial_list_tree(int type){
    initial_list *temp = (initial_list*)malloc(sizeof(initial_list));
    switch (type) {
        case 0:
            temp->type = SINGLE;
            break;
        case 1:
            temp->type = GROUP;
            break;
        default:
            return NULL;
    }
    temp->initer = NULL;
    temp->next = NULL;
    temp->design_list = NULL;
    return temp;
}

designator* create_design_tree(int type){
    designator *temp = (designator*)malloc(sizeof(designator));
    switch (type) {
        case 0://数组
            temp->type = ARRAY_INDEX;
            break;
        case 1:
            temp->type = MEMBER;
            break;
        default:
            return NULL;
    }
    temp->info.logical_or_exp = NULL;
    temp->info.ID = NULL;
    temp->next = NULL;
    return temp;
}

stat_Node* create_stat_tree(int type){
    stat_Node *temp = (stat_Node*)malloc(sizeof(stat_Node));
    switch (type) {
        case 0:
            temp->type = LABEL;
            break;
        case 1:
            temp->type = EXP;
            break;
        case 2:
            temp->type = SELECT;
            break;
        case 3:
            temp->type = ITER;
            break;
        case 4:
            temp->type =JUMP;
            break;
        default:
            return NULL;
    }
    return temp;
}

block_item *create_block_tree(){
    block_item *temp = (block_item*)malloc(sizeof(block_item));
    temp->declaration = NULL;
    temp->statement = NULL;
    temp->next = NULL;
    return temp;
}

root_Node *create_root_tree(void){
    root_Node *temp = (root_Node*)malloc(sizeof(root_Node));
    temp->next = NULL;
    return temp;
}

func_Node *create_func_tree(type_specifier_kind type){
    func_Node *temp = (func_Node*)malloc(sizeof(func_Node));
    temp->type = type;
    temp->func_name = NULL;
    temp->decl_list = NULL;
    temp->stat_list = NULL;
    temp->beg_line = 0;
    temp->end_line = 0;
    return temp;
}


