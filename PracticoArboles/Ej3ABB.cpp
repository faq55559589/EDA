#include "Ej3ABB.h"
#include <iostream>
using namespace std;

struct nodoABB {
    unsigned int elem;
    nodoABB* izq;
    nodoABB* der;
};
typedef nodoABB * ABB;


ABB CrearNuevoNodo(int x) {
    ABB nuevoNodo = new nodoABB();
    nuevoNodo->elem = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}


void insertarABB(int x, ABB& b) {
    if (b == NULL) {
        b = CrearNuevoNodo(x);
    }
    else if (x < b->elem) {
        return insertarABB(x,b->izq);
    }
    else if (x > b->elem) {
        return insertarABB(x, b->der);
    }
    else if (x == b->elem) {
        cout << "El elemento " << x << " ya existe en el ABB. No se insertan duplicados." << endl;
        return; // El elemento ya existe, no se insertan duplicados
    }
}












int main() {
    int numero;
    int opcion;
    ABB arbol = NULL;   
    do {
        system("clear");  // Limpia la pantalla (en Linux/WSL)
        cout << "\t Bienvenido al programa de Arboles hecho por Facundo Pintado" << endl;
        cout << "1. Insertar un numero en el ABB" << endl;
        cout << "2. Salir" << endl;


        cout << " Ingrese una opcion: ";
        cin >> opcion;


        switch(opcion) {
            case 1:
                cout << "Ingrese un numero: ";
                cin >> numero;
                insertarABB(numero, arbol);
                cout << "Numero insertado correctamente." << endl;
                cout << "Presione Enter para continuar...";
                cin.ignore(); // Ignorar el '\n' del input anterior
                cin.get();    // Esperar a que el usuario presione una tecla
                break;
            case 2:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                cout << "Presione Enter para continuar...";
                cin.ignore(); // Ignorar el '\n' del input anterior
                cin.get();    // Esperar a que el usuario presione una tecla
        }
    }   while (opcion != 2);
    return 0;

}