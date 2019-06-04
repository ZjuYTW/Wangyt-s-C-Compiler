#ifndef parser_hpp
#define parser_hpp
#include "ast.hpp"
#include "block.hpp"
#include "tools.hpp"
#include "InnerCodeGenerator.hpp"
#include "Codegen.hpp"
#include <vector>
#include <iostream>
#include <map>


using namespace std;

class parser{
public:
    parser(root_Node*);
    ~parser();
    
private:
    struct root_Node* root;
    map<string, FuncNode> funcPool;
    vector<block> stack;
    ICG innerCodeGenerator;
    
    void parserInit();
    void parse(root_Node*);
    void printCode();
    void parseFunc(func_Node*);
    void parseDecl(declaration_Node*);
    void parseParam(param_Node*,string,bool);
    void parseBlist(block_item*);
    VarNode parseExp(exp_Node*);
    //*******************************************STAT*******************************************
    //Select_Stat
    void parseIfExp(exp_Node*,stat_Node*);
    void parseIfElseExp(exp_Node*, stat_Node*, stat_Node*);
    void parseSwitchExp(exp_Node*, stat_Node*);
    //Iter_Stat
    void parseWhileExp(exp_Node*, stat_Node*);
    void parseDoWhileExp(stat_Node*, exp_Node*);
    void parseFor1Exp(stat_Node* exp_stat1, stat_Node* exp_stat2, stat_Node* stat);
    void parseFor2Exp(stat_Node* exp_stat1, stat_Node* exp_stat2, exp_Node* exp, stat_Node* stat);
    void parseFor3Exp(declaration_Node* decl1, stat_Node* stat1, stat_Node* stat);
    void parseFor4Exp(declaration_Node* decl1, stat_Node* stat1, exp_Node* exp, stat_Node *stat);
    //Jump_stat
    void parseBreak(stat_Node*);
    void parseGoto(stat_Node*);
    void parseContinue(stat_Node*);
    void parseReturn1(stat_Node*);
    void parseReturn2(exp_Node *);
    //Stat
    void parseStat(stat_Node*);
    void parseLabelStat(stat_Node*);
    void parseCompoundStat(stat_Node*);
    void parseExpStat(stat_Node*);
    void parseSelectStat(stat_Node*);
    void parseIterStat(stat_Node*);
    void parseJumpStat(stat_Node*);
     //*******************************************Declaration***************************************
    void parseInitDeclList(declarator_Node*, type_specifier_kind);
    void parseIDDecl(declarator_Node*, type_specifier_kind);
    void parseArrayDecl(declarator_Node*, type_specifier_kind);
    void parseFuncDecl(declarator_Node*, type_specifier_kind);
    
    
    //*******************************************Expression***************************************
    VarNode parseConstExp(exp_Node*);
    VarNode parseAssignExp(exp_Node*);
    VarNode parseCondiExp(exp_Node*);
    VarNode parseUnaryExp(exp_Node*);
    VarNode parseLogicalOrExp(exp_Node *);
    VarNode parseLogicalAndExp(exp_Node *);
    VarNode parseIncluOrExp(exp_Node*);
    VarNode parseIncluAndExp(exp_Node*);
    VarNode parseExcluOrExp(exp_Node*);
    VarNode parseAndExp(exp_Node*);
    VarNode parseEqualExp(exp_Node*);
    VarNode parseRelaExp(exp_Node*);
    VarNode parseShiftExp(exp_Node*);
    VarNode parseAddExp(exp_Node*);
    VarNode parseMulExp(exp_Node*);
    VarNode parsePostExp(exp_Node*);
    VarNode parsePrimExp(exp_Node*);
    void parseArugumentExp(exp_Node*, string);
    //*****************************************Sundry function***************************************
    bool lookupCurVar(string);
    VarNode lookupNode(string);
    string getIDname(declarator_Node* );
    ArrayNode getArryNode(string );
    VarNode createTempVar (string , type_specifier_kind);
    type_specifier_kind getFuncRType();
    int getBreakBlock();
    void error(int line,string error);
};

#endif /* parser_hpp */
