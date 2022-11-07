yacc -d parser.y
lex lex.l
gcc symbol_table.c ast.c semantic.c lex.yy.c y.tab.c  -o parser 