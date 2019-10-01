#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAMANHO 7

int crescente(){
	int i, comp = 0, troca = 0;
	char palavra[TAMANHO];
	int vetor[TAMANHO]; //vetor com tamanho definido
	clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
	tempoInicial = clock(); //inicia contagem do tempo

	printf("Digite uma palavra (Pode ser 'Gustavo'): ");
	scanf("%s", palavra);

	for (i=0; i<TAMANHO; i++){
		if (palavra[i] == ' ')
			vetor[i] = 0;
		else if (palavra[i] == 'A' || palavra[i] == 'a'){
			vetor[i] = 1;
		}
		else if (palavra[i] == 'B' || palavra[i] == 'b')
			vetor[i] = 2;
		else if (palavra[i] == 'C' || palavra[i] == 'c')
			vetor[i] = 3;
		else if (palavra[i] == 'D' || palavra[i] == 'd')
			vetor[i] = 4;
		else if (palavra[i] == 'E' || palavra[i] == 'e')
			vetor[i] = 5;
		else if (palavra[i] == 'F' || palavra[i] == 'f')
			vetor[i] = 6;
		else if (palavra[i] == 'G' || palavra[i] == 'g')
			vetor[i] = 7;
		else if (palavra[i] == 'H' || palavra[i] == 'h')
			vetor[i] = 8;
		else if (palavra[i] == 'I' || palavra[i] == 'i')
			vetor[i] = 9;
		else if (palavra[i] == 'J' || palavra[i] == 'j')
			vetor[i] = 10;
		else if (palavra[i] == 'K' || palavra[i] == 'k')
			vetor[i] = 11;
		else if (palavra[i] == 'L' || palavra[i] == 'l')
			vetor[i] = 12;
		else if (palavra[i] == 'M' || palavra[i] == 'm')
			vetor[i] = 13;
		else if (palavra[i] == 'N' || palavra[i] == 'n')
			vetor[i] = 14;
		else if (palavra[i] == 'O' || palavra[i] == 'o')
			vetor[i] = 15;
		else if (palavra[i] == 'P' || palavra[i] == 'p')
			vetor[i] = 16;
		else if (palavra[i] == 'Q' || palavra[i] == 'q')
			vetor[i] = 17;
		else if (palavra[i] == 'R' || palavra[i] == 'r')
			vetor[i] = 18;
		else if (palavra[i] == 'S' || palavra[i] == 's')
			vetor[i] = 19;
		else if (palavra[i] == 'T' || palavra[i] == 't')
			vetor[i] = 20;
		else if (palavra[i] == 'U' || palavra[i] == 'u')
			vetor[i] = 21;
		else if (palavra[i] == 'V' || palavra[i] == 'v')
			vetor[i] = 22;
		else if (palavra[i] == 'W' || palavra[i] == 'w')
			vetor[i] = 23;
		else if (palavra[i] == 'X' || palavra[i] == 'x')
			vetor[i] = 24;
		else if (palavra[i] == 'Y' || palavra[i] == 'y')
			vetor[i] = 25;
		else if (palavra[i] == 'Z' || palavra[i] == 'z')
			vetor[i] = 26;
		/*if (palavra[i] == 'Ç' || 'ç')
			vetor[i] = 27;*/
  	}

	//Desordenado
	printf("\nDesordenado:\n");
	for (i = 0; i < TAMANHO; i++) {
		printf("| %c |", palavra[i]);
    }
	printf("\n");
    for (i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }

	
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
    
	//Ordenado
	printf("\nOrdenado:\n");
    for (i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }

    printf("\n\nComparações: %d", comp);
    printf("\nTrocas: %d", troca);
    printf("\n");
    tempoFinal = clock(); //finaliza contagem do tempo
    //calcula e mostra o tempo total de execucao
    printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}


void main() {
	crescente();
}
