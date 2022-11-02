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
    CONSTANT_INT = 259,            /* CONSTANT_INT  */
    CONSTANT_CHAR = 260,           /* CONSTANT_CHAR  */
    CONSTANT_FLOAT = 261,          /* CONSTANT_FLOAT  */
    CONSTANT_DOUBLE = 262,         /* CONSTANT_DOUBLE  */
    BOOL = 263,                    /* BOOL  */
    CHAR = 264,                    /* CHAR  */
    INT = 265,                     /* INT  */
    DOUBLE = 266,                  /* DOUBLE  */
    VOID = 267,                    /* VOID  */
    ID = 268,                      /* ID  */
    STRING_LITERAL = 269,          /* STRING_LITERAL  */
    STRUCT = 270                   /* STRUCT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DECLARE 258
#define CONSTANT_INT 259
#define CONSTANT_CHAR 260
#define CONSTANT_FLOAT 261
#define CONSTANT_DOUBLE 262
#define BOOL 263
#define CHAR 264
#define INT 265
#define DOUBLE 266
#define VOID 267
#define ID 268
#define STRING_LITERAL 269
#define STRUCT 270

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "parser.y"

	struct token_node_t{
		char *name_token;
		struct ast_node_t *node;
	}token_node;

#line 104 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
