#include <iostream>
using namespace std;

bool EncontrarElemento(int arr[], int size, int elemento); // declaración adelantada

int main() {
    int tamanio;
    
    // Pedir tamaño del arreglo
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamanio;
    
    // Crear arreglo dinámico
    int arreglo[tamanio];
    
    // Pedir los elementos del arreglo
    cout << "Ingrese los " << tamanio << " elementos del arreglo:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> arreglo[i];
    }
    
    // Pedir el elemento a buscar
    int buscar;
    cout << "\nIngrese el elemento a buscar: ";
    cin >> buscar;
    
    // Llamar a la función recursiva
    if (EncontrarElemento(arreglo, tamanio, buscar)) {
        cout << "El elemento " << buscar << " SI esta en el arreglo." << endl;
    }
    else {
        cout << "El elemento " << buscar << " NO esta en el arreglo." << endl;
    }
    
    return 0;
}




bool EncontrarElemento(int arr[], int size, int elemento) {
    if (size == 0) {
      return false;
    }
    else {
        if (arr[size - 1] == elemento) {
            return true;
        }
        else {
            return EncontrarElemento(arr, size - 1, elemento);
        }
    }
}