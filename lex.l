
D		     	[0-9]
L		     	[a-zA-Z]
H		     	[a-fA-F0-9]
E		     	[Ee][+-]?{D}+


%{
#include <stdio.h>
#include "parser.tab.h"

#include <stdlib.h>
#include <string.h>


void count();
%}

%%



"declare"		    { count();  return(DECLARE); }
"receive"		    { count(); return(RECEIVE); }
"if"			{ count();return(IF); }
"else"			{ count();return(ELSE); }
"break"			{ count();return(BREAK); }
"continue"		{ count();return(CONTINUE); }
"invariant"		{ count(); return(INVARIANT); }
"loop"			{ count();return(LOOP); }
"return"		{ count(); return(RETURN); }
"bool_1"		{ count();s return(BOOL_1); }
"char_8"		{ count(); return(CHAR_8); }
"int_64"		{ count(); return(INT_64); }
"double_128"		{ count(); return(DOUBLE_128); }

"TeX{"([^"}"])*"}"           { count(); return(TEX); }
{L}({L}|{D})*   { count(); return(ID);   }
"[:"			{ count(); return(TEX_OPEN); }
":]"			{ count(); return(TEX_CLOSE); }
"[{"			{ count(); return(SF_OPEN); }
"}]"			{ count(); return(SF_CLOSE); }
"[("			{ count(); return(MS_OPEN); }
")]"			{ count(); return(MS_CLOSE); }
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

	ECHO;
}

int k=1; 
int a=0; 
void enumeratred_comment()
{
    char a;
	int input_number = 0;
	
	while((int)(a = input()) <= 57 && (int)a >= 48)
	{
		putchar(a);
		input_number = temp*10;
		input_number += (int)a - 48;
	}
    if(a=0)
        {
        if(input_number != k)
            { printf("Inaccurate comment numbering error"); }
        a=1;
        }
    else
        {
        if(input_number != k)
           { printf("Inaccurate comment numbering error"); }
        a=0;
        k++;
        }

}
