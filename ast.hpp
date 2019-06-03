#ifndef ast_hpp
#define ast_hpp
#include <stdio.h>
#include <string>
#include "y.tab.hpp"
#include "enums_type.hpp"

using namespace std;
/*一共有五种tree_Node
  root_node ☑️
  func_node ☑️
  declaration_node ☑️
  declarator_Node
  init_Node
  stat_node ☑️
  exp_node ☑️
  ID_node
 
 */


struct root_Node{//整个大类上分为声明以及函数节点
    root_kind type;//{Func_T,Decl_T,Stat_T,root_NA};
    union{
        struct func_Node* func_tree;
        struct declaration_Node* decl_tree;
    }son;
    root_Node *next;
};

struct func_Node{
    type_specifier_kind type;//{VOID,CHAR,INT,DOUBLE,BOOL}
    
    struct declarator_Node *func_name;//所有的参数记在这里
    struct declaration_Node *decl_list;//这个节点的作用不知道，文法中要求我就加了一个
    struct stat_Node* stat_list;//语句
    
    int beg_line;
    int end_line;
};

struct ID_Node{
    string name;
    ID_Node* next;
    int line;
    //可能还有表征这个ID属于哪里的一些别的属性，想起来的时候再添加
};

struct declaration_Node{//declaration_Node
    type_specifier_kind type;//{VOID,CHAR,INT,DOUBLE,BOOL}
    struct declarator_Node* decl_list;
    
    //declaration_list中会用到next，基本不会考虑这个。。。
    struct declaration_Node* next;
    int line;
};


struct declarator_Node{
    declarator_kind type;//{DECL,INITED};
    //有些忘了NA是做啥的了。。。，想起来记得注释
    union{
        struct{//if type == DECL
            declarator_kind2 type2;//{Identifier,ARRAY,FUNC}
            union{
                struct{
                    struct ID_Node* ID_list;
                }ID_info;
                struct{
                    decl_arr_kind arr_type;//{arr_C_exp,arr_NA}
                    struct exp_Node* exp;
                    struct declarator_Node* decl_tree;
                }arr_info;
                struct{
                    decl_func_kind func_type;//{PARAM,IDENT,func_NA}
                    struct declarator_Node* decl_tree;
                    union{
                        struct param_Node* param_list;
                        struct ID_Node* ID_list;
                    }list;
                }func_info;
            }detail;
        }decl_info;
        
        struct{//if type == INITED
            struct declarator_Node* decl_tree;
            struct initializer_Node* initalizer;
        }init_info;
    }info;
    int line;
    
    declarator_Node* next;//做成list形式
};

struct initializer_Node{
    list_kind type;//也就是单独一个赋值语句或者用列表赋值
    union{
        struct exp_Node* assign_exp;
        struct initial_list* init_list;
    }info;
};

struct initial_list{
    list_kind type;//SINGLE表示只有一个initializer,GROUP表示还有一个designation在产生式文法中
    struct initializer_Node* initer;
    struct designator* design_list;
    struct initial_list* next;
};

struct designator{
    designator_kind type;//{ARRAY_INDEX,MEMBER};
    union{
        ID_Node *ID;
        struct exp_Node* logical_or_exp;
    }info;
    designator *next;
};

struct param_Node{
    type_specifier_kind type;//{VOID,CHAR,INT,DOUBLE,BOOL}
    struct declarator_Node* declarator;
    struct param_Node* next;
};

struct stat_Node{
    stat_kind type;//{LABEL,COMPOUND,EXP,SELECT,ITER,JUMP}
    
    union{
        struct{
            ID_Node *ID;
            struct exp_Node* exp;
            struct stat_Node* stat;
        } label_info;
        
        struct{
            list_kind type2;//SINGLE 为空，GROUP 为block_item_list
            struct block_item *blist;
        }compound_info;
        
        struct{
            exp_Node *exp;
        }exp_info;
        
        struct{
            select_kind type2;//{IF,IF_ELSE,SWITCH};
            struct exp_Node* exp;
            struct stat_Node* stat1;
            struct stat_Node* stat2;
        } select_info;
        
        struct{
            iter_kind type2;//{WHILE,DO_WHILE,FOR1,FOR2,FOR3,FOR4};
            struct exp_Node* exp;
            struct stat_Node* stat1;
            struct stat_Node* stat2;
            struct stat_Node* stat3;
            struct declaration_Node* decl;
        }iter_info;
        
        struct{
            jump_kind type2;//{GOTO,CONTINUE,BREAK,RETURN1,RETURN2};
            ID_Node *ID;
            struct exp_Node* exp;
        }jump_info;
    }stat_info;
    int line;
};

struct block_item{
    struct declaration_Node *declaration;
    struct stat_Node *statement;
    struct block_item *next;
};


struct exp_Node{
    exp_kind type;//{PRIM,POST,ASSIG,Logcial_OR,Logcial_AND,IOR,XOR,AND,EQUAL,RELAT,SHIFT,ADD,MUL,UNARY,ARUG,EXP}
    union{
        struct{
            struct exp_Node* next_exp;
            struct exp_Node* assign_exp;
        }exp_root;
        struct{
            prim_kind type2;//{ID,TRUE,FALSE,CONSTAN_INT,CONSTANT_DOUBLE,prim_NA}
            struct{
                char* val;//除了ID以外的信息存在val中
                ID_Node* ID;
                struct exp_Node *exp;
            }detail;
        }prim_info;
        struct{
            postfix_kind type2;//{ARRAY_CALL,FUNC_CALL,INC,DEC,post_NA}
            struct exp_Node* post_exp;
            struct exp_Node* arg_list;//也可以用作连接一个prim_exp的指针
        }post_info;
        struct{
            struct exp_Node* unary_exp;//如果是conditional_expression的规约（也就是type2为assign_NA），就去unary_exp中找
            struct exp_Node* assign_exp;
            assign_kind type2;//{ASSIGNMENT,MUL_ASSIGN,DIV_ASSIGN,MOD_ASSIGN,ADD_ASSIGN,SUB_ASSIGN,LEFT_ASSIGN,RIGHT_ASSIGN,AND_ASSIGN,XOR_ASSIGN,OR_ASSIGN,assign_NA}
        }assign_info;
        struct{
            struct exp_Node* logical_or_exp;
            struct exp_Node* logical_and_exp;
        }logi_or_info;
        struct{
            struct exp_Node* logical_and_exp;
            struct exp_Node* inclusive_or_exp;
        }logi_and_info;
        struct{
            struct exp_Node* inclusive_or_exp;
            struct exp_Node* exclusive_or_exp;
        }incl_or_info;
        struct{
            struct exp_Node* exclusive_or_exp;
            struct exp_Node* and_exp;
        }excl_or_info;
        struct{
            struct exp_Node* and_exp;
            struct exp_Node* equal_exp;
        }and_info;
        struct{
            equal_kind type2;//{EQ,NE,equal_NA}
            struct exp_Node* equal_exp;
            struct exp_Node* relation_exp;
        }equal_info;
        struct{
            relation_kind type2;//{LES,GT,LE,GE,relation_NA}
            struct exp_Node* relation_exp;
            struct exp_Node* shift_exp;
        }rela_info;
        struct{
            shift_kind type2;//{LEFT,RIGHT,shift_NA};  LEFT = <<  RIGHT = >>
            struct exp_Node* shift_exp;
            struct exp_Node* addtive_exp;
        }shift_info;
        struct{
            add_kind type2;//{ADD_OP,MINUS_OP,add_NA}
            struct exp_Node* add_exp;
            struct exp_Node* mul_exp;
        }add_info;
        struct{
            mul_kind type2;//{MUL_OP,DIV_OP,MOD,mul_NA}
            struct exp_Node* unary_exp;
            struct exp_Node* mul_exp;
        }mul_info;
        struct{
            unary_kind type2;//按位取反 ~, 非 !  {INC_OP,DEC_OP,POS,NEG,BIT_NEG,FEI,unary_NA}
            struct exp_Node* post_exp;
            struct exp_Node* unary_exp;
        }unary_info;
        struct{
            list_kind type2;//list or single
            struct exp_Node* argu_exp;
            struct exp_Node* assig_exp;
        }argument_info;
        struct{
            struct exp_Node *cond_exp;
        }const_info;
        struct{
            struct exp_Node *logical_or_exp;
            struct exp_Node *exp;
            struct exp_Node *cond_exp;
        }cond_info;
    }info;
    int line;
};


ID_Node* create_ID(int linenum);
exp_Node* create_exp_tree(int linenum,int type);
exp_Node* create_exp_tree(int type);
root_Node* create_root();
declaration_Node* create_declaration_tree(type_specifier_kind type);
declarator_Node* create_declarator_tree(declarator_Node* decl_list, initializer_Node* init);
declarator_Node* create_declarator_tree(int type);
param_Node* create_param_tree(enum type_specifier_kind type);
initializer_Node* create_initializer_tree(int type);
initial_list* create_initial_list_tree(int type);
designator* create_design_tree(int type);
stat_Node* create_stat_tree(int type);
block_item *create_block_tree();
root_Node *create_root_tree(void);
func_Node *create_func_tree(type_specifier_kind type);
#endif /* ast_hpp */
