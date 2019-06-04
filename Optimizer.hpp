//
//  Optimizer.hpp
//  C_compiler(2)
//
//  Created by egoist on 2019/6/4.
//  Copyright © 2019 egoist. All rights reserved.
//

#ifndef Optimizer_hpp
#define Optimizer_hpp
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct message{
    int line =-1;
    int num = 0;
};

class Optimizer{
private:
    vector<string> final_innercode;
    void initMap(vector<string>&);
    void dropTemp(vector<string>&);
public:
    Optimizer(vector<string>);
    vector<string> getCode();
    map<string,message> m_map;
    
};

#endif /* Optimizer_hpp */
