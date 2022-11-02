%{
    #include <stdio.h>
	#include <stdlib.h>

	#include <string.h>
	#include "ast.h"

    int yylex(void);
    void yyerror(char *); 

	extern FILE *yyin;

	char* ptr;
	symbol_table *current_symbol_table;
	symbol_table *temp_symbol_table;
	int counter=0;
	enum data_type_t data_type;
%}
 

%union
{
	struct token_node_t{
		char *name_token;
		struct ast_node_t *node;
	}token_node;
}



%token <token_node> DECLARE 
%token <token_node> CONSTANT_INT CONSTANT_CHAR CONSTANT_FLOAT CONSTANT_DOUBLE
%token <token_node> BOOL CHAR INT DOUBLE VOID ID STRING_LITERAL STRUCT


%type  <token_node> translation_main translation_unit external_declaration declaration function_definition
%type <token_node>  declarator compound_statement compound_statement_content
%type <token_node>  statement expression_statement 
%type <token_node>  init_declarator type_specifier expression
%type <token_node> assignment_expression primary_expression postfix_expression 
%type <token_node> binary_operator function_body

%start translation_main

%%

translation_main
	: translation_unit               { ptr="Main"; $$.node=build_node(ptr,$1.node,NULL); root=$$.node ;}
	;



translation_unit
	: external_declaration                          {ptr="trans_unit"; $$.node=build_node(ptr,$1.node,NULL);}
	| translation_unit external_declaration 		{ ptr="trans_unit"; $$.node=build_node(ptr,$1.node,$2.node);  }
	;

external_declaration
	: declaration 					{ptr="declr"; $$.node=build_node(ptr,$1.node,NULL);}
	| function_definition        {ptr="fun_def"; $$.node=build_node(ptr,$1.node,NULL);}
	;

function_definition
	:type_specifier function_body   {ptr="fun_def"; $$.node=build_node(ptr,$1.node,$2.node);}

function_body
	:declarator compound_statement {ptr="fun_body"; $$.node=build_node(ptr,$1.node,$2.node);}


compound_statement
	:  '{' {table_push(current_symbol_table); temp_symbol_table=init_child_symbol_table(current_symbol_table);current_symbol_table=temp_symbol_table;   } compound_statement_content '}'  {table_push(temp_symbol_table); /*current_symbol_table=table_pop(); current_symbol_table=table_top();*/   ptr="cmp_stmt"; $$.node=build_node(ptr,$3.node,NULL); }
	;

compound_statement_content
	: declaration							   {ptr="cmp_stmt"; $$.node=build_node(ptr,$1.node,NULL);}
	| statement									{ptr="cmp_stmt"; $$.node=build_node(ptr,$1.node,NULL);}
	| compound_statement_content declaration  {ptr="cmp_stmt"; $$.node=build_node(ptr,$1.node,$2.node);}
	| compound_statement_content statement     {ptr="cmp_stmt"; $$.node=build_node(ptr,$1.node,$2.node);}
	;

statement
	: compound_statement                {ptr="comp_st"; $$.node=build_node(ptr,$1.node,NULL);}
	| expression_statement			{ptr="comp_st"; $$.node=build_node(ptr,$1.node,NULL);}
	;





declaration
	:DECLARE  type_specifier init_declarator ';'			{ptr="declr"; $$.node=build_node(ptr,$2.node,$3.node);}  
	;





expression_statement
	:   expression ';'                  { $$.node=build_node($1.name_token,$1.node,NULL); }
	;


expression
	: assignment_expression						{ptr="assign_exp"; $$.node=build_node(ptr,$1.node,NULL); }
	| primary_expression						{ptr="prm_exp"; $$.node=build_node(ptr,$1.node,NULL); }
	| postfix_expression						{ptr="post_exp"; $$.node=build_node(ptr,$1.node,NULL); }
	;

assignment_expression
	: ID ':' primary_expression			{ptr="assignment";$$.node=build_node(ptr,$1.node,$3.node);}
	| ID ':' postfix_expression			{ptr="assignment";$$.node=build_node(ptr,$1.node,$3.node);}
	;


init_declarator
	: declarator							{ptr="init_declarator";$$.node=build_node(ptr,$1.node,NULL);}
	| declarator ':' primary_expression    {ptr="init_declarator";$$.node=build_node(ptr,$1.node,$3.node);}
	| declarator ':' postfix_expression		{ptr="init_declarator";$$.node=build_node(ptr,$1.node,$3.node);}
	;

declarator
	: ID							{/*add the name_token to symbol table */if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , variable_t , data_type)==false){printf("redeclared\n");};
										$$.node=build_node($1.name_token,$1.node,NULL);	}			
	| ID '('')' 					{/*add the name_token to symbol table */ if ( insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , function_t,data_type)==false){printf("redeclared\n");};
										$$.node=build_node($1.name_token,$1.node,NULL);	}	
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



type_specifier
	: CHAR                  {ptr="char"; $$.node=build_node(ptr,NULL,NULL); data_type=char_t ;}      
	| INT					{ptr="int"; $$.node=build_node(ptr,NULL,NULL); data_type=int_t ;}
	| DOUBLE				{ptr="double"; $$.node=build_node(ptr,NULL,NULL); data_type=double_t; }
    | BOOL					{ptr="bool"; $$.node=build_node(ptr,NULL,NULL); data_type=bool_t ;}
	| STRUCT				{ptr="struct"; $$.node=build_node(ptr,NULL,NULL); data_type=struct_t;}
	| VOID					{ptr="void"; $$.node=build_node(ptr,NULL,NULL); data_type=void_t;}
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



int main(int argc, char *argv[])
{
      symbol_table *global_sym_tbl = init_symbol_table();
	  current_symbol_table=global_sym_tbl;
	  ptr=(char*)malloc(sizeof(char)*10);
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
		print_ast(root);
		//printf("\n Completed \n") ;
		//table_push(current_symbol_table);
		print_symbol_table(table_top());
		return 0;
}










