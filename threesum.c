#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"

int qtdOperacoes3SumFB=0;
int qtdOperacoes3SumMelhorado=0;

/* treeSumForcaBruta(): */
void treeSumForcaBruta(int A[], int n) {
    int cont = 0; 
    int sum;

    for(int i = 0; i < n-2; i ++){

        for(int j = i +1; j < n - 1; j++){

            for(int k = j+1; k < n; k++){

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
