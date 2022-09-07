D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
DS			(d|D)
IS			(i|I)*

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void count();
%}

%%


"declare"		    { count(); printf("  DECLARE\n"); /*return(DECLARE);*/ }
"receive"		    { count();printf("  RECEIVE\n"); /*return(RECEIVE);*/ }
"if"			{ count();printf("  IF\n"); /*return(IF);*/ }
"else"			{ count();printf("  ELSE\n"); /*return(ELSE);*/ }
"break"			{ count();printf("  BREAK\n"); /*return(BREAK);*/ }
"continue"		{ count();printf("  CONTINUE\n"); /*return(CONTINUE);*/ }
"invariant"		{ count();printf("  INVARIANT\n"); /*return(INVARIANT);*/ }
"loop"			{ count();printf("  LOOP\n"); /*return(LOOP); */}
"return"		{ count();printf("  RETURN\n"); /*return(RETURN);*/ }
"bool_1"		{ count();printf("  BOOL_1\n"); /*return(BOOL_1); */}
"char_8"		{ count();printf("  CHAR_8\n"); /*return(CHAR_8);*/ }
"int_64"		{ count();printf("  INT_64\n"); /*return(INT_64); */}
"double_128"		{ count();printf("  DOUBLE_128\n"); /*return(DOUBLE_128);*/ }

"TeX{"([^"}"])*"}"           { count();printf(" TEX\n"); /*return(TEX); */}
{L}({L}|{D})*   { count();printf("  ID\n"); /*return(ID);   */}
({D})*          {count(); printf("  Number\n") ;  }
"[:"			{ count();printf("  [:\n"); /*return(TEX_OPEN);*/ }
":]"			{ count();printf("  :]\n"); /*return(TEX_CLOSE); */}
"[{"			{ count();printf("  [{\n"); /*return(SF_OPEN); */}
"}]"			{ count();printf("  }]\n"); /*return(SF_CLOSE); */}
"[("			{ count();printf("  [(\n"); /*return(MS_OPEN); */}
")]"			{ count();printf("  )]\n"); /*return(MS_CLOSE); */}
"+"			{ count();printf("  PLUS\n"); /*return('+'); */}
"-"			{ count();printf("  MINUS\n"); /*return('-'); */}
"*"			{ count();printf("  MULTIPLY\n"); /*return('*'); */}
"/"			{ count();printf("  DIVIDE\n"); /*return('/'); */}
"%"			{ count(); /*return('%'); */}
"="			{ count();printf("  EQUAL\n"); /*return('='); */}
"<"			{ count();printf("  <\n"); /*return('<'); */}
">"			{ count();printf("  >\n"); /*return('>'); */}
"^"			{ count();printf("  ^\n"); /*return('^'); */}
"|"			{ count();printf("  |\n"); /*return('|'); */}
"~"			{ count();printf("  ~\n"); /*return('~'); */}
":"			{ count();printf("  :\n"); /*return(':'); */}
"&"			{ count();printf("  &\n"); /*return('&'); */}
"{"			{ count();printf("  {\n"); /*return('{'); */}
"}"			{ count();printf("  }\n"); /*return('}'); */}
"("			{ count();printf("  (\n"); /*return('('); */}
")"			{ count();printf("  )\n"); /*return(')'); */}
"["			{ count();printf("  [\n"); /*return('['); */}
"]"			{ count();printf("  ]\n"); /*return(']'); */}
"."         { count();printf("  .\n"); /*return('.'); */}
","			{ count();printf("  ,"); /*return(',');*/ }
";"			{ count();printf("  ;\n"); /*return(';'); */}
"!"			{ count(); /*return('!'); */}
"?"			{ count(); /*return('?'); */}
[ \n\t\f\v]             {}
<<EOF>>     return 0;
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

int main()
{
    yyin=fopen("input.txt","r");
    printf("opened\n");
    yylex();
    fclose(yyin);
    return 0;
 }
