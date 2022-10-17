#include "ast.h"
#include <stdlib.h>
#include <string.h>

ast_node* build_node(char *name, ast_node *left, ast_node *right){

    //memory for new node
    ast_node *new_ast_node=(ast_node*)malloc(sizeof(ast_node));

    //memory for name 
    new_ast_node->name=(char*)malloc(sizeof(name));

    //assign node_name by name
    strcpy(new_ast_node->name,name);
    new_ast_node->left=left;
    new_ast_node->right=right;
    return new_ast_node;
}
