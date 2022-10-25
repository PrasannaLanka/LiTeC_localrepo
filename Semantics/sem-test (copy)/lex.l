
D		     	[0-9]
L		     	[a-zA-Z]



%{

#include <stdio.h>
#include "y.tab.h"
#include "symbol_table.h"
#include <string.h>
#include <stdlib.h>

#define MC yylval.token_node.name_token=(char*)malloc(sizeof(char)*5); strcpy(yylval.token_node.name_token,(yytext)) ;
char *param_name="Fixed";
value_t v; 
 
id_data_t d;

void count();




%}

%%

"int"		        {MC count(); return(INT);  }
"bool"
{L}({L}|{D})*   	{MC count(); return(ID);             }
					
{D}+				{MC count(); return(CONSTANT);       }



":"			{ count(); return(ASSG); }

";"			{ count(); return(END); }


%%

int yywrap(void)
{
	return 1;
}

void standard_comment()
{
	char a, b;
	
loop:
	while((a = input()) != '*' && a != 0)
		putchar(a);
	
	if((b = input()) != '/' && b != 0)
	{
		unput(b);
		goto loop;
	}
	
	if(a != 0)
		putchar(b);
}

int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}




