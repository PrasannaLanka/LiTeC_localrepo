/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DECLARE = 258,
    IF = 259,
    ELSE = 260,
    BREAK = 261,
    CONTINUE = 262,
    INVARIANT = 263,
    LOOP = 264,
    RETURN = 265,
    CONSTANT = 266,
    BOOL = 267,
    CHAR = 268,
    INT = 269,
    DOUBLE = 270,
    VOID = 271,
    ID = 272,
    STRING_LITERAL = 273,
    SF_OPEN = 274,
    SF_CLOSE = 275,
    STRUCT = 276,
    TEX = 277,
    TEX_OPEN = 278,
    TEX_CLOSE = 279,
    MS_OPEN = 280,
    MS_CLOSE = 281
  };
#endif
/* Tokens.  */
#define DECLARE 258
#define IF 259
#define ELSE 260
#define BREAK 261
#define CONTINUE 262
#define INVARIANT 263
#define LOOP 264
#define RETURN 265
#define CONSTANT 266
#define BOOL 267
#define CHAR 268
#define INT 269
#define DOUBLE 270
#define VOID 271
#define ID 272
#define STRING_LITERAL 273
#define SF_OPEN 274
#define SF_CLOSE 275
#define STRUCT 276
#define TEX 277
#define TEX_OPEN 278
#define TEX_CLOSE 279
#define MS_OPEN 280
#define MS_CLOSE 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
