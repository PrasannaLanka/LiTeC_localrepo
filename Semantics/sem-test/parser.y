%{
    #include <stdio.h>
	#include <stdlib.h>

	
	#include "ast.h"

    int yylex(void);
    void yyerror(char *); 

	extern FILE *yyin;

	char* ptr;

%}

%union
{
	struct token_node_t{
		char *name_token;
		struct ast_node_t *node;
	}token_node;
}



%token <token_node> DECLARE INVARIANT 
%token CONSTANT_INT CONSTANT_CHAR CONSTANT_FLOAT CONSTANT_DOUBLE
%token <token_node> BOOL CHAR INT DOUBLE VOID ID STRING_LITERAL STRUCT


%type  <token_node> translation_main translation_unit external_declaration declaration function_definition
%type <token_node>  declarator compound_statement compound_statement_content
%type <token_node>  statement expression_statement 
%type <token_node>  init_declarator type_specifier expression
%type <token_node> assignment_expression primary_expression postfix_expression logical_operator
%type <token_node> binary_operator parameter_list

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
	:type_specifier declarator compound_statement   {ptr="fun_def"; $$.node=build_node(ptr,)}

compound_statement
	:  '{' compound_statement_content '}' { ptr="cmp_stmt"; $$.nd=build_node(ptr,$2.nd,NULL); }
	;

compound_statement_content
	: declaration							   {ptr="cmp_stmt"; $$.nd=build_node(ptr,$1.nd,NULL);}
	| statement									{ptr="cmp_stmt"; $$.nd=build_node(ptr,$1.nd,NULL);}
	| compound_statement_content declaration  {ptr="cmp_stmt"; $$.nd=build_node(ptr,$1.nd,$2.nd);}
	| compound_statement_content statement     {ptr="cmp_stmt"; $$.nd=build_node(ptr,$1.nd,$2.nd);}
	;

statement
	: compound_statement                {ptr="comp_st"; $$.nd=build_node(ptr,$1.nd,NULL);}
	| expression_statement			{ptr="comp_st"; $$.nd=build_node(ptr,$1.nd,NULL);}
	;





declaration
	:DECLARE  type_specifier init_declarator ';'			{ptr="declr"; $$.nd=build_node(ptr,$2.nd,$3.nd);}  
	;





expression_statement
	:   expression ';'                  { $$.nd=build_node($1.name_token,$1.nd,NULL); }
	;


expression
	: assignment_expression						{ptr="assign_exp"; $$.nd=build_node(ptr,$1.nd,NULL); }
	| primary_expression						{ptr="prm_exp"; $$.nd=build_node(ptr,$1.nd,NULL); }
	| postfix_expression						{ptr="post_exp"; $$.nd=build_node(ptr,$1.nd,NULL); }
	;

assignment_expression
	: ID ':' primary_expression			{ptr="assignment";$$.nd=build_node(ptr,$1.nd,$3.nd);}
	| ID ':' postfix_expression			{ptr="assignment";$$.nd=build_node(ptr,$1.nd,$3.nd);}
	;


init_declarator
	: declarator							{ptr="init_declarator";$$.nd=build_node(ptr,$1.nd,NULL);}
	| declarator ':' primary_expression    {ptr="init_declarator";$$.nd=build_node(ptr,$1.nd,$3.nd);}
	| declarator ':' postfix_expression		{ptr="init_declarator";$$.nd=build_node(ptr,$1.nd,$3.nd);}
	;

declarator
	: ID							{/*add the name_token to symbol table */ 
										$$.nd=build_node($1.name_token,$1.nd,NULL);	}			
	| ID '('')' 					{/*add the name_token to symbol table */ 
										$$.nd=build_node($1.name_token,$1.nd,NULL);	}	
	;



	

parameter_list
	: ID							{$$.node=build_node($1.name_token,NULL,NULL);}
	| parameter_list ',' ID			{ptr="parameter_list"; $$.node=build_node(ptr,$1.node,$3.node); }
	;

postfix_expression
	: '(' binary_operator primary_expression primary_expression  ')'   { $$.node=build_node($2.name_token,$3.node,$4.node);   }
	| '(' binary_operator primary_expression postfix_expression  ')'	{ $$.node=build_node($2.name_token,$3.node,$4.node);   }
	| '(' binary_operator postfix_expression primary_expression  ')'	{ $$.node=build_node($2.name_token,$3.node,$4.node);   }
	| '(' binary_operator postfix_expression postfix_expression  ')'	{ $$.node=build_node($2.name_token,$3.node,$4.node);   }
	;



binary_operator
	: '+'					{ptr="+"; $$.node=build_node(ptr,NULL,NULL); }
	| '-'					{ptr="-"; $$.node=build_node(ptr,NULL,NULL); }
	| '*'					{ptr="*"; $$.node=build_node(ptr,NULL,NULL); }
	| '/'					{ptr="/"; $$.node=build_node(ptr,NULL,NULL); }
	| '%'					{ptr="%"; $$.node=build_node(ptr,NULL,NULL); }
	| '<'					{ptr="<"; $$.node=build_node(ptr,NULL,NULL); }
	| '>'					{ptr=">"; $$.node=build_node(ptr,NULL,NULL); }
	| '='					{ptr="="; $$.node=build_node(ptr,NULL,NULL); }
	;

logical_operator
	: '<'                   {ptr="<"; $$.node=build_node(ptr,NULL,NULL); }
	| '>'					{ptr=">"; $$.node=build_node(ptr,NULL,NULL); }
	| '='					{ptr="="; $$.node=build_node(ptr,NULL,NULL); }
	;


type_specifier
	: CHAR                  {ptr="char"; $$.node=build_node(ptr,NULL,NULL); }      
	| INT					{ptr="int"; $$.node=build_node(ptr,NULL,NULL); }
	| DOUBLE				{ptr="double"; $$.node=build_node(ptr,NULL,NULL); }
    | BOOL					{ptr="bool"; $$.node=build_node(ptr,NULL,NULL); }
	| STRUCT				{ptr="struct"; $$.node=build_node(ptr,NULL,NULL); }
	| VOID					{ptr="void"; $$.node=build_node(ptr,NULL,NULL); }
	;

primary_expression
	: CONSTANT_INT          { $$.node=build_node($1.name_token,NULL,NULL); }
	| CONSTANT_CHAR         { $$.node=build_node($1.name_token,NULL,NULL); }
	| CONSTANT_FLOAT	    { $$.node=build_node($1.name_token,NULL,NULL); }
	| CONSTANT_DOUBLE       { $$.node=build_node($1.name_token,NULL,NULL); }
	| ID					{ $$.node=build_node($1.name_token,NULL,NULL); }
	| STRING_LITERAL		{ $$.node=build_node($1.name_token,NULL,NULL); }
	;


%%

void yyerror(char *s) 
{
    fprintf(stderr, "%s\n", s);
	return ;
}  

/*For insertion we store data temporarily*/
char *int_ptr="int";
char *char_ptr="char";
char *float_ptr="float";
char *doubl_ptr="double";

void store_data_type()
{
	//temp_data_type is declarated in symbol_table.h
	//It is used to store the variable data type tempararlily	
    if(strcmp(yytext,int_ptr)==0)
	{
		temp_data_type = int_t;
	}
	else if(strcmp(yytext,char_ptr)==0)
	{
		temp_data_type = char_t;
	}
	else if(strcmp(yytext,float_ptr)==0)
	{
		temp_data_type = float_t;
	}
	else if(strcmp(yytext,doubl_ptr)==0)
	{
		temp_data_type = double_t;
	}
	return;
}

void add_data_type()
{
	item_t *item=search_in_symbol_table(yytext);
}





int main(void)
{
	
    yyparse();
	
    return 0;
}




