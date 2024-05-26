#include "polinomios.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;



class cl_declaracion;
class cl_modificacion;
class cl_expresion_booleana;
class cl_expresion_aritmetica;
class cl_argumentos_llamada;
class cl_lista_argumentos;
class cl_ciclo;
class cl_declaracion_funcion;
class cl_llamada_funcion;
class cl_tipoDato;
class cl_bloque_codigo;


class cl_atributos_tokens{
public:
    int token_id;
    int line_number;
    long long int value_int;
    long double value_double;
    std::string value_string;
    char value_char;
};
class cl_raiz{
public:
    std::vector<cl_declaracion*> globales_declaradas;
    std::vector<cl_declaracion_funcion*> funciones_declaradas;

    int low_link_value;
    int scc_id;
};


class cl_expresion_booleana{
public: 
    cl_expresion_booleana* izquierda;
    cl_expresion_booleana* derecha;
    //-1/0/1- >puede ser terminal o puede ser cualquier operador, 1-> ||, 2-> &&
    int es_conector;
    bool es_terminal;
    cl_expresion_aritmetica* valor;
    cl_complejidad complejidad;
    bool es_logaritmica;


    int low_link_value;
    int scc_id;
};

class cl_expresion_aritmetica{
public:
    //SI NO ES TERMINAL, LEFT SERA TOMADA COMO NEXT
    cl_expresion_aritmetica* izquierda;
    cl_expresion_aritmetica* derecha;
    
    //0 -> (+-), 1-> (*/), 2->(+=-=), 3->(/=*=), 4-> (=)
    int operador;
    bool es_terminal;

    bool es_llamada_funcion;
    cl_llamada_funcion* llamada_val;

    bool es_constante;
    long double valor_numerico;
    
    bool es_cadena;
    string cadena;

    bool es_identificador;
    string identificador;

    bool es_posicion_arreglo;
    bool es_asignacion;

    cl_complejidad complejidad;
    int low_link_value;
    int scc_id;
};  
class cl_argumentos_llamada{
public:
    vector<cl_expresion_aritmetica*> argumentos;
};



class cl_llamada_funcion{
public: 
    string identificador;
    //si es un metodo miembro de una clase
    bool esta_contenida;
    string id_contenedor;
    vector<cl_expresion_aritmetica*> argumentos;
};

class cl_if{
public:
    cl_expresion_booleana* argumento;
    cl_bloque_codigo* bloque_if;
    bool tiene_else;
    cl_bloque_codigo* bloque_else;
    bool tiene_break;

    int low_link_value;
    int scc_id;
};

class cl_ciclo{
public: 
    cl_expresion_booleana* argumento_continuacion;
    cl_expresion_aritmetica* step;
    cl_bloque_codigo* bloque_codigo;

    int low_link_value;
    int scc_id;
};
class cl_bloque_codigo{
public:
    vector<cl_expresion_aritmetica*> aritmeticas;
    vector<cl_expresion_booleana*> booleanas;
    vector<cl_declaracion*> declaraciones;
    vector<cl_ciclo*> ciclos;
    vector<cl_if*> ifs;
    bool tiene_break;
    cl_expresion_aritmetica* expresion_return;
};

class cl_tipoDato{
public: 
    string tipo;
    //aplica solo para el tipo de contenedores
    string subtipo;
    string subtipo2;
};

class cl_declaracion{
public: 
    string identificador;
    //either primitive or the name of the container
    cl_tipoDato* tipo;

    bool inicializada;
    cl_expresion_aritmetica* valor_predeterminado;

    int low_link_value;
    int scc_id;
};

class cl_lista_argumentos{
public:
    std::vector<cl_declaracion> argumentos;
};

class cl_declaracion_funcion{
public: 
    string identificador;
    std::vector<cl_declaracion> argumentos; 
    cl_bloque_codigo* bloque_codigo;
    cl_tipoDato* tipo;

    bool es_recursiva;
    int low_link_value;
    int scc_id;
};