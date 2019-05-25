#ifndef ast_hpp
#define ast_hpp
#include <stdio.h>
#include <string>

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


/*这个枚举类型应用在root_Node上（只用到Func_T,Decl_T,NA）
 */
enum root_kind {Func_T,Decl_T,Stat_T,root_NA};//root_NA表示不属于前几类

enum type_specifier_kind {VOID,CHAR,INT,DOUBLE,BOOL};

enum declarator_kind {DECL,INITED};

enum declarator_kind2 {Identifier,ARRAY,FUNC};

enum decl_arr_kind {ASSIG_EXP,STAR,arr_NA};

enum decl_func_kind {PARAM,IDENT,func_NA};

enum list_kind {SINGLE,GROUP}; //这个枚举类型用在initial_Node与initial_list上面，表示到底是一个赋值还是多个赋值，具体的应用可以看结构体内部的注释

enum designator_kind {ARRAY_INDEX,MEMBER};

enum stat_kind {LABEL,COMPOUND,EXP,SELECT,ITER,JUMP};

enum select_kind {IF,IF_ELSE,SWITCH};

/*FOR1是括号内有两个exp_stat，例如 for(i=0;i<10;)
 FOR2是两个exp_stat后面还有一个exp eg.for(i=0;i<10;i++)
 FOR3是第一个是decl,第二个是exp，eg.for(int i=0;i<10)
 FOR4是三个句子，类比上面的。。
 */
enum iter_kind {WHILE,DO_WHILE,FOR1,FOR2,FOR3,FOR4};

enum jump_kind {GOTO,CONTINUE,BREAK,RETURN1,RETURN2};

enum exp_kind {PRIM,POST,ASSIG,Logcial_OR,Logcial_AND,IOR,XOR,AND,EQUAL,RELAT,SHIFT,ADD,MUL,UNARY,ARUG,exp_NA};

enum prim_kind {ID,TRUE,FALSE,CONSTAN_INT,CONSTANT_DOUBLE,prim_NA};

enum postfix_kind {ARRAY_CALL,FUNC_CALL,INC,DEC,post_NA};

enum assign_kind {ASSIGNMENT,MUL_ASSIGN,DIV_ASSIGN,MOD_ASSIGN,ADD_ASSIGN,SUB_ASSIGN,LEFT_ASSIGN,RIGHT_ASSIGN,AND_ASSIGN,XOR_ASSIGN,OR_ASSIGN,assign_NA};

enum equal_kind {EQ,NE,equal_NA};

enum relation_kind {LES,GT,LE,GE,relation_NA};//为了区分每一个NA，给NA编了一个号

enum shift_kind {LEFT,RIGHT,shift_NA};

enum add_kind {ADD_OP,MINUS_OP,add_NA};

enum mul_kind {MUL_OP,DIV_OP,MOD,mul_NA};

enum unary_kind {INC_OP,DEC_OP,POS,NEG,BIT_NEG,FEI,unary_NA};//按位取反 ~, 非 !


struct root_Node{//整个大类上分为声明以及函数节点
    root_kind type;//{Func_T,Decl_T,Stat_T,root_NA};
    union{
        struct func_Node* func_tree;
        struct decl_Node* decl_tree;
    }son;
    root_Node *next;
};

struct func_Node{
    type_specifier_kind type;//{VOID,CHAR,INT,DOUBLE,BOOL}
    
    struct declarator_Node *func_name;
    struct declaration_Node *decl_list;//参数列表
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
    
    //每一个句子之间的连接
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
                    decl_arr_kind arr_type;//{ASSIG_EXP,STAR,arr_NA}
                    struct exp_Node* assig_exp;
                    struct declarator_Node* decl_tree;
                }arr_info;
                struct{
                    decl_func_kind func_type;//{PARAM,IDENT,func_NA}
                    struct declarator_Node* decl_tree;
                    union{
                        struct param_Node* param_list;
                        struct declarator_Node* ID_list;
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
        struct exp_Node* assig_exp;
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
            struct exp_Node* stat2;
            struct exp_Node* stat3;
            struct decl_Node* decl;
        }iter_info;
        
        struct{
            jump_kind type2;//{GOTO,CONTINUE,BREAK,RETURN1,RETURN2};
            ID_Node *ID;
            struct exp_Node* exp;
        }jump_info;
    }stat_info;
    
};

struct block_item{
    struct decl_Node *declaration;
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
            union{
                string val;//除了ID以外的信息存在val中
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
            struct exp_Node* unary_exp;//如果是logical_or_exp的规约（也就是type2为assign_NA），就去unary_exp中找
            struct exp_Node* assign_exp;
            assign_kind type2;//{ASSIGNMENT,MUL_ASSIGN,DIV_ASSIGN,MOD_ASSIGN,ADD_ASSIGN,SUB_ASSIGN,LEFT_ASSIGN,RIGHT_ASSIGN,AND_ASSIGN,XOR_ASSIGN,OR_ASSIGN,assign_NA}
        }assig_info;
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
    }info;
    int line;
};
#endif /* ast_hpp */
