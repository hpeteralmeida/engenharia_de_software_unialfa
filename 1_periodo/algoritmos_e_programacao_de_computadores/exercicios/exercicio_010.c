/* Desenvolva um algoritmo em C que:
    - Solicite 3 notas de um aluno
    - Calcule a media
    - Informe se foi aprovado ou nao 
    
    Considere
    - Media >= 7 como aprovado */

#include <stdio.h>

int main() {
    float notas[3];
    float soma = 0, media;

    for (int c = 0; c < 3; c++) {
        printf("Escreva a %dº nota: ", c+1);
        scanf("%f", &notas[c]);
        soma += notas[c];
    }

    media = soma/3;

    if (media >= 7) {
        printf("A media foi %.2f, O aluno está aprovado", media);
    } else {
        printf("A media foi %.2f, O aluno está reprovado", media);
    }

    return 0;
}