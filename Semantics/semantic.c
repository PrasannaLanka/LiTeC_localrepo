#include "semantic.h"

ast_node* nd;


//check function return type
void check_function_return(ast_node *node)
{
    char *c="fun_declr";
    enum data_type_t data_type;
    enum data_type_t void_type;
    void_type=void_t;
    ast_node *nd;
    if (strcmp(c,node->name)==1)
    {
        printf("Wrong_node \n");
        return ;
    }
    
    data_type=node->left->left->data_type; // c is data type in string .It can be "int", "double" , "bool"
    
    
    
    nd=node;

    nd=nd->left->right->right->right;// nd is return node
    //printf("name : %s \n",nd->name);
    c=";";
    if (strcmp(nd->name,c)==0)
    {   
        
        if (data_type==void_t)
        {
            return ;
        }
        else
        {
            printf("Return type error \n");
            return ;
        }
        
        
    }
    nd=nd->left;
    
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
void check_assignment(symbol_table* sym_tbl , ast_node *node)
{
    char *c="assignment";
    ast_node *nd ;
    item_t *item = search_in_all_sym_tbl(sym_tbl,node->name);
    if (item==NULL)
    {
        printf("Identifier not found \n");
        return;
    }
    enum data_type_t data_type=item->data_type;
    if (node->right->data_type==data_type)
    {
        return ;
    }
    else
    {
        printf("Type mismatch \n");
        return ;
    }    
}

void check_function_parameters(param* par,ast_node* node)
{
    char *c="id_list";
    if ((node==NULL && par!=NULL) || (node!=NULL && par==NULL))
    {
        printf("function parameters not matched \n ");
        return ;
    }
    if (node==NULL && par==NULL)
    {
        return ;
    }
    
    
    if (strcmp(node->name,c)==0)
    {
        if(node->right->data_type==par->parameter_data_type)
        {
            if (par->next && node->left)
            {
                check_function_parameters(par->next,node->left);
                return;
            }
            if (par->next==NULL && node->left==NULL)
            {
                return ;
            }
        }
        else
        {
            printf("Function parameter doesn't match \n");
            return ;
        }
    }

    if (node->data_type!=par->parameter_data_type)
    {
        printf("Function parameter doesn't match \n");
        return ;
    }
    //printf("Matched ra hawle \n ");
    
}
