#include "parser.hpp"


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

void parser::parseFunc(func_Node* fNode){
    type_specifier_kind cur_type = fNode->type;
    declarator_Node *func_declarator = fNode->func_name;
    declaration_Node *param_list = fNode->decl_list;
    
    if(func_declarator->next != NULL){
        cout << "ERROR: too many function name" <<endl;
    }
    else{
        
    }
}

void parser::parseDecl(declaration_Node* dNode){
    
}


