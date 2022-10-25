


%{
   #include <stdio.h>
   #include <stdlib.h>
   #include "ast.h"
   int yylex(void);
   void yyerror(char *);
 
   extern FILE *yyin;

	char *temp_ptr;
	void mem();
 
%}



%union{
			struct token_node_t{
				char *name_token;
				struct ast_node_t* node;
				
			}token_node;


}


%token <token_node>  INT ID  CONSTANT END ASSG


%type <token_node> translation_unit


 
 
%start translation_unit

%%


translation_unit
	: INT ID ASSG CONSTANT END	{ printf("translation unit\n ") ; mem();temp_ptr="translation_unit";$$.node=build_node(temp_ptr,NULL,NULL); root=$$.node; }
	;

%%
 
void yyerror(char *s)
{
   fprintf(stderr, "%s\n", s);
   return ;
} 

void mem()
{
	/* temp_ptr=(char*)malloc(sizeof(char)*20); */
}
 
int main(int argc, char *argv[])
{
      init_symbol_table();
	  /* temp_ptr=(char*)malloc(sizeof(char)*10); */
	  temp_ptr="DEfault";
	  printf("In main \n");
   	  yyin=fopen(argv[--argc],"r");
	  printf("104 %s\n", temp_ptr);
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


