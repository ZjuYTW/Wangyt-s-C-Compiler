//
//  Codegen.hpp
//  C_compiler(2)
//
//  Created by egoist on 2019/6/4.
//  Copyright © 2019 egoist. All rights reserved.
//

#ifndef Codegen_hpp
#define Codegen_hpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <set>
#include "Optimizer.hpp"

using namespace std;

class codegen{
public:
    codegen(map<string,message>);
    map<string, message> count_num;//string var_name, message 
    map<string, int> regs;
    map<string, string> tables;
    vector<string> variables;
private:
    string Get_R(string str);
    string translate(vector<string>& line);
    void Generate();
    bool inVector(vector<string>, string);
};
#endif /* Codegen_hpp */
