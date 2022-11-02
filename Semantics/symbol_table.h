#include <stdbool.h>

#define MAX_SYMBOL_TABLE_SIZE 50
#define STACK_SIZE 10


static int table_size=0;
static int m=0;
// symbol table is implementated using hashing , each bucket has linked list 

// item is the entry in the symbol table .


// symbol table  data structures :  p->p->p->p-> ....... and each p pointes to p->  item* -> item*->  item*->......





enum data_type_t{char_t, int_t , double_t , float_t ,bool_t , void_t };
typedef enum id_type{ variable_t , function_t , struct_t , array_t  }id_type;

// only one data type can exist for a variable ,so respective value 
union Value
{
    int int_value;
    float float_value;
    double double_value;
    char char_value;
}typedef value_t;



//for array data_type , array_size
struct array_data
{
    enum data_type_t data_type;
    unsigned int array_size;
}typedef array_data_t;

struct parameter
{
    char *parameter_name;
    enum data_type_t parameter_data_type;
    struct parameter *next;

}typedef param;
// function data , return type ,parameters data_type list
struct function_data
{
    
    
    enum data_type_t return_data_type;
    int no_parameters;
    // paramter list ......
    param* parameters;


    
}typedef fun_data_t;



union identifier_data
{
    //array information array size , data type
    array_data_t array_info;

    //return type for function
    fun_data_t function_info;
}typedef id_data_t;




struct item_
{

    char* name;              // name of the identifier
    struct item_* next;
    enum data_type_t data_type;
    id_type iden_type;
    value_t value;
    id_data_t id_info;

}typedef item_t;

struct symbol_table
{
    item_t **symbol_table_t;
    struct symbol_table *parent;
}typedef symbol_table;

static symbol_table* tables[STACK_SIZE];
// item_t **symbol_table_t;
symbol_table *init_symbol_table();

//get hash key for the given identifier
unsigned int get_hash_key(char *id_name,int len);

// return true if sucessful insertion or false 
bool insert_symbol_tbl(item_t** symbol_table_t ,char* name , id_type iden_type , enum data_type_t data_type);


//search in table
item_t* search_in_symbol_table(item_t** symbol_table_t ,char* name);

//search in all tables from current scope to global scope table
item_t* search_in_all_sym_tbl(symbol_table *sym_tbl , char *name);

// create new symbol table for the new scope for the parent scope
symbol_table *init_child_symbol_table(symbol_table *parent);

//print symbol table 
void print_symbol_table();

// free the memory for the table
void terminate_symbol_table(item_t** symbol_table_t );

/*
    variable 
    function 
    array
    struct 
*/

void table_push(symbol_table* it);

symbol_table* table_pop();
symbol_table*  table_top();

void print_symbol_table(symbol_table *table);