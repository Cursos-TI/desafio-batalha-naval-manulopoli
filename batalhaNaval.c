#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
#define tamanhoTabuleiro 10
#define linha


// Tabuleiro parte água (0)
void iniciarTabuleiro(int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro]) {
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = 0; 
        }
    }
}

// Exibindo o Tabuleiro
void exibirTabuleiro(int tabuleiro[10][10]) {
    printf("*** TABULEIRO BATALHA NAVAL ***\n");
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verificando se uma posição não está ocupada
int posicaoLivre(int tabuleiro[10][10], int x, int y, int direcao) {
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
        

        if (novoX < 0 || novoX >= 10 || novoY < 0 || novoY >= 10
          || tabuleiro[novoX][novoY] == 3) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionamento do navio
void posicionarNavio(int tabuleiro[10][10], int x, int y, int direcao) {
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
        
        tabuleiro[novoX][novoY] = 3; // Marcando a posição do navio com 3
    }
}

int main() {
    int tabuleiro[10][10];
    // Inicializando o tabuleiro
    iniciarTabuleiro(tabuleiro);

    // Definindo as coordenadas dos navios
    // Primeiro navio (Horizontal)
    int x1 = 6, y1 = 3, direcao1 = 0; // x1, y1 são as coordenadas de início, direcao1 = 0 (horizontal)
    if (posicaoLivre(tabuleiro, x1, y1, direcao1)) {
        posicionarNavio(tabuleiro, x1, y1, direcao1);
    }

    // Segundo navio (Vertical)
    int x2 = 2, y2 = 3, direcao2 = 1; // x2, y2 são as coordenadas de início, direcao2 = 1 (vertical)
    if (posicaoLivre(tabuleiro, x2, y2, direcao2)) {
        posicionarNavio(tabuleiro, x2, y2, direcao2);
    }

    // Exibir o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
