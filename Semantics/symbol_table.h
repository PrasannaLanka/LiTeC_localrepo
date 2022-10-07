#define MAX_HASH_SIZE 200



enum data_type={ int , double , float , char }

union Value
{
    int int_value;
    float float_value;
    double double_value;
    char char_value;
}typedef value_t;





struct item_
{
    char* name;

    value_t value_;

    data_type data_type_t;




    struct item_* next;
};





void init_hash();

unsigned int hash_key();

void insert(char* name,   value_t val , );


