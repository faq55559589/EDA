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
    if (l2 == NULL) 
        return l1;
    }

    nodoLista * aux = l1;
    while (aux ->sig ! = NULL) {
        aux = aux ->sig;
    }
    aux->sig = l2;
    return l1;  
}   

Lista preOrden(AB b) {
    if (b == NULL) {
        return NULL;
    
    Lista raiz = crearNodoLista(b->dato);  // Paso 1: Crear lista con la raiz
    
    Lista izq = preOrden(b->izq); // Paso 2: Obtener Lista del subarbol izquierdo.
    
    Lista der = preOrden(b->der); // Paso 3: Obtener Lista del subarbol derecho.
     
    return concatenar(concatenar(raiz, izq),der);
    }
}

Lista postOrden(AB b) {
    if (b == ) {
        return NULL;
    }

    Lista izq = postOrden(b->izq); // Paso 1: Obtener Lista del subarbol izquierdo.
    Lista der = postOrden(b->der); // Paso 2: Obtener Lista del subarbol derecho.
    Lista raiz = crearNodoLista(b->dato);  // Paso 3: Crear lista con la raiz
    return concatenar(concatenar(izq, der), raiz);
}

Lista inOrden(AB b) {
    if (b == NULL) {
        return NULL;
    }

    Lista izq = inOrden(b->izq);
    Lista raiz = crearNodoLista(b->dato);
    Lista der = inOrden(b->der);
    return concatenar(concatenar(izq, raiz), der);
}

bool esCamino(AB &b, Lista &l) {
}













}

