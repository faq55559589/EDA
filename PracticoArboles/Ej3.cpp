#include "Ej3.h"
#include <iostream>
using namespace std;

// Estructura del nodo del árbol binario de búsqueda
struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
};
static Nodo* arbol = NULL;  

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


void mostrarArbol(Nodo *arbol, int contador) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->der, contador + 1);
        for (int i = 0; i < contador; i++) {
            cout << "   ";
        }
    }
    cout << arbol->dato << endl;
    mostrarArbol(arbol->izq, contador + 1);
}

bool buscarElemento(Nodo * arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->dato == n) {
        return true;
    }
    else if (n < arbol->dato) {
        return buscarElemento(arbol->izq, n);
    }
    else {
        return buscarElemento(arbol->der, n);
    }
}

void PreOrdenAux(Nodo* arbol, bool& primero) {
    if (arbol != NULL) {
        if (!primero) {
            cout << "-";
        }
        cout << arbol->dato;
        primero = false;
        PreOrdenAux(arbol->izq, primero);
        PreOrdenAux(arbol->der, primero);
    }
}

void PreOrden(Nodo* arbol) {
    bool primero = true;
    PreOrdenAux(arbol, primero);
}

void InOrdenAux(Nodo* arbol, bool& primero) {
    if (arbol != NULL) {
        InOrdenAux(arbol->izq, primero);
        if (!primero) {
            cout << "-";
        }
        cout << arbol->dato;
        primero = false;
        InOrdenAux(arbol->der, primero);
    }
}


void InOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    bool primero = true;
    InOrdenAux(arbol, primero);
}

void pausa() {
    cout << "\nPresione una tecla para continuar...";
    cin.ignore(); // Ignorar el '\n' del input anterior
    cin.get();    // Esperar a que el usuario presione una tecla
}

int main() {
    int numero;
    int opcion;
    int contador = 0;
    do {
        system("clear");  // Limpia la pantalla (en Linux/WSL)
        cout << "\t.:MENU:." << endl;
        cout << "1. Insertar un numero en el ABB" << endl;
        cout << "2. Mostrar arbol" << endl;
        cout << "3. Buscar un numero en el ABB" << endl;
        cout << "4. Recorrido PreOrden" << endl;
        cout << "5. Recorrido InOrden" << endl;
        cout << "6. Salir" << endl;
        
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> numero;
                insertarABB(arbol, numero);
                pausa();
                break;
            case 2:
                cout << "Mostrando el arbol binario de busqueda:" << endl;
                mostrarArbol(arbol, 0);
                pausa();
                break;
            case 3:
                cout << "Ingrese el numero a buscar: ";
                cin >> numero;
                if (buscarElemento(arbol, numero)) {
                    cout << "El numero " << numero << " SI se encuentra en el ABB." << endl;
                }
                else {
                    cout << "El numero " << numero << " NO se encuentra en el ABB." << endl;
                }
                pausa();
                break;
            case 4:
                cout << "Recorrido PreOrden del ABB: ";
                PreOrden(arbol);
                cout << endl;
                pausa();
                break;
            case 5:
                cout << "Recorrido InOrden del ABB: ";
                InOrden(arbol);
                cout << endl;
                pausa();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                pausa();
        }
    } while (opcion != 6);
}