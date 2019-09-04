#include<stdio.h>
#include<stdlib.h>
#define NOME_TAM 100
#define CPF_TAM 14
typedef struct {
	char nome[NOME_TAM];
	char cpf[CPF_TAM];
	float peso, altura, imc;
	int idade;
} Pessoa;

void imprimirPessoa(Pessoa p){
	printf("| Nome: %s |\n| CPF: %s |\n| Idade: %d |\n| Peso: %.2f| \n| Altura: %.2f |\n| IMC: %.2f |\n", p.nome, p.cpf, p.idade, p.peso, p.altura, p.imc);
}

void setPessoa(Pessoa* p, char nome[], char cpf[], int idade, float peso, float altura, float imc){
	for(int i = 0; i < NOME_TAM; i++){
		p->nome[i] = nome[i];
	}
	for(int i = 0; i < CPF_TAM; i++){
		p->cpf[i] = cpf[i];
	}
	(*p).idade = idade;
	p -> peso = peso;
	p -> altura = altura;
	imc = peso / (altura * altura);
	p -> imc = imc; 

}
int main(){
	Pessoa pessoa01;
	char nome[NOME_TAM] = "Otário";
	char cpf[CPF_TAM] = "111.111.111-00";
	float imc;
	setPessoa(&pessoa01, nome, cpf, 20, 72, 1.70, imc);
	imprimirPessoa(pessoa01);
	return 0;
}
