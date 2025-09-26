#ifndef __ARBOLGENERAL_H__
#define __ARBOLGENERAL_H__

#include "NodoGeneral.h"
#include <queue>

template <class T>
class ArbolGeneral {
	protected:
		NodoGeneral<T>* raiz;
	public:
		ArbolGeneral();
		ArbolGeneral(T val);
		~ArbolGeneral();
		bool esVacio();
		NodoGeneral<T>* obtenerRaiz();
		void fijarRaiz(NodoGeneral<T>* nraiz);
		bool insertarNodo(T padre, T n);
		bool insertarNodo(NodoGeneral<T>* nodo, T padre, T n);
		bool eliminarNodo(T n);
		bool eliminarNodo(T n, NodoGeneral<T>* nodo);
		bool buscar(T n);
		bool buscar(NodoGeneral<T>* nodo, T n);
		unsigned int altura();
		unsigned int altura(NodoGeneral<T>* nodo);
		unsigned int tamano();
		unsigned int tamano(NodoGeneral<T>* nodo);
		void preOrden();
		void preOrden(NodoGeneral<T>* nodo);
		void posOrden();
		void posOrden(NodoGeneral<T>* nodo);
		void nivelesOrden();
};

#include "ArbolGeneral.hxx"

#endif
