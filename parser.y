%{
   #include <stdio.h>
   #include <stdlib.h>
   int yylex(void);
   void yyerror(char *);
 
   extern FILE *yyin;
 
%}
 
%token DECLARE IF ELSE BREAK CONTINUE INVARIANT LOOP RETURN CONSTANT
%token BOOL CHAR INT DOUBLE ID STRING_LITERAL STRUCT
%token TEX TEX_OPEN TEX_CLOSE SF_OPEN SF_CLOSE
 
 
%start translation_main

translation_main
   : translation
   ;
 
translation
   : translation SF_OPEN translation_unit SF_CLOSE
   | SF_OPEN translation_unit SF_CLOSE
   ;
 
translation_unit
   : external_declaration
   | translation_unit external_declaration
   ;
 
external_declaration
   : declaration
   | function_definition
   ;

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



