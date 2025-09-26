#include "ArbolBinarioOrd.h"
#include <iostream>


template<class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(){
    this->raiz = nullptr;
}

template<class T>
ArbolBinarioOrd<T>::ArbolBinarioOrd(T val){
    NodoBinario<T>* nraiz = new NodoBinario<T>;
    this->raiz = nraiz;
}

template<class T>
ArbolBinarioOrd<T>::~ArbolBinarioOrd(){
    if (this->raiz != nullptr){
        delete this->raiz;
        this->raiz = nullptr;
    }
}

template<class T>
bool ArbolBinarioOrd<T>::esVacio(){
    return this->raiz == nullptr;
}

template<class T>
NodoBinario<T>* ArbolBinarioOrd<T>::obtenerRaiz(){
    return this->raiz;
}

template<class T>
T ArbolBinarioOrd<T>::datoRaiz(){
    if(this->raiz!=nullptr)
        return (this->raiz)->obtenerDato();
    return nullptr;
}

template<class T>
int ArbolBinarioOrd<T>::altura(){
    if(this->esVacio())
        return -1;
    return this->altura(this->raiz);
}

template<class T>
int ArbolBinarioOrd<T>::altura(NodoBinario<T>* nodo){
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
bool ArbolBinarioOrd<T>::insertarNodo(T n){
    if(this->esVacio()){
        NodoBinario<T>* nuevoNodo = new NodoBinario<T>(n);
        this->raiz=nuevoNodo;
        return true;
    }
    NodoBinario<T>* nodo = this->raiz;
    NodoBinario<T>* padre= this->raiz;
    bool insertado = false;
    bool duplicado = false;

    while(nodo != nullptr){
        padre = nodo;
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
        NodoBinario<T>* nuevoNodo = new NodoBinario<T>(n);
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
    }

    return insertado; 
}

template<class T>
bool ArbolBinarioOrd<T>::eliminarNodo(T n){
    if(this->esVacio())
        return false;
    NodoBinario<T> *nodo = this->raiz, *padre= this->raiz;
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
        else if(nodo->obtenerHijoDer()!=nullptr && nodo->obtenerHijoIzq()){
            NodoBinario<T>* mayorSubIzq=nodo->obtenerHijoIzq();
            NodoBinario<T>* padreMayor=nodo;
            NodoBinario<T>* izq;
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
bool ArbolBinarioOrd<T>::buscar(T n){
    if(this->esVacio())
        return false;
    NodoBinario<T>* nodo = this->raiz;
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
unsigned int ArbolBinarioOrd<T>::tamano(){
    if(this->esVacio())
		return 0;
	return tamano(raiz);
}

template<class T>
unsigned int ArbolBinarioOrd<T>::tamano(NodoBinario<T>* nodo){
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
void ArbolBinarioOrd<T>::preOrden(){
    if(!this->esVacio())
        this->preOrden(this->raiz);
}

template<class T>
void ArbolBinarioOrd<T>::preOrden(NodoBinario<T>* nodo){
    std::cout<<nodo->obtenerDato()<<" ";
    if(nodo->obtenerHijoIzq()!=nullptr)
        this->preOrden(nodo->obtenerHijoIzq());
    if(nodo->obtenerHijoDer()!=nullptr)
        this->preOrden(nodo->obtenerHijoDer());
}

template<class T>
void ArbolBinarioOrd<T>::posOrden(){
    if(!this->esVacio())
        this->posOrden(this->raiz);
}

template<class T>
void ArbolBinarioOrd<T>::posOrden(NodoBinario<T>* nodo){
    if(nodo->obtenerHijoIzq()!=nullptr)
        this->posOrden(nodo->obtenerHijoIzq());
    if(nodo->obtenerHijoDer()!=nullptr)
        this->posOrden(nodo->obtenerHijoDer());
    std::cout<<nodo->obtenerDato()<<" ";
}

template<class T>
void ArbolBinarioOrd<T>::nivelesOrden(){
    if (!this->esVacio())
    {
        std::queue< NodoBinario<T>* > cola;
        NodoBinario<T>* nodoVisitado;
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
void ArbolBinarioOrd<T>::inOrden(){
    if(!this->esVacio())
        this->inOrden(this->raiz);
}

template<class T>
void ArbolBinarioOrd<T>::inOrden(NodoBinario<T>* nodo){
    if(nodo->obtenerHijoIzq()!=nullptr)
        this->inOrden(nodo->obtenerHijoIzq());
    std::cout<<nodo->obtenerDato()<<" ";
    if(nodo->obtenerHijoDer()!=nullptr)
        this->inOrden(nodo->obtenerHijoDer());
}