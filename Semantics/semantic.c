#include "semantic.h"
extern int line_number;
ast_node *nd;

// check function return type
void check_function_return(ast_node *node)
{
    char *c = "fun_declr";
    enum data_type_t data_type;
    enum data_type_t void_type;
    void_type = void_t;
    ast_node *nd;
    if (strcmp(c, node->name) == 1)
    {
        printf("Wrong_node \n");
        return;
    }


    data_type = node->left->left->data_type; // c is data type in string .It can be "int", "double" , "bool"

    // printf("%s ",c);

    nd = node;

    nd = nd->left->right->right->right; // nd is return node
    // printf("name : %s \n",nd->name);
    c = ";";
    if (strcmp(nd->name, c) == 0)
    {

        if (data_type == void_t)
        {
            return;
        }
        else
        {
            printf("ERROR: Return type is not compatible with function at line %d\n", line_number);
            return;
        }
    }

    nd = nd->left;
   

    c = "prm_exp";
    if (strcmp(c, nd->name) == 0)

    {
        // check primary exp like constant number , c , id .
        if (data_type != nd->data_type)
        {
            printf("ERROR: Return type is not compatible with function at line %d\n", line_number);
        }
    }
}
void check_assignment(symbol_table *sym_tbl, ast_node *node)
{
    char *c = "assignment";
    ast_node *nd;
    item_t *item = search_in_all_sym_tbl(sym_tbl, node->name);
    if (item == NULL)
    {
        printf("ERROR: Identifier not found at line %d\n", line_number);
        return;
    }
    enum data_type_t data_type = item->data_type;
    if (node->right->data_type == data_type)
    {
        if(node->right->isMatrix == 1 && item->iden_type == matrix_t)
        {
            node->isMatrix = 1;
            return;
        }
        else if(node->right->isMatrix == 1 && item->iden_type != matrix_t)
        {
            printf("ERROR: Matrix cannot be assigned to a Scalar\n");
            return;
        }
        else if(node->right->isMatrix != 1 && item->iden_type == matrix_t)
        {
            printf("ERROR: Scalar cannot be assigned to a Matrix\n");
            return;
        }
        return;
    }
    else
    {
        printf("ERROR: Type mismatch at line %d\n", line_number);
        return;
    }
}

void check_declaration(ast_node *node)
{
    if(node->right->data_type == node->left->data_type)
    {
        if(node->right->isMatrix == 1 && node->left->isMatrix == 1)
        {
            node->isMatrix = 1;
            return;
        }
        else if(node->right->isMatrix == 1 && node->left->isMatrix == 0)
        {
            printf("ERROR: Matrix cannot be assigned to a Scalar\n");
            return;
        }
        else if(node->right->isMatrix == 0 && node->left->isMatrix == 1)
        {
            printf("ERROR: Scalar cannot be assigned to a Matrix\n");
            return;
        }
        return;
    }
    else
    {
        printf("ERROR: Type mismatch at line %d\n", line_number);
        return;
    }
}

void check_function_parameters(param *par, ast_node *node)
{
    char *c = "id_list";
    
    if ((node == NULL && par != NULL) || (node != NULL && par == NULL))
    {
        printf("ERROR: Invalid function arguments at line %d\n", line_number);
        return;
    }
    if (node == NULL && par == NULL)
    {  
        return;
    }

    if (strcmp(node->name, c) == 0)
    {
    
        if (node->right->data_type == par->parameter_data_type)
        {
            
            if (par->next && node->left)
            {
                
                check_function_parameters(par->next, node->left);
                return;
            }
            if (par->next == NULL && node->left == NULL)
            {
                return;
            }
            if ((node->left == NULL && par->next != NULL) || (node->left != NULL && par->next == NULL))
            {
                printf("ERROR: Invalid function arguments at line %d\n", line_number);
                return;
            }
            if (node == NULL && par == NULL)
            {
                return;
            }
        }
        else
        {
            
            // printf("Function parameter doesn't match \n");
            printf("ERROR: Invalid function arguments at line %d\n", line_number);
            return;
        }
        
    }
    
    if (node->data_type == par->parameter_data_type)
    {
                if ((node->left == NULL && par->next != NULL) || (node->left != NULL && par->next == NULL))
                {
                    printf("ERROR: Invalid function arguments at line %d\n", line_number);
                    return;
                }
        return ;
    }
    
    else
    {
        printf("ERROR: Invalid function arguments at line %d\n", line_number);
        return;
    }
}

int check_matrix(ast_node *parent , ast_node *left_node , ast_node *right_node){
    if(left_node->isMatrix == 1 && right_node->isMatrix == 0)
    {
        char *operator_mul;
        operator_mul="*";
        if(strcmp(parent->name, operator_mul) == 0)
        {
            parent->isMatrix = 1;
            parent->matrix_info.row = left_node->matrix_info.row;
            parent->matrix_info.column = left_node->matrix_info.column;
            printf("Scalar Multiplication with left variable as the matrix");
            return 0;
        }

        char *operator_div;
        operator_div="/";
        if(strcmp(parent->name, operator_div) == 0)
        {
            parent->isMatrix = 1;
            parent->matrix_info.row = left_node->matrix_info.row;
            parent->matrix_info.column = left_node->matrix_info.column;
            printf("Scalar Division with left variable as the matrix");
            return 0;
        }

        printf("ERROR: Only Scalar Multiplication and Division are possible\n");
        return 1;
    }
    else if(left_node->isMatrix == 0 && right_node->isMatrix == 1)
    {
        char *operator_mul;
        operator_mul="*";
        if(strcmp(parent->name, operator_mul) == 0)
        {
            parent->isMatrix = 1;
            parent->matrix_info.row = right_node->matrix_info.row;
            parent->matrix_info.column = right_node->matrix_info.column;
            printf("Scalar Multiplication with right variable as the matrix");
            return 0;
        }

        char *operator_div;
        operator_div="/";
        if(strcmp(parent->name, operator_div) == 0)
        {
            printf("ERROR: Scalar divided by a Matrix is Impossible\n");
            return 1;
        }

        printf("Only Scalar Multiplication and Division are possible\n");
        return 1;
    }
    else
    {
        char *operator_add;
        operator_add="+";
        if (strcmp(parent->name,operator_add)==0)
        {
            if (left_node->matrix_info.row!=right_node->matrix_info.row)
            {
                printf("ERROR: no of rows didn't matched \n ");
                return 1;
            }
            if (left_node->matrix_info.column!=right_node->matrix_info.column)
            {
                printf("ERROR: no of columns didn't matched \n ");
                return 1;
            }
            else
            {
                parent->isMatrix=1;
                parent->matrix_info.row=left_node->matrix_info.row;
                parent->matrix_info.column=left_node->matrix_info.column;
                printf("Both matrix matched \n ");
                return 0;
            }
            
        }

        char *operator_sub;
        operator_add = "-";
        if(strcmp(parent->name, operator_add) == 0)
        {
            if (left_node->matrix_info.row != right_node->matrix_info.row)
            {
                printf("ERROR: No of rows didn't matched \n ");
                return 1;
            }
            if (left_node->matrix_info.column != right_node->matrix_info.column)
            {
                printf("ERROR: No of columns didn't matched \n ");
                return 1;
            }
            else
            {
                parent->isMatrix = 1;
                parent->matrix_info.row = left_node->matrix_info.row;
                parent->matrix_info.column = left_node->matrix_info.column;
                printf("Both matrix matched \n ");
                return 0;
            }
            
        }

        char *operator_mul;
        operator_mul = "*";
        if(strcmp(parent->name, operator_mul) == 0)
        {
            if(left_node->matrix_info.column != right_node->matrix_info.row)
            {
                printf("ERROR: No of columns in the left matrix didn't match with the No of rows in the right matrix\n");
                return 1;
            }
            else
            {
                parent->isMatrix = 1;
                parent->matrix_info.row = left_node->matrix_info.row;
                parent->matrix_info.column = right_node->matrix_info.column;
                printf("The two matrices can be multiplied\n");
                return 0;
            }
        }
    }

    printf("ERROR: Only Matrix Addition, Subtraction and Division are possible\n");
    return 1;
}

