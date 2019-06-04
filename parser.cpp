#include "parser.hpp"
#include <string>

//*******************************************Initial part***********************************************
parser::parser(root_Node* root){
    this->root = root;
    parserInit();
}

parser::~parser(){
    printCode();
}

void parser::parserInit(){
    block wholeBlock;
    stack.push_back(wholeBlock);
    
    parse(root);
}
//******************************************************************************************************

//************************************最高级部分的PARSE********************************************************

//*******************************************Parse**************************************************
void parser::parse(root_Node* rNode){
    if(rNode == NULL)
        return;
    root_kind cur_kind = rNode->type;
    switch (cur_kind) {
        case Func_T:
            parseFunc(rNode->son.func_tree);
            break;
        case Decl_T:
            parseDecl(rNode->son.decl_tree);
            break;
        default:
            cout << "Not the expected Function or Declaration type" <<endl;
            return;
    }
    parse(rNode->next);
}
//******************************************************************************************************

//**************************************二级单元PARSE******************************************************
//*******************************parse function& function decl********************************************
void parser::parseFunc(func_Node* fNode){
    type_specifier_kind cur_type = fNode->type;
    declarator_Node *func_declarator = fNode->func_name;
    param_Node *param_list = func_declarator->info.decl_info.detail.func_info.list.param_list;
    
    if(fNode->decl_list != NULL){
        error(fNode->beg_line, "一个未知语法发生了!");
    }
    
    if(func_declarator->next != NULL){
        error(fNode->beg_line, "Function should have just one name!");
    }
    else if(func_declarator->info.decl_info.type2 != FUNC){
        error(fNode->beg_line, "Check the function definition!");
    }
    else if(func_declarator->info.decl_info.detail.func_info.func_type != PARAM && func_declarator->info.decl_info.detail.func_info.func_type != func_NA ){
        error(fNode->beg_line,"C requires a type specifier for all declarations!");
    }
    
    else{
        FuncNode declfunc;
        string func_name = getIDname(func_declarator->info.decl_info.detail.func_info.decl_tree);
        bool isdeclared = false;
        if(funcPool.find(func_name) != funcPool.end()){
            //如果不存在这个函数，也就是没有声明过
            if(funcPool[func_name].isdefinied){
                error(fNode->beg_line,"Function " + func_name + "is duplicated!");
            }
            else{
                isdeclared = true;
                //准备更新funcpool中的节点
                declfunc = funcPool[func_name];
                funcPool.erase(funcPool.find(func_name));
            }
        }
        block funcBlock;
        funcBlock.isfunc = true;
        funcBlock.func.name = func_name;
        funcBlock.func.rettype = cur_type;
        funcBlock.func.isdefinied = true;
        
        stack.push_back(funcBlock);
        funcPool.insert({func_name,funcBlock.func});
        
        innerCodeGenerator.addCode("FUNCTION "+ func_name + " :");
        
        parseParam(param_list,func_name,true);
        
        FuncNode newfunc = funcPool[func_name];
        
        if(isdeclared){
            if(declfunc.rettype != newfunc.rettype){
                error(fNode->beg_line, "The function declared return type has a conflict with the definition!");
            }
            
            if(declfunc.paralist.size() != newfunc.paralist.size() ){
                error(fNode->beg_line,"The parameter number is conflict with declared!");
            }
            
            for(vector<VarNode>::iterator iter1 = declfunc.paralist.begin(),iter2 = newfunc.paralist.begin() ; iter1 != declfunc.paralist.end()&&iter2 != newfunc.paralist.end();
                iter1++,iter2++){
                if(iter1->type != iter2->type){
                    error(iter1->line,"The declared function parameter " + iter2->name + "'s type doesn't match the definition!");
                }
            }
        }
        
        funcBlock.func = newfunc;
        
        parseCompoundStat(fNode->stat_list);
        
        stack.pop_back();
    }
}


void parser::parseDecl(declaration_Node* dNode){
    type_specifier_kind cur_type = dNode->type;
    if(cur_type == t_VOID)
        error(dNode->line,"Variable has incomplete type 'void'");
    if(dNode->decl_list == NULL)
        return;
    parseInitDeclList(dNode->decl_list, cur_type);
}

//**************************************三级单元的PARSE**************************************************
//*****************************parse parameter & stat & decl & exp********************************************

//函数的定义需要获得形参数，声明不需要
void parser::parseParam(param_Node* decl_Node, string func_name, bool Isdefinition){
    if(decl_Node == NULL)
        return;
    
    type_specifier_kind cur_type = decl_Node->type;
    
    if(cur_type == t_VOID){
        error(decl_Node->declarator->line, "Can't definite parameter as VOID!");
    }
    //暂时只考虑变量，不考虑数组
    declarator_Node *cur_declarator = decl_Node->declarator;
    
    if(cur_declarator->info.decl_info.type2 != Identifier){
        error(cur_declarator->line,"Currently only Identifier can be handled!");
    }
    
    ID_Node* cur_ID = cur_declarator->info.decl_info.detail.ID_info.ID_list;
    
    string varName = cur_ID->name;
    
    VarNode newVar;
    
    newVar.name = varName;
    newVar.line = cur_ID->line;
    newVar.type = cur_type;
    
    if(Isdefinition){
        newVar.num = innerCodeGenerator.varNum++;
        stack.back().func.paralist.push_back(newVar);
    }
    
    funcPool[func_name].paralist.push_back(newVar);
    //加入到该函数的符号表中
    stack.back().varMap.insert({varName,newVar});
    
    if(Isdefinition)
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforParam(newVar));
    
    //对下一个变量进行分析
    parseParam(decl_Node->next, func_name, Isdefinition);
}

void parser::parseStat(stat_Node* stat){
    if(stat == NULL){
        //debug用
        cout<<"Stat END"<<endl;
        return;
    }
    stat_kind cur_type = stat->type;
    switch (cur_type) {
        case LABEL:
            parseLabelStat(stat);
            break;
        case COMPOUND:
            parseCompoundStat(stat);
            break;
        case EXP:
            parseExpStat(stat);
            break;
        case SELECT:
            parseSelectStat(stat);
            break;
        case ITER:
            parseIterStat(stat);
            break;
        case JUMP:
            parseJumpStat(stat);
            break;
        default:
            break;
    }
    return;
}

VarNode parser::parseExp(exp_Node* exp){
    VarNode resnode;
    resnode = parseAssignExp(exp->info.exp_root.assign_exp);
    if(exp->info.exp_root.next_exp != NULL)
        resnode = parseExp(exp->info.exp_root.next_exp);
    return resnode;
}

void parser::parseLabelStat(stat_Node* lab_stat){
    //暂时先没做
    return;
}

//**************************************四级单元的PARSE**************************************************
//***************************************STATEMENT*****************************************************

void parser::parseCompoundStat(stat_Node* Compoud_stat){
    if(Compoud_stat->stat_info.compound_info.type2 == SINGLE)//type == SINGLE 说明是空语句
        return;
    else{
        block_item* cur_blist = Compoud_stat->stat_info.compound_info.blist;
        parseBlist(cur_blist);
    }
}

void parser::parseBlist(block_item* blist){
    if(blist == NULL)
        return;
    if(blist->declaration == NULL)//说明是statement
        parseStat(blist->statement);
    else
        parseDecl(blist->declaration);
    parseBlist(blist->next);
}

void parser::parseExpStat(stat_Node* Exp_stat){
    if(Exp_stat->stat_info.exp_info.exp == NULL)// ;
        return;
    parseExp(Exp_stat->stat_info.exp_info.exp);
}

void parser::parseSelectStat(stat_Node* Select_stat){
    select_kind cur_type = Select_stat->stat_info.select_info.type2;
    switch (cur_type) {
        case t_IF:
            parseIfExp(Select_stat->stat_info.select_info.exp, Select_stat->stat_info.select_info.stat1);
            break;
        case t_IF_ELSE:
            parseIfElseExp(Select_stat->stat_info.select_info.exp, Select_stat->stat_info.select_info.stat1, Select_stat->stat_info.select_info.stat2);
            break;
        case t_SWITCH:
            parseSwitchExp(Select_stat->stat_info.select_info.exp, Select_stat->stat_info.select_info.stat1);
            break;
        default:
            break;
    }
}
//这个其实是stat, 打错了名字...暂时先不改了
void parser::parseIfExp(exp_Node* exp, stat_Node* stat){
    block newblock;
    stack.push_back(newblock);
    
    VarNode exp_rnode = parseExp(exp);
    
    string lab1 = innerCodeGenerator.getLabelname();
    string lab2 = innerCodeGenerator.getLabelname();
    
    if(exp_rnode.type == t_BOOL)
        innerCodeGenerator.addCode("IF " + exp_rnode.boolstr + " GOTO " + lab1);
    else{
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_INT);
        innerCodeGenerator.addCode(temp_name + " := #0");
        
        innerCodeGenerator.addCode("IF " + innerCodeGenerator.getNodename(newNode) + " != " + temp_name + " GOTO " + lab1);
    }
    
    innerCodeGenerator.addCode("GOTO " + lab2);
    innerCodeGenerator.addCode("LABEL " + lab1 + " :");
    
    parseStat(stat);
    
    innerCodeGenerator.addCode("LABEL " + lab2 + " :");
    
    stack.pop_back();
}

void parser::parseIfElseExp(exp_Node *exp, stat_Node *stat1, stat_Node *stat2){
    block newblock;
    stack.push_back(newblock);
    
    VarNode exp_rnode = parseExp(exp);
    
    string lab1 = innerCodeGenerator.getLabelname();
    string lab2 = innerCodeGenerator.getLabelname();
    string lab3 = innerCodeGenerator.getLabelname();
    
    if(exp_rnode.type == t_BOOL){
        innerCodeGenerator.addCode("IF " + exp_rnode.boolstr + " GOTO " + lab1);
    }
    else{
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_INT);
        innerCodeGenerator.addCode(temp_name + " := #0");
        
        innerCodeGenerator.addCode("IF " + innerCodeGenerator.getNodename(exp_rnode) + " != " + temp_name + " GOTO " + lab1);
        
    }
    
    innerCodeGenerator.addCode("GOTO " + lab2);
    innerCodeGenerator.addCode("LABEL " + lab1 + " :");
    
    parseStat(stat1);
    
    innerCodeGenerator.addCode("GOTO " + lab3);
    stack.pop_back();
    
    //else
    innerCodeGenerator.addCode("LABEL " + lab2 + " :");
    
    block newblock2;
    stack.push_back(newblock2);
    
    parseStat(stat2);
    
    innerCodeGenerator.addCode("LABEL " + lab3 + " :");
    
    stack.pop_back();
}

void parser::parseSwitchExp(exp_Node *exp, stat_Node *stat){
    //暂时先空着
}

void parser::parseIterStat(stat_Node *IterStat){
    iter_kind cur_type = IterStat->stat_info.iter_info.type2;
    switch (cur_type) {
        case t_WHILE:
            parseWhileExp(IterStat->stat_info.iter_info.exp,IterStat->stat_info.iter_info.stat1);
            break;
        case t_DO_WHILE:
            parseDoWhileExp(IterStat->stat_info.iter_info.stat1, IterStat->stat_info.iter_info.exp);
            break;
        case FOR1:
            parseFor1Exp(IterStat->stat_info.iter_info.stat1, IterStat->stat_info.iter_info.stat2, IterStat->stat_info.iter_info.stat3);
            break;
        case FOR2:
            parseFor2Exp(IterStat->stat_info.iter_info.stat1, IterStat->stat_info.iter_info.stat2, IterStat->stat_info.iter_info.exp, IterStat->stat_info.iter_info.stat3);
            break;
        case FOR3:
            parseFor3Exp(IterStat->stat_info.iter_info.decl, IterStat->stat_info.iter_info.stat1, IterStat->stat_info.iter_info.stat2);
            break;
        case FOR4:
            parseFor4Exp(IterStat->stat_info.iter_info.decl, IterStat->stat_info.iter_info.stat1, IterStat->stat_info.iter_info.exp, IterStat->stat_info.iter_info.stat2);
            break;
        default:
            break;
    }
}

void parser::parseWhileExp(exp_Node *exp, stat_Node *stat){
    block newblock;
    newblock.canBreak = true;
    stack.push_back(newblock);
    
    string lab1 = innerCodeGenerator.getLabelname();
    string lab2 = innerCodeGenerator.getLabelname();
    string lab3 = innerCodeGenerator.getLabelname();
    
    stack.back().breakLabelname = lab3;
    
    innerCodeGenerator.addCode("LABEL " + lab1 + " :");
    
    VarNode exp_rnode = parseExp(exp);
    
    if(exp_rnode.type == t_BOOL){
        innerCodeGenerator.addCode("IF " + exp_rnode.boolstr + " GOTO " + lab2 );
    }
    else{
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_INT);
        innerCodeGenerator.addCode(temp_name + " := #0");
        
        innerCodeGenerator.addCode("IF " + innerCodeGenerator.getNodename(exp_rnode) + " != " + temp_name + " GOTO " + lab2);
    }
    
    innerCodeGenerator.addCode("GOTO " + lab3);
    innerCodeGenerator.addCode("LABEL " + lab2 + " :");
    
    parseStat(stat);
    
    innerCodeGenerator.addCode("GOTO " + lab1);
    innerCodeGenerator.addCode("LABEL " + lab3 + " :");
    
    stack.pop_back();
}


void parser::parseDoWhileExp(stat_Node *stat, exp_Node *exp){
    block newblock;
    newblock.canBreak = true;
    stack.push_back(newblock);
    
    string lab1 = innerCodeGenerator.getLabelname();
    string lab2 = innerCodeGenerator.getLabelname();
    
    stack.back().breakLabelname = lab2;
    
    innerCodeGenerator.addCode("LABEL " + lab1 + " :");
    
    parseStat(stat);
    
    VarNode exp_rnode = parseExp(exp);
    
    if(exp_rnode.type == t_BOOL){
        innerCodeGenerator.addCode("IF " + exp_rnode.boolstr + " GOTO " + lab2 );
    }
    else{
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_INT);
        innerCodeGenerator.addCode(temp_name + " := #0");
        
        innerCodeGenerator.addCode("IF " + innerCodeGenerator.getNodename(exp_rnode) + " != " + temp_name + " GOTO " + lab1);
    }
    innerCodeGenerator.addCode("LABEL " + lab2 + " :");
    
    stack.pop_back();
}

void parser::parseFor1Exp(stat_Node *stat1, stat_Node *stat2, stat_Node* stat){
    block newblock;
    newblock.canBreak = true;
    stack.push_back(newblock);
    
    string lab1 = innerCodeGenerator.getLabelname();
    string lab2 = innerCodeGenerator.getLabelname();
    string lab3 = innerCodeGenerator.getLabelname();
    
    stack.back().breakLabelname = lab3;
    
    parseExpStat(stat1);
    
    innerCodeGenerator.addCode("LABEL " + lab1 + " :");
    
    VarNode exp_rnode;
    
    if(stat2->stat_info.exp_info.exp != NULL){
        exp_rnode = parseExp(stat2->stat_info.exp_info.exp);
        if(exp_rnode.type == t_BOOL)
            innerCodeGenerator.addCode("IF " + exp_rnode.boolstr + " GOTO " + lab2);
        else{
            string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            VarNode newnode = createTempVar(temp_name, t_INT);
            innerCodeGenerator.addCode(temp_name + " := #0");
            
            innerCodeGenerator.addCode("IF " + innerCodeGenerator.getNodename(exp_rnode) + " GOTO " + lab2);
        }
    }
    else{
        innerCodeGenerator.addCode("GOTO " + lab2);
    }
    
    innerCodeGenerator.addCode("GOTO " + lab3);
    innerCodeGenerator.addCode("LABEL " + lab2 + " :");
    
    parseStat(stat);
    
    innerCodeGenerator.addCode("GOTO " + lab1);
    innerCodeGenerator.addCode("LABEL " + lab3 + " :");
    
    stack.pop_back();
}

void parser::parseFor2Exp(stat_Node *stat1, stat_Node *stat2, exp_Node *exp, stat_Node *stat){
    block newblock;
    newblock.canBreak = true;
    stack.push_back(newblock);
    
    string lab1 = innerCodeGenerator.getLabelname();
    string lab2 = innerCodeGenerator.getLabelname();
    string lab3 = innerCodeGenerator.getLabelname();
    
    stack.back().breakLabelname = lab3;
    
    parseStat(stat1);
    
    innerCodeGenerator.addCode("LABEL " + lab1 + " :");
    
    VarNode exp_rnode;
    if(stat2->stat_info.exp_info.exp != NULL){
        exp_rnode = parseExp(stat2->stat_info.exp_info.exp);
        if(exp_rnode.type == t_BOOL)
            innerCodeGenerator.addCode("IF " + exp_rnode.boolstr + " GOTO " + lab2);
        else{
            string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            VarNode newnode = createTempVar(temp_name, t_INT);
            innerCodeGenerator.addCode(temp_name + " := #0");
            
            innerCodeGenerator.addCode("IF " + innerCodeGenerator.getNodename(exp_rnode) + " != " + temp_name + " GOTO " + lab2);
        }
    }
    else
        innerCodeGenerator.addCode("GOTO " + lab2);
    
    innerCodeGenerator.addCode("GOTO " + lab3);
    innerCodeGenerator.addCode("LABEL " + lab2 + " :");
    
    parseStat(stat);
    parseExp(exp);
    
    innerCodeGenerator.addCode("GOTO " + lab1);
    innerCodeGenerator.addCode("LABEL " + lab3 + " :");
    
    stack.pop_back();
}

void parser::parseFor3Exp(declaration_Node *decl, stat_Node *stat1, stat_Node *stat){
    block newblock;
    newblock.canBreak = true;
    stack.push_back(newblock);
    
    string lab1 = innerCodeGenerator.getLabelname();
    string lab2 = innerCodeGenerator.getLabelname();
    string lab3 = innerCodeGenerator.getLabelname();
    
    stack.back().breakLabelname = lab3;
    
    parseDecl(decl);
    innerCodeGenerator.addCode("LABEL " + lab1 + " :");
    VarNode exp_rnode;
    if(stat1->stat_info.exp_info.exp != NULL){
        exp_rnode = parseExp(stat1->stat_info.exp_info.exp);
        if(exp_rnode.type == t_BOOL)
            innerCodeGenerator.addCode("IF " + exp_rnode.boolstr + " GOTO " + lab2);
        else{
            string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            VarNode newnode = createTempVar(temp_name, t_INT);
            innerCodeGenerator.addCode(temp_name + " := #0");
            
            innerCodeGenerator.addCode("IF " +innerCodeGenerator.getNodename(exp_rnode) + " != " + temp_name + " GOTO " + lab2);
        }
    }
    else{
        innerCodeGenerator.addCode("GOTO " + lab2);
    }
    innerCodeGenerator.addCode("GOTO " + lab3);
    innerCodeGenerator.addCode("LABEL " + lab2 + " :");
    
    stack.pop_back();
}

void parser::parseFor4Exp(declaration_Node *decl, stat_Node *stat1, exp_Node *exp, stat_Node *stat){
    block newblock;
    newblock.canBreak = true;
    stack.push_back(newblock);
    
    string lab1 = innerCodeGenerator.getLabelname();
    string lab2 = innerCodeGenerator.getLabelname();
    string lab3 = innerCodeGenerator.getLabelname();
    
    parseDecl(decl);
    innerCodeGenerator.addCode("LABEL " + lab1 + " :");
    
    VarNode exp_rnode;
    if(stat1->stat_info.exp_info.exp != NULL){
        exp_rnode = parseExp(stat1->stat_info.exp_info.exp);
        
        if(exp_rnode.type == t_BOOL)
            innerCodeGenerator.addCode("IF " + exp_rnode.boolstr + " GOTO " + lab2);
        else{
            string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            VarNode newNode = createTempVar(temp_name, t_INT);
            innerCodeGenerator.addCode(temp_name + " := #0");
            
            innerCodeGenerator.addCode("IF " + innerCodeGenerator.getNodename(exp_rnode) + " != " + temp_name + "  GOTO " + lab2);
        }
    }
    else
        innerCodeGenerator.addCode("GOTO " + lab2);
    innerCodeGenerator.addCode("GOTO " + lab3);
    innerCodeGenerator.addCode("LABEL " + lab2 + " :");
    
    parseStat(stat);
    parseExp(exp);
    
    innerCodeGenerator.addCode("GOTO " + lab1);
    innerCodeGenerator.addCode("LABEL " + lab3 + " :");
    
    stack.pop_back();
}

void parser::parseJumpStat(stat_Node *stat){
    switch (stat->stat_info.jump_info.type2) {
        case t_GOTO:
            parseGoto(stat);
            break;
        case t_BREAK:
            parseBreak(stat);
            break;
        case t_CONTINUE:
            parseContinue(stat);
            break;
        case RETURN1://return;
            parseReturn1(stat);
            break;
        case RETURN2://return expression
            parseReturn2(stat->stat_info.jump_info.exp);
            break;
        default:
            break;
    }
}

void parser::parseGoto(stat_Node *stat){
    
}

void parser::parseContinue(stat_Node *stat){
    
}

void parser::parseReturn1(stat_Node *stat){
    type_specifier_kind fret_type = getFuncRType();
    innerCodeGenerator.addCode("RETURN");
    if(fret_type != t_VOID)
        error(stat->line, "Non-void function should return a value!");
}

void parser::parseReturn2(exp_Node* exp){
    type_specifier_kind fret_type = getFuncRType();
    VarNode rnode = parseExp(exp);
    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforRet(rnode));
    if(rnode.type != fret_type)
        error(exp->line, "function return a conflict type value!");
}


void parser::parseBreak(stat_Node *stat){
    int num = getBreakBlock();
    if(num < 0)
        error(stat->line, "Can't break here!");
    else
        innerCodeGenerator.addCode("GOTO " + stack[num].breakLabelname);
    return;
}

//**************************************四级单元的PARSE**************************************************
//****************************************DECLARATION*****************************************************

void parser::parseInitDeclList(declarator_Node *decl_list, type_specifier_kind cur_type){
    if(decl_list == NULL)
        return;
    if(decl_list->type == DECL){
        switch (decl_list->info.decl_info.type2) {
            case Identifier:
                parseIDDecl(decl_list, cur_type);
                break;
            case ARRAY:
                parseArrayDecl(decl_list, cur_type);
                break;
            case FUNC:
                parseFuncDecl(decl_list, cur_type);
                break;
            default:
                break;
        }
    }
    else{// declarator = initializer
        //暂时先只处理变量的赋值
        VarNode newvar;
        declarator_Node *declarator = decl_list->info.init_info.decl_tree;
        initializer_Node *initer = decl_list->info.init_info.initalizer;
        
        if(declarator->info.decl_info.type2 != Identifier)
            error(declarator->line, getIDname(declarator) + "is not a variable!");
        else{
            string ID_name = getIDname(declarator);
            if(!lookupCurVar(ID_name)){
                newvar.name = ID_name;
                newvar.type = cur_type;
                newvar.num = innerCodeGenerator.varNum++;
                newvar.line = declarator->line;
                stack.back().varMap.insert({ID_name,newvar});
            }
            else
                error(declarator->line, "Redifinition of " + ID_name );
            
            //处理initializer
            if(initer->type != SINGLE)
                error(declarator->line, "Wrong value to variable");
            else{
                VarNode rnode = parseAssignExp(initer->info.assign_exp);
                innerCodeGenerator.addCode(innerCodeGenerator.createCodeforAssign(newvar, rnode));
                type_specifier_kind rtype = rnode.type;
                if(rtype != cur_type)
                    error(declarator->line, "Wrong type assignment from" + rnode.name + " to " + newvar.name);
            }
        }
    }
    parseInitDeclList(decl_list->next, cur_type);
}

void parser::parseIDDecl(declarator_Node *decl_node,type_specifier_kind cur_type){
    ID_Node *cur_ID=decl_node->info.decl_info.detail.ID_info.ID_list;
    string var_name = cur_ID->name;
    if(!lookupCurVar(var_name)){
        VarNode newvar;
        newvar.name = var_name;
        newvar.type = cur_type;
        newvar.num = innerCodeGenerator.varNum++;
        newvar.line = decl_node->line;
        stack.back().varMap.insert({var_name,newvar});
    }
    else
        error(decl_node->line, "Redefinition of '" + var_name + "' ");
}

void parser::parseArrayDecl(declarator_Node *decl_node, type_specifier_kind cur_type){
    string arrName = decl_node->info.decl_info.detail.arr_info.decl_tree->info.decl_info.detail.ID_info.ID_list->name;
    if(decl_node->info.decl_info.detail.arr_info.arr_type != arr_C_exp)
        error(decl_node->line, "Definition of variable with array type needs an explicit size or an initializer");
    exp_Node *const_exp = decl_node->info.decl_info.detail.arr_info.exp;
    
    VarNode rnode = parseConstExp(const_exp);
    
    if(rnode.type != t_INT)
        error(decl_node->line, "Array size must be int");
    
    VarNode tnode;
    if(cur_type == t_INT){
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        tnode = createTempVar(temp_name, t_INT);
        
        stack.back().varMap.insert({temp_name,tnode});
        
        VarNode tempVar3;
        string temp_name3 = "temp" +inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        tempVar3.name = temp_name3;
        tempVar3.type = t_INT;
        stack.back().varMap.insert({temp_name3,tempVar3});
        
        innerCodeGenerator.addCode(temp_name3 + " := #4");
        
        innerCodeGenerator.addCode(tnode.name + " := " + temp_name3 + " * " + rnode.name);
    }
    else if(cur_type == t_DOUBLE){
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        tnode = createTempVar(temp_name, t_INT);
        
        stack.back().varMap.insert({temp_name,tnode});
        
        VarNode tempVar3;
        string temp_name3 = "temp" +inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        tempVar3.name = temp_name3;
        tempVar3.type = t_INT;
        stack.back().varMap.insert({temp_name3,tempVar3});
        
        innerCodeGenerator.addCode(temp_name3 + " := #8");
        
        innerCodeGenerator.addCode(tnode.name + " := " + temp_name3 + " * " + rnode.name);
    }
    else if(cur_type == t_BOOL)
        tnode = rnode;
    
    ArrayNode anode;
    anode.name = arrName;
    anode.type = cur_type;
    anode.num = innerCodeGenerator.arrayNum++;
    
    innerCodeGenerator.addCode("DEC " + innerCodeGenerator.getArrNodename(anode) + " " + tnode.name);
    
    stack.back().arrayMap.insert({arrName,anode});
}

void parser::parseFuncDecl(declarator_Node *dnode, type_specifier_kind cur_type){
    string funcName = getIDname(dnode->info.decl_info.detail.func_info.decl_tree);
    if(dnode->info.decl_info.detail.func_info.func_type == IDENT)
        error(dnode->line,"C requires a type specifier for all declarations");
    param_Node *parmlist = dnode->info.decl_info.detail.func_info.list.param_list;
    
    FuncNode newFunc;
    newFunc.name = funcName;
    newFunc.isdefinied = false;
    newFunc.rettype = cur_type;
    funcPool.insert({funcName,newFunc});
    
    parseParam(parmlist, funcName, false);
}

//**************************************四级单元的PARSE**************************************************
//*******************************************Expression*********************************************

VarNode parser::parseAssignExp(exp_Node *assignExp){
    if(assignExp->info.assign_info.type2 == assign_NA)
        return parseCondiExp(assignExp->info.assign_info.unary_exp);
    else{
        assign_kind op =  assignExp->info.assign_info.type2;
        VarNode node1 = parseUnaryExp(assignExp->info.assign_info.unary_exp);
        VarNode node2 = parseAssignExp(assignExp->info.assign_info.assign_exp);
        VarNode node3;
        if(op == t_ASSIGNMENT){
            node3 = node2;
        }
        else{
            string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            node3 = createTempVar(temp_name, node1.type);
            
            stack.back().varMap.insert({temp_name, node3});
            switch (op) {
                case t_MUL_ASSIGN://*=
                    if(node1.type != node2.type)
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "*" , node1, node2));
                    break;
                
                case t_DIV_ASSIGN:// /=
                    if(node1.type != node2.type)
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "/", node1, node2));
                    break;
                    
                case t_MOD_ASSIGN:// %=
                    if((node1.type != t_INT) || (node2.type != t_INT))
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "%", node1, node2));
                    break;
                    
                case t_ADD_ASSIGN:// +=
                    if(node1.type != node2.type)
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "+", node1, node2));
                    break;
                    
                case t_SUB_ASSIGN: // -=
                    if(node1.type != node2.type)
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "-", node1, node2));
                    break;
                    
                case t_LEFT_ASSIGN: // <<=
                    if((node1.type != t_INT) || (node2.type != t_INT))
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "<<", node1, node2));
                    break;
                
                case t_RIGHT_ASSIGN:// >>=
                    if((node1.type != t_INT) || (node2.type != t_INT))
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, ">>" ,node1, node2));
                    break;
                    
                case t_AND_ASSIGN:
                    if((node1.type != t_INT) || (node2.type != t_INT))
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "&", node1, node2));
                    break;
                    
                case t_XOR_ASSIGN:
                    if((node1.type != t_INT) || (node2.type != t_INT))
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "^", node1, node2));
                    break;
                    
                case t_OR_ASSIGN:
                    if((node1.type != t_INT) || (node2.type != t_INT))
                        error(node1.line, node1.name + " has conflict type with " + node2.name);
                    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "|", node1, node2));
                    break;
                    
                default:
                    break;
            }
        }
        
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforAssign(node1, node3));
        return node1;
    }
}

VarNode parser::parseLogicalOrExp(exp_Node *logicaloexp){
    if(logicaloexp->info.logi_or_info.logical_or_exp == NULL){
        return parseLogicalAndExp(logicaloexp->info.logi_or_info.logical_and_exp);
    }
    else{
        VarNode node1 = parseLogicalOrExp(logicaloexp->info.logi_or_info.logical_or_exp);
        VarNode node2 = parseLogicalAndExp(logicaloexp->info.logi_or_info.logical_and_exp);
        
        if(node1.type != t_BOOL || node2.type != t_BOOL)
            error(logicaloexp->line, "Logical expression need 'bool' type expression!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, node1.type);
        
        stack.back().varMap.insert({temp_name,newNode});
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "||", node1, node2));
        
        newNode.boolstr = innerCodeGenerator.getNodename(node1) + " || " + innerCodeGenerator.getNodename(node2);
        return newNode;
    }
}

VarNode parser::parseLogicalAndExp(exp_Node *LogAndexp){
    if(LogAndexp->info.logi_and_info.logical_and_exp == NULL)
        return parseIncluOrExp(LogAndexp->info.logi_and_info.inclusive_or_exp);
    else{
        VarNode node1 = parseLogicalAndExp(LogAndexp->info.logi_and_info.logical_and_exp);
        VarNode node2 = parseIncluOrExp(LogAndexp->info.logi_and_info.inclusive_or_exp);
        
        if(node1.type != t_BOOL || node2.type != t_BOOL)
            error(LogAndexp->line, "Logical expression need 'bool' type expression!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, node1.type);
        
        stack.back().varMap.insert({temp_name,newNode});
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "&&", node1, node2));
        
        newNode.boolstr = innerCodeGenerator.getNodename(node1) + " && " + innerCodeGenerator.getNodename(node2);
        return newNode;
    }
}

VarNode parser::parseIncluOrExp(exp_Node *InclOrexp){
    if(InclOrexp->info.incl_or_info.inclusive_or_exp == NULL)
        return parseExcluOrExp(InclOrexp->info.incl_or_info.exclusive_or_exp);
    else{
        VarNode node1 = parseIncluOrExp(InclOrexp->info.incl_or_info.inclusive_or_exp);
        VarNode node2 = parseExcluOrExp(InclOrexp->info.incl_or_info.exclusive_or_exp);
        
        if(node1.type != t_INT || node2.type != t_INT)
            error(InclOrexp->line, "Inclusive or expression need 'int' type expression!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, node1.type);
        
        stack.back().varMap.insert({temp_name,newNode});
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "|", node1, node2));
        
        newNode.boolstr = innerCodeGenerator.getNodename(node1) + " | " + innerCodeGenerator.getNodename(node2);
        return newNode;
    }
}

VarNode parser::parseExcluOrExp(exp_Node *ExclOrexp){
    if(ExclOrexp->info.excl_or_info.exclusive_or_exp == NULL)
        return parseAndExp(ExclOrexp->info.excl_or_info.and_exp);
    else{
        VarNode node1 = parseExcluOrExp(ExclOrexp->info.excl_or_info.exclusive_or_exp);
        VarNode node2 = parseAndExp(ExclOrexp->info.excl_or_info.and_exp);
        
        if(node1.type != t_INT || node2.type != t_INT)
            error(ExclOrexp->line, "Exclusive expression need 'int' type expression!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, node1.type);
        
        stack.back().varMap.insert({temp_name,newNode});
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "^", node1, node2));
        
        newNode.boolstr = innerCodeGenerator.getNodename(node1) + " ^ " + innerCodeGenerator.getNodename(node2);
        return newNode;
        
    }
}

VarNode parser::parseAndExp(exp_Node *Andexp){
    if(Andexp->info.and_info.and_exp == NULL)
        return parseEqualExp(Andexp->info.and_info.equal_exp);
    else{
        VarNode node1 = parseAndExp(Andexp->info.and_info.and_exp);
        VarNode node2 = parseEqualExp(Andexp->info.and_info.equal_exp);
        
        if(node1.type != t_INT || node2.type != t_INT)
            error(Andexp->line, "And expression need 'int' type expression!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, node1.type);
        
        stack.back().varMap.insert({temp_name,newNode});
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, "&", node1, node2));
        
        newNode.boolstr = innerCodeGenerator.getNodename(node1) + " & " + innerCodeGenerator.getNodename(node2);
        return newNode;
        
    }
}

VarNode parser::parseEqualExp(exp_Node *Equalexp){
    if(Equalexp->info.equal_info.type2 == equal_NA)
        return parseRelaExp(Equalexp->info.equal_info.relation_exp);
    
    else{
        VarNode node1 = parseEqualExp(Equalexp->info.equal_info.equal_exp);
        VarNode node2 = parseRelaExp(Equalexp->info.equal_info.relation_exp);
        string op;
        
        if(node1.type != node2.type)
            error(Equalexp->line, "Different type for two variable");
        
        if(Equalexp->info.equal_info.type2 == EQ)
            op = "==";
        else
            op = "!=";
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        
        VarNode newnode = createTempVar(temp_name, t_BOOL);
        stack.back().varMap.insert({temp_name,newnode});
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, op, node1, node2));
        
        newnode.boolstr = innerCodeGenerator.getNodename(node1) + " " + op + " " + innerCodeGenerator.getNodename(node2);
        
        return newnode;
    }
}

VarNode parser::parseRelaExp(exp_Node *Relaexp){
    if(Relaexp->info.rela_info.type2 == relation_NA)
        return parseShiftExp(Relaexp->info.rela_info.shift_exp);
    else{
        string op;
        switch (Relaexp->info.rela_info.type2) {
            case LES:
                op = "<";
                break;
            case GT:
                op = ">";
                break;
            case LE:
                op = "<=";
                break;
            case GE:
                op = ">=";
                break;
            default:
                break;
        }
        
        VarNode node1 = parseRelaExp(Relaexp->info.rela_info.relation_exp);
        VarNode node2 = parseShiftExp(Relaexp->info.rela_info.shift_exp);
        if(node1.type != node2.type)
            error(Relaexp->line, "Different type for two variables");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        
        VarNode newnode = createTempVar(temp_name, t_BOOL);
        stack.back().varMap.insert({temp_name,newnode});
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, op, node1, node2));
        
        newnode.boolstr = innerCodeGenerator.getNodename(node1) + " " + op + " " + innerCodeGenerator.getNodename(node2);
        
        return newnode;
    }
}

VarNode parser::parseShiftExp(exp_Node *Shiftexp){
    if(Shiftexp->info.shift_info.type2 == shift_NA)
        return parseAddExp(Shiftexp->info.shift_info.addtive_exp);
    else{
        string op;
        switch (Shiftexp->info.shift_info.type2) {
            case LEFT:
                op = "<<";
                break;
            case RIGHT:
                op = ">>";
                break;
            default:
                break;
        }
        VarNode node1 = parseShiftExp(Shiftexp->info.shift_info.shift_exp);
        VarNode node2 = parseAddExp(Shiftexp->info.shift_info.addtive_exp);
        
        if(node1.type != t_INT || node2.type != t_INT)
            error(Shiftexp->line, "Shift opearation need 'int' type expression!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        
        VarNode newnode = createTempVar(temp_name, node1.type);
        
        stack.back().varMap.insert({temp_name,newnode});
        
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, op, node1, node2));
        return newnode;
    }
}

VarNode parser::parseAddExp(exp_Node *Addexp){
    if(Addexp->info.add_info.type2 == add_NA)
        return parseMulExp(Addexp->info.add_info.mul_exp);
    else{
        string op;
        switch (Addexp->info.add_info.type2) {
            case ADD_OP:
                op = "+";
                break;
            case MINUS_OP:
                op = "-";
                break;
            default:
                break;
        }
        VarNode node1 = parseAddExp(Addexp->info.add_info.add_exp);
        VarNode node2 = parseMulExp(Addexp->info.add_info.mul_exp);
        
        if(node1.type != node2.type)
            error(Addexp->line, "Different type for two variables!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newnode = createTempVar(temp_name, node1.type);
        stack.back().varMap.insert({temp_name,newnode});
        
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, op, node1, node2));
        return newnode;
    }
}

VarNode parser::parseMulExp(exp_Node *Mulexp){
    if(Mulexp->info.mul_info.type2 == mul_NA)
        return parseUnaryExp(Mulexp->info.mul_info.unary_exp);
    else{
        string op;
        switch (Mulexp->info.mul_info.type2) {
            case MUL_OP:
                op = "*";
                break;
            case DIV_OP:
                op = "/";
                break;
            case MOD:
                op = "%";
                break;
            default:
                break;
        }
        VarNode node1 = parseMulExp(Mulexp->info.mul_info.mul_exp);
        VarNode node2 = parseUnaryExp(Mulexp->info.mul_info.unary_exp);
        
        if(node1.type != node2.type)
            error(Mulexp->line, "Different type for two variables!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newnode = createTempVar(temp_name, node1.type);
        stack.back().varMap.insert({temp_name,newnode});
        
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforVar(temp_name, op, node1, node2));
        return newnode;
    }
}

VarNode parser::parseUnaryExp(exp_Node *Unaryexp){
    if(Unaryexp->info.unary_info.type2 == unary_NA)
        return parsePostExp(Unaryexp->info.unary_info.post_exp);
    
    else if(Unaryexp->info.unary_info.type2 == t_INC_OP){//++
        VarNode rnode = parseUnaryExp(Unaryexp->info.unary_info.unary_exp);
        if(rnode.type != t_INT)
            error(Unaryexp->line, "++ opearation can only use for int type");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_INT);
        stack.back().varMap.insert({temp_name,newNode});
        
        innerCodeGenerator.addCode(temp_name + " := #1");
        
        if(rnode.useAddress)
            innerCodeGenerator.addCode("*" + rnode.name + " := " + rnode.name + " + " + temp_name);
        else
            innerCodeGenerator.addCode(innerCodeGenerator.getNodename(rnode) + " := " + innerCodeGenerator.getNodename(rnode) + " + " + temp_name);
        
        return rnode;
    }
    
    else if(Unaryexp->info.unary_info.type2 == t_DEC_OP){//--
        VarNode rnode = parseUnaryExp(Unaryexp->info.unary_info.unary_exp);
        if(rnode.type != t_INT)
            error(Unaryexp->line, "-- opearation can only use for int type");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_INT);
        stack.back().varMap.insert({temp_name,newNode});
        
        innerCodeGenerator.addCode(temp_name + " := #1");
        
        if(rnode.useAddress)
            innerCodeGenerator.addCode("*" + rnode.name + " := " + rnode.name + " - " + temp_name);
        else
            innerCodeGenerator.addCode(innerCodeGenerator.getNodename(rnode) + " := " + innerCodeGenerator.getNodename(rnode) + " - " + temp_name);
        
        return rnode;
    }
    
    else{// + - ~ !
        string op;
        switch (Unaryexp->info.unary_info.type2) {
            case POS://+
                op = "+";
                break;
            case NEG:
                op = "-";
                break;
            case BIT_NEG:
                op = "~";
                break;
            case FEI:
                op = "!";
                break;
            default:
                break;
        }
        VarNode rnode = parseUnaryExp(Unaryexp->info.unary_info.unary_exp);
        
        if(op == "+"){
            if(rnode.type != t_INT && rnode.type != t_DOUBLE)
                error(Unaryexp->line,"Opearator '+' only can combine with int or double");
            return rnode;
        }
        else if( op == "-"){
            if(rnode.type != t_INT && rnode.type != t_DOUBLE)
                error(Unaryexp->line,"Opearator '-' only can combine with int or double");
            
            string temp_zero_name = "temp" +inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            VarNode newzeroNode = createTempVar(temp_zero_name, rnode.type);
            stack.back().varMap.insert({temp_zero_name, newzeroNode});
            
            string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            VarNode newNode = createTempVar(temp_name, rnode.type);
            stack.back().varMap.insert({temp_name, newNode});
            
            if(rnode.useAddress)
                innerCodeGenerator.addCode(temp_name + " := " + temp_zero_name + "- *" + rnode.name);
            else
                innerCodeGenerator.addCode(temp_name + " := " + temp_zero_name + " - " + innerCodeGenerator.getNodename(rnode));
            return newNode;
        }
        else if(op == "~"){
            error(Unaryexp->line, "Currently not support this type of operation!");
            return rnode;
        }
        else{
            error(Unaryexp->line, "Currently not support this type of operation!");
            return rnode;
        }
    }
}


VarNode parser::parsePostExp(exp_Node *Postexp){
    if(Postexp->info.post_info.type2 == post_NA)
        return parsePrimExp(Postexp->info.post_info.arg_list);
    else if(Postexp->info.post_info.type2 == ARRAY_CALL){
        exp_Node *next_Postexp = Postexp->info.post_info.post_exp;
        //处理primExp 得到数组 名字
        string arrayName = next_Postexp->info.post_info.arg_list->info.prim_info.detail.ID->name;
        
        VarNode enode = parseExp(Postexp->info.post_info.arg_list);
        ArrayNode anode = getArryNode(arrayName);
        
        if(anode.num < 0)
            error(Postexp->line, "Undefined array!");
        
        VarNode tempVar;
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        tempVar.name = temp_name;
        tempVar.type = anode.type;
        tempVar.useAddress = true;
        tempVar.line = Postexp->line;
        stack.back().varMap.insert({temp_name,tempVar});
        
        if(anode.type == t_INT || anode.type == t_DOUBLE){
            VarNode tempvar2;
            string temp_name2 = "temp" + inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            tempvar2.name = temp_name2;
            tempvar2.type = t_INT;
            tempvar2.line = tempVar.line;
            stack.back().varMap.insert({temp_name2,tempvar2});
            
            if(anode.type == t_INT){
                
                VarNode tempvar3;
                string temp_name3 = "temp" + inttostr(innerCodeGenerator.tempNum);
                innerCodeGenerator.tempNum++;
                tempvar3.name = temp_name3;
                tempvar3.type = t_INT;
                tempvar3.line = Postexp->line;
                stack.back().varMap.insert({temp_name3,tempvar3});
                
                innerCodeGenerator.addCode(temp_name3 + " := #4");
                innerCodeGenerator.addCode(temp_name2 + " := " + innerCodeGenerator.getNodename(enode) + " * " +temp_name3);
            }
            else if(anode.type == t_DOUBLE){
                VarNode tempvar3;
                string tempname3 = "temp" + inttostr(innerCodeGenerator.tempNum);
                innerCodeGenerator.tempNum++;
                tempvar3.name = tempname3;
                tempvar3.type = t_INT;
                tempvar3.line = Postexp->line;
                stack.back().varMap.insert({tempname3,tempvar3});
                
                innerCodeGenerator.addCode(tempname3 + " := #8");
                
                innerCodeGenerator.addCode(temp_name2 + " := " + innerCodeGenerator.getNodename(enode) + " * " +tempname3);
            }
            
            innerCodeGenerator.addCode(temp_name + " := &" + innerCodeGenerator.getArrNodename(anode) + " + " + innerCodeGenerator.getNodename(tempvar2));
            return tempVar;
        }
        
        innerCodeGenerator.addCode(temp_name + " := &" + innerCodeGenerator.getArrNodename(anode) + " + " + innerCodeGenerator.getNodename(enode));
        return tempVar;
    }
    else if(Postexp->info.post_info.type2 == FUNC_CALL){
        exp_Node *next_Postexp = Postexp->info.post_info.post_exp;
        //处理primExp 得到函数名字
        string funcName = next_Postexp->info.post_info.arg_list->info.prim_info.detail.ID->name;
        
        VarNode newNode;
        
        if(funcPool.find(funcName) == funcPool.end())
            error(Postexp->line, "Undefined function " + funcName);
        
        if(Postexp->info.post_info.arg_list != NULL)
            parseArugumentExp(Postexp->info.post_info.arg_list,funcName);
        
        FuncNode func = funcPool[funcName];
        
        if(func.rettype == t_VOID)
            innerCodeGenerator.addCode("CALL " + funcName);
        else{
            string temp_name = "temp" +inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            
            newNode = createTempVar(temp_name, funcPool[funcName].rettype);
            
            innerCodeGenerator.addCode(temp_name + " := CALL " + funcName);
        }
        return newNode;
    }
    else if(Postexp->info.post_info.type2 == INC){
        VarNode rnode = parsePostExp(Postexp->info.post_info.post_exp);
        
        if(rnode.type != t_INT)
            error(Postexp->line, "++ opearation can only use for int type!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_INT);
        stack.back().varMap.insert({temp_name,newNode});
        
        string temp_name1 = "temp" +inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode1 = createTempVar(temp_name1, t_INT);
        stack.back().varMap.insert({temp_name1, newNode1});
        
        innerCodeGenerator.addCode(temp_name1 + " := #1");
        
        if(rnode.useAddress){
            innerCodeGenerator.addCode(temp_name + " := *" +rnode.name);
            innerCodeGenerator.addCode("*" + rnode.name + " := *" + rnode.name + " + " + temp_name1);
        }
        else{
            innerCodeGenerator.addCode(temp_name + " := " + innerCodeGenerator.getNodename(rnode));
            innerCodeGenerator.addCode(innerCodeGenerator.getNodename(rnode) + " := " + innerCodeGenerator.getNodename(rnode) + " + " + temp_name1);
        }
        return newNode;
    }
    
    else if(Postexp->info.post_info.type2 == DEC){
        VarNode rnode = parsePostExp(Postexp->info.post_info.post_exp);
        
        if(rnode.type != t_INT)
            error(Postexp->line, "-- opearation can only use for int type!");
        
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_INT);
        stack.back().varMap.insert({temp_name,newNode});
        
        string temp_name1 = "temp" +inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode1 = createTempVar(temp_name1, t_INT);
        stack.back().varMap.insert({temp_name1, newNode1});
        
        innerCodeGenerator.addCode(temp_name1 + " := #1");
        
        if(rnode.useAddress){
            innerCodeGenerator.addCode(temp_name + " := *" +rnode.name);
            innerCodeGenerator.addCode("*" + rnode.name + " := *" + rnode.name + " - " + temp_name1);
        }
        else{
            innerCodeGenerator.addCode(temp_name + " := " + innerCodeGenerator.getNodename(rnode));
            innerCodeGenerator.addCode(innerCodeGenerator.getNodename(rnode) + " := " + innerCodeGenerator.getNodename(rnode) + " - " + temp_name1);
        }
        return newNode;
    }
    else{
        VarNode junk;
        error(Postexp->line,"Enter unknow parsing step!");
        return junk;
    }
}

void parser::parseArugumentExp(exp_Node *Aruglist, string funcname){
    FuncNode func = funcPool[funcname];
    int i = 0;
    exp_Node *originNode = Aruglist;
    while(Aruglist->info.argument_info.type2 == GROUP){
        VarNode rnode = parseAssignExp(Aruglist->info.argument_info.assig_exp);
        innerCodeGenerator.addCode(innerCodeGenerator.createCodeforArugument(rnode));
        
        Aruglist = Aruglist->info.argument_info.argu_exp;
        i++;
        if(func.paralist[func.paralist.size() - i].type != rnode.type)
            error(originNode->line,"definition of" + funcname + "does not match any declaration");
    }
    
    VarNode rnode = parseAssignExp(Aruglist->info.argument_info.assig_exp);
    innerCodeGenerator.addCode(innerCodeGenerator.createCodeforArugument(rnode));
    i++;
    if(func.paralist[func.paralist.size() - i].type != rnode.type)
        error(originNode->line,"definition of" + funcname + "does not match any declaration");
    if( i != func.paralist.size())
        error(originNode->line, "The number of arguments doesn't match with declaration");
}

VarNode parser::parsePrimExp(exp_Node *Primexp){
    if(Primexp->info.prim_info.type2 == ID){
        string name = Primexp->info.prim_info.detail.ID->name;
        VarNode rnode = lookupNode(name);
        if(rnode.num < 0)
            error(Primexp->line, "Undefined variable " + name);
        return rnode;
    }
    else if(Primexp->info.prim_info.type2 == t_TRUE || Primexp->info.prim_info.type2 == t_FALSE){
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_BOOL);
        stack.back().varMap.insert({temp_name,newNode});
        if(Primexp->info.prim_info.type2 == t_TRUE)
            innerCodeGenerator.addCode(temp_name + " := #1");
        else
            innerCodeGenerator.addCode(temp_name + " := #0");
        return newNode;
    }
    else if(Primexp->info.prim_info.type2 == CONSTAN_INT){
        string content = Primexp->info.prim_info.detail.val;
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_INT);
        stack.back().varMap.insert({temp_name,newNode});
        innerCodeGenerator.addCode(temp_name + " := #" + content);
        return newNode;
    }
    else if(Primexp->info.prim_info.type2 == t_CONSTANT_DOUBLE){
        string content = Primexp->info.prim_info.detail.val;
        string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
        innerCodeGenerator.tempNum++;
        VarNode newNode = createTempVar(temp_name, t_DOUBLE);
        stack.back().varMap.insert({temp_name,newNode});
        innerCodeGenerator.addCode(temp_name + " := F" + content);
        return newNode;
    }
    else{
        return parseExp(Primexp->info.prim_info.detail.exp);
    }
}

VarNode parser::parseCondiExp(exp_Node *Condexp){
    if (Condexp->info.cond_info.cond_exp == NULL) {
        return parseLogicalOrExp(Condexp->info.cond_info.logical_or_exp);
    }
    else{
        string lab1 = innerCodeGenerator.getLabelname();
        string lab2 = innerCodeGenerator.getLabelname();
        string lab3 = innerCodeGenerator.getLabelname();
        
        VarNode exp_rnode = parseExcluOrExp(Condexp->info.cond_info.logical_or_exp);
        
        if(exp_rnode.type == t_BOOL)
            innerCodeGenerator.addCode("IF " + exp_rnode.boolstr + " GOTO " + lab1);
        else{
            string temp_name = "temp" + inttostr(innerCodeGenerator.tempNum);
            innerCodeGenerator.tempNum++;
            VarNode newNode = createTempVar(temp_name, t_INT);
            innerCodeGenerator.addCode(temp_name + " := #0");
            
            innerCodeGenerator.addCode("IF " + innerCodeGenerator.getNodename(exp_rnode) + " != " + temp_name + " GOTO " + lab1);
        }
        
        innerCodeGenerator.addCode("GOTO " + lab2);
        innerCodeGenerator.addCode("LABEL " + lab1 + " :");
        
        VarNode node1 = parseExp(Condexp->info.cond_info.exp);
        
        innerCodeGenerator.addCode("GOTO " + lab3);
        innerCodeGenerator.addCode("LABEL " + lab2 + " :");
        
        VarNode node2 = parseCondiExp(Condexp->info.cond_info.cond_exp);
        
        innerCodeGenerator.addCode("LABEL " + lab3 + " :");
        
        return node1;//这里其实有问题，返回的应该是正确的那个node
    }
}

VarNode parser::parseConstExp(exp_Node *Constexp){
    return parseCondiExp(Constexp->info.const_info.cond_exp);
}


//**************************************四级单元的PARSE**************************************************
//************************************************Sundry functions*********************************************
bool parser::lookupCurVar(string name){
    return stack.back().varMap.find(name) != stack.back().varMap.end();
}

VarNode parser::lookupNode(string name){
    int N = stack.size();
    for(int i = N-1 ; i>= 0 ; i--){
        if(stack[i].varMap.find(name) != stack[i].varMap.end())
            return stack[i].varMap[name];
    }
    VarNode temp;
    temp.num = -1;
    return temp;
}

ArrayNode parser::getArryNode(string name){
    int N = stack.size();
    for(int i = N-1 ;i > 0 ; i--){
        if(stack[i].arrayMap.find(name) != stack[i].arrayMap.end())
            return stack[i].arrayMap[name];
    }
    ArrayNode temp;
    temp.num = -1;
    return temp;
}

void parser::error(int line, string error){
    printCode();
    
    cout << "error! line"<< line <<": ";
    cout << error <<endl;
    exit(1);
}

int parser::getBreakBlock(){
    int N = stack.size();
    for(int i = N -1 ; i > 0 ; i--){
        if(stack[i].canBreak)
            return i;
    }
    return -1;
}

VarNode parser::createTempVar(string name, type_specifier_kind type){
    VarNode var;
    var.name = name;
    var.type = type;
    var.num = -1;
    return var;
}

void parser::printCode(){
    innerCodeGenerator.printCode();
}

type_specifier_kind parser::getFuncRType(){
    int N = stack.size();
    for(int i = N -1 ; i >= 0; i--){
        if(stack[i].isfunc)
            return stack[i].func.rettype;
    }
    switch (N) {
        case 1:
            int i ;
            break;
        case 2:
            i = 10;
            break;
            
        default:
            break;
    }
    
    return t_VOID;
}

string parser::getIDname(declarator_Node *decl){
    if(decl->info.decl_info.type2 != Identifier)
        error(decl->line, "ID获取失败！！！");
    return decl->info.decl_info.detail.ID_info.ID_list->name;
}
