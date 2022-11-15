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

#line 231 "y.tab.c"

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
  YYSYMBOL_38_ = 38,                       /* '+'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_42_ = 42,                       /* '%'  */
  YYSYMBOL_43_ = 43,                       /* '<'  */
  YYSYMBOL_44_ = 44,                       /* '>'  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_translation_main = 47,          /* translation_main  */
  YYSYMBOL_translation = 48,               /* translation  */
  YYSYMBOL_translation_init = 49,          /* translation_init  */
  YYSYMBOL_translation_unit = 50,          /* translation_unit  */
  YYSYMBOL_external_declaration = 51,      /* external_declaration  */
  YYSYMBOL_function_definition = 52,       /* function_definition  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_function_body = 54,             /* function_body  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_body = 56,                      /* body  */
  YYSYMBOL_compound_statement = 57,        /* compound_statement  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_compound_statement_content = 59, /* compound_statement_content  */
  YYSYMBOL_statement = 60,                 /* statement  */
  YYSYMBOL_selection_statement = 61,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 62,       /* iteration_statement  */
  YYSYMBOL_tex_statement = 63,             /* tex_statement  */
  YYSYMBOL_tex_data = 64,                  /* tex_data  */
  YYSYMBOL_tex_function = 65,              /* tex_function  */
  YYSYMBOL_jump_statement = 66,            /* jump_statement  */
  YYSYMBOL_declaration = 67,               /* declaration  */
  YYSYMBOL_expression_statement = 68,      /* expression_statement  */
  YYSYMBOL_expression = 69,                /* expression  */
  YYSYMBOL_assignment_expression = 70,     /* assignment_expression  */
  YYSYMBOL_init_declarator = 71,           /* init_declarator  */
  YYSYMBOL_declarator = 72,                /* declarator  */
  YYSYMBOL_73_4 = 73,                      /* $@4  */
  YYSYMBOL_parameter_list = 74,            /* parameter_list  */
  YYSYMBOL_postfix_expression = 75,        /* postfix_expression  */
  YYSYMBOL_logical_expression = 76,        /* logical_expression  */
  YYSYMBOL_binary_operator = 77,           /* binary_operator  */
  YYSYMBOL_logical_operator = 78,          /* logical_operator  */
  YYSYMBOL_type_specifier = 79,            /* type_specifier  */
  YYSYMBOL_primary_expression = 80,        /* primary_expression  */
  YYSYMBOL_id_list = 81                    /* id_list  */
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

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
       2,     2,     2,     2,     2,     2,     2,    42,     2,     2,
      33,    34,    40,    38,    36,    39,     2,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    35,
      43,    45,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,    73,    73,    77,    78,    82,    86,    87,    91,    92,
      96,    96,   100,   100,   114,   115,   120,   120,   125,   126,
     127,   128,   132,   133,   134,   135,   136,   138,   142,   143,
     148,   153,   162,   166,   167,   168,   169,   173,   177,   178,
     179,   180,   184,   188,   189,   194,   195,   196,   200,   201,
     206,   207,   208,   212,   216,   223,   223,   245,   253,   266,
     276,   286,   296,   309,   310,   314,   315,   316,   317,   318,
     319,   320,   321,   325,   326,   327,   331,   332,   333,   334,
     335,   336,   340,   341,   342,   343,   344,   345,   349,   350,
     362,   378,   379,   380,   381
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
  "'+'", "'-'", "'*'", "'/'", "'%'", "'<'", "'>'", "'='", "$accept",
  "translation_main", "translation", "translation_init",
  "translation_unit", "external_declaration", "function_definition", "$@1",
  "function_body", "$@2", "body", "compound_statement", "$@3",
  "compound_statement_content", "statement", "selection_statement",
  "iteration_statement", "tex_statement", "tex_data", "tex_function",
  "jump_statement", "declaration", "expression_statement", "expression",
  "assignment_expression", "init_declarator", "declarator", "$@4",
  "parameter_list", "postfix_expression", "logical_expression",
  "binary_operator", "logical_operator", "type_specifier",
  "primary_expression", "id_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,   -12,    18,    10,    12,    40,  -135,   -12,   298,  -135,
      41,   313,  -135,  -135,  -135,  -135,  -135,  -135,    69,  -135,
    -135,  -135,  -135,  -135,    17,   298,  -135,    17,    37,    16,
      39,   298,  -135,    46,    44,  -135,   253,  -135,  -135,   313,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,   284,  -135,  -135,
     131,   -19,    65,    60,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,   253,   211,    59,    61,    73,    76,    67,    78,
    -135,  -135,    81,  -135,   164,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,    75,  -135,  -135,  -135,  -135,   313,  -135,    -3,
     253,   253,    84,  -135,    82,  -135,  -135,   267,   225,    13,
     253,   197,  -135,   211,  -135,  -135,  -135,    92,    85,  -135,
    -135,     4,    87,    91,    93,    94,   100,     3,   105,    15,
     267,   281,  -135,   -20,  -135,  -135,  -135,   239,    98,  -135,
    -135,  -135,   108,   253,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,   267,    95,   111,   117,   136,  -135,    23,  -135,   114,
    -135,  -135,  -135,  -135,  -135,   142,    49,  -135,  -135,  -135,
    -135,    95,    95,   118,  -135,  -135,    95,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     1,     0,     0,     4,
       0,     0,    79,    76,    77,    78,    81,    80,     0,     6,
       9,     8,    10,     3,     0,     0,     7,     0,    53,     0,
      50,     5,    11,     0,    55,    42,     0,    12,    54,     0,
      82,    83,    84,    88,    85,    86,    87,     0,    52,    51,
       0,     0,     0,     0,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,    87,
      16,    43,     0,    22,     0,    19,    24,    25,    26,    27,
      18,    23,     0,    45,    47,    46,    56,     0,    57,     0,
       0,     0,    40,    15,     0,    38,    39,     0,     0,     0,
       0,     0,    13,     0,    21,    20,    44,     0,     0,    92,
      91,     0,     0,     0,     0,     0,    41,     0,     0,    46,
       0,     0,    33,     0,    34,    49,    48,     0,     0,    14,
      58,    89,     0,     0,    62,    61,    60,    59,    73,    74,
      75,     0,     0,     0,     0,     0,    32,     0,    40,     0,
      17,    90,    94,    93,    64,    28,     0,    37,    35,    36,
      41,     0,     0,     0,    29,    30,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,   144,   129,   -11,  -135,  -135,  -135,  -135,
    -135,  -134,  -135,    57,   -68,  -135,  -135,  -135,  -135,    14,
    -135,   -49,   -59,   -61,  -135,  -135,   132,  -135,  -135,   -33,
      43,  -135,  -135,    -6,   -36,  -135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,    18,    19,    20,    27,    32,    50,
      72,    73,   101,    74,    75,    76,    77,    78,   123,   124,
      79,    21,    81,    82,    83,    29,    30,    39,    51,    84,
     118,    62,   141,    22,    85,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    80,    94,    48,    93,    24,   104,    26,   155,     1,
      40,    41,   146,    42,     4,    86,   147,    87,     6,    43,
      26,    44,    45,    46,   121,   105,    91,   164,   165,    90,
      47,   108,   167,    52,   121,   122,   117,     7,   132,   120,
     133,     8,    94,    28,   129,   158,   138,   139,   140,   -63,
     -63,    35,    80,   110,   113,   115,   109,   112,   114,   117,
     104,   119,    40,    41,   126,    42,   149,   125,     9,    23,
      34,    43,    11,    44,    45,    69,    36,    37,    38,   105,
     154,   107,    47,   162,   119,   145,    12,    13,    14,    15,
      16,    88,    17,    89,    95,   163,    96,   153,    99,    25,
     152,    11,   127,    64,    65,    66,    97,    67,    68,    98,
     106,    40,    41,   102,    42,   100,   -43,   116,   130,   131,
      43,   134,    44,    45,    69,   135,    70,   136,   137,    70,
     150,    47,   -44,    71,    11,    63,    64,    65,    66,   142,
      67,    68,   151,    53,    40,    41,   156,    42,   157,   160,
     161,    10,   166,    43,    31,    44,    45,    69,   128,    33,
       0,   159,    70,   143,    47,     0,    71,    11,   103,    64,
      65,    66,     0,    67,    68,     0,     0,    40,    41,     0,
      42,     0,     0,     0,     0,     0,    43,     0,    44,    45,
      69,     0,     0,     0,     0,    70,     0,    47,     0,    71,
      11,   127,    64,    65,    66,     0,    67,    68,     0,     0,
      40,    41,     0,    42,     0,     0,     0,     0,     0,    43,
       0,    44,    45,    69,    40,    41,     0,    42,    70,     0,
      47,     0,    71,    43,     0,    44,    45,    69,    40,    41,
       0,    42,     0,     0,    47,     0,    92,    43,     0,    44,
      45,    69,    40,    41,     0,    42,     0,     0,    47,     0,
      71,    43,     0,    44,    45,    69,    40,    41,     0,    42,
       0,     0,    47,     0,   148,    43,     0,    44,    45,    46,
      40,    41,     0,    42,     0,     0,    47,     0,     0,    43,
       0,    44,    45,    69,    40,    41,     0,    42,     0,     0,
      47,    11,     0,    43,     0,    44,    45,    46,     0,     0,
      53,     0,     0,     0,   144,    12,    13,    14,    15,    16,
       0,    17,    54,    55,    56,    57,    58,    59,    60,    61,
      12,    13,    14,    15,    16,     0,    17
};

static const yytype_int16 yycheck[] =
{
      36,    50,    63,    36,    63,    11,    74,    18,   142,    27,
      13,    14,    32,    16,    26,    34,    36,    36,     0,    22,
      31,    24,    25,    26,    11,    74,    62,   161,   162,    62,
      33,    34,   166,    39,    11,    22,    97,    27,    34,    98,
      36,    29,   103,    26,   103,    22,    43,    44,    45,    34,
      35,    35,   101,    89,    90,    91,    89,    90,    91,   120,
     128,    97,    13,    14,   100,    16,   127,   100,    28,    28,
      33,    22,     3,    24,    25,    26,    37,    31,    34,   128,
     141,    87,    33,    34,   120,   121,    17,    18,    19,    20,
      21,    26,    23,    33,    35,   156,    35,   133,    31,    30,
     133,     3,     4,     5,     6,     7,    33,     9,    10,    33,
      35,    13,    14,    32,    16,    37,    32,    35,    26,    34,
      22,    34,    24,    25,    26,    34,    31,    34,    34,    31,
      32,    33,    32,    35,     3,     4,     5,     6,     7,    34,
       9,    10,    34,    26,    13,    14,    35,    16,    12,    35,
       8,     7,    34,    22,    25,    24,    25,    26,   101,    27,
      -1,   147,    31,   120,    33,    -1,    35,     3,     4,     5,
       6,     7,    -1,     9,    10,    -1,    -1,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,    35,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    -1,
      13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    24,    25,    26,    13,    14,    -1,    16,    31,    -1,
      33,    -1,    35,    22,    -1,    24,    25,    26,    13,    14,
      -1,    16,    -1,    -1,    33,    -1,    35,    22,    -1,    24,
      25,    26,    13,    14,    -1,    16,    -1,    -1,    33,    -1,
      35,    22,    -1,    24,    25,    26,    13,    14,    -1,    16,
      -1,    -1,    33,    -1,    35,    22,    -1,    24,    25,    26,
      13,    14,    -1,    16,    -1,    -1,    33,    -1,    -1,    22,
      -1,    24,    25,    26,    13,    14,    -1,    16,    -1,    -1,
      33,     3,    -1,    22,    -1,    24,    25,    26,    -1,    -1,
      26,    -1,    -1,    -1,    33,    17,    18,    19,    20,    21,
      -1,    23,    38,    39,    40,    41,    42,    43,    44,    45,
      17,    18,    19,    20,    21,    -1,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    47,    48,    26,    49,     0,    27,    29,    28,
      49,     3,    17,    18,    19,    20,    21,    23,    50,    51,
      52,    67,    79,    28,    79,    30,    51,    53,    26,    71,
      72,    50,    54,    72,    33,    35,    37,    31,    34,    73,
      13,    14,    16,    22,    24,    25,    26,    33,    75,    80,
      55,    74,    79,    26,    38,    39,    40,    41,    42,    43,
      44,    45,    77,     4,     5,     6,     7,     9,    10,    26,
      31,    35,    56,    57,    59,    60,    61,    62,    63,    66,
      67,    68,    69,    70,    75,    80,    34,    36,    26,    33,
      75,    80,    35,    68,    69,    35,    35,    33,    33,    31,
      37,    58,    32,     4,    60,    67,    35,    79,    34,    75,
      80,    81,    75,    80,    75,    80,    35,    69,    76,    80,
      68,    11,    22,    64,    65,    75,    80,     4,    59,    68,
      26,    34,    34,    36,    34,    34,    34,    34,    43,    44,
      45,    78,    34,    76,    33,    80,    32,    36,    35,    69,
      32,    34,    75,    80,    69,    57,    35,    12,    22,    65,
      35,     8,    34,    69,    57,    57,    34,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    50,    50,    51,    51,
      53,    52,    55,    54,    56,    56,    58,    57,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    64,    64,    64,    64,    65,    66,    66,
      66,    66,    67,    68,    68,    69,    69,    69,    70,    70,
      71,    71,    71,    72,    72,    73,    72,    74,    74,    75,
      75,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    78,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     4,     3,     5,     1,     2,     1,     1,
       0,     3,     0,     5,     3,     2,     0,     4,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     5,     7,
       7,     8,     4,     1,     1,     3,     3,     3,     2,     2,
       2,     3,     4,     1,     2,     1,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     0,     5,     2,     4,     5,
       5,     5,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       6,     1,     1,     3,     3
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
#line 73 "parser.y"
                                                        { ptr = "Main"; (yyval.token_node).node = build_node(ptr,(yyvsp[0].token_node).node,NULL); root = (yyval.token_node).node; }
#line 1442 "y.tab.c"
    break;

  case 3: /* translation: translation SF_OPEN translation_init SF_CLOSE  */
#line 77 "parser.y"
                                                            { ptr = "sub_file"; (yyval.token_node).node = build_node(ptr,(yyvsp[-3].token_node).node,(yyvsp[-1].token_node).node); }
#line 1448 "y.tab.c"
    break;

  case 4: /* translation: SF_OPEN translation_init SF_CLOSE  */
#line 78 "parser.y"
                                                            { ptr = "sub_file"; (yyval.token_node).node = build_node(ptr,(yyvsp[-1].token_node).node,NULL); }
#line 1454 "y.tab.c"
    break;

  case 5: /* translation_init: ID MS_OPEN translation_unit MS_CLOSE translation_unit  */
#line 82 "parser.y"
                                                                { ptr = "trans_init"; (yyval.token_node).node = build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 1460 "y.tab.c"
    break;

  case 6: /* translation_unit: external_declaration  */
#line 86 "parser.y"
                                                    { ptr = "trans_unit"; (yyval.token_node).node = (yyvsp[0].token_node).node; }
#line 1466 "y.tab.c"
    break;

  case 7: /* translation_unit: translation_unit external_declaration  */
#line 87 "parser.y"
                                                        { ptr = "trans_unit"; (yyval.token_node).node = build_node(ptr,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node); }
#line 1472 "y.tab.c"
    break;

  case 8: /* external_declaration: declaration  */
#line 91 "parser.y"
                                                                                        { ptr="external_declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1478 "y.tab.c"
    break;

  case 9: /* external_declaration: function_definition  */
#line 92 "parser.y"
                                                                        { ptr="fun_declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); check_function_return((yyval.token_node).node); }
#line 1484 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 96 "parser.y"
                     { }
#line 1490 "y.tab.c"
    break;

  case 11: /* function_definition: type_specifier $@1 function_body  */
#line 96 "parser.y"
                                                                { ptr="fun_def"; (yyval.token_node).node=build_node((yyvsp[0].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 1496 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 100 "parser.y"
                     {}
#line 1502 "y.tab.c"
    break;

  case 13: /* function_body: declarator '{' $@2 body '}'  */
#line 100 "parser.y"
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
#line 1518 "y.tab.c"
    break;

  case 14: /* body: compound_statement_content RETURN expression_statement  */
#line 114 "parser.y"
                                                               { ptr="body"; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 1524 "y.tab.c"
    break;

  case 15: /* body: RETURN expression_statement  */
#line 115 "parser.y"
                                                                                           { ptr="body"; (yyval.token_node).node=build_node(ptr,NULL,(yyvsp[0].token_node).node); }
#line 1530 "y.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 120 "parser.y"
          {table_push(current_symbol_table); current_symbol_table=init_child_symbol_table(current_symbol_table); }
#line 1536 "y.tab.c"
    break;

  case 17: /* compound_statement: '{' $@3 compound_statement_content '}'  */
#line 121 "parser.y"
                                            {table_push(temp_symbol_table);	 ptr="cmp_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,NULL); }
#line 1542 "y.tab.c"
    break;

  case 18: /* compound_statement_content: declaration  */
#line 125 "parser.y"
                                                                                        { ptr="declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1548 "y.tab.c"
    break;

  case 19: /* compound_statement_content: statement  */
#line 126 "parser.y"
                                                                                        { ptr="stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1554 "y.tab.c"
    break;

  case 20: /* compound_statement_content: compound_statement_content declaration  */
#line 127 "parser.y"
                                                        { ptr="cmp_stmt_content"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node); }
#line 1560 "y.tab.c"
    break;

  case 21: /* compound_statement_content: compound_statement_content statement  */
#line 128 "parser.y"
                                                        { ptr="cmp_stmt_content"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node); }
#line 1566 "y.tab.c"
    break;

  case 22: /* statement: compound_statement  */
#line 132 "parser.y"
                                                                                { ptr="comp_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1572 "y.tab.c"
    break;

  case 23: /* statement: expression_statement  */
#line 133 "parser.y"
                                                                                { ptr="expr_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1578 "y.tab.c"
    break;

  case 24: /* statement: selection_statement  */
#line 134 "parser.y"
                                                                                { ptr="sel_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1584 "y.tab.c"
    break;

  case 25: /* statement: iteration_statement  */
#line 135 "parser.y"
                                                                                { ptr="itr_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1590 "y.tab.c"
    break;

  case 26: /* statement: tex_statement  */
#line 136 "parser.y"
                                                                                        { ptr="tex_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); 
                                                    single_tex_function++; if(single_tex_function==2){ printf("\n More than one TeX Function \n") ; }  }
#line 1597 "y.tab.c"
    break;

  case 27: /* statement: jump_statement  */
#line 138 "parser.y"
                                                                                { printf("dfghj\n"); ptr = "jump_stmt"; (yyval.token_node).node = build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1603 "y.tab.c"
    break;

  case 28: /* selection_statement: IF '(' logical_expression ')' compound_statement  */
#line 142 "parser.y"
                                                                                                                        { ptr = "if_"; (yyval.token_node).node = build_node(ptr, (yyvsp[-2].token_node).node, (yyvsp[0].token_node).node); }
#line 1609 "y.tab.c"
    break;

  case 29: /* selection_statement: IF '(' logical_expression ')' compound_statement ELSE compound_statement  */
#line 143 "parser.y"
                                                                                                { ptr = "if_"; ast_node* _if = build_node(ptr, (yyvsp[-4].token_node).node, (yyvsp[-2].token_node).node); 
                                                                                          ptr = "if_else"; (yyval.token_node).node = build_node(ptr, _if, (yyvsp[0].token_node).node); }
#line 1616 "y.tab.c"
    break;

  case 30: /* iteration_statement: LOOP '(' expression_statement logical_expression ';' ')' compound_statement  */
#line 149 "parser.y"
            {
                ptr = "lp_cdn"; ast_node* lp_cdn = build_node(ptr, (yyvsp[-3].token_node).node, (yyvsp[0].token_node).node);
                ptr = "loop"; (yyval.token_node).node = build_node(ptr, (yyvsp[-4].token_node).node, lp_cdn);
            }
#line 1625 "y.tab.c"
    break;

  case 31: /* iteration_statement: LOOP '(' expression_statement logical_expression ';' expression ')' compound_statement  */
#line 154 "parser.y"
            {
                ptr = "lp_cdn"; ast_node* lp_cdn = build_node(ptr, (yyvsp[-4].token_node).node, (yyvsp[0].token_node).node);
                ptr = "lp_itr"; ast_node* lp_itr = build_node(ptr, (yyvsp[-2].token_node).node, lp_cdn);
                ptr = "loop"; (yyval.token_node).node = build_node(ptr, (yyvsp[-5].token_node).node, lp_itr);
            }
#line 1635 "y.tab.c"
    break;

  case 32: /* tex_statement: TEX '{' tex_data '}'  */
#line 162 "parser.y"
                                                                        { ptr = "tex"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1641 "y.tab.c"
    break;

  case 33: /* tex_data: STRING_LITERAL  */
#line 166 "parser.y"
                                                                                { ptr = "tex_str"; (yyval.token_node).node = build_node(ptr, (yyvsp[0].token_node).node, NULL); }
#line 1647 "y.tab.c"
    break;

  case 34: /* tex_data: tex_function  */
#line 167 "parser.y"
                                                                                        { ptr = "tex_fun"; (yyval.token_node).node = build_node(ptr, NULL, (yyvsp[0].token_node).node); }
#line 1653 "y.tab.c"
    break;

  case 35: /* tex_data: tex_data ',' STRING_LITERAL  */
#line 168 "parser.y"
                                                                        { ptr = "tex_data"; (yyval.token_node).node = build_node(ptr, (yyvsp[0].token_node).node, (yyvsp[-2].token_node).node); }
#line 1659 "y.tab.c"
    break;

  case 36: /* tex_data: tex_data ',' tex_function  */
#line 169 "parser.y"
                                                                        { ptr = "tex_data"; (yyval.token_node).node = build_node(ptr, (yyvsp[-2].token_node).node, (yyvsp[0].token_node).node); }
#line 1665 "y.tab.c"
    break;

  case 37: /* tex_function: TEX_OPEN primary_expression TEX_CLOSE  */
#line 173 "parser.y"
                                                                { (yyval.token_node).node = (yyvsp[-1].token_node).node; }
#line 1671 "y.tab.c"
    break;

  case 38: /* jump_statement: CONTINUE ';'  */
#line 177 "parser.y"
                                                                                        { ptr = "j_cnt"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1677 "y.tab.c"
    break;

  case 39: /* jump_statement: BREAK ';'  */
#line 178 "parser.y"
                                                                                        { ptr = "j_brk"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1683 "y.tab.c"
    break;

  case 40: /* jump_statement: RETURN ';'  */
#line 179 "parser.y"
                                                                                        { ptr = "j_rtn"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1689 "y.tab.c"
    break;

  case 41: /* jump_statement: RETURN expression ';'  */
#line 180 "parser.y"
                                                                                { ptr = "ret_exp"; (yyval.token_node).node = build_node(ptr, (yyvsp[-1].token_node).node, NULL); }
#line 1695 "y.tab.c"
    break;

  case 42: /* declaration: DECLARE type_specifier init_declarator ';'  */
#line 184 "parser.y"
                                                        { ptr="declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node); }
#line 1701 "y.tab.c"
    break;

  case 43: /* expression_statement: ';'  */
#line 188 "parser.y"
                                                                                                { ptr=";"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1707 "y.tab.c"
    break;

  case 44: /* expression_statement: expression ';'  */
#line 189 "parser.y"
                                                                { ptr="expr"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,NULL); }
#line 1713 "y.tab.c"
    break;

  case 45: /* expression: assignment_expression  */
#line 194 "parser.y"
                                                                                { ptr="assign_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1719 "y.tab.c"
    break;

  case 46: /* expression: primary_expression  */
#line 195 "parser.y"
                                                                                { ptr="prm_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); (yyval.token_node).node->data_type=(yyvsp[0].token_node).node->data_type; }
#line 1725 "y.tab.c"
    break;

  case 47: /* expression: postfix_expression  */
#line 196 "parser.y"
                                                                                { ptr="post_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1731 "y.tab.c"
    break;

  case 48: /* assignment_expression: ID ':' primary_expression  */
#line 200 "parser.y"
                                                                        { ptr="assignment";(yyval.token_node).node=build_node((yyvsp[-2].token_id).name_token,(yyvsp[-2].token_id).node,(yyvsp[0].token_node).node); check_assignment(current_symbol_table , (yyval.token_node).node); }
#line 1737 "y.tab.c"
    break;

  case 49: /* assignment_expression: ID ':' postfix_expression  */
#line 201 "parser.y"
                                                                        { ptr="assignment";(yyval.token_node).node=build_node((yyvsp[-2].token_id).name_token,(yyvsp[-2].token_id).node,(yyvsp[0].token_node).node); check_assignment(current_symbol_table , (yyval.token_node).node); }
#line 1743 "y.tab.c"
    break;

  case 50: /* init_declarator: declarator  */
#line 206 "parser.y"
                                                                                        { ptr="init_declarator";(yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1749 "y.tab.c"
    break;

  case 51: /* init_declarator: declarator ':' primary_expression  */
#line 207 "parser.y"
                                                                { ptr="init_declarator";(yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 1755 "y.tab.c"
    break;

  case 52: /* init_declarator: declarator ':' postfix_expression  */
#line 208 "parser.y"
                                                                { ptr="init_declarator";(yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 1761 "y.tab.c"
    break;

  case 53: /* declarator: ID  */
#line 212 "parser.y"
                                                                                                { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[0].token_id).name_token , variable_t , data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}
                                                       (yyvsp[0].token_id).data_type=get_type(data_type);	(yyval.token_node).node=build_node((yyvsp[0].token_id).name_token,(yyvsp[0].token_id).node,NULL);	(yyval.token_node).node->data_type=data_type; 
                                                    }
#line 1770 "y.tab.c"
    break;

  case 54: /* declarator: ID '(' ')'  */
#line 216 "parser.y"
                                                                                        { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[-2].token_id).name_token , function_t,data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);} 
                                                      current_symbol_table=init_child_symbol_table(current_symbol_table); 
                                                      table_push(current_symbol_table);																			
                                                      item=search_in_all_sym_tbl(current_symbol_table , (yyvsp[-2].token_id).name_token);
                                                      (yyvsp[-2].token_id).data_type=get_type(data_type);	(yyval.token_node).node=build_node((yyvsp[-2].token_id).name_token,(yyvsp[-2].token_id).node,NULL);	(yyval.token_node).node->data_type=data_type; 
                                                    }
#line 1782 "y.tab.c"
    break;

  case 55: /* $@4: %empty  */
#line 223 "parser.y"
                                                                        { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[-1].token_id).name_token , function_t , data_type)==false)
                                                            {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}
                                                      current_symbol_table=init_child_symbol_table(current_symbol_table); ptr="LOCAL"; current_symbol_table->name=(char*)malloc(sizeof(char)*10);
                                                      strcpy(current_symbol_table->name,ptr); table_push(current_symbol_table); 
                                                      parameter_list=(param*)malloc(sizeof(param));
                                                      params=(param*)malloc(sizeof(param));
                                                      parameter_list=params; 
                                                    }
#line 1795 "y.tab.c"
    break;

  case 56: /* declarator: ID '(' $@4 parameter_list ')'  */
#line 231 "parser.y"
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
#line 1810 "y.tab.c"
    break;

  case 57: /* parameter_list: type_specifier ID  */
#line 245 "parser.y"
                                                        { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[0].token_id).name_token , function_param , data_type)==false)
                                                                                {printf("ERROR: Redeclaration of variable at line %d\n",line_number);} 
                                                                                else {
                                                                                    no_of_parameters++;    
                                                                                    (yyval.token_node).node=build_node((yyvsp[0].token_id).name_token,NULL,NULL); 
                                                                                    (yyval.token_node).node->data_type=data_type; 	
                                                                                    link_p((yyvsp[0].token_id).name_token,data_type); } 																				
                                                        }
#line 1823 "y.tab.c"
    break;

  case 58: /* parameter_list: parameter_list ',' type_specifier ID  */
#line 253 "parser.y"
                                                                        { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[0].token_id).name_token , function_param , data_type)==false)
                                                                                {printf("ERROR: Redeclaration of variable at line %d\n",line_number);}  
                                                                                else {
                                                                                    (yyvsp[0].token_id).node=build_node((yyvsp[0].token_id).name_token,NULL,NULL);
                                                                                    (yyvsp[0].token_id).node->data_type=data_type;  
                                                                                    no_of_parameters++;
                                                                                    ptr="param_list";  (yyval.token_node).node=build_node(ptr,(yyvsp[-3].token_node).node,(yyvsp[0].token_id).node ); 																				 
                                                                                    link_p((yyvsp[-1].token_node).name_token,data_type);   } 																				
                                                        }
#line 1837 "y.tab.c"
    break;

  case 59: /* postfix_expression: '(' binary_operator primary_expression primary_expression ')'  */
#line 266 "parser.y"
                                                                        { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);  
                                                                        if((yyvsp[-2].token_node).node->data_type==(yyvsp[-1].token_node).node->data_type)
                                                                        {
                                                                            (yyval.token_node).node->data_type=(yyvsp[-2].token_node).node->data_type;
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
#line 1852 "y.tab.c"
    break;

  case 60: /* postfix_expression: '(' binary_operator primary_expression postfix_expression ')'  */
#line 276 "parser.y"
                                                                        { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);  
                                                                        if((yyvsp[-2].token_node).node->data_type==(yyvsp[-1].token_node).node->data_type)
                                                                        {
                                                                            (yyval.token_node).node->data_type=(yyvsp[-2].token_node).node->data_type;
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
#line 1867 "y.tab.c"
    break;

  case 61: /* postfix_expression: '(' binary_operator postfix_expression primary_expression ')'  */
#line 286 "parser.y"
                                                                        { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);  
                                                                        if((yyvsp[-2].token_node).node->data_type==(yyvsp[-1].token_node).node->data_type)
                                                                        {
                                                                            (yyval.token_node).node->data_type=(yyvsp[-2].token_node).node->data_type;
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
#line 1882 "y.tab.c"
    break;

  case 62: /* postfix_expression: '(' binary_operator postfix_expression postfix_expression ')'  */
#line 296 "parser.y"
                                                                        { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);  
                                                                        if((yyvsp[-2].token_node).node->data_type==(yyvsp[-1].token_node).node->data_type)
                                                                        {
                                                                            (yyval.token_node).node->data_type=(yyvsp[-2].token_node).node->data_type;
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("ERROR: Operation on incompatible data types at line %d\n",line_number);
                                                                        }
                                                                         }
#line 1897 "y.tab.c"
    break;

  case 63: /* logical_expression: primary_expression  */
#line 309 "parser.y"
                                                                                                { ptr = "prm_exp"; (yyval.token_node).node = build_node(ptr, (yyvsp[0].token_node).node, NULL); }
#line 1903 "y.tab.c"
    break;

  case 64: /* logical_expression: expression logical_operator expression  */
#line 310 "parser.y"
                                                                        { (yyval.token_node).node = build_node((yyvsp[-1].token_node).name_token, (yyvsp[-2].token_node).node, (yyvsp[0].token_node).node); }
#line 1909 "y.tab.c"
    break;

  case 65: /* binary_operator: '+'  */
#line 314 "parser.y"
                                                { ptr="+"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1915 "y.tab.c"
    break;

  case 66: /* binary_operator: '-'  */
#line 315 "parser.y"
                                                { ptr="-"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1921 "y.tab.c"
    break;

  case 67: /* binary_operator: '*'  */
#line 316 "parser.y"
                                                { ptr="*"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1927 "y.tab.c"
    break;

  case 68: /* binary_operator: '/'  */
#line 317 "parser.y"
                                                { ptr="/"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1933 "y.tab.c"
    break;

  case 69: /* binary_operator: '%'  */
#line 318 "parser.y"
                                                { ptr="%"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1939 "y.tab.c"
    break;

  case 70: /* binary_operator: '<'  */
#line 319 "parser.y"
                                                { ptr="<"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1945 "y.tab.c"
    break;

  case 71: /* binary_operator: '>'  */
#line 320 "parser.y"
                                                { ptr=">"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1951 "y.tab.c"
    break;

  case 72: /* binary_operator: '='  */
#line 321 "parser.y"
                                                { ptr="="; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1957 "y.tab.c"
    break;

  case 73: /* logical_operator: '<'  */
#line 325 "parser.y"
                                                { ptr="<"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1963 "y.tab.c"
    break;

  case 74: /* logical_operator: '>'  */
#line 326 "parser.y"
                                                { ptr=">"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1969 "y.tab.c"
    break;

  case 75: /* logical_operator: '='  */
#line 327 "parser.y"
                                                { ptr="="; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1975 "y.tab.c"
    break;

  case 76: /* type_specifier: CHAR  */
#line 331 "parser.y"
                            { ptr="char"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=char_t ; (yyval.token_node).node->data_type=char_t; }
#line 1981 "y.tab.c"
    break;

  case 77: /* type_specifier: INT  */
#line 332 "parser.y"
                                                { ptr="int"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=int_t ;  (yyval.token_node).node->data_type=int_t; }
#line 1987 "y.tab.c"
    break;

  case 78: /* type_specifier: DOUBLE  */
#line 333 "parser.y"
                                        { ptr="double"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=double_t; (yyval.token_node).node->data_type=double_t; }
#line 1993 "y.tab.c"
    break;

  case 79: /* type_specifier: BOOL  */
#line 334 "parser.y"
                                                { ptr="bool"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=bool_t ; (yyval.token_node).node->data_type=bool_t;}
#line 1999 "y.tab.c"
    break;

  case 80: /* type_specifier: STRUCT  */
#line 335 "parser.y"
                                        { ptr="struct"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 2005 "y.tab.c"
    break;

  case 81: /* type_specifier: VOID  */
#line 336 "parser.y"
                                                { ptr="void"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=void_t;(yyval.token_node).node->data_type=void_t; }
#line 2011 "y.tab.c"
    break;

  case 82: /* primary_expression: CONSTANT_INT  */
#line 340 "parser.y"
                            { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); (yyval.token_node).node->data_type=int_t; }
#line 2017 "y.tab.c"
    break;

  case 83: /* primary_expression: CONSTANT_CHAR  */
#line 341 "parser.y"
                            { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); (yyval.token_node).node->data_type=char_t; }
#line 2023 "y.tab.c"
    break;

  case 84: /* primary_expression: CONSTANT_DOUBLE  */
#line 342 "parser.y"
                            { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); (yyval.token_node).node->data_type=double_t; }
#line 2029 "y.tab.c"
    break;

  case 85: /* primary_expression: TRUE  */
#line 343 "parser.y"
                            { ptr="true"; (yyval.token_node).node=build_node(ptr,NULL,NULL); (yyval.token_node).node->data_type=bool_t;  }
#line 2035 "y.tab.c"
    break;

  case 86: /* primary_expression: FALSE  */
#line 344 "parser.y"
                            { ptr="false"; (yyval.token_node).node=build_node(ptr,NULL,NULL); (yyval.token_node).node->data_type=bool_t; }
#line 2041 "y.tab.c"
    break;

  case 87: /* primary_expression: ID  */
#line 345 "parser.y"
                                                { (yyval.token_node).node=build_node((yyvsp[0].token_id).name_token,NULL,NULL); item=search_in_all_sym_tbl(current_symbol_table , (yyvsp[0].token_id).name_token);
                                if(item==NULL){printf("ERROR: %s is undeclared identifier at %d\n",(yyvsp[0].token_id).name_token,line_number);}
                                else{(yyval.token_node).node->data_type=item->data_type;}								
                            }
#line 2050 "y.tab.c"
    break;

  case 88: /* primary_expression: STRING_LITERAL  */
#line 349 "parser.y"
                                { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); }
#line 2056 "y.tab.c"
    break;

  case 89: /* primary_expression: '(' ID '(' ')' ')'  */
#line 350 "parser.y"
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
#line 2073 "y.tab.c"
    break;

  case 90: /* primary_expression: '(' ID '(' id_list ')' ')'  */
#line 362 "parser.y"
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
#line 2089 "y.tab.c"
    break;

  case 91: /* id_list: primary_expression  */
#line 378 "parser.y"
                                                                { (yyval.token_node).node=(yyvsp[0].token_node).node; }
#line 2095 "y.tab.c"
    break;

  case 92: /* id_list: postfix_expression  */
#line 379 "parser.y"
                                                                { (yyval.token_node).node=(yyvsp[0].token_node).node; }
#line 2101 "y.tab.c"
    break;

  case 93: /* id_list: id_list ',' primary_expression  */
#line 380 "parser.y"
                                                { ptr="id_list" ; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 2107 "y.tab.c"
    break;

  case 94: /* id_list: id_list ',' postfix_expression  */
#line 381 "parser.y"
                                                { ptr="id_list" ; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 2113 "y.tab.c"
    break;


#line 2117 "y.tab.c"

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

#line 385 "parser.y"




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
        print_ast(root);
        
        
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
