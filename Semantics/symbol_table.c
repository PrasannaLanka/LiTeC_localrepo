#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static item_t **symbol_table_t;
void init_symbol_table()
{
    symbol_table_t=(item_t**)malloc(sizeof(item_t*)*MAX_SYMBOL_TABLE_SIZE);
}

//using identifier name , generate an unsigned key 
unsigned int get_hash_key(char *id_name,int len)
{
    key = key + 1;
    
    if(key >= 100)
    {
        key = 0;
    }
    
    return key;
}


unsigned int insert_symbol_tbl(char* name,enum data_type data_type_t , value_t val ,int scope , id_data_t data_info )
{

    size_t sz=strlen(name);
    int l = (int)sz;
    
    unsigned int key=get_hash_key(name,l);
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
        new_item->next=NULL;
        it=new_item;
        
    }
    
    




}



// search in symbol table and return item if exist or NULL if not.
item_t* search_in_symbol_table(char *name)
{
    size_t sz=strlen(name);
    int l = (int)sz;
    unsigned int key=get_hash_key(name,l);
    item_t *head=symbol_table_t[key];

    item_t *it=head;
    while (*(it->name)!=*name && it!=NULL)
    {
        it=it->next;
    }
    return it;
}
