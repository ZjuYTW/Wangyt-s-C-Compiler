//
//  InnerCodeGenerator.cpp
//  C_Compiler
//
//  Created by egoist on 2019/5/26.
//  Copyright © 2019 egoist. All rights reserved.
//

#include "InnerCodeGenerator.hpp"
#include <iostream>
#include <fstream>

ICG::ICG(){
    
}

void ICG::addCode(string code){
    codeList.push_back(code);
}

void ICG::printCode(){
    //代码优化部分
    
    ofstream fout("innerCode.txt");
    cout << "\n===============INNERCODE===================" <<endl;
    for(vector<string>::iterator iter=codeList.begin(); iter != codeList.end(); iter++){
        cout<< *iter <<"\n";
        fout<< *iter <<"\n";
    }
}


