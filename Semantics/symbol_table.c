#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



symbol_table *init_symbol_table()
{
    symbol_table *sym_tbl;
    
    sym_tbl->symbol_table_t=(item_t**)malloc(sizeof(item_t)*MAX_SYMBOL_TABLE_SIZE);
    for (int i = 0; i < MAX_SYMBOL_TABLE_SIZE; i++)
    {
        sym_tbl->symbol_table_t[i]=NULL;
    }
    sym_tbl->parent=NULL;

    return sym_tbl;
    
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


bool insert_symbol_tbl_lex(item_t** symbol_table_t ,char* name)
{

    size_t sz=strlen(name);
    int l = (int)sz;
    
    unsigned int key=get_hash_key(name,l);

    //printf("Insertion phase : generated key for %s is %u\n",name,key);
    if (symbol_table_t[key]==NULL)
    {
        item_t *new_item=(item_t*)malloc(sizeof(item_t));
        new_item->name=(char*)malloc(sizeof(name));
        strcpy(new_item->name,name);
        new_item->next=NULL;
        symbol_table_t[key]=new_item;
        return true;
        
    }
    else
    {
        printf("Reached \n");
        item_t *head=symbol_table_t[key];
        while (head->next!=NULL)
        {
            if (strcmp(head->name,name)==0)
            {
                return false;
            }
            
            head=head->next;
        }
        if(head->next==NULL && strcmp(head->name,name)==1)
        {
            item_t *new_item=(item_t*)malloc(sizeof(item_t*));
            new_item->name=(char*)malloc(sizeof(name));
            strcpy(new_item->name,name);
            new_item->next=NULL;
            head->next=new_item;
            return true;
            
        }

        return false;
    }
}



// search in symbol table and return item if exist or NULL if not.
item_t* search_in_symbol_table(item_t **symbol_table_t ,  char *name)
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

symbol_table *child_symbol_table(symbol_table *parent)
{
    symbol_table *child = init_symbol_table();
    child->parent=parent;
    return child;
}

void terminate_symbol_table(item_t** symbol_table_t )
{
    free(symbol_table_t);
}
