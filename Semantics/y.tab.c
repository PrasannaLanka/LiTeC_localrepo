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
	#include "ast.h"

    int yylex(void);
    void yyerror(char *); 

	extern FILE *yyin;

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
	
	void link_p(char *name ,enum data_type_t d );

#line 99 "y.tab.c"

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
    CONSTANT_INT = 260,            /* CONSTANT_INT  */
    CONSTANT_CHAR = 261,           /* CONSTANT_CHAR  */
    CONSTANT_FLOAT = 262,          /* CONSTANT_FLOAT  */
    CONSTANT_DOUBLE = 263,         /* CONSTANT_DOUBLE  */
    BOOL = 264,                    /* BOOL  */
    CHAR = 265,                    /* CHAR  */
    INT = 266,                     /* INT  */
    DOUBLE = 267,                  /* DOUBLE  */
    VOID = 268,                    /* VOID  */
    STRING_LITERAL = 269,          /* STRING_LITERAL  */
    STRUCT = 270,                  /* STRUCT  */
    ID = 271                       /* ID  */
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
#define CONSTANT_INT 260
#define CONSTANT_CHAR 261
#define CONSTANT_FLOAT 262
#define CONSTANT_DOUBLE 263
#define BOOL 264
#define CHAR 265
#define INT 266
#define DOUBLE 267
#define VOID 268
#define STRING_LITERAL 269
#define STRUCT 270
#define ID 271

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"

	struct token_node_t{
		char *name_token;
		struct ast_node_t *node;
	}token_node;

	struct token_node_id{
		char *name_token;
		struct ast_node_t *node;
		struct data_type_d *data_type;	
	}token_id;

#line 197 "y.tab.c"

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
  YYSYMBOL_CONSTANT_INT = 5,               /* CONSTANT_INT  */
  YYSYMBOL_CONSTANT_CHAR = 6,              /* CONSTANT_CHAR  */
  YYSYMBOL_CONSTANT_FLOAT = 7,             /* CONSTANT_FLOAT  */
  YYSYMBOL_CONSTANT_DOUBLE = 8,            /* CONSTANT_DOUBLE  */
  YYSYMBOL_BOOL = 9,                       /* BOOL  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_DOUBLE = 12,                    /* DOUBLE  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_STRING_LITERAL = 14,            /* STRING_LITERAL  */
  YYSYMBOL_STRUCT = 15,                    /* STRUCT  */
  YYSYMBOL_ID = 16,                        /* ID  */
  YYSYMBOL_17_ = 17,                       /* '{'  */
  YYSYMBOL_18_ = 18,                       /* '}'  */
  YYSYMBOL_19_ = 19,                       /* ';'  */
  YYSYMBOL_20_ = 20,                       /* ':'  */
  YYSYMBOL_21_ = 21,                       /* '('  */
  YYSYMBOL_22_ = 22,                       /* ')'  */
  YYSYMBOL_23_ = 23,                       /* ','  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_29_ = 29,                       /* '<'  */
  YYSYMBOL_30_ = 30,                       /* '>'  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_translation_main = 33,          /* translation_main  */
  YYSYMBOL_translation_unit = 34,          /* translation_unit  */
  YYSYMBOL_external_declaration = 35,      /* external_declaration  */
  YYSYMBOL_function_definition = 36,       /* function_definition  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_function_body = 38,             /* function_body  */
  YYSYMBOL_39_2 = 39,                      /* $@2  */
  YYSYMBOL_body = 40,                      /* body  */
  YYSYMBOL_compound_statement = 41,        /* compound_statement  */
  YYSYMBOL_42_3 = 42,                      /* $@3  */
  YYSYMBOL_compound_statement_content = 43, /* compound_statement_content  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_declaration = 45,               /* declaration  */
  YYSYMBOL_expression_statement = 46,      /* expression_statement  */
  YYSYMBOL_expression = 47,                /* expression  */
  YYSYMBOL_assignment_expression = 48,     /* assignment_expression  */
  YYSYMBOL_init_declarator = 49,           /* init_declarator  */
  YYSYMBOL_declarator = 50,                /* declarator  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_parameter_list = 52,            /* parameter_list  */
  YYSYMBOL_postfix_expression = 53,        /* postfix_expression  */
  YYSYMBOL_binary_operator = 54,           /* binary_operator  */
  YYSYMBOL_type_specifier = 55,            /* type_specifier  */
  YYSYMBOL_primary_expression = 56,        /* primary_expression  */
  YYSYMBOL_id_list = 57                    /* id_list  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   271


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
       2,     2,     2,     2,     2,     2,     2,    28,     2,     2,
      21,    22,    26,    24,    23,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    20,    19,
      29,    31,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    17,     2,    18,     2,     2,     2,     2,
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
      15,    16
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    69,    70,    74,    75,    79,    79,    84,
      84,    93,    94,    99,    99,   104,   105,   106,   107,   111,
     112,   120,   124,   125,   130,   131,   132,   136,   137,   142,
     143,   144,   148,   151,   158,   158,   177,   181,   189,   190,
     191,   192,   198,   199,   200,   201,   202,   203,   204,   205,
     211,   212,   213,   214,   215,   216,   220,   221,   222,   223,
     224,   225,   226,   227,   232,   233
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
  "CONSTANT_INT", "CONSTANT_CHAR", "CONSTANT_FLOAT", "CONSTANT_DOUBLE",
  "BOOL", "CHAR", "INT", "DOUBLE", "VOID", "STRING_LITERAL", "STRUCT",
  "ID", "'{'", "'}'", "';'", "':'", "'('", "')'", "','", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'<'", "'>'", "'='", "$accept", "translation_main",
  "translation_unit", "external_declaration", "function_definition", "$@1",
  "function_body", "$@2", "body", "compound_statement", "$@3",
  "compound_statement_content", "statement", "declaration",
  "expression_statement", "expression", "assignment_expression",
  "init_declarator", "declarator", "$@4", "parameter_list",
  "postfix_expression", "binary_operator", "type_specifier",
  "primary_expression", "id_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-55)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     157,   164,   -55,   -55,   -55,   -55,   -55,   -55,     5,   157,
     -55,   -55,   -55,   -55,    -1,   -55,   -55,    -1,    -4,     7,
      15,   -55,    21,    -3,   -55,     6,   -55,   -55,   164,   -55,
     -55,   -55,   -55,   -55,   -55,   128,   -55,   -55,    55,     9,
      23,    19,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
       6,   112,    22,   -55,   -55,    28,   -55,    74,   -55,   -55,
     -55,    31,   -55,   -55,   -55,   -55,   164,   -55,     2,     6,
       6,   -55,     6,   108,   -55,   112,   -55,   -55,   -55,    25,
      36,    33,   -55,    11,    34,    35,    42,    43,   -55,   -55,
      91,   -55,   -55,   -55,    45,   129,   -55,   -55,   -55,   -55,
     -55,   -55,   -55
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    53,    50,    51,    52,    55,    54,     0,     2,
       3,     6,     5,     7,     0,     1,     4,     0,    32,     0,
      29,     8,     0,    34,    21,     0,     9,    33,     0,    56,
      57,    58,    59,    61,    60,     0,    31,    30,     0,     0,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
       0,     0,    60,    13,    22,     0,    19,     0,    16,    15,
      20,     0,    24,    26,    25,    35,     0,    36,     0,     0,
       0,    12,     0,     0,    10,     0,    18,    17,    23,     0,
       0,     0,    64,     0,     0,     0,     0,     0,    28,    27,
       0,    11,    37,    62,     0,     0,    41,    40,    39,    38,
      14,    63,    65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,   -55,    44,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,    -5,   -54,   -36,   -45,   -55,   -55,   -55,    56,   -55,
     -55,   -21,   -55,     0,   -25,   -55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    17,    21,    38,    55,    56,
      73,    57,    58,    12,    60,    61,    62,    19,    20,    28,
      39,    63,    50,    13,    64,    83
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    14,    59,    76,    36,    15,    71,    29,    30,    31,
      32,    29,    30,    31,    32,    18,    33,    23,    34,    27,
      33,    77,    34,    80,    81,    70,    24,    35,    40,    69,
      91,    65,    66,    94,    95,    25,    76,    59,    26,    67,
      68,    92,    72,    82,    85,    87,    74,    89,    84,    86,
      78,    88,    41,    16,    77,    93,    96,    97,     1,    51,
      29,    30,    31,    32,    98,    99,    79,   101,    90,    33,
     102,    52,    53,    22,    54,     0,    35,     1,    75,    29,
      30,    31,    32,     0,     0,     0,     0,     0,    33,     0,
      52,    53,     0,    54,     1,    35,    29,    30,    31,    32,
       0,     0,     0,     0,     0,    33,     0,    52,    53,   100,
      54,     1,    35,    29,    30,    31,    32,    29,    30,    31,
      32,     0,    33,     0,    52,    53,    33,    54,    52,    35,
       0,    54,     0,    35,    29,    30,    31,    32,     0,     0,
       0,     0,     0,    33,    41,    34,     0,     0,     0,     0,
      80,     0,    42,    43,    44,    45,    46,    47,    48,    49,
       1,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     7,     2,     3,     4,     5,     6,     0,     7
};

static const yytype_int8 yycheck[] =
{
      25,     1,    38,    57,    25,     0,    51,     5,     6,     7,
       8,     5,     6,     7,     8,    16,    14,    21,    16,    22,
      14,    57,    16,    21,    22,    50,    19,    21,    28,    50,
      75,    22,    23,    22,    23,    20,    90,    73,    17,    16,
      21,    16,    20,    68,    69,    70,    18,    72,    69,    70,
      19,    72,    16,     9,    90,    22,    22,    22,     3,     4,
       5,     6,     7,     8,    22,    22,    66,    22,    73,    14,
      95,    16,    17,    17,    19,    -1,    21,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      16,    17,    -1,    19,     3,    21,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    16,    17,    18,
      19,     3,    21,     5,     6,     7,     8,     5,     6,     7,
       8,    -1,    14,    -1,    16,    17,    14,    19,    16,    21,
      -1,    19,    -1,    21,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    14,    16,    16,    -1,    -1,    -1,    -1,
      21,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
       3,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      13,    -1,    15,     9,    10,    11,    12,    13,    -1,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     9,    10,    11,    12,    13,    15,    33,    34,
      35,    36,    45,    55,    55,     0,    35,    37,    16,    49,
      50,    38,    50,    21,    19,    20,    17,    22,    51,     5,
       6,     7,     8,    14,    16,    21,    53,    56,    39,    52,
      55,    16,    24,    25,    26,    27,    28,    29,    30,    31,
      54,     4,    16,    17,    19,    40,    41,    43,    44,    45,
      46,    47,    48,    53,    56,    22,    23,    16,    21,    53,
      56,    46,    20,    42,    18,     4,    44,    45,    19,    55,
      21,    22,    56,    57,    53,    56,    53,    56,    53,    56,
      43,    46,    16,    22,    22,    23,    22,    22,    22,    22,
      18,    22,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    37,    36,    39,
      38,    40,    40,    42,    41,    43,    43,    43,    43,    44,
      44,    45,    46,    46,    47,    47,    47,    48,    48,    49,
      49,    49,    50,    50,    51,    50,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     0,     3,     0,
       5,     3,     2,     0,     4,     1,     1,     2,     2,     1,
       1,     4,     1,     2,     1,     1,     1,     3,     3,     1,
       3,     3,     1,     3,     0,     5,     2,     4,     5,     5,
       5,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     6,     1,     3
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
  case 2: /* translation_main: translation_unit  */
#line 63 "parser.y"
                                         { ptr="Main"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); root=(yyval.token_node).node ;}
#line 1317 "y.tab.c"
    break;

  case 3: /* translation_unit: external_declaration  */
#line 69 "parser.y"
                                                        {ptr="trans_unit"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL);}
#line 1323 "y.tab.c"
    break;

  case 4: /* translation_unit: translation_unit external_declaration  */
#line 70 "parser.y"
                                                                { ptr="trans_unit"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node);  }
#line 1329 "y.tab.c"
    break;

  case 5: /* external_declaration: declaration  */
#line 74 "parser.y"
                                                        {ptr="external_declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL);}
#line 1335 "y.tab.c"
    break;

  case 6: /* external_declaration: function_definition  */
#line 75 "parser.y"
                                     {ptr="fun_declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL);}
#line 1341 "y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 79 "parser.y"
                        { }
#line 1347 "y.tab.c"
    break;

  case 8: /* function_definition: type_specifier $@1 function_body  */
#line 80 "parser.y"
                          {ptr="fun_def"; (yyval.token_node).node=build_node((yyvsp[0].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 1353 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 84 "parser.y"
                        {}
#line 1359 "y.tab.c"
    break;

  case 10: /* function_body: declarator '{' $@2 body '}'  */
#line 85 "parser.y"
                            {temp_symbol_table=table_pop(); current_symbol_table=table_top();  ptr="fun_body"; no_of_parameters=0;
													    if((yyvsp[-4].token_node).node->left!=NULL)
														{(yyval.token_node).node=build_node((yyvsp[-4].token_node).node->name,(yyvsp[-4].token_node).node->left,(yyvsp[-1].token_node).node);}  
														else{(yyval.token_node).node=build_node(ptr,NULL,(yyvsp[-1].token_node).node);}
														}
#line 1369 "y.tab.c"
    break;

  case 11: /* body: compound_statement_content RETURN expression_statement  */
#line 93 "parser.y"
                                                                   { ptr="body"; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node); }
#line 1375 "y.tab.c"
    break;

  case 12: /* body: RETURN expression_statement  */
#line 94 "parser.y"
                                      { ptr="body"; (yyval.token_node).node=build_node(ptr,NULL,(yyvsp[0].token_node).node);  }
#line 1381 "y.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 99 "parser.y"
               {table_push(current_symbol_table); current_symbol_table=init_child_symbol_table(current_symbol_table);  }
#line 1387 "y.tab.c"
    break;

  case 14: /* compound_statement: '{' $@3 compound_statement_content '}'  */
#line 100 "parser.y"
                                                        {table_push(temp_symbol_table);	 ptr="cmp_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,NULL); }
#line 1393 "y.tab.c"
    break;

  case 15: /* compound_statement_content: declaration  */
#line 104 "parser.y"
                                                                           {ptr="cmp_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL);}
#line 1399 "y.tab.c"
    break;

  case 16: /* compound_statement_content: statement  */
#line 105 "parser.y"
                                                                                        {ptr="cmp_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL);}
#line 1405 "y.tab.c"
    break;

  case 17: /* compound_statement_content: compound_statement_content declaration  */
#line 106 "parser.y"
                                                  {ptr="cmp_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node);}
#line 1411 "y.tab.c"
    break;

  case 18: /* compound_statement_content: compound_statement_content statement  */
#line 107 "parser.y"
                                                   {ptr="cmp_stmt"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,(yyvsp[0].token_node).node);}
#line 1417 "y.tab.c"
    break;

  case 19: /* statement: compound_statement  */
#line 111 "parser.y"
                                            {ptr="comp_st"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL);}
#line 1423 "y.tab.c"
    break;

  case 20: /* statement: expression_statement  */
#line 112 "parser.y"
                                                {ptr="comp_st"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL);}
#line 1429 "y.tab.c"
    break;

  case 21: /* declaration: DECLARE type_specifier init_declarator ';'  */
#line 120 "parser.y"
                                                                        {ptr="declr"; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);}
#line 1435 "y.tab.c"
    break;

  case 22: /* expression_statement: ';'  */
#line 124 "parser.y"
                                                                        {ptr=";"; (yyval.token_node).node=build_node(ptr,NULL,NULL);  }
#line 1441 "y.tab.c"
    break;

  case 23: /* expression_statement: expression ';'  */
#line 125 "parser.y"
                                           { ptr="expr"; (yyval.token_node).node=build_node(ptr,(yyvsp[-1].token_node).node,NULL); }
#line 1447 "y.tab.c"
    break;

  case 24: /* expression: assignment_expression  */
#line 130 "parser.y"
                                                                        {ptr="assign_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1453 "y.tab.c"
    break;

  case 25: /* expression: primary_expression  */
#line 131 "parser.y"
                                                                        {ptr="prm_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1459 "y.tab.c"
    break;

  case 26: /* expression: postfix_expression  */
#line 132 "parser.y"
                                                                        {ptr="post_exp"; (yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL); }
#line 1465 "y.tab.c"
    break;

  case 27: /* assignment_expression: ID ':' primary_expression  */
#line 136 "parser.y"
                                                        {ptr="assignment";(yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_id).node,(yyvsp[0].token_node).node);}
#line 1471 "y.tab.c"
    break;

  case 28: /* assignment_expression: ID ':' postfix_expression  */
#line 137 "parser.y"
                                                        {ptr="assignment";(yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_id).node,(yyvsp[0].token_node).node);}
#line 1477 "y.tab.c"
    break;

  case 29: /* init_declarator: declarator  */
#line 142 "parser.y"
                                                                        {ptr="init_declarator";(yyval.token_node).node=build_node(ptr,(yyvsp[0].token_node).node,NULL);}
#line 1483 "y.tab.c"
    break;

  case 30: /* init_declarator: declarator ':' primary_expression  */
#line 143 "parser.y"
                                               {ptr="init_declarator";(yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node);}
#line 1489 "y.tab.c"
    break;

  case 31: /* init_declarator: declarator ':' postfix_expression  */
#line 144 "parser.y"
                                                        {ptr="init_declarator";(yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node);}
#line 1495 "y.tab.c"
    break;

  case 32: /* declarator: ID  */
#line 148 "parser.y"
                                                                {if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[0].token_id).name_token , variable_t , data_type)==false)
																			{ptr="Redeclared";yyerror(ptr); printf("redeclared\n");}
									 (yyvsp[0].token_id).data_type=get_type(data_type);	(yyval.token_node).node=build_node((yyvsp[0].token_id).name_token,(yyvsp[0].token_id).node,NULL);	(yyval.token_node).node->data_type=data_type;}
#line 1503 "y.tab.c"
    break;

  case 33: /* declarator: ID '(' ')'  */
#line 151 "parser.y"
                                                { if ( insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[-2].token_id).name_token , function_t,data_type)==false)
																			{ptr="Redeclared";yyerror(ptr);printf("redeclared\n");} 
																			current_symbol_table=init_child_symbol_table(current_symbol_table); 
																			table_push(current_symbol_table);
																			
																			item=search_in_all_sym_tbl(current_symbol_table , (yyvsp[-2].token_id).name_token);
									(yyvsp[-2].token_id).data_type=get_type(data_type);	(yyval.token_node).node=build_node((yyvsp[-2].token_id).name_token,(yyvsp[-2].token_id).node,NULL);	(yyval.token_node).node->data_type=data_type;          }
#line 1515 "y.tab.c"
    break;

  case 34: /* $@4: %empty  */
#line 158 "parser.y"
                                     {  
									if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[-1].token_id).name_token , function_t , data_type)==false)
																			{ptr="Redeclared";yyerror(ptr);printf("redeclared\n");}
									current_symbol_table=init_child_symbol_table(current_symbol_table); table_push(current_symbol_table);}
#line 1524 "y.tab.c"
    break;

  case 35: /* declarator: ID '(' $@4 parameter_list ')'  */
#line 162 "parser.y"
                                      {    item=search_in_all_sym_tbl(current_symbol_table , (yyvsp[-4].token_id).name_token);
											
										function_info.return_data_type=data_type;
										function_info.no_parameters=no_of_parameters;
										function_info.parameters=parameter_list->next;
										id_info.function_info=function_info; 
										item->id_info=id_info;
										parameter_list=NULL;
										params=parameter_list;
										
										(yyvsp[-4].token_id).data_type=get_type(data_type); (yyval.token_node).node=build_node((yyvsp[-4].token_id).name_token ,(yyvsp[-1].token_node).node ,NULL ); (yyval.token_node).node->data_type=data_type; }
#line 1540 "y.tab.c"
    break;

  case 36: /* parameter_list: type_specifier ID  */
#line 177 "parser.y"
                                                     { if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[0].token_id).name_token , function_param , data_type)==false)
																			{ptr="Redeclared";yyerror(ptr);printf("redeclared\n");} no_of_parameters++;      (yyvsp[0].token_id).data_type=get_type(data_type);  
																			(yyval.token_node).node=build_node((yyvsp[0].token_id).name_token,(yyvsp[0].token_id).node,NULL); (yyval.token_node).node->data_type=data_type; 
																			link_p((yyvsp[0].token_id).name_token,data_type);}
#line 1549 "y.tab.c"
    break;

  case 37: /* parameter_list: parameter_list ',' type_specifier ID  */
#line 181 "parser.y"
                                                                        {if (insert_symbol_tbl(current_symbol_table->symbol_table_t ,(yyvsp[0].token_id).name_token , function_param , data_type)==false)
																			{ptr="Redeclared";yyerror(ptr);printf("redeclared\n");}  (yyvsp[0].token_id).data_type=get_type(data_type);  no_of_parameters++;
															ptr="param";  (yyval.token_node).node=build_node(ptr,(yyvsp[-3].token_node).node,(yyvsp[0].token_id).node );(yyval.token_node).node->data_type=data_type; link_p((yyvsp[-1].token_node).name_token,data_type);     }
#line 1557 "y.tab.c"
    break;

  case 38: /* postfix_expression: '(' binary_operator primary_expression primary_expression ')'  */
#line 189 "parser.y"
                                                                           { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);   }
#line 1563 "y.tab.c"
    break;

  case 39: /* postfix_expression: '(' binary_operator primary_expression postfix_expression ')'  */
#line 190 "parser.y"
                                                                                { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);   }
#line 1569 "y.tab.c"
    break;

  case 40: /* postfix_expression: '(' binary_operator postfix_expression primary_expression ')'  */
#line 191 "parser.y"
                                                                                { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);   }
#line 1575 "y.tab.c"
    break;

  case 41: /* postfix_expression: '(' binary_operator postfix_expression postfix_expression ')'  */
#line 192 "parser.y"
                                                                                { (yyval.token_node).node=build_node((yyvsp[-3].token_node).node->name,(yyvsp[-2].token_node).node,(yyvsp[-1].token_node).node);   }
#line 1581 "y.tab.c"
    break;

  case 42: /* binary_operator: '+'  */
#line 198 "parser.y"
                                                {ptr="+"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1587 "y.tab.c"
    break;

  case 43: /* binary_operator: '-'  */
#line 199 "parser.y"
                                                {ptr="-"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1593 "y.tab.c"
    break;

  case 44: /* binary_operator: '*'  */
#line 200 "parser.y"
                                                {ptr="*"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1599 "y.tab.c"
    break;

  case 45: /* binary_operator: '/'  */
#line 201 "parser.y"
                                                {ptr="/"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1605 "y.tab.c"
    break;

  case 46: /* binary_operator: '%'  */
#line 202 "parser.y"
                                                {ptr="%"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1611 "y.tab.c"
    break;

  case 47: /* binary_operator: '<'  */
#line 203 "parser.y"
                                                {ptr="<"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1617 "y.tab.c"
    break;

  case 48: /* binary_operator: '>'  */
#line 204 "parser.y"
                                                {ptr=">"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1623 "y.tab.c"
    break;

  case 49: /* binary_operator: '='  */
#line 205 "parser.y"
                                                {ptr="="; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1629 "y.tab.c"
    break;

  case 50: /* type_specifier: CHAR  */
#line 211 "parser.y"
                                {ptr="char"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=char_t ;}
#line 1635 "y.tab.c"
    break;

  case 51: /* type_specifier: INT  */
#line 212 "parser.y"
                                                {ptr="int"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=int_t ;  }
#line 1641 "y.tab.c"
    break;

  case 52: /* type_specifier: DOUBLE  */
#line 213 "parser.y"
                                                {ptr="double"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=double_t; }
#line 1647 "y.tab.c"
    break;

  case 53: /* type_specifier: BOOL  */
#line 214 "parser.y"
                                                {ptr="bool"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=bool_t ;}
#line 1653 "y.tab.c"
    break;

  case 54: /* type_specifier: STRUCT  */
#line 215 "parser.y"
                                                {ptr="struct"; (yyval.token_node).node=build_node(ptr,NULL,NULL); }
#line 1659 "y.tab.c"
    break;

  case 55: /* type_specifier: VOID  */
#line 216 "parser.y"
                                                {ptr="void"; (yyval.token_node).node=build_node(ptr,NULL,NULL); data_type=void_t;}
#line 1665 "y.tab.c"
    break;

  case 56: /* primary_expression: CONSTANT_INT  */
#line 220 "parser.y"
                                { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); }
#line 1671 "y.tab.c"
    break;

  case 57: /* primary_expression: CONSTANT_CHAR  */
#line 221 "parser.y"
                                { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); }
#line 1677 "y.tab.c"
    break;

  case 58: /* primary_expression: CONSTANT_FLOAT  */
#line 222 "parser.y"
                                    { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); }
#line 1683 "y.tab.c"
    break;

  case 59: /* primary_expression: CONSTANT_DOUBLE  */
#line 223 "parser.y"
                                { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); }
#line 1689 "y.tab.c"
    break;

  case 60: /* primary_expression: ID  */
#line 224 "parser.y"
                                                { (yyval.token_node).node=build_node((yyvsp[0].token_id).name_token,NULL,NULL); }
#line 1695 "y.tab.c"
    break;

  case 61: /* primary_expression: STRING_LITERAL  */
#line 225 "parser.y"
                                        { (yyval.token_node).node=build_node((yyvsp[0].token_node).name_token,NULL,NULL); }
#line 1701 "y.tab.c"
    break;

  case 62: /* primary_expression: '(' ID '(' ')' ')'  */
#line 226 "parser.y"
                                      { (yyval.token_node).node=(yyvsp[-3].token_id).node; }
#line 1707 "y.tab.c"
    break;

  case 63: /* primary_expression: '(' ID '(' id_list ')' ')'  */
#line 227 "parser.y"
                                    { (yyval.token_node).node=build_node( (yyvsp[-4].token_id).name_token, (yyvsp[-4].token_id).node , (yyvsp[-2].token_node).node ); }
#line 1713 "y.tab.c"
    break;

  case 64: /* id_list: primary_expression  */
#line 232 "parser.y"
                                                                        {(yyval.token_node).node=(yyvsp[0].token_node).node;}
#line 1719 "y.tab.c"
    break;

  case 65: /* id_list: id_list ',' primary_expression  */
#line 233 "parser.y"
                                                    {ptr="id_list" ; (yyval.token_node).node=build_node(ptr,(yyvsp[-2].token_node).node,(yyvsp[0].token_node).node);   }
#line 1725 "y.tab.c"
    break;


#line 1729 "y.tab.c"

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

#line 238 "parser.y"


void yyerror(char *s) 
{
    fprintf(stderr, "%s\n", s);
	return ;
}  

/*For insertion we store data temporarily*/
char *int_ptr="int";
char *char_ptr="char";
char *float_ptr="float";
char *doubl_ptr="double";



int main(int argc, char *argv[])
{
	
	  data_type = int_t;
      symbol_table *global_sym_tbl = init_symbol_table();
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
			printf("\nParsing error \n");
		}
		else
		{
			printf("\nparsing completed \n");
		}
		fclose(yyin);
		print_ast(root);
		printf("\n"); 
		//printf("Symbol Table \n");
		//print_symbol_table(table_top());

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










