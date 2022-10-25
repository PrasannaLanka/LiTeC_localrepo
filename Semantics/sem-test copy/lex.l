
D		     	[0-9]
L		     	[a-zA-Z]



%{
#include <stdio.h>
#include "y.tab.h"
#include "symbol_table.h"
#include <string.h>
#include <stdlib.h>

char *param_name="Fixed";
value_t v; 
 
id_data_t d;

void count();
%}

%%






"return"		{ count(); return(RETURN); }

"int"		{ count(); return(INT);  }


{L}({L}|{D})*   {   fprintf(stderr,"In lex %s\n",yytext);
					  
					v.int_value=0;
					d.NA=false;
					fprintf(stderr,"line 4 \n");
					if( insert_symbol_tbl(param_name,UNDEF,v,0,d)==false )
					{
						//give error
						fprintf(stderr,"%s already declared \n",param_name);
					}    
					else
					{
						fprintf(stderr,"successfully inserted \n");
					}       
					                   
					count(); return(ID); 


				}
{D}+			{ count(); return(CONSTANT); }


"+"			{ count(); return('+'); }
"-"			{ count(); return('-'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }

":"			{ count(); return(':'); }

"{"			{ count(); return('{'); }
"}"			{ count(); return('}'); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }

";"			{ count(); return(';'); }



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
