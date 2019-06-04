//
//  InnerCodeGenerator.cpp
//  C_Compiler
//
//  Created by egoist on 2019/5/26.
//  Copyright © 2019 egoist. All rights reserved.
//

#include "InnerCodeGenerator.hpp"
#include "tools.hpp"
#include <iostream>
#include <fstream>

ICG::ICG(){
    
}

void ICG::addCode(string code){
    codeList.push_back(code);
}

void ICG::printCode(){
    Optimizer op(codeList);
    codeList = op.getCode();
    
    ofstream fout("innerCode.txt");
    cout << "\n===============INNERCODE===================" <<endl;
    for(vector<string>::iterator iter=codeList.begin(); iter != codeList.end(); iter++){
        cout<< *iter <<"\n";
        fout<< *iter <<"\n";
    }
    fout.close();
    codegen cg(op.m_map);
}

string ICG::createCodeforVar(string tempname, string op, VarNode node1, VarNode node2){
    string result = tempname + " := ";
    if(node1.useAddress)
        result += "*" +node1.name;
    else{
        if (node1.num < 0)
            result += node1.num;
        else
            result += "var" + inttostr(node1.num);
    }
    
    result += " " + op + " ";
    
    if(node2.useAddress){
        result += "*" +node2.name;
    }
    else{
        if(node2.num < 0)
            result += node2.name;
        else
            result += "var" + inttostr(node2.num);
    }
    
    return result;
}

string ICG::createCodeforAssign(VarNode node1, VarNode node2){
    string result;
    if(node1.useAddress)
        result = "*" + node1.name + " := ";
    else{
        result = "var" + inttostr(node1.num);
        result += " := ";
    }
    
    if(node2.useAddress)
        result += "*" +node2.name;
    else{
        if(node2.num < 0)
            result += node2.name;
        else
            result += "var" + inttostr(node2.num);
    }
    return result;
}

string ICG::createCodeforParam(VarNode node){
    string result = "PARAM ";
    result += "var" + inttostr(node.num);
    return result;
    
}

string ICG::createCodeforRet(VarNode node){
    string result = "RETURN ";
    if(node.useAddress)
        result += "*" + node.name;
    else{
        if(node.num < 0)
            result += node.name;
        else
            result += "var" + inttostr(node.num);
    }
    return result;
}

string ICG::createCodeforArugument(VarNode node){
    string result = "ARG ";
    if(node.useAddress)
    result += "*" + node.name;
    else{
        if(node.num < 0)
            result += node.name;
        else
            result += "var" + inttostr(node.num);
    }
    return result;
}

string ICG::getNodename(VarNode node){
    if(node.useAddress)
        return "*" + node.name;
    else{
        if(node.num < 0)
            return node.name;
        else
            return ("var" + inttostr(node.num));
    }
}

string ICG::getArrNodename(ArrayNode node){
    return ("array" + inttostr(node.num));
}

string ICG::getLabelname(){
    return ("label" + inttostr(labelNum++));
}



