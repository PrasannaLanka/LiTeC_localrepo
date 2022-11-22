/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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
    int single_tex_function=0;
    
    void link_p(char *name ,enum data_type_t d );
    extern int line_number;

#line 100 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    CONTINUE = 260,                /* CONTINUE  */
    BREAK = 261,                   /* BREAK  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    LOOP = 264,                    /* LOOP  */
    TEX = 265,                     /* TEX  */
    TEX_OPEN = 266,                /* TEX_OPEN  */
    TEX_CLOSE = 267,               /* TEX_CLOSE  */
    CONSTANT_INT = 268,            /* CONSTANT_INT  */
    CONSTANT_CHAR = 269,           /* CONSTANT_CHAR  */
    CONSTANT_FLOAT = 270,          /* CONSTANT_FLOAT  */
    CONSTANT_DOUBLE = 271,         /* CONSTANT_DOUBLE  */
    BOOL = 272,                    /* BOOL  */
    CHAR = 273,                    /* CHAR  */
    INT = 274,                     /* INT  */
    DOUBLE = 275,                  /* DOUBLE  */
    VOID = 276,                    /* VOID  */
    STRING_LITERAL = 277,          /* STRING_LITERAL  */
    STRUCT = 278,                  /* STRUCT  */
    TRUE = 279,                    /* TRUE  */
    FALSE = 280,                   /* FALSE  */
    ID = 281,                      /* ID  */
    SF_OPEN = 282,                 /* SF_OPEN  */
    SF_CLOSE = 283,                /* SF_CLOSE  */
    MS_OPEN = 284,                 /* MS_OPEN  */
    MS_CLOSE = 285                 /* MS_CLOSE  */
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
#define CONTINUE 260
#define BREAK 261
#define IF 262
#define ELSE 263
#define LOOP 264
#define TEX 265
#define TEX_OPEN 266
#define TEX_CLOSE 267
#define CONSTANT_INT 268
#define CONSTANT_CHAR 269
#define CONSTANT_FLOAT 270
#define CONSTANT_DOUBLE 271
#define BOOL 272
#define CHAR 273
#define INT 274
#define DOUBLE 275
#define VOID 276
#define STRING_LITERAL 277
#define STRUCT 278
#define TRUE 279
#define FALSE 280
#define ID 281
#define SF_OPEN 282
#define SF_CLOSE 283
#define MS_OPEN 284
#define MS_CLOSE 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

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



#line 233 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DECLARE = 3,                    /* DECLARE  */
  YYSYMBOL_RETURN = 4,                     /* RETURN  */
  YYSYMBOL_CONTINUE = 5,                   /* CONTINUE  */
  YYSYMBOL_BREAK = 6,                      /* BREAK  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_LOOP = 9,                       /* LOOP  */
  YYSYMBOL_TEX = 10,                       /* TEX  */
  YYSYMBOL_TEX_OPEN = 11,                  /* TEX_OPEN  */
  YYSYMBOL_TEX_CLOSE = 12,                 /* TEX_CLOSE  */
  YYSYMBOL_CONSTANT_INT = 13,              /* CONSTANT_INT  */
  YYSYMBOL_CONSTANT_CHAR = 14,             /* CONSTANT_CHAR  */
  YYSYMBOL_CONSTANT_FLOAT = 15,            /* CONSTANT_FLOAT  */
  YYSYMBOL_CONSTANT_DOUBLE = 16,           /* CONSTANT_DOUBLE  */
  YYSYMBOL_BOOL = 17,                      /* BOOL  */
  YYSYMBOL_CHAR = 18,                      /* CHAR  */
  YYSYMBOL_INT = 19,                       /* INT  */
  YYSYMBOL_DOUBLE = 20,                    /* DOUBLE  */
  YYSYMBOL_VOID = 21,                      /* VOID  */
  YYSYMBOL_STRING_LITERAL = 22,            /* STRING_LITERAL  */
  YYSYMBOL_STRUCT = 23,                    /* STRUCT  */
  YYSYMBOL_TRUE = 24,                      /* TRUE  */
  YYSYMBOL_FALSE = 25,                     /* FALSE  */
  YYSYMBOL_ID = 26,                        /* ID  */
  YYSYMBOL_SF_OPEN = 27,                   /* SF_OPEN  */
  YYSYMBOL_SF_CLOSE = 28,                  /* SF_CLOSE  */
  YYSYMBOL_MS_OPEN = 29,                   /* MS_OPEN  */
  YYSYMBOL_MS_CLOSE = 30,                  /* MS_CLOSE  */
  YYSYMBOL_31_ = 31,                       /* '{'  */
  YYSYMBOL_32_ = 32,                       /* '}'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* ':'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_45_ = 45,                       /* '<'  */
  YYSYMBOL_46_ = 46,                       /* '>'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_translation_main = 49,          /* translation_main  */
  YYSYMBOL_translation = 50,               /* translation  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_translation_init = 53,          /* translation_init  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_translation_unit = 55,          /* translation_unit  */
  YYSYMBOL_external_declaration = 56,      /* external_declaration  */
  YYSYMBOL_function_definition = 57,       /* function_definition  */
  YYSYMBOL_58_4 = 58,                      /* $@4  */
  YYSYMBOL_function_body = 59,             /* function_body  */
  YYSYMBOL_60_5 = 60,                      /* $@5  */
  YYSYMBOL_body = 61,                      /* body  */
  YYSYMBOL_compound_statement = 62,        /* compound_statement  */
  YYSYMBOL_63_6 = 63,                      /* $@6  */
  YYSYMBOL_compound_statement_content = 64, /* compound_statement_content  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_selection_statement = 66,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 67,       /* iteration_statement  */
  YYSYMBOL_tex_statement = 68,             /* tex_statement  */
  YYSYMBOL_tex_data = 69,                  /* tex_data  */
  YYSYMBOL_tex_function = 70,              /* tex_function  */
  YYSYMBOL_jump_statement = 71,            /* jump_statement  */
  YYSYMBOL_declaration = 72,               /* declaration  */
  YYSYMBOL_expression_statement = 73,      /* expression_statement  */
  YYSYMBOL_expression = 74,                /* expression  */
  YYSYMBOL_assignment_expression = 75,     /* assignment_expression  */
  YYSYMBOL_matrix_assignment = 76,         /* matrix_assignment  */
  YYSYMBOL_matrix_index = 77,              /* matrix_index  */
  YYSYMBOL_matrix_value = 78,              /* matrix_value  */
  YYSYMBOL_init_declarator = 79,           /* init_declarator  */
  YYSYMBOL_declarator = 80,                /* declarator  */
  YYSYMBOL_81_7 = 81,                      /* $@7  */
  YYSYMBOL_parameter_list = 82,            /* parameter_list  */
  YYSYMBOL_postfix_expression = 83,        /* postfix_expression  */
  YYSYMBOL_logical_expression = 84,        /* logical_expression  */
  YYSYMBOL_binary_operator = 85,           /* binary_operator  */
  YYSYMBOL_logical_operator = 86,          /* logical_operator  */
  YYSYMBOL_type_specifier = 87,            /* type_specifier  */
  YYSYMBOL_primary_expression = 88,        /* primary_expression  */
  YYSYMBOL_id_list = 89                    /* id_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      33,    34,    42,    40,    36,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    35,
      45,    47,    46,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    80,    80,    81,    81,    86,    86,    90,
      91,    95,    96,   100,   100,   104,   104,   118,   119,   124,
     124,   129,   130,   131,   132,   136,   137,   138,   139,   140,
     143,   148,   149,   154,   159,   168,   172,   173,   174,   175,
     179,   183,   184,   185,   186,   190,   194,   195,   200,   201,
     202,   206,   207,   208,   211,   217,   225,   230,   231,   232,
     236,   240,   247,   247,   266,   283,   291,   304,   319,   333,
     347,   364,   365,   369,   370,   371,   372,   373,   374,   375,
     376,   380,   381,   382,   386,   387,   388,   389,   390,   391,
     395,   396,   397,   398,   399,   400,   416,   417,   429,   445,
     446,   447,   448
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DECLARE", "RETURN",
  "CONTINUE", "BREAK", "IF", "ELSE", "LOOP", "TEX", "TEX_OPEN",
  "TEX_CLOSE", "CONSTANT_INT", "CONSTANT_CHAR", "CONSTANT_FLOAT",
  "CONSTANT_DOUBLE", "BOOL", "CHAR", "INT", "DOUBLE", "VOID",
  "STRING_LITERAL", "STRUCT", "TRUE", "FALSE", "ID", "SF_OPEN", "SF_CLOSE",
  "MS_OPEN", "MS_CLOSE", "'{'", "'}'", "'('", "')'", "';'", "','", "':'",
  "'['", "']'", "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'='",
  "$accept", "translation_main", "translation", "$@1", "$@2",
  "translation_init", "$@3", "translation_unit", "external_declaration",
  "function_definition", "$@4", "function_body", "$@5", "body",
  "compound_statement", "$@6", "compound_statement_content", "statement",
  "selection_statement", "iteration_statement", "tex_statement",
  "tex_data", "tex_function", "jump_statement", "declaration",
  "expression_statement", "expression", "assignment_expression",
  "matrix_assignment", "matrix_index", "matrix_value", "init_declarator",
  "declarator", "$@7", "parameter_list", "postfix_expression",
  "logical_expression", "binary_operator", "logical_operator",
  "type_specifier", "primary_expression", "id_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-72)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,  -150,    45,    20,    22,  -150,  -150,    25,    21,    22,
     332,  -150,    27,   263,  -150,  -150,  -150,  -150,  -150,  -150,
      77,  -150,  -150,  -150,  -150,  -150,    30,  -150,  -150,    30,
       2,    32,    28,   332,  -150,    40,    39,    61,  -150,   289,
     332,  -150,  -150,   263,    37,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,   249,  -150,  -150,   144,     3,    51,    41,    48,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   289,   224,
      43,    47,    50,    53,    56,   -23,  -150,  -150,    52,  -150,
     177,  -150,  -150,  -150,  -150,  -150,  -150,  -150,    64,  -150,
    -150,  -150,  -150,  -150,   263,  -150,    75,    -6,   289,   289,
      59,  -150,    67,  -150,  -150,   307,   238,     0,   289,   312,
      66,   210,  -150,   224,  -150,  -150,  -150,    78,    69,    71,
    -150,  -150,     8,    85,    88,    89,    92,    79,     6,    94,
     -10,   307,   312,  -150,   -15,  -150,  -150,  -150,    83,    73,
     312,  -150,   252,   111,  -150,  -150,  -150,  -150,    95,   289,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,   307,    99,    96,
     120,  -150,     1,   101,  -150,  -150,   105,  -150,  -150,  -150,
    -150,  -150,   126,   284,  -150,  -150,  -150,   312,  -150,    99,
      99,   107,   106,  -150,  -150,    99,  -150,  -150
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     0,     2,     0,     1,     3,     0,     0,     0,
       0,     6,     0,     0,    87,    84,    85,    86,    89,    88,
       0,     9,    12,    11,    13,     4,     0,     7,    10,     0,
      60,     0,    57,     0,    14,     0,    62,     0,    45,     0,
       8,    15,    61,     0,     0,    90,    91,    92,    96,    93,
      94,    95,     0,    59,    58,     0,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,     0,     0,
       0,     0,     0,     0,     0,    95,    19,    46,     0,    25,
       0,    22,    27,    28,    29,    30,    21,    26,     0,    48,
      53,    50,    49,    63,     0,    65,     0,     0,     0,     0,
      43,    18,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     0,    16,     0,    24,    23,    47,     0,     0,     0,
     100,    99,     0,     0,     0,     0,     0,    44,     0,     0,
      49,     0,     0,    36,     0,    37,    52,    51,     0,     0,
       0,    54,     0,     0,    17,    66,    64,    97,     0,     0,
      70,    69,    68,    67,    81,    82,    83,     0,     0,     0,
       0,    35,     0,     0,    56,    43,     0,    20,    98,   102,
     101,    72,    31,     0,    40,    38,    39,     0,    44,     0,
       0,     0,     0,    32,    33,     0,    55,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,  -150,  -150,   143,  -150,   122,    -7,  -150,
    -150,  -150,  -150,  -150,  -149,  -150,    54,   -75,  -150,  -150,
    -150,  -150,    -3,  -150,   -54,   -63,   -67,  -150,  -150,  -150,
    -150,  -150,   127,  -150,  -150,   -36,    31,  -150,  -150,    -9,
     -39,  -150
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     9,     4,     8,    33,    20,    21,    22,
      29,    34,    55,    78,    79,   111,    80,    81,    82,    83,
      84,   134,   135,    85,    23,    87,    88,    89,    90,   110,
     141,    31,    32,    43,    56,    91,   129,    68,   157,    24,
      92,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    86,   102,    53,    26,   114,   101,    45,    46,   172,
      47,   132,   132,    28,   108,   109,    48,   161,    49,    50,
      51,   162,   133,   175,   -71,   -71,   115,    52,   119,    99,
     183,   184,    98,    28,    57,    36,   187,    93,   128,    94,
      37,     1,   148,   131,   149,     5,   102,     6,     7,    11,
     144,   154,   155,   156,    10,    25,    30,    86,   121,   124,
     126,   120,   123,   125,   128,    39,   130,    38,   114,   137,
     139,    41,   136,    42,    44,   166,    58,    95,   103,    96,
      13,    97,   104,   105,   112,   117,   106,   107,   118,   115,
     171,   -46,   130,   160,    14,    15,    16,    17,    18,   116,
      19,   164,   127,   140,   145,   147,   181,    27,   146,    59,
     170,   -47,   163,   169,    13,   142,    70,    71,    72,   150,
      73,    74,   151,   152,    45,    46,   153,    47,   158,   168,
      76,   173,   174,    48,   179,    49,    50,    75,   182,   177,
     178,   185,    76,   167,    52,   186,    77,    13,    69,    70,
      71,    72,    12,    73,    74,    40,    35,    45,    46,   176,
      47,     0,   159,     0,     0,   143,    48,     0,    49,    50,
      75,     0,     0,     0,     0,    76,     0,    52,     0,    77,
      13,   113,    70,    71,    72,     0,    73,    74,     0,     0,
      45,    46,     0,    47,     0,     0,     0,     0,     0,    48,
       0,    49,    50,    75,     0,     0,     0,     0,    76,     0,
      52,     0,    77,    13,   142,    70,    71,    72,     0,    73,
      74,     0,     0,    45,    46,     0,    47,     0,     0,     0,
       0,     0,    48,     0,    49,    50,    75,    45,    46,     0,
      47,    76,     0,    52,     0,    77,    48,     0,    49,    50,
      75,    45,    46,     0,    47,     0,     0,    52,     0,   100,
      48,     0,    49,    50,    75,    45,    46,     0,    47,     0,
       0,    52,     0,    77,    48,    59,    49,    50,    75,     0,
      14,    15,    16,    17,    18,    52,    19,   165,     0,    60,
      61,    62,    63,    64,    65,    66,    67,    45,    46,     0,
      47,     0,    45,    46,     0,    47,    48,     0,    49,    50,
      75,    48,     0,    49,    50,    51,     0,    52,   180,     0,
      45,    46,    52,    47,     0,    45,    46,     0,    47,    48,
       0,    49,    50,    75,    48,    13,    49,    50,    51,     0,
      52,     0,     0,     0,     0,   138,     0,     0,     0,    14,
      15,    16,    17,    18,     0,    19
};

static const yytype_int16 yycheck[] =
{
      39,    55,    69,    39,    13,    80,    69,    13,    14,   158,
      16,    11,    11,    20,    37,    38,    22,    32,    24,    25,
      26,    36,    22,    22,    34,    35,    80,    33,    34,    68,
     179,   180,    68,    40,    43,    33,   185,    34,   105,    36,
      38,    27,    34,   106,    36,     0,   113,    27,    26,    28,
     113,    45,    46,    47,    29,    28,    26,   111,    97,    98,
      99,    97,    98,    99,   131,    37,   105,    35,   143,   108,
     109,    31,   108,    34,    13,   142,    39,    26,    35,    38,
       3,    33,    35,    33,    32,    94,    33,    31,    13,   143,
     157,    32,   131,   132,    17,    18,    19,    20,    21,    35,
      23,   140,    35,    37,    26,    34,   173,    30,    39,    26,
     149,    32,    39,   149,     3,     4,     5,     6,     7,    34,
       9,    10,    34,    34,    13,    14,    34,    16,    34,    34,
      31,    35,    12,    22,     8,    24,    25,    26,   177,    38,
      35,    34,    31,    32,    33,    39,    35,     3,     4,     5,
       6,     7,     9,     9,    10,    33,    29,    13,    14,   162,
      16,    -1,   131,    -1,    -1,   111,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    35,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      33,    -1,    35,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    -1,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    22,    -1,    24,    25,    26,    13,    14,    -1,
      16,    31,    -1,    33,    -1,    35,    22,    -1,    24,    25,
      26,    13,    14,    -1,    16,    -1,    -1,    33,    -1,    35,
      22,    -1,    24,    25,    26,    13,    14,    -1,    16,    -1,
      -1,    33,    -1,    35,    22,    26,    24,    25,    26,    -1,
      17,    18,    19,    20,    21,    33,    23,    35,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    13,    14,    -1,
      16,    -1,    13,    14,    -1,    16,    22,    -1,    24,    25,
      26,    22,    -1,    24,    25,    26,    -1,    33,    34,    -1,
      13,    14,    33,    16,    -1,    13,    14,    -1,    16,    22,
      -1,    24,    25,    26,    22,     3,    24,    25,    26,    -1,
      33,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    -1,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    49,    50,    52,     0,    27,    26,    53,    51,
      29,    28,    53,     3,    17,    18,    19,    20,    21,    23,
      55,    56,    57,    72,    87,    28,    87,    30,    56,    58,
      26,    79,    80,    54,    59,    80,    33,    38,    35,    37,
      55,    31,    34,    81,    13,    13,    14,    16,    22,    24,
      25,    26,    33,    83,    88,    60,    82,    87,    39,    26,
      40,    41,    42,    43,    44,    45,    46,    47,    85,     4,
       5,     6,     7,     9,    10,    26,    31,    35,    61,    62,
      64,    65,    66,    67,    68,    71,    72,    73,    74,    75,
      76,    83,    88,    34,    36,    26,    38,    33,    83,    88,
      35,    73,    74,    35,    35,    33,    33,    31,    37,    38,
      77,    63,    32,     4,    65,    72,    35,    87,    13,    34,
      83,    88,    89,    83,    88,    83,    88,    35,    74,    84,
      88,    73,    11,    22,    69,    70,    83,    88,    33,    88,
      37,    78,     4,    64,    73,    26,    39,    34,    34,    36,
      34,    34,    34,    34,    45,    46,    47,    86,    34,    84,
      88,    32,    36,    39,    88,    35,    74,    32,    34,    83,
      88,    74,    62,    35,    12,    22,    70,    38,    35,     8,
      34,    74,    88,    62,    62,    34,    39,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    51,    50,    52,    50,    54,    53,    55,
      55,    56,    56,    58,    57,    60,    59,    61,    61,    63,
      62,    64,    64,    64,    64,    65,    65,    65,    65,    65,
      65,    66,    66,    67,    67,    68,    69,    69,    69,    69,
      70,    71,    71,    71,    71,    72,    73,    73,    74,    74,
      74,    75,    75,    75,    76,    77,    78,    79,    79,    79,
      80,    80,    81,    80,    80,    82,    82,    83,    83,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    87,    87,    87,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    89,
      89,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     5,     0,     4,     0,     6,     1,
       2,     1,     1,     0,     3,     0,     5,     3,     2,     0,
       4,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     5,     7,     7,     8,     4,     1,     1,     3,     3,
       3,     2,     2,     2,     3,     4,     1,     2,     1,     1,
       1,     3,     3,     1,     3,     6,     2,     1,     3,     3,
       1,     3,     0,     5,     7,     2,     4,     5,     5,     5,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     6,     1,
       1,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* translation_main: translation  */
#line 76 "parser.y"
                                                        { ptr = "Main"; (yyval.token_node).node = build_node(ptr,(yyvsp[0].token_node).node,NULL); root = (yyval.token_node).node; }
#line 1468 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 80 "parser.y"
                              {}
#line 1474 "y.tab.c"
    break;

  case 4: /* translation: translation SF_OPEN $@1 translation_init SF_CLOSE  */
#line 80 "parser.y"
                                                                           {current_symbol_table=table_pop();current_symbol_table=table_top(); ptr = "sub_file"; (yyval.token_node).node = build_node(ptr,(yyvsp[-4].token_node).node,(yyvsp[-1].token_node).node); }
#line 1480 "y.tab.c"
    break;

  case 5: /* $@2: %empty  */
#line 81 "parser.y"
                  {}
#line 1486 "y.tab.c"
    break;

  case 6: /* translation: SF_OPEN $@2 translation_init SF_CLOSE  */
#line 81 "parser.y"
                                                               {current_symbol_table=table_pop();current_symbol_table=table_top();
                                                                                                                                                                  ptr = "sub_file"; (yyval.token_node).node = build_node(ptr,(yyvsp[-1].token_node).node,NULL); }
#line 1493 "y.tab.c"
    break;

  case 7: /* $@3: %empty  */
#line 86 "parser.y"
                                               {current_symbol_table=init_child_symbol_table(current_symbol_table); table_push(current_symbol_table);}
#line 1499 "y.tab.c"
    break;

  case 8: /* translation_init: ID MS_OPEN translation_unit MS_CLOSE $@3 translation_unit  */
#line 86 "parser.y"
                                                                                                                                                                        { ptr = "trans_init"; (yyval.token_node).node = build_node(ptr,(yyvsp[-3].token_node).node,(yyvsp[0].token_node).node); }
#line 1505 "y.tab.c"
    break;

  case 9: /* translation_unit: external_declaration  */
#line 90 "parser.y"
                                                    { ptr = "trans_unit"; (yyval.token_node).node = (yyvsp[0].token_node).node; }
#line 1511 "y.tab.c"
    break;

  case 10: /* translation_unit: translation_unit external_declaration  */
#line 91 "parser.y"
                                                        { ptr = "trans_unit"; (yyval.token_node).node = build_node(ptr,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node); }
#line 1517 "y.tab.c"
    break;

  case 11: /* external_declaration: declaration  */
#line 95 "parser.y"
                                                                                        { ptr="external_declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1523 "y.tab.c"
    break;

  case 12: /* external_declaration: function_definition  */
#line 96 "parser.y"
                                                                        { ptr="fun_declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); check_function_return((yyval.token_node).node); }
#line 1529 "y.tab.c"
    break;

  case 13: /* $@4: %empty  */
#line 100 "parser.y"
                     { }
#line 1535 "y.tab.c"
    break;

  case 14: /* function_definition: type_specifier $@4 function_body  */
#line 100 "parser.y"
                                                                { ptr="fun_def"; (yyval.token_node).node=build_node((yyvsp[0].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 1541 "y.tab.c"
    break;

  case 15: /* $@5: %empty  */
#line 104 "parser.y"
                     {}
#line 1547 "y.tab.c"
    break;

  case 16: /* function_body: declarator '{' $@5 body '}'  */
#line 104 "parser.y"
                                                                        { temp_symbol_table=table_pop(); current_symbol_table=table_top();
                                                      ptr="fun_body"; no_of_parameters=0;
                                                      if((yyvsp[-4].token_node).node->left!=NULL)
                                                        {
                                                            (yyval.token_node).node=build_node((yyvsp[-4].token_node).node->name,(yyvsp[-4].token_node).node->left,(yyvsp[-1].token_node).node);
                                                        }  
                                                      else
                                                        {
                                                            (yyval.token_node).node=build_node(ptr,NULL,(yyvsp[-1].token_node).node);
                                                        }														
                                                    }
#line 1563 "y.tab.c"
    break;

  case 17: /* body: compound_statement_content RETURN expression_statement  */
#line 118 "parser.y"
                                                               { ptr="body"; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 1569 "y.tab.c"
    break;

  case 18: /* body: RETURN expression_statement  */
#line 119 "parser.y"
                                                                                           { ptr="body"; (yyval.token_node).node=build_node(ptr,NULL,(yyvsp[0].token_node).node); }
#line 1575 "y.tab.c"
    break;

  case 19: /* $@6: %empty  */
#line 124 "parser.y"
          { current_symbol_table=init_child_symbol_table(current_symbol_table); table_push(current_symbol_table);}
#line 1581 "y.tab.c"
    break;

  case 20: /* compound_statement: '{' $@6 compound_statement_content '}'  */
#line 125 "parser.y"
                                            {current_symbol_table=table_pop();current_symbol_table=table_top();	 ptr="cmp_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,NULL); }
#line 1587 "y.tab.c"
    break;

  case 21: /* compound_statement_content: declaration  */
#line 129 "parser.y"
                                                                                        { ptr="declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1593 "y.tab.c"
    break;

  case 22: /* compound_statement_content: statement  */
#line 130 "parser.y"
                                                                                        { ptr="stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1599 "y.tab.c"
    break;

  case 23: /* compound_statement_content: compound_statement_content declaration  */
#line 131 "parser.y"
                                                        { ptr="cmp_stmt_content"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node); }
#line 1605 "y.tab.c"
    break;

  case 24: /* compound_statement_content: compound_statement_content statement  */
#line 132 "parser.y"
                                                        { ptr="cmp_stmt_content"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node); }
#line 1611 "y.tab.c"
    break;

  case 25: /* statement: compound_statement  */
#line 136 "parser.y"
                                                                                { ptr="comp_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1617 "y.tab.c"
    break;

  case 26: /* statement: expression_statement  */
#line 137 "parser.y"
                                                                                { ptr="expr_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1623 "y.tab.c"
    break;

  case 27: /* statement: selection_statement  */
#line 138 "parser.y"
                                                                                { ptr="sel_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1629 "y.tab.c"
    break;

  case 28: /* statement: iteration_statement  */
#line 139 "parser.y"
                                                                                { ptr="itr_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1635 "y.tab.c"
    break;

  case 29: /* statement: tex_statement  */
#line 140 "parser.y"
                                                                                        { ptr="tex_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); 
                                                    single_tex_function++; if(single_tex_function==2){ printf("\n More than one TeX Function \n") ; }  }
#line 1642 "y.tab.c"
    break;

  case 30: /* statement: jump_statement  */
#line 143 "parser.y"
                                                                                {  ptr = "jump_stmt"; (yyval.token_node).node = build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1648 "y.tab.c"
    break;

  case 31: /* selection_statement: IF '(' logical_expression ')' compound_statement  */
#line 148 "parser.y"
                                                                                                                        { ptr = "if_"; (yyval.token_node).node = build_node(ptr, (yyvsp[-2].token_node).node, (yyvsp[0].token_node).node); }
#line 1654 "y.tab.c"
    break;

  case 32: /* selection_statement: IF '(' logical_expression ')' compound_statement ELSE compound_statement  */
#line 149 "parser.y"
                                                                                                { ptr = "if_"; ast_node* _if = build_node(ptr, (yyvsp[-4].token_node).node, (yyvsp[-2].token_node).node); 
                                                                                          ptr = "if_else"; (yyval.token_node).node = build_node(ptr, _if, (yyvsp[0].token_node).node); }
#line 1661 "y.tab.c"
    break;

  case 33: /* iteration_statement: LOOP '(' expression_statement logical_expression ';' ')' compound_statement  */
#line 155 "parser.y"
            {
                ptr = "lp_cdn"; ast_node* lp_cdn = build_node(ptr, (yyvsp[-3].token_node).node, (yyvsp[0].token_node).node);
                ptr = "loop"; (yyval.token_node).node = build_node(ptr, (yyvsp[-4].token_node).node, lp_cdn);
            }
#line 1670 "y.tab.c"
    break;

  case 34: /* iteration_statement: LOOP '(' expression_statement logical_expression ';' expression ')' compound_statement  */
#line 160 "parser.y"
            {
                ptr = "lp_cdn"; ast_node* lp_cdn = build_node(ptr, (yyvsp[-4].token_node).node, (yyvsp[0].token_node).node);
                ptr = "lp_itr"; ast_node* lp_itr = build_node(ptr, (yyvsp[-2].token_node).node, lp_cdn);
                ptr = "loop"; (yyval.token_node).node = build_node(ptr, (yyvsp[-5].token_node).node, lp_itr);
            }
#line 1680 "y.tab.c"
    break;

  case 35: /* tex_statement: TEX '{' tex_data '}'  */
#line 168 "parser.y"
                                                                        { ptr = "tex"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1686 "y.tab.c"
    break;

  case 36: /* tex_data: STRING_LITERAL  */
#line 172 "parser.y"
                                                                                { ptr = "tex_str"; (yyval.token_node).node = build_node(ptr, (yyvsp[0].token_node).node, NULL); }
#line 1692 "y.tab.c"
    break;

  case 37: /* tex_data: tex_function  */
#line 173 "parser.y"
                                                                                        { ptr = "tex_fun"; (yyval.token_node).node = build_node(ptr, NULL, (yyvsp[0].token_node).node); }
#line 1698 "y.tab.c"
    break;

  case 38: /* tex_data: tex_data ',' STRING_LITERAL  */
#line 174 "parser.y"
                                                                        { ptr = "tex_data"; (yyval.token_node).node = build_node(ptr, (yyvsp[0].token_node).node, (yyvsp[-2].token_node).node); }
#line 1704 "y.tab.c"
    break;

  case 39: /* tex_data: tex_data ',' tex_function  */
#line 175 "parser.y"
                                                                        { ptr = "tex_data"; (yyval.token_node).node = build_node(ptr, (yyvsp[-2].token_node).node, (yyvsp[0].token_node).node); }
#line 1710 "y.tab.c"
    break;

  case 40: /* tex_function: TEX_OPEN primary_expression TEX_CLOSE  */
#line 179 "parser.y"
                                                                { (yyval.token_node).node = (yyvsp[-1].token_node).node; }
#line 1716 "y.tab.c"
    break;

  case 41: /* jump_statement: CONTINUE ';'  */
#line 183 "parser.y"
                                                                                        { ptr = "j_cnt"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1722 "y.tab.c"
    break;

  case 42: /* jump_statement: BREAK ';'  */
#line 184 "parser.y"
                                                                                        { ptr = "j_brk"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1728 "y.tab.c"
    break;

  case 43: /* jump_statement: RETURN ';'  */
#line 185 "parser.y"
                                                                                        { ptr = "j_rtn"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1734 "y.tab.c"
    break;

  case 44: /* jump_statement: RETURN expression ';'  */
#line 186 "parser.y"
                                                                                { ptr = "ret_exp"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1740 "y.tab.c"
    break;

  case 45: /* declaration: DECLARE type_specifier init_declarator ';'  */
#line 190 "parser.y"
                                                        { ptr="declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node); }
#line 1746 "y.tab.c"
    break;

  case 46: /* expression_statement: ';'  */
#line 194 "parser.y"
                                                                                                { ptr=";"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1752 "y.tab.c"
    break;

  case 47: /* expression_statement: expression ';'  */
#line 195 "parser.y"
                                                                { ptr="expr"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,NULL); }
#line 1758 "y.tab.c"
    break;

  case 48: /* expression: assignment_expression  */
#line 200 "parser.y"
                                                                                { ptr="assign_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1764 "y.tab.c"
    break;

  case 49: /* expression: primary_expression  */
#line 201 "parser.y"
                                                                                { ptr="prm_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); (yyval.token_node).node->data_type=(yyvsp[0].token_node).node->data_type; }
#line 1770 "y.tab.c"
    break;

  case 50: /* expression: postfix_expression  */
#line 202 "parser.y"
                                                                                { ptr="post_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1776 "y.tab.c"
    break;

  case 51: /* assignment_expression: ID ':' primary_expression  */
#line 206 "parser.y"
                                                                        { ptr="assignment";(yyval.token_node).node=build_node((yyvsp[-2].token_id).name_token,(yyvsp[-2].token_id).node,(yyvsp[0].token_node).node); check_assignment(current_symbol_table , (yyval.token_node).node); }
#line 1782 "y.tab.c"
    break;

  case 52: /* assignment_expression: ID ':' postfix_expression  */
#line 207 "parser.y"
                                                                        { ptr="assignment";(yyval.token_node).node=build_node((yyvsp[-2].token_id).name_token,(yyvsp[-2].token_id).node,(yyvsp[0].token_node).node); check_assignment(current_symbol_table , (yyval.token_node).node); }
#line 1788 "y.tab.c"
    break;

  case 53: /* assignment_expression: matrix_assignment  */
#line 208 "parser.y"
                                                    {(yyval.token_node).node=(yyvsp[0].token_node).node; }
#line 1794 "y.tab.c"
    break;

  case 54: /* matrix_assignment: ID matrix_index matrix_value  */
#line 211 "parser.y"
                                                    { (yyval.token_node).node=build_node((yyvsp[-2].token_id).name_token,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node); 
                                                      
                                                     if ( check_matrix_assignment(current_symbol_table ,(yyval.token_node).node)==0){}       }
#line 1802 "y.tab.c"
    break;

  case 55: /* matrix_index: '[' primary_expression ']' '[' primary_expression ']'  */
#line 217 "parser.y"
                                                             {ptr="matrix_index"; (yyval.token_node).node=build_node(ptr,(yyvsp[-4].token_node).node,(yyvsp[-1].token_node).node); 
                                                                if((yyvsp[-4].token_node).node->data_type!=int_t)
                                                                { printf(" ERROR : row index must be int data type at line %d \n",line_number);}
                                                                if((yyvsp[-1].token_node).node->data_type!=int_t)
                                                                { printf(" ERROR : column index must be int data type at line %d \n",line_number);}      
                                                                }
#line 1813 "y.tab.c"
    break;

  case 56: /* matrix_value: ':' primary_expression  */
#line 225 "parser.y"
                                                    {ptr="prm_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); (yyval.token_node).node->data_type=(yyvsp[0].token_node).node->data_type; }
#line 1819 "y.tab.c"
    break;

  case 57: /* init_declarator: declarator  */
#line 230 "parser.y"
                                                                { ptr="init_declarator";(yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1825 "y.tab.c"
    break;

  case 58: /* init_declarator: declarator ':' primary_expression  */
#line 231 "parser.y"
                                                                { ptr="init_declarator";(yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); check_declaration((yyval.token_node).node); }
#line 1831 "y.tab.c"
    break;

  case 59: /* init_declarator: declarator ':' postfix_expression  */
#line 232 "parser.y"
                                                                { ptr="init_declarator";(yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); check_declaration((yyval.token_node).node); }
#line 1837 "y.tab.c"
    break;

  case 60: /* declarator: ID  */
#line 236 "parser.y"
                                                                                                { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[0].token_id).name_token , variable_t , data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}
                                                       (yyvsp[0].token_id).data_type=get_type(data_type);	(yyval.token_node).node=build_node((yyvsp[0].token_id).name_token,(yyvsp[0].token_id).node,NULL);	(yyval.token_node).node->data_type=data_type; 
                                                    }
#line 1846 "y.tab.c"
    break;

  case 61: /* declarator: ID '(' ')'  */
#line 240 "parser.y"
                                                                                        { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[-2].token_id).name_token , function_t,data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);} 
                                                      current_symbol_table=init_child_symbol_table(current_symbol_table); 
                                                      table_push(current_symbol_table);																			
                                                      item=search_in_all_sym_tbl(current_symbol_table , (yyvsp[-2].token_id).name_token);
                                                      (yyvsp[-2].token_id).data_type=get_type(data_type);	(yyval.token_node).node=build_node((yyvsp[-2].token_id).name_token,(yyvsp[-2].token_id).node,NULL);	(yyval.token_node).node->data_type=data_type; 
                                                    }
#line 1858 "y.tab.c"
    break;

  case 62: /* $@7: %empty  */
#line 247 "parser.y"
                                                                        { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[-1].token_id).name_token , function_t , data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}
                                                      current_symbol_table=init_child_symbol_table(current_symbol_table); ptr="LOCAL"; current_symbol_table->name=(char*)malloc(sizeof(char)*10);
                                                      strcpy(current_symbol_table->name,ptr); table_push(current_symbol_table); 
                                                      parameter_list=(param*)malloc(sizeof(param));
                                                      params=(param*)malloc(sizeof(param));
                                                      parameter_list=params; 
                                                    }
#line 1871 "y.tab.c"
    break;

  case 63: /* declarator: ID '(' $@7 parameter_list ')'  */
#line 255 "parser.y"
                                                                        { item=search_in_all_sym_tbl(current_symbol_table , (yyvsp[-4].token_id).name_token);											
                                                      function_info.return_data_type=data_type;
                                                      function_info.no_parameters=no_of_parameters;
                                                      function_info.parameters=parameter_list->next;
                                                      id_info.function_info=function_info; 
                                                      item->id_info=id_info;
                                                      parameter_list=NULL;
                                                      params=parameter_list;										
                                                      (yyvsp[-4].token_id).data_type=get_type(data_type); (yyval.token_node).node=build_node((yyvsp[-4].token_id).name_token ,(yyvsp[-1].token_node).node ,NULL ); (yyval.token_node).node->data_type=data_type; 
                                                      }
#line 1886 "y.tab.c"
    break;

  case 64: /* declarator: ID '[' CONSTANT_INT ']' '[' CONSTANT_INT ']'  */
#line 266 "parser.y"
                                                    { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[-6].token_id).name_token , matrix_t , data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}  
                                                            
                                                            (yyval.token_node).node=build_node((yyvsp[-6].token_id).name_token,(yyvsp[-6].token_id).node,NULL);   
                                                            (yyval.token_node).node->data_type=data_type;
                                                            item=search_in_all_sym_tbl(current_symbol_table, (yyvsp[-6].token_id).name_token);
                                                            
                                                            matrix_info.row=atoi((yyvsp[-4].token_node).name_token);
                                                            matrix_info.column=atoi((yyvsp[-1].token_node).name_token);
                                                            id_info.matrix_info=matrix_info;
                                                            item->id_info=id_info;

                                                            }
#line 1904 "y.tab.c"
    break;

  case 65: /* parameter_list: type_specifier ID  */
#line 283 "parser.y"
                                                        { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[0].token_id).name_token , function_param , data_type)==false)
                                                                                {printf("ERROR: Redeclaration of variable at line %d\n",line_number);} 
                                                                                else {
                                                                                    no_of_parameters++;    
                                                                                    (yyval.token_node).node=build_node((yyvsp[0].token_id).name_token,NULL,NULL); 
                                                                                    (yyval.token_node).node->data_type=data_type; 	
                                                                                    link_p((yyvsp[0].token_id).name_token,data_type); } 																				
                                                        }
#line 1917 "y.tab.c"
    break;

  case 66: /* parameter_list: parameter_list ',' type_specifier ID  */
#line 291 "parser.y"
                                                                        { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[0].token_id).name_token , function_param , data_type)==false)
                                                                                {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}  
                                                                                else {
                                                                                    (yyvsp[0].token_id).node=build_node((yyvsp[0].token_id).name_token,NULL,NULL);
                                                                                    (yyvsp[0].token_id).node->data_type=data_type;  
                                                                                    no_of_parameters++;
                                                                                    ptr="param_list";  (yyval.token_node).node=build_node(ptr,(yyvsp[-3].token_node).node,(yyvsp[0].token_id).node ); 																				 
                                                                                    link_p((yyvsp[-1].token_node).name_token,data_type);   } 																				
                                                        }
#line 1931 "y.tab.c"
    break;

  case 67: /* postfix_expression: '(' binary_operator primary_expression primary_expression ')'  */
#line 304 "parser.y"
                                                                        { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);  
                                                                        if((yyvsp[-2].token_node).node->data_type==(yyvsp[-1].token_node).node->data_type)
                                                                        {
                                                                            (yyval.token_node).node->data_type=(yyvsp[-2].token_node).node->data_type;
                                                                            //
                                                                            if((yyvsp[-2].token_node).node->isMatrix==1 || (yyvsp[-1].token_node).node->isMatrix==1)
                                                                            {
                                                                                if(check_matrix((yyval.token_node).node ,(yyvsp[-2].token_node).node , (yyvsp[-1].token_node).node)==1){printf("Error in matrix operations \n");}
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
#line 1951 "y.tab.c"
    break;

  case 68: /* postfix_expression: '(' binary_operator primary_expression postfix_expression ')'  */
#line 319 "parser.y"
                                                                        { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);  
                                                                        if((yyvsp[-2].token_node).node->data_type==(yyvsp[-1].token_node).node->data_type)
                                                                        {
                                                                            (yyval.token_node).node->data_type=(yyvsp[-2].token_node).node->data_type;
                                                                            if((yyvsp[-2].token_node).node->isMatrix==1 || (yyvsp[-1].token_node).node->isMatrix==1)
                                                                            {
                                                                                if(check_matrix((yyval.token_node).node ,(yyvsp[-2].token_node).node , (yyvsp[-1].token_node).node)==1){printf("Error in matrix operations \n");}
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
#line 1970 "y.tab.c"
    break;

  case 69: /* postfix_expression: '(' binary_operator postfix_expression primary_expression ')'  */
#line 333 "parser.y"
                                                                        { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);  
                                                                        if((yyvsp[-2].token_node).node->data_type==(yyvsp[-1].token_node).node->data_type)
                                                                        {
                                                                            (yyval.token_node).node->data_type=(yyvsp[-2].token_node).node->data_type;
                                                                            if((yyvsp[-2].token_node).node->isMatrix==1 || (yyvsp[-1].token_node).node->isMatrix==1)
                                                                            {
                                                                                if(check_matrix((yyval.token_node).node ,(yyvsp[-2].token_node).node , (yyvsp[-1].token_node).node)==1){printf("Error in matrix operations \n");}
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
#line 1989 "y.tab.c"
    break;

  case 70: /* postfix_expression: '(' binary_operator postfix_expression postfix_expression ')'  */
#line 347 "parser.y"
                                                                        { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);  
                                                                        if((yyvsp[-2].token_node).node->data_type==(yyvsp[-1].token_node).node->data_type)
                                                                        {
                                                                            (yyval.token_node).node->data_type=(yyvsp[-2].token_node).node->data_type;
                                                                            if((yyvsp[-2].token_node).node->isMatrix==1 || (yyvsp[-1].token_node).node->isMatrix==1)
                                                                            {
                                                                                if(check_matrix((yyval.token_node).node ,(yyvsp[-2].token_node).node , (yyvsp[-1].token_node).node)==1){printf("Error in matrix operations \n");}
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
#line 2008 "y.tab.c"
    break;

  case 71: /* logical_expression: primary_expression  */
#line 364 "parser.y"
                                                                                                { ptr = "prm_exp"; (yyval.token_node).node = build_node(ptr, (yyvsp[0].token_node).node, NULL); }
#line 2014 "y.tab.c"
    break;

  case 72: /* logical_expression: expression logical_operator expression  */
#line 365 "parser.y"
                                                                        { (yyval.token_node).node = build_node((yyvsp[-1].token_node).name_token, (yyvsp[-2].token_node).node, (yyvsp[0].token_node).node); }
#line 2020 "y.tab.c"
    break;

  case 73: /* binary_operator: '+'  */
#line 369 "parser.y"
                                                { ptr="+"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2026 "y.tab.c"
    break;

  case 74: /* binary_operator: '-'  */
#line 370 "parser.y"
                                                { ptr="-"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2032 "y.tab.c"
    break;

  case 75: /* binary_operator: '*'  */
#line 371 "parser.y"
                                                { ptr="*"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2038 "y.tab.c"
    break;

  case 76: /* binary_operator: '/'  */
#line 372 "parser.y"
                                                { ptr="/"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2044 "y.tab.c"
    break;

  case 77: /* binary_operator: '%'  */
#line 373 "parser.y"
                                                { ptr="%"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2050 "y.tab.c"
    break;

  case 78: /* binary_operator: '<'  */
#line 374 "parser.y"
                                                { ptr="<"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2056 "y.tab.c"
    break;

  case 79: /* binary_operator: '>'  */
#line 375 "parser.y"
                                                { ptr=">"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2062 "y.tab.c"
    break;

  case 80: /* binary_operator: '='  */
#line 376 "parser.y"
                                                { ptr="="; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2068 "y.tab.c"
    break;

  case 81: /* logical_operator: '<'  */
#line 380 "parser.y"
                                                { ptr="<"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2074 "y.tab.c"
    break;

  case 82: /* logical_operator: '>'  */
#line 381 "parser.y"
                                                { ptr=">"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2080 "y.tab.c"
    break;

  case 83: /* logical_operator: '='  */
#line 382 "parser.y"
                                                { ptr="="; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2086 "y.tab.c"
    break;

  case 84: /* type_specifier: CHAR  */
#line 386 "parser.y"
                            { ptr="char"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=char_t ; (yyval.token_node).node->data_type=char_t; }
#line 2092 "y.tab.c"
    break;

  case 85: /* type_specifier: INT  */
#line 387 "parser.y"
                                                { ptr="int"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=int_t ;  (yyval.token_node).node->data_type=int_t; }
#line 2098 "y.tab.c"
    break;

  case 86: /* type_specifier: DOUBLE  */
#line 388 "parser.y"
                                        { ptr="double"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=double_t; (yyval.token_node).node->data_type=double_t; }
#line 2104 "y.tab.c"
    break;

  case 87: /* type_specifier: BOOL  */
#line 389 "parser.y"
                                                { ptr="bool"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=bool_t ; (yyval.token_node).node->data_type=bool_t;}
#line 2110 "y.tab.c"
    break;

  case 88: /* type_specifier: STRUCT  */
#line 390 "parser.y"
                                        { ptr="struct"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2116 "y.tab.c"
    break;

  case 89: /* type_specifier: VOID  */
#line 391 "parser.y"
                                                { ptr="void"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=void_t;(yyval.token_node).node->data_type=void_t; }
#line 2122 "y.tab.c"
    break;

  case 90: /* primary_expression: CONSTANT_INT  */
#line 395 "parser.y"
                            { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); (yyval.token_node).node->data_type=int_t; }
#line 2128 "y.tab.c"
    break;

  case 91: /* primary_expression: CONSTANT_CHAR  */
#line 396 "parser.y"
                            { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); (yyval.token_node).node->data_type=char_t; }
#line 2134 "y.tab.c"
    break;

  case 92: /* primary_expression: CONSTANT_DOUBLE  */
#line 397 "parser.y"
                            { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); (yyval.token_node).node->data_type=double_t; }
#line 2140 "y.tab.c"
    break;

  case 93: /* primary_expression: TRUE  */
#line 398 "parser.y"
                            { ptr="true"; (yyval.token_node).node=build_node(ptr,NULL,NULL); (yyval.token_node).node->data_type=bool_t;  }
#line 2146 "y.tab.c"
    break;

  case 94: /* primary_expression: FALSE  */
#line 399 "parser.y"
                            { ptr="false"; (yyval.token_node).node=build_node(ptr,NULL,NULL); (yyval.token_node).node->data_type=bool_t; }
#line 2152 "y.tab.c"
    break;

  case 95: /* primary_expression: ID  */
#line 400 "parser.y"
                                                { (yyval.token_node).node=build_node((yyvsp[0].token_id).name_token,NULL,NULL); item=search_in_all_sym_tbl(current_symbol_table , (yyvsp[0].token_id).name_token);
                                if(item==NULL){printf("ERROR: %s is undeclared identifier at %d\n",(yyvsp[0].token_id).name_token,line_number);}
                                else
                                {
                                    (yyval.token_node).node->data_type=item->data_type;
                                    if(item->iden_type==matrix_t) // id is matrix 
                                    {
                                        //printf("Got item for %s \n",item->name);
                                        (yyval.token_node).node->isMatrix=1;
                                        matrix_info.row=item->id_info.matrix_info.row;
                                        matrix_info.column=item->id_info.matrix_info.column;
                                        (yyval.token_node).node->matrix_info=matrix_info;
                                    }
                                }	
                                							
                            }
#line 2173 "y.tab.c"
    break;

  case 96: /* primary_expression: STRING_LITERAL  */
#line 416 "parser.y"
                                { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); }
#line 2179 "y.tab.c"
    break;

  case 97: /* primary_expression: '(' ID '(' ')' ')'  */
#line 417 "parser.y"
                            { (yyval.token_node).node=build_node((yyvsp[-3].token_id).name_token,NULL,NULL);
                                item=search_in_all_sym_tbl(current_symbol_table , (yyvsp[-3].token_id).name_token);
                               if(item==NULL)
                               {	
                                    printf("ERROR: %s is undeclared identifier at %d\n",(yyvsp[-3].token_id).name_token,line_number);
                                       (yyval.token_node).node->data_type=void_t; 
                                } 
                               else
                               {
                                    (yyval.token_node).node->data_type=item->data_type;
                                }
                            }
#line 2196 "y.tab.c"
    break;

  case 98: /* primary_expression: '(' ID '(' id_list ')' ')'  */
#line 429 "parser.y"
                                { (yyval.token_node).node=build_node( (yyvsp[-4].token_id).name_token , (yyvsp[-4].token_id).node , (yyvsp[-2].token_node).node );
                                  item=search_in_all_sym_tbl(current_symbol_table , (yyvsp[-4].token_id).name_token);
                                if(item==NULL)
                                {
                                    printf("ERROR: %s is undeclared identifier at %d\n",(yyvsp[-4].token_id).name_token,line_number);
                                      (yyval.token_node).node->data_type=void_t;
                                } 
                                else{ 
                                    check_function_parameters(item->id_info.function_info.parameters,(yyvsp[-2].token_node).node);
                                    (yyval.token_node).node->data_type=item->data_type; }    
                                }
#line 2212 "y.tab.c"
    break;

  case 99: /* id_list: primary_expression  */
#line 445 "parser.y"
                                                                { (yyval.token_node).node=(yyvsp[0].token_node).node; }
#line 2218 "y.tab.c"
    break;

  case 100: /* id_list: postfix_expression  */
#line 446 "parser.y"
                                                                { (yyval.token_node).node=(yyvsp[0].token_node).node; }
#line 2224 "y.tab.c"
    break;

  case 101: /* id_list: id_list ',' primary_expression  */
#line 447 "parser.y"
                                                { ptr="id_list" ; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 2230 "y.tab.c"
    break;

  case 102: /* id_list: id_list ',' postfix_expression  */
#line 448 "parser.y"
                                                { ptr="id_list" ; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 2236 "y.tab.c"
    break;


#line 2240 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 452 "parser.y"




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
        //print_ast(root);
        
        
        printf("\nSymbol Table \n");
        print_symbol_table(table_top());

        //check_function_return(root->left->left);
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
