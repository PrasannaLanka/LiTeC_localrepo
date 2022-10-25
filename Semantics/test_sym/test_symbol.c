#include "../symbol_table.h"
#include <stdio.h>
#include <string.h>

int f1()
{
    
    char *p="function1";
   

    insert_symbol_tbl(p);
    item_t *it=search_in_symbol_table(p);
    if (it==NULL)
    {
        printf("Error\n");
        return 0;
    }
    
    printf("Name : %s \n",it->name);

    return 0;
}

int f2()
{
    
    char *p="function2";
   

    insert_symbol_tbl(p);
    item_t *it=search_in_symbol_table(p);
    if (it==NULL)
    {
        printf("Error\n");
        return 0;
    }
    
    printf("Name : %s\n",it->name);

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
    init_symbol_table();

    f1();
    f1();
    terminate_symbol_table();
    return 0;
}