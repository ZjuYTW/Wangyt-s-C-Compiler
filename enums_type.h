//
//  enums_type.h
//  C_Compiler
//
//  Created by egoist on 2019/5/28.
//  Copyright © 2019 egoist. All rights reserved.
//

#ifndef enums_type_h
#define enums_type_h
/*这个枚举类型应用在root_Node上（只用到Func_T,Decl_T,NA）
 */
enum root_kind {Func_T,Decl_T,Stat_T,root_NA};//root_NA表示不属于前几类

enum type_specifier_kind {t_VOID,t_CHAR,t_INT,t_DOUBLE,t_BOOL};

enum declarator_kind {DECL,INITED};

enum declarator_kind2 {Identifier,ARRAY,FUNC};

enum decl_arr_kind {ASSIGN_EXP,STAR,arr_NA};

enum decl_func_kind {PARAM,IDENT,func_NA};

enum list_kind {SINGLE,GROUP}; //这个枚举类型用在initial_Node与initial_list上面，表示到底是一个赋值还是多个赋值，具体的应用可以看结构体内部的注释

enum designator_kind {ARRAY_INDEX,MEMBER};

enum stat_kind {LABEL,COMPOUND,EXP,SELECT,ITER,JUMP};

enum select_kind {t_IF,t_IF_ELSE,t_SWITCH};

/*FOR1是括号内有两个exp_stat，例如 for(i=0;i<10;)
 FOR2是两个exp_stat后面还有一个exp eg.for(i=0;i<10;i++)
 FOR3是第一个是decl,第二个是exp，eg.for(int i=0;i<10)
 FOR4是三个句子，类比上面的。。
 */
enum iter_kind {t_WHILE,t_DO_WHILE,FOR1,FOR2,FOR3,FOR4};

enum jump_kind {t_GOTO,t_CONTINUE,t_BREAK,RETURN1,RETURN2};

enum exp_kind {PRIM,POST,ASSIG,Logcial_OR,Logcial_AND,IOR,XOR,AND,EQUAL,RELAT,SHIFT,ADD,MUL,UNARY,ARUG,exp_NA};

enum prim_kind {ID,t_TRUE,t_FALSE,CONSTAN_INT,t_CONSTANT_DOUBLE,prim_NA};

enum postfix_kind {ARRAY_CALL,FUNC_CALL,INC,DEC,post_NA};

enum assign_kind {t_ASSIGNMENT,t_MUL_ASSIGN,t_DIV_ASSIGN,t_MOD_ASSIGN,t_ADD_ASSIGN,t_SUB_ASSIGN,t_LEFT_ASSIGN,t_RIGHT_ASSIGN,t_AND_ASSIGN,t_XOR_ASSIGN,t_OR_ASSIGN,assign_NA};

enum equal_kind {EQ,NE,equal_NA};

enum relation_kind {LES,GT,LE,GE,relation_NA};//为了区分每一个NA，给NA编了一个号

enum shift_kind {LEFT,RIGHT,shift_NA};

enum add_kind {ADD_OP,MINUS_OP,add_NA};

enum mul_kind {MUL_OP,DIV_OP,MOD,mul_NA};

enum unary_kind {t_INC_OP,t_DEC_OP,POS,NEG,BIT_NEG,FEI,unary_NA};//按位取反 ~, 非 !

#endif /* enums_type_h */
