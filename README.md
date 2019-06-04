# 类C语言编译器
通过lex以及yacc生成的类c语言编译器。  
暂时没有实现struct,指针以及数组（这个有中间代码了）  
 词法分析以及语法分析参考了 http://www.quut.com/c/ANSI-C-grammar-l-1998.html 和 http://www.quut.com/c/ANSI-C-grammar-y-1995.html  
 水平太差没有做UI界面  （鹅颈不过鹅颈不过）  

# 使用说明

## 运行环境
flex  
bison  
g++  

### 运行

flex lexical.l
bison -vdty grammar.y  
g++ -std=c++11 -o compiler ast.cpp block.cpp InnerCodeGenerator.cpp lex.yy.cpp parser.cpp tools.cpp Optimizer.cpp y.tab.cpp Codegen.cpp    
然后本人暂时太懒了全用的是绝对地址，等做展示了再改吧。。。

# 中间代码格式定义
（这里我仿照@Uyouii c编译器的中间代码格式写的，这里实在不好意思了。。  

| 语法  | 描述 |
| :---: | :---- |
| LABEL label1 : | 定义标签 label1  |
| FUNCTION f :  | 定义函数 f  | 
| x := y | 赋值操作，将变量 y 赋值给 x | 
| x := &y |  取地址操作，将 y 的地址赋值给 x | 
| x := *y | 取以 y 值为地址的内存单元的内容赋给 x | 
| *x := y | 将 y 值赋给以 x 值为地址的内存单元 | 
| GOTO label1| 无条件跳转至 lable1 | 
| IF x [relop] y GOTO z | 如果 x 与 y 满足[relop]关系则跳转至标号 z | 
| RETURN x | 退出当前函数并返回 x 值 | 
| DEC x [size] | 内存空间申请，大小为[size] | 
| ARG x | 为函数传入实参 x | 
| x := CALL f | 调用函数 f，并将其返回值赋给 x | 
| CALL f | 调用函数 f | 
| PARAM x | 函数形参声明 | 
| x := y [op] z | 将变量 y 和 z 进行 op 运算的结果传递给 x | 
| x := #10 | 将立即数 10 的值传递给变量 x | 

## 示例
🈚️