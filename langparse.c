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
  YYSYMBOL_55_1 = 55,                      /* $@1  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_func_prefix = 57,               /* func_prefix  */
  YYSYMBOL_paramsspec = 58,                /* paramsspec  */
  YYSYMBOL_paramspec = 59,                 /* paramspec  */
  YYSYMBOL_stmts = 60,                     /* stmts  */
  YYSYMBOL_stmt = 61,                      /* stmt  */
  YYSYMBOL_func_call = 62,                 /* func_call  */
  YYSYMBOL_varref = 63,                    /* varref  */
  YYSYMBOL_varpart = 64,                   /* varpart  */
  YYSYMBOL_lval = 65,                      /* lval  */
  YYSYMBOL_params = 66,                    /* params  */
  YYSYMBOL_param = 67,                     /* param  */
  YYSYMBOL_expr = 68,                      /* expr  */
  YYSYMBOL_andexpr = 69,                   /* andexpr  */
  YYSYMBOL_relexpr = 70,                   /* relexpr  */
  YYSYMBOL_addit = 71,                     /* addit  */
  YYSYMBOL_term = 72,                      /* term  */
  YYSYMBOL_unary = 73,                     /* unary  */
  YYSYMBOL_fact = 74                       /* fact  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 49 "lang.y"

    int yyerror(const char *msg);

    cAstNode *yyast_root;

#line 210 "langparse.c"


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
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

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
     134,   136,   138,   140,   143,   150,   152,   155,   157,   167,
     177,   177,   183,   183,   189,   195,   197,   200,   203,   205,
     208,   210,   212,   214,   216,   218,   220,   222,   224,   226,
     229,   234,   240,   242,   244,   247,   250,   253,   255,   261,
     264,   266,   269,   271,   274,   276,   278,   280,   282,   284,
     286,   289,   291,   293,   296,   298,   300,   302,   305,   307,
     310,   312,   314,   316,   318
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
  "struct_decl", "array_decl", "func_decl", "func_header", "$@1", "$@2",
  "func_prefix", "paramsspec", "paramspec", "stmts", "stmt", "func_call",
  "varref", "varpart", "lval", "params", "param", "expr", "andexpr",
  "relexpr", "addit", "term", "unary", "fact", YY_NULLPTR
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

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,   -19,    49,   -59,   -59,   177,   -59,    18,    21,    54,
      41,    61,    67,    74,   -19,    62,    32,   -59,   177,   -59,
      52,    88,    99,   -59,   -18,    59,    91,   -59,   100,    53,
     -59,    85,   102,    38,   101,    32,   121,    32,    32,    25,
     107,   -59,   -59,    32,    32,   -59,    53,    44,   127,    66,
      46,   -22,   -59,   -59,   -59,    91,   -59,   -59,   -59,   177,
     -59,   143,   114,   122,   -59,   -59,   -59,   -59,    32,   149,
      32,   -59,    34,   -59,   151,   -59,     1,   139,     3,     5,
     144,   165,   167,     6,   -59,    32,   -59,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,   -59,
     177,   137,   168,   -59,    58,   -59,   -59,   -59,    13,   -59,
     -59,    48,   -59,    32,   146,   147,   221,   221,   -59,   173,
     152,   -59,   127,    66,    46,    46,    46,    46,    46,    46,
     -22,   -22,   -59,   -59,   -59,   141,   -59,   -59,   -59,   143,
     -59,   -59,   -59,   -59,   -59,   -59,   188,   -59,   174,   -59,
     -59,   221,   155,   -59,   210,   -59,   156,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     2,     0,     1,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     8,
       0,     0,     0,    12,     0,    20,     0,    29,     0,    46,
      44,     0,    13,     0,    14,     0,     0,     0,     0,     0,
       0,    71,    72,     0,     0,    74,    73,     0,    51,    53,
      60,    63,    67,    69,     7,     0,     9,    11,    10,     0,
      17,     0,     0,     0,     6,     4,    28,    36,     0,     0,
       0,    41,     0,    48,    49,    24,     0,     0,     0,     0,
       0,     0,     0,     0,    68,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
       0,     0,     0,    27,     0,    26,    23,    39,     0,    45,
      42,     0,    40,     0,     0,     0,     0,     0,    13,     0,
       0,    70,    50,    52,    58,    59,    54,    55,    56,    57,
      61,    62,    64,    65,    66,     0,    19,    14,    21,     0,
      43,    35,    47,    33,    34,    32,     0,    15,     0,    18,
      25,     0,     0,    16,     0,    30,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   178,   171,   -51,    -8,   -13,   -58,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,    47,   -17,   -15,    -5,
      -3,   128,   -59,   -59,    77,   -10,   113,   115,    33,    10,
     -35,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    17,     5,    65,    18,    19,    20,    21,    22,
      23,    24,    61,    62,    25,   104,   105,    26,    27,    45,
      46,    30,    31,    72,    73,    74,    48,    49,    50,    51,
      52,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    55,    29,   103,    99,    54,    47,     3,    59,    84,
      60,    66,    85,    28,    85,    29,    85,    85,    96,    97,
      98,    28,     1,    29,    85,    76,    80,    78,    79,     9,
     119,    81,   114,    83,   116,     8,   117,   121,    41,    42,
      66,     8,   101,   140,    41,    42,    32,    14,    15,     6,
      28,   100,    29,    33,    28,    85,    29,    34,   108,    85,
     111,   132,   133,   134,    43,   112,    40,   113,    54,    71,
      43,    44,    86,    35,    88,    89,   141,    44,    90,    91,
      56,   103,    68,   135,    94,    95,    66,    54,    69,   138,
     -22,   139,    63,    36,     8,    28,    28,    29,    29,    37,
     146,   145,    92,    93,   130,   131,    38,    10,    11,    12,
      13,    28,    28,    29,    29,    16,    57,     3,    64,    70,
      66,   124,   125,   126,   127,   128,   129,    58,    67,   -39,
      28,    66,    29,    75,   154,    77,    82,    87,    63,    66,
       8,    28,    63,    29,     8,   106,    28,   102,    29,    28,
     107,    29,   109,    10,    11,    12,    13,    10,    11,    12,
      13,    16,    85,     3,   136,    16,    80,     3,   149,     9,
     115,   137,   118,   120,   143,   144,   147,   153,     7,     4,
       8,     9,   148,   155,   157,    39,   150,    14,    15,    63,
     142,     8,    64,    10,    11,    12,    13,   110,   122,    14,
      15,    16,   123,     3,    10,    11,    12,    13,   151,   152,
       0,    63,    16,     8,     3,     0,     0,     0,     0,     0,
       0,     0,    63,     0,     8,     0,    10,    11,    12,    13,
       0,   156,     0,     0,    16,     0,     3,    10,    11,    12,
      13,     0,     0,     0,     0,    16,     0,     3
};

static const yytype_int16 yycheck[] =
{
       5,    18,     5,    61,    55,    18,    16,    26,    26,    44,
      28,    26,    11,    18,    11,    18,    11,    11,    40,    41,
      42,    26,    15,    26,    11,    35,     1,    37,    38,     4,
      81,    39,    31,    43,    31,     3,    31,    31,     6,     7,
      55,     3,    59,    30,     6,     7,    28,    22,    23,     0,
      55,    59,    55,    32,    59,    11,    59,     3,    68,    11,
      70,    96,    97,    98,    32,    31,     4,    33,    81,    31,
      32,    39,    28,    32,     8,     9,    28,    39,    12,    13,
      28,   139,    29,   100,    38,    39,   101,   100,    35,    31,
      31,    33,     1,    32,     3,   100,   101,   100,   101,    32,
     117,   116,    36,    37,    94,    95,    32,    16,    17,    18,
      19,   116,   117,   116,   117,    24,    28,    26,    27,    34,
     135,    88,    89,    90,    91,    92,    93,    28,    28,    27,
     135,   146,   135,    32,   151,    14,    29,    10,     1,   154,
       3,   146,     1,   146,     3,    31,   151,     4,   151,   154,
      28,   154,     3,    16,    17,    18,    19,    16,    17,    18,
      19,    24,    11,    26,    27,    24,     1,    26,    27,     4,
      31,     3,    28,     6,    28,    28,     3,     3,     1,     1,
       3,     4,    30,    28,    28,    14,   139,    22,    23,     1,
     113,     3,    27,    16,    17,    18,    19,    69,    85,    22,
      23,    24,    87,    26,    16,    17,    18,    19,    20,    21,
      -1,     1,    24,     3,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,    -1,    16,    17,    18,    19,
      -1,    21,    -1,    -1,    24,    -1,    26,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    24,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    44,    26,    45,    46,     0,     1,     3,     4,
      16,    17,    18,    19,    22,    23,    24,    45,    48,    49,
      50,    51,    52,    53,    54,    57,    60,    61,    62,    63,
      64,    65,    28,    32,     3,    32,    32,    32,    32,    46,
       4,     6,     7,    32,    39,    62,    63,    68,    69,    70,
      71,    72,    73,    74,    49,    60,    28,    28,    28,    26,
      28,    55,    56,     1,    27,    47,    61,    28,    29,    35,
      34,    31,    66,    67,    68,    32,    68,    14,    68,    68,
       1,    48,    29,    68,    73,    11,    28,    10,     8,     9,
      12,    13,    36,    37,    38,    39,    40,    41,    42,    47,
      48,    60,     4,    50,    58,    59,    31,    28,    68,     3,
      64,    68,    31,    33,    31,    31,    31,    31,    28,    47,
       6,    31,    69,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    73,    60,    27,     3,    31,    33,
      30,    28,    67,    28,    28,    61,    60,     3,    30,    27,
      59,    20,    21,     3,    60,    28,    21,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    47,    48,    48,    49,
      49,    49,    49,    49,    50,    51,    52,    53,    53,    53,
      55,    54,    56,    54,    57,    58,    58,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    63,    64,    65,    66,    66,    67,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    72,    72,    72,    72,    73,    73,
      74,    74,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     3,     1,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     5,     6,     2,     5,     4,
       0,     4,     0,     3,     3,     3,     1,     1,     2,     1,
       7,     9,     5,     5,     5,     4,     2,     1,     3,     2,
       4,     3,     3,     4,     1,     1,     1,     3,     1,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     1,
       3,     1,     1,     1,     1
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
#line 1386 "langparse.c"
    break;

  case 3: /* block: open decls stmts close  */
#line 118 "lang.y"
                                { (yyval.block_node) = new cBlockNode((yyvsp[-2].decls_node), (yyvsp[-1].stmts_node)); }
#line 1392 "langparse.c"
    break;

  case 4: /* block: open stmts close  */
#line 120 "lang.y"
                                { (yyval.block_node) = new cBlockNode(nullptr, (yyvsp[-1].stmts_node)); }
#line 1398 "langparse.c"
    break;

  case 5: /* open: '{'  */
#line 123 "lang.y"
                                { g_symbolTable.IncreaseScope(); }
#line 1404 "langparse.c"
    break;

  case 6: /* close: '}'  */
#line 126 "lang.y"
                                { g_symbolTable.DecreaseScope(); }
#line 1410 "langparse.c"
    break;

  case 7: /* decls: decls decl  */
#line 129 "lang.y"
                                { (yyval.decls_node) = (yyvsp[-1].decls_node); (yyval.decls_node)->Insert((cDeclNode*)(yyvsp[0].ast_node)); }
#line 1416 "langparse.c"
    break;

  case 8: /* decls: decl  */
#line 131 "lang.y"
                                { (yyval.decls_node) = new cDeclsNode((cDeclNode*)(yyvsp[0].ast_node)); }
#line 1422 "langparse.c"
    break;

  case 9: /* decl: var_decl ';'  */
#line 133 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1428 "langparse.c"
    break;

  case 10: /* decl: array_decl ';'  */
#line 135 "lang.y"
                            {  }
#line 1434 "langparse.c"
    break;

  case 11: /* decl: struct_decl ';'  */
#line 137 "lang.y"
                            {  }
#line 1440 "langparse.c"
    break;

  case 12: /* decl: func_decl  */
#line 139 "lang.y"
                            {  }
#line 1446 "langparse.c"
    break;

  case 13: /* decl: error ';'  */
#line 141 "lang.y"
                            {  }
#line 1452 "langparse.c"
    break;

  case 14: /* var_decl: TYPE_ID IDENTIFIER  */
#line 144 "lang.y"
                { 
                  cSymbol* fresh = new cSymbol((yyvsp[0].symbol)->GetName());
                  g_symbolTable.Insert(fresh);
                  (yyval.ast_node) = new cVarDeclNode((yyvsp[-1].symbol), fresh);
                  CHECK_ERROR();
                }
#line 1463 "langparse.c"
    break;

  case 15: /* struct_decl: STRUCT open decls close IDENTIFIER  */
#line 151 "lang.y"
                                {  }
#line 1469 "langparse.c"
    break;

  case 16: /* array_decl: ARRAY TYPE_ID '[' INT_VAL ']' IDENTIFIER  */
#line 153 "lang.y"
                                { (yyval.ast_node) = new cArrayDeclNode((yyvsp[-4].symbol), (yyvsp[-2].int_val), (yyvsp[0].symbol)); }
#line 1475 "langparse.c"
    break;

  case 17: /* func_decl: func_header ';'  */
#line 156 "lang.y"
                                { g_symbolTable.DecreaseScope(); (yyval.func_decl_node) = (yyvsp[-1].func_decl_node); CHECK_ERROR(); }
#line 1481 "langparse.c"
    break;

  case 18: /* func_decl: func_header '{' decls stmts '}'  */
#line 158 "lang.y"
                                {
                                    (yyval.func_decl_node) = (yyvsp[-4].func_decl_node);
                                    (yyval.func_decl_node)->AddChild((yyvsp[-2].decls_node));
                                    (yyval.func_decl_node)->AddChild((yyvsp[-1].stmts_node));
                                    cSymbol* name = (cSymbol*)(yyval.func_decl_node)->GetChild(1);
                                    (yyval.func_decl_node)->CheckMultipleDefinitions(name);
                                    g_symbolTable.DecreaseScope();
                                    CHECK_ERROR();
                                }
#line 1495 "langparse.c"
    break;

  case 19: /* func_decl: func_header '{' stmts '}'  */
#line 168 "lang.y"
                                {
                                    (yyval.func_decl_node) = (yyvsp[-3].func_decl_node);
                                    (yyval.func_decl_node)->AddChild((yyvsp[-1].stmts_node));
                                    cSymbol* name = (cSymbol*)(yyval.func_decl_node)->GetChild(1);
                                    (yyval.func_decl_node)->CheckMultipleDefinitions(name);
                                    g_symbolTable.DecreaseScope();
                                    CHECK_ERROR();
                                }
#line 1508 "langparse.c"
    break;

  case 20: /* $@1: %empty  */
#line 177 "lang.y"
                         { g_symbolTable.IncreaseScope(); }
#line 1514 "langparse.c"
    break;

  case 21: /* func_header: func_prefix $@1 paramsspec ')'  */
#line 178 "lang.y"
                                {
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)(yyvsp[-3].ast_node))->GetChild(0);
                                    cSymbol *name = (cSymbol*)((cAstNode*)(yyvsp[-3].ast_node))->GetChild(1);
                                    (yyval.func_decl_node) = new cFuncDeclNode(returnType, name, (yyvsp[-1].params_node));
                                }
#line 1524 "langparse.c"
    break;

  case 22: /* $@2: %empty  */
#line 183 "lang.y"
                         { g_symbolTable.IncreaseScope(); }
#line 1530 "langparse.c"
    break;

  case 23: /* func_header: func_prefix $@2 ')'  */
#line 184 "lang.y"
                                {
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)(yyvsp[-2].ast_node))->GetChild(0);
                                    cSymbol *name = (cSymbol*)((cAstNode*)(yyvsp[-2].ast_node))->GetChild(1);
                                    (yyval.func_decl_node) = new cFuncDeclNode(returnType, name, nullptr);
                                }
#line 1540 "langparse.c"
    break;

  case 24: /* func_prefix: TYPE_ID IDENTIFIER '('  */
#line 190 "lang.y"
                                {
                                    (yyval.ast_node) = new cPrefixNode();
                                    (yyval.ast_node)->AddChild((yyvsp[-2].symbol));
                                    (yyval.ast_node)->AddChild((yyvsp[-1].symbol));
                                }
#line 1550 "langparse.c"
    break;

  case 25: /* paramsspec: paramsspec ',' paramspec  */
#line 196 "lang.y"
                                { (yyval.params_node) = (yyvsp[-2].params_node); (yyval.params_node)->AddChild((yyvsp[0].ast_node)); }
#line 1556 "langparse.c"
    break;

  case 26: /* paramsspec: paramspec  */
#line 198 "lang.y"
                                { (yyval.params_node) = new cParamsNode((yyvsp[0].ast_node)); }
#line 1562 "langparse.c"
    break;

  case 27: /* paramspec: var_decl  */
#line 201 "lang.y"
                                { (yyval.ast_node) = (yyvsp[0].ast_node); }
#line 1568 "langparse.c"
    break;

  case 28: /* stmts: stmts stmt  */
#line 204 "lang.y"
                                { (yyval.stmts_node) = (yyvsp[-1].stmts_node); (yyval.stmts_node)->Insert((cStmtNode*)(yyvsp[0].ast_node)); }
#line 1574 "langparse.c"
    break;

  case 29: /* stmts: stmt  */
#line 206 "lang.y"
                            { (yyval.stmts_node) = new cStmtsNode((cStmtNode*)(yyvsp[0].ast_node)); }
#line 1580 "langparse.c"
    break;

  case 30: /* stmt: IF '(' expr ')' stmts ENDIF ';'  */
#line 209 "lang.y"
                                {  }
#line 1586 "langparse.c"
    break;

  case 31: /* stmt: IF '(' expr ')' stmts ELSE stmts ENDIF ';'  */
#line 211 "lang.y"
                                {  }
#line 1592 "langparse.c"
    break;

  case 32: /* stmt: WHILE '(' expr ')' stmt  */
#line 213 "lang.y"
                                {  }
#line 1598 "langparse.c"
    break;

  case 33: /* stmt: PRINT '(' expr ')' ';'  */
#line 215 "lang.y"
                                { (yyval.ast_node) = new cPrintNode((yyvsp[-2].expr_node)); }
#line 1604 "langparse.c"
    break;

  case 34: /* stmt: PRINTS '(' STRING_LIT ')' ';'  */
#line 217 "lang.y"
                                { }
#line 1610 "langparse.c"
    break;

  case 35: /* stmt: lval '=' expr ';'  */
#line 219 "lang.y"
                            { (yyval.ast_node) = new cAssignNode((yyvsp[-3].ast_node), (yyvsp[-1].expr_node)); }
#line 1616 "langparse.c"
    break;

  case 36: /* stmt: func_call ';'  */
#line 221 "lang.y"
                            {  }
#line 1622 "langparse.c"
    break;

  case 37: /* stmt: block  */
#line 223 "lang.y"
                            {  }
#line 1628 "langparse.c"
    break;

  case 38: /* stmt: RETURN expr ';'  */
#line 225 "lang.y"
                            { (yyval.ast_node) = new cReturnNode((yyvsp[-1].expr_node)); }
#line 1634 "langparse.c"
    break;

  case 39: /* stmt: error ';'  */
#line 227 "lang.y"
                            {}
#line 1640 "langparse.c"
    break;

  case 40: /* func_call: IDENTIFIER '(' params ')'  */
#line 230 "lang.y"
                                { 
                                    (yyval.func_call_node) = new cFuncCallNode((yyvsp[-3].symbol), (yyvsp[-1].ast_node)); 
                                    CHECK_ERROR(); 
                                }
#line 1649 "langparse.c"
    break;

  case 41: /* func_call: IDENTIFIER '(' ')'  */
#line 235 "lang.y"
                                { 
                                    (yyval.func_call_node) = new cFuncCallNode((yyvsp[-2].symbol)); 
                                    CHECK_ERROR(); 
                                }
#line 1658 "langparse.c"
    break;

  case 42: /* varref: varref '.' varpart  */
#line 241 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-2].ast_node); ((cVarExprNode*)(yyval.ast_node))->AddSymbol((yyvsp[0].symbol)); }
#line 1664 "langparse.c"
    break;

  case 43: /* varref: varref '[' expr ']'  */
#line 243 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-3].ast_node); (yyval.ast_node)->AddChild((yyvsp[-1].expr_node)); }
#line 1670 "langparse.c"
    break;

  case 44: /* varref: varpart  */
#line 245 "lang.y"
                                { (yyval.ast_node) = new cVarExprNode((yyvsp[0].symbol)); }
#line 1676 "langparse.c"
    break;

  case 45: /* varpart: IDENTIFIER  */
#line 248 "lang.y"
                                { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1682 "langparse.c"
    break;

  case 46: /* lval: varref  */
#line 251 "lang.y"
                                {  }
#line 1688 "langparse.c"
    break;

  case 47: /* params: params ',' param  */
#line 254 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-2].ast_node); (yyval.ast_node)->AddChild((yyvsp[0].ast_node)); }
#line 1694 "langparse.c"
    break;

  case 48: /* params: param  */
#line 256 "lang.y"
                                { 
                                    (yyval.ast_node) = new cPrefixNode();
                                    (yyval.ast_node)->AddChild((yyvsp[0].ast_node));
                                }
#line 1703 "langparse.c"
    break;

  case 49: /* param: expr  */
#line 262 "lang.y"
                                { (yyval.ast_node) = (yyvsp[0].expr_node); }
#line 1709 "langparse.c"
    break;

  case 50: /* expr: expr OR andexpr  */
#line 265 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(OR), (yyvsp[0].expr_node)); }
#line 1715 "langparse.c"
    break;

  case 51: /* expr: andexpr  */
#line 267 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1721 "langparse.c"
    break;

  case 52: /* andexpr: andexpr AND relexpr  */
#line 270 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(AND), (yyvsp[0].expr_node)); }
#line 1727 "langparse.c"
    break;

  case 53: /* andexpr: relexpr  */
#line 272 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1733 "langparse.c"
    break;

  case 54: /* relexpr: relexpr EQUALS addit  */
#line 275 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(EQUALS), (yyvsp[0].expr_node)); }
#line 1739 "langparse.c"
    break;

  case 55: /* relexpr: relexpr NOT_EQUALS addit  */
#line 277 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(NOT_EQUALS), (yyvsp[0].expr_node)); }
#line 1745 "langparse.c"
    break;

  case 56: /* relexpr: relexpr '<' addit  */
#line 279 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('<'), (yyvsp[0].expr_node)); }
#line 1751 "langparse.c"
    break;

  case 57: /* relexpr: relexpr '>' addit  */
#line 281 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('>'), (yyvsp[0].expr_node)); }
#line 1757 "langparse.c"
    break;

  case 58: /* relexpr: relexpr LE addit  */
#line 283 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(LE), (yyvsp[0].expr_node)); }
#line 1763 "langparse.c"
    break;

  case 59: /* relexpr: relexpr GE addit  */
#line 285 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode(GE), (yyvsp[0].expr_node)); }
#line 1769 "langparse.c"
    break;

  case 60: /* relexpr: addit  */
#line 287 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1775 "langparse.c"
    break;

  case 61: /* addit: addit '+' term  */
#line 290 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('+'), (yyvsp[0].expr_node)); }
#line 1781 "langparse.c"
    break;

  case 62: /* addit: addit '-' term  */
#line 292 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('-'), (yyvsp[0].expr_node)); }
#line 1787 "langparse.c"
    break;

  case 63: /* addit: term  */
#line 294 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1793 "langparse.c"
    break;

  case 64: /* term: term '*' unary  */
#line 297 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('*'), (yyvsp[0].expr_node)); }
#line 1799 "langparse.c"
    break;

  case 65: /* term: term '/' unary  */
#line 299 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('/'), (yyvsp[0].expr_node)); }
#line 1805 "langparse.c"
    break;

  case 66: /* term: term '%' unary  */
#line 301 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('%'), (yyvsp[0].expr_node)); }
#line 1811 "langparse.c"
    break;

  case 67: /* term: unary  */
#line 303 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1817 "langparse.c"
    break;

  case 68: /* unary: '-' unary  */
#line 306 "lang.y"
                                { (yyval.expr_node) = new cUnaryExprNode(new cOpNode('-'), (yyvsp[0].expr_node)); }
#line 1823 "langparse.c"
    break;

  case 69: /* unary: fact  */
#line 308 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1829 "langparse.c"
    break;

  case 70: /* fact: '(' expr ')'  */
#line 311 "lang.y"
                                { (yyval.expr_node) = (yyvsp[-1].expr_node); }
#line 1835 "langparse.c"
    break;

  case 71: /* fact: INT_VAL  */
#line 313 "lang.y"
                                { (yyval.expr_node) = new cIntExprNode((yyvsp[0].int_val)); }
#line 1841 "langparse.c"
    break;

  case 72: /* fact: FLOAT_VAL  */
#line 315 "lang.y"
                                { (yyval.expr_node) = new cFloatExprNode((yyvsp[0].float_val)); }
#line 1847 "langparse.c"
    break;

  case 73: /* fact: varref  */
#line 317 "lang.y"
                                { (yyval.expr_node) = (cExprNode*)(yyvsp[0].ast_node); }
#line 1853 "langparse.c"
    break;

  case 74: /* fact: func_call  */
#line 319 "lang.y"
                                { (yyval.expr_node) = (yyvsp[0].func_call_node); }
#line 1859 "langparse.c"
    break;


#line 1863 "langparse.c"

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

#line 321 "lang.y"


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
