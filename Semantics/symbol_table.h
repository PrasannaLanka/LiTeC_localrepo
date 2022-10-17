#include <stdbool.h>

#define MAX_SYMBOL_TABLE_SIZE 200

// symbol table is implementated using hashing , each bucket has linked list 

// item is the entry in the symbol table .


// symbol table  data structures :  p->p->p->p-> ....... and each p pointes to p->  item* -> item*->  item*->......





enum data_type_t{ int_t , double_t , float_t , char_t ,array_t};


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
    value_t value;
    id_data_t id_info;
    int scope;

}typedef item_t;




item_t **symbol_table_t;
void init_symbol_table();

unsigned int get_hash_key(char *id_name,int len);

bool insert_symbol_tbl_lex(char* name,int scope);

item_t* search_in_symbol_table(char* name);


/*For Insertion */

enum data_type_t temp_data_type;
value_t *temp_value;

void store_data_type();











void terminate_symbol_table();

