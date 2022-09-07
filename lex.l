D			[0-9]
L			[a-zA-Z]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
DS			(d|D)
IS			(i|I)*

%{
#include <stdio.h>
#include "parser.tab.h"

void count();
%}

%%

"Tex"			{ count(); }
"/*"			{ standard_comment(); }
"!"			{ enumerated_comment(); }

"bool_1"		{ count(); return(BOOL_1); }
"break"			{ count(); return(BREAK); }
"char_8"		{ count(); return(CHAR_8); }
"continue"		{ count(); return(CONTINUE); }
"declare"		{ count(); return(DECLARE); }
"double_128"		{ count(); return(DOUBLE_128); }
"else"			{ count(); return(ELSE); }
"if"			{ count(); return(IF); }
"int_64"		{ count(); return(INT_64); }
"invariant"		{ count(); return(INVARIANT); }
"loop"			{ count(); return(LOOP); }
"return"		{ count(); return(RETURN); }
"void"			{ count(); return(VOID); }

"[:"			{ count(); return(TEX_OPEN); }
":]"			{ count(); return(TEX_CLOSE); }
"[{"			{ count(); return(SUBFILE_OPEN); }
"}]"			{ count(); return(SUBFILE_CLOSE); }
"[("			{ count(); return(MAINSECTION_OPEN); }
")]"			{ count(); return(MAINSECTION_CLOSE); }
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
"."			{ count(); return('.'); }
","			{ count(); return(','); }
";"			{ count(); return(';'); }

[ \t\n]			{ count(); }
.

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

int num = 1;
int pair = 0;
void enumerated_comment()
{
	char a;
	int temp = 0;
	
	while((int)(a = input()) <= 57 && (int)a >= 48)
	{
		putchar(a);
		temp = temp*10;
		temp += (int)a - 48;
	}
	
	if(temp == num)
	{
		if(pair == 0)
		{
			pair = 1;
		}
		else
		{
			pair = 0;
			if((a = input()) == " ")
			{
				if((a = input()) == "/")
				{
					if((a = input() == "*")
					{
						standard_comment():
					}
				}
			}
			num++;
		}
	}
}
