#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



symbol_table *init_symbol_table()
{
    symbol_table *sym_tbl_t=(symbol_table*)malloc(sizeof(symbol_table));
    sym_tbl_t->symbol_table_t=(item_t**)malloc(sizeof(item_t)*MAX_SYMBOL_TABLE_SIZE);
    
    for (int i = 0; i < MAX_SYMBOL_TABLE_SIZE; i++)
    {
        //sym_tbl_t->symbol_table_t[i]=NULL;
    }
    sym_tbl_t->parent=NULL;

    return sym_tbl_t;
    
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


bool insert_symbol_tbl(item_t** symbol_table_t ,char* name , id_type iden_type, enum data_type_t data_type)
{

    size_t sz=strlen(name);
    int l = (int)sz;
    
    unsigned int key=get_hash_key(name,l);

    //printf("Insertion phase : generated key for %s is %u\n",name,key);
    if (symbol_table_t[key]==NULL)
    {
        item_t *new_item=(item_t*)malloc(sizeof(item_t));
        new_item->name=(char*)malloc(sizeof(name));
        new_item->iden_type=iden_type;
        new_item->data_type=data_type;
        strcpy(new_item->name,name);
        new_item->next=NULL;
        symbol_table_t[key]=new_item;
        //printf("\n inserted\n");
        return true;
        
    }
    else
    {
        //printf("Reached \n");
        item_t *head=symbol_table_t[key];
        while (head->next!=NULL)
        {
            if (strcmp(head->name,name)==0)
            {
                //printf("\n %s is already declared \n ",name);
                return false;
            }
            
            head=head->next;
        }
        if(head->next==NULL && strcmp(head->name,name)==1)
        {
            item_t *new_item=(item_t*)malloc(sizeof(item_t*));
            new_item->name=(char*)malloc(sizeof(name));
            new_item->iden_type=iden_type;
            new_item->data_type=data_type;
            strcpy(new_item->name,name);
            new_item->next=NULL;
            head->next=new_item;
            return true;
            
        }
        //printf("\n %s is already declared \n ",name);
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

symbol_table *init_child_symbol_table(symbol_table *parent)
{
    symbol_table *child = init_symbol_table();
    child->parent=parent;
    return child;
}

item_t* search_in_all_sym_tbl(symbol_table *sym_tbl , char *name)
{
    //we can optimise it by passing hash key from here , currently we are doing hasing in search in symbol table function
    item_t *it=search_in_symbol_table(sym_tbl->symbol_table_t,name);
    while (it==NULL)
    {
        it = search_in_all_sym_tbl(sym_tbl->parent,name);
    }
    return it;
}


void terminate_symbol_table(item_t** symbol_table_t )
{
    free(symbol_table_t);
}


////-------------------stack ---------------

void table_push(symbol_table* it)
{
    m++;
    //printf("\n m is %d\n",m);
    tables[table_size]=it;
    if (it)
    {
        //print_symbol_table(it);
        //printf("\nentered\n");
    }
    
    table_size++;
}

symbol_table* table_pop()
{
    table_size--;
    return tables[table_size];
}

symbol_table*  table_top()
{
    return tables[m-1];
}

void print_id_type(enum id_type id)
{
    if (id==variable_t)
    {
        printf("variable");
    }
    else if (id==function_param)
    {
        printf("parameter");
    }
    
    else if (id==function_t)
    {
        printf("function");
    }
    
    printf("\t");
    
}
void print_data_type(enum data_type_t data_type)
{
    switch (data_type)
    {
    case int_t:
        printf("int");
        break;
    case double_t:
        printf("double");
        break;
    case char_t:
        printf("char");
        break;
    case bool_t:
        printf("bool");
        break;
    default:
        printf("void");
        break;
    }
    printf("\n");
}

void print_data(item_t *item)
{
    //printf("Called\n");
    printf("Name : %s \t", item->name );
    print_id_type(item->iden_type);
    print_data_type(item->data_type);

    if (item->next!=NULL)
    {
        print_data(item->next);
    }
    
}

void print_symbol_table(symbol_table *table_t)
{
    item_t **sym_tbl;  

     
    sym_tbl=table_t->symbol_table_t;
    //printf("Called\n");
    if (table_t->parent!=NULL)
    {
        print_symbol_table(table_t->parent);   
    }
    for (int i = 0; i < MAX_SYMBOL_TABLE_SIZE; i++)
    {
        if(sym_tbl[i]!=NULL)
        {
            print_data(sym_tbl[i]);
        }
    }    
}