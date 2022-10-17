
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


"if"			{ count();return(IF); }
"else"			{ count();return(ELSE); }
"break"			{ count();return(BREAK); }
"continue"		{ count();return(CONTINUE); }
"invariant"		{ count(); return(INVARIANT); }
"loop"			{ count();return(LOOP); }
"return"		{ count(); return(RETURN); }

"bool"		{ count(); return(BOOL); }
"char"		{ count(); return(CHAR); }
"int"		{ count(); return(INT);  }
"double"		{ count(); return(DOUBLE); }
"struct"		{ count(); return(STRUCT); }

"void"			{ count(); return(VOID); }


"TeX"           { count(); return(TEX); }
"[:"			{ count(); return(TEX_OPEN); }
":]"			{ count(); return(TEX_CLOSE); }


{L}({L}|{D})*   {   param_name=(char*)malloc(sizeof(yytext));
					strcpy(param_name,yytext);
					if( insert_symbol_tbl_lex(param_name)==false )     
					{
						// if identifier already in symbol table
						//give error
						fprintf(stderr,"%s already declared \n",param_name);
					}    
					else
					{
						fprintf(stderr,"successfully inserted \n");
					}       
					                   
					count(); return(ID);                            }


					
{D}+			{ count(); return(CONSTANT); }
\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }

"+"			{ count(); return('+'); }
"-"			{ count(); return('-'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"="			{ count(); return('='); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"~"			{ count(); return('~'); }
":"			{ count(); return(':'); }
"&"			{ count(); return('&'); }
"{"			{ count(); return('{'); }
"}"			{ count(); return('}'); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
"["			{ count(); return('['); }
"]"			{ count(); return(']'); }
"."         { count(); return('.'); }
","			{ count(); return(','); }
";"			{ count(); return(';'); }
"!"			{ count(); return('!'); }
"?"			{ count(); return('?'); }


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

	//ECHO;
}



