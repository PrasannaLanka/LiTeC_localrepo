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


function_definition
   :DECLARE declaration_specifiers declarator compound_statement
 
compound_statement
   : '{''}'
   |  '{' compound_statement_content '}'
   ;
 
compound_statement_content
   : declaration
   | statement
   | compound_statement_content declaration
   | compound_statement_content statement
   ;
 
statement
   : compound_statement
   | expression_statement
   | selection_statement
   | iteration_statement
   | jump_statement
   | tex_statement
   ;



