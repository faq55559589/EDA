//Definir 2 enteros en memoria dinámica guardar su suma en otra variable entera en
//memoria dinámica e imprimir su valor:

#include <iostream>
using namespace std;
int main() {
    // Definir dos enteros en memoria dinámica
    int* num1 = new int;
    int* num2 = new int;

    // Pedir al usuario que ingrese los valores de los enteros
    cout << "Ingrese el primer entero: ";
    cin >> *num1;
    cout << "Ingrese el segundo entero: ";
    cin >> *num2;

    // Calcular la suma y guardarla en otra variable entera en memoria dinámica
    int* suma = new int;
    *suma = *num1 + *num2;

    // Imprimir el valor de la suma
    cout << "La suma de " << *num1 << " y " << *num2 << " es: " << *suma << endl;

    // Liberar la memoria asignada
    delete num1;
    delete num2;
    delete suma;

    return 0;   
}