%{
#include "nodos.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

//GLOBAL

cl_raiz* raiz;
extern int yylex();
void yyerror(const char *s) { printf("ERROR, FIX THIS SOMEHOW LOOOOL: %s \n", s); }

%}
%union {
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
}
%token<nada> t_nspacestd t_define t_new t_opregb t_cloregb t_return
%token<nada> t_cout t_cin t_endl t_bool t_void t_long t_short t_int t_char
%token<nada> t_float t_double t_struct t_string t_vector t_map t_umap t_set t_multiset
%token<nada> t_queue t_pqueue t_stack t_bitset t_pair t_if t_else t_while t_for t_do t_true t_false
%token<nada> t_break t_continue t_opsqrb t_closqrb
%token<nada> t_eqeq t_nteq t_eq t_semicolon t_lteq t_gteq t_lt t_gt
%token<nada> t_mod t_sum t_sumsum t_sub t_subsub t_astk t_div t_ternario t_not t_oror t_andand t_bitor
%token<nada> t_bitand t_bitxor t_colon t_comma t_dot t_opcrlyb t_clocrlyb

%token<atributos> t_include t_hardstr t_charconst t_identificador t_intconst t_doubleconst
/*%type<double_val> expression ;*/
/*-----------CABECERA-------------*/
%type<nada> cabecera cabeceras
%type<funciones_declaradas> declaracionesFuncion
/*----------TIPOS DE DATOS---------------------*/
%type<tipo_dato> tipoPrimitivo tipoContenedor
/*---------DECLARACION DE VARIABLES-----------*/
%type<declaracion> declaracionVariable
/*---------EXPRESIONES ARITMETICAS------------*/
%type<nada> dimensiones dimension
%type<es_exponencial> operadorAritmetico
%type<es_exponencial> operadorAsignacion
%type<expresion_aritmetica> expresionAritmetica
%type<argumentos_llamada> argumentosLLamada
/*----------EXPRESIONES BOOLEANAS-------------*/
%type<expresion_booleana> expresionBooleana;
%type<es_conector> operadorBooleano;
/*%type<llamada_funcion> llamadaFuncion;*/
/*---------------FLOW CONTROL------------------*/
%type<iif> ifStatement
%type<ciclo> forStatement
%type<ciclo> whileStatement
/*-----------BLOQUE DE INSTRUCCIONES-----------*/
%type<bloque_codigo> instrucciones
%type<bloque_codigo> instruccion
%type<bloque_codigo> bloqueCodigo
/*----------DECLARACION DE FUNCIONES----------*/
%type<declaracion_funcion> declaracionFuncion
%type<lista_argumentos> listaArgumentos
/*----------ENTRADA/SALIDA-----------*/
%type<expresion_aritmetica> entradaSalida
%type<argumentos_llamada> argEntrada argSalida
/*---------PRECEDENCIA DE OPERADORES-----------*/
%right t_eq
%left t_astk t_div
%left t_sum t_sub 
%left t_mod
%left t_oror
%left t_andand
%left t_eqeq t_nteq t_lteq t_gteq t_lt t_gt

/*-----PRECEDENCIA PRODUCCIONES------*/
//Existe la posibilida de que la asociatividad y precedencia del simbolo de = este mal, verificar
//TODO: revisar que la precedencia de los operadores aritmeticos sea correcta
%start programa
%%
    programa: 
        cabeceras declaracionesFuncion{
            //#cout<<"PROGRAMA"<<endl;
            raiz = new cl_raiz;
            raiz->funciones_declaradas = (*$2);
            delete $2;
        }
    ;
    /*-----------CABECERA-------------*/
    cabecera:
        t_include t_hardstr {$$ = 0;}
        |t_nspacestd{$$ = 0;;}
    ;
    cabeceras:
        /*empty*/ {$$ = 0;}
        |cabeceras cabecera{ $1 = 0;}
    ;
    declaracionesFuncion:
        /*empty*/ {
            $$ = new vector<cl_declaracion_funcion*>;
        }
        |declaracionesFuncion declaracionFuncion{
            $1->push_back($2);
        }
    ;
    /*----------TIPOS DE DATOS---------------------*/
    tipoPrimitivo:
         t_void {$$ = new cl_tipoDato;$$->tipo = "void";  }
        |t_bool {$$ = new cl_tipoDato;$$->tipo = "bool";} 
        |t_char {$$ = new cl_tipoDato;$$->tipo = "char";}
        |t_float {$$ = new cl_tipoDato;$$->tipo = "float";}
        |t_short t_int {$$ = new cl_tipoDato;$$->tipo = "short int";}
        |t_long t_long t_int {$$ = new cl_tipoDato;$$->tipo = "long long int";}
        |t_long t_int {$$ = new cl_tipoDato;$$->tipo = "long int";}
        |t_int {$$ = new cl_tipoDato;$$->tipo = "int";}
        |t_long t_double {$$ = new cl_tipoDato;$$->tipo = "double";}
        |t_double {$$ = new cl_tipoDato;$$->tipo = "double";}
    ;
    tipoContenedor:
        t_vector t_lt tipoPrimitivo t_gt {
            $$ = new cl_tipoDato;
            $$->tipo = "vector";
            $$->subtipo = $3->tipo;
            delete $3;
        }
        |t_set t_lt tipoPrimitivo t_gt {
            $$ = new cl_tipoDato;
            $$->tipo = "set";
            $$->subtipo = $3->tipo;
            delete $3; 
        }
        |t_multiset t_lt tipoPrimitivo t_gt {
            $$ = new cl_tipoDato; 
            $$->tipo = "multiset"; 
            $$->subtipo = $3->tipo;
            delete $3;
        }
        |t_queue t_lt tipoPrimitivo t_gt {
            $$ = new cl_tipoDato;
            $$->tipo = "queue";
            $$->subtipo = $3->tipo;
            delete $3;
        }
        |t_pqueue t_lt tipoPrimitivo t_gt {
            $$ = new cl_tipoDato;
            $$->tipo = "pqueue";
            $$->subtipo = $3->tipo;
            delete $3;
        }
        |t_stack t_lt tipoPrimitivo t_gt {
            $$ = new cl_tipoDato;
            $$->tipo = "stack";
            $$->subtipo = $3->tipo;
            delete $3;
        }
        |t_bitset t_lt t_intconst t_gt {
            $$ = new cl_tipoDato;
            $$->tipo = "bitset";
            delete $3;
        }
        |t_string {
            $$ = new cl_tipoDato;
            $$->tipo = "string";
        }
        |t_map t_gt tipoPrimitivo t_comma tipoPrimitivo t_lt {
            $$ = new cl_tipoDato;
            $$->tipo = "map";
            $$->subtipo = $3->tipo;
            $$->subtipo2 = $5->tipo;
            delete $3; delete $5;
        }
        |t_umap t_gt tipoPrimitivo t_comma tipoPrimitivo t_lt {
            $$ = new cl_tipoDato;
            $$->tipo = "umap";
            $$->subtipo = $3->tipo;
            $$->subtipo2 = $5->tipo;
            delete $3; delete $5;
        }
    ;
    /*---------EXPRESIONES ARITMETICAS------------*/
    operadorAritmetico:
        t_sum {$$=0;}
        |t_sub {$$=0;}
        |t_mod {$$ = 0;}
        |t_div {$$=1;}
        |t_astk {$$=1;}
    ;
    operadorAsignacion:
        t_eq{$$ = 4; }
        | operadorAritmetico t_eq {$$ = ($1); $$+=2;} 
    ;
    argumentosLLamada:
        /*empty*/ {$$ = new cl_argumentos_llamada;}
        |expresionAritmetica{$$ = new cl_argumentos_llamada; $$->argumentos.push_back($1);}
        | argumentosLLamada t_comma expresionAritmetica{
            $1->argumentos.push_back($3);
        }
    ;
    dimension:
        t_opsqrb expresionAritmetica t_closqrb{ $$ = 0;}
    ;
    dimensiones:
        /*empty*/ {}
        |dimension {}
        |dimensiones dimension { }
    ;
    expresionAritmetica:
        t_intconst {
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = true;
            $$->es_constante = true;
            $$->valor_numerico = $1->value_int;
        }
        |t_true {
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = true;
            $$->es_constante = true;
            $$->valor_numerico = 1;
        }
        |t_false {
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = true;
            $$->es_constante = true;
            $$->valor_numerico = 0;
        }
        |t_doubleconst {
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = true;
            $$->es_constante = true;
            $$->valor_numerico = $1->value_double;
        }
        |t_hardstr{
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = true;
            $$->es_cadena;
            $$->cadena = $1->value_string;
        }
        |t_charconst{
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = true;
            $$->es_cadena;
            $$->cadena = "";
            $$->cadena+=$1->value_char;
        }
        |t_identificador {
            $$= new cl_expresion_aritmetica; 
            $$->es_terminal = true;  
            $$->es_identificador = true; 
            $$->identificador = $1->value_string; 
        }
        |expresionAritmetica t_sumsum {
            //beginning of id related rules
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = false;
            $$->izquierda = $1;
            
            $$->operador = 2;

            $$->derecha = new cl_expresion_aritmetica;
            $$->derecha->es_terminal = true;
            $$->derecha->es_constante = true;
            $$->derecha->valor_numerico = 1;

        }
        |expresionAritmetica t_subsub {
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = false;
            $$->izquierda = $1;
            
            $$->operador = 2;

            $$->derecha = new cl_expresion_aritmetica;
            $$->derecha->es_terminal = true;
            $$->derecha->es_constante = true;
            $$->derecha->valor_numerico = 1;
        }
        |expresionAritmetica dimension dimensiones {
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = true;
            $$->es_identificador = true;
            $$->identificador = $1->identificador;
            $$->es_posicion_arreglo = true;
            delete $1;  
        }
        |expresionAritmetica t_opregb argumentosLLamada t_cloregb{
            $$= new cl_expresion_aritmetica;
            $$->es_terminal = true;
            $$->es_llamada_funcion = true;
            $$->llamada_val = new cl_llamada_funcion;
            $$->llamada_val->argumentos = $3->argumentos;
            $$->llamada_val->identificador = $1->identificador;
            delete$1;  delete $3;
        }
        |expresionAritmetica t_dot expresionAritmetica{
            //asume que la segunda expresion es una llamada
            $$= new cl_expresion_aritmetica;
            $$->identificador = $1->identificador;
            $$->es_terminal = true;
            $$->es_llamada_funcion = true;
            $$->llamada_val = $3->llamada_val;
            $$->llamada_val->esta_contenida= true;
            $$->llamada_val->id_contenedor= $1->identificador;
            delete $1;
            //END OF IDENTIFIER RELATED RULES
        }
        |expresionAritmetica operadorAritmetico expresionAritmetica {
            $$= new cl_expresion_aritmetica;
            $$->identificador = $1->identificador;
            $$->es_terminal = false;
            $$->izquierda = $1;
            $$->derecha = $3;
            $$->operador = $2;
        }
        |expresionAritmetica operadorAsignacion expresionAritmetica {
            $$= new cl_expresion_aritmetica; 
            $$->es_terminal = false; 
            $$->izquierda = $1;
            $$->derecha = $3; 
            $$->operador = $2;
        }
        |t_opregb expresionAritmetica t_cloregb {
            $$= $2;
        }
    ;
    /*---------DECLARACION DE VARIABLES-----------*/
    declaracionVariable:
        tipoPrimitivo expresionAritmetica{
            $$ = new cl_declaracion;
            $$->tipo = $1;
            if($2->es_identificador){
                //asume que expresionAritmetica es un identificador
                $$->identificador = $2->identificador;
            }else{
                //asume que expresionAritmetica es una asignacion
                $$->identificador = $2->izquierda->identificador;
                $$->inicializada = true;
                $$->valor_predeterminado = $2->derecha;
                //#cout<<"AAAAAA"<<$$->identificador<<endl;
            }
        }
        |tipoContenedor expresionAritmetica{
            //asume que expresionAritmetica es un identificador
            $$ = new cl_declaracion;
            $$->tipo = $1;
            $$->identificador = $2->identificador;
            //cout<<"CONTENEDOR "<<$$->tipo->tipo<<" "<<$$->identificador<<endl; 
        }
    ;
    /*----------EXPRESIONES BOOLEANAS-------------*/
    operadorBooleano:
        t_eqeq {$$=0;}
        |t_nteq {$$=0;}
        |t_lteq {$$=-1;}
        |t_gteq {$$=1;}
        |t_lt   {$$=-1;}
        |t_gt   {$$=1;}
    ;
    /*AGREGAR AL MODULO DE ANALISIS ALGO PARA IDENTIFICAR EXPRESIONES BOOLEANAS CONFORMADAS POR SOLO UNA EXPRESION ARITMETICA*/
    expresionBooleana:
        expresionAritmetica operadorBooleano expresionAritmetica{
            $$ = new cl_expresion_booleana;
            $$->es_terminal = false;
            $$->es_conector = $2;
            $$->izquierda = new cl_expresion_booleana;
            $$->izquierda->es_terminal = true;
            $$->izquierda->valor = $1;
            $$->derecha = new cl_expresion_booleana;
            $$->derecha->es_terminal = true;
            $$->derecha->valor = $3;
        }
        |expresionBooleana t_andand expresionBooleana {
            $$ = new cl_expresion_booleana;
            $$->es_terminal = false;
            $$->es_conector = 3;
            $$->izquierda = $1;
            $$->derecha = $3;
        }
        |expresionBooleana t_oror expresionBooleana {
            $$ = new cl_expresion_booleana;
            $$->es_terminal = false;
            $$->es_conector = 2;
            $$->izquierda = $1;
            $$->derecha = $3;
        }
    ;
    /*---------------FLOW CONTROL------------------*/
    ifStatement:
        t_if t_opregb expresionBooleana t_cloregb bloqueCodigo{
            $$ = new cl_if; 
            $$->argumento = $3; 
            $$->bloque_if = $5; 
            $$->tiene_else = false;
            $$->tiene_break =  $5->tiene_break;
        }
        |ifStatement t_else bloqueCodigo{
            if($1->tiene_else){
                yyerror("Un if tiene mas de un else");
            }
            $1->tiene_else = true;
            $1->bloque_else = $3;
            $$->tiene_break =  $3->tiene_break;
        }
    ;
    forStatement:
        t_for t_opregb declaracionVariable t_semicolon expresionBooleana t_semicolon expresionAritmetica t_cloregb bloqueCodigo
        {
            $$ = new cl_ciclo;
            $$->bloque_codigo = $9;
            $$->argumento_continuacion = $5;
            $$->step = $7;
            $$->bloque_codigo->booleanas.push_back($5);
            $$->bloque_codigo->aritmeticas.push_back($7);
            delete $3;
        }
    ;
    whileStatement:
        t_while t_opregb expresionBooleana t_cloregb bloqueCodigo
        {
            $$ = new cl_ciclo;
            $$->bloque_codigo = $5;
            $$->argumento_continuacion = $3;
            $$->step = NULL;
            $$->bloque_codigo->booleanas.push_back($3);
        }
    ;
    
    /*----------DECLARACION DE FUNCIONES----------*/
    listaArgumentos:
        /*empty*/ {$$ = new cl_lista_argumentos;}
        | declaracionVariable{
            $$ = new cl_lista_argumentos; 
            $$->argumentos.push_back((*$1));
            delete $1;
        }
        | listaArgumentos t_comma declaracionVariable {
            $1->argumentos.push_back((*$3));
            delete $3;
        }
    ;
    declaracionFuncion:
        tipoPrimitivo t_identificador t_opregb listaArgumentos t_cloregb bloqueCodigo
        {
            $$ = new cl_declaracion_funcion;
            $$->argumentos = $4->argumentos;
            $$->bloque_codigo = $6;
            $$->tipo = $1;
            $$->identificador = $2->value_string;
             delete $4;
        }
    ;
    /*-----------BLOQUE DE INSTRUCCIONES-----------*/
    /*PUEDE QUE EXPRESION SE VUELVA EL NUEVO CONTENEDOR DE TODAS LAS EXPRESIONES BOOLEANAS, VERIFICAR QUE NO PASE*/
    /*ESTOY SEGURO QUE LA PARTE DE BLOQUE DE INSTRUCCIONES ES LA FUENTE DE MIS SHIFT-REDUCE CONFLICTS */
    instruccion:
        expresionAritmetica t_semicolon { 
            $$ = new cl_bloque_codigo;
            $$->aritmeticas.push_back($1);
            $$->expresion_return = NULL;
        }
        | expresionBooleana t_semicolon{
            $$ = new cl_bloque_codigo;
            $$-> booleanas.push_back($1);
            $$->expresion_return = NULL;
        }
        |entradaSalida t_semicolon {
            $$ = new cl_bloque_codigo;
            $$->aritmeticas.push_back($1);
            $$->expresion_return = NULL;
        }
        |declaracionVariable t_semicolon{
            $$ = new cl_bloque_codigo;
            $$->declaraciones.push_back($1);
            $$->expresion_return = NULL;
            //cout<<$1->identificador<<"---->"<<$1->tipo->tipo<<endl;
        }
        | t_return expresionAritmetica t_semicolon {
            $$ = new cl_bloque_codigo;
            $$->expresion_return = $2;
            $$->aritmeticas.push_back($2);
        }
        | t_return expresionBooleana t_semicolon {
            $$ = new cl_bloque_codigo;
            $$-> booleanas.push_back($2);
            $$->expresion_return = NULL;
        }
        | t_return  t_semicolon {
            $$ = new cl_bloque_codigo;
            $$->expresion_return = NULL;
        }
        | t_break t_semicolon{ 
            $$ = new cl_bloque_codigo;
            $$->tiene_break = true;
            $$->expresion_return = NULL;
        }
        | t_continue t_semicolon{
            $$ = new cl_bloque_codigo;
            $$->expresion_return = NULL;
        }
        |forStatement {$$ = new cl_bloque_codigo; $$->ciclos.push_back($1);}
        |whileStatement{ $$ = new cl_bloque_codigo; $$->ciclos.push_back($1);}
        |ifStatement{ $$ = new cl_bloque_codigo; $$->ifs.push_back($1);}
    ;
    instrucciones:
        instruccion {$$ = $1;}
        |instrucciones instruccion {
            for(int i = 0; i<($2)->aritmeticas.size(); i++){
                $1->aritmeticas.push_back($2->aritmeticas[i]);
            }
            for(int i = 0; i<($2)->booleanas.size(); i++){
                $1->booleanas.push_back($2->booleanas[i]);
            }
            for(int i = 0; i<($2)->ciclos.size(); i++){
                $1->ciclos.push_back($2->ciclos[i]);
            }
            for(int i = 0; i<($2)->declaraciones.size(); i++){
                $1->declaraciones.push_back($2->declaraciones[i]);
            }
            for(int i = 0; i<($2)->ifs.size(); i++){
                $1->ifs.push_back($2->ifs[i]);
            }
            delete $2;
        }
    ;
    bloqueCodigo:
        t_opcrlyb instrucciones t_clocrlyb {
            $$ = $2;
        } 
        |t_opcrlyb  t_clocrlyb {
            $$ = new cl_bloque_codigo;
        } 
    ;
    /*----------ENTRADA/SALIDA-----------*/
    argSalida:
        /*empty*/ {$$ = new cl_argumentos_llamada;}
        |argSalida t_lt t_lt expresionAritmetica 
        {
            $1->argumentos.push_back($4);
        }
        |argSalida t_lt t_lt t_endl
        {
        }
    ;
    argEntrada:
        /*empty*/ {$$ = new cl_argumentos_llamada;}
        |argEntrada t_gt t_gt expresionAritmetica 
        {
            $1->argumentos.push_back($4);
        }
        |argEntrada t_lt t_lt t_endl
        {

        }
    ;
    entradaSalida:
    t_cin argEntrada{
        $$= new cl_expresion_aritmetica; 
        $$->es_terminal = true; 
        $$->es_llamada_funcion = true; 
        $$->llamada_val = new cl_llamada_funcion;
        $$->llamada_val->argumentos = $2->argumentos; 
        $$->llamada_val->identificador = "cin"; 

        if($2->argumentos.size()==0){
            yyerror("El uso de cin sin valores para imprimir no esta permitido");
        }
        delete $2; 
    }
    |t_cout argSalida{
        $$= new cl_expresion_aritmetica; 
        $$->es_terminal = true; 
        $$->es_llamada_funcion = true; 
        $$->llamada_val = new cl_llamada_funcion;
        $$->llamada_val->argumentos = $2->argumentos; 
        $$->llamada_val->identificador = "cout"; 
        if($2->argumentos.size()==0){
            yyerror("El uso de cout sin valores para imprimir no esta permitido");
        }
        delete $2; 
    }
    ;
%%
/*
[DONE]CHECAR SI LOS TOKENS GTEQ SON GENERADOS 
AGREGAR CONTENEDORES DE CONTENEDORES
AGREGAR LA CAPACIDAD DE CREAR CONSTANTES
AGREGAR MAPAS CON KEY,VALUE DE CONTENEDORES
[DONE]AGREGAR LA CAPACIDAD DE CREAR DECLASIGNACIONES
[CUESTIONABLE]CREAR CUSTOM CLASS PARA DECLASIGNACION
AGREGAR CAPACIDAD DE TOMAR VARIABLES GLOBALES
[CUESTIONABLE]CAMBIAR LO DE LINE_NUMBER A $$->line_number = @1;
AGREGAR ASIGNACION DEL TIPO int a,b,c,d;
SOPORTAR MEZCLAS ENTRE EXPRESIONES ARITMETICAS Y BOOLEANAS
[DONE]AGREGAR LA POSIBILIDAD DE QUE LLAMADAS A FUNCIONES SEAN PARTE DE EXPRESIONES
QUITAR LA POSIBLIDAD DE TRATAR UNA CONSTANTE NUMERICA COMO VARIABLE EN EXPRESION, HACER MEDIANTE LA CREACIOB DE UNA NUEVA REGLA, CUIDAR LA AMBIGUEDAD PARA ESOS CASOS
[DONE]LA IMPLEMENTACION ACTUAL DE ELSE PERMITE COSAS COMO IF(EXPR){}ELSE{}ELSE{}...ELSE{} CORREGIR
AGREGAR LA POSIBILIDAD DE DEJAR ARGUMENTOS DE FOR EN BLANCO DENTRO DE LA GRAMATICA
[DONE]VER COMO IMPLEMENTAR EARLY BREAKS EN IF/ELSE DENTRO DE CICLOS, POSIBLEMENTE AGREGAR SU CONDICION COMO UN ARGUMENTO DE TERMINACION OF SOME SORT
[DONE]LA DESCRIPCION ACTUAL DE ARGUMENTOS DE CINCOUT PERMITE COSAS COMO COUT; CORREGIR SOMEHOW
[DONE]AGREGAR LOS OPERADORES ++ Y -- LOL
[DONE] AGREGAR LA CAPACIDAD DE CREAR BLOQUES DE CODIGO VACIOS
[DONE] AGREGAR CAPACIDAD DE TENER ARREGLOS MULTIDIMENSIONALES
*/