//
//  Optimizer.cpp
//  C_compiler(2)
//
//  Created by egoist on 2019/6/4.
//  Copyright © 2019 egoist. All rights reserved.
//

#include "Optimizer.hpp"

Optimizer::Optimizer(vector<string> origin_code){
    initMap(origin_code);
    dropTemp(origin_code);
}

void Optimizer::initMap(vector<string>& code){
    for(size_t i = 0; i < code.size(); i++){
        string code_l = code[i];
        size_t begin = 0;
        size_t index = code_l.find("temp", begin);
        while(index != string::npos){
            size_t end = code_l.find(" ", index);
            string name = code_l.substr(index, end - index);
            
            if(m_map.find(name) != m_map.end()){
                if(code_l.find("CALL") != string::npos)
                    m_map[name].num += 1000;
                m_map[name].num++;
            }
            else{
                message temp;
                temp.line = (int)i;
                temp.num = 1;
                if(code_l.find("CALL") != string::npos)
                    temp.num += 1000;
                m_map.insert({name, temp});
            }
            begin = end;
            index = code_l.find("temp", begin);
        }
    }
}

//一个简单的代码优化策略，仅仅将没有用过的temp给删去
void Optimizer::dropTemp(vector<string>& ori_code){
    set<int> lines;
    for(map<string,message>::iterator iter= m_map.begin(); iter!= m_map.end(); iter++){
        if(iter->second.num == 1){
            int line = iter->second.line;
            lines.insert(line);
        }
    }
    
    for(int i = 0; i < ori_code.size(); i++)
        if(lines.find(i) == lines.end())
            this->final_innercode.push_back(ori_code[i]);
}

vector<string> Optimizer::getCode(){
    return this->final_innercode;
}
