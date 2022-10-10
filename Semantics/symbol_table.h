#define MAX_SYMBOL_TABLE_SIZE 200

// symbol table is implementated using hashing , each bucket has linked list 

// item is the entry in the symbol table .


// symbol table  data structures :  p->p->p->p-> ....... and each p pointes to p->  item* -> item*->  item*->......





enum data_type{ int_t , double_t , float_t , char_t ,array_t};


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
    enum data_type data_type_t;
    unsigned int array_size;
}typedef array_data_t;

// function data , return type ,parameters data_type list
struct function_data
{
    enum data_type return_data_type;
    int no_parameters;
    // paramter list ......
    
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
    enum data_type data_type_t;    // data type of the variable
    value_t value_;               // value of the variable

    int scope;                      // scope of the variable

    /*if the identifier is function , array  then id_data is used for extra information*/  
    id_data_t data_info;            




    struct item_* next;
}typedef item_t;





void init_hash();

unsigned int hash_key();

void insert(char* name,enum data_type data_type_t , value_t val ,int scope , id_data_t data_info );


