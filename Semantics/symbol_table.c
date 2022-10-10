#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static item_t **symbol_table_t;
void init_hash()
{
    symbol_table_t=(item_t**)malloc(sizeof(item_t*)*MAX_SYMBOL_TABLE_SIZE);
}

//using identifier name , generate an unsigned key 
unsigned int hash_key(char *id_name,int len)
{
    unsigned int key;

    for (int i = 0; i < len; i++)
    {
        key+=(int)id_name[i]-(int)id_name/2;
    }
    key+=len+(int)id_name[len/2];
    return key%MAX_SYMBOL_TABLE_SIZE;
}


unsigned int insert_symbol_tbl(char* name,enum data_type data_type_t , value_t val ,int scope , id_data_t data_info )
{

    size_t sz=strlen(name);
    int l = (int)sz;
    
    unsigned int key=hash_key(name,l);
    item_t *head;
    head=symbol_table_t[1];
    item_t *it=head;
    while (it!=NULL)
    {
        //if already declared and exist in symbol table
        if (it->name==name)
        {
            /* give error */
            break;
        }


        
        it=it->next;
    }
    if(it==NULL)
    {
        item_t *new_item=(item_t*)malloc(sizeof(item_t*));
        new_item->name=name;
        new_item->data_type_t=data_type_t;
        new_item->value_=val;
        new_item->scope=scope;
        new_item->data_info;
        it=new_item;
        
    }
    
    




}