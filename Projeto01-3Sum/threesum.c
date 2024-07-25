#include <stdio.h>
#include <stdlib.h>
#include "threesum.h"

int qtdOperacoes3SumFB = 0;
int qtdOperacoes3SumMelhorado = 0;

/* treeSumForcaBruta(): */
void treeSumForcaBruta(int A[], int n) {
    int contBrute = 0;  // Inicializa um contador para acompanhar o número de combinações encontradas

    // Loop sobre os elementos do array para gerar todas as combinações possíveis
    for(int i = 0; i < n; i ++) { // i vai passar por todos valores de 0 a n para varrer cada elemento e realizar as combinações
        for(int j = i+1; j < n-1; j++) { // j vai se limitar entre o valor i atual +1 até o valor de n-1 para que não haja repetições das combinações (matemática nn sei)
            for(int k = j+1; k < n; k++) { // k vai passar por todos valores de j+1 até n

                int soma = A[i]+A[j]+A[k]; // variável soma recebe a tripla atual
                qtdOperacoes3SumFB++; // incrementa qtd de operaçoes

                if (soma != 0) { // caso a tripla atual não some 0 passamos para o próximo laço.
                    continue;
                }

		// caso a soma da tripla atual seja 0 imprimimos a tripla encontrada
                
		printf("\n%d Tripla encontrada: ", contBrute+1);
		printf("[%d,%d,%d]", A[i], A[j], A[k]);
		
               	contBrute++;  // Incrementa o contador para indicar que uma combinação foi encontrada
                }
            }
        } 

    printf("\nTotal Triplas Encontradas pela Forca Bruta: %d\n", contBrute);
}


/* treeSumMelhorado(): */
void treeSumMelhorado(int A[], int n) {
    printf("\n ---3SUM - Melhorado:--- \n");
    MergeSortRecursivo(A, 0, n - 1, n); // Ordena 
    ImprimeArray(A, "Array Ord.   [] = ", n); 
    int contMelhor = 0; // Contador para o número de triplas encontradas

    for (int i = 0; i < n - 2; i++) { // Percorre todo array
        for (int j = i + 1; j < n - 1; j++) { // Percorre uma casa na frente
            int k = BuscaBinaria((A[i] + A[j]) * -1, A, j + 1, n - 1); 
            qtdOperacoes3SumMelhorado++; // Tncrementa operações do 3sum melhorado
            // Calcula o terceiro elemento necessário para formar uma tripla que soma zero
            // Multiplicar por -1 para transformar a soma A[i] + A[j] em seu complemento negativo.
            if (k >= 0) {
                contMelhor++;
                printf("%d Tripla Encontrada: [%d, %d, %d]\n", contMelhor, A[i], A[j], A[k]);
            }
        }
    }
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
        MergeSortRecursivo(A, inicio, meio, n);
        MergeSortRecursivo(A, meio+1, fim, n);
        IntercalaSemSentinela(A, inicio, meio, fim, n);
    }
}

/* IntercalaSemSentinela(): */
void IntercalaSemSentinela(int A[], int inicio, int meio, int fim, int n) {

    int B[n]; 

    int i = inicio; 
    int j = meio + 1; 
    int k = inicio; 

    for (int p = inicio; p <= fim; p++) {
        B[p] = A[p];
    }

    while (i <= meio && j <= fim) {
        if (B[i] <= B[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        A[k] = B[i];
        i++;
        k++;
    }
}

/* ImprimeArray(): */
void ImprimeArray(int A[], char Msg[], int n) {
    printf("\n%s =  ", Msg);
    for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
    }
    printf("\n");
}

/* ImprimeQtdOperacoes():  */
void ImprimeQtdOperacoes() {
    printf("Quantidade de Operacoes - 3SUM - Forca Bruta: %d\n", qtdOperacoes3SumFB);
    printf("Quantidade de Operacoes - 3SUM - Melhorado: %d", qtdOperacoes3SumMelhorado); //dando 21 e não 45. arrumar.
    printf("\n\n"); // apenas para alinhar leitura final
}