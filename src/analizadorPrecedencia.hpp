class analizador_precedencia{
private:
    cl_raiz* raiz;
    map<string,cl_declaracion_funcion*> direccion_de_llamada;
    map<string,bool> esta_predefinida;
    vector<int> call_stack;
    map<int,bool> on_stack;
    
    string funcion_actual;
    map<string,bool> es_recursiva;
    int SINVISITAR;
    int id_disponible;
    void dfs(cl_declaracion_funcion* actual);
    void dfs(cl_if* actual);
    void dfs(cl_ciclo* actual);
    void dfs(cl_declaracion* actual);
    void dfs(cl_expresion_booleana* actual);
    void dfs(cl_expresion_aritmetica* actual);
    int explorar_bloque(cl_bloque_codigo* bloque_codigo, int low_link_value);
public:
    analizador_precedencia(cl_raiz* raiz);
    vector<cl_declaracion_funcion*> orden_topologico;
    bool esRecursivo();
};  

analizador_precedencia::analizador_precedencia(cl_raiz* raiz){
    this->raiz = raiz;
    SINVISITAR = 0;
    id_disponible = 1;
    for(int i = 0; i<this->raiz->funciones_declaradas.size(); i++){
        direccion_de_llamada[this->raiz->funciones_declaradas[i]->identificador] = this->raiz->funciones_declaradas[i];
    }
    esta_predefinida["cin"] = true;
    esta_predefinida["cout"] = true;
    esta_predefinida["reverse"] = true;
    esta_predefinida["sort"] = true;
    esta_predefinida["min"] = true;
    esta_predefinida["max"] = true;
    esta_predefinida["swap"] = true;
    esta_predefinida["upper_bound"] = true;
    esta_predefinida["lower_bound"] = true;
    
}
//Esta funcion es llamada una sola vez
bool analizador_precedencia::esRecursivo(){
    bool respuesta = false;
    for(int i = 0; i<raiz->funciones_declaradas.size(); i++){
        if(raiz->funciones_declaradas[i]->scc_id == SINVISITAR ) dfs(raiz->funciones_declaradas[i]);
        if(raiz->funciones_declaradas[i]->scc_id != raiz->funciones_declaradas[i]->low_link_value) respuesta = false;
        if(es_recursiva[raiz->funciones_declaradas[i]->identificador]){
            raiz->funciones_declaradas[i]->es_recursiva = true;
        }
    }

    //al arreglo de declaraciones en postorden, basta con invertirlo para convertirlo en el orden topologico
    //el primer elemento del orden topologico es el primer elemento sin dependencias, asumiendo que el grafo sea una DAG
    //reverse(orden_topologico.begin(),orden_topologico.end());
    return respuesta;
}


int analizador_precedencia::explorar_bloque(cl_bloque_codigo* bloque_codigo, int low_link_value){
    //aritmeticas
    for(int i = 0; i<bloque_codigo->aritmeticas.size(); i++){
        if(bloque_codigo->aritmeticas[i]->scc_id == SINVISITAR){
            dfs(bloque_codigo->aritmeticas[i]);
        }
        if(on_stack[bloque_codigo->aritmeticas[i]->scc_id]){
            low_link_value = min(low_link_value,bloque_codigo->aritmeticas[i]->low_link_value);
        }
    }
    //booleanas
    for(int i = 0; i<bloque_codigo->booleanas.size(); i++){
        if(bloque_codigo->booleanas[i]->scc_id == SINVISITAR){
            dfs(bloque_codigo->booleanas[i]);
        }
        if(on_stack[bloque_codigo->booleanas[i]->scc_id]){
            low_link_value = min(low_link_value,bloque_codigo->booleanas[i]->low_link_value);
        }
    }
    //declaraciones
    for(int i = 0; i<bloque_codigo->declaraciones.size(); i++){
        if(bloque_codigo->declaraciones[i]->scc_id == SINVISITAR){
            dfs(bloque_codigo->declaraciones[i]);
        }
        if(on_stack[bloque_codigo->declaraciones[i]->scc_id]){
            low_link_value = min(low_link_value,bloque_codigo->declaraciones[i]->low_link_value);
        }
    }
    //ciclos
    for(int i = 0; i<bloque_codigo->ciclos.size(); i++){
        if(bloque_codigo->ciclos[i]->scc_id == SINVISITAR){
            dfs(bloque_codigo->ciclos[i]);
        }
        if(on_stack[bloque_codigo->ciclos[i]->scc_id]){
            low_link_value = min(low_link_value,bloque_codigo->ciclos[i]->low_link_value);
        }
    }
    //ifs
    for(int i = 0; i<bloque_codigo->ifs.size(); i++){
        if(bloque_codigo->ifs[i]->scc_id == SINVISITAR){
            dfs(bloque_codigo->ifs[i]);
        }
        if(on_stack[bloque_codigo->ifs[i]->scc_id]){
            low_link_value = min(low_link_value,bloque_codigo->ifs[i]->low_link_value);
        }
    }
    return low_link_value;
}
void analizador_precedencia::dfs(cl_declaracion_funcion* actual){
    funcion_actual = actual->identificador;
    
    actual->scc_id = id_disponible;
    actual->low_link_value = id_disponible;
    id_disponible++;
    call_stack.push_back(actual->scc_id);
    on_stack[actual->scc_id] = true;


    actual->low_link_value = explorar_bloque(actual->bloque_codigo, actual->low_link_value);


    //si es el primer nodo del ciclo
    if(actual->scc_id==actual->low_link_value){
        while(call_stack.back()!=actual->scc_id){
            on_stack[call_stack.back()] = false; 
            call_stack.pop_back();
        }
        call_stack.pop_back();;
        on_stack[actual->scc_id] = false;
    }
    //Se introducen en postorden las declaraciones de funciones
    orden_topologico.push_back(actual);
}

void analizador_precedencia::dfs(cl_if* actual){
    actual->scc_id = id_disponible;
    actual->low_link_value = id_disponible;
    id_disponible++;
    call_stack.push_back(actual->scc_id);
    on_stack[actual->scc_id] = true;


    actual->low_link_value = explorar_bloque(actual->bloque_if, actual->low_link_value);

    if(actual->tiene_else == true){
        actual->low_link_value = explorar_bloque(actual->bloque_else, actual->low_link_value);
    }
    

    //si es el primer nodo del ciclo
    if(actual->scc_id==actual->low_link_value){
        while(call_stack.back()!=actual->scc_id){
            on_stack[call_stack.back()] = false; 
            call_stack.pop_back();
        }
        call_stack.pop_back();;
        on_stack[actual->scc_id] = false;
    }
}

void analizador_precedencia::dfs(cl_ciclo* actual){
    actual->scc_id = id_disponible;
    actual->low_link_value = id_disponible;
    id_disponible++;
    call_stack.push_back(actual->scc_id);
    on_stack[actual->scc_id] = true;

    actual->low_link_value = explorar_bloque(actual->bloque_codigo, actual->low_link_value);

    //si es el primer nodo del ciclo
    if(actual->scc_id==actual->low_link_value){
        while(call_stack.back()!=actual->scc_id){
            on_stack[call_stack.back()] = false; 
            call_stack.pop_back();
        }
        call_stack.pop_back();;
        on_stack[actual->scc_id] = false;
    }
}

void analizador_precedencia::dfs(cl_declaracion* actual){
    actual->scc_id = id_disponible;
    actual->low_link_value = id_disponible;
    id_disponible++;
    call_stack.push_back(actual->scc_id);
    on_stack[actual->scc_id] = true;

    if(actual->inicializada){
        dfs(actual->valor_predeterminado);
    }

    //si es el primer nodo del ciclo
    if(actual->scc_id==actual->low_link_value){
        while(call_stack.back()!=actual->scc_id){
            on_stack[call_stack.back()] = false; 
            call_stack.pop_back();
        }
        call_stack.pop_back();;
        on_stack[actual->scc_id] = false;
    }
}

void analizador_precedencia::dfs(cl_expresion_booleana* actual){
    actual->scc_id = id_disponible;
    actual->low_link_value = id_disponible;
    id_disponible++;
    call_stack.push_back(actual->scc_id);
    on_stack[actual->scc_id] = true;

    if(actual->es_terminal){
        if(actual->valor->scc_id == SINVISITAR){
            dfs(actual->valor);
        }
        if(on_stack[actual->valor->scc_id]){
            actual->low_link_value = min(actual->low_link_value,actual->valor->low_link_value);
        }
        return;
    }
    //izquierda
    if(actual->izquierda->scc_id == SINVISITAR){
        dfs(actual->izquierda);
    }
    if(on_stack[actual->izquierda->scc_id]){
        actual->low_link_value = min(actual->low_link_value,actual->izquierda->low_link_value);
    }
    //derecha
    if(actual->derecha->scc_id == SINVISITAR){
        dfs(actual->derecha);
    }
    if(on_stack[actual->derecha->scc_id]){
        actual->low_link_value = min(actual->low_link_value,actual->derecha->low_link_value);
    }
    
    //si es el primer nodo del ciclo IMPOSSIBLE
    if(actual->scc_id==actual->low_link_value){
        while(call_stack.back()!=actual->scc_id){
            on_stack[call_stack.back()] = false; 
            call_stack.pop_back();
        }
        call_stack.pop_back();;
        on_stack[actual->scc_id] = false;
    }
}

void analizador_precedencia::dfs(cl_expresion_aritmetica* actual){
    actual->scc_id = id_disponible;
    actual->low_link_value = id_disponible;
    id_disponible++;
    call_stack.push_back(actual->scc_id);
    on_stack[actual->scc_id] = true;

    if(actual->es_llamada_funcion){
        if(actual->llamada_val->identificador == funcion_actual){
            es_recursiva[funcion_actual] = true;
        }
        if(esta_predefinida[actual->llamada_val->identificador] == true || actual->llamada_val->esta_contenida){
            if(actual->scc_id==actual->low_link_value){
                while(call_stack.back()!=actual->scc_id){
                    on_stack[call_stack.back()] = false; 
                    call_stack.pop_back();
                }
                call_stack.pop_back();;
                on_stack[actual->scc_id] = false;
            }
            return;
        }
        string nombre = actual->llamada_val->identificador;;
        cl_declaracion_funcion* direccion_declaracion = direccion_de_llamada[nombre];
        if(direccion_declaracion->scc_id == SINVISITAR){
            dfs(direccion_declaracion);
        }
        if(on_stack[direccion_declaracion->scc_id]){
            actual->low_link_value = min(actual->low_link_value,direccion_declaracion->low_link_value);
        }
        return;
    }
    if(actual->es_terminal == true){
        //si es el primer nodo del ciclo IMPOSSIBLE
        if(actual->scc_id==actual->low_link_value){
            while(call_stack.back()!=actual->scc_id){
                on_stack[call_stack.back()] = false; 
                call_stack.pop_back();
            }
            call_stack.pop_back();;
            on_stack[actual->scc_id] = false;
        }
        return;
    }  

    //izquierda
    if(actual->izquierda->scc_id == SINVISITAR){
        dfs(actual->izquierda);
    }
    if(on_stack[actual->izquierda->scc_id]){
        actual->low_link_value = min(actual->low_link_value,actual->izquierda->low_link_value);
    }

    
    //derecha
    if(actual->derecha->scc_id == SINVISITAR){
        dfs(actual->derecha);
    }
    if(on_stack[actual->derecha->scc_id]){
        actual->low_link_value = min(actual->low_link_value,actual->derecha->low_link_value);
    }
    
    //si es el primer nodo del ciclo IMPOSSIBLE
    if(actual->scc_id==actual->low_link_value){
        while(call_stack.back()!=actual->scc_id){
            on_stack[call_stack.back()] = false; 
            call_stack.pop_back();
        }
        call_stack.pop_back();;
        on_stack[actual->scc_id] = false;
    }
}