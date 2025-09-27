#include "ArbolAVL.h"

#include <iostream>
using namespace std;

int main(){
    ArbolAVL<int> arbol;
    for(int i=1; i<=25; i++){
	arbol.insertarNodo(i);
    }
    cout<<"\n\nFinal\nEl recorrido inOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelesOrden();
    cout<<"\nAltura: "<<arbol.altura();

    return 0;
}
