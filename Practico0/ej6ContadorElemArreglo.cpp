// Contar cuántas veces aparece un elemento en un arreglo (recursivo)
#include <iostream>
using namespace std;

int contarElemento(int arr[], int size, int elemento);

int main() {
    int arreglo[] = {3, 5, 2, 5, 8, 5, 1, 5};
    int tamanio = 8;
    int buscar;
    
    cout << "Arreglo: {3, 5, 2, 5, 8, 5, 1, 5}" << endl;
    cout << "Ingrese el elemento a buscar: ";
    cin >> buscar;
    
    int cantidad = contarElemento(arreglo, tamanio, buscar);
    
    cout << "El elemento " << buscar << " aparece " << cantidad << " veces." << endl;
    
    return 0;
}

// Función recursiva que cuenta cuántas veces aparece 'elemento' en el arreglo
int contarElemento(int arr[], int size, int elemento) {
    // Caso base: si el tamaño es 0, no hay elementos que contar
    if (size == 0) {
        return 0;
    }
    
    // Caso recursivo:
    // 1. Reviso el último elemento (arr[size - 1])
    // 2. Si es igual al elemento buscado, sumo 1
    // 3. Llamo recursivamente con tamaño - 1
    
    if (arr[size - 1] == elemento) {
        return 1 + contarElemento(arr, size - 1, elemento);
    }
    else {
        return contarElemento(arr, size - 1, elemento);
    }
}
