#include "NodoGeneral.h"

template<class T>
NodoGeneral::NodoGeneral(){
	this->desc.clear();
}

template<class T>
NodoGeneral::~NodoGeneral(){
	std::list< NodoGeneral<T>* >::iterator it;
	for (it=this->desc.begin(); it!=this->desc.end(); it++){
		delete *it;
	}
	this->desc.clear();
}

template<class T>
T& NodoGeneral::obtenerDato(){
	return this->dato;
}

template<class T>
void NodoGeneral::fijarDato(T& val){
	this->dato=val;
}

template<class T>
void NodoGeneral::limpiarLista(){
	this->desc.clear();
}

template<class T>
void NodoGeneral::adicionarDesc(T& nval){
	NodoGeneral<T> *nodo = new NodoGeneral<T>;
	nodo->fijarDato(nval);
	this->desc.push_back(nodo);
}

template<class T>
bool NodoGeneral::eliminarDesc(T& val){
	std::list< NodoGeneral<T>* >::iterator it;
	NodoGeneral<T> *aux;
	bool eliminado = false;

	for(it=this->desc.begin(); it!=this->desc.end(); it++){
		aux = *it;
		if(aux->obtenerDato() == val){
			break;
		}
	}

	if(it!=this->desc.end()){
		delete *it;
		desc.erase(it);
		eliminado = true;
	}

	return eliminado;
}

template<class T>
bool NodoGeneral::esHoja(){
	return this->desc.size()==0;
}
