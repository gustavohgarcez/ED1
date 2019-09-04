#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TAMANHO 100000

int bubbleAleatorio(){
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

int bubbleCrescente(){
int i, comp = 0, troca = 0;    
	int vetor[TAMANHO]; //vetor com tamanho definido
	clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
	tempoInicial = clock(); //inicia contagem do tempo

//Definindo valor
    for (i = 0; i < TAMANHO; i++) {
		vetor[i] = TAMANHO-i;
    }
//Desordenado
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

int bubbleDecrescente(){
	int i, comp = 0, troca = 0;    
	int vetor[TAMANHO]; //vetor com tamanho definido
	clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
	tempoInicial = clock(); //inicia contagem do tempo

//Definindo valor
    for (i = 0; i < TAMANHO; i++) {
		vetor[i] = i;
    }
//Desordenado
    for (i = 0; i < TAMANHO; i++) {
		printf("| %d |", vetor[i]);
    }
	
    for (int i = 0; i < TAMANHO; i++) {
		for (int j = 0; j < TAMANHO - 1; j++) {
			int proximo = vetor[j + 1];
			int atual  = vetor[j];
			comp = comp + 1;
			if (atual < proximo) {
				vetor[j] = proximo;
				vetor[j + 1] = atual;
				troca = troca + 1;
			}
		}
    }
    
    printf("\n");
    
//Ordenado
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

void bubbleMain() {
	
	int opcao = 0;
	printf("---------- Menu ----------");
	printf("\n| 1 - Aleatório           |\n| 2 - Crescente           |\n| 3 - Decrescente         |\n| 4 - Sair                |");
	printf("\n| Escolha uma opção: ");
	scanf("%d", &opcao);

	switch (opcao) {
		case 1 :
		printf("\n----- Bubble Aleatório -----\n");
		bubbleAleatorio();
		break;
    
		case 2 :
		printf("\n----- Bubble Crescente -----\n");
		bubbleCrescente();
		break;
    
		case 3 :
		printf("\n----- Bubble Decrescente -----\n");
		bubbleDecrescente();
		break;
		
		case 4 :
		printf("\n--------- ADEUS! ----------\n");
		exit(0);
		break;
		
		default :
		printf("\n----- Valor Inválido! -----");
	}
}

void insertionAleatorio() {
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

void insertionCrescente() {
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

void insertionDecrescente() {
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

void insertionMain() {
	
	int opcao = 0;
	printf("---------- Menu ----------");
	printf("\n| 1 - Aleatório           |\n| 2 - Crescente           |\n| 3 - Decrescente         |\n| 4 - Sair                |");
	printf("\n| Escolha uma opção: ");
	scanf("%d", &opcao);

	switch (opcao) {
		case 1 :
		printf("\n----- Insertion Aleatório -----\n");
		insertionAleatorio();
		break;
    
		case 2 :
		printf("\n----- Insertion Crescente -----\n");
		insertionCrescente();
		break;
    
		case 3 :
		printf("\n----- Insertion Decrescente -----\n");
		insertionDecrescente();
		break;
		
		case 4 :
		printf("\n--------- ADEUS! ----------\n");
		exit(0);
		break;
		
		default :
		printf("\n----- Valor Inválido! -----");
	}
}

int selectionAleatorio(){
	
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

int selectionCrescente(){
	
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

int selectionDecrescente(){
	
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

void selectionMain() {
	
	int opcao = 0;
	printf("---------- Menu ----------");
	printf("\n| 1 - Aleatório           |\n| 2 - Crescente           |\n| 3 - Decrescente         |\n| 4 - Sair                |");
	printf("\n| Escolha uma opção: ");
	scanf("%d", &opcao);

	switch (opcao) {
		case 1 :
		printf("\n----- Selection Aleatório -----\n");
		selectionAleatorio();
		break;
    
		case 2 :
		printf("\n----- Selection Crescente -----\n");
		selectionCrescente();
		break;
    
		case 3 :
		printf("\n----- Selection Decrescente -----\n");
		selectionDecrescente();
		break;
		
		case 4 :
		printf("\n--------- ADEUS! ----------\n");
		exit(0);
		break;
		
		default :
		printf("\n----- Valor Inválido! -----");
	}
}

void main() {
	
	int opcao = 0;
	printf("---------- Menu ----------");
	printf("\n| 1 - Bubble              |\n| 2 - Insertion           |\n| 3 - Selection           |\n| 4 - Sair                |");
	printf("\n| Escolha uma opção: ");
	scanf("%d", &opcao);

	switch (opcao) {
		case 1 :
		printf("\n------- BubbleSort -------\n");
		bubbleMain();
		break;
    
		case 2 :
		printf("\n------- Insertion --------\n");
		insertionMain();
		break;
    
		case 3 :
		printf("\n------- Selection --------\n");
		selectionMain();
		break;
		
		case 4 :
		printf("\n--------- ADEUS! ----------\n");
		exit(0);
		break;
		
		default :
		printf("\n------- Valor Inválido! -------");
	}
}

