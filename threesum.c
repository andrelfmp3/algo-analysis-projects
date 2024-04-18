#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"

int qtdOperacoes3SumFB=0;
int qtdOperacoes3SumMelhorado=0;

/* treeSumForcaBruta(): */
void treeSumForcaBruta(int A[], int n) {
    int cont = 0;  // Inicializa um contador para acompanhar o número de combinações encontradas
    int **sum = NULL;  // Inicializa um ponteiro para ponteiro para armazenar as combinações

    // Loop sobre os elementos do array para gerar todas as combinações possíveis
    for(int i = 0; i < n-2; i ++) {
        for(int j = i +1; j < n - 1; j++) {
            for(int k = j+1; k < n; k++) {
                // Verifica se já foram encontradas combinações antes de realocar memória
                if (cont > 0) {
                    // Realoca memória para adicionar espaço para outra combinação
                    sum = (int **)realloc(sum, (cont + 1) * sizeof(int *));
                    // Aloca memória para armazenar os elementos da nova combinação
                    sum[cont] = (int *) malloc (sizeof(int) * 3);
                    // Armazena os elementos da combinação no array
                    sum[cont][0] = A[i];
                    sum[cont][1] = A[j];
                    sum[cont][2] = A[k];
                } else if (0 == cont) {
                    // Se esta é a primeira combinação, aloca memória sem realocar
                    sum = (int **)realloc(sum, (cont + 1) * sizeof(int *));
                    sum[cont] = (int *) malloc (sizeof(int) * 3);
                    sum[cont][0] = A[i];
                    sum[cont][1] = A[j];
                    sum[cont][2] = A[k];
                    cont++;  // Incrementa o contador para indicar que uma combinação foi encontrada
                }
            }
        }
    }
}


/* treeSumMelhorado(): */
void treeSumMelhorado(int A[], int n) {

}

/* BuscaBinaria(): */
int BuscaBinaria (int x, int A[], int inicio, int fim)
{
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2; 

        if (A[meio] == x) {
            return meio; 
        } else if (A[meio] < x) {
            return BuscaBinaria(x, A, meio + 1, fim); 
        } else {
            return BuscaBinaria(x, A, inicio, meio - 1); 
        }
    }

    return -1; 
}

/* MergeSortRecursivo(): */
void MergeSortRecursivo(int A[], int inicio, int fim, int n)
{
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        ImprimeArray(A, "Array Desord. -" , n);
        MergeSortRecursivo(A, inicio, meio, n);
        MergeSortRecursivo(A, meio+1, fim, n);
        IntercalaSemSentinela(A, inicio, meio, fim, n);
        ImprimeArray(A, "Array Ord. -", n);
    }
}

/* IntercalaSemSentinela(): */
void IntercalaSemSentinela(int A[], int inicio, int meio, int fim, int n) {
    int B[fim+1];

    for (int i = inicio; i <= meio; i++) {
        B[i] = A[i]; 
    }

    for (int j = meio+1; j <= fim; j++) {
        B[fim+meio+1-j] = A[j];
    }

    int i = inicio;
    int j = meio;

    for (int k = inicio; k <= fim; k++) {
        if (B[i] <= B[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j--;
        }
    }

}

/* ImprimeArray(): */
void ImprimeArray(int A[], char Msg[], int n)
{
    printf("\n%s", Msg);

    for(int i = 0; i < n; i++) {
        printf(" %d ", A[i]);
    }
}

/* ImprimeQtdOperacoes():  */
void ImprimeQtdOperacoes()
{

}
