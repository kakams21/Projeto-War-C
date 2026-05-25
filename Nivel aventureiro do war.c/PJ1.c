#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TERRITORIO 5
#define TAM_STRING 100

struct war {
    char territorio[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void batalha(struct war territorio[], int atacante, int defensor) {

    if (territorio[atacante].tropas <= 1) {
        printf("\nErro: O territorio atacante precisa ter mais de 1 tropa!\n");
        return;
    }

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("\n===== BATALHA =====\n");
    printf("%s tirou %d no dado\n",
           territorio[atacante].territorio, dadoAtacante);
    printf("%s tirou %d no dado\n",
           territorio[defensor].territorio, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("\n%s venceu a batalha!\n",
               territorio[atacante].territorio);

        if (territorio[defensor].tropas > 0) {
            territorio[defensor].tropas--;
        }
    }
    else if (dadoDefensor > dadoAtacante) {
        printf("\n%s venceu a batalha!\n",
               territorio[defensor].territorio);

        if (territorio[atacante].tropas > 0) {
            territorio[atacante].tropas--;
        }
    }
    else {
        printf("\nEmpate! Ninguem perdeu tropas.\n");
    }
}

int main() {

    struct war territorio[MAX_TERRITORIO];
    int i;
    int atacante, defensor;

    srand(time(NULL));

    // Cadastro dos territórios
    for(i = 0; i < MAX_TERRITORIO; i++) {

        printf("\n=== Cadastro do Territorio %d ===\n", i + 1);

        printf("Nome do territorio: ");
        fgets(territorio[i].territorio, TAM_STRING, stdin);
        territorio[i].territorio[strcspn(territorio[i].territorio, "\n")] = 0;

        printf("Cor: ");
        fgets(territorio[i].cor, TAM_STRING, stdin);
        territorio[i].cor[strcspn(territorio[i].cor, "\n")] = 0;

        printf("Numero de tropas: ");
        scanf("%d", &territorio[i].tropas);
        limparBufferEntrada();
    }

    printf("\n===== TERRITORIOS DISPONIVEIS =====\n");
    for(i = 0; i < MAX_TERRITORIO; i++) {
        printf("%d - %s (%s) - Tropas: %d\n",
               i,
               territorio[i].territorio,
               territorio[i].cor,
               territorio[i].tropas);
    }

    printf("\nEscolha o numero do territorio ATACANTE: ");
    scanf("%d", &atacante);

    printf("Escolha o numero do territorio DEFENSOR: ");
    scanf("%d", &defensor);

    if (atacante < 0 || atacante >= MAX_TERRITORIO ||
        defensor < 0 || defensor >= MAX_TERRITORIO) {

        printf("\nOpcao invalida!\n");
        return 0;
    }

    if (atacante == defensor) {
        printf("\nErro: Um territorio nao pode atacar ele mesmo!\n");
        return 0;
    }

    batalha(territorio, atacante, defensor);

    printf("\n===== RESULTADO FINAL =====\n");

    for(i = 0; i < MAX_TERRITORIO; i++) {
        printf("\nTerritorio: %s\n", territorio[i].territorio);
        printf("Cor: %s\n", territorio[i].cor);
        printf("Tropas restantes: %d\n", territorio[i].tropas);
    }

    return 0;
}
