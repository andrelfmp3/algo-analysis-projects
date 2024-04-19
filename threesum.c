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
    for(int i = 0; i < n; i ++) { // i vai passar por todos valores de 0 a n para varrer cada elemento e realizar as combinações
        for(int j = i+1; j < n-1; j++) { // j vai se limitar entre o valor i atual +1 até o valor de n-1 para que não haja repetições das combinações (matemática nn sei)
            for(int k = j+1; k < n; k++) { // k vai passar por todos valores de j+1 até n

                int soma = A[i]+A[j]+A[k]; // autoexplicativo
                if (soma != 0) { // caso a tripla atual não some 0 passamos para o próximo laço.
                    continue;
                }

                // caso a soma da tripla atual seja 0 adicionamos ao array sum

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
                    cont++;
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
   
    // imprimir as combinações possíveis
    for (int i = 0; i < cont; i++) {

        printf("\n%d Tripla encontrada: ", i+1);
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%d", sum[i][j]);
            if (j < 2) {
                printf(",");
            }
        }
        printf("]");
    }

    printf("\nTotal Triplas Encontradas pela Forca Bruta: %d\n", cont);
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
