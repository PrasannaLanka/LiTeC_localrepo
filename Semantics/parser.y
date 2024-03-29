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
    matrix_info_t matrix_info;
    array_data_t array_info;
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
%token <token_id> ID SF_OPEN SF_CLOSE MS_OPEN MS_CLOSE

%type <token_node> translation_main translation translation_init translation_unit external_declaration
%type <token_node> declaration function_definition declarator compound_statement compound_statement_content
%type <token_node> statement expression_statement 
%type <token_node> init_declarator type_specifier expression
%type <token_node> assignment_expression primary_expression postfix_expression 
%type <token_node> binary_operator function_body body parameter_list id_list
%type <token_node> selection_statement iteration_statement tex_statement jump_statement logical_expression logical_operator
%type <token_node> matrix_assignment matrix_index matrix_value array_assignment array_index array_value

%type <token_node> tex_data tex_function 
%start translation_main

%%

translation_main
    : translation                                       { ptr = "Main"; $$.node = build_node(ptr,$1.node,NULL); root = $$.node; }
    ;

translation
	: translation SF_OPEN {} translation_init SF_CLOSE                 {current_symbol_table=table_pop();current_symbol_table=table_top(); ptr = "sub_file"; $$.node = build_node(ptr,$1.node,$4.node); }
	| SF_OPEN {} translation_init SF_CLOSE                 {current_symbol_table=table_pop();current_symbol_table=table_top();
                                                                                                                                                                  ptr = "sub_file"; $$.node = build_node(ptr,$3.node,NULL); }
	;

translation_init
	: ID MS_OPEN translation_unit MS_CLOSE { data_type=int_t;   if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , variable_t , data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}
                                                current_symbol_table=init_child_symbol_table(current_symbol_table); table_push(current_symbol_table);} translation_unit { ptr = "trans_init"; $$.node = build_node(ptr,$3.node,$6.node); }
	;

translation_unit
    : external_declaration                          { ptr = "trans_unit"; $$.node = $1.node; }
    | translation_unit external_declaration 		{ ptr = "trans_unit"; $$.node = build_node(ptr,$1.node,$2.node); }
    ;

external_declaration
    : declaration 									{ ptr="external_declr"; $$.node=build_node(ptr,$1.node,NULL); }
    | function_definition          					{ ptr="fun_declr"; $$.node=build_node(ptr,$1.node,NULL); check_function_return($$.node); }
    ;

function_definition
    : type_specifier { } function_body  			{ ptr="fun_def"; $$.node=build_node($3.node->name,$1.node,$3.node); }
    ;

function_body
    : declarator '{' {} body '}' 					{ temp_symbol_table=table_pop(); current_symbol_table=table_top();
                                                      ptr="fun_body"; no_of_parameters=0;
                                                      if($1.node->left!=NULL)
                                                        {
                                                            $$.node=build_node($1.node->name,$1.node->left,$4.node);
                                                        }  
                                                      else
                                                        {
                                                            $$.node=build_node(ptr,NULL,$4.node);
                                                        }														
                                                    }
    ;

body
    : compound_statement_content RETURN expression_statement   { ptr="body"; $$.node=build_node(ptr,$1.node,$3.node); }
    | RETURN expression_statement 							   { ptr="body"; $$.node=build_node(ptr,NULL,$2.node); }
    ;  


compound_statement
    : '{' { current_symbol_table=init_child_symbol_table(current_symbol_table); table_push(current_symbol_table);} 
            compound_statement_content '}'  {current_symbol_table=table_pop();current_symbol_table=table_top();	 ptr="cmp_stmt"; $$.node=build_node(ptr,$3.node,NULL); }
    ;

compound_statement_content
    : declaration							  		{ ptr="declr"; $$.node=build_node(ptr,$1.node,NULL); }
    | statement										{ ptr="stmt"; $$.node=build_node(ptr,$1.node,NULL); }
    | compound_statement_content declaration  		{ ptr="cmp_stmt_content"; $$.node=build_node(ptr,$1.node,$2.node); }
    | compound_statement_content statement     		{ ptr="cmp_stmt_content"; $$.node=build_node(ptr,$1.node,$2.node); }
    ;

statement
    : compound_statement							{ ptr="comp_stmt"; $$.node=build_node(ptr,$1.node,NULL); }
    | expression_statement							{ ptr="expr_stmt"; $$.node=build_node(ptr,$1.node,NULL); }
    | selection_statement							{ ptr="sel_stmt"; $$.node=build_node(ptr,$1.node,NULL); }
    | iteration_statement							{ ptr="itr_stmt"; $$.node=build_node(ptr,$1.node,NULL); }
    | tex_statement				  					{ ptr="tex_stmt"; $$.node=build_node(ptr,$1.node,NULL); 
                                                    single_tex_function++; if(single_tex_function==2){ printf("\n More than one TeX Function \n") ; }  }

    | jump_statement								{  ptr = "jump_stmt"; $$.node = build_node(ptr,$1.node,NULL); }

    ;

selection_statement
    : IF '(' logical_expression ')' compound_statement									{ ptr = "if_"; $$.node = build_node(ptr, $3.node, $5.node); }
    | IF '(' logical_expression ')' compound_statement ELSE compound_statement			{ ptr = "if_"; ast_node* _if = build_node(ptr, $3.node, $5.node); 
                                                                                          ptr = "if_else"; $$.node = build_node(ptr, _if, $7.node); }
	| IF '(' logical_expression ')' compound_statement ELSE selection_statement         { ptr = "if_"; ast_node* _if = build_node(ptr, $3.node, $5.node); 
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
    : TEX '{' tex_data '}'					        { ptr = "tex"; $$.node = build_node(ptr, $3.node, NULL); }
    ;

tex_data
    : STRING_LITERAL								{ ptr = "tex_str"; $$.node = build_node(ptr, $1.node, NULL); }
    | tex_function									{ ptr = "tex_fun"; $$.node = build_node(ptr, NULL, $1.node); }
    | tex_data ',' STRING_LITERAL					{ ptr = "tex_data"; $$.node = build_node(ptr, $3.node, $1.node); }
    | tex_data ',' tex_function						{ ptr = "tex_data"; $$.node = build_node(ptr, $1.node, $3.node); }
    ;

tex_function
    : TEX_OPEN primary_expression TEX_CLOSE			{ $$.node = $2.node; }
    | TEX_OPEN postfix_expression TEX_CLOSE			{ $$.node = $2.node; }
    ;

jump_statement
    : CONTINUE ';'									{ ptr = "j_cnt"; $$.node = build_node(ptr, $1.node, NULL); }
    | BREAK ';'										{ ptr = "j_brk"; $$.node = build_node(ptr, $1.node, NULL); }
    | RETURN ';'									{ ptr = "j_rtn"; $$.node = build_node(ptr, $1.node, NULL); }
    | RETURN expression ';'							{ ptr = "ret_exp"; $$.node = build_node(ptr, $2.node, NULL); }
    ;

declaration
    : DECLARE type_specifier init_declarator ';'	{ ptr="declr"; $$.node=build_node(ptr,$2.node,$3.node); }  
    ;

expression_statement
    :   ';'							  				{ ptr=";"; $$.node=build_node(ptr,NULL,NULL); }
    |  expression ';'                      			{ ptr="expr"; $$.node=build_node(ptr,$1.node,NULL); }
    ;


expression
    : assignment_expression							{ ptr="assign_exp"; $$.node=build_node(ptr,$1.node,NULL); }
    | primary_expression							{ ptr="prm_exp"; $$.node=build_node(ptr,$1.node,NULL); $$.node->data_type=$1.node->data_type; }
    | postfix_expression							{ ptr="post_exp"; $$.node=build_node(ptr,$1.node,NULL); }
    ;

assignment_expression
    : ID ':' primary_expression						{ ptr="assignment";$$.node=build_node($1.name_token,$1.node,$3.node); check_assignment(current_symbol_table , $$.node); }
    | ID ':' postfix_expression						{ ptr="assignment";$$.node=build_node($1.name_token,$1.node,$3.node); check_assignment(current_symbol_table , $$.node); }                 
    | matrix_assignment                             { $$.node=$1.node; }
    | array_assignment                              { $$.node=$1.node; }
    ;
matrix_assignment
    : ID matrix_index matrix_value                  { $$.node=build_node($1.name_token,$2.node,$3.node); 
                                                      
                                                     if ( check_matrix_assignment(current_symbol_table ,$$.node)==0){}       }
    ;

matrix_index
    : '[' primary_expression ']' '[' primary_expression ']'  {ptr="matrix_index_prm"; $$.node=build_node(ptr,$2.node,$5.node); 
                                                                if($2.node->data_type!=int_t)
                                                                { printf(" ERROR : row index must be int data type at line %d \n",line_number);}
                                                                if($5.node->data_type!=int_t)
                                                                { printf(" ERROR : column index must be int data type at line %d \n",line_number);}      
                                                                }
    | '[' postfix_expression ']' '[' postfix_expression']'     { ptr="matrix_index"; $$.node=build_node(ptr,$2.node,$5.node); 
                                                                if($2.node->data_type!=int_t)
                                                                { printf(" ERROR : row index must be int data type at line %d \n",line_number);}
                                                                if($5.node->data_type!=int_t)
                                                                { printf(" ERROR : column index must be int data type at line %d \n",line_number);}      
                                                                }     
    |  '[' primary_expression ']' '[' postfix_expression ']'   {ptr="matrix_index"; $$.node=build_node(ptr,$2.node,$5.node); 
                                                                if($2.node->data_type!=int_t)
                                                                { printf(" ERROR : row index must be int data type at line %d \n",line_number);}
                                                                if($5.node->data_type!=int_t)
                                                                { printf(" ERROR : column index must be int data type at line %d \n",line_number);}      
                                                                }
    |  '[' postfix_expression ']'  '[' primary_expression ']'   {ptr="matrix_index"; $$.node=build_node(ptr,$2.node,$5.node); 
                                                                if($2.node->data_type!=int_t)
                                                                { printf(" ERROR : row index must be int data type at line %d \n",line_number);}
                                                                if($5.node->data_type!=int_t)
                                                                { printf(" ERROR : column index must be int data type at line %d \n",line_number);}      
                                                                }
    ;
matrix_value
    :   ':' primary_expression                      {ptr="prm_exp"; $$.node=build_node(ptr,$2.node,NULL); $$.node->data_type=$2.node->data_type; }
    |    ':' postfix_expression                     {ptr="post_exp"; $$.node=build_node(ptr,$2.node,NULL);$$.node->data_type=$2.node->data_type;   }
    ;


array_assignment
    : ID array_index array_value                   {$$.node=build_node($1.name_token,$2.node,$3.node);
                                                      if( check_array_assignment(current_symbol_table,$$.node)   ==0 ){}    }
    ;

array_index 
    : '[' primary_expression ']'               {ptr="array_index_prmexp"; $$.node=build_node(ptr,$2.node,NULL); 
                                                if($2.node->data_type!=int_t)
                                                  {printf("ERROR : index must be int type at line %d \n",line_number);}
                                                  }
    | '[' postfix_expression  ']'              {ptr="array_index_postexp"; $$.node=build_node(ptr,$2.node,NULL); 
                                                    if($2.node->data_type!=int_t)
                                                  {printf("ERROR : index must be int type at line %d \n",line_number);}
                                                    }
    ;
array_value
    : ':' primary_expression                    { ptr="array_value"; $$.node=build_node(ptr,$2.node,NULL); $$.node->data_type=$2.node->data_type;  }
    | ':' postfix_expression                    { ptr="array_value"; $$.node=build_node(ptr,$2.node,NULL); $$.node->data_type=$2.node->data_type;  }
    ;


init_declarator
    : declarator						{ ptr="init_declarator";$$.node=build_node(ptr,$1.node,NULL); }
    | declarator ':' primary_expression    			{ ptr="init_declarator";$$.node=build_node(ptr,$1.node,$3.node); check_declaration($$.node); if($1.node->isMatrix==1) {check_declaration_helper(current_symbol_table, $$.node);} }
    | declarator ':' postfix_expression				{ ptr="init_declarator";$$.node=build_node(ptr,$1.node,$3.node); check_declaration($$.node); }
    ; 

declarator
    : ID											{ if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , variable_t , data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}
                                                       $1.data_type=get_type(data_type);	$$.node=build_node($1.name_token,$1.node,NULL);	$$.node->data_type=data_type; 
                                                    }			
    | ID   '('')' 									{ if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , function_t,data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);} 
                                                      current_symbol_table=init_child_symbol_table(current_symbol_table); 
                                                      table_push(current_symbol_table);																			
                                                      item=search_in_all_sym_tbl(current_symbol_table , $1.name_token);
                                                      $1.data_type=get_type(data_type);	$$.node=build_node($1.name_token,$1.node,NULL);	$$.node->data_type=data_type; 
                                                    }	
    | ID '('                   						{ if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , function_t , data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}
                                                      current_symbol_table=init_child_symbol_table(current_symbol_table); ptr="LOCAL"; current_symbol_table->name=(char*)malloc(sizeof(char)*10);
                                                      strcpy(current_symbol_table->name,ptr); table_push(current_symbol_table); 
                                                      parameter_list=(param*)malloc(sizeof(param));
                                                      params=(param*)malloc(sizeof(param));
                                                      parameter_list=params; 
                                                    }   
    parameter_list ')'          					{ item=search_in_all_sym_tbl(current_symbol_table , $1.name_token);											
                                                      function_info.return_data_type=data_type;
                                                      function_info.no_parameters=no_of_parameters;
                                                      function_info.parameters=parameter_list->next;
                                                      id_info.function_info=function_info; 
                                                      item->id_info=id_info;
                                                      parameter_list=NULL;
                                                      params=parameter_list;										
                                                      $1.data_type=get_type(data_type); $$.node=build_node($1.name_token ,$4.node ,NULL ); $$.node->data_type=data_type; 
                                                      }							
            
    |ID '['CONSTANT_INT ']'                         { /*Array declaration*/ 
                                                                if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , array_t , data_type)==false)
                                                                { printf("ERROR: Redeclaration of variable at line %d\n",line_number);    } 
                                                                item=search_in_all_sym_tbl(current_symbol_table, $1.name_token);
                                                                if(atoi($3.name_token)<0){printf("ERROR : index must be positive at line %d \n",line_number);}
                                                                else{
                                                                array_info.array_size=atoi($3.name_token); 
                                                                item->id_info.array_info.array_size=atoi($3.name_token); }
                                                                
                                                                
                                                                }
    |ID '['CONSTANT_INT']' '[' CONSTANT_INT']'      { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$1.name_token , matrix_t , data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}  
                                                            
                                                            $$.node=build_node($1.name_token,$1.node,NULL);   
                                                            $$.node->data_type=data_type;

                                                            $$.node->isMatrix=1;
                                                            item=search_in_all_sym_tbl(current_symbol_table, $1.name_token);
                                                            
                                                            if(atoi($3.name_token)<0){printf("ERROR :  row index must be positive at line %d \n",line_number); }
                                                            else {
                                                            matrix_info.row=atoi($3.name_token); }
                                                            if(atoi($6.name_token)<0){printf("ERROR :  column index must be positive at line %d \n",line_number); }
                                                            else{ matrix_info.column=atoi($6.name_token);}
                                                            id_info.matrix_info=matrix_info;
                                                            item->id_info=id_info;

                                                            }
    
    ;

parameter_list
        : type_specifier ID                             { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$2.name_token , function_param , data_type)==false)
                                                                                {printf("ERROR: Redeclaration of variable at line %d\n",line_number);} 
                                                                                else {
                                                                                    no_of_parameters++;    
                                                                                    $$.node=build_node($2.name_token,NULL,NULL); 
                                                                                    $$.node->data_type=data_type; 	
                                                                                    link_p($2.name_token,data_type); } 																				
                                                        }
    | parameter_list ',' type_specifier ID				{ if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,$4.name_token , function_param , data_type)==false)
                                                                                {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}  
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
                                                                            //
                                                                            if($3.node->isMatrix==1 || $4.node->isMatrix==1)
                                                                            {
                                                                                if(check_matrix($$.node ,$3.node , $4.node)==1){printf("Error in matrix operations \n");}
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
    | '(' binary_operator primary_expression postfix_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);  
                                                                        if($3.node->data_type==$4.node->data_type)
                                                                        {
                                                                            $$.node->data_type=$3.node->data_type;
                                                                            if($3.node->isMatrix==1 || $4.node->isMatrix==1)
                                                                            {
                                                                                if(check_matrix($$.node ,$3.node , $4.node)==1){printf("Error in matrix operations \n");}
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
    | '(' binary_operator postfix_expression primary_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);  
                                                                        if($3.node->data_type==$4.node->data_type)
                                                                        {
                                                                            $$.node->data_type=$3.node->data_type;
                                                                            if($3.node->isMatrix==1 || $4.node->isMatrix==1)
                                                                            {
                                                                                if(check_matrix($$.node ,$3.node , $4.node)==1){printf("Error in matrix operations line %d\n",line_number);}
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
    | '(' binary_operator postfix_expression postfix_expression  ')'	{ $$.node=build_node($2.node->name,$3.node,$4.node);  
                                                                        if($3.node->data_type==$4.node->data_type)
                                                                        {
                                                                            $$.node->data_type=$3.node->data_type;
                                                                            if($3.node->isMatrix==1 || $4.node->isMatrix==1)
                                                                            {
                                                                                if(check_matrix($$.node ,$3.node , $4.node)==1){printf("Error in matrix operations line %d\n",line_number);}
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
    ;

logical_expression
    : primary_expression									{ ptr = "prm_exp"; $$.node = build_node(ptr, $1.node, NULL); }
    | expression logical_operator expression				{ $$.node = build_node($2.name_token, $1.node, $3.node); }
    ;

binary_operator
    : '+'					{ ptr="+"; $$.node=build_node(ptr,NULL,NULL); }
    | '-'					{ ptr="-"; $$.node=build_node(ptr,NULL,NULL); }
    | '*'					{ ptr="*"; $$.node=build_node(ptr,NULL,NULL); }
    | '/'					{ ptr="/"; $$.node=build_node(ptr,NULL,NULL); }
    | '%'					{ ptr="%"; $$.node=build_node(ptr,NULL,NULL); }
    | '<'					{ ptr="<"; $$.node=build_node(ptr,NULL,NULL); }
    | '>'					{ ptr=">"; $$.node=build_node(ptr,NULL,NULL); }
    | '='					{ ptr="="; $$.node=build_node(ptr,NULL,NULL); }
    ;

logical_operator
    : '<'					{ ptr="<"; $$.node=build_node(ptr,NULL,NULL); }
    | '>'					{ ptr=">"; $$.node=build_node(ptr,NULL,NULL); }
    | '='					{ ptr="="; $$.node=build_node(ptr,NULL,NULL); }
    ;

type_specifier
    : CHAR                  { ptr="char"; $$.node=build_node(ptr,NULL,NULL); data_type=char_t ; $$.node->data_type=char_t; }      
    | INT					{ ptr="int"; $$.node=build_node(ptr,NULL,NULL); data_type=int_t ;  $$.node->data_type=int_t; }
    | DOUBLE				{ ptr="double"; $$.node=build_node(ptr,NULL,NULL); data_type=double_t; $$.node->data_type=double_t; }
    | BOOL					{ ptr="bool"; $$.node=build_node(ptr,NULL,NULL); data_type=bool_t ; $$.node->data_type=bool_t;}
    | STRUCT				{ ptr="struct"; $$.node=build_node(ptr,NULL,NULL); }
    | VOID					{ ptr="void"; $$.node=build_node(ptr,NULL,NULL); data_type=void_t;$$.node->data_type=void_t; }
    ;

primary_expression
    : CONSTANT_INT          { $$.node=build_node($1.name_token,NULL,NULL); $$.node->data_type=int_t; }
    | CONSTANT_CHAR         { $$.node=build_node($1.name_token,NULL,NULL); $$.node->data_type=char_t; }
    | CONSTANT_DOUBLE       { $$.node=build_node($1.name_token,NULL,NULL); $$.node->data_type=double_t; }
    | TRUE                  { ptr="true"; $$.node=build_node(ptr,NULL,NULL); $$.node->data_type=bool_t;  }
    | FALSE                 { ptr="false"; $$.node=build_node(ptr,NULL,NULL); $$.node->data_type=bool_t; }
    | ID					{ $$.node=build_node($1.name_token,NULL,NULL); item=search_in_all_sym_tbl(current_symbol_table , $1.name_token);
                                if(item==NULL){printf("ERROR: %s is undeclared identifier at %d\n",$1.name_token,line_number);}
                                else
                                {
                                    $$.node->data_type=item->data_type;
                                    if(item->iden_type==matrix_t) // id is matrix 
                                    {
                                        //printf("Got item for %s \n",item->name);
                                        $$.node->isMatrix=1;
                                        matrix_info.row=item->id_info.matrix_info.row;
                                        matrix_info.column=item->id_info.matrix_info.column;
                                        $$.node->matrix_info=matrix_info;
                                    }
                                }	
                                							
                            }	
    | STRING_LITERAL		{ $$.node=build_node($1.name_token,NULL,NULL); }
    | '('ID '('')'')'       { $$.node=build_node($2.name_token,NULL,NULL);
                                item=search_in_all_sym_tbl(current_symbol_table , $2.name_token);
                               if(item==NULL)
                               {	
                                    printf("ERROR: %s is undeclared identifier at %d\n",$2.name_token,line_number);
                                       $$.node->data_type=void_t; 
                                } 
                               else
                               {
                                    check_function_parameters(item->id_info.function_info.parameters,NULL);
                                    $$.node->data_type=item->data_type;
                                }
                            }
    | '('ID '(' id_list ')' ')' { $$.node=build_node( $2.name_token , $2.node , $4.node );
                                  item=search_in_all_sym_tbl(current_symbol_table , $2.name_token);
                                if(item==NULL)
                                {
                                    printf("ERROR: %s is undeclared identifier at %d\n",$2.name_token,line_number);
                                      $$.node->data_type=void_t;
                                } 
                                else{ 
                                    check_function_parameters(item->id_info.function_info.parameters,$4.node);
                                    $$.node->data_type=item->data_type; }    
                                }

     ;


id_list
    : primary_expression					{ $$.node=$1.node; }
    | postfix_expression					{ $$.node=$1.node; }
    | id_list ',' primary_expression		{ ptr="id_list" ; $$.node=build_node(ptr,$1.node,$3.node); }
    | id_list ',' postfix_expression		{ ptr="id_list" ; $$.node=build_node(ptr,$1.node,$3.node); }
    ;
    

%%



/*For insertion we store data temporarily*/
char *int_ptr="int";
char *char_ptr="char";
char *float_ptr="float";
char *doubl_ptr="double";

void yyerror () 
{
    fprintf(stderr, "ERROR: Parsing failed, Syntax error at line %d\n",line_number);
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
      table_push(current_symbol_table);                        // push the table to stack .
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
        printf("Semantic analysis completed \n");
        fclose(yyin);
        printf("\nAST in pre-order\n");
        print_ast(root);
        printf("\n");
        
        
        printf("\nSymbol Table \n");
        print_symbol_table(table_top());

        //check_function_return(root->left->left);
        return 0;
}

//It is used for linking parameters for functions 
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
