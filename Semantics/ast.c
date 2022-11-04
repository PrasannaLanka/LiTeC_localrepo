#include "ast.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

void print_ast(ast_node *node)
{
    
    // root left right
    printf("-- %s ",node->name);
    if (node->data_type)
    {
        //printf("Data_type : %d ",node->data_type);
    }
    
    if (node->left==NULL)
    {
        return;
    }
    else
    {
        print_ast(node->left);
    }
    if (node->right==NULL)
    {
        return ;
    }
    else
    {
        printf("\n");
        print_ast(node->right);
        
    }
    

}

data_type_s *get_type(enum data_type_t d)
{
    data_type_s *n=(data_type_s*)malloc(sizeof(data_type_s));
    n->data_type=d;
    return n;
}
