#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
#define tamanhoTabuleiro 10

// Tabuleiro parte água (0)
void iniciarTabuleiro(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro]) {
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Exibindo o tabuleiro
void exibirTabuleiro(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro]) {
    printf("*** TABULEIRO BATALHA NAVAL ***\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verificando se uma posição não está ocupada
int posicaoLivre(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro], int x, int y, int direcao) {
    for (int i = 0; i < 3; i++) {
        int novoX = x, novoY = y;

        // Navio horizontal
        if (direcao == 0) {
            novoY += i;
        }
        // Navio vertical
        else if (direcao == 1) {
            novoX += i;
        }
        // Navio diagonal (para cima e para a direita)
        else if (direcao == 2) {
            novoX += i;
            novoY += i;
        }
        // Navio diagonal (para baixo e para a direita)
        else if (direcao == 3) {
            novoX += i;
            novoY -= i;
        }
       
        if (novoX < 0 || novoX >= tamanhoTabuleiro || novoY < 0 || novoY >= tamanhoTabuleiro
          || tabuleiro[novoX][novoY] == 3) {
            return 0; // posição inválida ou já ocupada
        }
    }
    return 1;
}

// Função para posicionamento do navio
void posicionarNavio(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro], int x, int y, int direcao) {
    for (int i = 0; i < 3; i++) {
        int novoX = x, novoY = y;

        // Se o navio for horizontal
        if (direcao == 0) {
            novoY += i;
        }
        // Se o navio for vertical
        else if (direcao == 1) {
            novoX += i;
        }
        // Se o navio for diagonal para cima e para a direita
        else if (direcao == 2) {
            novoX += i;
            novoY += i;
        }
        // Se o navio for diagonal para baixo e para a direita
        else if (direcao == 3) {
            novoX += i;
            novoY -= i;
        }
       
        tabuleiro[novoX][novoY] = 3; // Marcando a posição do navio com 3
    }
}

int main() {
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];

    // Inicializando o tabuleiro
    iniciarTabuleiro(tabuleiro);

    // Definindo as coordenadas dos navios
    // Primeiro navio (Horizontal)
    int x1 = 8, y1 = 5, direcao1 = 0; // x1, y1 são as coordenadas de início, direcao1 = 0 (horizontal)
    if (posicaoLivre(tabuleiro, x1, y1, direcao1)) {
        posicionarNavio(tabuleiro, x1, y1, direcao1);
    }

    // Segundo navio (Vertical)
    int x2 = 5, y2 = 1, direcao2 = 1; // x2, y2 são as coordenadas de início, direcao2 = 1 (vertical)
    if (posicaoLivre(tabuleiro, x2, y2, direcao2)) {
        posicionarNavio(tabuleiro, x2, y2, direcao2);
    }

    // Terceiro navio (Diagonal - para cima e à direita)
    int x3 = 4, y3 = 4, direcao3 = 2; // x3, y3 são as coordenadas de início, direcao3 = 2 (diagonal para cima e direita)
    if (posicaoLivre(tabuleiro, x3, y3, direcao3)) {
        posicionarNavio(tabuleiro, x3, y3, direcao3);
    }

    // Quarto navio (Diagonal para baixo e à direita)
    int x4 = 2, y4 = 8, direcao4 = 3; // x4, y4 são as coordenadas de início, direcao4 = 3 (diagonal para baixo e direita)
    if (posicaoLivre(tabuleiro, x4, y4, direcao4)) {
        posicionarNavio(tabuleiro, x4, y4, direcao4);
    }

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
