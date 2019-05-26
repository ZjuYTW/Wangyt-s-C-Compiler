#ifndef block_hpp
#define block_hpp
#include <vector>
#include <map>

struct varNode{//这些个节点是把抽象语法树的那些节点做进一步的结合
    string name;
    string type;
    int num = -1;
    bool useAddress = false;
    
}；

struct funcNode{
    bool isdefinied = false;
    string name;
    string rettype;
    vector<varNode> paralist;
};

struct arrayNode{
    string name;
    string type;
    int num = -1;
};

class block{
public:
    funcNode func;
    bool isfunc = false;
    map<string, varNode> varMap;
    map<string, arrayNode> arrayMap;
    string breakLabelname;
    bool canBreak = false;
};

#endif /* block_hpp */
