%{
   #include <stdio.h>
   #include <stdlib.h>
   #include "symbol_table.h"
   int yylex(void);
   void yyerror(char *);
 
   extern FILE *yyin;
 
%}
 
%token  RETURN CONSTANT
%token  INT ID 
 
 
%start translation_main

%%


translation_main
   : translation
   ;
 
translation
   : external_declaration
   | translation external_declaration
   ;
 
external_declaration
   : declaration
   | function_definition
   ;

function_definition
   : type_specifier declarator compound_statement
 
compound_statement
   :  '{' compound_statement_content '}'
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
   | jump_statement
   ;

declaration
   :type_specifier init_declarator';'
   ;
 
jump_statement
  : RETURN ';'
  | RETURN expression ';'
  ;
 
expression_statement
   : expression ';'
   ;

expression
   : assignment_expression
   | primary_expression
   | postfix_expression
   ;
 
assignment_expression
   : ID ':' primary_expression
   | ID ':' postfix_expression
   ;


 
init_declarator
   : declarator
   | declarator ':' primary_expression
   | declarator ':' postfix_expression
   ;
 
declarator
   : ID
   | ID '('')'
   ;
 
postfix_expression
   : '(' binary_operator primary_expression primary_expression  ')'
   | '(' binary_operator primary_expression postfix_expression  ')'
   | '(' binary_operator postfix_expression primary_expression  ')'
   | '(' binary_operator postfix_expression postfix_expression  ')'
   ;
 
binary_operator
   : '+'
   | '-'
   | '*'
   | '/'
   | '%'
   ;

type_specifier
   : INT
   ;
 
primary_expression
   : CONSTANT
   | ID
   ;
%%
 
void yyerror(char *s)
{
   fprintf(stderr, "%s\n", s);
   return ;
} 
 
int main(int argc, char *argv[])
{
      init_symbol_table();

   	yyin=fopen(argv[--argc],"r");
		if (yyparse())
		{
			printf("\n Parsing error \n");
		}
		else
		{
			printf("\n parsing completed \n");
		}
		fclose(yyin);

		printf("\n Completed \n") ;
		return 0;
}