//Lo mismo que el ejercicio 9 pero con punteros.
#include <iostream>
using namespace std;

int copiarArreglo(int * arr, int size, int *copia) {
    for (int i = 0; i < size; i++) {
        *(copia + i) = *(arr + i);
    }
    return 0;
}
int main() {
    int tamanio;
    
    // Pedir tamaño del arreglo
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamanio;
    
    // Crear arreglo dinámico
    int *arreglo = new int[tamanio];
    
    // Pedir los elementos del arreglo
    cout << "Ingrese los " << tamanio << " elementos del arreglo:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> *(arreglo + i);
    }
    
    // Crear arreglo dinámico para la copia
    int *copiaArreglo = new int[tamanio];
    
    // Llamar a la función para copiar el arreglo
    copiarArreglo(arreglo, tamanio, copiaArreglo);
    
    // Imprimir el arreglo copiado
    cout << "\nEl arreglo copiado es:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Elemento [" << i << "]: " << *(copiaArreglo + i) << endl;
    }
    
    // Liberar la memoria asignada para los arreglos
    delete[] arreglo;
    delete[] copiaArreglo;
    
    return 0;
}