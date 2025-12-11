#include <stdio.h>

int producto (int A, int B) {
    if (B == 0 || A == 0) {
        return 0;
    } 
    else if (B == 1) {
        return A;
    }
    else if (B > 0) {
        return A + producto (A, B - 1);
    }
    else if (B < 0) {
        return -A + producto (A, B + 1);
    }
}

int main () {


int numero1, numero2;
int resultado;
printf("Ingrese el primer numero: ");
scanf("%d", &numero1);


printf("Ingrese el segundo numero: ");
scanf("%d", &numero2);

resultado = producto(numero1, numero2);
printf("El producto de %d y %d es: %d\n", numero1, numero2, resultado); 

return 0;
}



