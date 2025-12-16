#include "Ej2ABYLista.h"
#include <iostream>
using namespace std;

//Definicion estandar de un arbol Binario para este contexto
struct nodoAB {
    uint dato;
    nodoAB *izq;
    nodoAB *der;
};
typedef nodoAB * AB;


//Definicion dada de la estructura de listas
struct nodoLista {
    int elem;
    nodoLista *sig;
};
typedef nodoLista * Lista;
typedef unsigned int uint;

//Inicializamos la estructura del arbol
AB crearNodoArbol(uint valor) {
    AB nuevoNodo = new nodoAB;
    nuevoNodo->valor = valor;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

//Inicializamos la estructura de la lista
Lista crearNodoLista(int valor) {
    Lista nuevoNodo = new nodoLista;
    nuevoNodo->elem = valor;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

Lista concatenar(Lista l1, Lista l2) {
    if (l1 == NULL) {
        return L2;
    }
    if (l2 == NULL) {
        return l1;
    }

    nodoLista * aux = l1;
    while (aux ->sig ! = NULL) {
        aux = aux ->sig;
    }
     aux->sig = l2;
     return l1;
    
}   

