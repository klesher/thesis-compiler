/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 8 "aol.y" /* yacc.c:339  */

    #include <stdio.h>
    #include <stdlib.h>
    #include "aol.h"

    int yylex(void);
    int yyparse(void);

    int debug = 0;

#line 77 "aol.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "aol.tab.h".  */
#ifndef YY_YY_AOL_TAB_H_INCLUDED
# define YY_YY_AOL_TAB_H_INCLUDED
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
    INTEGER = 258,
    DOUBLE = 259,
    STRING = 260,
    LONGDIRECTION = 261,
    LATDIRECTION = 262,
    TEMPERATUREUNITS = 263,
    DISTANCEUNITS = 264,
    VELOCITYUNITS = 265,
    DIRECTION = 266,
    CATALOG = 267,
    K_TELESCOPEID = 268,
    K_TELESCOPE = 269,
    K_NAME = 270,
    K_BRAND = 271,
    K_MODEL = 272,
    K_TYPE = 273,
    K_APERTURE = 274,
    K_FOCALLENGTH = 275,
    K_FOCALRATIO = 276,
    K_MOUNT = 277,
    K_OBSERVATION = 278,
    K_TIME = 279,
    K_LOCATION = 280,
    K_LONGITUDE = 281,
    K_SEEING = 282,
    K_TRANSPARENCY = 283,
    K_WEATHER = 284,
    K_TEMPERATURE = 285,
    K_HUMIDITY = 286,
    K_WIND = 287,
    K_TARGET = 288,
    K_DESIGNATION = 289,
    K_CONSTELLATION = 290,
    K_RIGHTASCENSION = 291,
    K_DECLINATION = 292,
    K_ALTITUDE = 293,
    K_AZIMUTH = 294,
    K_FILTER = 295,
    K_MAGNITUDE = 296,
    K_EYEPIECE = 297,
    K_DIRECTORY = 298,
    K_IMAGE = 299,
    K_NOTE = 300,
    K_LATITUDE = 301,
    K_TO = 302,
    K_H = 303,
    K_M = 304,
    K_S = 305,
    K_NGC = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "aol.y" /* yacc.c:355  */

    int i;
    double d;
    char* str;

    struct ast *a;

    /* Unnecessary without a symbol table */
    /*struct symbol *s;
     *struct symlist *sl; */

#line 181 "aol.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_AOL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "aol.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    61,     2,     2,    56,     2,    60,
       2,     2,     2,    58,     2,    62,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    54,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    74,    80,    81,    84,    85,    88,    93,
      94,    96,   100,   101,   102,   103,   104,   105,   106,   107,
     110,   111,   115,   117,   120,   121,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   138,
     140,   143,   146,   149,   150,   153,   156,   157,   158,   161,
     162,   163,   167,   168,   171,   173,   175,   178,   179,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   196,   197,   199,   200,   203,   204,   207,   208,   209,
     211,   212,   214,   215,   217,   218,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "DOUBLE", "STRING",
  "LONGDIRECTION", "LATDIRECTION", "TEMPERATUREUNITS", "DISTANCEUNITS",
  "VELOCITYUNITS", "DIRECTION", "CATALOG", "K_TELESCOPEID", "K_TELESCOPE",
  "K_NAME", "K_BRAND", "K_MODEL", "K_TYPE", "K_APERTURE", "K_FOCALLENGTH",
  "K_FOCALRATIO", "K_MOUNT", "K_OBSERVATION", "K_TIME", "K_LOCATION",
  "K_LONGITUDE", "K_SEEING", "K_TRANSPARENCY", "K_WEATHER",
  "K_TEMPERATURE", "K_HUMIDITY", "K_WIND", "K_TARGET", "K_DESIGNATION",
  "K_CONSTELLATION", "K_RIGHTASCENSION", "K_DECLINATION", "K_ALTITUDE",
  "K_AZIMUTH", "K_FILTER", "K_MAGNITUDE", "K_EYEPIECE", "K_DIRECTORY",
  "K_IMAGE", "K_NOTE", "K_LATITUDE", "K_TO", "K_H", "K_M", "K_S", "K_NGC",
  "'{'", "'}'", "'f'", "'/'", "'%'", "':'", "'+'", "'o'", "'\\''", "'\"'",
  "'-'", "$accept", "start", "infoTypes", "infoType", "telescopeStmt",
  "teleOptStmts", "teleOptStmt", "size", "observationStmt", "date",
  "observationOptStmts", "observationOptStmt", "time", "latitude",
  "longitude", "coordinate", "hourMinSec", "arcDegree", "degree",
  "temperature", "wind", "optTargetStmts", "optTargetStmt", "catalog",
  "magnitude", "optImgStmts", "optImgStmt", "optString", "optStmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   123,   125,   102,    47,    37,    58,    43,   111,
      39,    34,    45
};
# endif

#define YYPACT_NINF -146

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-146)))

#define YYTABLE_NINF -6

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,  -146,    11,    10,    65,  -146,    -5,  -146,  -146,   -29,
      12,    -4,  -146,  -146,    23,    68,    62,    70,    71,    72,
      43,    43,    24,    74,    75,    28,    23,  -146,    27,    93,
      92,    -1,    95,    96,    97,    48,    50,   100,   101,    -1,
      47,    62,  -146,  -146,  -146,  -146,   102,   103,  -146,  -146,
      46,  -146,  -146,  -146,  -146,   106,    56,  -146,  -146,    57,
      58,    52,    55,  -146,    99,  -146,  -146,  -146,  -146,  -146,
     107,   110,  -146,    63,    64,   104,  -146,    69,  -146,   115,
    -146,  -146,  -146,  -146,    66,  -146,   120,   121,  -146,    67,
      73,    76,    77,  -146,  -146,  -146,  -146,  -146,     8,    -7,
    -146,  -146,  -146,    78,    79,   124,  -146,   125,  -146,  -146,
    -146,  -146,   126,   128,    93,   -39,   129,   127,     2,    -1,
      -1,   132,     4,    17,   133,    87,    -7,  -146,   138,   139,
      82,    84,  -146,  -146,  -146,  -146,  -146,    21,  -146,    81,
    -146,   142,   143,  -146,  -146,  -146,  -146,  -146,   144,   145,
    -146,   146,   146,    98,  -146,  -146,    90,    94,   149,   150,
    -146,  -146,   153,  -146,  -146,  -146,  -146,  -146,    29,   154,
    -146,   105,   108,   109,   156,   111,    29,  -146,  -146,  -146,
    -146,   155,   146,  -146,  -146,   112,  -146,  -146
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     0,     2,     5,     6,     7,     0,
       0,     0,     1,     4,    10,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    38,    11,    12,    13,     0,     0,    14,    15,
       0,    18,    86,     8,     9,     0,     0,    26,    27,     0,
       0,     0,     0,    29,     0,    43,    44,    31,    32,    30,
       0,     0,    33,     0,     0,     0,    36,     0,    28,     0,
      22,    24,    21,    20,     0,    23,     0,     0,    51,     0,
       0,     0,     0,    42,    53,    52,    35,    34,     0,    58,
      41,    17,    16,    40,     0,     0,    49,     0,    50,    56,
      55,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    74,     0,     0,
       0,     0,    70,    60,    59,    75,    76,     0,    63,     0,
      64,     0,     0,    65,    66,    67,    68,    79,     0,     0,
      69,    85,    85,     0,    37,    57,     0,     0,     0,     0,
      62,    61,     0,    77,    78,    84,    72,    71,    81,     0,
      48,     0,     0,     0,     0,     0,    81,    83,    39,    46,
      47,     0,    85,    73,    80,     0,    82,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,   157,  -146,  -146,   141,  -146,   -20,  -146,  -146,
     130,  -146,    51,  -146,  -146,   -35,  -146,    54,  -146,  -146,
    -146,    42,  -146,  -146,  -146,    -6,  -146,  -145,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    25,    26,    48,     8,    11,
      40,    41,    57,    78,    63,    64,   140,    65,    66,    72,
      76,   125,   126,   137,   150,   175,   176,   166,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    49,    59,    60,    79,    59,   112,   167,   147,     2,
     135,   113,   136,    10,   109,   110,     9,   114,     3,   111,
      46,    47,   151,    14,   160,    42,   161,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   186,    24,    17,
      18,    19,    20,    21,    22,    23,    46,    47,    16,    -5,
       1,    70,    71,    73,    74,    89,    90,    61,    91,    92,
     141,    62,   148,     2,   142,    12,   149,    15,    24,   101,
     102,    28,     3,   174,    24,    43,    44,    45,    50,    51,
      52,    53,    55,   127,   144,   145,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    56,    58,    67,    68,
      80,    84,    69,   152,    75,    93,    77,    24,    39,    85,
     127,    82,    83,    86,    98,    94,    87,    88,    95,    96,
      97,    99,   100,   103,   104,   128,   105,   130,   131,   162,
     139,   132,   106,   133,   138,   107,   108,   146,   153,   129,
     154,   156,   158,   157,   159,    89,    91,   169,   163,   164,
     168,   165,   177,   171,   172,   170,   173,   178,   181,   185,
     177,   182,   187,    13,   183,   134,   179,    54,   155,   180,
     184,    81,   143
};

static const yytype_uint8 yycheck[] =
{
      16,    21,     3,     4,    39,     3,    13,   152,     4,    14,
      49,    18,    51,     3,     6,     7,     5,    24,    23,    11,
       3,     4,     5,    52,     3,    41,     5,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   182,    45,    16,
      17,    18,    19,    20,    21,    22,     3,     4,    52,     0,
       1,     3,     4,     3,     4,     3,     4,    58,     3,     4,
      58,    62,    58,    14,    62,     0,    62,    55,    45,     3,
       4,     3,    23,    44,    45,     5,     5,     5,    54,     5,
       5,    53,    55,    99,   119,   120,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     3,     5,     3,     3,
      53,    55,     5,   123,     4,     6,     5,    45,    46,     3,
     126,     9,     9,    57,    10,     8,    59,    59,     8,    56,
      56,    52,     7,     3,     3,    47,    59,     3,     3,    48,
       3,     5,    59,     5,     5,    59,    59,     5,     5,    60,
      53,     3,    60,     4,    60,     3,     3,    57,     4,     4,
      52,     5,   168,     4,     4,    61,     3,     3,    49,     4,
     176,     5,    50,     6,    53,   114,    61,    26,   126,    61,
     176,    41,   118
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    14,    23,    64,    65,    66,    67,    71,     5,
       3,    72,     0,    65,    52,    55,    52,    16,    17,    18,
      19,    20,    21,    22,    45,    68,    69,    91,     3,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    46,
      73,    74,    91,     5,     5,     5,     3,     4,    70,    70,
      54,     5,     5,    53,    68,    55,     3,    75,     5,     3,
       4,    58,    62,    77,    78,    80,    81,     3,     3,     5,
       3,     4,    82,     3,     4,     4,    83,     5,    76,    78,
      53,    73,     9,     9,    55,     3,    57,    59,    59,     3,
       4,     3,     4,     6,     8,     8,    56,    56,    10,    52,
       7,     3,     4,     3,     3,    59,    59,    59,    59,     6,
       7,    11,    13,    18,    24,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    84,    85,    91,    47,    60,
       3,     3,     5,     5,    75,    49,    51,    86,     5,     3,
      79,    58,    62,    80,    78,    78,     5,     4,    58,    62,
      87,     5,    70,     5,    53,    84,     3,     4,    60,    60,
       3,     5,    48,     4,     4,     5,    90,    90,    52,    57,
      61,     4,     4,     3,    44,    88,    89,    91,     3,    61,
      61,    49,     5,    53,    88,     4,    90,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    66,    66,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    71,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75,
      75,    76,    77,    78,    78,    79,    80,    80,    80,    81,
      81,    81,    82,    82,    83,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    87,
      88,    88,    89,    89,    90,    90,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     1,     1,     5,     2,
       0,     2,     2,     2,     2,     2,     4,     4,     2,     1,
       2,     2,     5,     5,     2,     0,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     2,     5,     1,     7,
       3,     2,     2,     1,     1,     6,     7,     7,     6,     3,
       3,     2,     2,     2,     3,     3,     3,     2,     0,     2,
       2,     3,     3,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     5,     1,     1,     1,     2,     2,     1,
       2,     0,     3,     1,     1,     0,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 67 "aol.y" /* yacc.c:1646  */
    {
                                                                    if (debug)
                                                                        dumpast((yyvsp[0].a), 0);
                                                                    generateIntermediateCode((yyvsp[0].a));
                                                                    // Clean things up
                                                                    // treefree($1);
                                                                }
#line 1411 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "aol.y" /* yacc.c:1646  */
    {
                                                                    yyerrok;
                                                                    exit(0);
                                                                }
#line 1420 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 80 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(list, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1426 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = NULL; }
#line 1432 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 84 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1438 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 85 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1444 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 88 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(telescope, newstring((yyvsp[-3].str)), (yyvsp[-1].a));
                                                                  free(tempTelescope);
                                                                  tempTelescope = newTelescopeInfo();
                                                                }
#line 1453 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 93 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(list, (yyvsp[-1].a), (yyvsp[0].a));  }
#line 1459 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 94 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = NULL; }
#line 1465 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 96 "aol.y" /* yacc.c:1646  */
    {
                                                                  attemptDeclaration("TELESCOPE", &tempTelescope->brandSet, "BRAND");
                                                                  (yyval.a) = newast(brand, newstring((yyvsp[0].str)), NULL);
                                                                }
#line 1474 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 100 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(model, newstring((yyvsp[0].str)), NULL); }
#line 1480 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 101 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(type, newstring((yyvsp[0].str)), NULL); }
#line 1486 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 102 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(aperture, (yyvsp[0].a), NULL); }
#line 1492 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 103 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(focallength, (yyvsp[0].a), NULL); }
#line 1498 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 104 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(focalratio, newdouble((yyvsp[0].d)), NULL); }
#line 1504 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 105 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(focalratio, newint((yyvsp[0].i)), NULL); }
#line 1510 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 106 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(mount, newstring((yyvsp[0].str)), NULL); }
#line 1516 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 107 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1522 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 110 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(size, newdouble((yyvsp[-1].d)), newstring((yyvsp[0].str)));}
#line 1528 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 111 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(size, newint((yyvsp[-1].i)), newstring((yyvsp[0].str)));}
#line 1534 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 115 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(observation, (yyvsp[-3].a), (yyvsp[-1].a)); }
#line 1540 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 117 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newdate((yyvsp[-4].i), (yyvsp[-2].i), (yyvsp[0].i)); }
#line 1546 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(list, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1552 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = NULL; }
#line 1558 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 123 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a);  }
#line 1564 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 124 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(location, newstring((yyvsp[0].str)), NULL);  }
#line 1570 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 125 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1576 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 126 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1582 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 127 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(weather, newstring((yyvsp[0].str)), NULL);  }
#line 1588 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 128 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(seeing, newint((yyvsp[0].i)), NULL);  }
#line 1594 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 129 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(transparency, newint((yyvsp[0].i)), NULL);  }
#line 1600 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 130 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1606 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 131 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(humidity, newdouble((yyvsp[-1].d)), NULL); }
#line 1612 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 132 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(humidity, newint((yyvsp[-1].i)), NULL); }
#line 1618 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 133 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1624 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 134 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(target, newstring((yyvsp[-3].str)), (yyvsp[-1].a)); }
#line 1630 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 135 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1636 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 138 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(timeRange, newast(time, newint((yyvsp[-6].i)), newint((yyvsp[-4].i))),
                                                                              newast(time, newint((yyvsp[-2].i)), newint((yyvsp[0].i)))); }
#line 1643 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 140 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(time, newint((yyvsp[-2].i)), newint((yyvsp[0].i))); }
#line 1649 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 143 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(latitude, (yyvsp[-1].a), newstring((yyvsp[0].str))); }
#line 1655 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 146 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(longitude, (yyvsp[-1].a), newstring((yyvsp[0].str))); }
#line 1661 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 149 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1667 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 150 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1673 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 153 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newHorDMinSec(' ', (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].d)); }
#line 1679 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 156 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newHorDMinSec('+', (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].d)); }
#line 1685 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 157 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newHorDMinSec('-', (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].d)); }
#line 1691 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 158 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newHorDMinSec('+', (yyvsp[-5].i), (yyvsp[-3].i), (yyvsp[-1].d)); }
#line 1697 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 161 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(degree, newchar('+'), newdouble((yyvsp[-1].d))); }
#line 1703 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 162 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(degree, newchar('-'), newdouble((yyvsp[-1].d))); }
#line 1709 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 163 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(degree, newchar('+'), newdouble((yyvsp[-1].d))); }
#line 1715 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 167 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(temperature, newdouble((yyvsp[-1].d)), newstring((yyvsp[0].str))); }
#line 1721 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 168 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(temperature, newint((yyvsp[-1].i)), newstring((yyvsp[0].str))); }
#line 1727 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 171 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newwind((yyvsp[-2].d), (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1733 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 173 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newwind((yyvsp[-2].d), (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1739 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 175 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newwind((yyvsp[-2].d), (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1745 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 178 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(list, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1751 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 179 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = NULL; }
#line 1757 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 182 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1763 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 183 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(type, newstring((yyvsp[0].str)), NULL); }
#line 1769 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 184 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(designation, (yyvsp[-1].a), newstring((yyvsp[0].str))); }
#line 1775 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 185 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(designation, (yyvsp[-1].a), newint((yyvsp[0].i))); }
#line 1781 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 186 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(constellation, newstring((yyvsp[0].str)), NULL); }
#line 1787 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 187 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(rightascension, (yyvsp[0].a), NULL); }
#line 1793 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 188 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(declination, (yyvsp[0].a), NULL); }
#line 1799 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 189 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(altitude, (yyvsp[0].a), NULL); }
#line 1805 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 190 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(azimuth, (yyvsp[0].a), NULL); }
#line 1811 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 191 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(filter, newstring((yyvsp[0].str)), NULL); }
#line 1817 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 192 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1823 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 193 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(telescopeid, newstring((yyvsp[0].str)), NULL); }
#line 1829 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 196 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(eyepiece, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1835 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 197 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(eyepiece, newstring((yyvsp[-1].str)), (yyvsp[0].a)); }
#line 1841 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 199 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(directory, newstring((yyvsp[-3].str)), (yyvsp[-1].a)); }
#line 1847 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 200 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1853 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 203 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newstring("m"); }
#line 1859 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 204 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newstring("ngc"); }
#line 1865 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 207 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(magnitude, newchar('+'), newdouble((yyvsp[0].d))); }
#line 1871 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 208 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(magnitude, newchar('-'), newdouble((yyvsp[0].d))); }
#line 1877 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 209 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(magnitude, newchar('+'), newdouble((yyvsp[0].d))); }
#line 1883 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 211 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(list, (yyvsp[-1].a), (yyvsp[0].a)); }
#line 1889 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 212 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = NULL; }
#line 1895 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 214 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(image, newstring((yyvsp[-1].str)), (yyvsp[0].a)); }
#line 1901 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 215 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = (yyvsp[0].a); }
#line 1907 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 217 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(note, newstring((yyvsp[0].str)), NULL); }
#line 1913 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 218 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = NULL; }
#line 1919 "aol.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 222 "aol.y" /* yacc.c:1646  */
    { (yyval.a) = newast(note, newstring((yyvsp[0].str)), NULL); }
#line 1925 "aol.tab.c" /* yacc.c:1646  */
    break;


#line 1929 "aol.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 224 "aol.y" /* yacc.c:1906  */

