/* faca um programa que leia um numero e diga 
 se ele é par ou impar */

#include <stdio.h> 

int main() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("o numero %d é par", numero);
    } else {
        printf("o numero %d é impar", numero);
    }

    return 0;
}