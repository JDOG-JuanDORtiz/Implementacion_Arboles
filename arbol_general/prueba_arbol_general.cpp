#include <iostream>
#include <string>
/*#include <bits/stdc++.h>*/
#include "ArbolGeneral.h"
#include "NodoGeneral.h"

using namespace std;

int main(){
    //Se crea un arbol con raiz 1
    ArbolGeneral<int> arbol(1);
    //Inserciones de los nodos en formato (padre,hijo)
    arbol.insertarNodo(1,2);
    arbol.insertarNodo(1,3);
    arbol.insertarNodo(1,4);
    arbol.insertarNodo(1,5);
    arbol.insertarNodo(2,6);
    arbol.insertarNodo(2,7);
    arbol.insertarNodo(3,8);
    arbol.insertarNodo(3,9);
    arbol.insertarNodo(4,10);
    arbol.insertarNodo(5,11);
    arbol.insertarNodo(5,12);
    arbol.insertarNodo(5,13);
    arbol.insertarNodo(6,14);
    arbol.insertarNodo(14,15);
    //impresion de recorridos
    cout<<"PreOrden"<<endl;
    arbol.preOrden();
    cout<<"inOrden"<<endl;
    arbol.nivelesOrden();
    cout<<"posOrden"<<endl;
    arbol.posOrden();
    cout<<"tamano "<<arbol.tamano()<<endl;
    cout<<"altura "<<arbol.altura()<<endl;
    // Eliminacion de un nodo
    int elim = 2;
    arbol.eliminarNodo(elim);
    cout<<"inOrden"<<endl;
    arbol.nivelesOrden();
    return 0;

}
