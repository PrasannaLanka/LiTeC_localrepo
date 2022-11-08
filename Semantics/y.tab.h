/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DECLARE = 258,                 /* DECLARE  */
    RETURN = 259,                  /* RETURN  */
    IF = 260,                      /* IF  */
    ELSE = 261,                    /* ELSE  */
    LOOP = 262,                    /* LOOP  */
    TEX = 263,                     /* TEX  */
    TEX_OPEN = 264,                /* TEX_OPEN  */
    TEX_CLOSE = 265,               /* TEX_CLOSE  */
    CONSTANT_INT = 266,            /* CONSTANT_INT  */
    CONSTANT_CHAR = 267,           /* CONSTANT_CHAR  */
    CONSTANT_FLOAT = 268,          /* CONSTANT_FLOAT  */
    CONSTANT_DOUBLE = 269,         /* CONSTANT_DOUBLE  */
    BOOL = 270,                    /* BOOL  */
    CHAR = 271,                    /* CHAR  */
    INT = 272,                     /* INT  */
    DOUBLE = 273,                  /* DOUBLE  */
    VOID = 274,                    /* VOID  */
    STRING_LITERAL = 275,          /* STRING_LITERAL  */
    STRUCT = 276,                  /* STRUCT  */
    ID = 277                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DECLARE 258
#define RETURN 259
#define IF 260
#define ELSE 261
#define LOOP 262
#define TEX 263
#define TEX_OPEN 264
#define TEX_CLOSE 265
#define CONSTANT_INT 266
#define CONSTANT_CHAR 267
#define CONSTANT_FLOAT 268
#define CONSTANT_DOUBLE 269
#define BOOL 270
#define CHAR 271
#define INT 272
#define DOUBLE 273
#define VOID 274
#define STRING_LITERAL 275
#define STRUCT 276
#define ID 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "parser.y"

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

#line 129 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
