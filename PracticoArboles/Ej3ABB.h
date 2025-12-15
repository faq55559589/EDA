#ifndef _PRACTICOARBOL3_H
#define _PRACTICOARBOL3_H

// Declaración adelantada de la estructura
struct nodoABB;
typedef nodoABB* ABB;

// Crea un nuevo nodo con el valor n
ABB CrearNuevoNodo(int x);

// Inserta un nuevo nodo en el árbol binario de búsqueda
void insertarABB(int x, ABB& b);

// Busca un elemento en el ABB
bool perteneceABB(int x, ABB b);

#endif



