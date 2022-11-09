#include "ast.h"
void check_function_return(ast_node *node);
void check_assignment(symbol_table* sym_tbl , ast_node *node);
void check_function_parameters(param* par,ast_node* node);