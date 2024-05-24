#include <iostream>
#include "nodos.h"
#include <string> 
#include <algorithm>
#include <map>
#include <set>
#include "analizadorPrecedencia.hpp"
extern cl_raiz* raiz;
extern int yyparse();
extern void analizador_complejidad(std::vector<cl_declaracion_funcion*> orden_topologico);
extern void pionero();
void explorar(int lvl, cl_expresion_booleana* curr){
    if(!curr->es_terminal){
        explorar(lvl*2, curr->izquierda);
        cout<<lvl<<" --> "<<curr->es_conector<<endl;
        explorar(lvl*2+1, curr->derecha);
        return;
    }
    cout<<lvl<<" --> "<<curr->valor->identificador<<endl;
}
void explorar(int lvl, cl_expresion_aritmetica* curr){
    if(!curr->es_terminal){
        explorar(lvl*2, curr->izquierda);
        cout<<lvl<<" --> "<<curr->operador<<endl;
        explorar(lvl*2+1, curr->derecha);
        return;
    }
    cout<<lvl<<" --> "<<curr->identificador<<endl;
}
int main(int argc, char **argv)
{
    yyparse();
    analizador_precedencia analizadorPrecedencia(raiz);
    analizadorPrecedencia.esRecursivo();
    /*std::cout<<(analizadorPrecedencia.esRecursivo()?"RECURSIVO":"NO RECURSIVO")<<std::endl;
    for(cl_declaracion_funcion* el: analizadorPrecedencia.orden_topologico){
        std::cout<<el->identificador<<std::endl;
    }*/


    /*for(cl_expresion_booleana* curr: raiz->funciones_declaradas[0]->bloque_codigo->booleanas){
        explorar(1,curr);
        cout<<endl<<endl;
    }
    for(cl_expresion_aritmetica* curr: raiz->funciones_declaradas[0]->bloque_codigo->aritmeticas){
        explorar(1,curr);
        cout<<endl<<endl;
    }*/


    analizador_complejidad(analizadorPrecedencia.orden_topologico);
    //std::cout << "end me" << std::endl;
    return 0;
}