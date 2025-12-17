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

bool perteneceABB(int x, ABB b) {
    if (b == NULL) {
        return false;
    }
    else if (x == b->elem) {
        return true;
    }
    else if (x < b->elem) {
        return perteneceABB(x, b->izq);
    }
    else if (x > b->elem) {
        return perteneceABB(x, b->der);
    }
    return false; // Caso base, no encontrado
}


ABB minABB (ABB b) { //Funcion que busca el nodo minimo en un subarbol
    if (b == NULL) {
        return NULL;
    }
    else if (b->izq) {
        return minABB(b->izq);
    }
    else {
        return b;
    }
}
ABB maxABB (ABB b) {
    if (b->der == NULL) {
        return b;
    }
    else {
        return maxABB(b->der);
    }
}

void removerMaxABB(ABB& b) {
    if (b == NULL) {
        return;
    }
    else if (b->der != NULL) {
        removerMaxABB(b->der);
    }
    else {
        ABB aux = b;
        b = b->izq; 
        delete aux;
    }
}

void removerABB (int x, ABB& b) {
    if (b == NULL) {
        return;
    }
    else if (b->elem == x) {
        eliminarNodo(b);
    }
    else if (x < b->elem) {
        removerABB(x , b->izq);
    }
    else {
        removerABB(x, b->der);
    }
}
void remplazarABB(int x, ABB& b) {

} 

void eliminarNodo(ABB & b){
       if (b->izq && b->der) { // Si el nodo tiene dos hijos
        ABB maxIzq = maxABB(b->izq);
        b->elem = maxIzq->elem;
        remplazarABB(maxIzq->elem, b->izq);
    }
    else if (b->izq) { // Si el nodo tiene solo hijo izquierdo
        ABB aux = b;
        b = b->izq;
        delete aux;
    }
    else if (b->der) { // Si el nodo tiene solo hijo derecho
        ABB aux = b;
        b = b->der;
        delete aux;
    }
    else { // Si el nodo no tiene hijos 
        delete b;
        b = NULL;
    }
}







int main() {
    int numero;
    int opcion;
    ABB arbol = NULL;   
    do {
        #ifdef _WIN32
            system("cls");  // Windows
        #else
            system("clear");  // Linux/WSL
        #endif
        cout << "\t Bienvenido al programa de Arboles hecho por Facundo Pintado" << endl;
        cout << "1. Insertar un numero en el ABB" << endl;
        cout << "2. Ingrese un numero para buscar dentro del ABB" << endl;
        cout << "3. Salir" << endl;
        
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
                cout << "Ingrese el numero a buscar: ";
                cin >> numero;
                if (perteneceABB(numero,arbol)) {
                    cout << "El numero " << numero << " Se encuentra en el arbol." << endl;
                }
                else {
                    cout << "El numero " << numero << " No se encuentra en el Arbol." << endl;
                }
                cout << "Presiona algun numero para continuar pinche cabron :)";
                cin.ignore();
                cin.get();
                break;
            case 3:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                cout << "Presione Enter para continuar...";
                cin.ignore(); // Ignorar el '\n' del input anterior
                cin.get();    // Esperar a que el usuario presione una tecla
        }
    }   while (opcion != 3);
    return 0;

}