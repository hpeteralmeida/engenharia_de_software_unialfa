#include <stdio.h>

int calcularIdade(int A){
    return 2026 - A;
}

int main (void) {
    int anoAtual;

    printf("Em que ano voce nasceu? ");
    scanf("%d", &anoAtual);

    printf("sua idade é %d", calcularIdade(anoAtual));
}