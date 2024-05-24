#include "bits/stdc++.h"
#include "nodos.h"


using namespace std;
cl_complejidad crea_o_constante(){
    cl_complejidad constante;
    return constante;
}
cl_complejidad crea_o_lineal(string identificador){
    cl_factor on(2,1,identificador);
    cl_complejidad lineal;
    lineal.sumandos[0].factores.pop_back();
    lineal.sumandos[0].factores.push_back(on);
    return lineal;
}
cl_complejidad crea_o_logaritmica(string identificador){
    cl_factor ologn(1,1,identificador);
    cl_complejidad logaritmica;
    logaritmica.sumandos[0].factores.pop_back();
    logaritmica.sumandos[0].factores.push_back(ologn);
    return logaritmica;
}


bool contiene_llamada(cl_expresion_aritmetica* actual,string identificador_objetivo){
    if(actual->es_terminal){
        if(actual->es_llamada_funcion && actual->es_llamada_funcion){
            return (actual->llamada_val->identificador==identificador_objetivo);
        }
        return false;
    }
    return (contiene_llamada(actual->izquierda,identificador_objetivo) || contiene_llamada(actual->derecha,identificador_objetivo));
}
class cl_analizador{
private:

    
    bool estaPredefinida(string identificador);
    cl_expresion_booleana* retorno_pendientes;

    vector<cl_declaracion_funcion*> orden_topologico;
    map<string,cl_declaracion_funcion*> definiciones;
    map<string, cl_complejidad> complejidad_funcion;
    map<string, bool> modifica_tam_contenedor;
    //tipo de contenedor, identificadorde la funcion, complejidad asociada
    map<string,map<string,cl_complejidad>> complejidad_funcion_contenida;
    //cambia por cada declaracion de funcion
    //identificador, tipo de dato
    map<string,cl_tipoDato> tipado_de_variable;
    
    //resetear al inicio de cada expresion aritmetica no contenida
    map<string,int> apariciones_en_aritmetica;
    //0->constante, 1->lineal, 2->exponencial
    //lvl de anidamiento, id, tasa de crec
    map<int,map<string,int>> tasa_crecimiento_variable; 
    int anidamiento_actual;
    
    void inicializador_complejidades_predefinidas();//[DONE]
    cl_complejidad obtener_complejidad(cl_llamada_funcion* llamada);//[DONE]
    cl_complejidad obtener_complejidad(string identificador_funcion,string identificador,cl_tipoDato tipoContenedor);//[DONE]
    cl_complejidad analizar(cl_if* actual);//[DONE]
    cl_complejidad analizar(cl_ciclo* actual);//[DONE]
    cl_complejidad analizar(cl_declaracion* actual);//[DONE]
    cl_complejidad analizar(cl_expresion_booleana* actual);//[DONE]
    cl_complejidad analizar(cl_expresion_aritmetica* actual);//[DONE]
    cl_complejidad analizar_no_asignacion(cl_expresion_aritmetica* actual);//[DONE]
    cl_complejidad analizar(cl_bloque_codigo* actual);//[DONE]
public:
    //doesn´t make sense for it to be public, but fuck it
    string identificador_declaracion_funcion;
    cl_analizador(vector<cl_declaracion_funcion*> orden_topologico);//[DONE]
    cl_complejidad analizar(cl_declaracion_funcion* actual);  //[DONE]
    cl_complejidad analizar_recursiva(cl_declaracion_funcion* actual);  //[DONE]
};


void analizador_complejidad(vector<cl_declaracion_funcion*> orden_topologico){
    cl_analizador analizador(orden_topologico);
    cl_complejidad complejidad;
    cl_complejidad comp_funcion;
    for(cl_declaracion_funcion* declaracion: orden_topologico){
        analizador.identificador_declaracion_funcion = declaracion->identificador;
        if(declaracion->es_recursiva){
            comp_funcion = analizador.analizar_recursiva(declaracion);
        }else{
            comp_funcion = analizador.analizar(declaracion);
        }
        if(declaracion->identificador == "main"){
            complejidad = complejidad + comp_funcion;
        }
        
        //#cout<<"OwO  "<<declaracion->identificador;
        //#comp_funcion.imprimir_expresion();
    }   

    complejidad.imprimir_expresion();
}



cl_analizador::cl_analizador(vector<cl_declaracion_funcion*> orden_topologico){
    this->orden_topologico = orden_topologico;
    for(cl_declaracion_funcion* declaracion_actual: orden_topologico){
        definiciones[declaracion_actual->identificador] = declaracion_actual;
    }
    inicializador_complejidades_predefinidas();
    anidamiento_actual = 0;
    modifica_tam_contenedor["push_back"] = true;
    modifica_tam_contenedor["pop_back"] = true;
    modifica_tam_contenedor["insert"] = true;
    modifica_tam_contenedor["erase"] = true;
    modifica_tam_contenedor["push"] = true;
    modifica_tam_contenedor["pop"] = true;
    modifica_tam_contenedor["clear"] = true;
}


cl_complejidad cl_analizador::analizar(cl_ciclo* actual){
    cl_complejidad complejidad;
    anidamiento_actual++;

    if(actual->step != NULL){
        complejidad = complejidad + analizar(actual->step);
    }

    complejidad = complejidad + analizar(actual->bloque_codigo);

    //TODO: Come up with a way to include early breaks that really changes the complexity
    //maybe something with the form of (x%100) == 54
    //#cout<<"CICLO"<<endl;
    //#actual->argumento_continuacion->complejidad.imprimir_expresion();
    //#complejidad.imprimir_expresion();


    complejidad = complejidad + analizar(actual->argumento_continuacion);

    complejidad = complejidad * actual->argumento_continuacion->complejidad;
    
    
    
    //#complejidad.imprimir_expresion();
    anidamiento_actual--;
    return complejidad;
}           

cl_complejidad cl_analizador::analizar(cl_if* actual){
    cl_complejidad complejidad;

    complejidad = complejidad + analizar(actual->bloque_if);
    complejidad = complejidad + analizar(actual->argumento);
    if(actual->bloque_if->expresion_return != NULL){
        if(contiene_llamada(actual->bloque_if->expresion_return,identificador_declaracion_funcion) == false){
            retorno_pendientes = actual->argumento;
        }
    }

    //
    for(cl_if* ifactual: actual->bloque_if->ifs){
        if(ifactual->tiene_break && actual->tiene_break == false){
            actual->argumento = ifactual->argumento;
            actual->tiene_break = true;
        }
        if(ifactual->tiene_break && actual->tiene_break){
            if(ifactual->argumento->es_logaritmica){
                actual->argumento = ifactual->argumento;
            }
        }
    }
    
    if(actual->tiene_else){
        complejidad = complejidad + analizar(actual->bloque_else);
        for(cl_if* ifactual: actual->bloque_else->ifs){
            if(ifactual->tiene_break && actual->tiene_break == false){
                actual->argumento = ifactual->argumento;
                actual->tiene_break = true;
            }
            if(ifactual->tiene_break && actual->tiene_break){
                if(ifactual->argumento->es_logaritmica){
                    actual->argumento = ifactual->argumento;
                }
            }
        }
    }

    //#cout<<"IF-.---"<<endl;
    //#complejidad.imprimir_expresion();
    return complejidad;
}


cl_complejidad analizar_no_asignacion(cl_expresion_aritmetica* actual){
    cl_complejidad complejidad;
    if(actual->es_terminal && actual->es_identificador){
        complejidad = crea_o_lineal(actual->identificador);
    }
    if(actual->es_terminal== false && actual->operador == 1){
        complejidad = actual->izquierda->complejidad*actual->derecha->complejidad;
    }
    return complejidad;
}
cl_complejidad cl_analizador::analizar(cl_expresion_aritmetica* actual){
    cl_complejidad complejidad;
    //TODO: modificar para que no se intente calcular la complejidad de una funcion recursiva aqui
    if(actual->es_terminal && actual->es_llamada_funcion){
        if(actual->llamada_val->esta_contenida){
            complejidad = complejidad + obtener_complejidad(actual->llamada_val->identificador, actual->identificador,tipado_de_variable[actual->identificador]);
        }else{
            //#cout<<actual->llamada_val->identificador;
            complejidad = complejidad + obtener_complejidad(actual->llamada_val);

            //llamada recursiva
            if(identificador_declaracion_funcion == actual->llamada_val->identificador){
                // ELIMINAR SI FALLA
                //revisa la tasa de crecimiento entre llamadas recursivas
                
                int anidamiento_original = anidamiento_actual;
                anidamiento_actual = -1;
                cl_expresion_aritmetica* asignacion_por_llamada;
                asignacion_por_llamada->izquierda = new cl_expresion_aritmetica;
                asignacion_por_llamada->izquierda->es_terminal = true;
                asignacion_por_llamada->izquierda->es_identificador = true;
                asignacion_por_llamada->operador = 4; 

                int ind = 0;
                cl_declaracion_funcion* decl_actual = definiciones[identificador_declaracion_funcion];

                //#cout<<"TTT___TTTT"<<endl;
                for(cl_expresion_aritmetica* argumento : actual->llamada_val->argumentos){
                    asignacion_por_llamada->izquierda->identificador = decl_actual->argumentos[ind].identificador;
                    //#cout<<decl_actual->argumentos.size()<<decl_actual->argumentos[ind].identificador<<endl;
                    asignacion_por_llamada->derecha = argumento;
                    
                    analizar(asignacion_por_llamada);
                    ind++;
                }
                anidamiento_actual = anidamiento_original;
            }
            
        }

        
        if(actual->llamada_val->esta_contenida && modifica_tam_contenedor[actual->llamada_val->identificador]){
            tasa_crecimiento_variable[anidamiento_actual][actual->llamada_val->id_contenedor] = 1;
        }
    }
    if(actual->es_terminal && actual->es_posicion_arreglo){
        complejidad = complejidad + obtener_complejidad("[]", actual->identificador,tipado_de_variable[actual->identificador]);
        apariciones_en_aritmetica[actual->identificador]++;
    }
    if(actual->es_terminal && actual->es_identificador){
        apariciones_en_aritmetica[actual->identificador]++;
    }
    if(actual->es_terminal) return complejidad;
    //asume que esto se cumple
    //if(actual->es_terminal == false){
    complejidad = complejidad + analizar(actual->izquierda);
    complejidad = complejidad + analizar(actual->derecha);

    string identificador = actual->izquierda->identificador;
    //Tasas de crecimiento, se asumen que en este solo pueden cambiar dentro de una asignacion
    if(actual->operador >=2){
        int valor = tasa_crecimiento_variable[anidamiento_actual][identificador];
        valor = max(valor,1);
        tasa_crecimiento_variable[anidamiento_actual][identificador] = valor;
        apariciones_en_aritmetica.clear();
        if(actual->derecha->es_terminal == true && actual->derecha->es_identificador == true){
            tasa_crecimiento_variable[anidamiento_actual][identificador] = tasa_crecimiento_variable[anidamiento_actual][actual->derecha->identificador]; 
            //#cout<< identificador <<"^_^"<<endl;
        }
    }
    if(actual->operador ==2){
        if(actual->derecha->es_terminal == false && apariciones_en_aritmetica[identificador]>=2){
            tasa_crecimiento_variable[anidamiento_actual][identificador] = 2;
        }
    }
    if(actual->operador ==3){
        tasa_crecimiento_variable[anidamiento_actual][identificador] = 2;
    }
    if(actual->operador == 4){
        if(actual->derecha->es_terminal == false && actual->derecha->operador == 1){
            tasa_crecimiento_variable[anidamiento_actual][identificador] = 2;
            //#cout<< identificador <<"^_^"<<endl;
        }
        if(actual->derecha->es_terminal == false && apariciones_en_aritmetica[identificador]>=3){
            tasa_crecimiento_variable[anidamiento_actual][identificador] = 2;
        }
        if(actual->derecha->es_terminal == true && actual->derecha->es_identificador == true){
            tasa_crecimiento_variable[anidamiento_actual][identificador] = tasa_crecimiento_variable[anidamiento_actual][actual->derecha->identificador]; 
            //#cout<< identificador <<"^_^"<<endl;
        }
    }
    
    return complejidad;
}
//TODO: Mejorar el crecimiento previsto para expresiones booleanas
//De manera que tome O(logn + logm) o cosas de ese estilo
cl_complejidad cl_analizador::analizar(cl_expresion_booleana* actual){
    cl_complejidad complejidad;
    if(actual->es_terminal){
        complejidad = complejidad + analizar(actual->valor);
        return complejidad;
    }else{
        complejidad = complejidad + analizar(actual->izquierda);
        complejidad = complejidad + analizar(actual->derecha);
    }
    if(actual->es_conector==3){
        if(actual->izquierda->es_logaritmica){
            complejidad = actual->izquierda->complejidad;
            actual->es_logaritmica = actual->izquierda->es_logaritmica;
        }else{
            complejidad = actual->derecha->complejidad;
            actual->es_logaritmica = actual->derecha->es_logaritmica;
        }
    }
    if(actual->es_conector==2){
        if(actual->izquierda->es_logaritmica == false){
            complejidad = actual->izquierda->complejidad;
            actual->es_logaritmica = actual->izquierda->es_logaritmica;
        }else{
            complejidad = actual->derecha->complejidad;
            actual->es_logaritmica = actual->derecha->es_logaritmica;
        }
    }
    if(actual->es_conector>=2){
        return complejidad;
    }
    //asume que la desigualdad es en funcion de constantes numericas o identificadores
    //es una expresion de la forma a<b, a>b, a<=b ...
    string id_izq;
    string id_der;

    if(actual->izquierda->valor->es_constante){
        //como una constante no puede ser un identificador, su valor en tasa_crecimiento sera 0 i.e. costante
        id_izq = to_string((long long int)actual->izquierda->valor->valor_numerico);
    }else{
        id_izq = actual->izquierda->valor->identificador;
    }

    if(actual->derecha->valor->es_constante){
        //como una constante no puede ser un identificador, su valor en tasa_crecimiento sera 0 i.e. costante
        id_der = to_string((long long int)actual->derecha->valor->valor_numerico);
    }else{
        id_der = actual->derecha->valor->identificador;
    }

    //too much nesting!!!!!!
    //<
    if(actual->es_conector == -1){
        if(tasa_crecimiento_variable[anidamiento_actual][id_izq] == 2 || tasa_crecimiento_variable[anidamiento_actual][id_der] == 2){
            actual->es_logaritmica = true;
            actual->complejidad = crea_o_logaritmica(id_der);
        }else{
            actual->complejidad = crea_o_lineal(id_der);
        }
    }
    //>,==
    if( actual->es_conector == 1 || actual->es_conector == 0){
        if(tasa_crecimiento_variable[anidamiento_actual][id_izq] == 2 || tasa_crecimiento_variable[anidamiento_actual][id_der] == 2){
            actual->es_logaritmica = true;
            actual->complejidad = crea_o_logaritmica(id_izq);
        }else{
            actual->complejidad = crea_o_lineal(id_izq);
        }
    }

    return complejidad;
}
cl_complejidad cl_analizador::analizar(cl_declaracion* actual){
    tipado_de_variable[actual->identificador] = *(actual->tipo);
    //cout<<actual->identificador<<"  =  "<<actual->tipo->tipo<<endl;
    cl_complejidad complejidad;
    
    if(actual->inicializada){
        complejidad = complejidad + analizar(actual->valor_predeterminado);
    }
    return complejidad;
}




cl_complejidad cl_analizador::analizar(cl_declaracion_funcion* actual){
    tipado_de_variable.clear();
    tasa_crecimiento_variable.clear();
    
    cl_complejidad complejidad;
    cl_bloque_codigo* bloque_codigo = actual->bloque_codigo;
    //La complejidad de una funcion es igual a la suma de las instrucciones en su definicion
    complejidad = complejidad + analizar(bloque_codigo);


    complejidad_funcion[actual->identificador] = complejidad;
    return complejidad;
}


cl_complejidad cl_analizador::analizar_recursiva(cl_declaracion_funcion* actual){
    tipado_de_variable.clear();
    tasa_crecimiento_variable.clear();
    complejidad_funcion[actual->identificador] = crea_o_constante();
    
    cl_complejidad complejidad;
    cl_bloque_codigo* bloque_codigo = actual->bloque_codigo;
    //La complejidad de una funcion es igual a la suma de las instrucciones en su definicion
    complejidad = complejidad + analizar(bloque_codigo);

    //

    int anidamiento_original = anidamiento_actual;
    anidamiento_actual = -1;
    analizar(retorno_pendientes);
    anidamiento_actual = anidamiento_original;

    complejidad = complejidad * retorno_pendientes->complejidad;

    complejidad_funcion[actual->identificador] = complejidad;
    return complejidad;
}






//asume que no esta contenida
cl_complejidad cl_analizador::obtener_complejidad(cl_llamada_funcion* llamada){
    string identificador_funcion = llamada->identificador;
    cl_complejidad complejidad;

    complejidad = complejidad_funcion[identificador_funcion];
    
    string identificador_generico;
    string identificador_final;
    map<string,string> identificadorGenerico_a_identificadorFinal;
    
    if(estaPredefinida(llamada->identificador)){
        identificador_generico = "n";
        identificador_final = llamada->argumentos[0]->identificador;
        identificadorGenerico_a_identificadorFinal[identificador_generico] = identificador_final;
    }else{
        for(cl_sumando& sumando: complejidad.sumandos){
            for(cl_factor& factor: sumando.factores){
                identificador_generico = factor.identificador;
                identificador_final = factor.identificador;
                identificadorGenerico_a_identificadorFinal[identificador_generico] = identificador_final;
            }
        }
        for(int i = 0; i<definiciones[identificador_funcion]->argumentos.size(); i++){
            identificador_generico = definiciones[identificador_funcion]->argumentos[i].identificador;
            //asume que el argumento es un identificador
            identificador_final = llamada->argumentos[i]->identificador;
            identificadorGenerico_a_identificadorFinal[identificador_generico] = identificador_final;
        }
    }
    
    
    for(cl_sumando& sumando: complejidad.sumandos){
        for(cl_factor& factor: sumando.factores){
            if(factor.esConstante()) continue;
            factor.identificador = identificadorGenerico_a_identificadorFinal[factor.identificador];
        }
    }

    //#cout<<"-_- "<<identificador_funcion<<" ";complejidad.imprimir_expresion();
    return complejidad;
}

//asume que esta contenida
//La definicion termino siendo mas caotica de lo necesaria
//todo porque el acceso con [] no es considerado una funcion lol
cl_complejidad cl_analizador::obtener_complejidad(string identificador_funcion,string identificador,cl_tipoDato tipoContenedor){
    string contenedor = tipoContenedor.tipo;
    //#cout<<contenedor<<" "<<identificador<<" ";
    cl_complejidad complejidad;

    complejidad = complejidad_funcion_contenida[contenedor][identificador_funcion];
    
    map<string,string> identificadorGenerico_a_identificadorFinal;
    identificadorGenerico_a_identificadorFinal["n"] = identificador;
    
    for(cl_sumando& sumando: complejidad.sumandos){
        for(cl_factor& factor: sumando.factores){
            if(factor.esConstante()) continue;
            factor.identificador = identificadorGenerico_a_identificadorFinal[factor.identificador];
        }
    }

    //#complejidad.imprimir_expresion();

    return complejidad;
}


//ESTA TOMA LA COMPLEJIDAD DE UN BLOQUE ASUMIENDO QUE SOLO AGRUPA CODIGO
//IMPLEMENTAR OTRA COSA PARA BLOQUES DE FORS Y FUNCIONES RECURSIVAS
// LOOOLOLOLOL
cl_complejidad cl_analizador::analizar(cl_bloque_codigo* actual){
    cl_complejidad complejidad;
    
    //declaraciones
    for(cl_declaracion* declaracion_actual: actual->declaraciones){
        complejidad = complejidad + analizar(declaracion_actual); 
    }
    //aritmeticas
    for(cl_expresion_aritmetica* aritmetica_actual: actual->aritmeticas){
        complejidad = complejidad + analizar(aritmetica_actual); 
    }
    //booleanas
    for(cl_expresion_booleana* booleana_actual: actual->booleanas){
        complejidad = complejidad + analizar(booleana_actual); 
    }
    //ciclos
    for(cl_ciclo* ciclo_actual: actual->ciclos){
        complejidad = complejidad + analizar(ciclo_actual); 
    }
    //ifs
    for(cl_if* if_actual: actual->ifs){
        complejidad = complejidad + analizar(if_actual); 
    }
    return complejidad;
}
bool cl_analizador::estaPredefinida(string identificador){
    if(identificador == "cin") return true;
    if(identificador == "cout") return true;
    if(identificador == "swap") return true;
    if(identificador == "min") return true;
    if(identificador == "max") return true;
    if(identificador == "sort") return true;
    if(identificador == "reverse") return true;
    if(identificador == "lower_bound") return true;
    if(identificador == "upper_bound") return true;
    return false;

}
void cl_analizador::inicializador_complejidades_predefinidas(){
    cl_factor ologn(1,1,"n");
    cl_factor on(2,1,"n");

    //O(1)
    cl_complejidad constante;
    //O(logn)
    cl_complejidad logaritmica;
    logaritmica.sumandos[0].factores.pop_back();
    logaritmica.sumandos[0].factores.push_back(ologn);
    //O(n)
    cl_complejidad lineal;
    lineal.sumandos[0].factores.pop_back();
    lineal.sumandos[0].factores.push_back(on);
    //O(nlogn)
    cl_complejidad loglineal;
    loglineal.sumandos[0].factores.pop_back();
    loglineal.sumandos[0].factores.push_back(on);
    loglineal.sumandos[0].factores.push_back(ologn);
    
    
    //no containerazadas
    complejidad_funcion["cin"] = constante;
    complejidad_funcion["cout"] = constante;
    complejidad_funcion["swap"] = constante;
    complejidad_funcion["min"] = constante;
    complejidad_funcion["max"] = constante;
    complejidad_funcion["sort"] = loglineal;
    complejidad_funcion["reverse"] = loglineal;
    complejidad_funcion["lower_bound"] = logaritmica;
    complejidad_funcion["upper_bound"] = logaritmica;

    //VECTOR
    complejidad_funcion_contenida["vector"]["push_back"] = constante;
    complejidad_funcion_contenida["vector"]["pop_back"] = constante;
    complejidad_funcion_contenida["vector"]["size"] = constante;
    complejidad_funcion_contenida["vector"]["[]"] = constante;
    complejidad_funcion_contenida["vector"]["front"] = constante;
    complejidad_funcion_contenida["vector"]["back"] = constante;
    complejidad_funcion_contenida["vector"]["clear"] = lineal;
    complejidad_funcion_contenida["vector"]["shrink_to_fit"] = lineal;
    complejidad_funcion_contenida["vector"]["at"] = constante;
    
    //STRING
    complejidad_funcion_contenida["string"]["push_back"] = constante;
    complejidad_funcion_contenida["string"]["pop_back"] = constante;
    complejidad_funcion_contenida["string"]["size"] = constante;
    complejidad_funcion_contenida["string"]["[]"] = constante;
    complejidad_funcion_contenida["string"]["front"] = constante;
    complejidad_funcion_contenida["string"]["back"] = constante;
    complejidad_funcion_contenida["string"]["clear"] = lineal;
    complejidad_funcion_contenida["string"]["shrink_to_fit"] = lineal;
    complejidad_funcion_contenida["string"]["at"] = constante;

    //map
    complejidad_funcion_contenida["map"]["insert"] = logaritmica;
    complejidad_funcion_contenida["map"]["clear"] = loglineal;
    complejidad_funcion_contenida["map"]["[]"] = logaritmica;

    //unordered_map
    complejidad_funcion_contenida["unordered_map"]["insert"] = logaritmica;
    complejidad_funcion_contenida["unordered_map"]["clear"] = loglineal;
    complejidad_funcion_contenida["unordered_map"]["[]"] = logaritmica;

    //set
    complejidad_funcion_contenida["set"]["insert"] = logaritmica;
    complejidad_funcion_contenida["set"]["erase"] = logaritmica;
    complejidad_funcion_contenida["set"]["size"] =  constante;
    complejidad_funcion_contenida["set"]["clear"] = loglineal;
    complejidad_funcion_contenida["set"]["lower_bound"] = logaritmica;
    complejidad_funcion_contenida["set"]["upper_bound"] = logaritmica;
    complejidad_funcion_contenida["set"]["find"] = logaritmica;
    complejidad_funcion_contenida["set"]["count"] = logaritmica;

    //multiset
    complejidad_funcion_contenida["multiset"]["insert"] = logaritmica;
    complejidad_funcion_contenida["multiset"]["erase"] = logaritmica;
    complejidad_funcion_contenida["multiset"]["size"] =  constante;
    complejidad_funcion_contenida["multiset"]["clear"] = loglineal;
    complejidad_funcion_contenida["multiset"]["lower_bound"] = logaritmica;
    complejidad_funcion_contenida["multiset"]["upper_bound"] = logaritmica;
    complejidad_funcion_contenida["multiset"]["find"] = logaritmica;
    complejidad_funcion_contenida["multiset"]["count"] = lineal;

    //queue
    complejidad_funcion_contenida["queue"]["size"] = constante;
    complejidad_funcion_contenida["queue"]["push"] = constante;
    complejidad_funcion_contenida["queue"]["pop"] =  constante;
    complejidad_funcion_contenida["queue"]["front"] = constante;
    complejidad_funcion_contenida["queue"]["back"] = constante;
    //stack
    complejidad_funcion_contenida["queue"]["size"] = constante;
    complejidad_funcion_contenida["queue"]["push"] = constante;
    complejidad_funcion_contenida["queue"]["pop"] =  constante;
    complejidad_funcion_contenida["queue"]["top"] = constante;


    //primitivos
    complejidad_funcion_contenida["bool"]["[]"] = constante;
    complejidad_funcion_contenida["char"]["[]"] = constante;
    complejidad_funcion_contenida["float"]["[]"] = constante;
    complejidad_funcion_contenida["short int"]["[]"] = constante;
    complejidad_funcion_contenida["long long int"]["[]"] = constante;
    complejidad_funcion_contenida["long int"]["[]"] = constante;
    complejidad_funcion_contenida["int"]["[]"] = constante;
    complejidad_funcion_contenida["double"]["[]"] = constante;
}   


void pionero(){
    cout<<":DDDDDDDD"<<endl;
}