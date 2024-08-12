#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "subarray.h"

#define LINHAS 5 // tamanho da matriz esperada
#define COLUNAS 30 // tamanho da matriz esperada

int main() {
    FILE *ativos;
    char matrizChar[LINHAS][127]; // 27 é o número de caracteres por linha, incluindo letras, pontos e espaços
    int matrizInt[LINHAS][COLUNAS];

    // Abre o arquivo para leitura
    ativos = fopen("ativos.txt", "r");

    // Lê o conteúdo do arquivo e armazena na matriz de caracteres
    int i = 0; // linha da matriz de
    while (fgets(matrizChar[i], 127, ativos) != NULL) { //fgets retorna null quancdo encerra
        i++; // vai para a próxima linha
    }

    // Fecha o arquivo
    fclose(ativos);

    // Processa a matrizChar e armazena os números na matrizInt
    int j;
    for (int i = 0; i < LINHAS; i++) {
        char *token = strtok(matrizChar[i], "; \n"); // Divide a linha via strtok
        int j = 0; // Índice da coluna
    
        while (token != NULL) { // Processa token de cada linha (converte para inteiro)
            char *fim; // Ponteiro para verificar fim da conversão
            int valor = strtol(token, &fim, 10);
        
            if (fim != token) {
                matrizInt[i][j] = valor; // Armazena o valor convertido na matriz de inteiros
                j++; // Pŕoxima coluna
            }
        
            // Obtém o próximo token
            token = strtok(NULL, "; \n");
        }
    }
   
    int novaMatriz[LINHAS][COLUNAS];

    for (int i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
         novaMatriz[i][j] = 0;
        }
    }

    //Imprime a matriz de inteiros (teste)
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            if (j > 0) {
                int atual = matrizInt[i][j];
                int anterior = matrizInt[i][j-1];
                novaMatriz[i][j] = atual - anterior;
            }
        }
    }

    
    for (i = 0; i < LINHAS; i++) {
        switch (i) {
            
        case 0:
            printf("PETR4: ");
            break;
        case 1:
            printf("VALE3: ");
            break;
        case 2:
            printf("ITUB4: ");
            break;
        case 3:
            printf("BRAS3: ");
            break;
        case 4:
            printf("BBDC4: ");
            break;
        }
        for (j = 0; j < COLUNAS; j++) {
            printf("%d ", novaMatriz[i][j]);
        }
        printf("\n");
    }
   
    printf("\n");

    int inicio = 0;
    int fim = 0;
    int maiorSoma = 0;
    
    for (i = 0; i < LINHAS; i++) {
        FindMaxSubArray(novaMatriz[i], 0, COLUNAS-1, &inicio, &fim, &maiorSoma);
        
        switch (i) {
            
        case 0:
            printf("PETR4: ");
            break;
        case 1:
            printf("VALE3: ");
            break;
        case 2:
            printf("ITUB4: ");
            break;
        case 3:
            printf("BRAS3: ");
            break;
        case 4:
            printf("BBDC4: ");
            break;
        }

        printf("Maior soma: %d\nIniciando no dia: %d\nTerminando no dia: %d\n\n", maiorSoma, inicio+1, fim+1);
    }



    return 0;
}
