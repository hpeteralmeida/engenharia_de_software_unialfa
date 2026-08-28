#include <stdio.h>

int main() {
    struct {
        char name[50];
        int age;
        char city[50];
    } people[] = {
        {"Alice", 25, "São Paulo"},
        {"Bob", 30, "Rio de Janeiro"},
        {"Carlos", 28, "Belo Horizonte"},
        {"Diana", 22, "Curitiba"},
        {"Eduardo", 35, "Porto Alegre"}
    };

    int num_people = 5;

    printf("===== LISTA DE PESSOAS =====\n\n");

    for (int i = 0; i < num_people; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("  Nome: %s\n", people[i].name);
        printf("  Idade: %d anos\n", people[i].age);
        printf("  Cidade: %s\n\n", people[i].city);
    }

    return 0;
}