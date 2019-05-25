# Wangyt-s-C-Compiler
# 语法树的构造相关
   词法分析完之后，在构造语法树的时候，思路是整个程序主要分成函数以及声明（全局变量的声明），分别构造两种节点——func_Node& declaration_Node。用root_Node来穿起来每一个func&delcaration.  
   然后再细分，func_Node里面也有declaration,有statment。然后再为这两种节点创建一个数据结构。然后再细分。。。 直到identifier的识别或者表达式的识别。  
   具体的实现可以看代码。  
   然后在写parser的时候，其实每一个节点的type我已经都区分出来了，只要简单的结合compiler.y中的产生式判别出来具体的类型，就可以很好做相应的中间代码生成。  
   现在我在考虑的是error怎么处理
# 最终代码生成
