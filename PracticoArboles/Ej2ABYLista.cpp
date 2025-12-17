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
AB crearNodoArbol(uint valor) {
    AB nuevoNodo = new nodoAB;
    nuevoNodo->dato = valor;
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
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }

    nodoLista * aux = l1;
    while (aux ->sig != NULL) {
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
    if (b == NULL) {
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
//Determina si la lista l es un camino desde la raiz hasta una hoja del arbol b
//Un camino es una secuencia de nodos en la que cada nodo es hijo del anterior
bool esCamino(AB &b, Lista &l) { //O(N) donde N es la cantidad de nodos del arbol
  if (b == NULL && l == NULL) {
    return true;
  }
  if (b == NULL || l == NULL) {
    return false;
  }
  if (b->dato != l->elem) {
    return false;
  }
  return esCamino(b->izq, l->sig) || esCamino(b->der, l->sig);
}

Lista caminoMasLargo(AB &b) {
    if (b == NULL) {
        return NULL;
    }

    //Preguntamos las alturas de los subarboles
    int hIzq = altura(b->izq);
    int hDer = altura(b->der);     

    Lista caminoHijo;

    //Si la altura del subarbol izquierdo es mayor o igual a la del derecho
    if (hIzq >= hDer) {
        caminoHijo = caminoMasLargo(b->izq);
    } else {
        caminoHijo = caminoMasLargo(b->der);    
    }
    //Concatenamos la raiz con el camino del hijo seleccionado
    return concatenar(crearNodoLista(b->dato), caminoHijo);
}

int contarArboles(AB &b) {
    if (b == NULL) {
        return 0;
    } else {
        return 1 + contarArboles(b->izq) + contarArboles(b->der);
    }
}

int contarHojas(AB & b) {
    if (b == NULL) {
        return 0;
    }
    else {
        if (b->izq == NULL && b->der == NULL) {
            return 1;
        }
    } return contarHojas(b->izq) + contarHojas(b->der);
}

uint altura(AB& b) {
    if (b == NULL) {
        return 0;
    }
    uint alturaIzq = altura(b->izq);
    uint alturaDer = altura(b->der);
    return 1 + max(alturaIzq, alturaDer); 
}

AB copiar (AB b) {
   if (b == NULL) {
    return NULL;
   }
   AB nuevaRaiz = new nodoAB;
   nuevaRaiz->dato = b->dato;
   nuevaRaiz->izq = copiar(b->izq);
   nuevaRaiz->der = copiar(b->der);
   return nuevaRaiz;
}

void liberarArbol(AB &b) {
    if (b!= NULL) {
        liberarArbol(b->izq);
        liberarArbol(b->der);
        delete b;
        b = NULL;
    }
}


