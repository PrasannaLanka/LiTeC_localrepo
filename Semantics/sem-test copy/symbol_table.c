#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static item_t **symbol_table_t;
void init_symbol_table()
{
    printf("Init called \n");
    symbol_table_t=(item_t**)malloc(sizeof(item_t*)*MAX_SYMBOL_TABLE_SIZE);
    for (int i = 0; i < MAX_SYMBOL_TABLE_SIZE; i++)
    {
        symbol_table_t[i]=NULL;
    }
    
}

//using identifier name , generate an unsigned key 
unsigned int get_hash_key(char *id_name,int len)
{
    unsigned int key=0;

    for (int i = 0; i < len; i++)
    {
        key+=(int)id_name[i]-(int)id_name[i]%10;
    }
    key+=len+(int)id_name[len/2];
    return key%MAX_SYMBOL_TABLE_SIZE;
}


bool insert_symbol_tbl(char* name,enum data_type data_type_t , value_t val ,int scope , id_data_t data_info )
{

    size_t sz=strlen(name);
    int l = (int)sz;
    
    unsigned int key=get_hash_key(name,l);

    printf("Insertion phase : generated key for %s is %u\n",name,key);
    if (symbol_table_t[key]==NULL)
    {
        item_t *new_item=(item_t*)malloc(sizeof(item_t*));
        new_item->name=name;
        new_item->data_type_t=data_type_t;
        new_item->value_=val;
        new_item->scope=scope;
        new_item->data_info;
        new_item->next=NULL;
        symbol_table_t[key]=new_item;
        return true;
        
    }
    printf("Reached \n");
    item_t *head;
    head=symbol_table_t[key];
    item_t *it=head;
    while (it->next!=NULL)
    {
        //if already declared and exist in symbol table
        if (strcmp(it->name,name)==0)
        {
            /* give error */
            return false;
            break;
        }


        
        it=it->next;
    }
    if(it->next==NULL)
    {
        item_t *new_item=(item_t*)malloc(sizeof(item_t*));
        new_item->name=name;
        new_item->data_type_t=data_type_t;
        new_item->value_=val;
        new_item->scope=scope;
        new_item->data_info;
        new_item->next=NULL;
        it->next=new_item;
        
    }

    return true;
}



// search in symbol table and return item if exist or NULL if not.
item_t* search_in_symbol_table(char *name)
{
    size_t sz=strlen(name);
    int l = (int)sz;
    unsigned int key=get_hash_key(name,l);
    item_t *head=symbol_table_t[key];

    const char* p1=name;
    item_t *it=head;
    while (strcmp(p1,it->name)==1 && it!=NULL)
    {
        it=it->next;
    }
    return it;
}
