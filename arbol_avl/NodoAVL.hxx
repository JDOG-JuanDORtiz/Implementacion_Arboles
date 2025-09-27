#include "NodoAVL.h"

template <class T>
NodoAVL<T>::NodoAVL(){
    this->hijoDer = nullptr;
    this->hijoIzq = nullptr;
}

template <class T>
NodoAVL<T>::NodoAVL(T val){
    this->hijoDer = nullptr;
    this->hijoIzq = nullptr;
    this->fijarDato(val);
}

template <class T>
NodoAVL<T>::~NodoAVL(){}

template <class T>
T NodoAVL<T>::obtenerDato(){
    return this->dato;
}

template <class T>
void NodoAVL<T>::fijarDato(T val){
    this->dato = val;
}

template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoIzq(){
    return this->hijoIzq;
}

template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoDer(){
    return this->hijoDer;
}

template <class T>
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T> *izq){
    this->hijoIzq=izq;
}

template <class T>
void NodoAVL<T>::fijarHijoDer(NodoAVL<T> *der){
    this->hijoDer = der;
}

template <class T>
bool NodoAVL<T>::esHoja(){
    if(hijoIzq==nullptr && hijoDer==nullptr){
        return true;
    }
    return false;
}