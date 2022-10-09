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



union data_type_info
{
    //array information array size , data type
    array_info_t array_inf;

    //return type for function
    enum data_type return_type;
}data_type_info_t;


struct item_
{
    char* name;

    value_t value_;

    int scope;

    enum data_type data_type_t;
    data_type_info_t data_info;




    struct item_* next;
};





void init_hash();

unsigned int hash_key();

void insert(char* name,   value_t val , );


