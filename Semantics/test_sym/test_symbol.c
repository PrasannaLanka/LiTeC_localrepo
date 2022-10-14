#include "../symbol_table.h"
#include <stdio.h>
#include <string.h>

int f1()
{
    init_symbol_table();
    char *p="function";
    id_data_t d;
    d.function_info.no_parameters=3;
    d.function_info.return_data_type=int_t;
    value_t v;
    v.int_value=0;
    enum data_type f=int_t;

    insert_symbol_tbl(p,f,v,1,d);
    item_t *it=search_in_symbol_table(p);
    if (it==NULL)
    {
        printf("Error\n");
        return 0;
    }
    
    printf("Name : %s \n return data_type : %d \n parameters : %d ",it->name,it->data_info.function_info.return_data_type,it->data_info.function_info.no_parameters);

    return 0;
}

void key()
{
    char *p="Function";
    size_t sz=strlen(p);
    int l = (int)sz;
    unsigned int k=get_hash_key(p,l);
    printf("l is : %d key is %u\n",l,k);
    return ;
}

int main()
{

    f1();
    return 0;
}