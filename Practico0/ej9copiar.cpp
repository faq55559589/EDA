//Funcion que retorna una copia de un arreglo pasado por parametro.
#include <iostream>
using namespace std;

int* CopiarArreglo(int arr[], int size) {
    // Crear un nuevo arreglo dinámico para la copia
    int* nuevoArr = new int[size];
    
    // Copiar los elementos del arreglo original al nuevo arreglo
    for (int i = 0; i < size; i++) {
        nuevoArr[i] = arr[i];
    }
    
    return nuevoArr; // Retornar el nuevo arreglo copiado
}
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
    
    // Llamar a la función para copiar el arreglo
    int* copiaArreglo = CopiarArreglo(arreglo, tamanio);
    
    // Imprimir el arreglo copiado
    cout << "\nEl arreglo copiado es:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Elemento [" << i << "]: " << copiaArreglo[i] << endl;
    }
    
    // Liberar la memoria asignada para el arreglo copiado
    delete[] copiaArreglo;
    
    return 0;
}

