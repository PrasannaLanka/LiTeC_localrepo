%{
    #include <stdio.h>
	#include <stdlib.h>

	#include <string.h>
	
	#include "semantic.h"
    int yylex(void);  
	extern FILE *yyin;
	void yyerror();
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

	int single_tex_function=0;
	
	void link_p(char *name ,enum data_type_t d );
	extern int line_number;
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

	struct token_node_str{
		char *name_token;
		struct ast_node_t *node;
	}token_str;
}




%token <token_node> DECLARE RETURN CONTINUE BREAK IF ELSE LOOP TEX TEX_OPEN TEX_CLOSE
%token <token_node> CONSTANT_INT CONSTANT_CHAR CONSTANT_FLOAT CONSTANT_DOUBLE

%token <token_node> BOOL CHAR INT DOUBLE VOID  STRING_LITERAL STRUCT TRUE FALSE
%token <token_id> ID

%type  <token_node> translation_main translation_unit external_declaration declaration function_definition
%type <token_node>  declarator compound_statement compound_statement_content
%type <token_node>  statement expression_statement 
%type <token_node>  init_declarator type_specifier expression
%type <token_node> assignment_expression primary_expression postfix_expression 
%type <token_node> binary_operator function_body body parameter_list id_list
%type <token_node> selection_statement iteration_statement tex_statement logical_expression logical_operator

%type <token_node> tex_data tex_function 
%start translation_main

%%

translation_main
	: translation_unit               { ptr="Main"; $$.node=build_node(ptr,$1.node,NULL); root=$$.node ;}
	;



translation_unit
	: external_declaration                          { ptr="trans_unit"; $$.node=$1.node; }
	| translation_unit external_declaration 		{ ptr="trans_unit"; $$.node=build_node(ptr,$1.node,$2.node);   }
	;

external_declaration
	: declaration 					{ptr="external_declr"; $$.node=build_node(ptr,$1.node,NULL);}
	| function_definition           {ptr="fun_declr"; $$.node=build_node(ptr,$1.node,NULL); check_function_return($$.node);}
	;

function_definition
	:type_specifier { }
	  function_body   {ptr="fun_def"; $$.node=build_node($3.node->name,$1.node,$3.node);  }
	;

function_body
	:declarator '{' {} 
		body  '}'   {temp_symbol_table=table_pop(); current_symbol_table=table_top();
														 
														  ptr="fun_body"; no_of_parameters=0;
													    if($1.node->left!=NULL)
														{$$.node=build_node($1.node->name,$1.node->left,$4.node);
														}  
														else{$$.node=build_node(ptr,NULL,$4.node);}
														
														}
	;

body
	:  compound_statement_content RETURN expression_statement  { ptr="body"; $$.node=build_node(ptr,$1.node,$3.node); }
	| RETURN expression_statement { ptr="body"; $$.node=build_node(ptr,NULL,$2.node);  }
	;  


compound_statement
	:  '{' {table_push(current_symbol_table); current_symbol_table=init_child_symbol_table(current_symbol_table);  } 
			compound_statement_content '}'  {table_push(temp_symbol_table);	 ptr="cmp_stmt"; $$.node=build_node(ptr,$3.node,NULL); }
	;

compound_statement_content
	: declaration							   {ptr="declr"; $$.node=build_node(ptr,$1.node,NULL);}
	| statement									{ptr="stmt"; $$.node=build_node(ptr,$1.node,NULL);}
	| compound_statement_content declaration  {ptr="cmp_stmt_content"; $$.node=build_node(ptr,$1.node,$2.node);}
	| compound_statement_content statement     {ptr="cmp_stmt_content"; $$.node=build_node(ptr,$1.node,$2.node);}
	;

statement
	: compound_statement			{ptr="comp_stmt"; $$.node=build_node(ptr,$1.node,NULL);}
	| expression_statement			{ptr="expr_stmt"; $$.node=build_node(ptr,$1.node,NULL);}
	| selection_statement			{ptr="sel_stmt"; $$.node=build_node(ptr,$1.node,NULL);}
	| iteration_statement			{ptr="itr_stmt"; $$.node=build_node(ptr,$1.node,NULL);}
	| tex_statement				{ptr="tex_stmt"; $$.node=build_node(ptr,$1.node,NULL); 
									single_tex_function++; if(single_tex_function==2){ printf("\n More than one TeX Function \n") ; }  }
	| jump_statement				{ ptr = "jump_stmt"; $$.node = build_node{ptr,$1.node,NULL}; }
	;

selection_statement
	: IF '(' logical_expression ')' compound_statement						{ ptr = "if_"; $$.node = build_node(ptr, $3.node, $5.node);}
	| IF '(' logical_expression ')' compound_statement ELSE compound_statement			{ ptr = "if_"; ast_node* _if = build_node(ptr, $3.node, $5.node); 
																							ptr = "if_else"; $$.node = build_node(ptr, _if, $7.node); }
	;

iteration_statement
	: LOOP '(' expression_statement logical_expression ';' ')' compound_statement
			{
				ptr = "lp_cdn"; ast_node* lp_cdn = build_node(ptr, $4.node, $7.node);
				ptr = "loop"; $$.node = build_node(ptr, $3.node, lp_cdn);
			}
	| LOOP '(' expression_statement logical_expression ';' expression ')' compound_statement
			{
				ptr = "lp_cdn"; ast_node* lp_cdn = build_node(ptr, $4.node, $8.node);
				ptr = "lp_itr"; ast_node* lp_itr = build_node(ptr, $6.node, lp_cdn);
				ptr = "loop"; $$.node = build_node(ptr, $3.node, lp_itr);
			}
	;

tex_statement
	: TEX '{' tex_data '}'					{ ptr = "tex"; $$.node = build_node(ptr, $3.node, NULL); }
	;

tex_data
	: STRING_LITERAL					{ ptr = "tex_str"; $$.node = build_node(ptr, $1.node, NULL); }
	| tex_function						{ ptr = "tex_fun"; $$.node = build_node(ptr, NULL, $1.node); }
	| tex_data ',' STRING_LITERAL				{ ptr = "tex_data"; $$.node = build_node(ptr, $3.node, $1.node); }
	| tex_data ',' tex_function				{ ptr = "tex_data"; $$.node = build_node(ptr, $1.node, $3.node); }
	;

tex_function
	: TEX_OPEN primary_expression TEX_CLOSE				{ $$.node = $2.node; }
	;

declaration
	: DECLARE type_specifier init_declarator ';'			{ptr="declr"; $$.node=build_node(ptr,$2.node,$3.node);}  
	;

jump_statement
	: CONTINUE ';'						{ ptr = "j_cnt"; $$.node = build_node(ptr, $1.node, NULL); }
	| BREAK ';'							{ ptr = "j_brk"; $$.node = build_node(ptr, $1.node, NULL); }
	| RETURN ';'						{ ptr = "j_rtn"; $$.node = build_node(ptr, $1.node, NULL); }
	| RETURN expression ';'				{ ptr = "j_exp"; $$.node = build_node(ptr, $1.node, $2.node); }
	;

expression_statement
	:   ';'							   {ptr=";"; $$.node=build_node(ptr,NULL,NULL);  }
	|  expression ';'                  { ptr="expr"; $$.node=build_node(ptr,$1.node,NULL); }
	;


expression
	: assignment_expression						{ptr="assign_exp"; $$.node=build_node(ptr,$1.node,NULL); }
	| primary_expression						{ptr="prm_exp"; $$.node=build_node(ptr,$1.node,NULL); $$.node->data_type=$1.node->data_type;}
	| postfix_expression						{ptr="post_exp"; $$.node=build_node(ptr,$1.node,NULL); }
	;

assignment_expression
	: ID ':' primary_expression			{ptr="assignment";$$.node=build_node($1.name_token,$1.node,$3.node); check_assignment(current_symbol_table , $$.node); }
	| ID ':' postfix_expression			{ptr="assignment";$$.node=build_node($1.name_token,$1.node,$3.node); check_assignment(current_symbol_table , $$.node);}
	;


init_declarator
	: declarator							{ptr="init_declarator";$$.node=build_node(ptr,$1.node,NULL);}
	| declarator ':' primary_expression    {ptr="init_declarator";$$.node=build_node(ptr,$1.node,$3.node);}
	| declarator ':' postfix_expression		{ptr="init_declarator";$$.node=build_node(ptr,$1.node,$3.node);}
	;

declarator
	: ID							{if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , variable_t , data_type)==false)
																			{printf("Redeclared of variable at line %d\n",line_number);}
									 $1.data_type=get_type(data_type);	$$.node=build_node($1.name_token,$1.node,NULL);	$$.node->data_type=data_type;}			
	| ID   '('')' 				{ if ( insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , function_t,data_type)==false)
																			{printf("Redeclared of variable at line %d\n",line_number);} 
																			current_symbol_table=init_child_symbol_table(current_symbol_table); 
																			table_push(current_symbol_table);
																			
																			item=search_in_all_sym_tbl(current_symbol_table , $1.name_token);
									$1.data_type=get_type(data_type);	$$.node=build_node($1.name_token,$1.node,NULL);	$$.node->data_type=data_type;          }	
	| ID '('                     {  
									if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , function_t , data_type)==false)
																			{printf("Redeclared of variable at line %d\n",line_number);}
									current_symbol_table=init_child_symbol_table(current_symbol_table); ptr="LOCAL"; current_symbol_table->name=(char*)malloc(sizeof(char)*10);
									strcpy(current_symbol_table->name,ptr); table_push(current_symbol_table); 
									parameter_list=(param*)malloc(sizeof(param));
																				params=(param*)malloc(sizeof(param));
																				parameter_list=params;
																				}   
	parameter_list ')'            {    item=search_in_all_sym_tbl(current_symbol_table , $1.name_token);
											
										function_info.return_data_type=data_type;
										function_info.no_parameters=no_of_parameters;
										function_info.parameters=parameter_list->next;
										id_info.function_info=function_info; 
										item->id_info=id_info;
										parameter_list=NULL;
										params=parameter_list;
										
										$1.data_type=get_type(data_type); $$.node=build_node($1.name_token ,$4.node ,NULL ); $$.node->data_type=data_type; 
								  }
										
										
	;



parameter_list
	: type_specifier ID                          { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$2.name_token , function_param , data_type)==false)
																			{printf("Redeclared of variable at line %d\n",line_number);} 
																			else {
																				no_of_parameters++;      
																				 
																				$$.node=build_node($2.name_token,NULL,NULL); 
																				$$.node->data_type=data_type; 
																				
																				link_p($2.name_token,data_type);  } 
																				
																			}
	| parameter_list ',' type_specifier ID				{if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$4.name_token , function_param , data_type)==false)
																			{printf("Redeclared of variable at line %d\n",line_number);}  
																			else {
																				$4.node=build_node($4.name_token,NULL,NULL);
																				$4.node->data_type=data_type;  
																				no_of_parameters++;
																				ptr="param_list";  $$.node=build_node(ptr,$1.node,$4.node ); 
																				 
																				link_p($3.name_token,data_type);   } 
																				
															}
	;




postfix_expression
	: '(' binary_operator primary_expression primary_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);  
																		if($3.node->data_type==$4.node->data_type)
																		{
																			$$.node->data_type=$3.node->data_type;
																		}
																		else
																		{
																			printf("Operation on incompatible data types at line %d\n",line_number);
																		}
																		 }
	| '(' binary_operator primary_expression postfix_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);  
																		if($3.node->data_type==$4.node->data_type)
																		{
																			$$.node->data_type=$3.node->data_type;
																		}
																		else
																		{
																			printf("Operation on incompatible data types at line %d\n",line_number);
																		}
																		 }
	| '(' binary_operator postfix_expression primary_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);  
																		if($3.node->data_type==$4.node->data_type)
																		{
																			$$.node->data_type=$3.node->data_type;
																		}
																		else
																		{
																			printf("Operation on incompatible data types at line %d\n",line_number);
																		}
																		 }
	| '(' binary_operator postfix_expression postfix_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);  
																		if($3.node->data_type==$4.node->data_type)
																		{
																			$$.node->data_type=$3.node->data_type;
																		}
																		else
																		{
																			printf("Operation on incompatible data types at line %d\n",line_number);
																		}
																		 }
	;

logical_expression
	: primary_expression							{ ptr = "prm_exp"; $$.node = build_node(ptr, $1.node, NULL); }
	| expression logical_operator expression				{ $$.node = build_node($2.name_token, $1.node, $3.node); }
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
	: '<'					{ptr="<"; $$.node=build_node(ptr,NULL,NULL); }
	| '>'					{ptr=">"; $$.node=build_node(ptr,NULL,NULL); }
	| '='					{ptr="="; $$.node=build_node(ptr,NULL,NULL); }
	;

type_specifier
	: CHAR                  {ptr="char"; $$.node=build_node(ptr,NULL,NULL); data_type=char_t ; $$.node->data_type=char_t; }      
	| INT					{ptr="int"; $$.node=build_node(ptr,NULL,NULL); data_type=int_t ;  $$.node->data_type=int_t; }
	| DOUBLE				{ptr="double"; $$.node=build_node(ptr,NULL,NULL); data_type=double_t; $$.node->data_type=double_t; }
    | BOOL					{ptr="bool"; $$.node=build_node(ptr,NULL,NULL); data_type=bool_t ; $$.node->data_type=bool_t;}

	| STRUCT				{ptr="struct"; $$.node=build_node(ptr,NULL,NULL); }
	| VOID					{ptr="void"; $$.node=build_node(ptr,NULL,NULL); data_type=void_t;$$.node->data_type=void_t; }
	;

primary_expression
	: CONSTANT_INT          { $$.node=build_node($1.name_token,NULL,NULL); $$.node->data_type=int_t; }
	| CONSTANT_CHAR         { $$.node=build_node($1.name_token,NULL,NULL); $$.node->data_type=char_t;}
	| CONSTANT_DOUBLE       { $$.node=build_node($1.name_token,NULL,NULL); $$.node->data_type=double_t;}
	| TRUE                  { ptr="true"; $$.node=build_node(ptr,NULL,NULL); $$.node->data_type=bool_t;  }
	| FALSE                 { ptr="false"; $$.node=build_node(ptr,NULL,NULL); $$.node->data_type=bool_t; }
	| ID					{ $$.node=build_node($1.name_token,NULL,NULL); item=search_in_all_sym_tbl(current_symbol_table , $1.name_token);
								if(item==NULL){printf("%s is undeclared identifier at %d\n",$1.name_token,line_number);}
								else{$$.node->data_type=item->data_type;}
								
									}	
	| STRING_LITERAL		{ $$.node=build_node($1.name_token,NULL,NULL); }
	| '('ID '('')'')'       { $$.node=build_node($2.name_token,NULL,NULL);
								item=search_in_all_sym_tbl(current_symbol_table , $2.name_token);
							   if(item==NULL)
							   {	
									printf("%s is undeclared identifier at %d\n",$2.name_token,line_number);
							   		$$.node->data_type=void_t; 
								} 
							   else
							   {
									$$.node->data_type=item->data_type;
								}
								}
	| '('ID '(' id_list ')' ')' { $$.node=build_node( $2.name_token , $2.node , $4.node );
								  item=search_in_all_sym_tbl(current_symbol_table , $2.name_token);
								if(item==NULL)
								{
									printf("%s is undeclared identifier at %d\n",$2.name_token,line_number);
								  	$$.node->data_type=void_t;
								} 
								else{ 
									check_function_parameters(item->id_info.function_info.parameters,$4.node);
									$$.node->data_type=item->data_type; }    
								}

 	;


id_list
	: primary_expression				{$$.node=$1.node;}
	| id_list ',' primary_expression		{ptr="id_list" ; $$.node=build_node(ptr,$1.node,$3.node);   }
	;



%%



/*For insertion we store data temporarily*/
char *int_ptr="int";
char *char_ptr="char";
char *float_ptr="float";
char *doubl_ptr="double";

void yyerror () 
{
	fprintf(stderr, "Parsing failed, Syntax error at line %d\n",line_number);
	exit(1);
}

	
int main(int argc, char *argv[])
{
	
	  data_type = int_t;
      symbol_table *global_sym_tbl = init_symbol_table();
	  ptr="GLOBAL";
	  global_sym_tbl->name=(char*)malloc(sizeof(char)*10);
	  strcpy(global_sym_tbl->name,ptr);
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
			yyerror();		
			
		}
		else
		{
			printf("\nParsing completed \n");
		}
		fclose(yyin);
		printf("\nast in pre-order\n");
		print_ast(root);
		printf("\n"); 
		
		printf("\nSymbol Table \n");
		print_symbol_table(table_top());

		check_function_return(root->left->left);
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









