D			[0-9]
L			[a-zA-Z_]
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


"declare"		    { count(); return(DECLARE); }
"receive"		    { count(); return(RECEIVE); }
"if"			{ count(); return(IF); }
"else"			{ count(); return(ELSE); }
"break"			{ count(); return(BREAK); }
"continue"		{ count(); return(CONTINUE); }
"invariant"		{ count(); return(INVARIANT); }
"loop"			{ count(); return(LOOP); }
"return"		{ count(); return(RETURN); }
"bool_1"		{ count(); return(BOOL_1); }
"char_8"		{ count(); return(CHAR_8); }
"int_64"		{ count(); return(INT_64); }
"double_128"		{ count(); return(DOUBLE_128); }

"TeX"           { count(); return(TEX); }
{L}({L}|{D})*   
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
"."
","			{ count(); return(','); }
";"			{ count(); return(';'); }
"!"			{ count(); return('!'); }
"?"			{ count(); return('?'); }

%%
static int no_of_characters=0;
void count()
{
    no_of_characters++;
    printf("%d", no_of_characters);
}
int yywrap(void)
{
    return 1;
}

// int main()
// {
//     yylex();
//     return 0;
// }
