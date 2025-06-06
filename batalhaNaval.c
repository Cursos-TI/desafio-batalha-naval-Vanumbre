// Aparentemente tudo funciona :-)
// Nível Novato

#include <stdio.h>

#define T_TABULEIRO 10
#define T_NAVIO 3
#define MAR 0
#define NAVIO 3

// Exibe o tabuleiro com coordenadas (letras nas colunas, números nas linhas)
void exibirTabuleiro(int tabuleiro[T_TABULEIRO][T_TABULEIRO]) {
    printf("   ");  // Espaço para o canto superior esquerdo

    // Letras das colunas (A até J)
    for (int j = 0; j < T_TABULEIRO; j++) {
        printf(" %c ", 'a' + j);
    }
    printf("\n");

    for (int i = 0; i < T_TABULEIRO; i++) {
        printf("%2d ", i);  // Número da linha à esquerda

        for (int j = 0; j < T_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Inicializar o tabuleiro com 0
    int tabuleiro[T_TABULEIRO][T_TABULEIRO] = {0};

    // Definição das coordenadas iniciais dos navios
    // Navio 1: horizontal
    int navioHorizontal[T_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int linhaH = 2, colunaH = 4;

    // Navio 2: vertical
    int navioVertical[T_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int linhaV = 5, colunaV = 7;

    // Verificar se o navio horizontal cabe no tabuleiro
    if (colunaH + T_NAVIO <= T_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < T_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != MAR) {
                sobreposicao = 1;
                break;
            }
        }
        //caso não caiba vai dar erro
        if (!sobreposicao) {
            for (int i = 0; i < T_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        } else {
            printf("Erro: Sobreposição detectada para o navio horizontal.\n");
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Verificar se o navio vertical cabe no tabuleiro
    if (linhaV + T_NAVIO <= T_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < T_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != MAR) {
                sobreposicao = 1;
                break;
            }
        }
        //caso não caiba vai dar erro
        if (!sobreposicao) {
            for (int i = 0; i < T_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        } else {
            printf("Erro: Sobreposição detectada para o navio vertical.\n");
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
    }

    // Exibir o tabuleiro final com navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
