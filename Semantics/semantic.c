#include "semantic.h"
#include "ast.h"

ast_node* nd;


//check function return type
void check_function_return(ast_node *node)
{
    char *c="fun_declr";
    ast_node *nd;
    if (strcmp(c,node->name)==1)
    {
        printf("Wrong_node \n");
        return ;
    }
    c=node->left->left->name; // c is data type in string .It can be "int", "double" , "bool"
    printf("%s",c);
    nd=node;
    



}
