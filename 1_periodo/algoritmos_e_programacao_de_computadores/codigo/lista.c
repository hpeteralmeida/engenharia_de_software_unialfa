#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó
struct No {
    int valor;
    struct No *proximo;
};

// Função para inserir no fim da lista
void inserirNoFim(struct No **cabeca, int num) {
    struct No *novo = malloc(sizeof(struct No)); // Aloca memória
    if (novo) {
        novo->valor = num;
        novo->proximo = NULL;

        if (*cabeca == NULL) { // Se a lista estiver vazia
            *cabeca = novo;
        } else {
            struct No *aux = *cabeca;
            while (aux->proximo) { // Percorre até o último
                aux = aux->proximo;
            }
            aux->proximo = novo; // O antigo último aponta para o novo
        }
    } else {
        printf("\nErro ao alocar memoria!\n");
    }
}

// Função para imprimir a lista
void imprimirLista(struct No *no) {
    printf("\nLista: ");
    while (no) {
        printf("%d -> ", no->valor);
        no = no->proximo;
    }
    printf("NULL\n");
}

int main() {
    struct No *minhaLista = NULL;
    int opcao, valor;

    do {
        printf("\n1 - Inserir valor\n2 - Imprimir lista\n0 - Sair\nOpcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("Digite o valor: ");
            scanf("%d", &valor);
            inserirNoFim(&minhaLista, valor);
        } else if (opcao == 2) {
            imprimirLista(minhaLista);
        }
    } while (opcao != 0);

    return 0;
}
