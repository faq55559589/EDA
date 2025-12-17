//potencia(x,y) = x, y = 1
// x*potencia(x,y-1)     y > 1
#include <iostream>
using namespace std;

double potencia(int x, int y); // declaración adelantada

int main() {
    int base, exponente;
    cout << "Ingrese la base: "; 
    cin >> base;
    cout << "Ingrese el exponente: "; 
    cin >> exponente;
    
    cout << "\nPotencia de " << base << " elevado a " << exponente 
        << " es: " << potencia(base, exponente) << endl;
    
    return 0;
}

double potencia(int x, int y) {
    if (y < 0) { // caso exponente negativo: x^(-n) = 1/x^n
        return 1.0 / potencia(x, -y);
    }
    else if (y == 0) { // caso base
        return 1;
    }
    else if (y == 1) { // caso base
        return x;
    }
    else { // caso recursivo: y > 1
        return x * potencia(x, y - 1);
    }
}
