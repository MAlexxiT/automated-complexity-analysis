/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    //Si mal no recuerdo, tipos de datos no primitivos tienen que ser apuntadores, deal with it
    vector<cl_declaracion_funcion*>* funciones_declaradas;
    //1,2,3
    int es_conector;
    cl_bloque_codigo* bloque_codigo;
    cl_if* iif;
    int nada;

#line 155 "analizadorSintactico.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ANALIZADORSINTACTICO_HPP_INCLUDED  */
