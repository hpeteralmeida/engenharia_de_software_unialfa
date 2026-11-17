#include <stdio.h>

float divisao(int A, int B) {
    return A/B;
}


float porcentagem (int A, int B) {
    return A / B * 100;
}

int main (void) {
    int option, num1, num2;
    printf("====================\n");
    printf("    Calculadora     \n");
    printf("====================\n");
    printf("1. Divisao\n");
    printf("2. Porcentagem\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("Digite o primeiro numero inteiro: ");
        scanf("%d", &num1);

        printf("Digite o segundo numero inteiro: ");
        scanf("%d", &num2);

        printf("%d / %d = %f", num1, num2, divisao(num1,num2));
    } else {
        printf("Digite o numero que voce quer calcular a porcentagem: ");
        scanf("%d", &num1);

        printf("digite a porcentagem que voce quer ver desse numero: ");
        scanf("%d", &num2);

        printf("%d de %d = %f", num1, num2, porcentagem(num1, num2));
    }
}