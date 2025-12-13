
#include <iostream>
using namespace std;

bool esPalindrome(char arr[], char palabra[], int size) {
    if (size == 0 || size == 1) {
        return true;
    }
    else {
        if (arr[0] != arr[size-1]) {
            return false;
        }
        else {
            // Crear un nuevo arreglo sin el primer y último carácter
            char nuevoArr[size - 2];
            for (int i = 0; i < size - 2; i++) {
                nuevoArr[i] = arr[i + 1];
            }
            return esPalindrome(nuevoArr, palabra, size - 2);
        }

    }

}