#include "symbol_table.h"



void init_hash()
{

    
}

//using identifier name , generate an unsigned key 
unsigned int hash_key(char id_name[],int len)
{
    unsigned int key;

    for (int i = 0; i < len; i++)
    {
        key+=(int)id_name[i]-(int)id_name/2;
    }
    key+=len+(int)id_name[len/2];
    return key%MAX_HASH_SIZE;
}


unsigned int insert_symbol_tbl()
{




}