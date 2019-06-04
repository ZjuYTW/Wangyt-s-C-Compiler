#ifndef block_hpp
#define block_hpp
#include <vector>
#include <map>
#include "ast.hpp"


//这些个节点是把抽象语法树的那些节点做进一步的抽象提取
struct VarNode{
    string name;
    type_specifier_kind type;
    int num = -1;
    bool useAddress = false;
    int line;
    string boolstr;
};

struct FuncNode{
    bool isdefinied = false;
    string name;
    type_specifier_kind rettype;
    vector<VarNode> paralist;
};

struct ArrayNode{
    string name;
    type_specifier_kind type;
    int num = -1;
    int line;
};

class block{
public:
    FuncNode func;
    bool isfunc = false;
    map<string, VarNode> varMap;
    map<string, ArrayNode> arrayMap;
    string breakLabelname;
    bool canBreak = false;
};

#endif /* block_hpp */
