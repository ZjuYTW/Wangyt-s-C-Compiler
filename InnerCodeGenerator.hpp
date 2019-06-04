//
//  InnerCodeGenerator.hpp
//  C_Compiler
//
//  Created by egoist on 2019/5/26.
//  Copyright © 2019 egoist. All rights reserved.
//

#ifndef InnerCodeGenerator_hpp
#define InnerCodeGenerator_hpp

#include "ast.hpp"
#include "block.hpp"
#include "Optimizer.hpp"
#include "Codegen.hpp"
#include <string>

using namespace std;

class ICG{
private:
    vector<string> codeList;
    
public:
    int tempNum = 0;
    int varNum = 0;
    int labelNum = 0;
    int arrayNum = 0;
    
    ICG();
    void addCode(string code);
    void printCode();
    string createCode(string );
    string createCodeforParam(VarNode);
    string createCodeforRet(VarNode);
    string createCodeforAssign(VarNode, VarNode);
    string createCodeforVar(string, string, VarNode, VarNode);
    string createCodeforArugument(VarNode);
    
    string getLabelname();
    string getNodename(VarNode node);
    string getArrNodename(ArrayNode);
};

#endif /* InnerCodeGenerator_hpp */
