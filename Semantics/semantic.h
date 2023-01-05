#include "ast.h"
void check_function_return(ast_node *node);
void check_assignment(symbol_table* sym_tbl , ast_node *node);
void check_declaration(ast_node *node);
void check_function_parameters(param* par,ast_node* node);

int check_matrix(ast_node *parent ,ast_node *left_node , ast_node *right_node);

int check_matrix_assignment(symbol_table *sym_tbl,ast_node *node);
void check_declaration_helper(symbol_table *sym_tbl, ast_node *node);

int check_array_assignment(symbol_table *sym_tbl,ast_node *node);
