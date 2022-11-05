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

	fun_data_t function_info;
	param* parameter_list;
	param* params;
	int no_of_parameters=0;
	id_data_t id_info;
	item_t * item;
	
	void link_p(char *name ,enum data_type_t d );
%}
 

%union
{
	struct token_node_t{
		char *name_token;
		struct ast_node_t *node;
	}token_node;

	struct token_node_id{
		char *name_token;
		struct ast_node_t *node;
		struct data_type_d *data_type;	
	}token_id;
}



%token <token_node> DECLARE RETURN 
%token <token_node> CONSTANT_INT CONSTANT_CHAR CONSTANT_FLOAT CONSTANT_DOUBLE
%token <token_node> BOOL CHAR INT DOUBLE VOID  STRING_LITERAL STRUCT
%token <token_id> ID

%type  <token_node> translation_main translation_unit external_declaration declaration function_definition
%type <token_node>  declarator compound_statement compound_statement_content
%type <token_node>  statement expression_statement 
%type <token_node>  init_declarator type_specifier expression
%type <token_node> assignment_expression primary_expression postfix_expression 
%type <token_node> binary_operator function_body body parameter_list

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
	: declaration 					{ptr="external_declr"; $$.node=build_node(ptr,$1.node,NULL);}
	| function_definition        {ptr="fun_def"; $$.node=build_node(ptr,$1.node,NULL);}
	;

function_definition
	:type_specifier { } 
	  function_body   {ptr="fun_def"; $$.node=build_node(ptr,$1.node,$3.node); }
	;

function_body
	:declarator '{' {} 
		body  '}'   {temp_symbol_table=table_pop(); current_symbol_table=table_top();  ptr="fun_body"; no_of_parameters=0;
														$$.node=build_node($1.name_token,$1.node,$4.node);}
	;

body
	:  compound_statement_content RETURN expression_statement  { ptr="body"; $$.node=build_node(ptr,$1.node,$3.node); }
	;


compound_statement
	:  '{' {table_push(current_symbol_table); current_symbol_table=init_child_symbol_table(current_symbol_table);  } 
			compound_statement_content '}'  {table_push(temp_symbol_table);	 ptr="cmp_stmt"; $$.node=build_node(ptr,$3.node,NULL); }
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
	:   ';'								{ptr=";"; $$.node=build_node(ptr,NULL,NULL);  }
	|  expression ';'                  { $$.node=build_node($1.name_token,$1.node,NULL); }
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
	: ID							{if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , variable_t , data_type)==false)
																			{ptr="Redeclared";yyerror(ptr); printf("redeclared\n");}
									 $1.data_type=get_type(data_type);	$$.node=build_node($1.name_token,$1.node,NULL);	$$.node->data_type=data_type;}			
	| ID   '('')' 				{ if ( insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , function_t,data_type)==false)
																			{ptr="Redeclared";yyerror(ptr);printf("redeclared\n");} 
																			current_symbol_table=init_child_symbol_table(current_symbol_table); 
																			table_push(current_symbol_table);
																			printf("HI\n"); 
																			item=search_in_all_sym_tbl(current_symbol_table , $1.name_token);
									$1.data_type=get_type(data_type);	$$.node=build_node($1.name_token,$1.node,NULL);	$$.node->data_type=data_type;          }	
	| ID '('                     {  
									if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , function_t , data_type)==false)
																			{ptr="Redeclared";yyerror(ptr);printf("redeclared\n");}
									current_symbol_table=init_child_symbol_table(current_symbol_table); table_push(current_symbol_table);}  
	parameter_list ')'            {    item=search_in_all_sym_tbl(current_symbol_table , $1.name_token);
											
										function_info.return_data_type=data_type;
										function_info.no_parameters=no_of_parameters;
										function_info.parameters=parameter_list->next;
										id_info.function_info=function_info; 
										item->id_info=id_info;
										parameter_list=NULL;
										params=parameter_list;
										
										$1.data_type=get_type(data_type); $$.node=build_node($1.name_token ,$4.node ,NULL ); $$.node->data_type=data_type; }
	;


parameter_list
	: type_specifier ID                          { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$2.name_token , function_param , data_type)==false)
																			{ptr="Redeclared";yyerror(ptr);printf("redeclared\n");} no_of_parameters++;      $2.data_type=get_type(data_type);  
																			$$.node=build_node($2.name_token,$2.node,NULL); $$.node->data_type=data_type; 
																			link_p($2.name_token,data_type);}
	| parameter_list ',' type_specifier ID				{if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$4.name_token , function_param , data_type)==false)
																			{ptr="Redeclared";yyerror(ptr);printf("redeclared\n");}  $4.data_type=get_type(data_type);  no_of_parameters++;
															ptr="param";  $$.node=build_node(ptr,$1.node,$4.node );$$.node->data_type=data_type; link_p($3.name_token,data_type);     }
	;

	



postfix_expression
	: '(' binary_operator primary_expression primary_expression  ')'   { $$.node=build_node($2.node->name,$3.node,$4.node);   }
	| '(' binary_operator primary_expression postfix_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);   }
	| '(' binary_operator postfix_expression primary_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);   }
	| '(' binary_operator postfix_expression postfix_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);   }
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
	| INT					{ptr="int"; $$.node=build_node(ptr,NULL,NULL); data_type=int_t ;  }
	| DOUBLE				{ptr="double"; $$.node=build_node(ptr,NULL,NULL); data_type=double_t; }
    | BOOL					{ptr="bool"; $$.node=build_node(ptr,NULL,NULL); data_type=bool_t ;}
	| STRUCT				{ptr="struct"; $$.node=build_node(ptr,NULL,NULL); }
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
	
	  data_type = int_t;
      symbol_table *global_sym_tbl = init_symbol_table();
	  current_symbol_table=global_sym_tbl;
	  table_push(current_symbol_table);
	  ptr=(char*)malloc(sizeof(char)*10);
	  params=(param*)malloc(sizeof(param));
	  parameter_list=(param*)malloc(sizeof(param));
	  params=parameter_list;
	  item=(item_t*)malloc(sizeof(item_t));
	  
   	  yyin=fopen(argv[--argc],"r");
		if (yyparse())
		{
			printf("\nParsing error \n");
		}
		else
		{
			printf("\nparsing completed \n");
		}
		fclose(yyin);
		print_ast(root);
		printf("\n"); 
		printf("Symbol Table \n");
		print_symbol_table(table_top());
		ptr="main";
		item=search_in_all_sym_tbl(current_symbol_table ,ptr);
		//printf("\n%d\n",item->id_info.function_info.no_parameters);
		return 0;
}

void link_p(char *name ,enum data_type_t d )
{
	param* p = (param*)malloc(sizeof(param));
	p->parameter_name=(char*)malloc(sizeof(name));
	strcpy(p->parameter_name,name);
	p->parameter_data_type=d;
	p->next=NULL;
	params->next=p;
	params=p;
	return ;
}










