#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5
#define TOTAL_MISSOES 3

typedef struct {
    char pais[30];
    char cor[10];
    int tropas;
} Territorio;

// Sorteia e copia missão
void atribuirMissao(char* destino, char* missoes[], int total) {
    int i = rand() % total;
    strcpy(destino, missoes[i]);
}

// Ataque com ponteiros
void atacar(Territorio* a, Territorio* d) {

    if (strcmp(a->cor, d->cor) == 0 || a->tropas <= 1) {
        printf("Ataque invalido!\n");
        return;
    }

    int da = rand()%6+1;
    int dd = rand()%6+1;

    if (da > dd) {
        int metade = a->tropas / 2;
        strcpy(d->cor, a->cor);
        d->tropas = metade;
        a->tropas -= metade;
        printf("Atacante venceu!\n");
    } else {
        a->tropas--;
        printf("Defensor venceu!\n");
    }
}

// Verifica missão para qualquer cor
int verificarMissao(char* missao, Territorio* mapa, int tam, char* cor) {

    if (strcmp(missao, "Conquistar 3 territorios") == 0) {
        int c = 0;
        for (int i=0;i<tam;i++)
            if (strcmp(mapa[i].cor, cor)==0) c++;
        return c >= 3;
    }

    if (strcmp(missao, "Ter 10 tropas") == 0) {
        int soma = 0;
        for (int i=0;i<tam;i++)
            if (strcmp(mapa[i].cor, cor)==0)
                soma += mapa[i].tropas;
        return soma >= 10;
    }

    return 0;
}

int main() {

    srand(time(NULL));

    char* missoes[TOTAL_MISSOES] = {
        "Conquistar 3 territorios",
        "Ter 10 tropas",
        "Dominar metade do mapa"
    };

    Territorio* mapa = malloc(N * sizeof(Territorio));

    for (int i=0;i<N;i++) {
        printf("\nNome do pais: ");
        scanf("%s", mapa[i].pais);
        printf("Cor do pais: ");
        scanf("%s", mapa[i].cor);
        printf("Quantas Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }

    char corJogador[10];
    printf("\nDigite sua cor: ");
    scanf("%s", corJogador);

    char* missao = malloc(100);
    atribuirMissao(missao, missoes, TOTAL_MISSOES);

    printf("\nSua missao: %s\n", missao);

    int a,d;

    while (1) {

        printf("\n--- MAPA ---\n");
        for (int i=0;i<N;i++)
            printf("%d - %s | %s | %d\n",
                   i, mapa[i].pais,
                   mapa[i].cor,
                   mapa[i].tropas);

        printf("Atacante: ");
        scanf("%d",&a);
        printf("Defensor: ");
        scanf("%d",&d);

        if (a>=0 && a<N && d>=0 && d<N && a!=d)
            atacar(&mapa[a], &mapa[d]);

        if (verificarMissao(missao, mapa, N, corJogador)) {
            printf("\nMISSÃO CUMPRIDA! VOCE VENCEU!\n");
            break;
        }
    }

    free(mapa);
    free(missao);

    return 0;
}
