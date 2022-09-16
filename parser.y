%{
   #include <stdio.h>
   #include <stdlib.h>
   int yylex(void);
   void yyerror(char *);
 
   extern FILE *yyin;
 
%}
 
%token DECLARE IF ELSE BREAK CONTINUE INVARIANT LOOP RETURN CONSTANT
%token BOOL CHAR INT DOUBLE ID STRING_LITERAL SF_OPEN SF_CLOSE STRUCT
%token TEX TEX_OPEN TEX_CLOSE
 
 
%start translation_main





