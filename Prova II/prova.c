#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No{
  int dado;
  struct No* direita;
  struct No* esquerda;
} No;

No* criarArvore(){ return NULL; }

int ArvoreVazia(No* raiz){ 
  return raiz == NULL;
}

int getValor(No** no){
  if ((*no) != NULL){
    return (*no)->dado;
  }
}

void mostrarArvore(No* raiz){
  if(!ArvoreVazia(raiz)){ //No nao vazio
    printf("%p<-%d(%p)->%p\n\n", raiz->esquerda, raiz->dado, raiz, raiz->direita);
    printf("%d", getValor(&raiz->esquerda));
    mostrarArvore(raiz->esquerda);//esquerda (subNo)
    mostrarArvore(raiz->direita); //direita (subNo)
  }
}

void gerarArquivoDot(FILE** arquivoDot, No* raiz){
  if(raiz != NULL){
    char s1[50];
    char s2[50];
    if (getValor(&raiz->esquerda)!=0){
      sprintf(s1, "%d:sw->%d [ label=\"esq\"];\n", raiz->dado, getValor(&raiz->esquerda));
      fprintf((*arquivoDot), "%s", s1);
    }
    if (getValor(&raiz->direita)!=0){
      sprintf(s2, "%d:se->%d [ label=\"dir\"];\n", raiz->dado, getValor(&raiz->direita));
      fprintf((*arquivoDot), "%s", s2);
    }    
    gerarArquivoDot(arquivoDot,raiz->esquerda);//esquerda (subNo)
    gerarArquivoDot(arquivoDot,raiz->direita); //direita (subNo)
  }
}

void inserirDado(No** raiz, int dado){
    if(*raiz == NULL){
      *raiz = (No*)malloc(sizeof(No));
      (*raiz)->esquerda = NULL; 
      (*raiz)->direita = NULL; 
      (*raiz)->dado = dado; 
    } else {
        if(dado < (*raiz)->dado){ //dado menor? vai pra esquerda
            //percorrer subNo da esquerda
            inserirDado(&(*raiz)->esquerda, dado);
        }
        if(dado > (*raiz)->dado){ //dado maior? vai pra direita
            //percorrer subNo da direita
            inserirDado(&(*raiz)->direita, dado);
        }
    }
}

No *MaiorDireita(No **no){
    if((*no)->direita != NULL) 
       return MaiorDireita(&(*no)->direita);
    else{
       No *aux = *no;
       if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->esquerda;
       else
          *no = NULL;
       return aux;
       }
}

No *MenorEsquerda(No **no){
    if((*no)->esquerda != NULL) 
       return MenorEsquerda(&(*no)->esquerda);
    else{
       No *aux = *no; 
       if((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *no = (*no)->direita;
       else
          *no = NULL;
       return aux;
       }
}

void main(){
  int matriz[7][7],linha, coluna;
  srand(time(NULL));

  printf("\n\n*************** Imprimindo Matriz Aleatória *************** \n\n");
  
  for ( linha=0; linha<7; linha++ ){
    printf("\n");
    for ( coluna=0; coluna<7; coluna++ ){
      matriz[linha][coluna] = rand() % 100;
      printf("| %d |", matriz[linha][coluna]);
    }
  }

  printf("\n\n\n*************** Imprimindo Diagonal Principal Desordenada *************** \n\n");

  int vetor[7], aux = 0;

  for (linha=0; linha<7;linha++){    
    for (coluna=0; coluna<7;coluna++){
      if (coluna == linha){
        vetor[linha] = matriz[linha][coluna];                  
        printf("| %d |", matriz[linha][coluna]);
      }
    }
  }
  
  printf("\n\n\n*************** Imprimindo Diagonal Principal Ordenada *************** \n\n");

  for( linha = 0; linha < 7; linha++ ){
    for( coluna = linha + 1; coluna < 7; coluna++ ){
      if ( vetor[linha] > vetor[coluna] ){
         aux = vetor[linha];
         vetor[linha] = vetor[coluna];
         vetor[coluna] = aux;
      }
    }
  }

  for (linha=0; linha<7;linha++){    
    for (coluna=0; coluna<7;coluna++){
      if (coluna == linha){
        matriz[linha][coluna] = vetor[linha];                 
        printf("| %d |", matriz[linha][coluna]);
      }
    }
  }

  printf("\n\n\n*************** Imprimindo A Matriz com a Diagonal Principal Ordenada *************** \n\n");

    for ( linha=0; linha<7; linha++ ){
    printf("\n");
    for ( coluna=0; coluna<7; coluna++ ){
      printf("| %d |", matriz[linha][coluna]);
    }
  }
  printf("\n\n");
  //----------------------------------ÁRVORE---------------------------------------
  
  printf("\n\n\n*************** Imprimindo A Diagonal Principal Ordenada Na Árvore Binária *************** \n\n\n");

  No* raiz = criarArvore();
  for ( linha = 0; linha < 7; linha++) {
    for ( coluna = 0; coluna < 7; coluna++) {
      if (coluna == linha){
        inserirDado(&raiz, matriz[linha][coluna]); 
      }
    }
  }

  mostrarArvore(raiz);
  printf("\n---------------------------------------------\n\n\n");
  
  FILE* arquivoDot;
  arquivoDot = fopen("arvore.dot", "w");
  fprintf(arquivoDot, "%s", "digraph G {\nsplines=line;\n");
  gerarArquivoDot(&arquivoDot, raiz);
  fprintf(arquivoDot, "%s", "}\n");
  fclose(arquivoDot);

  free(raiz);
  system("dot -Tpng arvore.dot -o arvore.png");
}