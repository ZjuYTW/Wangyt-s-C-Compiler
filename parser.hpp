#ifndef parser_hpp
#define parser_hpp
#include "ast.hpp"
#include "block.hpp"
#include "InnerCodeGenerator.hpp"
#include <vector>
#include <iostream>


using namespace std;

class parser{
public:
    parser(root_Node*);
    ~parser();
    
private:
    struct root_Node* root;
    map<string, funcNode> funcPool;
    vector<block> stack;
    
    void parserInit();
    void parse(root_Node*);
    void printCode();
    void parseFunc(func_Node*);
    void parseDecl(declaration_Node*);
    
};

#endif /* parser_hpp */
