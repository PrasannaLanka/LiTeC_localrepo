#include "symbol_table.h"


struct ast_node_t
{
    char *name;
    value_t value;

    struct ast_node_t* left;
    struct ast_node_t* right;
}typedef ast_node;



typedef enum{
    variable,
    constant,
    identifier,
    function
}token_types;

static ast_node *root;
ast_node* build_node(char *name, ast_node *left, ast_node *right);
void print_ast(ast_node *node);