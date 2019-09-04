#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAMANHO 100000
void main() {
	int i, comp = 0, troca = 0;    
	int vetor[TAMANHO]; //vetor com tamanho definido
	clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
	tempoInicial = clock(); //inicia contagem do tempo
    srand(time(NULL)); //Cria uma semente para numeros aleatorios
    
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 10; //Atribui um inteiro aleatorio entre 0 e 9
    }
    //Mostra valores do vetor nao ordenado
    for (i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
        
    //Ordena vetor pelo metodo da bolha
    for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO - 1; j++) {
			int proximo = vetor[j + 1];
			int atual  = vetor[j];
			comp = comp + 1;
			if (atual > proximo) {
				vetor[j] = proximo;
				vetor[j + 1] = atual;
				troca = troca + 1;
			}
		}
    }
    
    printf("\n");
    
    //Mostra valores do vetor ordenado   
    for (i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    
    printf("\nComparações: %d", comp);
    printf("\nTrocas: %d", troca);
    printf("\n");
    tempoFinal = clock(); //finaliza contagem do tempo
    //calcula e mostra o tempo total de execucao
    printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}
