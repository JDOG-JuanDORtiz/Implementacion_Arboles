#ifndef __ARBOLAVL_H__
#define __ARBOLAVL_H__

#include "NodoAVL.h"
#include <queue>
#include <stack>

template <class T>
class ArbolAVL{
	protected:
		NodoAVL<T>* raiz;
	public:
		ArbolAVL();
		ArbolAVL(T val);
		~ArbolAVL();
		bool esVacio();
		NodoAVL<T>* obtenerRaiz();
        T datoRaiz();
		void fijarRaiz(NodoAVL<T>* nraiz);
		bool insertarNodo(T n);
		bool insertarNodo(NodoAVL<T>* nodo, T n);
		bool eliminarNodo(T n);
		bool eliminarNodo(T n, NodoAVL<T>* nodo);
		bool buscar(T n);
		int altura();
		int altura(NodoAVL<T>* nodo);
		unsigned int tamano();
		unsigned int tamano(NodoAVL<T>* nodo);
		void preOrden();
		void preOrden(NodoAVL<T>* nodo);
		void posOrden();
		void posOrden(NodoAVL<T>* nodo);
		void nivelesOrden();
        void inOrden();
        void inOrden(NodoAVL<T>* nodo);
		NodoAVL<T>* giroDerecha(NodoAVL<T>* n2);
		NodoAVL<T>* giroDerechaIzquierda(NodoAVL<T>* n1);
		NodoAVL<T>* giroIzquierda(NodoAVL<T>* n1);
		NodoAVL<T>* giroIzquierdaDerecha(NodoAVL<T>* n1);
};

#include "ArbolAVL.hxx"

#endif