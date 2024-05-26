#include <iostream>
#include "nodos.hpp"
#include <string> 
#include <algorithm>
#include <map>
#include <set>
#include "analizadorPrecedencia.hpp"
extern cl_raiz* raiz;
extern int yyparse();
extern void analizador_complejidad(std::vector<cl_declaracion_funcion*> orden_topologico);

int main(int argc, char **argv)
{
    yyparse();
    analizador_precedencia analizadorPrecedencia(raiz);
    analizadorPrecedencia.esRecursivo();

    analizador_complejidad(analizadorPrecedencia.orden_topologico);
    return 0;
}