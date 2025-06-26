
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include "common.h"


/* Line 189 of yacc.c  */
#line 78 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BASIC = 258,
     CONST = 259,
     ID = 260,
     IF = 261,
     ELSE = 262,
     DO = 263,
     WHILE = 264,
     BREAK = 265,
     LT = 266,
     LE = 267,
     GT = 268,
     GE = 269,
     EQ = 270,
     NEQ = 271,
     OR = 272,
     AND = 273,
     UMINUS = 274
   };
#endif
/* Tokens.  */
#define BASIC 258
#define CONST 259
#define ID 260
#define IF 261
#define ELSE 262
#define DO 263
#define WHILE 264
#define BREAK 265
#define LT 266
#define LE 267
#define GT 268
#define GE 269
#define EQ 270
#define NEQ 271
#define OR 272
#define AND 273
#define UMINUS 274




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 158 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   74

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNRULES -- Number of states.  */
#define YYNSTATES  81

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,     2,     2,     2,     2,     2,
      26,    27,    19,    21,     2,    22,     2,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,     2,    29,     2,     2,     2,     2,
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
      15,    16,    17,    18,    25
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    16,    17,    18,    21,    22,    26,
      28,    31,    32,    38,    46,    52,    60,    62,    66,    68,
      72,    74,    78,    82,    84,    88,    92,    96,   100,   102,
     107,   111,   115,   117,   121,   125,   127,   130,   132,   134
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,     3,     5,    26,    27,    33,    -1,    28,
      34,    36,    39,    35,    29,    -1,    -1,    -1,    36,    37,
      -1,    -1,    38,     5,    30,    -1,     3,    -1,    39,    40,
      -1,    -1,     6,    26,    41,    27,    40,    -1,     6,    26,
      41,    27,    40,     7,    40,    -1,     9,    26,    41,    27,
      40,    -1,     8,    40,     9,    26,    41,    27,    30,    -1,
      33,    -1,    41,    17,    42,    -1,    42,    -1,    42,    18,
      43,    -1,    43,    -1,    43,    15,    44,    -1,    43,    16,
      44,    -1,    44,    -1,    45,    11,    45,    -1,    45,    12,
      45,    -1,    45,    13,    45,    -1,    45,    14,    45,    -1,
      45,    -1,     5,    24,    45,    30,    -1,    45,    21,    46,
      -1,    45,    22,    46,    -1,    46,    -1,    46,    19,    47,
      -1,    46,    20,    47,    -1,    47,    -1,    22,    47,    -1,
       5,    -1,     4,    -1,    26,    45,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    34,    34,    36,    42,    46,    54,    55,    58,    71,
      74,    75,    78,    79,    80,    81,    82,    85,    86,    89,
      90,    93,    94,    95,    98,   100,   101,   102,   103,   108,
     130,   148,   166,   174,   192,   211,   219,   233,   259,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BASIC", "CONST", "ID", "IF", "ELSE",
  "DO", "WHILE", "BREAK", "LT", "LE", "GT", "GE", "EQ", "NEQ", "OR", "AND",
  "'*'", "'/'", "'+'", "'-'", "'!'", "'='", "UMINUS", "'('", "')'", "'{'",
  "'}'", "';'", "$accept", "function", "block", "blockM1", "blockM2",
  "decls", "decl", "type", "stmts", "stmt", "bool", "join", "equal", "rel",
  "expr", "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,    42,
      47,    43,    45,    33,    61,   274,    40,    41,   123,   125,
      59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    34,    35,    36,    36,    37,    38,
      39,    39,    40,    40,    40,    40,    40,    41,    41,    42,
      42,    43,    43,    43,    44,    44,    44,    44,    44,    40,
      45,    45,    45,    46,    46,    46,    47,    47,    47,    47
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     0,     0,     2,     0,     3,     1,
       2,     0,     5,     7,     5,     7,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     4,
       3,     3,     1,     3,     3,     1,     2,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     4,     2,     7,
      11,     9,     6,     0,     5,     0,     0,     0,     0,     0,
      16,     0,    10,     8,     0,     0,     0,     0,     3,    38,
      37,     0,     0,     0,    32,    35,     0,    18,    20,    23,
      28,     0,     0,    36,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    30,    31,    33,    34,    17,    12,    19,    21,
      22,    24,    25,    26,    27,     0,    14,     0,     0,    13,
      15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    20,     9,    21,    10,    12,    13,    14,    22,
      36,    37,    38,    39,    40,    34,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -22
static const yytype_int8 yypact[] =
{
       7,     8,    21,    -3,   -22,    11,     1,   -22,   -22,   -22,
      40,   -22,   -22,    43,    -4,    30,    37,    38,    -4,    39,
     -22,    33,   -22,   -22,     4,     4,    54,     4,   -22,   -22,
     -22,     4,     4,    19,    27,   -22,   -11,    48,    36,   -22,
       6,    41,    -5,   -22,    23,     4,     4,   -22,     4,     4,
       4,    -4,     4,     4,     4,     4,     4,     4,     4,     4,
      -4,   -22,    27,    27,   -22,   -22,    48,    61,    36,   -22,
     -22,    32,    32,    32,    32,    -2,   -22,    -4,    42,   -22,
     -22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,    63,   -22,   -22,   -22,   -22,   -22,   -22,   -18,
     -20,    20,    22,     2,   -21,    12,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      26,    16,    17,    33,    18,    19,    50,    42,    29,    30,
       1,    44,    50,     3,    43,    50,    51,    55,    56,    57,
      58,     4,    60,     5,     7,    78,    31,    45,    46,     7,
      32,    64,    65,    67,    71,    72,    73,    74,     6,    75,
      45,    46,    76,    11,    45,    46,    48,    49,    15,    47,
      61,    53,    54,    45,    46,    69,    70,    62,    63,    79,
      23,    24,    28,    41,    25,    27,    52,    59,    77,     8,
      66,     0,    80,     0,    68
};

static const yytype_int8 yycheck[] =
{
      18,     5,     6,    24,     8,     9,    17,    27,     4,     5,
       3,    32,    17,     5,    31,    17,    27,    11,    12,    13,
      14,     0,    27,    26,    28,    27,    22,    21,    22,    28,
      26,    48,    49,    51,    55,    56,    57,    58,    27,    59,
      21,    22,    60,     3,    21,    22,    19,    20,     5,    30,
      27,    15,    16,    21,    22,    53,    54,    45,    46,    77,
      30,    24,    29,     9,    26,    26,    18,    26,     7,     6,
      50,    -1,    30,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    32,     5,     0,    26,    27,    28,    33,    34,
      36,     3,    37,    38,    39,     5,     5,     6,     8,     9,
      33,    35,    40,    30,    24,    26,    40,    26,    29,     4,
       5,    22,    26,    45,    46,    47,    41,    42,    43,    44,
      45,     9,    41,    47,    45,    21,    22,    30,    19,    20,
      17,    27,    18,    15,    16,    11,    12,    13,    14,    26,
      27,    27,    46,    46,    47,    47,    42,    40,    43,    44,
      44,    45,    45,    45,    45,    41,    40,     7,    27,    40,
      30
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 34 "parser.y"
    { printf("\t\t| function\t: BASIC ID ( ) block\n"); }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 37 "parser.y"
    {
    printf("\t\t| block\t: {decls stmts}\n");

}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 42 "parser.y"
    {   printf("[INFO] 进入新的作用域, 创建符号表\n");
                TheSymbolList = CreateSymbolList( TheSymbolList, TheSymbolList->endaddr ); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 46 "parser.y"
    { SymbolListPtr env;
    PrintSymbolList( TheSymbolList);
    env = TheSymbolList->prev;
    DestroySymbolList( TheSymbolList );
    TheSymbolList = env;
    }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 54 "parser.y"
    { printf("\t\t| decls\t: decls decl\n"); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 55 "parser.y"
    { printf("\t\t| decls\t: null\n"); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 58 "parser.y"
    { int width;
                                printf("\t\t| decl\t: type ID ;\n",(yyvsp[(2) - (3)]).id.name);
    	switch( (yyvsp[(1) - (3)]).basic.type ) {
                                    case CHAR  : width = CHAR_WIDTH;  break;
                                    case INT   : width = INT_WIDTH;   break;
                                    case FLOAT : width = FLOAT_WIDTH; break;
                                    case BOOL  : width = BOOL_WIDTH;  break;
                                    default    : width = -1; break;
                                }
                                AddToSymbolList( TheSymbolList, (yyvsp[(2) - (3)]).id.name, (yyvsp[(1) - (3)]).basic.type, width );
                              }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    { printf("\t\t| type\t: BASIC\n"); (yyval).basic.type = (yyvsp[(1) - (1)]).basic.type; }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    { printf("\t\t| stmts\t: stmts stmt\n");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    { printf("\t\t| stmts\t: null\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    { printf("\t\t| stmt\t: IF (bool) stmt\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    { printf("\t\t| stmt\t: IF (bool) stmt ELSE stmt\n"); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    { printf("\t\t| stmt\t: WHILE (bool) stmt\n"); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    { printf("\t\t| stmt\t: DO stmt WHILE (bool) ;\n"); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    { printf("\t\t| stmt\t: block\n"); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { printf("\t\t| bool\t: bool OR join\n"); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    { printf("\t\t| bool\t: join\n"); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { printf("\t\t| join\t: join AND equal\n"); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    { printf("\t\t| join\t: equal\n"); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    { printf("\t\t| equal\t: equal EQ rel\n"); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    { printf("\t\t| equal\t: equal NEQ rel\n"); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    { printf("\t\t| equal\t: rel\n"); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    { printf("\t\t| rel\t: expr LT expr\n"); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    { printf("\t\t| rel\t: expr LE expr\n"); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    { printf("\t\t| rel\t: expr GT expr\n"); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    { printf("\t\t| rel\t: expr GE expr\n"); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { printf("\t\t| rel\t: expr\n"); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {
    // 查找符号表
    struct Symbol * p;
    p = LookUpAllSymbolList( TheSymbolList, (yyvsp[(1) - (4)]).id.name );
    // ID 不存在
    if( p == NULL ) {
        // 符号不存在
        char msg[128];
        sprintf(msg, "变量 \"%s\" 未定义", (yyvsp[(1) - (4)]).id.name);
        yyerror(msg);
        return 0;
    }
    // ID 存在
    // 四元式
    int qaddr = GenQuadruple( OIntEvaluation, (yyvsp[(3) - (4)]).expr.addr, 0, p->addr, (yyvsp[(3) - (4)]).expr.str, "", (yyvsp[(1) - (4)]).id.name);
    //归约
    printf("\t\t| stmt\t: ID = expr ;\n");
}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {
    //类型推导
    int type = MAX((yyvsp[(1) - (3)]).term.type, (yyvsp[(3) - (3)]).term.type);
    int width = TYPE_WIDTH(type);
    //创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, width);
    //生成四元式
    int OpCode = (type == FLOAT ? OFloatAdd : OIntAdd);
    int qaddr = GenQuadruple( OpCode, (yyvsp[(1) - (3)]).term.addr, (yyvsp[(3) - (3)]).term.addr, addr, (yyvsp[(1) - (3)]).term.str, (yyvsp[(3) - (3)]).term.str, str);
    //归约
    printf("\t\t| expr\t: expr + term\n");
    strcpy( (yyval).expr.str, str);
    (yyval).expr.type = type;
    (yyval).expr.addr = addr;
    (yyval).expr.width = width;
}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {
    //类型推导
    int type = MAX((yyvsp[(1) - (3)]).term.type, (yyvsp[(3) - (3)]).term.type);
    int width = TYPE_WIDTH(type);
    //创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, width);
    //生成四元式
    int OpCode = (type == FLOAT ? OFloatSub : OIntSub);
    int qaddr = GenQuadruple( OpCode, (yyvsp[(1) - (3)]).term.addr, (yyvsp[(3) - (3)]).term.addr, addr, (yyvsp[(1) - (3)]).term.str, (yyvsp[(3) - (3)]).term.str, str);
    //归约
    printf("\t\t| expr\t: expr - term\n");
    strcpy( (yyval).expr.str, str);
    (yyval).expr.type = type;
    (yyval).expr.addr = addr;
    (yyval).expr.width = width;
}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {
    printf("\t\t| expr\t: term\n");
    strcpy( (yyval).expr.str, (yyvsp[(1) - (1)]).term.str );
    (yyval).expr.type = (yyvsp[(1) - (1)]).term.type;
    (yyval).expr.addr = (yyvsp[(1) - (1)]).term.addr;
    (yyval).expr.width = (yyvsp[(1) - (1)]).term.width;
}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {
    // 类型推导
    int type = MAX((yyvsp[(1) - (3)]).term.type, (yyvsp[(3) - (3)]).factor.type);
    int width = TYPE_WIDTH(type);
    // 创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, width);
    // 生成四元式
    int OpCode = (type == FLOAT ? OFloatMultiply : OIntMultiply);
    int qaddr = GenQuadruple( OpCode, (yyvsp[(1) - (3)]).term.addr, (yyvsp[(3) - (3)]).factor.addr, addr, (yyvsp[(1) - (3)]).term.str, (yyvsp[(3) - (3)]).factor.str, str);
    // 归约
    printf("\t\t| term\t: term * factor\n");
    strcpy( (yyval).term.str, str);
    (yyval).term.type = type;
    (yyval).term.addr = addr;
    (yyval).term.width = width;
}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {
    // 类型推导
    int type = MAX((yyvsp[(1) - (3)]).term.type, (yyvsp[(3) - (3)]).factor.type);
    int width = TYPE_WIDTH(type);
    // 创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, width);
    // 生成四元式
    int OpCode = (type == FLOAT ? OFloatDivide : OIntDivide);
    printf("OpCode = %d\n", OpCode);
    int qaddr = GenQuadruple( OpCode, (yyvsp[(1) - (3)]).term.addr, (yyvsp[(3) - (3)]).factor.addr, addr, (yyvsp[(1) - (3)]).term.str, (yyvsp[(3) - (3)]).factor.str, str);
    // 归约
    printf("\t\t| term\t: term / factor\n");
    strcpy( (yyval).term.str, str);
    (yyval).term.type = type;
    (yyval).term.addr = addr;
    (yyval).term.width = width;
}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {
    printf("\t\t| term\t: factor\n");
    strcpy( (yyval).term.str, (yyvsp[(1) - (1)]).factor.str );
    (yyval).term.type = (yyvsp[(1) - (1)]).factor.type;
    (yyval).term.addr = (yyvsp[(1) - (1)]).factor.addr;
    (yyval).term.width = (yyvsp[(1) - (1)]).factor.width;
}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {
    // 创建临时变量
    char str[ID_MAX_LEN];
    int addr = NewTemp(TheSymbolList, str, (yyvsp[(2) - (2)]).factor.width);
    // 生成四元式
    GenQuadruple( OUMINUS, (yyvsp[(2) - (2)]).factor.addr, 0, addr, (yyvsp[(2) - (2)]).factor.str, "", str);
    // 归约
    printf("\t\t| factor\t: -factor\n");
    strcpy( (yyval).factor.str, str);
    (yyval).factor.type  = (yyvsp[(2) - (2)]).factor.type;
    (yyval).factor.addr  = addr;
    (yyval).factor.width = (yyvsp[(2) - (2)]).factor.width;
}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {
    printf("\t\t| factor\t: ID\n");
    // 查找符号表
    struct Symbol * p;
    p = LookUpAllSymbolList( TheSymbolList, (yyvsp[(1) - (1)]).id.name );
    // 符号存在
    if( p != NULL ) {
        // 从符号表中获取值进行归约
        strcpy( (yyval).factor.str, p->name );
        (yyval).factor.type  = p->type;
        (yyval).factor.addr  = p->addr;
        (yyval).factor.width = p->width;
    }
    else {
        // 符号不存在
        char msg[128];
        sprintf(msg, "变量 \"%s\" 未定义", (yyvsp[(1) - (1)]).id.name);
        yyerror(msg);
        /*容错归约*/
        strcpy( (yyval).factor.str, "no_id_defined" );
        (yyval).factor.type = INT;
        (yyval).factor.addr = -1;
        (yyval).factor.width = INT_WIDTH;
        }
}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    {
    printf("\t\t| factor\t: CONST\n");
    // 查找常量表
    struct ConstElem * p;
    p = LookUpConstList( (yyvsp[(1) - (1)]).constval.type, (yyvsp[(1) - (1)]).constval.value, (yyvsp[(1) - (1)]).constval.width );
    // 该常量不存在, 则添加到常量表
    if( p == NULL )
        p = AddToConstList( (yyvsp[(1) - (1)]).constval.str, (yyvsp[(1) - (1)]).constval.type, (yyvsp[(1) - (1)]).constval.value, (yyvsp[(1) - (1)]).constval.width );
    // 归约
    strcpy( (yyval).factor.str, (yyvsp[(1) - (1)]).constval.str );
    (yyval).factor.type  = (yyvsp[(1) - (1)]).constval.type;
    (yyval).factor.addr  = p->addr;
    (yyval).factor.width = p->width;
}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    {
    printf("\t\t| factor\t: (expr)\n" );
    strcpy( (yyval).factor.str, (yyvsp[(2) - (3)]).expr.str );
    (yyval).factor.type  = (yyvsp[(2) - (3)]).expr.type;
    (yyval).factor.addr  = (yyvsp[(2) - (3)]).expr.addr;
    (yyval).factor.width = (yyvsp[(2) - (3)]).expr.width;
}
    break;



/* Line 1455 of yacc.c  */
#line 1843 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 281 "parser.y"


