/* Desenvolva um programa em C utilizando matriz que:
    - Solicite 6 números ao usuário 
    - Exiba todos os valores digitados na tela */

#include <stdio.h>

int main() {
    int matriz [3][2];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Digite um numero para adicionar à matriz: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("=====Tabela=====\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}