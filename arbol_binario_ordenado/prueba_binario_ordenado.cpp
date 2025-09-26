#include "ArbolBinarioOrd.h"

#include <iostream>
using namespace std;

int main(){
    ArbolBinarioOrd<int> arbol;
    arbol.insertarNodo(13);
    arbol.insertarNodo(17);
    arbol.insertarNodo(15);
    arbol.insertarNodo(20);
    arbol.insertarNodo(5);
    arbol.insertarNodo(10);
    arbol.insertarNodo(21);
    arbol.insertarNodo(9);
    arbol.insertarNodo(11);
    arbol.insertarNodo(3);
    arbol.insertarNodo(4);
    arbol.insertarNodo(8);
    arbol.insertarNodo(2);
    arbol.insertarNodo(22);
    arbol.insertarNodo(16);
    arbol.insertarNodo(1);
    arbol.insertarNodo(12);
    // Impresion de recorrido
    cout<<"\nEl recorrido inOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelesOrden();
    cout<<"\nAltura: "<<arbol.altura();

    cout<<"\n\nEliminar 1: "<<arbol.eliminarNodo(1);
    cout<<"\nEl recorrido inOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelesOrden();
    cout<<"\nAltura: "<<arbol.altura();
    
    cout<<"\n\nEliminar 3: "<<arbol.eliminarNodo(3);
    cout<<"\nEl recorrido inOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelesOrden();
    cout<<"\nAltura: "<<arbol.altura();

    cout<<"\n\nEliminar 10: "<<arbol.eliminarNodo(10);
    cout<<"\nEl recorrido inOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelesOrden();
    cout<<"\nAltura: "<<arbol.altura();

    cout<<"\n\nEliminar 17: "<<arbol.eliminarNodo(17);
    cout<<"\nEl recorrido inOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelesOrden();
    cout<<"\nAltura: "<<arbol.altura();

    cout<<"\n\nEliminar 21: "<<arbol.eliminarNodo(21);
    cout<<"\nEl recorrido inOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelesOrden();
    cout<<"\nAltura: "<<arbol.altura();

    arbol.insertarNodo(23);
    arbol.insertarNodo(24);
    arbol.insertarNodo(25);
    arbol.insertarNodo(26);
    arbol.insertarNodo(27);
    cout<<"\n\nInsertar 23-27:";
    cout<<"\nEl recorrido inOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelesOrden();
    cout<<"\nAltura: "<<arbol.altura();
    
    cout<<"\n\nEliminar raiz: "<<arbol.eliminarNodo(13);
    cout<<"\nEl recorrido inOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelesOrden();
    cout<<"\nAltura: "<<arbol.altura()<<" Tamaño: "<<arbol.tamano();

    return 0;
}