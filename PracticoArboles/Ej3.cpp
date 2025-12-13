#include "Ej3.h"
#include <iostream>
using namespace std;

// Estructura del nodo del árbol binario de búsqueda
struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
};

Nodo* arbol = NULL;

Nodo* crearNodo(int n) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;
    return nuevoNodo;
}

void insertarABB(Nodo*& arbol, int n) {
    if (arbol == NULL) {
        Nodo* nuevoNodo = crearNodo(n);
        arbol = nuevoNodo;
    }
    else {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz) {
            insertarABB(arbol->izq, n);  
        }
        else {
            insertarABB(arbol->der, n);
        }
    }
}


int main() {
    int numero;
    int opcion;
    do {
        cout << "\t.:MENU:." << endl;
        cout << "1. Insertar un numero en el ABB" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> numero;
                insertarABB(arbol, numero);
                break;
            case 2:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 2);
}