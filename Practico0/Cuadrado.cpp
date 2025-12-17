// cuadrado(n) = n^2
// Formula recursiva: n^2 = (n-1)^2 + 2n - 1
#include <iostream>
using namespace std;

int cuadrado(int num); // declaración adelantada

int main() {
    int numero;
    cout << "Ingrese un numero: "; 
    cin >> numero;
    
    cout << "\nEl cuadrado de " << numero << " es: " << cuadrado(numero) << endl;
    
    return 0;
}

int cuadrado(int num) {
    if (num == 0) { // caso base
        return 0;
    }
    else if (num == 1) { // caso base
        return 1;
    }
    else { // caso recursivo: n^2 = (n-1)^2 + 2n - 1
        return cuadrado(num - 1) + 2 * num - 1;
    }
}