#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAMANHO 100000

int aleatorio(){
	
	int comp = 0, troca = 0;
    int vetor[TAMANHO];
    int eleito, menor, posicaoDoMenor;
    
    clock_t tempoInicial, tempoFinal; 
    srand(time(NULL));
    tempoInicial = clock();
    
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 10;
    }
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }    

    for (int i = 0; i < TAMANHO - 1; i++) {
		eleito = vetor[i];
		menor = vetor[i+1];
		posicaoDoMenor = i+1;
		for (int j = i+1; j < TAMANHO; j++) {
			if (vetor[j] < menor) {
				menor = vetor[j];
				posicaoDoMenor = j;
			}
			comp = comp + 1;
		}
		if( menor < eleito ){
			vetor[i] = vetor[posicaoDoMenor];
			vetor[posicaoDoMenor] = eleito;
				troca = troca + 1;
		}
	}
    
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    
    printf("\nComparação: %d", comp);
    printf("\nTroca: %d", troca);
    printf("\n");
    tempoFinal = clock(); 
    
    printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}

int crescente(){
	
	int comp = 0, troca = 0;
    int vetor[TAMANHO];
    int eleito, menor, posicaoDoMenor;
    
    clock_t tempoInicial, tempoFinal; 
    tempoInicial = clock();
    
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = TAMANHO - i;
    }
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }    

    for (int i = 0; i < TAMANHO - 2; i++) {
		eleito = vetor[i];
		menor = vetor[i+1];
		posicaoDoMenor = i+1;
		for (int j = i+1; j < TAMANHO; j++) {
			if (vetor[j] < menor) {
				menor = vetor[j];
				posicaoDoMenor = j;
			}
			comp = comp + 1;
		}
		if( menor < eleito ){
			vetor[i] = vetor[posicaoDoMenor];
			vetor[posicaoDoMenor] = eleito;
				troca = troca + 1;
		}
	}
    
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    
    printf("\nComparação: %d", comp);
    printf("\nTroca: %d", troca);
    printf("\n");
    tempoFinal = clock(); 
    
    printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}

int decrescente(){
	
	int comp = 0, troca = 0;
    int vetor[TAMANHO];
    int eleito, menor, posicaoDoMenor;
    
    clock_t tempoInicial, tempoFinal; 
    tempoInicial = clock();
    
    for (int i = 0; i < TAMANHO; i++) {
        vetor[i] = i;
    }
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }    

    for (int i = 0; i < TAMANHO - 2; i++) {
		eleito = vetor[i];
		menor = vetor[i+1];
		posicaoDoMenor = i+1;
		for (int j = i+1; j < TAMANHO; j++) {
			if (vetor[j] > menor) {
				menor = vetor[j];
				posicaoDoMenor = j;
			}
			comp = comp + 1;
		}
		if( menor > eleito ){
			vetor[i] = vetor[posicaoDoMenor];
			vetor[posicaoDoMenor] = eleito;
				troca = troca + 1;
		}
	}
    
    printf("\n");
    
    for (int i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
    
    printf("\nComparação: %d", comp);
    printf("\nTroca: %d", troca);
    printf("\n");
    tempoFinal = clock(); 
    
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
