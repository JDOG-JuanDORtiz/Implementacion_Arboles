#ifndef __ARBOLBINARIOORD_H__
#define __ARBOLBINARIOORD_H__

#include "NodoBinario.h"
#include <queue>

template <class T>
class ArbolBinarioOrd {
	protected:
		NodoBinario<T>* raiz;
	public:
		ArbolBinarioOrd();
		ArbolBinarioOrd(T val);
		~ArbolBinarioOrd();
		bool esVacio();
		NodoBinario<T>* obtenerRaiz();
        T datoRaiz();
		void fijarRaiz(NodoBinario<T>* nraiz);
		bool insertarNodo(T n);
		bool insertarNodo(NodoBinario<T>* nodo, T n);
		bool eliminarNodo(T n);
		bool eliminarNodo(T n, NodoBinario<T>* nodo);
		bool buscar(T n);
		int altura();
		int altura(NodoBinario<T>* nodo);
		unsigned int tamano();
		unsigned int tamano(NodoBinario<T>* nodo);
		void preOrden();
		void preOrden(NodoBinario<T>* nodo);
		void posOrden();
		void posOrden(NodoBinario<T>* nodo);
		void nivelesOrden();
        void inOrden();
        void inOrden(NodoBinario<T>* nodo);
};

#include "ArbolBinarioOrd.hxx"

#endif