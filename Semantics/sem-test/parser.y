%{
   #include <stdio.h>
   #include <stdlib.h>
   #include "symbol_table.h"
   int yylex(void);
   void yyerror(char *);
 
   extern FILE *yyin;
 
%}
 
%token DECLARE IF ELSE BREAK CONTINUE INVARIANT LOOP RETURN CONSTANT
%token BOOL CHAR INT DOUBLE VOID ID STRING_LITERAL STRUCT
%token TEX TEX_OPEN TEX_CLOSE 
 
 
%start translation_main

%%


translation_main
	: translation_unit
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
	:declaration_specifiers declarator compound_statement

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

tex_statement
	: TEX '{' tex_data '}'
	;

tex_data
	: STRING_LITERAL
	| tex_function
	| tex_data STRING_LITERAL
	| tex_data tex_function
	; 

tex_function
	: TEX_OPEN declarator TEX_CLOSE
	;



declaration
	:DECLARE  declaration_specifiers init_declarator_list ';'
	|DECLARE  INVARIANT declaration_specifiers init_declarator_list ';'
	|DECLARE  STRUCT '{'  declaration DECLARE  declaration_specifiers init_declarator_list ';'  '}' ';'
	|DECLARE  STRUCT '{'  declaration DECLARE  INVARIANT declaration_specifiers init_declarator_list ';'  '}' ';'
	;



declaration_specifiers
	: type_specifier
	;

selection_statement
   : IF '(' logical_expression ')' compound_statement
   | IF '(' logical_expression ')' compound_statement ELSE compound_statement
   ;

iteration_statement
   : LOOP '(' expression_statement expression_statement ')' statement
   | LOOP '(' expression_statement expression_statement expression ')' statement
   ;

 
jump_statement
   : CONTINUE ';'
   | BREAK ';'
   | RETURN ';'
   | RETURN expression ';'
   ;

expression_statement
	: ';'
	|  expression ';'
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

init_declarator_list
	: init_declarator
	;

init_declarator
	: declarator
	| declarator ':' primary_expression
	| declarator ':' postfix_expression
	;

declarator
	: ID
	| ID '('')' 
	| ID '(' parameter_type_list ')'
	| ID '(' parameter_list ')'
	;


parameter_type_list
	: type_specifier ID
	| parameter_type_list ',' type_specifier ID
	;

parameter_list
	: ID
	| parameter_list ',' ID
	;

postfix_expression
	: '(' binary_operator primary_expression primary_expression  ')'
	| '(' binary_operator primary_expression postfix_expression  ')'
	| '(' binary_operator postfix_expression primary_expression  ')'
	| '(' binary_operator postfix_expression postfix_expression  ')'
	;

logical_expression
	: primary_expression
	| expression logical_operator expression
	;

binary_operator
	: '+'
	| '-'
	| '*'
	| '/'
	| '%'
	| '<'
	| '>'
	| '='
	;

logical_operator
	: '<'
	| '>'
	| '='
	;


type_specifier
	: CHAR
	| INT
	| DOUBLE
   | BOOL
	| STRUCT
	| VOID
	;

primary_expression
	: CONSTANT
	| ID
	| STRING_LITERAL
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