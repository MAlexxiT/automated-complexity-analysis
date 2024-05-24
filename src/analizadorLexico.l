%{
#include <iostream>
#include <cstdlib>
#include <string>
#include "nodos.h"
#include "analizadorSintactico.hpp" // output of bison on example1 .y
extern "C" int yywrap() { }
//por si algun dia requiero volver a poner globales lol
%}
/*HARDCODED STUFF*/
USINGNPSTD "using namespace std;"
DEF "#define"
NEW "new"
OPERATOR "operator"
/*tipos de datos primitivos + struct + pair*/
BOOL "bool"
CHAR "char"
INT "int"
LONG "long" 
VOID "void" 
SHORT "short" 
FLOAT "float"
DOUBLE "double"
STRUCT "struct"
PAIR "pair"
/*contenedores STL*/
STRING "string"
VECTOR "vector"
MAP "map"
UMAP "unordered_map"
SET "set"
MULTISET "multiset"
QUEUE "queue"
PQUEUE "priority_queue"
STACK "stack"
BITSET "bitset"
/*operadores aritmeticos y de asignacion*/
ASTK \*
SUM \+
SUB -
DIV \/
EQ "="
MOD "%"
/*operadores logicos*/
LTEQ "<="
LT "<"
GTEQ ">="
GT ">"
NTEQ "!="
NOT "!"
OR "||"
AND "&&"
/* TRUE/FALSE , I/O , flow Control*/
TRUE "true"
FALSE "false"
COUT "cout"
CIN "cin"
ENDL "endl"
CONTINUE "continue"
BREAK "break"
RETURN "return"
/*operadores de bits + ternario*/
TERNARIO \?
BXOR "^"
BOR "|"
BAND "&"
/*CARACTERES CONSTRUCTORES*/
COMMA ","
DOT "."
OPREGB \(
CLOREGB \)
OPSQRB \[
CLOSQRB \]
OPCRLYB \{
CLOCRLYB \}
WHTSPCE [\t\r]
DBLQUOT \"
SNGLQUOT \'
SEMICOLON ;
COLON :
LETRA [A-Za-z]
DIGITO [0-9]
ID [A-Za-z\_]+[0-9A-Za-z\_]*
%%
[ \t\n] {}/* eat up whitespace */  
[\n] {}  
{DIV}{2}[^\n]* {}/* COMENTARIOS DE UNA SOLA LINEA */
{DIV}["\*"][^'\0']*["*\"]{DIV} {} /*COMENTARIOS DE UNA SOLA LINEA*/
"#include" {
    yylval.atributos = new cl_atributos_tokens;

    yylval.atributos->value_string = "";
    for(int i = 0;i<yyleng; i++){
        if(yytext[i]=='\n') break;
        yylval.atributos->value_string+=yytext[i];
    }
    //#cout<<"t_include"<<endl;
    return t_include;    
}
{USINGNPSTD} {
    return t_nspacestd;
}
{DEF} {
    return t_define;
}
{NEW} {
    return t_new;
}
{OPREGB} {
    return t_opregb;
}
{CLOREGB} {
    return t_cloregb;
}
{RETURN} {
    return t_return;
}
{COUT} {
    return t_cout;
}
{CIN} {
    return t_cin;
}
{ENDL} {
    return t_endl;
}
{DBLQUOT}[^\"\']*{DBLQUOT} {
    yylval.atributos = new cl_atributos_tokens;

    yylval.atributos->value_string = "";
    for(int i = 0;i<yyleng; i++){
        yylval.atributos->value_string+=yytext[i];
    }

    return t_hardstr;
}
{BOOL} {
    return t_bool;
}
{VOID} {
    return t_void;
}
{LONG} {
    return t_long;
}
{SHORT} {
    return t_short;
}
{INT} {
    return t_int;
}
{CHAR} {
    return t_char;
}
{FLOAT} {printf("T_FLOAT\n");
    return t_float;
}
{DOUBLE} {
    return t_double;
}
{STRUCT} {
    return t_struct;
}
{STRING} {
    return t_string;
}
{VECTOR} {
    return t_vector;
}
{MAP} {
    return t_map;
}
{UMAP} {
    return t_umap;
}
{SET} {
    //#std::cout<<"t_set"<<endl;
    return t_set;
}
{MULTISET} {
    return t_multiset;
}
{QUEUE} {
    return t_queue;
}
{PQUEUE} {
    return t_pqueue;
}
{STACK} {
    return t_stack;
}
{BITSET} {
    return t_bitset;
}
{PAIR} {
    return t_pair;
}
"if" {
    return t_if;
}
"else" {
    return t_else;
}
"while" {
    return t_while;
}
"for" {
    return t_for;
}
"do" {
    return t_do;
}
{TRUE} {
    return t_true;
}
{FALSE} {
    return t_false;
}
{CONTINUE} {
    return t_continue;
}
{BREAK} {
    return t_break;
}
{ID} {
    yylval.atributos = new cl_atributos_tokens;

    yylval.atributos->value_string = "";
    for(int i = 0;i<yyleng; i++){
        yylval.atributos->value_string+=yytext[i];
    }
    return t_identificador;
}
{OPSQRB} {
    return t_opsqrb;
}
{DIGITO}+ {
    yylval.atributos = new cl_atributos_tokens;

    yylval.atributos->value_string = "";
    for(int i = 0;i<yyleng; i++){
        yylval.atributos->value_string+=yytext[i];
    }
    yylval.atributos->value_int = stoll(yylval.atributos->value_string);

    return t_intconst;
}
{CLOSQRB} {
    return t_closqrb;
}
{DIGITO}+.{DIGITO}+ {
    yylval.atributos = new cl_atributos_tokens;

    yylval.atributos->value_string = "";
    for(int i = 0;i<yyleng; i++){
        yylval.atributos->value_string+=yytext[i];
    }
    yylval.atributos->value_double = stold(yylval.atributos->value_string);
    
    return t_doubleconst;
}
{EQ}{2} {    
    return t_eqeq;
}
{NTEQ} {
    return t_nteq;
}
{EQ} {
    return t_eq;
}
{SEMICOLON} {
    return t_semicolon;
}
{SNGLQUOT}{LETRA}{SNGLQUOT} {
    yylval.atributos = new cl_atributos_tokens;
    yylval.atributos->value_char = yytext[1];
    return t_charconst;
}
{LTEQ}   {
    return t_lteq;
}
{GTEQ} {
    return t_gteq;
}
{LT} {
   return t_lt;
}
{GT}   {
    return t_gt;
}
{ASTK} {
    return t_astk;
}
{SUM}{2} {
    return t_sumsum;
}   
{SUM} {
    return t_sum;
}
{SUB}{2} {
    return t_subsub;
}
{SUB} {
    return t_sub;
}
{DIV} {
    return t_div;
}
{MOD} {
    return t_mod;
}
{TERNARIO} {
    return t_ternario;
}
{NOT} {
    return t_not;
}
{OR} {
    return t_oror;
}
{AND} {
    return t_andand;
}
{BOR} {
    return t_bitor;
}
{BAND} {
    return t_bitand;
}
{BXOR} {
    return t_bitxor;
}
{COLON} {
    return t_colon;
}
{COMMA} {
    return t_comma;
}
{DOT} {
    return t_dot;
}
{OPCRLYB} {
    return t_opcrlyb;
}
{CLOCRLYB} {
    return t_clocrlyb;
}
%%
/*void yyerror (std::string codigo_error) { 
    std::cout<< " Parse Error : \n"<<codigo_error<<std::endl;
}*/


/*
    DESCARTADO
    METODO ATRIBUTO
    {DOT}{ID} {
    yylval.atributos = new cl_atributos_tokens;token_id++;
    yylval.atributos->token_id = token_id;
    yylval.atributos->line_number = line_number;

    yylval.atributos->value_string = "";
    for(int i = 1;i<yyleng; i++){
        yylval.atributos->value_string+=yytext[i];
    }
    return t_metodo_atributo;
}

*/