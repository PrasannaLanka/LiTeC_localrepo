
D		     	[0-9]
L		     	[a-zA-Z]


%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include <string.h>

#define MC yylval.token_node.name_token=(char*)malloc(sizeof(yytext)); strcpy(yylval.token_node.name_token,yytext);
#define MC_ID yylval.token_id.name_token=(char*)malloc(sizeof(yytext)); strcpy(yylval.token_id.name_token,yytext);
int line_number = 1;

void count();
%}

%%




"declare"   {count() ; return(DECLARE);}



"bool"			{ count(); return(BOOL); }
"char"			{ count(); return(CHAR); }
"int"			{ count(); return(INT);  }
"double"		{ count(); return(DOUBLE); }
"struct"		{ count(); return(STRUCT); }

"if"			{ count(); return(IF); }
"else"			{ count(); return(ELSE); }
"loop"			{ count(); return(LOOP); }
"continue"		{ count(); return(CONTINUE); }
"break"			{ count(); return(BREAK); }
"TeX"			{ count(); return(TEX); }

"void"			{ count(); return(VOID); }
"return"		{count(); return(RETURN); }

"true"			{count(); return(TRUE); }

"false"			{count(); return(FALSE); }



{L}({L}|{D})*   {   MC_ID 	count(); return(ID); }



{D}+			{MC count(); return(CONSTANT_INT); }
\"(\\.|[^\\"])\"	{MC count(); return(CONSTANT_CHAR); }
\"(\\.|[^\\"])*\"	{MC count(); return(STRING_LITERAL); }

"[:"			{ count(); return(TEX_OPEN); }
":]"			{ count(); return(TEX_CLOSE); }

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
"!"			{ count(); return('!'); }
"?"			{ count(); return('?'); }

[\n] 		{line_number++;}

.			{}

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

int column;

void count()
{
	int i;
	column = 1;
	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 1;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	//ECHO;
}
