#include <stdio.h>
#include <string.h>

struct Patient {
    char name[100];
    int age;
    char date_of_birth[11];
};

int main() {
    struct Patient patient;

    printf("===== REGISTRO DE PACIENTE NO HOSPITAL =====\n\n");

    printf("Digite o nome do paciente: ");
    fgets(patient.name, sizeof(patient.name), stdin);
    patient.name[strcspn(patient.name, "\n")] = '\0';

    printf("Digite a idade do paciente: ");
    scanf("%d", &patient.age);
    getchar();

    printf("Digite a data de nascimento (DD/MM/YYYY): ");
    fgets(patient.date_of_birth, sizeof(patient.date_of_birth), stdin);
    patient.date_of_birth[strcspn(patient.date_of_birth, "\n")] = '\0';

    printf("\n===== PACIENTE REGISTRADO =====\n");
    printf("Nome: %s\n", patient.name);
    printf("Idade: %d anos\n", patient.age);
    printf("Data de Nascimento: %s\n", patient.date_of_birth);
    printf("===============================\n");

    return 0;
}