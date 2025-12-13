//Definir un arreglo en memoria dinámica para almacenar 5 enteros, cargarlo con 10
//enteros e imprimirlo por pantalla

#include <iostream> 
using namespace std;
int main() {
    const int size = 5;
    
    // Crear un arreglo dinámico para almacenar 5 enteros
    int* arreglo = new int[size];
    
    // Cargar el arreglo con 10 enteros (solo se almacenarán los primeros 5)
    cout << "Ingrese 10 enteros (solo se almacenarán los primeros 5):" << endl;
    for (int i = 0; i < 10; i++) {
        int valor;
        cout << "Entero [" << i << "]: ";
        cin >> valor;
        if (i < size) {
            arreglo[i] = valor; // Almacenar solo los primeros 5 enteros
        }
    }
    
    // Imprimir el arreglo almacenado
    cout << "\nLos enteros almacenados en el arreglo son:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Elemento [" << i << "]: " << arreglo[i] << endl;
    }
    
    // Liberar la memoria asignada para el arreglo
    delete[] arreglo;
    
    return 0;
}