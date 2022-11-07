#include "semantic.h"

ast_node* nd;


//check function return type
void check_function_return(ast_node *node)
{
    char *c="fun_declr";
    enum data_type_t data_type;
    ast_node *nd;
    if (strcmp(c,node->name)==1)
    {
        printf("Wrong_node \n");
        return ;
    }
    data_type=node->left->left->data_type; // c is data type in string .It can be "int", "double" , "bool"
    printf("%s",c);
    nd=node;
    nd=nd->left->right->right->right->left;// nd is return node
    printf("%s \n",nd->name);
    printf("name : %d \n",nd->data_type);

    c="prm_exp";
    if (strcmp(c,nd->name)==0)
    {
        //check primary exp like constant number , c , id .
        if (data_type!=nd->data_type)
        {
            printf("return type error \n");
        }
        
    }
    



}
