
#ifndef PRACTICO_ARBOL_LABDEPRUEBA_H
#define PRACTICO_ARBOL_LABDEPRUEBA_H

#include <cstddef>

/**
 * @brief Estructura de un nodo del árbol binario de búsqueda.
 */
struct Nodo {
	int dato;           ///< Valor almacenado en el nodo
	Nodo* der;          ///< Puntero al hijo derecho
	Nodo* izq;          ///< Puntero al hijo izquierdo
	Nodo* padre;        ///< Puntero al nodo padre
};

/**
 * @brief Crea un nuevo nodo con el valor n y un padre.
 * @param n Valor a almacenar.
 * @param padre Puntero al nodo padre.
 * @return Puntero al nuevo nodo creado.
 */
Nodo* crearNodo(int n, Nodo* padre);

/**
 * @brief Inserta un nuevo nodo en el árbol binario de búsqueda.
 * @param arbol Referencia al puntero raíz del árbol.
 * @param n Valor a insertar.
 * @param padre Puntero al nodo padre.
 */
void insertarABB(Nodo*& arbol, int n, Nodo* padre);

/**
 * @brief Muestra el árbol en forma visual (2D).
 * @param arbol Puntero a la raíz del árbol.
 * @param contador Nivel de profundidad (para formato visual).
 */
void mostrarArbol(Nodo* arbol, int contador);

/**
 * @brief Busca un elemento en el ABB.
 * @param arbol Puntero a la raíz del árbol.
 * @param n Valor a buscar.
 * @return true si el elemento existe, false en caso contrario.
 */
bool buscarElemento(Nodo* arbol, int n);

/**
 * @brief Recorrido PreOrden (Raíz-Izq-Der).
 */
void PreOrden(Nodo* arbol);
void PreOrdenAux(Nodo* arbol, bool& primero);

/**
 * @brief Recorrido InOrden (Izq-Raíz-Der).
 */
void InOrden(Nodo* arbol);
void InOrdenAux(Nodo* arbol, bool& primero);

/**
 * @brief Recorrido PostOrden (Izq-Der-Raíz).
 */
void PostOrden(Nodo* arbol);
void PostOrdenAux(Nodo* arbol, bool& primero);

/**
 * @brief Busca el nodo con el valor mínimo en un subárbol.
 * @param arbol Puntero al subárbol.
 * @return Puntero al nodo mínimo.
 */
Nodo* buscarMinimo(Nodo* arbol);

/**
 * @brief Busca el nodo con el valor máximo en un subárbol.
 * @param arbol Puntero al subárbol.
 * @return Puntero al nodo máximo.
 */
Nodo* buscarMaximo(Nodo* arbol);

/**
 * @brief Elimina el nodo con el valor mínimo de un subárbol.
 * @param arbol Referencia al puntero raíz del subárbol.
 */
void removerMinimo(Nodo*& arbol);

/**
 * @brief Elimina el nodo con el valor máximo de un subárbol.
 * @param arbol Referencia al puntero raíz del subárbol.
 */
void removerMaximo(Nodo*& arbol);

/**
 * @brief Reemplaza un nodo por otro en el árbol.
 * @param arbol Nodo a reemplazar.
 * @param nuevoNodo Nodo nuevo.
 */
void remplazar(Nodo* arbol, Nodo* nuevoNodo);

/**
 * @brief Destruye un nodo y libera su memoria.
 * @param nodo Nodo a destruir.
 */
void destruirNodo(Nodo* nodo);

/**
 * @brief Elimina un nodo del árbol (por puntero).
 * @param nodoEliminar Nodo a eliminar.
 */
void eliminarNodo(Nodo* nodoEliminar);

/**
 * @brief Elimina un elemento del ABB por su valor.
 * @param arbol Puntero a la raíz del árbol.
 * @param n Valor a eliminar.
 */
void eliminar(Nodo* arbol, int n);

/**
 * @brief Pausa la ejecución esperando entrada del usuario.
 */
void pausa();

#endif // PRACTICO_ARBOL_LABDEPRUEBA_H