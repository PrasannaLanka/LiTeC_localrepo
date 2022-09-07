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

“Tex”			{ count(); }
“/*"			{ comment(); }

“declare”		{ count(); return(DECLARE); }
“if”			{ count(); return(IF); }
“else”			{ count(); return(ELSE); }
“break”			{ count(); return(BREAK); }
“continue”		{ count(); return(CONTINUE); }
“invariant”		{ count(); return(INVARIANT); }
“loop”			{ count(); return(LOOP); }
“return”		{ count(); return(RETURN); }

“bool_1”		{ count(); return(BOOL_1); }
“char_8”		{ count(); return(CHAR_8); }
“int_64”		{ count(); return(INT_64); }
“double_128”		{ count(); return(DOUBLE_128); }

“[:”			{ count(); return(TEX_OPEN); }
“:]”			{ count(); return(TEX_CLOSE); }
“[{“			{ count(); return(SUBFILE_OPEN); }
“}]”			{ count(); return(SUBFILE_CLOSE); }
“[(“			{ count(); return(MAINSECTION_OPEN); }
“)]”			{ count(); return(MAINSECTION_CLOSE); }
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
“{“			{ count(); return('{'); }
“}”			{ count(); return('}'); }
“(“			{ count(); return('('); }
“)”			{ count(); return(')'); }
“[“			{ count(); return('['); }
“]”			{ count(); return(']'); }
“.”			{ count(); return('.'); }
“,”			{ count(); return(','); }
“;”			{ count(); return(';'); }

[ \t\n]			{ count(); }
.

int yywrap(void)
{
	return 1;
}

void comment()
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

