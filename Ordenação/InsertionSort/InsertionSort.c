#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAMANHO 100000

void aleatorio() {
	int comp = 0, troca = 0;    
    int vetor[TAMANHO]; //vetor com tamanho definido
    int eleito = 0;
    int j = 0;
    clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
    srand(time(NULL)); //Cria uma semente para numeros aleatorios
    tempoInicial = clock(); //inicia contagem do tempo
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 10; //Atribui um inteiro aleatorio entre 0 e 5
    }
    //Mostra valores do vetor nao ordenado
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    printf("\n");
    //Ordena vetor pelo metodo da da selecao
    for (int i = 1; i < TAMANHO; i++) {
        eleito = vetor[i];
        j = i - 1;
		comp = comp + 1;
        while (j >= 0 && vetor[j] > eleito) {
            vetor[j + 1] = vetor[j];
            j--;
			troca = troca + 1;
        }
        vetor[j + 1] = eleito;
    }
    //Mostra valores do vetor ordenado   
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    printf("\nComparações: %d", comp);
    printf("\nTrocas: %d", troca);
    printf("\n");
    tempoFinal = clock(); //finaliza contagem do tempo
    //calcula e mostra o tempo total de execucao
    printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}

void crescente() {
	int comp = 0, troca = 0;    
    int vetor[TAMANHO]; //vetor com tamanho definido
    int eleito = 0;
    int j = 0;
    clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
    tempoInicial = clock(); //inicia contagem do tempo
    
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = TAMANHO - i; //Atribui um inteiro aleatorio entre 0 e 5
    }
    //Mostra valores do vetor nao ordenado
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    printf("\n");
    //Ordena vetor pelo metodo da da selecao
    for (int i = 1; i < TAMANHO; i++) {
        eleito = vetor[i];
        j = i - 1;
		comp = comp + 1;
        while (j >= 0 && vetor[j] > eleito) {
            vetor[j + 1] = vetor[j];
            j--;
			troca = troca + 1;
        }
        vetor[j + 1] = eleito;
    }
    //Mostra valores do vetor ordenado   
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    printf("\nComparações: %d", comp);
    printf("\nTrocas: %d", troca);
    printf("\n");
    tempoFinal = clock(); //finaliza contagem do tempo
    //calcula e mostra o tempo total de execucao
    printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}

void decrescente() {
	int comp = 0, troca = 0;    
    int vetor[TAMANHO]; //vetor com tamanho definido
    int eleito = 0;
    int j = 0;
    clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
    tempoInicial = clock(); //inicia contagem do tempo
    
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = i; //Atribui um inteiro aleatorio entre 0 e 5
    }
    //Mostra valores do vetor nao ordenado
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    printf("\n");
    //Ordena vetor pelo metodo da da selecao
    for (int i = 1; i < TAMANHO; i++) {
        eleito = vetor[i];
        j = i - 1;
		comp = comp + 1;
        while (j >= 0 && vetor[j] < eleito) {
            vetor[j + 1] = vetor[j];
            j--;
			troca = troca + 1;
        }
        vetor[j + 1] = eleito;
    }
    //Mostra valores do vetor ordenado   
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    printf("\nComparações: %d", comp);
    printf("\nTrocas: %d", troca);
    printf("\n");
    tempoFinal = clock(); //finaliza contagem do tempo
    //calcula e mostra o tempo total de execucao
    printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}

void main() {
	
	int opcao = 0;
	printf("---------- Menu ----------");
	printf("\n| 1 - Aleatório  |\n| 2 - Crescente  |\n| 3 - Decrescente|");
	printf("\n| Escolha uma opção: ");
	scanf("%d", &opcao);

	switch (opcao) {
		case 1 :
		printf("\n----- Aleatório -----\n");
		aleatorio();
		break;
    
		case 2 :
		printf("\n----- Crescente -----\n");
		crescente();
		break;
    
		case 3 :
		printf("\n----- Decrescente -----\n");
		decrescente();
		break;
		
		default :
		printf("\n----- Valor Inválido! -----");
	}
}
