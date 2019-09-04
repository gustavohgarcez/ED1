#include<stdio.h>
#include<stdlib.h>
#define NOME_TAM 100
#define CPF_TAM 14
#define DATA_TAM 10

typedef struct {
	char nome_alu[NOME_TAM];
	char cpf[CPF_TAM];
	char data_nasc[DATA_TAM];
} Pessoa;

typedef struct {
	char matricula[NOME_TAM];
	Pessoa pessoa;
} Aluno;

typedef struct {
	char nome_disc[NOME_TAM];
} Disciplina;

typedef struct {
	Aluno aluno;
	Disciplina disciplina;
	float nota;
} Nota;

void setPessoa(Pessoa* p, char nome_alu[], char cpf[], char data_nasc[]){
	for(int i = 0; i < NOME_TAM; i++){
		p -> nome_alu[i] = nome_alu[i];
	}
	for(int i = 0; i < CPF_TAM; i++){
		p -> cpf[i] = cpf[i];
	}
	for(int i = 0; i < DATA_TAM; i++){
		p -> data_nasc[i] = data_nasc[i];
	}
}

void setAluno(Aluno* a, char matricula[], Pessoa pessoa){
    a -> pessoa = pessoa;
	for(int i = 0; i < NOME_TAM; i++){
		a -> matricula[i] = matricula[i];
	}
}

void setDisciplina(Disciplina* d, char nome_disc[]){
	for(int i = 0; i < NOME_TAM; i++){
		d->nome_disc[i] = nome_disc[i];
	}
}

void setNota(Nota* n, Aluno aluno, Disciplina disciplina, float nota){
    n -> aluno = aluno;
	n -> disciplina = disciplina;
    n -> nota = nota;
}

void imprimirNota(Nota n){
	printf("| Nome: %s |\n", n.aluno.pessoa.nome_alu);
	printf("| CPF: %s |\n", n.aluno.pessoa.cpf);
	printf("| Data de Nascimento: %s |\n", n.aluno.pessoa.data_nasc);
	printf("| Matrícula: %s| \n", n.aluno.matricula);
	printf("| Disciplina: %s |\n", n.disciplina.nome_disc);
	printf("| Nota: %.2f |\n\n", n.nota);
}

int main(){
    Pessoa p_gustavo;
    Aluno a_gustavo;
    Nota n_gustavo;

    Pessoa p_angelica;
    Aluno a_angelica;
    Nota n_angelica;

    Disciplina EDI;
    Disciplina Redes;

    setPessoa(&p_gustavo, "Gustavo Garcez",  "065.357.671-98", "28/01/3999");
    setAluno(&a_gustavo, "20161070165578", p_gustavo);
    setDisciplina(&EDI, "Estrutura de Dados I");
    setNota(&n_gustavo, a_gustavo, EDI, 7.5);

	setPessoa(&p_angelica, "Angélica Farias",  "065.357.671-98", "28/01/3999");
    setAluno(&a_angelica, "20161070165578", p_angelica);
    setDisciplina(&Redes, "Redes de Computadores");
    setNota(&n_angelica, a_angelica, Redes, 7.5);
    
    imprimirNota(n_gustavo);
	imprimirNota(n_angelica);
	return 0;
}
