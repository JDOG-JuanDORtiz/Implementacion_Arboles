#include "ArbolGeneral.h"

<template T>
ArbolGeneral::ArbolGeneral(){
	this->raiz= NULL;
}

<template T>
ArbolGeneral(T& val){
	NodoGeneral<T> *nodo = new NodoGeneral<T>;
	nodo->fijarDato(val); 
	this->raiz = nodo;
}

<template T>
~ArbolGeneral(){
	delete this->raiz;
	this->raiz = NULL;
}

<template T>
bool esVacio(){ return this->raiz == NULL; }

<template T>
NodoGeneral<T>* obtenerRaiz() { return this->raiz; }

<template T>
void fijarRaiz(NodoGeneral<T>* nraiz) { this->raiz = nraiz; }

<template T>
bool insertarNodo(T& padre, T& n){
	//si el arbol es vacío:
	//crear nuevo nodo, asignar dato, poner ese nodo como raiz
	//
	//si hay al menos un nodo en el árbol:
	//- revisar el nodo donde estoy para ver si coincide con padre
	//- si es padre, insertar ahí el nuevo hijo
	//- si no es el padre, revisar cada nodo hijo y llamar insertar allí
}

<template T>
bool eliminarNodo(T& n){
	//si el árbol es vacío:
	//retornar
	if(this->esVacio()){
		return false;
	}

	//si es la raiz la que quiero eliminar:
	//-hacer delete a raiz
	//-poner raiz en nulo
	if(this->raiz->obtenerDato() == n){
		delete this->raiz;
		this->raiz=NULL;
		return true;
	}

	//si hay al menos un nodo en el arbol:
	//- si alguno de los hijos es al que quiero eliminar
	//- si ninguno de los hijos es el que quiero eliminar:
	//- revisar cada nodo hijo y llamar eliminar allí
	return this->eliminarNodo(n, this->raiz);
}

<template T>
bool eliminarNodo(T& n, NodoGeneral<T>* nodo){
	std::list< NodoGeneral<T>* >::iterator it;
	bool eliminado=false;
	for(it=nodo->desc.begin(); it!=nodo->desc.end(); it++){
		if((*it)->obtenerDato()==n){
			delete *it;
			nodo->desc.erase(it);
			return true;
		}
		eliminado = this->eliminarNodo(n, *it);
		if(eliminado == true){
			return true;
		}
	}
	return false;
}


<template T>
bool buscar(T& n);

<template T>
unsigned int altura(){
	if(this->esVacio()){
		return -1;
	} else {
		return this->altura(this->raiz);
	} 

}

<template T>
unsigned int altura(NodoGeneral<T>* nodo){
	int alt=-1, alturaHijo;

	if(nodo->EsHoja()){
		alt=0;
	} else{
		std::list< NodoGeneral<T>* >::iterator it;
		for (it = nodo->desc.begin(); it != nodo->desc.end(); it++){
			alturaHijo = this->altura(*it);
			if(alturaHijo+1>alt){
				alt=alturaHijo+1;
			}
		}
	}
	return alt;
}

<template T>
unsigned int tamano(){
	if(this->esVacio())
		return 0;
	tamano(raiz);
}

<template T>
unsigned int tamano(NodoGeneral<T>* nodo){
	if(nodo->esHoja()){
		return 1;
	}
	std::list< NodoGeneral<T>* >::iterator it;
	int tamano=0;
	for(it=nodo->desc.begin(); it!=nodo->desc.end(); it++){
		tamano+=tamano(*it);
	}
	return tamano+1;
}

<template T>
void preOrden(){
	if(!this->esVacio())
		this->preOrden(this->raiz);
}

<template T>
void preOrden(NodoGeneral<T>* nodo){
	std::cout << nodo->obtenerDato()<<" ";
	
	std::list< NodoGeneral<T>* >::iterator it;
	for(it=nodo->desc.begin(); it!=nodo->desc.end(); it++){
		this->preOrden(*it);
	}
}

<template T>
void posOrden(){
	if(!this->esVacio())
		this->posOrden(this->raiz);

}

void posOrden(){
	std::list< NodoGeneral<T>* >::iterator it;
	for(it=nodo->desc.begin(); it!=nodo->desc.end(); it++){
		this->posOrden(*it);
	}

	std::cout << nodo->obtenerDato()<<" ";
}

<template T>
void nivelesOrden(){
	std::queue< NodoGeneral<T>* > colaNivel;
	colaNivel.push(this->raiz);
	while(colaNivel.size()!=0){
		NodoGeneral<T>* dato = colaNivel.front();
		std::cout << dato->obtenerDato()<<" ";
		std::list< NodoGeneral<T>* >::iterator it;
		for(it=dato->desc.begin(); it!=dato->desc.begin(); it++){
			colaNivel.push(*it);
		}
		colaNivel.pop();
	}
}

