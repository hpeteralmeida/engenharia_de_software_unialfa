/* Faca um programa que leia as notas de um aluno e mostre se ele foi aprovado ou nao*/

#include <stdio.h>

int main () {
    float nota1, nota2, nota3, media;
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1+nota2+nota3)/3;

    printf ("A média do aluno é %.1f", media);

    if (media > 8) {
        printf("O aluno foi aprofado!");
    } else {
        if (media >= 6) {
            printf("O aluno está de recuperação!");
        } else {
            printf("O aluno foi reprovado!");
        }
    }
    return 0;
}