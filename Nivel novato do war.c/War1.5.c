#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes Globais
#define MAX_TERRITORIO 5
#define TAM_STRING 100

// Definição da estrutura
struct war {
    char territorio[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};

// Função para limpar buffer
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    struct war territorios[MAX_TERRITORIO];
    int totalterritorio = 0;

    // Cadastro
    for(int i = 0; i < MAX_TERRITORIO; i++) {

        printf("\nCadastro do territorio %d\n", i + 1);

        printf("Nome do territorio: ");
        fgets(territorios[i].territorio, TAM_STRING, stdin);
        territorios[i].territorio[strcspn(territorios[i].territorio, "\n")] = 0;

        printf("Cor: ");
        fgets(territorios[i].cor, TAM_STRING, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = 0;

        printf("Numero de tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBufferEntrada();

        totalterritorio++;
    }

    // Mostrar no final
    printf("\n===== TERRITORIOS CADASTRADOS =====\n");

    for(int i = 0; i < totalterritorio; i++) {
        printf("\nTerritorio: %s\n", territorios[i].territorio);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}
