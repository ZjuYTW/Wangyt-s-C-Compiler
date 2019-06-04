/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     CONSTANT_INT = 262,
     CONSTANT_DOUBLE = 263,
     TRUE = 264,
     FALSE = 265,
     CHAR = 266,
     INT = 267,
     DOUBLE = 268,
     VOID = 269,
     BOOL = 270,
     CASE = 271,
     IF = 272,
     ELSE = 273,
     SWITCH = 274,
     WHILE = 275,
     DO = 276,
     FOR = 277,
     GOTO = 278,
     CONTINUE = 279,
     BREAK = 280,
     RETURN = 281,
     PTR_OP = 282,
     INC_OP = 283,
     DEC_OP = 284,
     LEFT_OP = 285,
     RIGHT_OP = 286,
     LE_OP = 287,
     GE_OP = 288,
     EQ_OP = 289,
     NE_OP = 290,
     AND_OP = 291,
     OR_OP = 292,
     SUB_ASSIGN = 293,
     LEFT_ASSIGN = 294,
     RIGHT_ASSIGN = 295,
     AND_ASSIGN = 296,
     MUL_ASSIGN = 297,
     DIV_ASSIGN = 298,
     MOD_ASSIGN = 299,
     ADD_ASSIGN = 300,
     XOR_ASSIGN = 301,
     OR_ASSIGN = 302,
     TYPE_NAME = 303,
     LOWER_THAN_ELSE = 304
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define CONSTANT_INT 262
#define CONSTANT_DOUBLE 263
#define TRUE 264
#define FALSE 265
#define CHAR 266
#define INT 267
#define DOUBLE 268
#define VOID 269
#define BOOL 270
#define CASE 271
#define IF 272
#define ELSE 273
#define SWITCH 274
#define WHILE 275
#define DO 276
#define FOR 277
#define GOTO 278
#define CONTINUE 279
#define BREAK 280
#define RETURN 281
#define PTR_OP 282
#define INC_OP 283
#define DEC_OP 284
#define LEFT_OP 285
#define RIGHT_OP 286
#define LE_OP 287
#define GE_OP 288
#define EQ_OP 289
#define NE_OP 290
#define AND_OP 291
#define OR_OP 292
#define SUB_ASSIGN 293
#define LEFT_ASSIGN 294
#define RIGHT_ASSIGN 295
#define AND_ASSIGN 296
#define MUL_ASSIGN 297
#define DIV_ASSIGN 298
#define MOD_ASSIGN 299
#define ADD_ASSIGN 300
#define XOR_ASSIGN 301
#define OR_ASSIGN 302
#define TYPE_NAME 303
#define LOWER_THAN_ELSE 304




/* Copy the first part of user declarations.  */
#line 1 "compiler.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include "ast.hpp"
    #include "block.hpp"
    #include "parser.hpp"
    using namespace std;
    
    extern char *yytext;
    extern int column;
    extern FILE * yyin;
    extern FILE * yyout;
    root_Node *root;
    extern int yylineno;
    
    int yylex(void);
    void yyerror(const char*);
    

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 20 "compiler.y"
{
    struct root_Node* rootN;
    struct func_Node* funcN;
    struct ID_Node* IDN;
    struct declaration_Node* declarationN;
    struct declarator_Node* declaratorN;
    struct initializer_Node* initN;
    struct initial_list* initl;
    struct designator* design;
    struct param_Node* paraN;
    struct stat_Node* statN;
    struct block_item* block;
    struct exp_Node* expN;
    enum type_specifier_kind typekind;
    enum assign_kind assignkind;
    enum unary_kind arykind;
}
/* Line 193 of yacc.c.  */
#line 231 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 244 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   629

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNRULES -- Number of states.  */
#define YYNSTATES  250

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,     2,     2,    63,    56,     2,
      71,    72,    61,    60,    50,    59,    55,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    49,
      64,    52,    65,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    54,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    67,    70,    58,     2,     2,     2,
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
      45,    46,    47,    48,    73
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    19,
      21,    26,    30,    35,    38,    41,    43,    47,    49,    52,
      55,    58,    60,    62,    64,    66,    68,    72,    76,    80,
      82,    86,    90,    92,    96,   100,   102,   106,   110,   114,
     118,   120,   124,   128,   130,   134,   136,   140,   142,   146,
     148,   152,   154,   158,   160,   166,   168,   172,   174,   176,
     178,   180,   182,   184,   186,   188,   190,   192,   194,   196,
     200,   202,   205,   209,   211,   215,   217,   221,   223,   225,
     227,   229,   231,   233,   237,   242,   246,   251,   256,   260,
     262,   266,   269,   271,   273,   277,   279,   283,   288,   290,
     293,   297,   302,   305,   307,   310,   314,   317,   319,   321,
     323,   325,   327,   329,   333,   338,   341,   345,   347,   350,
     352,   354,   356,   359,   365,   373,   379,   385,   393,   400,
     408,   415,   423,   427,   430,   433,   436,   440,   442,   445,
     447,   449,   454,   458,   460
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      75,     0,    -1,   118,    -1,     3,    -1,     9,    -1,    10,
      -1,     7,    -1,     8,    -1,    71,    94,    72,    -1,    76,
      -1,    77,    53,    94,    54,    -1,    77,    71,    72,    -1,
      77,    71,    78,    72,    -1,    77,    28,    -1,    77,    29,
      -1,    92,    -1,    78,    50,    92,    -1,    77,    -1,    28,
      79,    -1,    29,    79,    -1,    80,    79,    -1,    60,    -1,
      59,    -1,    58,    -1,    57,    -1,    79,    -1,    81,    61,
      79,    -1,    81,    62,    79,    -1,    81,    63,    79,    -1,
      81,    -1,    82,    60,    81,    -1,    82,    59,    81,    -1,
      82,    -1,    83,    30,    82,    -1,    83,    31,    82,    -1,
      83,    -1,    84,    64,    83,    -1,    84,    65,    83,    -1,
      84,    32,    83,    -1,    84,    33,    83,    -1,    84,    -1,
      85,    34,    84,    -1,    85,    35,    84,    -1,    85,    -1,
      86,    56,    85,    -1,    86,    -1,    87,    66,    86,    -1,
      87,    -1,    88,    67,    87,    -1,    88,    -1,    89,    36,
      88,    -1,    89,    -1,    90,    37,    89,    -1,    90,    -1,
      90,    68,    94,    51,    91,    -1,    91,    -1,    79,    93,
      92,    -1,    52,    -1,    42,    -1,    43,    -1,    44,    -1,
      45,    -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,
      46,    -1,    47,    -1,    92,    -1,    94,    50,    92,    -1,
      91,    -1,    99,    49,    -1,    99,    97,    49,    -1,    98,
      -1,    97,    50,    98,    -1,   100,    -1,   100,    52,   104,
      -1,    14,    -1,    11,    -1,    12,    -1,    13,    -1,    15,
      -1,     3,    -1,    71,   100,    72,    -1,   100,    53,    95,
      54,    -1,   100,    53,    54,    -1,   100,    71,   101,    72,
      -1,   100,    71,   103,    72,    -1,   100,    71,    72,    -1,
     102,    -1,   101,    50,   102,    -1,    99,   100,    -1,    99,
      -1,     3,    -1,   103,    50,     3,    -1,    92,    -1,    69,
     105,    70,    -1,    69,   105,    50,    70,    -1,   104,    -1,
     106,   104,    -1,   105,    50,   104,    -1,   105,    50,   106,
     104,    -1,   107,    52,    -1,   108,    -1,   107,   108,    -1,
      53,    90,    54,    -1,    55,     3,    -1,   110,    -1,   111,
      -1,   114,    -1,   115,    -1,   116,    -1,   117,    -1,     3,
      51,   109,    -1,    16,    90,    51,   109,    -1,    69,    70,
      -1,    69,   112,    70,    -1,   113,    -1,   112,   113,    -1,
      96,    -1,   109,    -1,    49,    -1,    94,    49,    -1,    17,
      71,    94,    72,   109,    -1,    17,    71,    94,    72,   109,
      18,   109,    -1,    19,    71,    94,    72,   109,    -1,    20,
      71,    94,    72,   109,    -1,    21,   109,    20,    71,    94,
      72,    49,    -1,    22,    71,   114,   114,    72,   109,    -1,
      22,    71,   114,   114,    94,    72,   109,    -1,    22,    71,
      96,   114,    72,   109,    -1,    22,    71,    96,   114,    94,
      72,   109,    -1,    23,     3,    49,    -1,    24,    49,    -1,
      25,    49,    -1,    26,    49,    -1,    26,    94,    49,    -1,
     119,    -1,   118,   119,    -1,   120,    -1,    96,    -1,    99,
     100,   121,   111,    -1,    99,   100,   111,    -1,    96,    -1,
     121,    96,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    77,    82,    86,    89,    93,    97,   105,
     112,   120,   129,   137,   145,   156,   163,   174,   182,   190,
     198,   209,   212,   215,   218,   225,   232,   239,   246,   257,
     264,   271,   282,   290,   298,   310,   317,   324,   331,   339,
     351,   358,   366,   377,   383,   393,   399,   409,   415,   425,
     431,   442,   448,   458,   465,   476,   484,   495,   498,   502,
     506,   510,   514,   518,   522,   526,   530,   534,   542,   549,
     559,   567,   570,   579,   582,   591,   594,   603,   606,   609,
     612,   615,   623,   629,   633,   642,   650,   658,   666,   679,
     682,   691,   695,   701,   704,   714,   718,   723,   731,   735,
     740,   748,   759,   765,   768,   777,   781,   789,   792,   795,
     798,   801,   804,   811,   817,   827,   832,   840,   844,   853,
     857,   864,   868,   876,   883,   890,   901,   910,   919,   928,
     937,   946,   959,   965,   971,   977,   983,   992,   995,  1004,
    1011,  1021,  1030,  1042,  1045
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "CONSTANT_INT", "CONSTANT_DOUBLE", "TRUE",
  "FALSE", "CHAR", "INT", "DOUBLE", "VOID", "BOOL", "CASE", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "SUB_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "';'", "','",
  "':'", "'='", "'['", "']'", "'.'", "'&'", "'!'", "'~'", "'-'", "'+'",
  "'*'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'{'", "'}'",
  "'('", "')'", "LOWER_THAN_ELSE", "$accept", "Program",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "init_declarator_list",
  "init_declarator", "type_specifier", "declarator", "parameter_list",
  "parameter_declaration", "identifier_list", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    59,
      44,    58,    61,    91,    93,    46,    38,    33,   126,    45,
      43,    42,    47,    37,    60,    62,    94,   124,    63,   123,
     125,    40,    41,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    79,
      79,    80,    80,    80,    80,    81,    81,    81,    81,    82,
      82,    82,    83,    83,    83,    84,    84,    84,    84,    84,
      85,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    96,    96,    97,    97,    98,    98,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   104,   104,   105,   105,
     105,   105,   106,   107,   107,   108,   108,   109,   109,   109,
     109,   109,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   117,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   121,   121
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     3,     4,     2,     2,     1,     3,     1,     2,     2,
       2,     1,     1,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     4,     4,     3,     1,
       3,     2,     1,     1,     3,     1,     3,     4,     1,     2,
       3,     4,     2,     1,     2,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     4,     2,     3,     1,     2,     1,
       1,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       6,     7,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     4,     3,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    78,    79,    80,    77,    81,     0,   140,     0,     2,
     137,   139,     1,    82,    71,     0,     0,    73,    75,   138,
       0,    72,     0,     0,     0,     0,     0,   143,     0,   142,
       0,    83,    74,    75,     3,     6,     7,     4,     5,     0,
       0,    24,    23,    22,    21,     0,     0,     9,    17,    25,
       0,    29,    32,    35,    40,    43,    45,    47,    49,    51,
      53,    55,    95,    76,    85,    25,    70,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
     115,    68,     0,   119,   120,   107,   108,     0,   117,   109,
     110,   111,   112,    93,    88,    92,     0,    89,     0,   144,
     141,    18,    19,     0,     0,    98,     0,     0,     0,   103,
       0,    13,    14,     0,     0,    62,    63,    64,    65,    58,
      59,    60,    61,    66,    67,    57,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,   133,   134,   135,     0,
     122,     0,   116,   118,    91,     0,    86,     0,    87,     0,
     106,     0,    96,    99,   102,   104,     8,     0,    11,     0,
      15,    56,    26,    27,    28,    31,    30,    33,    34,    38,
      39,    36,    37,    41,    42,    44,    46,    48,    50,    52,
       0,   113,     0,     0,     0,     0,     0,     0,     0,   132,
     136,    69,    90,    94,   105,    97,   100,     0,    10,     0,
      12,     0,   114,     0,     0,     0,     0,     0,     0,   101,
      16,    54,   123,   125,   126,     0,     0,     0,     0,     0,
       0,     0,   130,     0,   128,     0,   124,   127,   131,   129
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    47,    48,   179,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    81,   126,
      82,    67,     7,    16,    17,    28,    33,    96,    97,    98,
      63,   106,   107,   108,   109,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     9,    10,    11,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -147
static const yytype_int16 yypact[] =
{
     167,  -147,  -147,  -147,  -147,  -147,    39,  -147,     6,   167,
    -147,  -147,  -147,  -147,  -147,    17,    90,  -147,   135,  -147,
     -25,  -147,    17,   221,   286,   248,    54,  -147,     6,  -147,
      20,  -147,  -147,    83,  -147,  -147,  -147,  -147,  -147,   558,
     558,  -147,  -147,  -147,  -147,   462,   558,  -147,   -17,   309,
     558,    36,   140,   136,    18,   168,   -38,   -29,   -15,    89,
     -12,  -147,  -147,  -147,  -147,  -147,  -147,    97,    94,   558,
      71,   130,   134,   371,   154,   170,   184,   194,   498,  -147,
    -147,  -147,   169,  -147,  -147,  -147,  -147,   313,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,    17,    -9,  -147,    -2,  -147,
    -147,  -147,  -147,   558,   241,  -147,   -21,   221,    40,  -147,
       3,  -147,  -147,   558,    14,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,   558,  -147,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,  -147,   371,     7,
     558,   558,   558,   225,   395,   197,  -147,  -147,  -147,   171,
    -147,   558,  -147,  -147,   100,   167,  -147,   244,  -147,   107,
    -147,   429,  -147,  -147,  -147,  -147,  -147,    37,  -147,    28,
    -147,  -147,  -147,  -147,  -147,    36,    36,   140,   140,   136,
     136,   136,   136,    18,    18,   168,   -38,   -29,   -15,    89,
     166,  -147,   371,    31,    51,    52,   177,   531,   531,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,   221,  -147,   558,
    -147,   558,  -147,   371,   371,   371,   558,   155,   182,  -147,
    -147,  -147,   234,  -147,  -147,    80,   371,    87,   371,    88,
     371,   217,  -147,   371,  -147,   371,  -147,  -147,  -147,  -147
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -147,  -147,   -24,  -147,    91,   102,    58,
      98,   141,   133,   142,   139,   143,   -63,   -23,    15,  -147,
     -19,  -147,   -11,  -147,   262,     4,    -5,  -147,   121,  -147,
     -43,  -147,   116,  -147,   183,   -68,  -147,    66,  -147,   211,
    -146,  -147,  -147,  -147,  -147,   290,  -147,  -147
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      65,    66,   105,    18,     8,   153,   149,    27,   208,    13,
      20,   111,   112,     8,    83,   101,   102,    34,   141,    99,
      13,    35,    36,    37,    38,   145,   127,   110,    24,   171,
      95,     1,     2,     3,     4,     5,   113,   142,    62,    12,
     169,   165,    39,    40,   145,    65,    26,    31,   167,   172,
     135,   136,   143,   161,   114,    14,   146,    93,   202,   159,
      62,   227,   228,   166,   173,     1,     2,     3,     4,     5,
     168,    41,    42,    43,    44,   176,    83,    15,   219,    65,
     201,   161,   137,   138,    29,    46,   178,   161,    15,    25,
     164,   218,   174,   103,   177,   104,   100,   128,   129,   130,
     220,   161,   161,   223,   182,   183,   184,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    62,   224,   225,   144,    94,   200,   216,   180,
     161,   203,   204,   205,   222,    23,    24,   161,   161,    21,
      22,   181,   150,   207,   145,   148,     1,     2,     3,     4,
       5,   147,   241,    24,    26,   232,   233,   234,    34,   243,
     245,   214,    35,    36,    37,    38,   133,   134,   242,    95,
     244,    26,   246,   155,   229,   248,   211,   249,     1,     2,
       3,     4,     5,    39,    40,    34,    62,    23,    24,    35,
      36,    37,    38,   189,   190,   191,   192,    65,   231,   131,
     132,   151,   139,   140,    25,   152,    26,   235,   237,   239,
      39,    40,    41,    42,    43,    44,   161,   221,   160,   161,
     210,   161,   185,   186,    34,   154,    46,   236,    35,    36,
      37,    38,    62,   156,   230,   187,   188,   193,   194,    41,
      42,    43,    44,   157,   170,   206,   209,   213,   226,    39,
      40,    68,   240,    46,   238,    35,    36,    37,    38,     1,
       2,     3,     4,     5,    69,    70,   247,    71,    72,    73,
      74,    75,    76,    77,    78,   196,    39,    40,    41,    42,
      43,    44,   195,   198,    32,   197,   212,   217,   199,    34,
      45,   175,    46,    35,    36,    37,    38,    79,   163,    19,
       0,     0,     0,     0,     0,    41,    42,    43,    44,     0,
       0,     0,     0,     0,    39,    40,    68,    25,    80,    46,
      35,    36,    37,    38,     1,     2,     3,     4,     5,    69,
      70,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      64,    39,    40,    41,    42,    43,    44,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    46,     0,     0,
       0,   125,    79,     0,     0,     0,     0,     0,     0,     0,
      41,    42,    43,    44,    68,     0,     0,     0,    35,    36,
      37,    38,    25,   162,    46,     0,     0,    69,    70,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    34,    39,
      40,     0,    35,    36,    37,    38,     1,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,    39,    40,     0,     0,     0,    41,    42,
      43,    44,    34,     0,     0,     0,    35,    36,    37,    38,
      25,     0,    46,     0,    79,     0,     0,     0,     0,     0,
       0,     0,    41,    42,    43,    44,     0,    39,    40,     0,
       0,     0,     0,     0,     0,    34,    46,     0,     0,    35,
      36,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   103,     0,   104,     0,    41,    42,    43,    44,
      39,    40,     0,     0,     0,     0,     0,     0,    45,   215,
      46,    34,     0,     0,     0,    35,    36,    37,    38,     0,
       0,     0,     0,     0,     0,   103,     0,   104,     0,    41,
      42,    43,    44,     0,     0,     0,    39,    40,     0,     0,
       0,    45,     0,    46,    34,     0,     0,     0,    35,    36,
      37,    38,     0,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,    41,    42,    43,    44,    39,
      40,    34,     0,     0,     0,    35,    36,    37,    38,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      79,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,    42,    43,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46
};

static const yytype_int16 yycheck[] =
{
      24,    24,    45,     8,     0,    73,    69,    18,   154,     3,
      15,    28,    29,     9,    25,    39,    40,     3,    56,    30,
       3,     7,     8,     9,    10,    37,    50,    46,    53,    50,
      26,    11,    12,    13,    14,    15,    53,    66,    23,     0,
     103,    50,    28,    29,    37,    69,    71,    72,    50,    70,
      32,    33,    67,    50,    71,    49,    68,     3,    51,    78,
      45,   207,   208,    72,   107,    11,    12,    13,    14,    15,
      72,    57,    58,    59,    60,    72,    87,    71,    50,   103,
     148,    50,    64,    65,    18,    71,    72,    50,    71,    69,
      95,    54,    52,    53,   113,    55,    30,    61,    62,    63,
      72,    50,    50,    72,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   107,    72,    72,    36,    72,   146,   171,   114,
      50,   150,   151,   152,   202,    52,    53,    50,    50,    49,
      50,   126,    71,   154,    37,    51,    11,    12,    13,    14,
      15,    54,    72,    53,    71,   223,   224,   225,     3,    72,
      72,    54,     7,     8,     9,    10,    30,    31,   236,   165,
     238,    71,   240,     3,   217,   243,   161,   245,    11,    12,
      13,    14,    15,    28,    29,     3,   171,    52,    53,     7,
       8,     9,    10,   135,   136,   137,   138,   221,   221,    59,
      60,    71,    34,    35,    69,    71,    71,   226,   227,   228,
      28,    29,    57,    58,    59,    60,    50,    51,    49,    50,
      49,    50,   131,   132,     3,    71,    71,    72,     7,     8,
       9,    10,   217,    49,   219,   133,   134,   139,   140,    57,
      58,    59,    60,    49,     3,    20,    49,     3,    71,    28,
      29,     3,    18,    71,    72,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    49,    19,    20,    21,
      22,    23,    24,    25,    26,   142,    28,    29,    57,    58,
      59,    60,   141,   144,    22,   143,   165,   171,   145,     3,
      69,   108,    71,     7,     8,     9,    10,    49,    87,     9,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    28,    29,     3,    69,    70,    71,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      54,    28,    29,    57,    58,    59,    60,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    71,    -1,    -1,
      -1,    52,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,     3,    -1,    -1,    -1,     7,     8,
       9,    10,    69,    70,    71,    -1,    -1,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,     3,    28,
      29,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    28,    29,    -1,    -1,    -1,    57,    58,
      59,    60,     3,    -1,    -1,    -1,     7,     8,     9,    10,
      69,    -1,    71,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    71,    -1,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    -1,    57,    58,    59,    60,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,     3,    -1,    -1,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    57,
      58,    59,    60,    -1,    -1,    -1,    28,    29,    -1,    -1,
      -1,    69,    -1,    71,     3,    -1,    -1,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    28,
      29,     3,    -1,    -1,    -1,     7,     8,     9,    10,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    28,    29,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    13,    14,    15,    75,    96,    99,   118,
     119,   120,     0,     3,    49,    71,    97,    98,   100,   119,
     100,    49,    50,    52,    53,    69,    71,    96,    99,   111,
     121,    72,    98,   100,     3,     7,     8,     9,    10,    28,
      29,    57,    58,    59,    60,    69,    71,    76,    77,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   104,    54,    79,    91,    95,     3,    16,
      17,    19,    20,    21,    22,    23,    24,    25,    26,    49,
      70,    92,    94,    96,   109,   110,   111,   112,   113,   114,
     115,   116,   117,     3,    72,    99,   101,   102,   103,    96,
     111,    79,    79,    53,    55,   104,   105,   106,   107,   108,
      94,    28,    29,    53,    71,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    52,    93,    79,    61,    62,
      63,    59,    60,    30,    31,    32,    33,    64,    65,    34,
      35,    56,    66,    67,    36,    37,    68,    54,    51,    90,
      71,    71,    71,   109,    71,     3,    49,    49,    49,    94,
      49,    50,    70,   113,   100,    50,    72,    50,    72,    90,
       3,    50,    70,   104,    52,   108,    72,    94,    72,    78,
      92,    92,    79,    79,    79,    81,    81,    82,    82,    83,
      83,    83,    83,    84,    84,    85,    86,    87,    88,    89,
      94,   109,    51,    94,    94,    94,    20,    96,   114,    49,
      49,    92,   102,     3,    54,    70,   104,   106,    54,    50,
      72,    51,   109,    72,    72,    72,    71,   114,   114,   104,
      92,    91,   109,   109,   109,    94,    72,    94,    72,    94,
      18,    72,   109,    72,   109,    72,   109,    49,   109,   109
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 70 "compiler.y"
    {//创建一个根节点
    root = (yyvsp[(1) - (1)].rootN);
}
    break;

  case 3:
#line 77 "compiler.y"
    {
    (yyval.expN) = create_exp_tree((yyvsp[(1) - (1)].IDN)->line,0);//$1是ID_Node
    (yyval.expN)->info.prim_info.detail.ID = (yyvsp[(1) - (1)].IDN);
}
    break;

  case 4:
#line 82 "compiler.y"
    {
    (yyval.expN) = (yyvsp[(1) - (1)].expN);
}
    break;

  case 5:
#line 86 "compiler.y"
    {
    (yyval.expN) = (yyvsp[(1) - (1)].expN);
}
    break;

  case 6:
#line 89 "compiler.y"
    {
    (yyval.expN) = (yyvsp[(1) - (1)].expN);
    
}
    break;

  case 7:
#line 93 "compiler.y"
    {
    (yyval.expN) = (yyvsp[(1) - (1)].expN);
}
    break;

  case 8:
#line 97 "compiler.y"
    {
    (yyval.expN) = create_exp_tree((yyvsp[(2) - (3)].expN)->line,5);
    (yyval.expN) ->info.prim_info.detail.exp = (yyvsp[(2) - (3)].expN);
}
    break;

  case 9:
#line 105 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(1);
    (yyval.expN)->info.post_info.type2 = post_NA;
    (yyval.expN)->info.post_info.arg_list = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->info.post_info.post_exp = NULL;
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 10:
#line 112 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(1);
    (yyval.expN)->info.post_info.post_exp = (yyvsp[(1) - (4)].expN);
    (yyval.expN)->info.post_info.arg_list = (yyvsp[(3) - (4)].expN);
    (yyval.expN)->info.post_info.type2 = ARRAY_CALL;
    (yyval.expN)->line = (yyvsp[(1) - (4)].expN)->line;
    //数组调用
}
    break;

  case 11:
#line 121 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(1);
    (yyval.expN)->info.post_info.type2 = FUNC_CALL;
    (yyval.expN)->info.post_info.post_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.post_info.arg_list = NULL;
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
    //函数调用
}
    break;

  case 12:
#line 129 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(1);
    (yyval.expN)->info.post_info.type2 = FUNC_CALL;
    (yyval.expN)->info.post_info.post_exp = (yyvsp[(1) - (4)].expN);
    (yyval.expN)->info.post_info.arg_list = (yyvsp[(3) - (4)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (4)].expN)->line;
    //函数调用
}
    break;

  case 13:
#line 137 "compiler.y"
    {
    //++
    (yyval.expN) = create_exp_tree(1);
    (yyval.expN)->info.post_info.type2 = INC;
    (yyval.expN)->info.post_info.post_exp = (yyvsp[(1) - (2)].expN);
    (yyval.expN)->info.post_info.arg_list = NULL;
    (yyval.expN)->line = (yyvsp[(1) - (2)].expN)->line;
}
    break;

  case 14:
#line 145 "compiler.y"
    {
    //--
    (yyval.expN) = create_exp_tree(1);
    (yyval.expN)->info.post_info.type2 = DEC;
    (yyval.expN)->info.post_info.post_exp = (yyvsp[(1) - (2)].expN);
    (yyval.expN)->info.post_info.arg_list = NULL;
    (yyval.expN)->line = (yyvsp[(1) - (2)].expN)->line;
}
    break;

  case 15:
#line 156 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(14);
    (yyval.expN)->info.argument_info.type2 = SINGLE;
    (yyval.expN)->info.argument_info.argu_exp = NULL;
    (yyval.expN)->info.argument_info.assig_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 16:
#line 163 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(14);
    (yyval.expN)->info.argument_info.type2 = GROUP;
    (yyval.expN)->info.argument_info.argu_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.argument_info.assig_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 17:
#line 174 "compiler.y"
    {
    //printf("postfix");
    (yyval.expN) = create_exp_tree(13);
    (yyval.expN)->info.unary_info.type2 = unary_NA;
    (yyval.expN)->info.unary_info.post_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->info.unary_info.unary_exp = NULL;
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 18:
#line 182 "compiler.y"
    {
    //++
    (yyval.expN) = create_exp_tree(13);
    (yyval.expN)->info.unary_info.type2 = t_INC_OP;
    (yyval.expN)->info.unary_info.unary_exp = (yyvsp[(2) - (2)].expN);
    (yyval.expN)->info.unary_info.post_exp = NULL;
    (yyval.expN)->line = (yyvsp[(2) - (2)].expN)->line;
}
    break;

  case 19:
#line 190 "compiler.y"
    {
    //--
    (yyval.expN) = create_exp_tree(13);
    (yyval.expN)->info.unary_info.type2 = t_DEC_OP;
    (yyval.expN)->info.unary_info.unary_exp = (yyvsp[(2) - (2)].expN);
    (yyval.expN)->info.unary_info.post_exp = NULL;
    (yyval.expN)->line = (yyvsp[(2) - (2)].expN)->line;
}
    break;

  case 20:
#line 198 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(13);
    (yyval.expN)->info.unary_info.type2 = (yyvsp[(1) - (2)].arykind);
    (yyval.expN)->info.unary_info.post_exp = NULL;
    (yyval.expN)->info.unary_info.unary_exp = (yyvsp[(2) - (2)].expN);
    (yyval.expN)->line = (yyvsp[(2) - (2)].expN)->line;
}
    break;

  case 21:
#line 209 "compiler.y"
    {
    (yyval.arykind) = POS;
}
    break;

  case 22:
#line 212 "compiler.y"
    {
    (yyval.arykind) = NEG;
}
    break;

  case 23:
#line 215 "compiler.y"
    {
    (yyval.arykind) = BIT_NEG;
}
    break;

  case 24:
#line 218 "compiler.y"
    {
    (yyval.arykind) = FEI;
}
    break;

  case 25:
#line 225 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(12);
    (yyval.expN)->info.mul_info.type2 = mul_NA;
    (yyval.expN)->info.mul_info.unary_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->info.mul_info.mul_exp = NULL;
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 26:
#line 232 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(12);
    (yyval.expN)->info.mul_info.type2 = MUL_OP;
    (yyval.expN)->info.mul_info.unary_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->info.mul_info.mul_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 27:
#line 239 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(12);
    (yyval.expN)->info.mul_info.type2 = DIV_OP;
    (yyval.expN)->info.mul_info.unary_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->info.mul_info.mul_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 28:
#line 246 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(12);
    (yyval.expN)->info.mul_info.type2 = MOD;
    (yyval.expN)->info.mul_info.unary_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->info.mul_info.mul_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 29:
#line 257 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(11);
    (yyval.expN)->info.add_info.type2 = add_NA;
    (yyval.expN)->info.add_info.add_exp = NULL;
    (yyval.expN)->info.add_info.mul_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 30:
#line 264 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(11);
    (yyval.expN)->info.add_info.type2 = ADD_OP;
    (yyval.expN)->info.add_info.add_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.add_info.mul_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 31:
#line 271 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(11);
    (yyval.expN)->info.add_info.type2 = MINUS_OP;
    (yyval.expN)->info.add_info.add_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.add_info.mul_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 32:
#line 282 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(10);
    (yyval.expN)->info.shift_info.type2 = shift_NA;
    (yyval.expN)->info.shift_info.shift_exp = NULL;
    (yyval.expN)->info.shift_info.addtive_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
    
}
    break;

  case 33:
#line 290 "compiler.y"
    {
    //<<
    (yyval.expN) = create_exp_tree(10);
    (yyval.expN)->info.shift_info.type2 = LEFT;
    (yyval.expN)->info.shift_info.shift_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.shift_info.addtive_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 34:
#line 298 "compiler.y"
    {
    //>>
    (yyval.expN) = create_exp_tree(10);
    (yyval.expN)->info.shift_info.type2 = RIGHT;
    (yyval.expN)->info.shift_info.shift_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.shift_info.addtive_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 35:
#line 310 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(9);
    (yyval.expN)->info.rela_info.type2 = relation_NA;
    (yyval.expN)->info.rela_info.relation_exp = NULL;
    (yyval.expN)->info.rela_info.shift_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 36:
#line 317 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(9);
    (yyval.expN)->info.rela_info.type2 = LES;
    (yyval.expN)->info.rela_info.relation_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.rela_info.shift_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 37:
#line 324 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(9);
    (yyval.expN)->info.rela_info.type2 = GT;
    (yyval.expN)->info.rela_info.relation_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.rela_info.shift_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 38:
#line 331 "compiler.y"
    {
    // <=
    (yyval.expN) = create_exp_tree(9);
    (yyval.expN)->info.rela_info.type2 = LE;
    (yyval.expN)->info.rela_info.relation_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.rela_info.shift_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 39:
#line 339 "compiler.y"
    {
    // >=
    (yyval.expN) = create_exp_tree(9);
    (yyval.expN)->info.rela_info.type2 = GE;
    (yyval.expN)->info.rela_info.relation_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.rela_info.shift_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 40:
#line 351 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(8);
    (yyval.expN)->info.equal_info.type2 = equal_NA;
    (yyval.expN)->info.equal_info.equal_exp = NULL;
    (yyval.expN)->info.equal_info.relation_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 41:
#line 358 "compiler.y"
    {
    // ==
    (yyval.expN) = create_exp_tree(8);
    (yyval.expN)->info.equal_info.type2 = EQ;
    (yyval.expN)->info.equal_info.equal_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.equal_info.relation_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 42:
#line 366 "compiler.y"
    {
    // !=
    (yyval.expN) = create_exp_tree(8);
    (yyval.expN)->info.equal_info.type2 = NE;
    (yyval.expN)->info.equal_info.equal_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.equal_info.relation_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 43:
#line 377 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(7);
    (yyval.expN)->info.and_info.and_exp = NULL;
    (yyval.expN)->info.and_info.equal_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 44:
#line 383 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(7);
    (yyval.expN)->info.and_info.and_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.and_info.equal_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 45:
#line 393 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(6);
    (yyval.expN)->info.excl_or_info.exclusive_or_exp = NULL;
    (yyval.expN)->info.excl_or_info.and_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 46:
#line 399 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(6);
    (yyval.expN)->info.excl_or_info.exclusive_or_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.excl_or_info.and_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 47:
#line 409 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(5);
    (yyval.expN)->info.incl_or_info.inclusive_or_exp = NULL;
    (yyval.expN)->info.incl_or_info.exclusive_or_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 48:
#line 415 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(5);
    (yyval.expN)->info.incl_or_info.inclusive_or_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.incl_or_info.exclusive_or_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 49:
#line 425 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(4);
    (yyval.expN)->info.logi_and_info.logical_and_exp = NULL;
    (yyval.expN)->info.logi_and_info.inclusive_or_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 50:
#line 431 "compiler.y"
    {
    //&&
    (yyval.expN) = create_exp_tree(4);
    (yyval.expN)->info.logi_and_info.logical_and_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.logi_and_info.inclusive_or_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 51:
#line 442 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(3);
    (yyval.expN)->info.logi_or_info.logical_or_exp = NULL;
    (yyval.expN)->info.logi_or_info.logical_and_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 52:
#line 448 "compiler.y"
    {
    //||
    (yyval.expN) = create_exp_tree(3);
    (yyval.expN)->info.logi_or_info.logical_or_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.logi_or_info.logical_and_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 53:
#line 458 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(16);
    (yyval.expN)->info.cond_info.logical_or_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->info.cond_info.exp = NULL;
    (yyval.expN)->info.cond_info.cond_exp = NULL;
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 54:
#line 465 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(16);
    (yyval.expN)->info.cond_info.logical_or_exp = (yyvsp[(1) - (5)].expN);
    (yyval.expN)->info.cond_info.exp = (yyvsp[(5) - (5)].expN);
    (yyval.expN)->info.cond_info.cond_exp = (yyvsp[(3) - (5)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (5)].expN)->line;
}
    break;

  case 55:
#line 476 "compiler.y"
    {//logical_or_expression
    //条件表达式
    (yyval.expN) = create_exp_tree(2);
    (yyval.expN)->info.assign_info.type2 = assign_NA;
    (yyval.expN)->info.assign_info.unary_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->info.assign_info.assign_exp =  NULL;
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 56:
#line 484 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(2);
    (yyval.expN)->info.assign_info.type2 = (yyvsp[(2) - (3)].assignkind);
    (yyval.expN)->info.assign_info.unary_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.assign_info.assign_exp =  (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (3)].expN)->line;
}
    break;

  case 57:
#line 495 "compiler.y"
    {
    (yyval.assignkind) = t_ASSIGNMENT;
}
    break;

  case 58:
#line 498 "compiler.y"
    {
    //*=
    (yyval.assignkind) = t_MUL_ASSIGN;
}
    break;

  case 59:
#line 502 "compiler.y"
    {
    // /=
    (yyval.assignkind) = t_DIV_ASSIGN;
}
    break;

  case 60:
#line 506 "compiler.y"
    {
    // %=
    (yyval.assignkind) = t_MOD_ASSIGN;
}
    break;

  case 61:
#line 510 "compiler.y"
    {
    // +=
    (yyval.assignkind) = t_ADD_ASSIGN;
}
    break;

  case 62:
#line 514 "compiler.y"
    {
    // -=
    (yyval.assignkind) = t_SUB_ASSIGN;
}
    break;

  case 63:
#line 518 "compiler.y"
    {
    // <<=
    (yyval.assignkind) = t_LEFT_ASSIGN;
}
    break;

  case 64:
#line 522 "compiler.y"
    {
    // >>=
    (yyval.assignkind) = t_RIGHT_ASSIGN;
}
    break;

  case 65:
#line 526 "compiler.y"
    {
    // &=
    (yyval.assignkind) = t_AND_ASSIGN;
}
    break;

  case 66:
#line 530 "compiler.y"
    {
    // ^=
    (yyval.assignkind) = t_XOR_ASSIGN;
}
    break;

  case 67:
#line 534 "compiler.y"
    {
    // |=
    (yyval.assignkind) = t_OR_ASSIGN;
}
    break;

  case 68:
#line 542 "compiler.y"
    {
    //赋值表达式
    (yyval.expN) = create_exp_tree(17);
    (yyval.expN)->info.exp_root.next_exp = NULL;
    (yyval.expN)->info.exp_root.assign_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 69:
#line 549 "compiler.y"
    {
    //逗号表达式
    (yyval.expN) = create_exp_tree(17);
    (yyval.expN)->info.exp_root.next_exp = (yyvsp[(1) - (3)].expN);
    (yyval.expN)->info.exp_root.assign_exp = (yyvsp[(3) - (3)].expN);
    (yyval.expN)->line = (yyvsp[(3) - (3)].expN)->line;
}
    break;

  case 70:
#line 559 "compiler.y"
    {
    (yyval.expN) = create_exp_tree(15);
    (yyval.expN)->info.const_info.cond_exp = (yyvsp[(1) - (1)].expN);
    (yyval.expN)->line = (yyvsp[(1) - (1)].expN)->line;
}
    break;

  case 71:
#line 567 "compiler.y"
    {
    (yyval.declarationN) = create_declaration_tree((yyvsp[(1) - (2)].typekind));
}
    break;

  case 72:
#line 570 "compiler.y"
    {
    (yyval.declarationN) = create_declaration_tree((yyvsp[(1) - (3)].typekind));
    (yyval.declarationN)->decl_list = (yyvsp[(2) - (3)].declaratorN);
    (yyval.declarationN)->line = (yyvsp[(2) - (3)].declaratorN)->line;
}
    break;

  case 73:
#line 579 "compiler.y"
    {
    (yyval.declaratorN) = (yyvsp[(1) - (1)].declaratorN);
}
    break;

  case 74:
#line 582 "compiler.y"
    {
    (yyval.declaratorN) = (yyvsp[(1) - (3)].declaratorN);
    while((yyvsp[(1) - (3)].declaratorN)->next != NULL)
    (yyvsp[(1) - (3)].declaratorN) = (yyvsp[(1) - (3)].declaratorN)->next;
    (yyvsp[(1) - (3)].declaratorN)->next = (yyvsp[(3) - (3)].declaratorN);
}
    break;

  case 75:
#line 591 "compiler.y"
    {
    (yyval.declaratorN) = (yyvsp[(1) - (1)].declaratorN);
}
    break;

  case 76:
#line 594 "compiler.y"
    {
    (yyval.declaratorN) = create_declarator_tree((yyvsp[(1) - (3)].declaratorN),(yyvsp[(3) - (3)].initN));
    (yyval.declaratorN)->line = (yyvsp[(1) - (3)].declaratorN)->line;
}
    break;

  case 77:
#line 603 "compiler.y"
    {
    (yyval.typekind) = t_VOID;
}
    break;

  case 78:
#line 606 "compiler.y"
    {
    (yyval.typekind) = t_CHAR;
}
    break;

  case 79:
#line 609 "compiler.y"
    {
    (yyval.typekind) = t_INT;
}
    break;

  case 80:
#line 612 "compiler.y"
    {
    (yyval.typekind) = t_DOUBLE;
}
    break;

  case 81:
#line 615 "compiler.y"
    {
    (yyval.typekind) = t_BOOL;
}
    break;

  case 82:
#line 623 "compiler.y"
    {
    //变量
    (yyval.declaratorN) = create_declarator_tree(0);
    (yyval.declaratorN)->info.decl_info.detail.ID_info.ID_list = (yyvsp[(1) - (1)].IDN);
    (yyval.declaratorN)->line = (yyvsp[(1) - (1)].IDN)->line;
}
    break;

  case 83:
#line 629 "compiler.y"
    {
    //.....
    (yyval.declaratorN) = (yyvsp[(2) - (3)].declaratorN);
}
    break;

  case 84:
#line 633 "compiler.y"
    {
    //数组
    //printf("assignment_expression");
    (yyval.declaratorN) = create_declarator_tree(1);
    (yyval.declaratorN)->info.decl_info.detail.arr_info.arr_type = arr_C_exp;
    (yyval.declaratorN)->info.decl_info.detail.arr_info.exp = (yyvsp[(3) - (4)].expN);
    (yyval.declaratorN)->info.decl_info.detail.arr_info.decl_tree = (yyvsp[(1) - (4)].declaratorN);
    (yyval.declaratorN)->line = (yyvsp[(1) - (4)].declaratorN)->line;
}
    break;

  case 85:
#line 642 "compiler.y"
    {
    //数组
    (yyval.declaratorN) = create_declarator_tree(1);
    (yyval.declaratorN)->info.decl_info.detail.arr_info.arr_type = arr_NA;
    (yyval.declaratorN)->info.decl_info.detail.arr_info.exp = NULL;
    (yyval.declaratorN)->info.decl_info.detail.arr_info.decl_tree = (yyvsp[(1) - (3)].declaratorN);
    (yyval.declaratorN)->line = (yyvsp[(1) - (3)].declaratorN)->line;
}
    break;

  case 86:
#line 650 "compiler.y"
    {
    //函数
    (yyval.declaratorN) = create_declarator_tree(2);
    (yyval.declaratorN)->info.decl_info.detail.func_info.func_type = PARAM;
    (yyval.declaratorN)->info.decl_info.detail.func_info.decl_tree = (yyvsp[(1) - (4)].declaratorN);
    (yyval.declaratorN)->info.decl_info.detail.func_info.list.param_list = (yyvsp[(3) - (4)].paraN);
    (yyval.declaratorN)->line = (yyvsp[(1) - (4)].declaratorN)->line;
}
    break;

  case 87:
#line 658 "compiler.y"
    {
    //函数
    (yyval.declaratorN) = create_declarator_tree(2);
    (yyval.declaratorN)->info.decl_info.detail.func_info.func_type = IDENT;
    (yyval.declaratorN)->info.decl_info.detail.func_info.decl_tree = (yyvsp[(1) - (4)].declaratorN);
    (yyval.declaratorN)->info.decl_info.detail.func_info.list.ID_list = (yyvsp[(3) - (4)].IDN);
    (yyval.declaratorN)->line = (yyvsp[(1) - (4)].declaratorN)->line;
}
    break;

  case 88:
#line 666 "compiler.y"
    {
    //函数
    (yyval.declaratorN) = create_declarator_tree(2);
    (yyval.declaratorN)->info.decl_info.detail.func_info.func_type = func_NA;
    (yyval.declaratorN)->info.decl_info.detail.func_info.decl_tree = (yyvsp[(1) - (3)].declaratorN);
    (yyval.declaratorN)->info.decl_info.detail.func_info.list.param_list = NULL;
    (yyval.declaratorN)->line = (yyvsp[(1) - (3)].declaratorN)->line;
}
    break;

  case 89:
#line 679 "compiler.y"
    {
    (yyval.paraN) = (yyvsp[(1) - (1)].paraN);
}
    break;

  case 90:
#line 682 "compiler.y"
    {
    (yyval.paraN) = (yyvsp[(1) - (3)].paraN);
    while((yyvsp[(1) - (3)].paraN)->next != NULL)
    (yyvsp[(1) - (3)].paraN) = (yyvsp[(1) - (3)].paraN)->next;
    (yyvsp[(1) - (3)].paraN)->next = (yyvsp[(3) - (3)].paraN);
}
    break;

  case 91:
#line 691 "compiler.y"
    {
    (yyval.paraN) = create_param_tree((yyvsp[(1) - (2)].typekind));
    (yyval.paraN)->declarator = (yyvsp[(2) - (2)].declaratorN);
}
    break;

  case 92:
#line 695 "compiler.y"
    {
    (yyval.paraN) = create_param_tree((yyvsp[(1) - (1)].typekind));
}
    break;

  case 93:
#line 701 "compiler.y"
    {
    (yyval.IDN) = (yyvsp[(1) - (1)].IDN);
}
    break;

  case 94:
#line 704 "compiler.y"
    {
    (yyval.IDN) = (yyvsp[(1) - (3)].IDN);
    while((yyvsp[(1) - (3)].IDN)->next != NULL)
    (yyvsp[(1) - (3)].IDN) = (yyvsp[(1) - (3)].IDN)->next;
    (yyvsp[(1) - (3)].IDN)->next = (yyvsp[(3) - (3)].IDN);
}
    break;

  case 95:
#line 714 "compiler.y"
    {
    (yyval.initN) = create_initializer_tree(0);
    (yyval.initN)->info.assign_exp = (yyvsp[(1) - (1)].expN);
}
    break;

  case 96:
#line 718 "compiler.y"
    {
    //列表初始化 {1,1,1}
    (yyval.initN) = create_initializer_tree(1);
    (yyval.initN)->info.init_list = (yyvsp[(2) - (3)].initl);
}
    break;

  case 97:
#line 723 "compiler.y"
    {//init_list->next
    //列表初始化 {1,1,1,}
    (yyval.initN) = create_initializer_tree(1);
    (yyval.initN)->info.init_list = (yyvsp[(2) - (4)].initl);
}
    break;

  case 98:
#line 731 "compiler.y"
    {
    (yyval.initl) = create_initial_list_tree(0);
    (yyval.initl)->initer = (yyvsp[(1) - (1)].initN);
}
    break;

  case 99:
#line 735 "compiler.y"
    {
    (yyval.initl) = create_initial_list_tree(1);
    (yyval.initl)->initer = (yyvsp[(2) - (2)].initN);
    (yyval.initl)->design_list = (yyvsp[(1) - (2)].design);
}
    break;

  case 100:
#line 740 "compiler.y"
    {// 在分析时需要判断next == NULL来确定是否到这个list的结尾
    (yyval.initl) = (yyvsp[(1) - (3)].initl);
    while((yyvsp[(1) - (3)].initl)->next != NULL)
    (yyvsp[(1) - (3)].initl) = (yyvsp[(1) - (3)].initl)->next;
    (yyvsp[(1) - (3)].initl)->next = create_initial_list_tree(0);
    (yyvsp[(1) - (3)].initl)->next->initer = (yyvsp[(3) - (3)].initN);
    
}
    break;

  case 101:
#line 748 "compiler.y"
    {
    (yyval.initl) = (yyvsp[(1) - (4)].initl);
    while((yyvsp[(1) - (4)].initl)->next != NULL)
    (yyvsp[(1) - (4)].initl) = (yyvsp[(1) - (4)].initl)->next;
    (yyvsp[(1) - (4)].initl)->next = create_initial_list_tree(1);
    (yyvsp[(1) - (4)].initl)->next->initer = (yyvsp[(4) - (4)].initN);
    (yyvsp[(1) - (4)].initl)->next->design_list = (yyvsp[(3) - (4)].design);
}
    break;

  case 102:
#line 759 "compiler.y"
    {
    (yyval.design) = (yyvsp[(1) - (2)].design);
}
    break;

  case 103:
#line 765 "compiler.y"
    {
    (yyval.design) = (yyvsp[(1) - (1)].design);
}
    break;

  case 104:
#line 768 "compiler.y"
    {
    (yyval.design) = (yyvsp[(1) - (2)].design);
    while((yyvsp[(1) - (2)].design)->next != NULL)
    (yyvsp[(1) - (2)].design)=(yyvsp[(1) - (2)].design)->next;
    (yyvsp[(1) - (2)].design)->next = (yyvsp[(2) - (2)].design);
}
    break;

  case 105:
#line 777 "compiler.y"
    {
    (yyval.design) = create_design_tree(0);
    (yyval.design)->info.logical_or_exp = (yyvsp[(2) - (3)].expN);
}
    break;

  case 106:
#line 781 "compiler.y"
    {
    (yyval.design) = create_design_tree(1);
    (yyval.design)->info.ID = (yyvsp[(2) - (2)].IDN);
}
    break;

  case 107:
#line 789 "compiler.y"
    {
    (yyval.statN) = (yyvsp[(1) - (1)].statN);
}
    break;

  case 108:
#line 792 "compiler.y"
    {
    (yyval.statN) = (yyvsp[(1) - (1)].statN);
}
    break;

  case 109:
#line 795 "compiler.y"
    {
    (yyval.statN) = (yyvsp[(1) - (1)].statN);
}
    break;

  case 110:
#line 798 "compiler.y"
    {
    (yyval.statN) = (yyvsp[(1) - (1)].statN);
}
    break;

  case 111:
#line 801 "compiler.y"
    {
    (yyval.statN) = (yyvsp[(1) - (1)].statN);
}
    break;

  case 112:
#line 804 "compiler.y"
    {
    (yyval.statN) = (yyvsp[(1) - (1)].statN);
}
    break;

  case 113:
#line 811 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(0);
    (yyval.statN)->stat_info.label_info.ID = (yyvsp[(1) - (3)].IDN);
    (yyval.statN)->stat_info.label_info.exp = NULL;
    (yyval.statN)->stat_info.label_info.stat = (yyvsp[(3) - (3)].statN);
}
    break;

  case 114:
#line 817 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(0);
    (yyval.statN)->stat_info.label_info.ID = NULL;
    (yyval.statN)->stat_info.label_info.exp = (yyvsp[(2) - (4)].expN);
    (yyval.statN)->stat_info.label_info.stat = (yyvsp[(4) - (4)].statN);
}
    break;

  case 115:
#line 827 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(1);
    (yyval.statN)->stat_info.compound_info.type2 = SINGLE;
    (yyval.statN)->stat_info.compound_info.blist = NULL;
}
    break;

  case 116:
#line 832 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(1);
    (yyval.statN)->stat_info.compound_info.type2 = GROUP;
    (yyval.statN)->stat_info.compound_info.blist = (yyvsp[(2) - (3)].block);
}
    break;

  case 117:
#line 840 "compiler.y"
    {
    (yyval.block) = (yyvsp[(1) - (1)].block);
    
}
    break;

  case 118:
#line 844 "compiler.y"
    {
    (yyval.block) = (yyvsp[(1) - (2)].block);
    while((yyvsp[(1) - (2)].block)->next != NULL)
    (yyvsp[(1) - (2)].block) = (yyvsp[(1) - (2)].block)->next;
    (yyvsp[(1) - (2)].block)->next = (yyvsp[(2) - (2)].block);
}
    break;

  case 119:
#line 853 "compiler.y"
    {
    (yyval.block) = create_block_tree();
    (yyval.block)->declaration = (yyvsp[(1) - (1)].declarationN);
}
    break;

  case 120:
#line 857 "compiler.y"
    {
    (yyval.block) = create_block_tree();
    (yyval.block)->statement = (yyvsp[(1) - (1)].statN);
}
    break;

  case 121:
#line 864 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(2);
    (yyval.statN)->stat_info.exp_info.exp = NULL;
}
    break;

  case 122:
#line 868 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(2);
    (yyval.statN)->stat_info.exp_info.exp = (yyvsp[(1) - (2)].expN);
}
    break;

  case 123:
#line 876 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(3);
    (yyval.statN)->stat_info.select_info.type2 = t_IF;
    (yyval.statN)->stat_info.select_info.exp = (yyvsp[(3) - (5)].expN);
    (yyval.statN)->stat_info.select_info.stat1 = (yyvsp[(5) - (5)].statN);
    (yyval.statN)->stat_info.select_info.stat2 = NULL;
}
    break;

  case 124:
#line 883 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(3);
    (yyval.statN)->stat_info.select_info.type2 = t_IF_ELSE;
    (yyval.statN)->stat_info.select_info.exp = (yyvsp[(3) - (7)].expN);
    (yyval.statN)->stat_info.select_info.stat1 = (yyvsp[(5) - (7)].statN);
    (yyval.statN)->stat_info.select_info.stat2 = (yyvsp[(7) - (7)].statN);
}
    break;

  case 125:
#line 890 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(3);
    (yyval.statN)->stat_info.select_info.type2 = t_SWITCH;
    (yyval.statN)->stat_info.select_info.exp = (yyvsp[(3) - (5)].expN);
    (yyval.statN)->stat_info.select_info.stat1 = (yyvsp[(5) - (5)].statN);
    (yyval.statN)->stat_info.select_info.stat2 = NULL;
}
    break;

  case 126:
#line 901 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(4);
    (yyval.statN)->stat_info.iter_info.type2 = t_WHILE;
    (yyval.statN)->stat_info.iter_info.exp = (yyvsp[(3) - (5)].expN);
    (yyval.statN)->stat_info.iter_info.stat1 = (yyvsp[(5) - (5)].statN);
    (yyval.statN)->stat_info.iter_info.stat2 = NULL;
    (yyval.statN)->stat_info.iter_info.stat3 = NULL;
    (yyval.statN)->stat_info.iter_info.decl = NULL;
}
    break;

  case 127:
#line 910 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(4);
    (yyval.statN)->stat_info.iter_info.type2 = t_DO_WHILE;
    (yyval.statN)->stat_info.iter_info.exp = (yyvsp[(5) - (7)].expN);
    (yyval.statN)->stat_info.iter_info.stat1 = (yyvsp[(2) - (7)].statN);
    (yyval.statN)->stat_info.iter_info.stat2 = NULL;
    (yyval.statN)->stat_info.iter_info.stat3 = NULL;
    (yyval.statN)->stat_info.iter_info.decl = NULL;
}
    break;

  case 128:
#line 919 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(4);
    (yyval.statN)->stat_info.iter_info.type2 = FOR1;
    (yyval.statN)->stat_info.iter_info.exp = NULL;
    (yyval.statN)->stat_info.iter_info.stat1 = (yyvsp[(3) - (6)].statN);
    (yyval.statN)->stat_info.iter_info.stat2 = (yyvsp[(4) - (6)].statN);
    (yyval.statN)->stat_info.iter_info.stat3 = (yyvsp[(6) - (6)].statN);
    (yyval.statN)->stat_info.iter_info.decl = NULL;
}
    break;

  case 129:
#line 928 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(4);
    (yyval.statN)->stat_info.iter_info.type2 = FOR2;
    (yyval.statN)->stat_info.iter_info.exp = (yyvsp[(5) - (7)].expN);
    (yyval.statN)->stat_info.iter_info.stat1 = (yyvsp[(3) - (7)].statN);
    (yyval.statN)->stat_info.iter_info.stat2 = (yyvsp[(4) - (7)].statN);
    (yyval.statN)->stat_info.iter_info.stat3 = (yyvsp[(7) - (7)].statN);
    (yyval.statN)->stat_info.iter_info.decl = NULL;
}
    break;

  case 130:
#line 937 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(4);
    (yyval.statN)->stat_info.iter_info.type2 = FOR3;
    (yyval.statN)->stat_info.iter_info.exp = NULL;
    (yyval.statN)->stat_info.iter_info.stat1 = (yyvsp[(4) - (6)].statN);
    (yyval.statN)->stat_info.iter_info.stat2 = (yyvsp[(6) - (6)].statN);
    (yyval.statN)->stat_info.iter_info.stat3 = NULL;
    (yyval.statN)->stat_info.iter_info.decl = (yyvsp[(3) - (6)].declarationN);
}
    break;

  case 131:
#line 946 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(4);
    (yyval.statN)->stat_info.iter_info.type2 = FOR4;
    (yyval.statN)->stat_info.iter_info.exp = (yyvsp[(5) - (7)].expN);
    (yyval.statN)->stat_info.iter_info.stat1 = (yyvsp[(4) - (7)].statN);
    (yyval.statN)->stat_info.iter_info.stat2 = (yyvsp[(7) - (7)].statN);
    (yyval.statN)->stat_info.iter_info.stat3 = NULL;
    (yyval.statN)->stat_info.iter_info.decl = (yyvsp[(3) - (7)].declarationN);
}
    break;

  case 132:
#line 959 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(5);
    (yyval.statN)->stat_info.jump_info.type2 = t_GOTO;
    (yyval.statN)->stat_info.jump_info.ID = (yyvsp[(2) - (3)].IDN);
    (yyval.statN)->stat_info.jump_info.exp = NULL;
}
    break;

  case 133:
#line 965 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(5);
    (yyval.statN)->stat_info.jump_info.type2 = t_CONTINUE;
    (yyval.statN)->stat_info.jump_info.ID = NULL;
    (yyval.statN)->stat_info.jump_info.exp = NULL;
}
    break;

  case 134:
#line 971 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(5);
    (yyval.statN)->stat_info.jump_info.type2 = t_BREAK;
    (yyval.statN)->stat_info.jump_info.ID = NULL;
    (yyval.statN)->stat_info.jump_info.exp = NULL;
}
    break;

  case 135:
#line 977 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(5);
    (yyval.statN)->stat_info.jump_info.type2 = RETURN1;
    (yyval.statN)->stat_info.jump_info.ID = NULL;
    (yyval.statN)->stat_info.jump_info.exp = NULL;
}
    break;

  case 136:
#line 983 "compiler.y"
    {
    (yyval.statN) = create_stat_tree(5);
    (yyval.statN)->stat_info.jump_info.type2 = RETURN2;
    (yyval.statN)->stat_info.jump_info.ID = NULL;
    (yyval.statN)->stat_info.jump_info.exp = (yyvsp[(2) - (3)].expN);
}
    break;

  case 137:
#line 992 "compiler.y"
    {
    (yyval.rootN) = (yyvsp[(1) - (1)].rootN);
}
    break;

  case 138:
#line 995 "compiler.y"
    {
    (yyval.rootN) = (yyvsp[(1) - (2)].rootN);
    while((yyvsp[(1) - (2)].rootN)->next != NULL)
    (yyvsp[(1) - (2)].rootN) = (yyvsp[(1) - (2)].rootN)->next;
    (yyvsp[(1) - (2)].rootN)->next = (yyvsp[(2) - (2)].rootN);
}
    break;

  case 139:
#line 1004 "compiler.y"
    {
    (yyval.rootN) = create_root_tree();
    (yyval.rootN)->type = Func_T;
    (yyval.rootN)->son.func_tree = (yyvsp[(1) - (1)].funcN);
    //函数定义
    //printf("function_definition");
}
    break;

  case 140:
#line 1011 "compiler.y"
    {
    (yyval.rootN) = create_root_tree();
    (yyval.rootN)->type = Decl_T;
    (yyval.rootN)->son.decl_tree = (yyvsp[(1) - (1)].declarationN);
    //变量声明
    //printf("declaration");
}
    break;

  case 141:
#line 1021 "compiler.y"
    {
    //这个形式的函数定义好像没有见过，基本用不上
    (yyval.funcN) = create_func_tree((yyvsp[(1) - (4)].typekind));
    (yyval.funcN)->func_name = (yyvsp[(2) - (4)].declaratorN);
    (yyval.funcN)->decl_list = (yyvsp[(3) - (4)].declarationN);
    (yyval.funcN)->stat_list = (yyvsp[(4) - (4)].statN);
    (yyval.funcN)->beg_line = (yyvsp[(2) - (4)].declaratorN)->line;
    //结束的行数得找一下
}
    break;

  case 142:
#line 1030 "compiler.y"
    {
    //这个文法对应的函数形式 int func_name(int , int b) {}
    (yyval.funcN) = create_func_tree((yyvsp[(1) - (3)].typekind));
    (yyval.funcN)->func_name = (yyvsp[(2) - (3)].declaratorN);
    (yyval.funcN)->decl_list = NULL;
    (yyval.funcN)->stat_list = (yyvsp[(3) - (3)].statN);
    (yyval.funcN)->beg_line = (yyvsp[(2) - (3)].declaratorN)->line;
    //结束的行数得找一下
}
    break;

  case 143:
#line 1042 "compiler.y"
    {
    (yyval.declarationN) = (yyvsp[(1) - (1)].declarationN);
}
    break;

  case 144:
#line 1045 "compiler.y"
    {
    (yyval.declarationN) = (yyvsp[(1) - (2)].declarationN);
    while((yyvsp[(1) - (2)].declarationN)->next != NULL)
    (yyvsp[(1) - (2)].declarationN) = (yyvsp[(1) - (2)].declarationN)->next;
    (yyvsp[(1) - (2)].declarationN)->next = (yyvsp[(2) - (2)].declarationN);
}
    break;


/* Line 1267 of yacc.c.  */
#line 3147 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 1053 "compiler.y"



void yyerror(char const *s)
{
    fflush(stdout);
    printf("\n%*s\n%*s\n", column, "^", column, s);
}


int main(int argc,char* argv[]) {
    yyin = fopen("/Users/egoist/Desktop/test.c","r");
    
    //freopen("output/output.txt","w", stdout);
    yyparse();
    printf("\n");
    //eval(root,0);    //输出语法分析树
    
    parser parser(root);
    
    //freeGramTree(root);
    
    fclose(yyin);
    return 0;
}


