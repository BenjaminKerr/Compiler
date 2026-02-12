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
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_block = 43,                     /* block  */
  YYSYMBOL_open = 44,                      /* open  */
  YYSYMBOL_close = 45,                     /* close  */
  YYSYMBOL_decls = 46,                     /* decls  */
  YYSYMBOL_decl = 47,                      /* decl  */
  YYSYMBOL_var_decl = 48,                  /* var_decl  */
  YYSYMBOL_struct_decl = 49,               /* struct_decl  */
  YYSYMBOL_array_decl = 50,                /* array_decl  */
  YYSYMBOL_func_decl = 51,                 /* func_decl  */
  YYSYMBOL_func_header = 52,               /* func_header  */
  YYSYMBOL_func_prefix = 53,               /* func_prefix  */
  YYSYMBOL_paramsspec = 54,                /* paramsspec  */
  YYSYMBOL_paramspec = 55,                 /* paramspec  */
  YYSYMBOL_stmts = 56,                     /* stmts  */
  YYSYMBOL_stmt = 57,                      /* stmt  */
  YYSYMBOL_func_call = 58,                 /* func_call  */
  YYSYMBOL_varref = 59,                    /* varref  */
  YYSYMBOL_varpart = 60,                   /* varpart  */
  YYSYMBOL_lval = 61,                      /* lval  */
  YYSYMBOL_params = 62,                    /* params  */
  YYSYMBOL_param = 63,                     /* param  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_addit = 65,                     /* addit  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_fact = 67                       /* fact  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 49 "lang.y"

    int yyerror(const char *msg);

    cAstNode *yyast_root;

#line 203 "langparse.c"


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
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

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
       2,     2,     2,     2,     2,     2,     2,    40,     2,     2,
      32,    31,    38,    36,    33,    37,    35,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,   106,   106,   114,   116,   119,   122,   125,   127,   129,
     131,   133,   135,   137,   140,   143,   145,   148,   150,   158,
     167,   173,   179,   185,   187,   190,   193,   195,   198,   200,
     202,   204,   206,   208,   210,   212,   214,   216,   219,   224,
     230,   232,   234,   237,   240,   243,   245,   251,   254,   256,
     259,   261,   263,   266,   268,   270,   272,   275,   277,   279,
     281,   283
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
  "'='", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept", "program",
  "block", "open", "close", "decls", "decl", "var_decl", "struct_decl",
  "array_decl", "func_decl", "func_header", "func_prefix", "paramsspec",
  "paramspec", "stmts", "stmt", "func_call", "varref", "varpart", "lval",
  "params", "param", "expr", "addit", "term", "fact", YY_NULLPTR
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
      93,    41,    40,    44,    61,    46,    43,    45,    42,    47,
      37
};
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -6,     5,    20,   -44,   -44,   165,   -44,     6,    39,    75,
      58,    67,    73,    74,     5,    78,    11,   -44,   165,   -44,
      79,    80,    81,   -44,    30,     8,   115,   -44,    82,    26,
     -44,    83,    86,     4,    87,    11,   110,    11,    11,    43,
      97,   -44,   -44,    11,   -44,    26,    41,    31,    54,   -44,
     -44,   115,   -44,   -44,   -44,   165,   -44,   126,   -44,   -44,
      29,   -44,   112,   -44,   -44,   -44,   -44,    11,   141,    11,
     -44,    48,   -44,   136,   -44,     7,   120,    10,    14,   122,
      50,   147,    18,    11,   -44,    11,    11,    11,    11,    11,
     -44,   165,   119,   -44,   -44,   148,   -44,    12,   -44,   -44,
      52,   -44,    11,   127,   128,   209,   209,   -44,   151,   129,
     -44,    31,    54,    54,   -44,   -44,   -44,   146,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   176,   -44,   154,   -44,
     209,   130,   -44,   198,   -44,   132,   -44
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
       0,    58,    59,     0,    61,    60,     0,    49,    52,    56,
       7,     0,     9,    11,    10,     0,    17,     0,    21,    25,
       0,    24,     0,     6,     4,    26,    34,     0,     0,     0,
      39,     0,    46,    47,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       3,     0,     0,    14,    20,     0,    37,     0,    43,    40,
       0,    38,     0,     0,     0,     0,     0,    13,     0,     0,
      57,    48,    50,    51,    53,    54,    55,     0,    19,    23,
      41,    33,    45,    31,    32,    30,     0,    15,     0,    18,
       0,     0,    16,     0,    28,     0,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   160,   153,   -43,   -23,   -17,   -20,   -44,   -44,
     -44,   -44,   -44,   -44,    76,   -15,   -22,    -5,    -3,   106,
     -44,   -44,    84,   -10,    92,    -1,     9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    17,     5,    64,    18,    19,    20,    21,    22,
      23,    24,    25,    60,    61,    26,    27,    44,    45,    30,
      31,    71,    72,    73,    47,    48,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    50,    29,    51,    65,    59,    46,     8,    90,     1,
      41,    42,    57,    28,     8,    29,    80,    41,    42,    83,
       6,    28,    83,    29,    83,    75,    83,    77,    78,    65,
      83,     3,    91,    82,    32,    70,    43,   108,   103,    58,
      92,   105,   120,    43,    79,   106,    28,     9,    29,   110,
      28,    79,    29,    83,     9,    67,    55,    97,    56,   100,
      94,    68,    95,    50,    83,    14,    15,    85,    86,    84,
      65,    33,    14,    15,    50,    59,   117,    63,    34,   101,
     121,   102,    40,   125,   112,   113,    28,    28,    29,    29,
      35,   126,    87,    88,    89,    65,   114,   115,   116,    36,
      28,    28,    29,    29,    65,    37,    38,    52,    53,    54,
      66,    65,    28,   -37,    29,   133,    62,    69,     8,    74,
      62,    28,     8,    29,    76,    28,    81,    29,    28,    93,
      29,    10,    11,    12,    13,    10,    11,    12,    13,    16,
      96,     3,    63,    16,    98,     3,   118,    62,    83,     8,
     107,   104,    57,   109,   127,   123,   124,   132,   134,   128,
     136,     4,    10,    11,    12,    13,     7,    39,     8,     9,
      16,   119,     3,   129,    99,   111,     0,    62,     0,     8,
       0,    10,    11,    12,    13,     0,   122,    14,    15,    16,
       0,     3,    10,    11,    12,    13,   130,   131,     0,    62,
      16,     8,     3,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     8,     0,    10,    11,    12,    13,     0,   135,
       0,     0,    16,     0,     3,    10,    11,    12,    13,     0,
       0,     0,     0,    16,     0,     3
};

static const yytype_int16 yycheck[] =
{
       5,    18,     5,    18,    26,    25,    16,     3,    51,    15,
       6,     7,     4,    18,     3,    18,    39,     6,     7,    12,
       0,    26,    12,    26,    12,    35,    12,    37,    38,    51,
      12,    26,    55,    43,    28,    31,    32,    80,    31,    31,
      55,    31,    30,    32,     1,    31,    51,     4,    51,    31,
      55,     1,    55,    12,     4,    29,    26,    67,    28,    69,
      31,    35,    33,    80,    12,    22,    23,    36,    37,    28,
      92,    32,    22,    23,    91,    95,    91,    27,     3,    31,
      28,    33,     4,   105,    85,    86,    91,    92,    91,    92,
      32,   106,    38,    39,    40,   117,    87,    88,    89,    32,
     105,   106,   105,   106,   126,    32,    32,    28,    28,    28,
      28,   133,   117,    27,   117,   130,     1,    34,     3,    32,
       1,   126,     3,   126,    14,   130,    29,   130,   133,     3,
     133,    16,    17,    18,    19,    16,    17,    18,    19,    24,
      28,    26,    27,    24,     3,    26,    27,     1,    12,     3,
      28,    31,     4,     6,     3,    28,    28,     3,    28,    30,
      28,     1,    16,    17,    18,    19,     1,    14,     3,     4,
      24,    95,    26,    27,    68,    83,    -1,     1,    -1,     3,
      -1,    16,    17,    18,    19,    -1,   102,    22,    23,    24,
      -1,    26,    16,    17,    18,    19,    20,    21,    -1,     1,
      24,     3,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,    -1,    16,    17,    18,    19,    -1,    21,
      -1,    -1,    24,    -1,    26,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    42,    26,    43,    44,     0,     1,     3,     4,
      16,    17,    18,    19,    22,    23,    24,    43,    46,    47,
      48,    49,    50,    51,    52,    53,    56,    57,    58,    59,
      60,    61,    28,    32,     3,    32,    32,    32,    32,    44,
       4,     6,     7,    32,    58,    59,    64,    65,    66,    67,
      47,    56,    28,    28,    28,    26,    28,     4,    31,    48,
      54,    55,     1,    27,    45,    57,    28,    29,    35,    34,
      31,    62,    63,    64,    32,    64,    14,    64,    64,     1,
      46,    29,    64,    12,    28,    36,    37,    38,    39,    40,
      45,    46,    56,     3,    31,    33,    28,    64,     3,    60,
      64,    31,    33,    31,    31,    31,    31,    28,    45,     6,
      31,    65,    66,    66,    67,    67,    67,    56,    27,    55,
      30,    28,    63,    28,    28,    57,    56,     3,    30,    27,
      20,    21,     3,    56,    28,    21,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    46,    46,    47,
      47,    47,    47,    47,    48,    49,    50,    51,    51,    51,
      52,    52,    53,    54,    54,    55,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    59,    60,    61,    62,    62,    63,    64,    64,
      65,    65,    65,    66,    66,    66,    66,    67,    67,    67,
      67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     4,     3,     1,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     5,     6,     2,     5,     4,
       3,     2,     3,     3,     1,     1,     2,     1,     7,     9,
       5,     5,     5,     4,     2,     1,     3,     2,     4,     3,
       3,     4,     1,     1,     1,     3,     1,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     1,     1,
       1,     1
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
#line 107 "lang.y"
                                { (yyval.program_node) = new cProgramNode((yyvsp[0].block_node));
                                  yyast_root = (yyval.program_node);
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
#line 1365 "langparse.c"
    break;

  case 3: /* block: open decls stmts close  */
#line 115 "lang.y"
                                { (yyval.block_node) = new cBlockNode((yyvsp[-2].decls_node), (yyvsp[-1].stmts_node)); }
#line 1371 "langparse.c"
    break;

  case 4: /* block: open stmts close  */
#line 117 "lang.y"
                                { (yyval.block_node) = new cBlockNode(nullptr, (yyvsp[-1].stmts_node)); }
#line 1377 "langparse.c"
    break;

  case 5: /* open: '{'  */
#line 120 "lang.y"
                                { g_symbolTable.IncreaseScope(); }
#line 1383 "langparse.c"
    break;

  case 6: /* close: '}'  */
#line 123 "lang.y"
                                { g_symbolTable.DecreaseScope(); }
#line 1389 "langparse.c"
    break;

  case 7: /* decls: decls decl  */
#line 126 "lang.y"
                                { (yyval.decls_node) = (yyvsp[-1].decls_node); (yyval.decls_node)->Insert((cDeclNode*)(yyvsp[0].ast_node)); }
#line 1395 "langparse.c"
    break;

  case 8: /* decls: decl  */
#line 128 "lang.y"
                                { (yyval.decls_node) = new cDeclsNode((cDeclNode*)(yyvsp[0].ast_node)); }
#line 1401 "langparse.c"
    break;

  case 9: /* decl: var_decl ';'  */
#line 130 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-1].ast_node); }
#line 1407 "langparse.c"
    break;

  case 10: /* decl: array_decl ';'  */
#line 132 "lang.y"
                            {  }
#line 1413 "langparse.c"
    break;

  case 11: /* decl: struct_decl ';'  */
#line 134 "lang.y"
                            {  }
#line 1419 "langparse.c"
    break;

  case 12: /* decl: func_decl  */
#line 136 "lang.y"
                            {  }
#line 1425 "langparse.c"
    break;

  case 13: /* decl: error ';'  */
#line 138 "lang.y"
                            {  }
#line 1431 "langparse.c"
    break;

  case 14: /* var_decl: TYPE_ID IDENTIFIER  */
#line 141 "lang.y"
                { (yyval.ast_node) = new cVarDeclNode((yyvsp[-1].symbol), (yyvsp[0].symbol)); 
                  CHECK_ERROR(); }
#line 1438 "langparse.c"
    break;

  case 15: /* struct_decl: STRUCT open decls close IDENTIFIER  */
#line 144 "lang.y"
                                {  }
#line 1444 "langparse.c"
    break;

  case 16: /* array_decl: ARRAY TYPE_ID '[' INT_VAL ']' IDENTIFIER  */
#line 146 "lang.y"
                                {  }
#line 1450 "langparse.c"
    break;

  case 17: /* func_decl: func_header ';'  */
#line 149 "lang.y"
                                { (yyval.func_decl_node) = (yyvsp[-1].func_decl_node); CHECK_ERROR(); }
#line 1456 "langparse.c"
    break;

  case 18: /* func_decl: func_header '{' decls stmts '}'  */
#line 151 "lang.y"
                                { 
                                    (yyval.func_decl_node) = (yyvsp[-4].func_decl_node);
                                    (yyval.func_decl_node)->AddChild((yyvsp[-1].stmts_node));  // Add stmts
                                    cSymbol* name = (cSymbol*)(yyval.func_decl_node)->GetChild(1);
                                    (yyval.func_decl_node)->CheckMultipleDefinitions(name);
                                    CHECK_ERROR(); 
                                }
#line 1468 "langparse.c"
    break;

  case 19: /* func_decl: func_header '{' stmts '}'  */
#line 159 "lang.y"
                                { 
                                    (yyval.func_decl_node) = (yyvsp[-3].func_decl_node);
                                    (yyval.func_decl_node)->AddChild((yyvsp[-1].stmts_node));  // Add stmts
                                    cSymbol* name = (cSymbol*)(yyval.func_decl_node)->GetChild(1);
                                    (yyval.func_decl_node)->CheckMultipleDefinitions(name);
                                    CHECK_ERROR(); 
                                }
#line 1480 "langparse.c"
    break;

  case 20: /* func_header: func_prefix paramsspec ')'  */
#line 168 "lang.y"
                                { 
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)(yyvsp[-2].ast_node))->GetChild(0);
                                    cSymbol *name = (cSymbol*)((cAstNode*)(yyvsp[-2].ast_node))->GetChild(1);
                                    (yyval.func_decl_node) = new cFuncDeclNode(returnType, name, (yyvsp[-1].params_node));
                                }
#line 1490 "langparse.c"
    break;

  case 21: /* func_header: func_prefix ')'  */
#line 174 "lang.y"
                                { 
                                    cSymbol *returnType = (cSymbol*)((cAstNode*)(yyvsp[-1].ast_node))->GetChild(0);
                                    cSymbol *name = (cSymbol*)((cAstNode*)(yyvsp[-1].ast_node))->GetChild(1);
                                    (yyval.func_decl_node) = new cFuncDeclNode(returnType, name, nullptr);
                                }
#line 1500 "langparse.c"
    break;

  case 22: /* func_prefix: TYPE_ID IDENTIFIER '('  */
#line 180 "lang.y"
                                { 
                                    (yyval.ast_node) = new cPrefixNode();
                                    (yyval.ast_node)->AddChild((yyvsp[-2].symbol));
                                    (yyval.ast_node)->AddChild((yyvsp[-1].symbol));
                                }
#line 1510 "langparse.c"
    break;

  case 23: /* paramsspec: paramsspec ',' paramspec  */
#line 186 "lang.y"
                                { (yyval.params_node) = (yyvsp[-2].params_node); (yyval.params_node)->AddParam((yyvsp[0].param_node)); }
#line 1516 "langparse.c"
    break;

  case 24: /* paramsspec: paramspec  */
#line 188 "lang.y"
                                { (yyval.params_node) = new cParamsNode((yyvsp[0].param_node)); }
#line 1522 "langparse.c"
    break;

  case 25: /* paramspec: var_decl  */
#line 191 "lang.y"
                                { (yyval.param_node) = new cParamNode((cVarDeclNode*)(yyvsp[0].ast_node)); }
#line 1528 "langparse.c"
    break;

  case 26: /* stmts: stmts stmt  */
#line 194 "lang.y"
                                { (yyval.stmts_node) = (yyvsp[-1].stmts_node); (yyval.stmts_node)->Insert((cStmtNode*)(yyvsp[0].ast_node)); }
#line 1534 "langparse.c"
    break;

  case 27: /* stmts: stmt  */
#line 196 "lang.y"
                            { (yyval.stmts_node) = new cStmtsNode((cStmtNode*)(yyvsp[0].ast_node)); }
#line 1540 "langparse.c"
    break;

  case 28: /* stmt: IF '(' expr ')' stmts ENDIF ';'  */
#line 199 "lang.y"
                                {  }
#line 1546 "langparse.c"
    break;

  case 29: /* stmt: IF '(' expr ')' stmts ELSE stmts ENDIF ';'  */
#line 201 "lang.y"
                                {  }
#line 1552 "langparse.c"
    break;

  case 30: /* stmt: WHILE '(' expr ')' stmt  */
#line 203 "lang.y"
                                {  }
#line 1558 "langparse.c"
    break;

  case 31: /* stmt: PRINT '(' expr ')' ';'  */
#line 205 "lang.y"
                                { (yyval.ast_node) = new cPrintNode((yyvsp[-2].expr_node)); }
#line 1564 "langparse.c"
    break;

  case 32: /* stmt: PRINTS '(' STRING_LIT ')' ';'  */
#line 207 "lang.y"
                                { }
#line 1570 "langparse.c"
    break;

  case 33: /* stmt: lval '=' expr ';'  */
#line 209 "lang.y"
                            {  }
#line 1576 "langparse.c"
    break;

  case 34: /* stmt: func_call ';'  */
#line 211 "lang.y"
                            {  }
#line 1582 "langparse.c"
    break;

  case 35: /* stmt: block  */
#line 213 "lang.y"
                            {  }
#line 1588 "langparse.c"
    break;

  case 36: /* stmt: RETURN expr ';'  */
#line 215 "lang.y"
                            { (yyval.ast_node) = new cReturnNode((yyvsp[-1].expr_node)); }
#line 1594 "langparse.c"
    break;

  case 37: /* stmt: error ';'  */
#line 217 "lang.y"
                            {}
#line 1600 "langparse.c"
    break;

  case 38: /* func_call: IDENTIFIER '(' params ')'  */
#line 220 "lang.y"
                                { 
                                    (yyval.func_call_node) = new cFuncCallNode((yyvsp[-3].symbol), (yyvsp[-1].ast_node)); 
                                    CHECK_ERROR(); 
                                }
#line 1609 "langparse.c"
    break;

  case 39: /* func_call: IDENTIFIER '(' ')'  */
#line 225 "lang.y"
                                { 
                                    (yyval.func_call_node) = new cFuncCallNode((yyvsp[-2].symbol)); 
                                    CHECK_ERROR(); 
                                }
#line 1618 "langparse.c"
    break;

  case 40: /* varref: varref '.' varpart  */
#line 231 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-2].ast_node); ((cVarExprNode*)(yyval.ast_node))->AddSymbol((yyvsp[0].symbol)); }
#line 1624 "langparse.c"
    break;

  case 41: /* varref: varref '[' expr ']'  */
#line 233 "lang.y"
                            { (yyval.ast_node) = (yyvsp[-3].ast_node); }
#line 1630 "langparse.c"
    break;

  case 42: /* varref: varpart  */
#line 235 "lang.y"
                            { (yyval.ast_node) = new cVarExprNode((yyvsp[0].symbol)); }
#line 1636 "langparse.c"
    break;

  case 43: /* varpart: IDENTIFIER  */
#line 238 "lang.y"
                                { (yyval.symbol) = (yyvsp[0].symbol); }
#line 1642 "langparse.c"
    break;

  case 44: /* lval: varref  */
#line 241 "lang.y"
                                {  }
#line 1648 "langparse.c"
    break;

  case 45: /* params: params ',' param  */
#line 244 "lang.y"
                                { (yyval.ast_node) = (yyvsp[-2].ast_node); (yyval.ast_node)->AddChild((yyvsp[0].ast_node)); }
#line 1654 "langparse.c"
    break;

  case 46: /* params: param  */
#line 246 "lang.y"
                                { 
                                    (yyval.ast_node) = new cPrefixNode();
                                    (yyval.ast_node)->AddChild((yyvsp[0].ast_node));
                                }
#line 1663 "langparse.c"
    break;

  case 47: /* param: expr  */
#line 252 "lang.y"
                                { (yyval.ast_node) = (yyvsp[0].expr_node); }
#line 1669 "langparse.c"
    break;

  case 48: /* expr: expr EQUALS addit  */
#line 255 "lang.y"
                                {  }
#line 1675 "langparse.c"
    break;

  case 49: /* expr: addit  */
#line 257 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1681 "langparse.c"
    break;

  case 50: /* addit: addit '+' term  */
#line 260 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('+'), (yyvsp[0].expr_node)); }
#line 1687 "langparse.c"
    break;

  case 51: /* addit: addit '-' term  */
#line 262 "lang.y"
                            { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('-'), (yyvsp[0].expr_node)); }
#line 1693 "langparse.c"
    break;

  case 52: /* addit: term  */
#line 264 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1699 "langparse.c"
    break;

  case 53: /* term: term '*' fact  */
#line 267 "lang.y"
                                { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('*'), (yyvsp[0].expr_node)); }
#line 1705 "langparse.c"
    break;

  case 54: /* term: term '/' fact  */
#line 269 "lang.y"
                            { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('/'), (yyvsp[0].expr_node)); }
#line 1711 "langparse.c"
    break;

  case 55: /* term: term '%' fact  */
#line 271 "lang.y"
                            { (yyval.expr_node) = new cBinaryExprNode((yyvsp[-2].expr_node), new cOpNode('%'), (yyvsp[0].expr_node)); }
#line 1717 "langparse.c"
    break;

  case 56: /* term: fact  */
#line 273 "lang.y"
                            { (yyval.expr_node) = (yyvsp[0].expr_node); }
#line 1723 "langparse.c"
    break;

  case 57: /* fact: '(' expr ')'  */
#line 276 "lang.y"
                                {  }
#line 1729 "langparse.c"
    break;

  case 58: /* fact: INT_VAL  */
#line 278 "lang.y"
                            { (yyval.expr_node) = new cIntExprNode((yyvsp[0].int_val)); }
#line 1735 "langparse.c"
    break;

  case 59: /* fact: FLOAT_VAL  */
#line 280 "lang.y"
                            { (yyval.expr_node) = new cFloatExprNode((yyvsp[0].float_val)); }
#line 1741 "langparse.c"
    break;

  case 60: /* fact: varref  */
#line 282 "lang.y"
                            { (yyval.expr_node) = (cExprNode*)(yyvsp[0].ast_node); }
#line 1747 "langparse.c"
    break;

  case 61: /* fact: func_call  */
#line 284 "lang.y"
                            {  }
#line 1753 "langparse.c"
    break;


#line 1757 "langparse.c"

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

#line 286 "lang.y"


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
