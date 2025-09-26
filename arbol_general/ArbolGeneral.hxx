#include "ArbolGeneral.h"

template <class T>
ArbolGeneral<T>::ArbolGeneral(){
	this->raiz= NULL;
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(T val){
	NodoGeneral<T> *nodo = new NodoGeneral<T>;
	nodo->fijarDato(val); 
	this->raiz = nodo;
}

template <class T>
ArbolGeneral<T>::~ArbolGeneral(){
	if (this->raiz != NULL){
    	delete this->raiz;
		this->raiz = NULL;
	}
}

template <class T>
bool ArbolGeneral<T>::esVacio(){ return this->raiz == NULL; }

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::obtenerRaiz() { return this->raiz; }

template <class T>
void ArbolGeneral<T>::fijarRaiz(NodoGeneral<T>* nraiz) { this->raiz = nraiz; }

template <class T>
bool ArbolGeneral<T>::insertarNodo(T padre, T n){
	//si el arbol es vacío:
	//crear nuevo nodo, asignar dato, poner ese nodo como raiz
	if(this->esVacio()){
		NodoGeneral<T> *nodo = new NodoGeneral<T>;
		nodo->fijarDato(n);
		this->fijarRaiz(nodo);
		return true;
	}

	return insertarNodo(this->raiz, padre, n);
	
	//
	//si hay al menos un nodo en el árbol:
	//- revisar el nodo donde estoy para ver si coincide con padre
	//- si es padre, insertar ahí el nuevo hijo
	//- si no es el padre, revisar cada nodo hijo y llamar insertar allí
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(NodoGeneral<T>* nodo, T padre, T n){
	if(nodo->obtenerDato() == padre){
		nodo->adicionarDesc(n);
		return true;
	}
	typename std::list< NodoGeneral<T>* >::iterator it;
	bool insertado=false;
	for(it = nodo->desc.begin() ; it != nodo->desc.end() ; it++){
		insertado = insertarNodo(*it, padre, n);
		if(insertado == true){return true;}
	}
	return false;
}

template <class T>
bool ArbolGeneral<T>::eliminarNodo(T n){
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

template <class T>
bool ArbolGeneral<T>::eliminarNodo(T n, NodoGeneral<T>* nodo){
	typename std::list< NodoGeneral<T>* >::iterator it;
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


template <class T>
bool ArbolGeneral<T>::buscar(T n){
	if(this->esVacio()){
		return false;
	}
	return buscar(this->raiz, n);
}

template <class T>
bool ArbolGeneral<T>::buscar(NodoGeneral<T>* nodo, T n){
	if(nodo->obtenerDato()==n){
		return true;
	}
	typename std::list< NodoGeneral<T> * >::iterator it;
	bool encontrado;
	for(it = nodo->desc.begin(); it != nodo->desc.end() ; it++){
		encontrado = buscar(*it, n);
		if(encontrado==true)
			return true;
	}
	return false;
}

template <class T>
unsigned int ArbolGeneral<T>::altura(){
	if(this->esVacio()){
		return -1;
	} else {
		return this->altura(this->raiz);
	} 

}

template <class T>
unsigned int ArbolGeneral<T>::altura(NodoGeneral<T>* nodo){
	int alt=-1, alturaHijo;

	if(nodo->esHoja()){
		alt=0;
	} else{
		typename std::list< NodoGeneral<T>* >::iterator it;
		for (it = nodo->desc.begin(); it != nodo->desc.end(); it++){
			alturaHijo = this->altura(*it);
			if(alturaHijo+1>alt){
				alt=alturaHijo+1;
			}
		}
	}
	return alt;
}

template <class T>
unsigned int ArbolGeneral<T>::tamano(){
	if(this->esVacio())
		return 0;
	return tamano(raiz);
}

template <class T>
unsigned int ArbolGeneral<T>::tamano(NodoGeneral<T>* nodo){
	if(nodo->esHoja()){
		return 1;
	}
	typename std::list< NodoGeneral<T>* >::iterator it;
	int tamanoArbol=0;
	for(it=nodo->desc.begin(); it!=nodo->desc.end(); it++){
		tamanoArbol+=tamano(*it);
	}
	return tamanoArbol+1;
}

template <class T>
void ArbolGeneral<T>::preOrden(){
	if(!this->esVacio())
		this->preOrden(this->raiz);
		
	std::cout <<"\n";
}

template <class T>
void ArbolGeneral<T>::preOrden(NodoGeneral<T>* nodo){
	std::cout << nodo->obtenerDato()<<" ";
	
	typename std::list< NodoGeneral<T>* >::iterator it;
	for(it=nodo->desc.begin(); it!=nodo->desc.end(); it++){
		this->preOrden(*it);
	}
}

template <class T>
void ArbolGeneral<T>::posOrden(){
	if(!this->esVacio())
		this->posOrden(this->raiz);
	std::cout <<"\n";
}

template <class T>
void ArbolGeneral<T>::posOrden(NodoGeneral<T>* nodo){
	typename std::list< NodoGeneral<T>* >::iterator it;
	for(it=nodo->desc.begin(); it!=nodo->desc.end(); it++){
		this->posOrden(*it);
	}

	std::cout << nodo->obtenerDato()<<" ";
}

template <class T>
void ArbolGeneral<T>::nivelesOrden(){
	std::queue< NodoGeneral<T>* > colaNivel;
	colaNivel.push(this->raiz);
	while(colaNivel.size()!=0){
		NodoGeneral<T>* dato = colaNivel.front();
		std::cout << dato->obtenerDato()<<" ";
		typename std::list< NodoGeneral<T>* >::iterator it;
		for(it=dato->desc.begin(); it!=dato->desc.end(); it++){
			colaNivel.push(*it);
		}
		colaNivel.pop();
	}
	
	std::cout <<"\n";
}

