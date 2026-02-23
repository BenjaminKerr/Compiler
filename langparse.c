/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lang.y"

//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard 
//

#include <iostream>
#include "lex.h"
#include "astnodes.h"

class cFloatExprNode;
class cBinaryExprNode;

static bool g_semanticErrorHappened = false;

#define CHECK_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; } }
#define PROP_ERROR() { if (g_semanticErrorHappened) \
    { g_semanticErrorHappened = false; YYERROR; } }


#line 96 "langparse.c"

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

#include "langparse.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_TYPE_ID = 4,                    /* TYPE_ID  */
  YYSYMBOL_CHAR_VAL = 5,                   /* CHAR_VAL  */
  YYSYMBOL_INT_VAL = 6,                    /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 7,                  /* FLOAT_VAL  */
  YYSYMBOL_LE = 8,                         /* LE  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_AND = 10,                       /* AND  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_EQUALS = 12,                    /* EQUALS  */
  YYSYMBOL_NOT_EQUALS = 13,                /* NOT_EQUALS  */
  YYSYMBOL_STRING_LIT = 14,                /* STRING_LIT  */
  YYSYMBOL_PROGRAM = 15,                   /* PROGRAM  */
  YYSYMBOL_PRINT = 16,                     /* PRINT  */
  YYSYMBOL_PRINTS = 17,                    /* PRINTS  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_ENDIF = 21,                     /* ENDIF  */
  YYSYMBOL_STRUCT = 22,                    /* STRUCT  */
  YYSYMBOL_ARRAY = 23,                     /* ARRAY  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_JUNK_TOKEN = 25,                /* JUNK_TOKEN  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* '['  */
  YYSYMBOL_30_ = 30,                       /* ']'  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '.'  */
  YYSYMBOL_36_ = 36,                       /* '<'  */
  YYSYMBOL_37_ = 37,                       /* '>'  */
  YYSYMBOL_38_ = 38,                       /* '+'  */
  YYSYMBOL_39_ = 39,                       /* '-'  */
  YYSYMBOL_40_ = 40,                       /* '*'  */
  YYSYMBOL_41_ = 41,                       /* '/'  */
  YYSYMBOL_42_ = 42,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_block = 45,                     /* block  */
  YYSYMBOL_open = 46,                      /* open  */
  YYSYMBOL_close = 47,                     /* close  */
  YYSYMBOL_decls = 48,                     /* decls  */
  YYSYMBOL_decl = 49,                      /* decl  */
  YYSYMBOL_var_decl = 50,                  /* var_decl  */
  YYSYMBOL_struct_decl = 51,               /* struct_decl  */
  YYSYMBOL_array_decl = 52,                /* array_decl  */
  YYSYMBOL_func_decl = 53,                 /* func_decl  */
  YYSYMBOL_func_header = 54,               /* func_header  */
  YYSYMBOL_func_prefix = 55,               /* func_prefix  */
  YYSYMBOL_paramsspec = 56,                /* paramsspec  */
  YYSYMBOL_paramspec = 57,                 /* paramspec  */
  YYSYMBOL_stmts = 58,                     /* stmts  */
  YYSYMBOL_stmt = 59,                      /* stmt  */
  YYSYMBOL_func_call = 60,                 /* func_call  */
  YYSYMBOL_varref = 61,                    /* varref  */
  YYSYMBOL_varpart = 62,                   /* varpart  */
  YYSYMBOL_lval = 63,                      /* lval  */
  YYSYMBOL_params = 64,                    /* params  */
  YYSYMBOL_param = 65,                     /* param  */
  YYSYMBOL_expr = 66,                      /* expr  */
  YYSYMBOL_andexpr = 67,                   /* andexpr  */
  YYSYMBOL_relexpr = 68,                   /* relexpr  */
  YYSYMBOL_addit = 69,                     /* addit  */
  YYSYMBOL_term = 70,                      /* term  */
  YYSYMBOL_unary = 71,                     /* unary  */
  YYSYMBOL_fact = 72                       /* fact  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 49 "lang.y"

    int yyerror(const char *msg);

    cAstNode *yyast_root;

#line 208 "langparse.c"


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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   235

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
      32,    31,    40,    38,    33,    39,    35,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      36,    34,    37,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   117,   119,   122,   125,   128,   130,   132,
     134,   136,   138,   140,   143,   146,   148,   151,   153,   161,
     170,   176,   182,   188,   190,   193,   196,   198,   201,   203,
     205,   207,   209,   211,   213,   215,   217,   219,   222,   227,
     233,   235,   237,   240,   243,   246,   248,   254,   257,   259,
     262,   264,   267,   269,   271,   273,   275,   277,   279,   282,
     284,   286,   289,   291,   293,   295,   298,   300,   303,   305,
     307,   309,   311
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "TYPE_ID", "CHAR_VAL", "INT_VAL", "FLOAT_VAL", "LE", "GE", "AND", "OR",
  "EQUALS", "NOT_EQUALS", "STRING_LIT", "PROGRAM", "PRINT", "PRINTS",
  "WHILE", "IF", "ELSE", "ENDIF", "STRUCT", "ARRAY", "RETURN",
  "JUNK_TOKEN", "'{'", "'}'", "';'", "'['", "']'", "')'", "'('", "','",
  "'='", "'.'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept",
  "program", "block", "open", "close", "decls", "decl", "var_decl",
  "struct_decl", "array_decl", "func_decl", "func_header", "func_prefix",
  "paramsspec", "paramspec", "stmts", "stmt", "func_call", "varref",
  "varpart", "lval", "params", "param", "expr", "andexpr", "relexpr",
  "addit", "term", "unary", "fact", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   123,   125,    59,    91,
      93,    41,    40,    44,    61,    46,    60,    62,    43,    45,
      42,    47,    37
};
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,    -2,    81,   -48,   -48,   165,   -48,    66,    63,   103,
      84,    85,    86,    87,    -2,   117,    35,   -48,   165,   -48,
      94,    97,    98,   -48,    27,     8,    59,   -48,   102,   -13,
     -48,    95,   105,     4,   104,    35,   124,    35,    35,    25,
     114,   -48,   -48,    35,    35,   -48,   -13,    21,   135,    60,
       7,   -23,   -48,   -48,   -48,    59,   -48,   -48,   -48,   165,
     -48,   145,   -48,   -48,    26,   -48,   131,   -48,   -48,   -48,
     -48,    35,   160,    35,   -48,    49,   -48,   156,   -48,     3,
     139,     9,    20,   150,   101,   174,    73,   -48,    35,   -48,
      35,    35,    35,    35,    35,    35,    35,    35,    35,    35,
      35,    35,   -48,   165,   134,   -48,   -48,   181,   -48,    79,
     -48,   -48,    82,   -48,    35,   158,   162,   209,   209,   -48,
     195,   173,   -48,   135,    60,     7,     7,     7,     7,     7,
       7,   -23,   -23,   -48,   -48,   -48,   138,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   176,   -48,   201,   -48,   209,
     177,   -48,   198,   -48,   178,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     2,     0,     1,     0,    43,     0,
       0,     0,     0,     0,     0,     0,     0,    35,     0,     8,
       0,     0,     0,    12,     0,     0,     0,    27,     0,    44,
      42,     0,    13,     0,    14,     0,     0,     0,     0,     0,
       0,    69,    70,     0,     0,    72,    71,     0,    49,    51,
      58,    61,    65,    67,     7,     0,     9,    11,    10,     0,
      17,     0,    21,    25,     0,    24,     0,     6,     4,    26,
      34,     0,     0,     0,    39,     0,    46,    47,    22,     0,
       0,     0,     0,     0,     0,     0,     0,    66,     0,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,    14,    20,     0,    37,     0,
      43,    40,     0,    38,     0,     0,     0,     0,     0,    13,
       0,     0,    68,    48,    50,    56,    57,    52,    53,    54,
      55,    59,    60,    62,    63,    64,     0,    19,    23,    41,
      33,    45,    31,    32,    30,     0,    15,     0,    18,     0,
       0,    16,     0,    28,     0,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   206,   194,   -47,    32,   -14,   -20,   -48,   -48,
     -48,   -48,   -48,   -48,   106,   -15,   -25,    -5,    -3,   137,
     -48,   -48,   107,   -10,   123,   128,    80,    10,   -35,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    17,     5,    68,    18,    19,    20,    21,    22,
      23,    24,    25,    64,    65,    26,    27,    45,    46,    30,
      31,    75,    76,    77,    48,    49,    50,    51,    52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    69,    29,    55,    54,    63,    47,     8,   102,    87,
      41,    42,    61,    28,    88,    29,    71,    99,   100,   101,
      88,    28,    72,    29,     3,    79,    83,    81,    82,     9,
      69,    88,    88,    86,   115,    74,    43,   120,     8,    62,
     117,    41,    42,    44,   104,    97,    98,    14,    15,    89,
      28,   118,    29,    59,    28,    60,    29,   106,     1,   107,
      66,   109,     8,   112,   133,   134,   135,    43,    91,    92,
      54,    84,    93,    94,    44,    10,    11,    12,    13,    69,
     113,     6,   114,    16,    88,     3,    67,    63,   136,    54,
      88,   103,   144,    88,    32,    33,    95,    96,    28,    28,
      29,    29,    83,   145,   122,     9,    34,   131,   132,   139,
     140,    69,    28,    28,    29,    29,    35,    36,    37,    38,
      69,    40,    56,    14,    15,    57,    58,    69,    67,    73,
      70,    28,   -37,    29,   152,    66,    78,     8,    80,    66,
      28,     8,    29,    85,    28,    90,    29,    28,   105,    29,
      10,    11,    12,    13,    10,    11,    12,    13,    16,   108,
       3,   137,    16,   110,     3,   148,     7,    88,     8,     9,
     116,   125,   126,   127,   128,   129,   130,    66,   119,     8,
     121,    10,    11,    12,    13,    61,   142,    14,    15,    16,
     143,     3,    10,    11,    12,    13,   149,   150,   146,    66,
      16,     8,     3,   147,   151,   153,   155,     4,    39,   111,
      66,   123,     8,   138,    10,    11,    12,    13,   124,   154,
       0,   141,    16,     0,     3,    10,    11,    12,    13,     0,
       0,     0,     0,    16,     0,     3
};

static const yytype_int16 yycheck[] =
{
       5,    26,     5,    18,    18,    25,    16,     3,    55,    44,
       6,     7,     4,    18,    11,    18,    29,    40,    41,    42,
      11,    26,    35,    26,    26,    35,     1,    37,    38,     4,
      55,    11,    11,    43,    31,    31,    32,    84,     3,    31,
      31,     6,     7,    39,    59,    38,    39,    22,    23,    28,
      55,    31,    55,    26,    59,    28,    59,    31,    15,    33,
       1,    71,     3,    73,    99,   100,   101,    32,     8,     9,
      84,    39,    12,    13,    39,    16,    17,    18,    19,   104,
      31,     0,    33,    24,    11,    26,    27,   107,   103,   103,
      11,    59,   117,    11,    28,    32,    36,    37,   103,   104,
     103,   104,     1,   118,    31,     4,     3,    97,    98,    30,
      28,   136,   117,   118,   117,   118,    32,    32,    32,    32,
     145,     4,    28,    22,    23,    28,    28,   152,    27,    34,
      28,   136,    27,   136,   149,     1,    32,     3,    14,     1,
     145,     3,   145,    29,   149,    10,   149,   152,     3,   152,
      16,    17,    18,    19,    16,    17,    18,    19,    24,    28,
      26,    27,    24,     3,    26,    27,     1,    11,     3,     4,
      31,    91,    92,    93,    94,    95,    96,     1,    28,     3,
       6,    16,    17,    18,    19,     4,    28,    22,    23,    24,
      28,    26,    16,    17,    18,    19,    20,    21,     3,     1,
      24,     3,    26,    30,     3,    28,    28,     1,    14,    72,
       1,    88,     3,   107,    16,    17,    18,    19,    90,    21,
      -1,   114,    24,    -1,    26,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    44,    26,    45,    46,     0,     1,     3,     4,
      16,    17,    18,    19,    22,    23,    24,    45,    48,    49,
      50,    51,    52,    53,    54,    55,    58,    59,    60,    61,
      62,    63,    28,    32,     3,    32,    32,    32,    32,    46,
       4,     6,     7,    32,    39,    60,    61,    66,    67,    68,
      69,    70,    71,    72,    49,    58,    28,    28,    28,    26,
      28,     4,    31,    50,    56,    57,     1,    27,    47,    59,
      28,    29,    35,    34,    31,    64,    65,    66,    32,    66,
      14,    66,    66,     1,    48,    29,    66,    71,    11,    28,
      10,     8,     9,    12,    13,    36,    37,    38,    39,    40,
      41,    42,    47,    48,    58,     3,    31,    33,    28,    66,
       3,    62,    66,    31,    33,    31,    31,    31,    31,    28,
      47,     6,    31,    67,    68,    69,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    71,    58,    27,    57,    30,
      28,    65,    28,    28,    59,    58,     3,    30,    27,    20,
      21,     3,    58,    28,    21,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    48,    48,    49,
      49,    49,    49,    49,    50,    51,    52,    53,    53,    53,
      54,    54,    55,    56,    56,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    63,    64,    64,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    69,    70,    70,    70,    70,    71,    71,    72,    72,
      72,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     3,     1,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     5,     6,     2,     5,     4,
       3,     2,     3,     3,     1,     1,     2,     1,     7,     9,
       5,     5,     5,     4,     2,     1,     3,     2,     4,     3,
       3,     4,     1,     1,     1,     3,     1,     1,     3,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     1,     3,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
    goto yyexhaustedlab;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: PROGRAM block  */
#line 110 "lang.y"
                                { (yyval.program_node) = new cProgramNode((yyvsp[0].block_node));
                                  yyast_root = (yyval.program_node);
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
#line 1380 "langparse.c"
    break;

  case 3: /* block: open decls stmts close  */
#line 118 "lang.y"
                                { (yyval.block_node) = new cBlockNode((yyvsp[-2].decls_node), (yyvsp[-1].stmts_node)); }
#line 1386 "langparse.c"
    break;

  case 4: /* block: open stmts close  */
#line 120 "lang.y"
                                { (yyval.block_node) = new cBlockNode(nullptr, (yyvsp[-1].stmts_node)); }
#line 1392 "langparse.c"
    break;

  case 5: /* open: '{'  */
#line 123 "lang.y"
                                { g_symbolTable.IncreaseScope(); }
#line 1398 "langparse.c"
    break;

  case 6: /* close: '}'  */
#line 126 "lang.y"
                                { g_symbolTable.DecreaseScope(); }
#line 1404 "langparse.c"
    break;

  case 7: /* decls: decls decl  */
#line 129 "lang.y"
                                { (yyval.decls_node) = (yyvsp[-1].decls_node); (yyval.decls_node)->Insert((cDeclNode*)(yyvsp[0].ast_node)); }
#line 1410 "langparse.c"
    break;

  case 8: /* decls: decl  */
#line 131 "lang.y"
                                { (yyval.decls_node) = new cDeclsNode((cDeclNode*)(yyvsp[0].ast_node)); }
#line 1416 "langparse.c"
    break;

  case 9: /* decl: var_decl ';'  */
#line 133 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1422 "langparse.c"
    break;

  case 10: /* decl: array_decl ';'  */
#line 135 "lang.y"
                            {  }
#line 1428 "langparse.c"
    break;

  case 11: /* decl: struct_decl ';'  */
#line 137 "lang.y"
                            {  }
#line 1434 "langparse.c"
    break;

  case 12: /* decl: func_decl  */
#line 139 "lang.y"
                            {  }
#line 1440 "langparse.c"
    break;

  case 13: /* decl: error ';'  */
#line 141 "lang.y"
                            {  }
#line 1446 "langparse.c"
    break;

  case 14: /* var_decl: TYPE_ID IDENTIFIER  */
#line 144 "lang.y"
                { (yyval.ast_node) = new cVarDeclNode((yyvsp[-1].symbol), (yyvsp[0].symbol)); 
                  CHECK_ERROR(); }
#line 1453 "langparse.c"
    break;

  case 15: /* struct_decl: STRUCT open decls close IDENTIFIER  */
#line 147 "lang.y"
                                {  }
#line 1459 "langparse.c"
    break;

  case 16: /* array_decl: ARRAY TYPE_ID '[' INT_VAL ']' IDENTIFIER  */
#line 149 "lang.y"
                                { (yyval.ast_node) = new cArrayDeclNode((yyvsp[-4].symbol), (yyvsp[-2].int_val), (yyvsp[0].symbol)); }
#line 1465 "langparse.c"
    break;

  case 17: /* func_decl: func_header ';'  */
#line 152 "lang.y"
                                { (yyval.func_decl_node) = (yyvsp[-1].func_decl_node); CHECK_ERROR(); }
#line 1471 "langparse.c"
    break;

  case 18: /* func_decl: func_header '{' decls stmts '}'  */
#line 154 "lang.y"
                                { 
                                    (yyval.func_decl_node) = (yyvsp[-4].func_decl_node);
                                    (yyval.func_decl_node)->AddChild((yyvsp[-1].stmts_node));  // Add stmts
                                    cSymbol* name = (cSymbol*)(yyval.func_decl_node)->GetChild(1);
                                    (yyval.func_decl_node)->CheckMultipleDefinitions(name);
                                    CHECK_ERROR(); 
                                }
#line 1483 "langparse.c"
    break;

  case 19: /* func_decl: func_header '{' stmts '}'  */
#line 162 "lang.y"
                                { 
                                    (yyval.func_decl_node) = (yyvsp[-3].func_decl_node);
                                    (yyval.func_decl_node)->AddChild((yyvsp[-1].stmts_node));  // Add stmts
                                    cSymbol* name = (cSymbol*)(yyval.func_decl_node)->GetChild(1);
                                    (yyval.func_decl_node)->CheckMultipleDefinitions(name);
                                    CHECK_ERROR(); 
                                }
#line 1495 "langparse.c"
    break;

  case 20: /* func_header: func_prefix paramsspec ')'  */
#line 171 "lang.y"
                                { 
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)(yyvsp[-2].ast_node))->GetChild(0);
                                    cSymbol *name = (cSymbol*)((cAstNode*)(yyvsp[-2].ast_node))->GetChild(1);
                                    (yyval.func_decl_node) = new cFuncDeclNode(returnType, name, (yyvsp[-1].params_node));
                                }
#line 1505 "langparse.c"
    break;

  case 21: /* func_header: func_prefix ')'  */
#line 177 "lang.y"
                                { 
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)(yyvsp[-1].ast_node))->GetChild(0);
                                    cSymbol *name = (cSymbol*)((cAstNode*)(yyvsp[-1].ast_node))->GetChild(1);
                                    (yyval.func_decl_node) = new cFuncDeclNode(returnType, name, nullptr);
                                }
#line 1515 "langparse.c"
    break;

  case 22: /* func_prefix: TYPE_ID IDENTIFIER '('  */
#line 183 "lang.y"
                                { 
                                    (yyval.ast_node) = new cPrefixNode();
                                    (yyval.ast_node)->AddChild((yyvsp[-2].symbol));
                                    (yyval.ast_node)->AddChild((yyvsp[-1].symbol));
                                }
#line 1525 "langparse.c"
    break;

  case 23: /* paramsspec: paramsspec ',' paramspec  */
#line 189 "lang.y"
                                { (yyval.params_node) = (yyvsp[-2].params_node); (yyval.params_node)->AddParam((yyvsp[0].param_node)); }
#line 1531 "langparse.c"
    break;

  case 24: /* paramsspec: paramspec  */
#line 191 "lang.y"
                                { (yyval.params_node) = new cParamsNode((yyvsp[0].param_node)); }
#line 1537 "langparse.c"
    break;

  case 25: /* paramspec: var_decl  */
#line 194 "lang.y"
                                { (yyval.param_node) = new cParamNode((cVarDeclNode*)(yyvsp[0].ast_node)); }
#line 1543 "langparse.c"
    break;

  case 26: /* stmts: stmts stmt  */
#line 197 "lang.y"
                                { (yyval.stmts_node) = (yyvsp[-1].stmts_node); (yyval.stmts_node)->Insert((cStmtNode*)(yyvsp[0].ast_node)); }
#line 1549 "langparse.c"
    break;

  case 27: /* stmts: stmt  */
#line 199 "lang.y"
                            { (yyval.stmts_node) = new cStmtsNode((cStmtNode*)(yyvsp[0].ast_node)); }
#line 1555 "langparse.c"
    break;

  case 28: /* stmt: IF '(' expr ')' stmts ENDIF ';'  */
#line 202 "lang.y"
                                {  }
#line 1561 "langparse.c"
    break;

  case 29: /* stmt: IF '(' expr ')' stmts ELSE stmts ENDIF ';'  */
#line 204 "lang.y"
                                {  }
#line 1567 "langparse.c"
    break;

  case 30: /* stmt: WHILE '(' expr ')' stmt  */
#line 206 "lang.y"
                                {  }
#line 1573 "langparse.c"
    break;

  case 31: /* stmt: PRINT '(' expr ')' ';'  */
#line 208 "lang.y"
                                { (yyval.ast_node) = new cPrintNode((yyvsp[-2].expr_node)); }
#line 1579 "langparse.c"
    break;

  case 32: /* stmt: PRINTS '(' STRING_LIT ')' ';'  */
#line 210 "lang.y"
                                { }
#line 1585 "langparse.c"
    break;

  case 33: /* stmt: lval '=' expr ';'  */
#line 212 "lang.y"
                            { (yyval.ast_node) = new cAssignNode((yyvsp[-3].ast_node), (yyvsp[-1].expr_node)); }
#line 1591 "langparse.c"
    break;

  case 34: /* stmt: func_call ';'  */
#line 214 "lang.y"
                            {  }
#line 1597 "langparse.c"
    break;

  case 35: /* stmt: block  */
#line 216 "lang.y"
                            {  }
#line 1603 "langparse.c"
    break;

  case 36: /* stmt: RETURN expr ';'  */
#line 218 "lang.y"
                            { (yyval.ast_node) = new cReturnNode((yyvsp[-1].expr_node)); }
#line 1609 "langparse.c"
    break;

  case 37: /* stmt: error ';'  */
#line 220 "lang.y"
                            {}
#line 1615 "langparse.c"
    break;

  case 38: /* func_call: IDENTIFIER '(' params ')'  */
#line 223 "lang.y"
                                { 
                                    (yyval.func_call_node) = new cFuncCallNode((yyvsp[-3].symbol), (yyvsp[-1].ast_node)); 
                                    CHECK_ERROR(); 
                                }
#line 1624 "langparse.c"
    break;

  case 39: /* func_call: IDENTIFIER '(' ')'  */
#line 228 "lang.y"
                                { 
                                    (yyval.func_call_node) = new cFuncCallNode((yyvsp[-2].symbol)); 
                                    CHECK_ERROR(); 
                                }
#line 1633 "langparse.c"
    break;

  case 40: /* varref: varref '.' varpart  */
#line 234 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-2].ast_node); ((cVarExprNode*)(yyval.ast_node))->AddSymbol((yyvsp[0].symbol)); }
#line 1639 "langparse.c"
    break;

  case 41: /* varref: varref '[' expr ']'  */
#line 236 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-3].ast_node); (yyval.ast_node)->AddChild((yyvsp[-1].expr_node)); }
#line 1645 "langparse.c"
    break;

  case 42: /* varref: varpart  */
#line 238 "lang.y"
                                { (yyval.ast_node) = new cVarExprNode((yyvsp[0].symbol)); }
#line 1651 "langparse.c"
    break;

  case 43: /* varpart: IDENTIFIER  */
#line 241 "lang.y"
                                { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1657 "langparse.c"
    break;

  case 44: /* lval: varref  */
#line 244 "lang.y"
                                {  }
#line 1663 "langparse.c"
    break;

  case 45: /* params: params ',' param  */
#line 247 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-2].ast_node); (yyval.ast_node)->AddChild((yyvsp[0].ast_node)); }
#line 1669 "langparse.c"
    break;

  case 46: /* params: param  */
#line 249 "lang.y"
                                { 
                                    (yyval.ast_node) = new cPrefixNode();
                                    (yyval.ast_node)->AddChild((yyvsp[0].ast_node));
                                }
#line 1678 "langparse.c"
    break;

  case 47: /* param: expr  */
#line 255 "lang.y"
                                { (yyval.ast_node) = (yyvsp[0].expr_node); }
#line 1684 "langparse.c"
    break;

  case 48: /* expr: expr OR andexpr  */
#line 258 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(OR), (yyvsp[0].expr_node)); }
#line 1690 "langparse.c"
    break;

  case 49: /* expr: andexpr  */
#line 260 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1696 "langparse.c"
    break;

  case 50: /* andexpr: andexpr AND relexpr  */
#line 263 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(AND), (yyvsp[0].expr_node)); }
#line 1702 "langparse.c"
    break;

  case 51: /* andexpr: relexpr  */
#line 265 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1708 "langparse.c"
    break;

  case 52: /* relexpr: relexpr EQUALS addit  */
#line 268 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(EQUALS), (yyvsp[0].expr_node)); }
#line 1714 "langparse.c"
    break;

  case 53: /* relexpr: relexpr NOT_EQUALS addit  */
#line 270 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(NOT_EQUALS), (yyvsp[0].expr_node)); }
#line 1720 "langparse.c"
    break;

  case 54: /* relexpr: relexpr '<' addit  */
#line 272 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('<'), (yyvsp[0].expr_node)); }
#line 1726 "langparse.c"
    break;

  case 55: /* relexpr: relexpr '>' addit  */
#line 274 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('>'), (yyvsp[0].expr_node)); }
#line 1732 "langparse.c"
    break;

  case 56: /* relexpr: relexpr LE addit  */
#line 276 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(LE), (yyvsp[0].expr_node)); }
#line 1738 "langparse.c"
    break;

  case 57: /* relexpr: relexpr GE addit  */
#line 278 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(GE), (yyvsp[0].expr_node)); }
#line 1744 "langparse.c"
    break;

  case 58: /* relexpr: addit  */
#line 280 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1750 "langparse.c"
    break;

  case 59: /* addit: addit '+' term  */
#line 283 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('+'), (yyvsp[0].expr_node)); }
#line 1756 "langparse.c"
    break;

  case 60: /* addit: addit '-' term  */
#line 285 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('-'), (yyvsp[0].expr_node)); }
#line 1762 "langparse.c"
    break;

  case 61: /* addit: term  */
#line 287 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1768 "langparse.c"
    break;

  case 62: /* term: term '*' unary  */
#line 290 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('*'), (yyvsp[0].expr_node)); }
#line 1774 "langparse.c"
    break;

  case 63: /* term: term '/' unary  */
#line 292 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('/'), (yyvsp[0].expr_node)); }
#line 1780 "langparse.c"
    break;

  case 64: /* term: term '%' unary  */
#line 294 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('%'), (yyvsp[0].expr_node)); }
#line 1786 "langparse.c"
    break;

  case 65: /* term: unary  */
#line 296 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1792 "langparse.c"
    break;

  case 66: /* unary: '-' unary  */
#line 299 "lang.y"
                                { (yyval.expr_node) = new cUnaryExprNode(new cOpNode('-'), (yyvsp[0].expr_node)); }
#line 1798 "langparse.c"
    break;

  case 67: /* unary: fact  */
#line 301 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1804 "langparse.c"
    break;

  case 68: /* fact: '(' expr ')'  */
#line 304 "lang.y"
                                { (yyval.expr_node) = (yyvsp[-1].expr_node); }
#line 1810 "langparse.c"
    break;

  case 69: /* fact: INT_VAL  */
#line 306 "lang.y"
                                { (yyval.expr_node) = new cIntExprNode((yyvsp[0].int_val)); }
#line 1816 "langparse.c"
    break;

  case 70: /* fact: FLOAT_VAL  */
#line 308 "lang.y"
                                { (yyval.expr_node) = new cFloatExprNode((yyvsp[0].float_val)); }
#line 1822 "langparse.c"
    break;

  case 71: /* fact: varref  */
#line 310 "lang.y"
                                { (yyval.expr_node) = (cExprNode*)(yyvsp[0].ast_node); }
#line 1828 "langparse.c"
    break;

  case 72: /* fact: func_call  */
#line 312 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].func_call_node); }
#line 1834 "langparse.c"
    break;


#line 1838 "langparse.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 314 "lang.y"


// Function to format error messages
int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

// Function that gets called when a semantic error happens
void SemanticParseError(std::string error)
{
    std::cout << "ERROR: " << error << " near line " 
              << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}
