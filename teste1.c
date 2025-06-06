#include <stdio.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Inicializar o tabuleiro
int main() {

    char linha [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J'};
    int coluna [10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("TABULEIRO    BATALHA    NAVAL\n");
        printf(" ");
        for(int j = 0; j <= 10; j++) {
            printf("%c\t ", linha[j]); //Imprime os números das colunas
        }
        for(int i = 0; i <= 10; i++) {
            printf("%d\n ", coluna[i]); //Imprime as letras das linhas
        }
   
    // Criando o Tabuleiro (Matriz 10 x 10)
    int tabuleiro [10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d\t", 0);
    }
        printf("\n");
    }
      return 0;
}