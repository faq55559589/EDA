#ifndef _PRACTICOARBOL3_H
#define _PRACTICOARBOL3_H

// Declaración adelantada de la estructura
struct Nodo;

// Crea un nuevo nodo con el valor n
Nodo* crearNodo(int n);

// Inserta un nuevo nodo en el árbol binario de búsqueda
void insertarABB(Nodo*& arbol, int n);

#endif