//  a) Realice un programa que muestre por consola el tamaño de un entero en C
//  b) Pida memoria para un dato del tipo entero, e imprima:
//• La dirección de memoria de lo apuntado por y
//• La dirección de memoria del puntero y
//• El contenido de memoria de lo apuntado por y

#include <iostream>
using namespace std;

int main() {
    // a) Mostrar el tamaño de un entero en C++
    cout << "El tamaño de un entero en C++ es: " << sizeof(int) << " bytes" << endl;

    // b) Pedir memoria para un dato del tipo entero
    int* y = new int; // Asignar memoria dinámicamente para un entero

    // Imprimir la dirección de memoria de lo apuntado por y
    cout << "Dirección de memoria de lo apuntado por y: " << y << endl;

    // Imprimir la dirección de memoria del puntero y
    cout << "Dirección de memoria del puntero y: " << &y << endl;

    // Imprimir el contenido de memoria de lo apuntado por y (inicialmente indeterminado)
    cout << "Contenido de memoria de lo apuntado por y (indeterminado): " << *y << endl;

    // Liberar la memoria asignada
    delete y;

    return 0;
}