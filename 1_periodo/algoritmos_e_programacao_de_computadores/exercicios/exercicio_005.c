#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct alunos{
    char nome[100];
    float nota1;
    float nota2;
    int id;
};

int alunos_totais = 0;

float media;

char aluno_mensagem[100];

struct alunos aluno[100];

void apertar_enter(){

    printf("\nPressione ENTER para continuar...");
    
    while(getchar() != '\n');

    getchar();
}

void adicionar_aluno(){
    
    char criar_aluno[100];
    
    printf("Digite o nome do aluno:");
    
    fgets(criar_aluno, 100, stdin);
    
    criar_aluno[strcspn(criar_aluno, "\n")] = '\0';
    
    strcpy(aluno[alunos_totais].nome, criar_aluno);
    
    
    printf("Digite a primeira nota do aluno:");
    scanf("%f", &aluno[alunos_totais].nota1);
    
    printf("Digite a segunda nota do aluno:");
    scanf("%f", &aluno[alunos_totais].nota2);
    
    while(getchar() != '\n');
    
    aluno[alunos_totais].id = alunos_totais + 1000;
    
    printf("O id do aluno é %d \n", aluno[alunos_totais].id);
    
    alunos_totais++;

}

bool calcular_media(){
    
    int aluno_id;
    bool calcular = false;
    int calcular_aluno;
    
    printf("Digite o id do aluno:");
    scanf("%d", &aluno_id);
    
    for(int i = 0; i < alunos_totais; i++){
        if(aluno_id == aluno[i].id){
            calcular_aluno = i;
            calcular = true;
        }
    }
    
    if(calcular){
        media = (aluno[calcular_aluno].nota1 + 
                aluno[calcular_aluno].nota2) / 2;

        strcpy(aluno_mensagem, aluno[calcular_aluno].nome);
    
        if(media >= 7){
            return true;
        } else {
            return false;
        }
    
    }
    
    printf("Aluno não encontrado!\n");
    
    return false;
}

void status(){
    
    if(calcular_media()){
        printf("Aluno %s está:\n", aluno_mensagem);
        printf("Aprovado!\n");
        printf("Sua media e: %.1f", media);
    } else {
        printf("Aluno %s está:\n", aluno_mensagem);
        printf("Reprovado!\n");
        printf("Sua media e: %.1f", media);
        
    }
    
}

void mostrar_alunos(){
    
    if(alunos_totais == 0){
        printf("nenhum aluno encontrado");
        return;
    }
    
    for(int i = 0; i < alunos_totais; i++){
        
        printf("Nome: %s\n", aluno[i].nome);
        printf("Nota 1: %.1f\n", aluno[i].nota1);
        printf("Nota 2: %.1f\n", aluno[i].nota2);
        printf("Id: %d\n", aluno[i].id);
        
        printf("\n");
        
    }
}

int main(){
    int op;
    
    while(1){

        printf("\nMENU\n");
        printf("Adicionar aluno------1\n");
        printf("Mostrar alunos-------2\n");
        printf("Status do aluno------3\n");
        printf("Exit-----------------4\n");
        
        printf("Choose an option:");
        scanf("%d", &op);
        while(getchar() != '\n');
    
        switch(op) {
        case 1:
            printf("\nAdicionar aluno!\n");
            adicionar_aluno();
            apertar_enter();
            break;

        case 2:
            printf("\nMostrar alunos!\n");
            mostrar_alunos();
            apertar_enter();
            break;

        case 3:
            printf("\nStatus!\n");
            status();
            apertar_enter();
            break;

        case 4:
            printf("\nObrigado!\n");
            apertar_enter();
            return 0;    
        }
                
    }

    return 0;
    
}