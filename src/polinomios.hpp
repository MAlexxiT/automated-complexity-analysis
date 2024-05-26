#include "bits/stdc++.h"
using namespace std;

#define CONSTANTE "__CONSTANTE__"
class cl_factor{
private: 
    //0 = constante, 1 = log(id)^exp, 2 = id^exp
    int tipo;
    double exponente;
public:
    bool usado;
    std::string identificador;
    //TIPO: 0 = constante, 1 = log_{2}{id}**exp, 2 = id**exp
    //en caso de tipo==0, pasar cualquier cosa en los demas argumentos, pues los demas metodos los ignoraran
    cl_factor(int tipo, int exponente, std::string identificador){
        this->tipo = tipo;
        this->exponente = exponente;
        this->identificador = identificador;
        this->usado = false;
    }
    //METODOS DE ACCESO
    double obtenerExponente(){
        return this->exponente;
    }
    string obtenerIdentificador(){
        return this->identificador;
    }
    int obtenerTipo(){
        return this->tipo;
    }
    //cuentan como metodos de acceso
    //pero decidi abstraer el valor del tipo en algo mas representativo por medio de los nombres de los metodos
    bool esConstante(){
        return (this->tipo == 0);
    }       
    bool esLogaritmico(){
        return (this->tipo == 1);
    }       
    bool esPotencial(){
        return (this->tipo == 2);
    }   
    //EL RESTO    
    bool multiplicables(cl_factor otro){
        //Un factor constante cuenta como termino semejante de cualquier otro factor
        if(this->esConstante()||otro.esConstante()){
            return true;
        }
        if(this->obtenerIdentificador() != otro.obtenerIdentificador()){
            return false;
        }
        if(this->obtenerTipo() != otro.obtenerTipo()){
            return false;
        }
        return true;
    }
    bool operator==(cl_factor otro){
        if(this->esConstante() && otro.esConstante()){
            return true;
        }
        if(this->obtenerIdentificador() != otro.obtenerIdentificador()){
            return false;
        }
        if(this->obtenerExponente() != otro.obtenerExponente()){
            return false;
        }
        if(this->obtenerTipo() != otro.obtenerTipo()){
            return false;
        }
        return true;
    }
    bool operator!=(cl_factor otro){
        return !((*this) == otro);
    }
    cl_factor operator*(cl_factor otro){
        assert(("Dos factores que se multiplican deben de ser similares",this->multiplicables(otro)));
        
        int tipo_resultante = max(this->obtenerTipo(), otro.obtenerTipo());
        int exponente_resultante =this->obtenerExponente()+otro.obtenerExponente(); 
        string nuevo_identificador = this->obtenerIdentificador();
        if(nuevo_identificador == CONSTANTE){
            nuevo_identificador = otro.obtenerIdentificador();
        }
        cl_factor resultado(tipo_resultante,exponente_resultante,nuevo_identificador);

        return resultado;
    }

    bool operator<(cl_factor otro){
        if(this->obtenerTipo() != otro.obtenerTipo()){
            return this->obtenerTipo() > otro.obtenerTipo();
        }
        if(this->obtenerIdentificador()!=otro.obtenerIdentificador()){
            return this->obtenerIdentificador() > otro.obtenerIdentificador();
        }
        return this->obtenerExponente()>otro.obtenerExponente();
    }
    
};
class cl_sumando{
public:
    bool tieneFactor(cl_factor factor_objetivo){
        if(factor_objetivo.esConstante()){
            return true;
        }
        for(cl_factor factor: factores){
            if(factor_objetivo.obtenerTipo()==factor.obtenerTipo() && factor_objetivo.identificador == factor.identificador && factor.obtenerExponente()>=factor_objetivo.obtenerExponente()){
                return true;
            }
        }
        return false;
    }
    vector<cl_factor> factores;
    bool duplicado;
    cl_sumando(){
        this->duplicado = false;
    }
    cl_sumando operator*(cl_sumando otro){
        cl_sumando resultado;
        bool encontrado;
        for(cl_factor fac_propio: factores){
            encontrado = false;
            for(cl_factor& fac_otro: otro.factores){
                if(fac_propio.multiplicables(fac_otro)){
                    resultado.factores.push_back(fac_propio*fac_otro);
                    
                    encontrado = true;
                    fac_otro.usado = true;
                    break;
                }
            }
            if(!encontrado){
                resultado.factores.push_back(fac_propio);
            }
        }
        for(cl_factor& factor: otro.factores){
            if(!factor.usado){
                resultado.factores.push_back(factor);
            }
        }
        return resultado;
    }
    bool operator==(cl_sumando otro){
        sort(factores.begin(),factores.end());
        sort(otro.factores.begin(),otro.factores.end());
        
        //ignora factores constantes que podrian estar al final del vector
        for(int i = 0; i<min(factores.size(),otro.factores.size()); i++){
            if(!(factores[i] == otro.factores[i])){
                return false;
            }
        }
        
        for(int i = factores.size(); i<otro.factores.size(); i++){
            if(otro.factores[i].esConstante() == false){
                return false;
            }
        }
        for(int i = otro.factores.size(); i<factores.size(); i++){
            if(factores[i].esConstante() == false){
                return false;
            }
        }
        return true;
    }
};
class cl_complejidad{
    void eliminar_terminos_semejantes(){
        vector<cl_sumando> copia_sumandos = sumandos;
        
        for(int i = 1; i<copia_sumandos.size(); i++){
            for(int j = 0; j<i; j++){
                if(copia_sumandos[i] == copia_sumandos[j]){
                    copia_sumandos[j].duplicado = true;
                }
            }
        }

        sumandos.clear();
        for(cl_sumando s: copia_sumandos){
            if(s.duplicado == false){
                sumandos.push_back(s);
            }
        }

        copia_sumandos.clear();
        copia_sumandos = sumandos;
        bool lo_contiene;
        for(int i = 0; i<copia_sumandos.size(); i++){
            for(int j = 0; j<copia_sumandos.size(); j++){
                if(i==j){
                    continue;
                }
                lo_contiene = true;
                for(cl_factor factor: copia_sumandos[j].factores){
                    lo_contiene = (lo_contiene&&copia_sumandos[i].tieneFactor(factor));
                }
                if(lo_contiene){
                    copia_sumandos[j].duplicado = true;
                }
            }
        }

        sumandos.clear();
        for(cl_sumando s: copia_sumandos){
            if(s.duplicado == false){
                sumandos.push_back(s);
            }
        }
    }
public:
    vector<cl_sumando> sumandos;
    //una complejidad siempre tiene por lo menos un factor constante
    cl_complejidad(){
        cl_sumando s;
        cl_factor f(0,0,CONSTANTE);
        s.factores.push_back(f);
        sumandos.push_back(s);
    }
    cl_complejidad operator*(cl_complejidad otro){
        cl_complejidad respuesta;
        for(cl_sumando propio_sumando: sumandos){
            for(cl_sumando otro_sumando: otro.sumandos){
                respuesta.sumandos.push_back(propio_sumando*otro_sumando);
            }    
        }

        respuesta.eliminar_terminos_semejantes();

        return respuesta;
    }

    cl_complejidad operator+(cl_complejidad otro){
        cl_complejidad respuesta;
        for(cl_sumando propio_sumando: sumandos){
            respuesta.sumandos.push_back(propio_sumando);
            
        }
        for(cl_sumando otro_sumando: otro.sumandos){
            respuesta.sumandos.push_back(otro_sumando);
        }   
        
        respuesta.eliminar_terminos_semejantes();

        return respuesta;
    }

    void imprimir_expresion(){  
        bool primero = true;
        bool primer_factor;

        cout<<"O( ";

        for(cl_sumando sumando: sumandos){
            if(!primero){
                cout<<" + ";
            }
            primero = false;
            primer_factor = true;
            for(cl_factor factor: sumando.factores){
                if(!primer_factor){
                    cout<<"*";
                }
                primer_factor = false;
                if(factor.identificador == CONSTANTE){
                    cout<<"1";
                }else{
                    if(factor.esLogaritmico()){
                        cout<<"log(";
                    }
                    cout<<factor.identificador;
                    if(factor.esLogaritmico()){
                        cout<<")";
                    }
                    if(factor.obtenerExponente()>1){
                        cout<<"^"<<factor.obtenerExponente()<<" ";
                    }
                }
                
            }   
        }

        cout<<" )"<<endl;
    }
};


