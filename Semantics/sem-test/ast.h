
struct ast_node_t
{
    char *name;
    

    struct ast_node_t* left;
    struct ast_node_t* right;
}typedef ast_node;

typedef enum{


    variable,
    constant,
    identifier,
    function






}token_types;

ast_node* build_node(char *name, ast_node *left, ast_node *right);