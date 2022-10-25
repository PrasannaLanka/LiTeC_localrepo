#include "symbol_table.h"
#include <stdio.h>
int main()
{
    char *p1="Jeevan";
    char *p2="sammeswar";
    char *p3="siddaboena";
    init_symbol_table();
    printf("B1 : %d \n",insert_symbol_tbl_lex(p1));
    printf("B2 :%d \n",insert_symbol_tbl_lex(p2));
    printf("B3 :%d \n",insert_symbol_tbl_lex(p1));



    terminate_symbol_table();
    return 0;
}