#define MAX_HASH_SIZE 200

// symbol table is implementated using hashing , each bucket has linked list 

// item is the entry in the symbol table .




enum data_type{ int_t , double_t , float_t , char_t ,array_t};

union Value
{
    int int_value;
    float float_value;
    double double_value;
    char char_value;
}typedef value_t;


union array_info
{
    enum data_type data_type_t;
    unsigned int array_size;
}typedef array_info_t;

union function_info
{
    
}typedef fun_info;



union identifier_data
{
    //array information array size , data type
    array_info_t array_inf;

    //return type for function
    enum data_type return_type;
}typedef id_data;


struct item_
{
    char* name;

    value_t value_;

    int scope;

    enum data_type data_type_t;
    id_data data_info;




    struct item_* next;
};





void init_hash();

unsigned int hash_key();

void insert(char* name,   value_t val , );


