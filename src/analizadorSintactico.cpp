/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "analizadorSintactico.y"

#include "nodos.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

//GLOBAL

cl_raiz* raiz;
extern int yylex();
void yyerror(const char *s) { printf("ERROR: %s \n", s); }


#line 85 "analizadorSintactico.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ANALIZADORSINTACTICO_HPP_INCLUDED
# define YY_YY_ANALIZADORSINTACTICO_HPP_INCLUDED
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
    t_nspacestd = 258,
    t_define = 259,
    t_new = 260,
    t_opregb = 261,
    t_cloregb = 262,
    t_return = 263,
    t_cout = 264,
    t_cin = 265,
    t_endl = 266,
    t_bool = 267,
    t_void = 268,
    t_long = 269,
    t_short = 270,
    t_int = 271,
    t_char = 272,
    t_float = 273,
    t_double = 274,
    t_struct = 275,
    t_string = 276,
    t_vector = 277,
    t_map = 278,
    t_umap = 279,
    t_set = 280,
    t_multiset = 281,
    t_queue = 282,
    t_pqueue = 283,
    t_stack = 284,
    t_bitset = 285,
    t_pair = 286,
    t_if = 287,
    t_else = 288,
    t_while = 289,
    t_for = 290,
    t_do = 291,
    t_true = 292,
    t_false = 293,
    t_break = 294,
    t_continue = 295,
    t_opsqrb = 296,
    t_closqrb = 297,
    t_eqeq = 298,
    t_nteq = 299,
    t_eq = 300,
    t_semicolon = 301,
    t_lteq = 302,
    t_gteq = 303,
    t_lt = 304,
    t_gt = 305,
    t_mod = 306,
    t_sum = 307,
    t_sumsum = 308,
    t_sub = 309,
    t_subsub = 310,
    t_astk = 311,
    t_div = 312,
    t_ternario = 313,
    t_not = 314,
    t_oror = 315,
    t_andand = 316,
    t_bitor = 317,
    t_bitand = 318,
    t_bitxor = 319,
    t_colon = 320,
    t_comma = 321,
    t_dot = 322,
    t_opcrlyb = 323,
    t_clocrlyb = 324,
    t_include = 325,
    t_hardstr = 326,
    t_charconst = 327,
    t_identificador = 328,
    t_intconst = 329,
    t_doubleconst = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "analizadorSintactico.y"

    cl_atributos_tokens *atributos;
    cl_declaracion *declaracion;
    cl_modificacion *modificacion;
    cl_expresion_booleana *expresion_booleana;
    cl_expresion_aritmetica* expresion_aritmetica;
    cl_ciclo *ciclo;
    cl_declaracion_funcion *declaracion_funcion;
    cl_llamada_funcion *llamada_funcion;
    cl_tipoDato *tipo_dato;
    cl_lista_argumentos *lista_argumentos; 
    cl_argumentos_llamada *argumentos_llamada;
    int es_exponencial;
    //Tipos de datos no primitivos tienen que ser apuntadores, deal with it
    vector<cl_declaracion_funcion*>* funciones_declaradas;
    //1,2,3
    int es_conector;
    cl_bloque_codigo* bloque_codigo;
    cl_if* iif;
    int nada;

#line 235 "analizadorSintactico.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALIZADORSINTACTICO_HPP_INCLUDED  */



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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   416

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

#define YYUNDEFTOK  2
#define YYMAXUTOK   330


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,   101,   102,   105,   106,   109,   112,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   130,
     136,   142,   148,   154,   160,   166,   171,   175,   182,   192,
     193,   194,   195,   196,   199,   200,   203,   204,   205,   210,
     213,   214,   215,   218,   224,   230,   236,   242,   248,   255,
     261,   275,   287,   295,   304,   316,   324,   331,   337,   350,
     359,   360,   361,   362,   363,   364,   367,   378,   385,   395,
     402,   412,   424,   436,   437,   442,   448,   460,   465,   470,
     475,   480,   485,   490,   494,   499,   503,   504,   505,   508,
     509,   529,   532,   538,   539,   543,   548,   549,   553,   559,
     572
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "t_nspacestd", "t_define", "t_new",
  "t_opregb", "t_cloregb", "t_return", "t_cout", "t_cin", "t_endl",
  "t_bool", "t_void", "t_long", "t_short", "t_int", "t_char", "t_float",
  "t_double", "t_struct", "t_string", "t_vector", "t_map", "t_umap",
  "t_set", "t_multiset", "t_queue", "t_pqueue", "t_stack", "t_bitset",
  "t_pair", "t_if", "t_else", "t_while", "t_for", "t_do", "t_true",
  "t_false", "t_break", "t_continue", "t_opsqrb", "t_closqrb", "t_eqeq",
  "t_nteq", "t_eq", "t_semicolon", "t_lteq", "t_gteq", "t_lt", "t_gt",
  "t_mod", "t_sum", "t_sumsum", "t_sub", "t_subsub", "t_astk", "t_div",
  "t_ternario", "t_not", "t_oror", "t_andand", "t_bitor", "t_bitand",
  "t_bitxor", "t_colon", "t_comma", "t_dot", "t_opcrlyb", "t_clocrlyb",
  "t_include", "t_hardstr", "t_charconst", "t_identificador", "t_intconst",
  "t_doubleconst", "$accept", "programa", "cabecera", "cabeceras",
  "declaracionesFuncion", "tipoPrimitivo", "tipoContenedor",
  "operadorAritmetico", "operadorAsignacion", "argumentosLLamada",
  "dimension", "dimensiones", "expresionAritmetica", "declaracionVariable",
  "operadorBooleano", "expresionBooleana", "ifStatement", "forStatement",
  "whileStatement", "listaArgumentos", "declaracionFuncion", "instruccion",
  "instrucciones", "bloqueCodigo", "argSalida", "argEntrada",
  "entradaSalida", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330
};
# endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -147,    20,     0,  -147,  -147,   -61,  -147,    89,  -147,  -147,
    -147,    67,     8,  -147,  -147,  -147,  -147,   -52,  -147,    11,
    -147,  -147,  -147,    28,  -147,   386,  -147,   -11,    17,    18,
     -10,    13,    31,    33,    35,    39,   214,   214,  -147,    -3,
      89,    89,    89,    89,    89,    89,    89,    89,    15,   214,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,   339,   339,    22,
     386,    41,    27,    43,    60,    61,    63,    81,    82,    83,
     286,   214,   214,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,   214,     3,   214,    93,   139,  -147,  -147,  -147,    89,
      89,  -147,  -147,  -147,  -147,  -147,  -147,  -147,    -2,   339,
     305,   339,  -147,   339,   339,  -147,    93,    23,  -147,  -147,
     129,   130,   132,    95,    96,  -147,    73,    97,   -38,   111,
    -147,  -147,  -147,   209,   113,   121,   123,  -147,   214,  -147,
    -147,  -147,   140,   -35,   126,   -34,   214,   214,   386,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,   214,  -147,
    -147,   214,   214,    22,  -147,  -147,  -147,  -147,  -147,   339,
    -147,  -147,   131,   133,   148,   269,     5,    12,   153,   339,
     141,  -147,  -147,   234,   189,   214,    22,    22,   214,  -147,
     339,  -147,   339,  -147,  -147,   -28,   214,   322,    22,  -147
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     7,     1,     4,     0,     6,     2,     3,    10,
       9,     0,     0,    16,    11,    12,    18,     0,     8,     0,
      15,    17,    13,     0,    14,    73,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,    47,    48,    49,    43,    46,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    34,    31,    29,    50,    30,    51,    33,
      32,     0,     0,     0,    40,     0,    76,    75,    19,     0,
       0,    20,    21,    22,    23,    24,    25,    57,     0,    37,
       0,    54,    35,    55,    56,    41,    52,     0,    93,    96,
       0,     0,     0,     0,     0,    92,     0,     0,     0,    88,
      86,    87,    89,     0,     0,     0,     0,    53,     0,    39,
      42,    83,     0,     0,   100,    99,     0,     0,     0,    84,
      85,    60,    61,    77,    62,    63,    64,    65,     0,    80,
      78,     0,     0,     0,    91,    90,    79,    27,    28,    38,
      81,    82,     0,     0,     0,     0,     0,     0,     0,    66,
      68,    67,    70,     0,     0,     0,     0,     0,     0,    95,
      94,    98,    97,    69,    72,     0,     0,     0,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,  -147,  -147,    10,  -147,  -147,  -147,  -147,
     -78,  -147,   -36,   -23,  -147,   -93,  -147,  -147,  -147,  -147,
    -147,    78,  -147,  -146,  -147,  -147,  -147
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     6,     2,     7,    36,    37,    82,    83,    98,
      84,   106,   165,   117,   148,   118,   119,   120,   121,    39,
      18,   122,   123,    86,   134,   135,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    58,    38,     4,    59,   127,   105,   172,   150,    49,
       8,   161,   176,    70,   133,   163,   164,    17,   186,   177,
       3,    23,   151,   152,    22,   151,   152,    24,   130,    49,
     183,   184,   151,   152,    25,    99,   100,    87,    40,    43,
      50,    51,   189,   166,   167,   101,   103,   104,   102,   116,
      61,    62,    63,    64,    65,    66,    67,    68,   170,   171,
      50,    51,    44,    60,   128,   151,   152,    41,    42,   131,
       5,   132,   151,   152,    52,    53,    54,    55,    56,    71,
      45,    19,    46,    20,    47,   185,    21,   116,    48,    69,
      85,    88,   159,    89,    52,    53,    54,    55,    56,   125,
     126,     9,    10,    11,    12,    13,    14,    15,    16,    90,
      91,    92,   169,    93,    72,   168,   141,   142,    73,   143,
     144,   145,   146,   147,    74,    75,    76,    77,    78,    79,
      80,    94,    95,    96,    72,   136,   137,   180,   138,   182,
      81,   139,   140,   149,   153,    49,    71,   107,   108,   109,
     187,     9,    10,    11,    12,    13,    14,    15,    16,   156,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
     157,   110,   158,   111,   112,   162,    50,    51,   113,   114,
     173,    72,   174,   141,   142,    73,   160,   144,   145,   146,
     147,    74,    75,    76,    77,    78,    79,    80,   175,   178,
     181,   155,   152,     0,     0,     0,     0,    81,   115,     0,
      52,    53,    54,    55,    56,    49,     0,   107,   108,   109,
      49,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      49,   110,     0,   111,   112,   179,    50,    51,   113,   114,
       0,    50,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,     0,     0,    71,     0,     0,   154,     0,
      52,    53,    54,    55,    56,    52,    53,    54,    55,    56,
       0,     0,    71,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,    54,    55,    56,
      72,    71,   141,   142,    73,     0,   144,   145,   146,   147,
      74,    75,    76,    77,    78,    79,    80,    72,    71,   188,
       0,    73,     0,     0,     0,     0,    81,    74,    75,    76,
      77,    78,    79,    80,     0,    71,    72,   129,     0,     0,
      73,     0,     0,    81,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    72,     0,     0,     0,    73,     0,     0,
       0,     0,    81,    74,    75,    76,    77,    78,    79,    80,
      72,     0,     0,     0,    73,     0,     0,     0,     0,    81,
      74,    75,    76,    77,    78,    79,    80,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    81,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35
};

static const yytype_int16 yycheck[] =
{
      36,    37,    25,     3,     7,     7,    84,   153,    46,     6,
      71,    46,     7,    49,   107,    49,    50,     7,    46,     7,
       0,    73,    60,    61,    16,    60,    61,    16,   106,     6,
     176,   177,    60,    61,     6,    71,    72,    60,    49,    49,
      37,    38,   188,   136,   137,    81,    82,    83,    45,    85,
      40,    41,    42,    43,    44,    45,    46,    47,   151,   152,
      37,    38,    49,    66,    66,    60,    61,    50,    50,    46,
      70,   107,    60,    61,    71,    72,    73,    74,    75,     6,
      49,    14,    49,    16,    49,   178,    19,   123,    49,    74,
      68,    50,   128,    66,    71,    72,    73,    74,    75,    89,
      90,    12,    13,    14,    15,    16,    17,    18,    19,    66,
      50,    50,   148,    50,    41,   138,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    50,    50,    50,    41,     6,     6,   173,     6,   175,
      67,    46,    46,    46,    33,     6,     6,     8,     9,    10,
     186,    12,    13,    14,    15,    16,    17,    18,    19,    46,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      49,    32,    49,    34,    35,    49,    37,    38,    39,    40,
      49,    41,    49,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    50,    46,
      11,   123,    61,    -1,    -1,    -1,    -1,    67,    69,    -1,
      71,    72,    73,    74,    75,     6,    -1,     8,     9,    10,
       6,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       6,    32,    -1,    34,    35,    11,    37,    38,    39,    40,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,     6,    -1,    -1,    69,    -1,
      71,    72,    73,    74,    75,    71,    72,    73,    74,    75,
      -1,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      41,     6,    43,    44,    45,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    41,     6,     7,
      -1,    45,    -1,    -1,    -1,    -1,    67,    51,    52,    53,
      54,    55,    56,    57,    -1,     6,    41,    42,    -1,    -1,
      45,    -1,    -1,    67,    -1,    -1,    51,    52,    53,    54,
      55,    56,    57,    41,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    67,    51,    52,    53,    54,    55,    56,    57,
      41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    67,
      51,    52,    53,    54,    55,    56,    57,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    67,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    77,    79,     0,     3,    70,    78,    80,    71,    12,
      13,    14,    15,    16,    17,    18,    19,    81,    96,    14,
      16,    19,    16,    73,    16,     6,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    81,    82,    89,    95,
      49,    50,    50,    49,    49,    49,    49,    49,    49,     6,
      37,    38,    71,    72,    73,    74,    75,    88,    88,     7,
      66,    81,    81,    81,    81,    81,    81,    81,    81,    74,
      88,     6,    41,    45,    51,    52,    53,    54,    55,    56,
      57,    67,    83,    84,    86,    68,    99,    89,    50,    66,
      66,    50,    50,    50,    50,    50,    50,     7,    85,    88,
      88,    88,    45,    88,    88,    86,    87,     8,     9,    10,
      32,    34,    35,    39,    40,    69,    88,    89,    91,    92,
      93,    94,    97,    98,   102,    81,    81,     7,    66,    42,
      86,    46,    88,    91,   100,   101,     6,     6,     6,    46,
      46,    43,    44,    46,    47,    48,    49,    50,    90,    46,
      46,    60,    61,    33,    69,    97,    46,    49,    49,    88,
      46,    46,    49,    49,    50,    88,    91,    91,    89,    88,
      91,    91,    99,    49,    49,    50,     7,     7,    46,    11,
      88,    11,    88,    99,    99,    91,    46,    88,     7,    99
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      83,    83,    83,    83,    84,    84,    85,    85,    85,    86,
      87,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    91,    91,    92,
      92,    93,    94,    95,    95,    95,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   101,   101,   101,   102,
     102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     0,     2,     0,     2,     1,
       1,     1,     1,     2,     3,     2,     1,     2,     1,     4,
       4,     4,     4,     4,     4,     4,     1,     6,     6,     1,
       1,     1,     1,     1,     1,     2,     0,     1,     3,     3,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     4,     3,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     5,
       3,     9,     5,     0,     1,     3,     6,     2,     2,     2,
       2,     3,     3,     2,     2,     2,     1,     1,     1,     1,
       2,     3,     2,     0,     4,     4,     0,     4,     4,     2,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
# undef YYSTACK_RELOCATE
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
  case 2:
#line 92 "analizadorSintactico.y"
                                      {
            //#cout<<"PROGRAMA"<<endl;
            raiz = new cl_raiz;
            raiz->funciones_declaradas = (*(yyvsp[0].funciones_declaradas));
            delete (yyvsp[0].funciones_declaradas);
        }
#line 1605 "analizadorSintactico.cpp"
    break;

  case 3:
#line 101 "analizadorSintactico.y"
                            {(yyval.nada) = 0;}
#line 1611 "analizadorSintactico.cpp"
    break;

  case 4:
#line 102 "analizadorSintactico.y"
                    {(yyval.nada) = 0;;}
#line 1617 "analizadorSintactico.cpp"
    break;

  case 5:
#line 105 "analizadorSintactico.y"
                  {(yyval.nada) = 0;}
#line 1623 "analizadorSintactico.cpp"
    break;

  case 6:
#line 106 "analizadorSintactico.y"
                           { (yyvsp[-1].nada) = 0;}
#line 1629 "analizadorSintactico.cpp"
    break;

  case 7:
#line 109 "analizadorSintactico.y"
                  {
            (yyval.funciones_declaradas) = new vector<cl_declaracion_funcion*>;
        }
#line 1637 "analizadorSintactico.cpp"
    break;

  case 8:
#line 112 "analizadorSintactico.y"
                                                {
            (yyvsp[-1].funciones_declaradas)->push_back((yyvsp[0].declaracion_funcion));
        }
#line 1645 "analizadorSintactico.cpp"
    break;

  case 9:
#line 118 "analizadorSintactico.y"
                {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "void";  }
#line 1651 "analizadorSintactico.cpp"
    break;

  case 10:
#line 119 "analizadorSintactico.y"
                {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "bool";}
#line 1657 "analizadorSintactico.cpp"
    break;

  case 11:
#line 120 "analizadorSintactico.y"
                {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "char";}
#line 1663 "analizadorSintactico.cpp"
    break;

  case 12:
#line 121 "analizadorSintactico.y"
                 {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "float";}
#line 1669 "analizadorSintactico.cpp"
    break;

  case 13:
#line 122 "analizadorSintactico.y"
                       {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "short int";}
#line 1675 "analizadorSintactico.cpp"
    break;

  case 14:
#line 123 "analizadorSintactico.y"
                             {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "long long int";}
#line 1681 "analizadorSintactico.cpp"
    break;

  case 15:
#line 124 "analizadorSintactico.y"
                      {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "long int";}
#line 1687 "analizadorSintactico.cpp"
    break;

  case 16:
#line 125 "analizadorSintactico.y"
               {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "int";}
#line 1693 "analizadorSintactico.cpp"
    break;

  case 17:
#line 126 "analizadorSintactico.y"
                         {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "double";}
#line 1699 "analizadorSintactico.cpp"
    break;

  case 18:
#line 127 "analizadorSintactico.y"
                  {(yyval.tipo_dato) = new cl_tipoDato;(yyval.tipo_dato)->tipo = "double";}
#line 1705 "analizadorSintactico.cpp"
    break;

  case 19:
#line 130 "analizadorSintactico.y"
                                         {
            (yyval.tipo_dato) = new cl_tipoDato;
            (yyval.tipo_dato)->tipo = "vector";
            (yyval.tipo_dato)->subtipo = (yyvsp[-1].tipo_dato)->tipo;
            delete (yyvsp[-1].tipo_dato);
        }
#line 1716 "analizadorSintactico.cpp"
    break;

  case 20:
#line 136 "analizadorSintactico.y"
                                       {
            (yyval.tipo_dato) = new cl_tipoDato;
            (yyval.tipo_dato)->tipo = "set";
            (yyval.tipo_dato)->subtipo = (yyvsp[-1].tipo_dato)->tipo;
            delete (yyvsp[-1].tipo_dato); 
        }
#line 1727 "analizadorSintactico.cpp"
    break;

  case 21:
#line 142 "analizadorSintactico.y"
                                            {
            (yyval.tipo_dato) = new cl_tipoDato; 
            (yyval.tipo_dato)->tipo = "multiset"; 
            (yyval.tipo_dato)->subtipo = (yyvsp[-1].tipo_dato)->tipo;
            delete (yyvsp[-1].tipo_dato);
        }
#line 1738 "analizadorSintactico.cpp"
    break;

  case 22:
#line 148 "analizadorSintactico.y"
                                         {
            (yyval.tipo_dato) = new cl_tipoDato;
            (yyval.tipo_dato)->tipo = "queue";
            (yyval.tipo_dato)->subtipo = (yyvsp[-1].tipo_dato)->tipo;
            delete (yyvsp[-1].tipo_dato);
        }
#line 1749 "analizadorSintactico.cpp"
    break;

  case 23:
#line 154 "analizadorSintactico.y"
                                          {
            (yyval.tipo_dato) = new cl_tipoDato;
            (yyval.tipo_dato)->tipo = "pqueue";
            (yyval.tipo_dato)->subtipo = (yyvsp[-1].tipo_dato)->tipo;
            delete (yyvsp[-1].tipo_dato);
        }
#line 1760 "analizadorSintactico.cpp"
    break;

  case 24:
#line 160 "analizadorSintactico.y"
                                         {
            (yyval.tipo_dato) = new cl_tipoDato;
            (yyval.tipo_dato)->tipo = "stack";
            (yyval.tipo_dato)->subtipo = (yyvsp[-1].tipo_dato)->tipo;
            delete (yyvsp[-1].tipo_dato);
        }
#line 1771 "analizadorSintactico.cpp"
    break;

  case 25:
#line 166 "analizadorSintactico.y"
                                       {
            (yyval.tipo_dato) = new cl_tipoDato;
            (yyval.tipo_dato)->tipo = "bitset";
            delete (yyvsp[-1].atributos);
        }
#line 1781 "analizadorSintactico.cpp"
    break;

  case 26:
#line 171 "analizadorSintactico.y"
                  {
            (yyval.tipo_dato) = new cl_tipoDato;
            (yyval.tipo_dato)->tipo = "string";
        }
#line 1790 "analizadorSintactico.cpp"
    break;

  case 27:
#line 175 "analizadorSintactico.y"
                                                             {
            (yyval.tipo_dato) = new cl_tipoDato;
            (yyval.tipo_dato)->tipo = "map";
            (yyval.tipo_dato)->subtipo = (yyvsp[-3].tipo_dato)->tipo;
            (yyval.tipo_dato)->subtipo2 = (yyvsp[-1].tipo_dato)->tipo;
            delete (yyvsp[-3].tipo_dato); delete (yyvsp[-1].tipo_dato);
        }
#line 1802 "analizadorSintactico.cpp"
    break;

  case 28:
#line 182 "analizadorSintactico.y"
                                                              {
            (yyval.tipo_dato) = new cl_tipoDato;
            (yyval.tipo_dato)->tipo = "umap";
            (yyval.tipo_dato)->subtipo = (yyvsp[-3].tipo_dato)->tipo;
            (yyval.tipo_dato)->subtipo2 = (yyvsp[-1].tipo_dato)->tipo;
            delete (yyvsp[-3].tipo_dato); delete (yyvsp[-1].tipo_dato);
        }
#line 1814 "analizadorSintactico.cpp"
    break;

  case 29:
#line 192 "analizadorSintactico.y"
              {(yyval.es_exponencial)=0;}
#line 1820 "analizadorSintactico.cpp"
    break;

  case 30:
#line 193 "analizadorSintactico.y"
               {(yyval.es_exponencial)=0;}
#line 1826 "analizadorSintactico.cpp"
    break;

  case 31:
#line 194 "analizadorSintactico.y"
               {(yyval.es_exponencial) = 0;}
#line 1832 "analizadorSintactico.cpp"
    break;

  case 32:
#line 195 "analizadorSintactico.y"
               {(yyval.es_exponencial)=1;}
#line 1838 "analizadorSintactico.cpp"
    break;

  case 33:
#line 196 "analizadorSintactico.y"
                {(yyval.es_exponencial)=1;}
#line 1844 "analizadorSintactico.cpp"
    break;

  case 34:
#line 199 "analizadorSintactico.y"
            {(yyval.es_exponencial) = 4; }
#line 1850 "analizadorSintactico.cpp"
    break;

  case 35:
#line 200 "analizadorSintactico.y"
                                  {(yyval.es_exponencial) = ((yyvsp[-1].es_exponencial)); (yyval.es_exponencial)+=2;}
#line 1856 "analizadorSintactico.cpp"
    break;

  case 36:
#line 203 "analizadorSintactico.y"
                  {(yyval.argumentos_llamada) = new cl_argumentos_llamada;}
#line 1862 "analizadorSintactico.cpp"
    break;

  case 37:
#line 204 "analizadorSintactico.y"
                            {(yyval.argumentos_llamada) = new cl_argumentos_llamada; (yyval.argumentos_llamada)->argumentos.push_back((yyvsp[0].expresion_aritmetica));}
#line 1868 "analizadorSintactico.cpp"
    break;

  case 38:
#line 205 "analizadorSintactico.y"
                                                       {
            (yyvsp[-2].argumentos_llamada)->argumentos.push_back((yyvsp[0].expresion_aritmetica));
        }
#line 1876 "analizadorSintactico.cpp"
    break;

  case 39:
#line 210 "analizadorSintactico.y"
                                              { (yyval.nada) = 0;}
#line 1882 "analizadorSintactico.cpp"
    break;

  case 40:
#line 213 "analizadorSintactico.y"
                  {}
#line 1888 "analizadorSintactico.cpp"
    break;

  case 41:
#line 214 "analizadorSintactico.y"
                   {}
#line 1894 "analizadorSintactico.cpp"
    break;

  case 42:
#line 215 "analizadorSintactico.y"
                               { }
#line 1900 "analizadorSintactico.cpp"
    break;

  case 43:
#line 218 "analizadorSintactico.y"
                   {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = true;
            (yyval.expresion_aritmetica)->es_constante = true;
            (yyval.expresion_aritmetica)->valor_numerico = (yyvsp[0].atributos)->value_int;
        }
#line 1911 "analizadorSintactico.cpp"
    break;

  case 44:
#line 224 "analizadorSintactico.y"
                {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = true;
            (yyval.expresion_aritmetica)->es_constante = true;
            (yyval.expresion_aritmetica)->valor_numerico = 1;
        }
#line 1922 "analizadorSintactico.cpp"
    break;

  case 45:
#line 230 "analizadorSintactico.y"
                 {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = true;
            (yyval.expresion_aritmetica)->es_constante = true;
            (yyval.expresion_aritmetica)->valor_numerico = 0;
        }
#line 1933 "analizadorSintactico.cpp"
    break;

  case 46:
#line 236 "analizadorSintactico.y"
                       {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = true;
            (yyval.expresion_aritmetica)->es_constante = true;
            (yyval.expresion_aritmetica)->valor_numerico = (yyvsp[0].atributos)->value_double;
        }
#line 1944 "analizadorSintactico.cpp"
    break;

  case 47:
#line 242 "analizadorSintactico.y"
                  {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = true;
            (yyval.expresion_aritmetica)->es_cadena;
            (yyval.expresion_aritmetica)->cadena = (yyvsp[0].atributos)->value_string;
        }
#line 1955 "analizadorSintactico.cpp"
    break;

  case 48:
#line 248 "analizadorSintactico.y"
                    {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = true;
            (yyval.expresion_aritmetica)->es_cadena;
            (yyval.expresion_aritmetica)->cadena = "";
            (yyval.expresion_aritmetica)->cadena+=(yyvsp[0].atributos)->value_char;
        }
#line 1967 "analizadorSintactico.cpp"
    break;

  case 49:
#line 255 "analizadorSintactico.y"
                         {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica; 
            (yyval.expresion_aritmetica)->es_terminal = true;  
            (yyval.expresion_aritmetica)->es_identificador = true; 
            (yyval.expresion_aritmetica)->identificador = (yyvsp[0].atributos)->value_string; 
        }
#line 1978 "analizadorSintactico.cpp"
    break;

  case 50:
#line 261 "analizadorSintactico.y"
                                      {
            //beginning of identifier related rules
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = false;
            (yyval.expresion_aritmetica)->izquierda = (yyvsp[-1].expresion_aritmetica);
            
            (yyval.expresion_aritmetica)->operador = 2;

            (yyval.expresion_aritmetica)->derecha = new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->derecha->es_terminal = true;
            (yyval.expresion_aritmetica)->derecha->es_constante = true;
            (yyval.expresion_aritmetica)->derecha->valor_numerico = 1;

        }
#line 1997 "analizadorSintactico.cpp"
    break;

  case 51:
#line 275 "analizadorSintactico.y"
                                      {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = false;
            (yyval.expresion_aritmetica)->izquierda = (yyvsp[-1].expresion_aritmetica);
            
            (yyval.expresion_aritmetica)->operador = 2;

            (yyval.expresion_aritmetica)->derecha = new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->derecha->es_terminal = true;
            (yyval.expresion_aritmetica)->derecha->es_constante = true;
            (yyval.expresion_aritmetica)->derecha->valor_numerico = 1;
        }
#line 2014 "analizadorSintactico.cpp"
    break;

  case 52:
#line 287 "analizadorSintactico.y"
                                                   {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = true;
            (yyval.expresion_aritmetica)->es_identificador = true;
            (yyval.expresion_aritmetica)->identificador = (yyvsp[-2].expresion_aritmetica)->identificador;
            (yyval.expresion_aritmetica)->es_posicion_arreglo = true;
            delete (yyvsp[-2].expresion_aritmetica);  
        }
#line 2027 "analizadorSintactico.cpp"
    break;

  case 53:
#line 295 "analizadorSintactico.y"
                                                                 {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->es_terminal = true;
            (yyval.expresion_aritmetica)->es_llamada_funcion = true;
            (yyval.expresion_aritmetica)->llamada_val = new cl_llamada_funcion;
            (yyval.expresion_aritmetica)->llamada_val->argumentos = (yyvsp[-1].argumentos_llamada)->argumentos;
            (yyval.expresion_aritmetica)->llamada_val->identificador = (yyvsp[-3].expresion_aritmetica)->identificador;
            delete(yyvsp[-3].expresion_aritmetica);  delete (yyvsp[-1].argumentos_llamada);
        }
#line 2041 "analizadorSintactico.cpp"
    break;

  case 54:
#line 304 "analizadorSintactico.y"
                                                      {
            //asume que la segunda expresion es una llamada
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->identificador = (yyvsp[-2].expresion_aritmetica)->identificador;
            (yyval.expresion_aritmetica)->es_terminal = true;
            (yyval.expresion_aritmetica)->es_llamada_funcion = true;
            (yyval.expresion_aritmetica)->llamada_val = (yyvsp[0].expresion_aritmetica)->llamada_val;
            (yyval.expresion_aritmetica)->llamada_val->esta_contenida= true;
            (yyval.expresion_aritmetica)->llamada_val->id_contenedor= (yyvsp[-2].expresion_aritmetica)->identificador;
            delete (yyvsp[-2].expresion_aritmetica);
            //END OF IDENTIFIER RELATED RULES
        }
#line 2058 "analizadorSintactico.cpp"
    break;

  case 55:
#line 316 "analizadorSintactico.y"
                                                                    {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica;
            (yyval.expresion_aritmetica)->identificador = (yyvsp[-2].expresion_aritmetica)->identificador;
            (yyval.expresion_aritmetica)->es_terminal = false;
            (yyval.expresion_aritmetica)->izquierda = (yyvsp[-2].expresion_aritmetica);
            (yyval.expresion_aritmetica)->derecha = (yyvsp[0].expresion_aritmetica);
            (yyval.expresion_aritmetica)->operador = (yyvsp[-1].es_exponencial);
        }
#line 2071 "analizadorSintactico.cpp"
    break;

  case 56:
#line 324 "analizadorSintactico.y"
                                                                    {
            (yyval.expresion_aritmetica)= new cl_expresion_aritmetica; 
            (yyval.expresion_aritmetica)->es_terminal = false; 
            (yyval.expresion_aritmetica)->izquierda = (yyvsp[-2].expresion_aritmetica);
            (yyval.expresion_aritmetica)->derecha = (yyvsp[0].expresion_aritmetica); 
            (yyval.expresion_aritmetica)->operador = (yyvsp[-1].es_exponencial);
        }
#line 2083 "analizadorSintactico.cpp"
    break;

  case 57:
#line 331 "analizadorSintactico.y"
                                                {
            (yyval.expresion_aritmetica)= (yyvsp[-1].expresion_aritmetica);
        }
#line 2091 "analizadorSintactico.cpp"
    break;

  case 58:
#line 337 "analizadorSintactico.y"
                                         {
            (yyval.declaracion) = new cl_declaracion;
            (yyval.declaracion)->tipo = (yyvsp[-1].tipo_dato);
            if((yyvsp[0].expresion_aritmetica)->es_identificador){
                //asume que expresionAritmetica es un identificador
                (yyval.declaracion)->identificador = (yyvsp[0].expresion_aritmetica)->identificador;
            }else{
                //asume que expresionAritmetica es una asignacion
                (yyval.declaracion)->identificador = (yyvsp[0].expresion_aritmetica)->izquierda->identificador;
                (yyval.declaracion)->inicializada = true;
                (yyval.declaracion)->valor_predeterminado = (yyvsp[0].expresion_aritmetica)->derecha;
            }
        }
#line 2109 "analizadorSintactico.cpp"
    break;

  case 59:
#line 350 "analizadorSintactico.y"
                                           {
            //asume que expresionAritmetica es un identificador
            (yyval.declaracion) = new cl_declaracion;
            (yyval.declaracion)->tipo = (yyvsp[-1].tipo_dato);
            (yyval.declaracion)->identificador = (yyvsp[0].expresion_aritmetica)->identificador;
        }
#line 2120 "analizadorSintactico.cpp"
    break;

  case 60:
#line 359 "analizadorSintactico.y"
               {(yyval.es_conector)=0;}
#line 2126 "analizadorSintactico.cpp"
    break;

  case 61:
#line 360 "analizadorSintactico.y"
                {(yyval.es_conector)=0;}
#line 2132 "analizadorSintactico.cpp"
    break;

  case 62:
#line 361 "analizadorSintactico.y"
                {(yyval.es_conector)=-1;}
#line 2138 "analizadorSintactico.cpp"
    break;

  case 63:
#line 362 "analizadorSintactico.y"
                {(yyval.es_conector)=1;}
#line 2144 "analizadorSintactico.cpp"
    break;

  case 64:
#line 363 "analizadorSintactico.y"
                {(yyval.es_conector)=-1;}
#line 2150 "analizadorSintactico.cpp"
    break;

  case 65:
#line 364 "analizadorSintactico.y"
                {(yyval.es_conector)=1;}
#line 2156 "analizadorSintactico.cpp"
    break;

  case 66:
#line 367 "analizadorSintactico.y"
                                                                {
            (yyval.expresion_booleana) = new cl_expresion_booleana;
            (yyval.expresion_booleana)->es_terminal = false;
            (yyval.expresion_booleana)->es_conector = (yyvsp[-1].es_conector);
            (yyval.expresion_booleana)->izquierda = new cl_expresion_booleana;
            (yyval.expresion_booleana)->izquierda->es_terminal = true;
            (yyval.expresion_booleana)->izquierda->valor = (yyvsp[-2].expresion_aritmetica);
            (yyval.expresion_booleana)->derecha = new cl_expresion_booleana;
            (yyval.expresion_booleana)->derecha->es_terminal = true;
            (yyval.expresion_booleana)->derecha->valor = (yyvsp[0].expresion_aritmetica);
        }
#line 2172 "analizadorSintactico.cpp"
    break;

  case 67:
#line 378 "analizadorSintactico.y"
                                                      {
            (yyval.expresion_booleana) = new cl_expresion_booleana;
            (yyval.expresion_booleana)->es_terminal = false;
            (yyval.expresion_booleana)->es_conector = 3;
            (yyval.expresion_booleana)->izquierda = (yyvsp[-2].expresion_booleana);
            (yyval.expresion_booleana)->derecha = (yyvsp[0].expresion_booleana);
        }
#line 2184 "analizadorSintactico.cpp"
    break;

  case 68:
#line 385 "analizadorSintactico.y"
                                                    {
            (yyval.expresion_booleana) = new cl_expresion_booleana;
            (yyval.expresion_booleana)->es_terminal = false;
            (yyval.expresion_booleana)->es_conector = 2;
            (yyval.expresion_booleana)->izquierda = (yyvsp[-2].expresion_booleana);
            (yyval.expresion_booleana)->derecha = (yyvsp[0].expresion_booleana);
        }
#line 2196 "analizadorSintactico.cpp"
    break;

  case 69:
#line 395 "analizadorSintactico.y"
                                                              {
            (yyval.iif) = new cl_if; 
            (yyval.iif)->argumento = (yyvsp[-2].expresion_booleana); 
            (yyval.iif)->bloque_if = (yyvsp[0].bloque_codigo); 
            (yyval.iif)->tiene_else = false;
            (yyval.iif)->tiene_break =  (yyvsp[0].bloque_codigo)->tiene_break;
        }
#line 2208 "analizadorSintactico.cpp"
    break;

  case 70:
#line 402 "analizadorSintactico.y"
                                        {
            if((yyvsp[-2].iif)->tiene_else){
                yyerror("Un if tiene mas de un else");
            }
            (yyvsp[-2].iif)->tiene_else = true;
            (yyvsp[-2].iif)->bloque_else = (yyvsp[0].bloque_codigo);
            (yyval.iif)->tiene_break =  (yyvsp[0].bloque_codigo)->tiene_break;
        }
#line 2221 "analizadorSintactico.cpp"
    break;

  case 71:
#line 413 "analizadorSintactico.y"
        {
            (yyval.ciclo) = new cl_ciclo;
            (yyval.ciclo)->bloque_codigo = (yyvsp[0].bloque_codigo);
            (yyval.ciclo)->argumento_continuacion = (yyvsp[-4].expresion_booleana);
            (yyval.ciclo)->step = (yyvsp[-2].expresion_aritmetica);
            (yyval.ciclo)->bloque_codigo->booleanas.push_back((yyvsp[-4].expresion_booleana));
            (yyval.ciclo)->bloque_codigo->aritmeticas.push_back((yyvsp[-2].expresion_aritmetica));
            delete (yyvsp[-6].declaracion);
        }
#line 2235 "analizadorSintactico.cpp"
    break;

  case 72:
#line 425 "analizadorSintactico.y"
        {
            (yyval.ciclo) = new cl_ciclo;
            (yyval.ciclo)->bloque_codigo = (yyvsp[0].bloque_codigo);
            (yyval.ciclo)->argumento_continuacion = (yyvsp[-2].expresion_booleana);
            (yyval.ciclo)->step = NULL;
            (yyval.ciclo)->bloque_codigo->booleanas.push_back((yyvsp[-2].expresion_booleana));
        }
#line 2247 "analizadorSintactico.cpp"
    break;

  case 73:
#line 436 "analizadorSintactico.y"
                  {(yyval.lista_argumentos) = new cl_lista_argumentos;}
#line 2253 "analizadorSintactico.cpp"
    break;

  case 74:
#line 437 "analizadorSintactico.y"
                             {
            (yyval.lista_argumentos) = new cl_lista_argumentos; 
            (yyval.lista_argumentos)->argumentos.push_back((*(yyvsp[0].declaracion)));
            delete (yyvsp[0].declaracion);
        }
#line 2263 "analizadorSintactico.cpp"
    break;

  case 75:
#line 442 "analizadorSintactico.y"
                                                      {
            (yyvsp[-2].lista_argumentos)->argumentos.push_back((*(yyvsp[0].declaracion)));
            delete (yyvsp[0].declaracion);
        }
#line 2272 "analizadorSintactico.cpp"
    break;

  case 76:
#line 449 "analizadorSintactico.y"
        {
            (yyval.declaracion_funcion) = new cl_declaracion_funcion;
            (yyval.declaracion_funcion)->argumentos = (yyvsp[-2].lista_argumentos)->argumentos;
            (yyval.declaracion_funcion)->bloque_codigo = (yyvsp[0].bloque_codigo);
            (yyval.declaracion_funcion)->tipo = (yyvsp[-5].tipo_dato);
            (yyval.declaracion_funcion)->identificador = (yyvsp[-4].atributos)->value_string;
             delete (yyvsp[-2].lista_argumentos);
        }
#line 2285 "analizadorSintactico.cpp"
    break;

  case 77:
#line 460 "analizadorSintactico.y"
                                        { 
            (yyval.bloque_codigo) = new cl_bloque_codigo;
            (yyval.bloque_codigo)->aritmeticas.push_back((yyvsp[-1].expresion_aritmetica));
            (yyval.bloque_codigo)->expresion_return = NULL;
        }
#line 2295 "analizadorSintactico.cpp"
    break;

  case 78:
#line 465 "analizadorSintactico.y"
                                       {
            (yyval.bloque_codigo) = new cl_bloque_codigo;
            (yyval.bloque_codigo)-> booleanas.push_back((yyvsp[-1].expresion_booleana));
            (yyval.bloque_codigo)->expresion_return = NULL;
        }
#line 2305 "analizadorSintactico.cpp"
    break;

  case 79:
#line 470 "analizadorSintactico.y"
                                   {
            (yyval.bloque_codigo) = new cl_bloque_codigo;
            (yyval.bloque_codigo)->aritmeticas.push_back((yyvsp[-1].expresion_aritmetica));
            (yyval.bloque_codigo)->expresion_return = NULL;
        }
#line 2315 "analizadorSintactico.cpp"
    break;

  case 80:
#line 475 "analizadorSintactico.y"
                                        {
            (yyval.bloque_codigo) = new cl_bloque_codigo;
            (yyval.bloque_codigo)->declaraciones.push_back((yyvsp[-1].declaracion));
            (yyval.bloque_codigo)->expresion_return = NULL;
        }
#line 2325 "analizadorSintactico.cpp"
    break;

  case 81:
#line 480 "analizadorSintactico.y"
                                                   {
            (yyval.bloque_codigo) = new cl_bloque_codigo;
            (yyval.bloque_codigo)->expresion_return = (yyvsp[-1].expresion_aritmetica);
            (yyval.bloque_codigo)->aritmeticas.push_back((yyvsp[-1].expresion_aritmetica));
        }
#line 2335 "analizadorSintactico.cpp"
    break;

  case 82:
#line 485 "analizadorSintactico.y"
                                                 {
            (yyval.bloque_codigo) = new cl_bloque_codigo;
            (yyval.bloque_codigo)-> booleanas.push_back((yyvsp[-1].expresion_booleana));
            (yyval.bloque_codigo)->expresion_return = NULL;
        }
#line 2345 "analizadorSintactico.cpp"
    break;

  case 83:
#line 490 "analizadorSintactico.y"
                                {
            (yyval.bloque_codigo) = new cl_bloque_codigo;
            (yyval.bloque_codigo)->expresion_return = NULL;
        }
#line 2354 "analizadorSintactico.cpp"
    break;

  case 84:
#line 494 "analizadorSintactico.y"
                             { 
            (yyval.bloque_codigo) = new cl_bloque_codigo;
            (yyval.bloque_codigo)->tiene_break = true;
            (yyval.bloque_codigo)->expresion_return = NULL;
        }
#line 2364 "analizadorSintactico.cpp"
    break;

  case 85:
#line 499 "analizadorSintactico.y"
                                {
            (yyval.bloque_codigo) = new cl_bloque_codigo;
            (yyval.bloque_codigo)->expresion_return = NULL;
        }
#line 2373 "analizadorSintactico.cpp"
    break;

  case 86:
#line 503 "analizadorSintactico.y"
                      {(yyval.bloque_codigo) = new cl_bloque_codigo; (yyval.bloque_codigo)->ciclos.push_back((yyvsp[0].ciclo));}
#line 2379 "analizadorSintactico.cpp"
    break;

  case 87:
#line 504 "analizadorSintactico.y"
                       { (yyval.bloque_codigo) = new cl_bloque_codigo; (yyval.bloque_codigo)->ciclos.push_back((yyvsp[0].ciclo));}
#line 2385 "analizadorSintactico.cpp"
    break;

  case 88:
#line 505 "analizadorSintactico.y"
                    { (yyval.bloque_codigo) = new cl_bloque_codigo; (yyval.bloque_codigo)->ifs.push_back((yyvsp[0].iif));}
#line 2391 "analizadorSintactico.cpp"
    break;

  case 89:
#line 508 "analizadorSintactico.y"
                    {(yyval.bloque_codigo) = (yyvsp[0].bloque_codigo);}
#line 2397 "analizadorSintactico.cpp"
    break;

  case 90:
#line 509 "analizadorSintactico.y"
                                   {
            for(int i = 0; i<((yyvsp[0].bloque_codigo))->aritmeticas.size(); i++){
                (yyvsp[-1].bloque_codigo)->aritmeticas.push_back((yyvsp[0].bloque_codigo)->aritmeticas[i]);
            }
            for(int i = 0; i<((yyvsp[0].bloque_codigo))->booleanas.size(); i++){
                (yyvsp[-1].bloque_codigo)->booleanas.push_back((yyvsp[0].bloque_codigo)->booleanas[i]);
            }
            for(int i = 0; i<((yyvsp[0].bloque_codigo))->ciclos.size(); i++){
                (yyvsp[-1].bloque_codigo)->ciclos.push_back((yyvsp[0].bloque_codigo)->ciclos[i]);
            }
            for(int i = 0; i<((yyvsp[0].bloque_codigo))->declaraciones.size(); i++){
                (yyvsp[-1].bloque_codigo)->declaraciones.push_back((yyvsp[0].bloque_codigo)->declaraciones[i]);
            }
            for(int i = 0; i<((yyvsp[0].bloque_codigo))->ifs.size(); i++){
                (yyvsp[-1].bloque_codigo)->ifs.push_back((yyvsp[0].bloque_codigo)->ifs[i]);
            }
            delete (yyvsp[0].bloque_codigo);
        }
#line 2420 "analizadorSintactico.cpp"
    break;

  case 91:
#line 529 "analizadorSintactico.y"
                                           {
            (yyval.bloque_codigo) = (yyvsp[-1].bloque_codigo);
        }
#line 2428 "analizadorSintactico.cpp"
    break;

  case 92:
#line 532 "analizadorSintactico.y"
                               {
            (yyval.bloque_codigo) = new cl_bloque_codigo;
        }
#line 2436 "analizadorSintactico.cpp"
    break;

  case 93:
#line 538 "analizadorSintactico.y"
                  {(yyval.argumentos_llamada) = new cl_argumentos_llamada;}
#line 2442 "analizadorSintactico.cpp"
    break;

  case 94:
#line 540 "analizadorSintactico.y"
        {
            (yyvsp[-3].argumentos_llamada)->argumentos.push_back((yyvsp[0].expresion_aritmetica));
        }
#line 2450 "analizadorSintactico.cpp"
    break;

  case 95:
#line 544 "analizadorSintactico.y"
        {
        }
#line 2457 "analizadorSintactico.cpp"
    break;

  case 96:
#line 548 "analizadorSintactico.y"
                  {(yyval.argumentos_llamada) = new cl_argumentos_llamada;}
#line 2463 "analizadorSintactico.cpp"
    break;

  case 97:
#line 550 "analizadorSintactico.y"
        {
            (yyvsp[-3].argumentos_llamada)->argumentos.push_back((yyvsp[0].expresion_aritmetica));
        }
#line 2471 "analizadorSintactico.cpp"
    break;

  case 98:
#line 554 "analizadorSintactico.y"
        {

        }
#line 2479 "analizadorSintactico.cpp"
    break;

  case 99:
#line 559 "analizadorSintactico.y"
                    {
        (yyval.expresion_aritmetica)= new cl_expresion_aritmetica; 
        (yyval.expresion_aritmetica)->es_terminal = true; 
        (yyval.expresion_aritmetica)->es_llamada_funcion = true; 
        (yyval.expresion_aritmetica)->llamada_val = new cl_llamada_funcion;
        (yyval.expresion_aritmetica)->llamada_val->argumentos = (yyvsp[0].argumentos_llamada)->argumentos; 
        (yyval.expresion_aritmetica)->llamada_val->identificador = "cin"; 

        if((yyvsp[0].argumentos_llamada)->argumentos.size()==0){
            yyerror("El uso de cin sin valores para imprimir no esta permitido");
        }
        delete (yyvsp[0].argumentos_llamada); 
    }
#line 2497 "analizadorSintactico.cpp"
    break;

  case 100:
#line 572 "analizadorSintactico.y"
                     {
        (yyval.expresion_aritmetica)= new cl_expresion_aritmetica; 
        (yyval.expresion_aritmetica)->es_terminal = true; 
        (yyval.expresion_aritmetica)->es_llamada_funcion = true; 
        (yyval.expresion_aritmetica)->llamada_val = new cl_llamada_funcion;
        (yyval.expresion_aritmetica)->llamada_val->argumentos = (yyvsp[0].argumentos_llamada)->argumentos; 
        (yyval.expresion_aritmetica)->llamada_val->identificador = "cout"; 
        if((yyvsp[0].argumentos_llamada)->argumentos.size()==0){
            yyerror("El uso de cout sin valores para imprimir no esta permitido");
        }
        delete (yyvsp[0].argumentos_llamada); 
    }
#line 2514 "analizadorSintactico.cpp"
    break;


#line 2518 "analizadorSintactico.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 585 "analizadorSintactico.y"

