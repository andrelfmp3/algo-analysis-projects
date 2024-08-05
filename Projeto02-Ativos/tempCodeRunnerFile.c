#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LINHAS 5
#define COLUNAS 30

int main() {
    FILE *ativos;
    char matrizC[LINHAS][130]; // número aproximado de caracteres por linha
    int matrizInt[LINHAS][COLUNAS];
    int i = 0;
    int j = 0;

    // Abre o arquivo para leitura
    ativos = fopen("ativos.txt", "r");
    if (ativos == NULL) {
        printf("Erro ao ler o arquivo");
        return 1;
    }

    // Lê o conteúdo do arquivo e armazena na matriz de caracteres
    while (fgets(matrizC[i], sizeof(matrizC[i]), ativos) != NULL && i < LINHAS) {
        i++;
    }

    // Fecha o arquivo
    fclose(ativos);

    // Processa a matrizC e armazena os números na matrizInt
    for (i = 0; i < LINHAS; i++) {
        char *token = strtok(matrizC[i], "; \n"); // Adiciona \n como delimitador
        j = 0;
        while (token != NULL && j < COLUNAS) {
            // Verifica se o token é um número inteiro
            int is_number = 1; // Assume que o token é um número
            for (int k = 0; token[k] != '\0'; k++) {
                if (!isdigit(token[k]) && !(token[k] == '-' && k == 0 && isdigit(token[k + 1]))) {
                    is_number = 0; // Não é um número
                    break;
                }
            }
            if (is_number) {
                matrizInt[i][j] = atoi(token); // Converte a string para inteiro
                j++;
            }
            token = strtok(NULL, "; \n"); // Adiciona \n como delimitador
        }
    }

    // Imprime a matriz de inteiros
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("%d ", matrizInt[i][j]);
        }
        printf("\n");
    }

    return 0;
}
