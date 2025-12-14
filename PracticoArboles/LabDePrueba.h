#ifndef _PRACTICOARBOL3_H
#define _PRACTICOARBOL3_H

// Declaración adelantada de la estructura
struct Nodo;

// Crea un nuevo nodo con el valor n y un padre
Nodo* crearNodo(int n, Nodo* padre);

// Inserta un nuevo nodo en el árbol binario de búsqueda
void insertarABB(Nodo*& arbol, int n, Nodo* padre);

// Muestra el árbol en forma visual (2D)
void mostrarArbol(Nodo* arbol, int contador);

// Busca un elemento en el ABB
bool buscarElemento(Nodo* arbol, int n);

// Recorrido PreOrden (Raíz-Izq-Der)
void PreOrden(Nodo* arbol);
void PreOrdenAux(Nodo* arbol, bool& primero);

// Recorrido InOrden (Izq-Raíz-Der)
void InOrden(Nodo* arbol);
void InOrdenAux(Nodo* arbol, bool& primero);

// Recorrido PostOrden (Izq-Der-Raíz)
void PostOrden(Nodo* arbol);
void PostOrdenAux(Nodo* arbol, bool& primero);

// Busca el nodo con el valor mínimo en un subárbol
Nodo* buscarMinimo(Nodo* arbol);

// Reemplaza un nodo por otro en el árbol
void remplazar(Nodo* arbol, Nodo* nuevoNodo);

// Destruye un nodo y libera su memoria
void destruirNodo(Nodo* nodo);

// Elimina un nodo del árbol
void eliminarNodo(Nodo* nodoEliminar);

// Elimina un elemento del ABB por su valor
void eliminar(Nodo* arbol, int n);

// Pausa la ejecución esperando entrada del usuario
void pausa();

#endif