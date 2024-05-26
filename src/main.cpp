#include <iostream>
#include "nodos.hpp"
#include "analizadorPrecedencia.hpp"
extern cl_raiz* raiz;
extern FILE * yyin;
extern int yyparse();
extern void analizador_complejidad(std::vector<cl_declaracion_funcion*> orden_topologico);

int main(int argc, char **argv)
{
    //toma el archivo del primer argumento
    FILE * file = fopen ( argv [1] ,"r");
    if(file == NULL){
        cout<<"archivo inexistente"<<endl;
        return 0;
    }else{
        yyin = file ;
    }
    yyparse();
    analizador_precedencia analizadorPrecedencia(raiz);
    if(analizadorPrecedencia.esRecursivo()){
        cout<<"El código fuente contiene por lo menos una dependencia circular de funciones"<<endl;
        return 0;
    }

    analizador_complejidad(analizadorPrecedencia.orden_topologico);
    return 0;
}