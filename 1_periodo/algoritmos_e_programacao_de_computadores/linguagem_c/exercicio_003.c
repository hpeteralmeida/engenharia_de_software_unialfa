/* Faca um programa que leia uma temperatura em graus celsius 
e converta para graus fahrenheit */

#include <stdio.h>

int main () {
    float celsius, fahrenheit;
    printf("Digite a temperatura em ºC: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("A temperatura em fahrenheit é %.2fºF", fahrenheit);

    return 0;
}