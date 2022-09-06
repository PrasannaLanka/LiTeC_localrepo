%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *); 

%}

%token DECLARE RECEIVE IF ELSE BREAK CONTINUE INVARIANT LOOP RETURN
%token BOOL_1 CHAR_8 INT_64 DOUBLE_128
%token TEX TEX_OPEN TEX_CLOSE SF_OPEN SF_CLOSE MS_OPEN MS_CLOSE

%%
operator
    :   '+'
    |   '-'
    |   '*'
    |   '/'
    ;
    
%%

void yyerror(char *s) 
{
    fprintf(stderr, "%s\n", s);
} 


int main()
{
    yyparse();
    return 0;
}

