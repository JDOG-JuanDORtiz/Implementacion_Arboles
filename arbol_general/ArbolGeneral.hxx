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
bool insertarNodo(T& padre, T& n);

<template T>
bool eliminarNodo(T& n);

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
			if(alturaHijo>alt){
				alt=alturaHijo;
			}
		}
	}
	return alt;
}

<template T>
unsigned int tamano();

<template T>
void preOrden();

<template T>
void posOrden();

<template T>
void nivelesOrden();

