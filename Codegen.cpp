//
//  Codegen.cpp
//  C_compiler(2)
//
//  Created by egoist on 2019/6/4.
//  Copyright © 2019 egoist. All rights reserved.
//

#include "Codegen.hpp"

codegen::codegen(map<string,message> info){
    regs["t1"]=0; regs["t2"]=0; regs["t3"]=0; regs["t4"]=0; regs["t5"]=0; regs["t6"]=0; regs["t7"]=0; regs["t8"]=0; regs["t9"]=0;
    regs["s0"]=0; regs["s1"]=0; regs["s2"]=0; regs["s3"]=0; regs["s4"]=0; regs["s5"]=0; regs["s6"]=0; regs["s7"]=0;
    this->count_num = info;
    for(map<string,message>::iterator iter = info.begin(); iter != info.end(); iter++)
        variables.push_back(iter->first);
    Generate();
}

string codegen::Get_R(string str){
    string temp="$";
    /*if(variables.find(str) != variables.end())
        variables.erase(str);*/
    for(size_t i = 0; i < variables.size(); i++){
        if(variables[i] == str)
            variables.erase(variables.begin()+i);
    }
    
    if (tables.find(str) != tables.end()){
        return temp+=tables[str];
    }
    else{
        vector<string> keys;
        for(map<string,string>::iterator iter = tables.begin() ; iter != tables.end(); iter++){
            keys.push_back(iter->first);
        }
        for(size_t i = 0; i != keys.size(); i++){
            if((keys[i].find("temp") != string::npos) && inVector(variables, keys[i])){
                regs[tables[keys[i]]]=0;
                tables.erase(keys[i]);
            }
        }
        for(map<string, int>::iterator iter = regs.begin(); iter!=regs.end(); iter++){
            if(iter->second==0){
                tables[str]=iter->first;
                iter->second=1;
                return temp+iter->first;
            }
            
        }
    }
    //如果出现到这行代码说明17个寄存器已经满了，接下来根据最小使用次数替换
    int min_time=100000;
    string name;
    for(map<string,string>::iterator iter = tables.begin(); iter != tables.end(); iter++){
        if(count_num[iter->first].num < min_time){
            min_time = count_num[iter->first].num;
            name = iter->first;
        }
    }
    
    tables[str] = tables[name];
    tables.erase(name);
    
    
    return temp + tables[str];
}

string codegen::translate(vector<string>& line){
    if(line[0]=="LABEL"){
        return line[1]+":";
    }
    if(line[1]==":="){
        if(line.size()==3){
            if(line[line.size()-1][0] =='#'){
                string str="\tli ";
                str+=Get_R(line[0]);
                str+=",";
                str+=line[line.size()-1].replace(line[line.size()-1].find("#"),1,"");
                return str;
            }
            else{
                string str="\tmove ";
                str+=Get_R(line[0]);
                str+=",";
                str+=Get_R(line[2]);
                return str;
            }
        }
        if(line.size()==5){
            if(line[3]=="+"){
                if(line[line.size()-1][0] =='#'){
                    string str="\taddi ";
                    str+=Get_R(line[0]);
                    str+=",";
                    str+=Get_R(line[2]);
                    str+=",";
                    str+=line[line.size()-1].replace(line[line.size()-1].find("#"),1,"");
                    return str;
                }
                else{
                    string str="\tadd ";
                    str+=Get_R(line[0]);
                    str+=",";
                    str+=Get_R(line[2]);
                    str+=",";
                    str+=Get_R(line[line.size()-1]);
                    return str;
                }
            }
            else if(line[3]=="-"){
                if(line[line.size()-1][0] =='#'){
                    string str="\taddi ";
                    str+=Get_R(line[0]);
                    str+=",";
                    str+=Get_R(line[2]);
                    str+=", -";
                    str+=line[line.size()-1].replace(line[line.size()-1].find("#"),1,"");
                    return str;
                }
                else{
                    string str="\tsub ";
                    str+=Get_R(line[0]);
                    str+=",";
                    str+=Get_R(line[2]);
                    str+=",";
                    str+=Get_R(line[line.size()-1]);
                    return str;
                }
            }
            else if(line[3]=="*"){
                string str="\tmul ";
                str+=Get_R(line[0]);
                str+=",";
                str+=Get_R(line[2]);
                str+=",";
                str+=Get_R(line[line.size()-1]);
                return str;
            }
            else if(line[3]=="/"){
                string str="\tdiv ";
                str+=Get_R(line[2]);
                str+=",";
                str+=Get_R(line[line.size()-1]);
                str+="\n\tmflo ";
                str+=Get_R(line[0]);
                return str;
            }
            else if(line[3]=="<"){
                string str="\tslt";
                str+=Get_R(line[0]);
                str+=",";
                str+=Get_R(line[2]);
                str+=",";
                str+=Get_R(line[line.size()-1]);
                return str;
            }
            else if(line[3]==">"){
                string str="\tslt";
                str+=Get_R(line[0]);
                str+=",";
                str+=Get_R(line[line.size()-1]);
                str+=",";
                str+=Get_R(line[2]);
                return str;
            }
        }
        if(line[2]=="CALL"){
            if(line[3]=="read"||line[3]=="print"){
                string str="\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal ";
                str+=line[line.size()-1];
                str+="\n\tlw $ra,0($sp)\n\tmove ";
                str+=Get_R(line[0]);
                str+=",$v0\n\taddi $sp,$sp,4";
                return str;
            }
            else{
                string str="\taddi $sp,$sp,-24\n\tsw $t0,0($sp)\n\tsw $ra,4($sp)\n\tsw $t1,8($sp)\n\tsw $t2,12($sp)\n\tsw $t3,16($sp)\n\tsw $t4,20($sp)\n\tjal ";
                str+=line[line.size()-1];
                str+="\n\tlw $a0,0($sp)\n\tlw $ra,4($sp)\n\tlw $t1,8($sp)\n\tlw $t2,12($sp)\n\tlw $t3,16($sp)\n\tlw $t4,20($sp)\n\taddi $sp,$sp,24\n\tmove ";
                str+=Get_R(line[0]);
                str+=" $v0";
                return str;
            }
        }
    }
    if(line[0]=="GOTO"){
        string str="\tj ";
        str+=line[1];
        return str;
    }
    if(line[0]=="RETURN"){
        string str="\tmove $v0, ";
        str+=Get_R(line[1]);
        str+="\n\tjr $ra";
        return str;
    }
    if(line[0]=="IF"){
        if(line[2]=="=="){
            string str="\tbeq ";
            str+=Get_R(line[1]);
            str+=",";
            str+=Get_R(line[3]);
            str+=",";
            str+=line[line.size()-1];
            return str;
        }
        if(line[2]=="!="){
            string str="\tbne ";
            str+=Get_R(line[1]);
            str+=",";
            str+=Get_R(line[3]);
            str+=",";
            str+=line[line.size()-1];
            return str;
        }
        if(line[2]==">"){
            string str="\tbgt ";
            str+=Get_R(line[1]);
            str+=",";
            str+=Get_R(line[3]);
            str+=",";
            str+=line[line.size()-1];
            return str;
        }
        if(line[2]=="<"){
            string str="\tblt ";
            str+=Get_R(line[1]);
            str+=",";
            str+=Get_R(line[3]);
            str+=",";
            str+=line[line.size()-1];
            return str;
        }
        if(line[2]==">="){
            string str="\tbge ";
            str+=Get_R(line[1]);
            str+=",";
            str+=Get_R(line[3]);
            str+=",";
            str+=line[line.size()-1];
            return str;
        }
        if(line[2]=="<="){
            string str="\tble ";
            str+=Get_R(line[1]);
            str+=",";
            str+=Get_R(line[3]);
            str+=",";
            str+=line[line.size()-1];
            return str;
        }
    }
    if(line[0]=="FUNCTION"){
        return line[1]+":";
    }
    if(line[0]=="CALL"){
        if(line[line.size()-1]=="read"||line[line.size()-1]=="print"){
            string str="\taddi $sp,$sp,-4\n\tsw $ra,0($sp)\n\tjal ";
            str+=line[line.size()-1];
            str+="\n\tlw $ra,0($sp)\n\taddi $sp,$sp,4";
            return str;
        }
        else{
            string str="\taddi $sp,$sp,-24\n\tsw $t0,0($sp)\n\tsw $ra,4($sp)\n\tsw $t1,8($sp)\n\tsw $t2,12($sp)\n\tsw $t3,16($sp)\n\tsw $t4,20($sp)\n\tjal ";
            str+=line[line.size()-1];
            str+="\n\tlw $a0,0($sp)\n\tlw $ra,4($sp)\n\tlw $t1,8($sp)\n\tlw $t2,12($sp)\n\tlw $t3,16($sp)\n\tlw $t4,20($sp)\n\taddi $sp,$sp,24\n\tmove ";
            str+=Get_R(line[0]);
            str+=" $v0";
            return str;
        }
    }
    if(line[0]=="ARG"){
        string str="\tmove $t0,$a0\n\tmove $a0, ";
        str+=Get_R(line[line.size()-1]);
        return str;
    }
    if (line[0]=="PARAM"){
        tables[line[line.size()-1]]="a0";
        return "";
    }
    return "";
}

void codegen::Generate(){
    ifstream in("/Users/egoist/Desktop/source code/C_compiler(2)/DerivedData/C_compiler(2)/Build/Products/Debug/innerCode.txt");
    // istreambuf_iterator<char> beg(in), end;
    //string Inter(beg, end);//鎴栬€卻tring st;st.assign(beg,end);
    string Inter;
    ofstream fout;
    fout.open("result.asm");
    fout<<".data"<<endl;
    fout<<".globl main"<<endl;
    fout<<".text"<<endl;
    fout<<"read:"<<endl;
    fout<<"    li $v0, 4"<<endl;
    fout<<"    la $a0,_prompt"<<endl;
    fout<<"    syscall"<<endl;
    fout<<"    li $v0,5"<<endl;
    fout<<"    syscall"<<endl;
    fout<<"    jr $ra"<<endl;
    fout<<"print:"<<endl;
    fout<<"    li $v0,1"<<endl;
    fout<<"    syscall"<<endl;
    fout<<"    li $v0,4"<<endl;
    fout<<"    la $a0,_ret"<<endl;
    fout<<"    syscall"<<endl;
    fout<<"    move $v0,$0"<<endl;
    fout<<"    jr $ra"<<endl;
    
    
    
    //cout<<inter<<endl;
    //Load_Var(Inter);
    
    string temp;
    string obj_line;
    string feat_onePoint;
    vector<string> line;
    while(getline(in, temp)){
        //cout<<temp<<endl;
        stringstream stringin; //使用串流实现对string的输入输出操作
        stringin.str(temp);
        while (stringin >> feat_onePoint) {      //按空格一次读取一个数据存入feat_onePoint
            line.push_back(feat_onePoint); //存储每行按空格分开的数据
        }
        obj_line=translate(line);
        //if(obj_line=="") continue;
        cout<<obj_line<<endl;
        fout<<obj_line<<endl;
        //cout<<line[0]<<endl;
        line.clear();
    }
    
    return;
    
}

bool codegen::inVector(vector<string> vec, string var){
    for(size_t i = 0; i < variables.size(); i++){
        if(vec[i] == var)
            return true;
    }
    return false;
}
