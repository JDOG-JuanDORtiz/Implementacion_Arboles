#include "ArbolAVL.h"
#include <iostream>


template<class T>
ArbolAVL<T>::ArbolAVL(){
    this->raiz = nullptr;
}

template<class T>
ArbolAVL<T>::ArbolAVL(T val){
    NodoAVL<T>* nraiz = new NodoAVL<T>;
    this->raiz = nraiz;
}

template<class T>
ArbolAVL<T>::~ArbolAVL(){
    if (this->raiz != nullptr){
        delete this->raiz;
        this->raiz = nullptr;
    }
}

template<class T>
bool ArbolAVL<T>::esVacio(){
    return this->raiz == nullptr;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::obtenerRaiz(){
    return this->raiz;
}

template<class T>
T ArbolAVL<T>::datoRaiz(){
    if(this->raiz!=nullptr)
        return (this->raiz)->obtenerDato();
    return nullptr;
}

template<class T>
void ArbolAVL<T>::fijarRaiz(NodoAVL<T>* nraiz){
    this->raiz=nraiz;
}

template<class T>
int ArbolAVL<T>::altura(){
    if(this->esVacio())
        return -1;
    return this->altura(this->raiz);
}

template<class T>
int ArbolAVL<T>::altura(NodoAVL<T>* nodo){
    if(nodo->esHoja()){
        return 0;
    }
    int alturaSubIzq;
    int alturaSubDer;
    if(nodo->obtenerHijoIzq()!=nullptr)
        alturaSubIzq = this->altura(nodo->obtenerHijoIzq());
    else
        alturaSubIzq = -1;

    if(nodo->obtenerHijoDer()!=nullptr)
        alturaSubDer = this->altura(nodo->obtenerHijoDer());
    else
        alturaSubDer = -1;
    
    if(alturaSubIzq > alturaSubDer)
        return alturaSubIzq + 1;
    else
        return alturaSubDer + 1;
}

template<class T>
bool ArbolAVL<T>::insertarNodo(T n){
    if(this->esVacio()){
        NodoAVL<T>* nuevoNodo = new NodoAVL<T>(n);
        this->raiz=nuevoNodo;
        return true;
    }
    std::stack< NodoAVL<T>* > camino;
    NodoAVL<T>* nodo = this->raiz;
    NodoAVL<T>* padre= this->raiz;
    bool insertado = false;
    bool duplicado = false;

    while(nodo != nullptr){
        padre = nodo;
        camino.push(nodo);
        if(n < nodo->obtenerDato()){
            nodo = nodo->obtenerHijoIzq();
        }else if ( n > nodo->obtenerDato()){
            nodo = nodo->obtenerHijoDer();
        }else{
            duplicado = true;
            break;
        }
    }
    
    if(!duplicado){
        NodoAVL<T>* nuevoNodo = new NodoAVL<T>(n);
        if(nuevoNodo != nullptr){
            if(n < padre->obtenerDato())
            {
                padre->fijarHijoIzq(nuevoNodo);
            }
            else{
                padre->fijarHijoDer(nuevoNodo);
            }
            insertado = true;
        }
        while(!camino.empty()){
            NodoAVL<T>* nodoEvaluado = camino.top(); 
            camino.pop();
            std::cout<<"\nCamino"<<nodoEvaluado->obtenerDato()<<" ";
            int hijoIzq, hijoDer, nietoIzq, nietoDer;
            if(nodoEvaluado->obtenerHijoIzq()!=nullptr)
                hijoIzq=altura(nodoEvaluado->obtenerHijoIzq())+1;
            else
                hijoIzq=0;
            if(nodoEvaluado->obtenerHijoDer()!=nullptr)
                hijoDer=altura(nodoEvaluado->obtenerHijoDer())+1;
            else
                hijoDer=0;
            std::cout<<"\tAlt izq: "<<hijoIzq<<"\tAlt der: "<<hijoDer;

            if((hijoIzq-hijoDer)==2){
                std::cout<<"\nArbol izquierdo mas grande: ";
                if(nodoEvaluado->obtenerHijoIzq()->obtenerHijoIzq()!=nullptr)
                    nietoIzq=altura(nodoEvaluado->obtenerHijoIzq()->obtenerHijoIzq())+1;
                else
                    nietoIzq=0;
                if(nodoEvaluado->obtenerHijoIzq()->obtenerHijoDer()!=nullptr)
                    nietoDer=altura(nodoEvaluado->obtenerHijoIzq()->obtenerHijoDer())+1;
                else
                    nietoDer=0;
                std::cout<<"\tAlt nieto izq: "<<nietoIzq<<"\tAlt nieto der: "<<nietoDer;
                if(nietoIzq-nietoDer>0){
                    if(nodoEvaluado->obtenerDato() == this->raiz->obtenerDato())
                        this->fijarRaiz(this->giroDerecha(nodoEvaluado));
                    else
                        camino.top()->fijarHijoIzq(this->giroDerecha(nodoEvaluado));
                }
                else{
                    if(nodoEvaluado->obtenerDato() == this->raiz->obtenerDato())
                        this->fijarRaiz(this->giroIzquierdaDerecha(nodoEvaluado));
                    else
                        camino.top()->fijarHijoIzq(this->giroIzquierdaDerecha(nodoEvaluado));
                }
            }
            else if((hijoIzq-hijoDer)==-2){
                std::cout<<"\nArbol Derecho mas grande: ";
                if(nodoEvaluado->obtenerHijoDer()->obtenerHijoIzq()!=nullptr)
                    nietoIzq=altura(nodoEvaluado->obtenerHijoDer()->obtenerHijoIzq())+1;
                else
                    nietoIzq=0;
                if(nodoEvaluado->obtenerHijoDer()->obtenerHijoDer()!=nullptr)
                    nietoDer=altura(nodoEvaluado->obtenerHijoDer()->obtenerHijoDer())+1;
                else
                    nietoDer=0;
                std::cout<<"\tAlt nieto izq: "<<nietoIzq<<"\tAlt nieto der: "<<nietoDer;
                if((nietoIzq-nietoDer)<0){
                    if(nodoEvaluado->obtenerDato() == this->raiz->obtenerDato())
                        this->fijarRaiz(this->giroIzquierda(nodoEvaluado));
                    else
                        camino.top()->fijarHijoDer(this->giroIzquierda(nodoEvaluado));
                }
                else{
                    if(nodoEvaluado->obtenerDato() == this->raiz->obtenerDato())
                        this->fijarRaiz(this->giroDerechaIzquierda(nodoEvaluado));
                    else
                        camino.top()->fijarHijoDer(this->giroDerechaIzquierda(nodoEvaluado));
                }
            }
        }
        std::cout<<"\nNueva raiz: "<<this->raiz->obtenerDato();
    }

    return insertado; 
}

template<class T>
bool ArbolAVL<T>::eliminarNodo(T n){
    if(this->esVacio())
        return false;
    NodoAVL<T> *nodo = this->raiz, *padre= this->raiz;
    bool eliminado = false;
    bool encontrado = false;

    while(nodo != nullptr && !encontrado){
        if(n < nodo->obtenerDato()){
            padre = nodo;
            nodo = nodo->obtenerHijoIzq();
        }
        else if ( n > nodo->obtenerDato()){
            padre = nodo;
            nodo = nodo->obtenerHijoDer();
        }
        else
            encontrado = true;
    }
    if(encontrado){
        //Caso: esHoja
        if(nodo->esHoja()){
            if(n < padre->obtenerDato())
            {
                padre->fijarHijoIzq(nullptr);
            }
            else{
                padre->fijarHijoDer(nullptr);
            }
        }

        //Caso: Tiene un hijo
        else if(nodo->obtenerHijoDer()==nullptr && nodo->obtenerHijoIzq()!=nullptr){
            if(n == raiz->obtenerDato()){
                this->raiz=nodo->obtenerHijoIzq();
            }
            else if(n < padre->obtenerDato())
            {
                padre->fijarHijoIzq(nodo->obtenerHijoIzq());
            }
            else{
                padre->fijarHijoDer(nodo->obtenerHijoIzq());
            }
        }
        else if(nodo->obtenerHijoDer()!=nullptr && nodo->obtenerHijoIzq()==nullptr){
            if(n == raiz->obtenerDato()){
                this->raiz=nodo->obtenerHijoDer();
            }
            else if(n < padre->obtenerDato())
            {
                padre->fijarHijoIzq(nodo->obtenerHijoDer());
            }
            else{
                padre->fijarHijoDer(nodo->obtenerHijoDer());
            }
        }

        //Caso: Tienen dos hijos
        else if(nodo->obtenerHijoDer()!=nullptr && nodo->obtenerHijoIzq()!=nullptr){
            NodoAVL<T>* mayorSubIzq=nodo->obtenerHijoIzq();
            NodoAVL<T>* padreMayor=nodo;
            NodoAVL<T>* izq;
            while(mayorSubIzq->obtenerHijoDer()!=nullptr){
                padreMayor=mayorSubIzq;
                mayorSubIzq = mayorSubIzq->obtenerHijoDer();
            }
            mayorSubIzq->fijarHijoDer(nodo->obtenerHijoDer());
            padreMayor->fijarHijoDer(mayorSubIzq->obtenerHijoIzq());
            if(padreMayor->obtenerDato()==nodo->obtenerDato()){
                padreMayor->fijarHijoIzq(nullptr);
                izq=mayorSubIzq->obtenerHijoIzq();
            }
            mayorSubIzq->fijarHijoIzq(nodo->obtenerHijoIzq());
            if(padreMayor->obtenerDato()==nodo->obtenerDato()){
                mayorSubIzq->fijarHijoIzq(izq);
            }
            if(n == raiz->obtenerDato()){
                this->raiz=mayorSubIzq;
            }
            else if(n < padre->obtenerDato())
            {
                padre->fijarHijoIzq(mayorSubIzq);
            }
            else{
                padre->fijarHijoDer(mayorSubIzq);
            }
        }
        delete nodo;
        eliminado = true;
    }

    return eliminado; 
}

template<class T>
bool ArbolAVL<T>::buscar(T n){
    if(this->esVacio())
        return false;
    NodoAVL<T>* nodo = this->raiz;
    bool encontrado = false;
    
    while(nodo != nullptr && !encontrado){
        if(n < nodo->obtenerDato())
            nodo = nodo->obtenerHijoIzq();
        else if ( n > nodo->obtenerDato())
            nodo = nodo->obtenerHijoDer();
        else
            encontrado = true;
    }

    return encontrado;
}

template<class T>
unsigned int ArbolAVL<T>::tamano(){
    if(this->esVacio())
		return 0;
	return tamano(raiz);
}

template<class T>
unsigned int ArbolAVL<T>::tamano(NodoAVL<T>* nodo){
    if(nodo->esHoja()){
		return 1;
	}
    unsigned int tamanoArbol=0;
    if(nodo->obtenerHijoIzq()!=nullptr)
        tamanoArbol+=tamano(nodo->obtenerHijoIzq());
    if(nodo->obtenerHijoDer()!=nullptr)
        tamanoArbol+=tamano(nodo->obtenerHijoDer());
    return tamanoArbol+1;
}

template<class T>
void ArbolAVL<T>::preOrden(){
    if(!this->esVacio())
        this->preOrden(this->raiz);
}

template<class T>
void ArbolAVL<T>::preOrden(NodoAVL<T>* nodo){
    std::cout<<nodo->obtenerDato()<<" ";
    if(nodo->obtenerHijoIzq()!=nullptr)
        this->preOrden(nodo->obtenerHijoIzq());
    if(nodo->obtenerHijoDer()!=nullptr)
        this->preOrden(nodo->obtenerHijoDer());
}

template<class T>
void ArbolAVL<T>::posOrden(){
    if(!this->esVacio())
        this->posOrden(this->raiz);
}

template<class T>
void ArbolAVL<T>::posOrden(NodoAVL<T>* nodo){
    if(nodo->obtenerHijoIzq()!=nullptr)
        this->posOrden(nodo->obtenerHijoIzq());
    if(nodo->obtenerHijoDer()!=nullptr)
        this->posOrden(nodo->obtenerHijoDer());
    std::cout<<nodo->obtenerDato()<<" ";
}

template<class T>
void ArbolAVL<T>::nivelesOrden(){
    if (!this->esVacio())
    {
        std::queue< NodoAVL<T>* > cola;
        NodoAVL<T>* nodoVisitado;
        cola.push(this->raiz);
        while(!cola.empty()){
            nodoVisitado = cola.front();
            cola.pop();
            std::cout<<nodoVisitado->obtenerDato()<<" ";
            if(nodoVisitado->obtenerHijoIzq()!=nullptr)
                cola.push(nodoVisitado->obtenerHijoIzq());
            if(nodoVisitado->obtenerHijoDer()!=nullptr)
                cola.push(nodoVisitado->obtenerHijoDer());
        }
    }
}
        
        
template<class T>
void ArbolAVL<T>::inOrden(){
    if(!this->esVacio())
        this->inOrden(this->raiz);
}

template<class T>
void ArbolAVL<T>::inOrden(NodoAVL<T>* nodo){
    if(nodo->obtenerHijoIzq()!=nullptr)
        this->inOrden(nodo->obtenerHijoIzq());
    std::cout<<nodo->obtenerDato()<<" ";
    if(nodo->obtenerHijoDer()!=nullptr)
        this->inOrden(nodo->obtenerHijoDer());
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::giroDerecha(NodoAVL<T>* n2){
    NodoAVL<T>* n_padre = n2->obtenerHijoIzq();
    n2->fijarHijoIzq(n_padre->obtenerHijoDer());
    n_padre->fijarHijoDer(n2);
    return n_padre;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::giroDerechaIzquierda(NodoAVL<T>* n1){
    NodoAVL<T> *n_padre, *aux;
    aux = this->giroDerecha(n1->obtenerHijoDer());
    n1->fijarHijoDer(aux);
    n_padre = this->giroIzquierda(n1);
    return n_padre;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::giroIzquierda(NodoAVL<T>* n1){
    NodoAVL<T>* n_padre = n1->obtenerHijoDer();
    n1->fijarHijoDer(n_padre->obtenerHijoIzq());
    n_padre->fijarHijoIzq(n1);
    return n_padre;
}

template<class T>
NodoAVL<T>* ArbolAVL<T>::giroIzquierdaDerecha(NodoAVL<T>* n1){
    NodoAVL<T> *n_padre, *aux;
    aux = this->giroIzquierda(n1->obtenerHijoIzq());
    n1->fijarHijoIzq(aux);
    n_padre = this->giroDerecha(n1);
    return n_padre;
}