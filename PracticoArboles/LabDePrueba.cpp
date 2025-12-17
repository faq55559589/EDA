#include "LabDePrueba.h"
#include <iostream>
using namespace std;

// Estructura del nodo del árbol binario de búsqueda
struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
};
static Nodo* arbol = NULL;  

Nodo* crearNodo(int n, Nodo* padre) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = n;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;
    nuevoNodo->padre = padre;
    return nuevoNodo;
}

void insertarABB(Nodo*& arbol, int n, Nodo* padre) {
    if (arbol == NULL) {
        Nodo* nuevoNodo = crearNodo(n,padre);
        arbol = nuevoNodo;
    }
    else {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz) {
            insertarABB(arbol->izq, n, arbol);  
        }
        else {
            insertarABB(arbol->der, n, arbol);
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

void PostOrdenAux(Nodo* arbol, bool& primero) {
    if (arbol == NULL) {
        return;
    }
    else {
        PostOrdenAux(arbol->izq, primero);
        PostOrdenAux(arbol->der, primero);
        if (!primero) {
            cout << "-";
        }
        cout << arbol->dato;
        primero = false;
    }
}

void PostOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    bool primero = true;
    PostOrdenAux(arbol, primero);
}

Nodo * buscarMinimo(Nodo* arbol) { //Funcion que busca el nodo minimo en un subarbol
    if (arbol == NULL) {
        return NULL;
    }
    else if (arbol->izq) {
        return buscarMinimo(arbol->izq);
    }
    else {
        return arbol;
    }
}

Nodo * buscarMaximo(Nodo* arbol) {
    if (arbol->der == NULL) {
        return arbol;
    }
    else {
        return buscarMaximo(arbol->der);
    }
}

void removerMaximo(Nodo*& arbol) {
    if (arbol == NULL) {
        return;
    }
    else if (arbol->der != NULL) {
        removerMaximo(arbol->der);
    }
    else {
        Nodo* aux = arbol;
        arbol = arbol->izq; 
        delete aux;
    }
}
void removerMinimo(Nodo*& arbol) {
    if (arbol == NULL) {
        return;
    }
    else if (arbol->izq != NULL) {
        removerMinimo(arbol->izq);
    }
    else {
        Nodo* aux = arbol;
        arbol = arbol->der; 
        delete aux;
    }
}
void remplazar(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->padre) {
        if (arbol->padre->izq == arbol) {
            arbol->padre->izq = nuevoNodo;
        } 
        else if (arbol->padre->der == arbol) {
            arbol->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
}

void destruirNodo(Nodo* nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    nodo->padre = NULL;
    delete nodo;
}


void eliminarNodo(Nodo* nodoEliminar) { //Funcion que elimina un Nodo y hace el remplazo, hay 3 tipos
    if (nodoEliminar->izq && nodoEliminar->der) { // Si el nodo tiene dos hijos
        Nodo* menor = buscarMinimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if (nodoEliminar->izq) { // Si el nodo tiene solo hijo izquierdo
        remplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->der) { // Si el nodo tiene solo hijo derecho
        remplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else { // Si el nodo no tiene hijos 
        remplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}

void eliminar(Nodo*arbol, int n) { // Funcion que busca el nodo a eliminar
    if (arbol == NULL) {
        return;
    }
    else if (arbol->dato == n) {
        eliminarNodo(arbol);
    }
    else if (n < arbol->dato) {
        eliminar(arbol->izq, n);
    }
    else {
        eliminar(arbol->der, n);
    }
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
    bool primero = true;
    do {
        system("clear");  // Limpia la pantalla (en Linux/WSL)
        cout << "\t.:MENU:." << endl;
        cout << "1. Insertar un numero en el ABB" << endl;
        cout << "2. Mostrar arbol" << endl;
        cout << "3. Buscar un numero en el ABB" << endl;
        cout << "4. Recorrido PreOrden" << endl;
        cout << "5. Recorrido InOrden" << endl;
        cout << "6. Recorrido PostOrden" << endl;
        cout << "7. Eliminar un nodo del ABB" << endl;
        cout << "8. Salir" << endl;
        
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> numero;
                insertarABB(arbol, numero, NULL);
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
                cout << "Recorrido PostOrden del ABB: ";
                PostOrden(arbol);
                cout << endl;   
                pausa();
                break;
            case 7:
                cout << "\nDigite el nodo que desea eliminar: ";
                cin >> numero;
                eliminar(arbol, numero);
                cout << "Nodo eliminado correctamente." << endl;
                pausa();
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;   
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                pausa();
        }
    } while (opcion != 8);
}