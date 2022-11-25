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

// int f = "c";
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

//int matrix[2][2];  int matrix2[2][1]=matrix    ; we should verify the dimensions of both matrix .
void check_declaration_helper(symbol_table *sym_tbl, ast_node *node)
{
    item_t *item1 =search_in_all_sym_tbl(sym_tbl,node->left->name);
    item_t *item2 = search_in_all_sym_tbl(sym_tbl,node->right->name);
    if (item1==NULL || item2==NULL)
    {
        printf("ERROR : identifier is undeclared at line %d \n  ",line_number);
        return;
    }
    if (item1->iden_type!=matrix_t || item2->iden_type!=matrix_t)
    {
        printf("ERROR : Both are not matrix at line %d \n",line_number);
        return ;
    }
    
    int mat1_row,mat1_col,mat2_row,mat2_col;

    mat1_row=item1->id_info.matrix_info.row;
    mat1_col=item1->id_info.matrix_info.column;
    
    mat2_row=item2->id_info.matrix_info.row;
    mat2_col=item2->id_info.matrix_info.column;

    if (mat1_row!=mat2_row)
    {
        printf("ERROR : rows are not matching at line  %d ",line_number);
        return ;
    }
    if (mat1_col!=mat2_col)
    {
        printf("ERROR : rows are not matching at line  %d ",line_number);
        return ;
    }
    
    return ;
    
}

// int matrix[5][5]=5; error 
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

// (+ m1[5][5] m2[4][5] )  // error 
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
//             printf("Scalar Multiplication with left variable as the matrix");
            return 0;
        }

        char *operator_div;
        operator_div="/";
        if(strcmp(parent->name, operator_div) == 0)
        {
            parent->isMatrix = 1;
            parent->matrix_info.row = left_node->matrix_info.row;
            parent->matrix_info.column = left_node->matrix_info.column;
//             printf("Scalar Division with left variable as the matrix");
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
//             printf("Scalar Multiplication with right variable as the matrix");
            return 0;
        }

        char *operator_div;
        operator_div="/";
        if(strcmp(parent->name, operator_div) == 0)
        {
            printf("ERROR: Scalar divided by a Matrix is Impossible\n");
            return 1;
        }

        printf("ERROR: Only Scalar Multiplication and Division are possible\n");
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
//                 printf("Both matrix matched \n ");
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
//                 printf("Both matrix matched \n ");
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
//                 printf("The two matrices can be multiplied\n");
                return 0;
            }
        }
    }

    printf("ERROR: Only Matrix Addition, Subtraction and Division are possible\n");
    return 1;
}

// int m[3][5] ;  m[5][5] = 90 ; //error 
int check_matrix_assignment(symbol_table *sym_tbl,ast_node *node)
{   
    if (node==NULL || node->name==NULL)
    {
        printf("Error occured while checking matrix assignment \n");
        return 0;  //return 0 means false 
    }
    
    item_t *item=search_in_all_sym_tbl(sym_tbl,node->name);
    if (item==NULL)
    {
        printf("ERROR :%s is not declared at line %d \n",node->name,line_number);
        return 0;
    }
    
    if (item->iden_type!=matrix_t)
    {
        printf("ERROR : %s is not matrix at line  %d \n",node->name,line_number);
        return 0 ; // return 0 means false 
    }

    if (item->data_type!=node->right->data_type)
    {
        printf("ERROR : incompatible data type assignment to %s at line %d \n",node->name,line_number);
        return 0;
    }
    
    int row=item->id_info.matrix_info.row;
    int col=item->id_info.matrix_info.column;
    char *index_ptr="matrix_index_prm";
    if (strcmp(index_ptr,node->left->name)==0)
    { 
        if (node->left->left->data_type!=int_t || node->left->right->data_type!=int_t)
        {
            return 0;
        }
        
        int given_row=atoi(node->left->left->name);
        int given_col=atoi(node->left->right->name);
        if (given_row>=row)
        {
            printf("ERROR : row is out of bound at line %d \n",line_number);
            return 0;
        }
        if (given_col>=col)
        {
            printf("ERROR : column is out of bound at line %d \n",line_number);
            return 0;
        }
        printf("ENtered \n ");
        return 1;
        
        
    }
    index_ptr="matrix_index";
    if (strcmp(index_ptr,node->left->name)==0)
    { 
        if (node->left->left->data_type!=int_t || node->left->right->data_type!=int_t)
        {
            return 0;
        }
        return 1;
        int given_row=atoi(node->left->left->name);
        int given_col=atoi(node->left->right->name);
        if (given_row>=row)
        {
            printf("ERROR : row is out of bound at line %d \n",line_number);
            return 0;
        }
        if (given_col>=col)
        {
            printf("ERROR : column is out of bound at line %d \n",line_number);
            return 0;
        }
        return 1;
           
    }

    else{printf("ERROR occured in matrix index at line %d \n",line_number);}
    


    



    return 0;
}

int check_array_assignment(symbol_table *sym_tbl,ast_node *node)
{

}