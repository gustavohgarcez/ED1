#include<stdio.h>
#include<stdlib.h>
#define TAM 100

typedef struct {
    char marca[TAM];
    char nacionalidade[TAM];
} Marca;

typedef struct {
    char modelo[TAM];
    float motor;
    Marca marca;
} Carro;

void setMarca(Marca *m, char marca[], char nacionalidade[]){
    for(int i = 0; i < TAM; i++){
        m -> marca[i] = marca[i];
    }
    for (int i = 0; i < TAM; i++){
        m -> nacionalidade[i] = nacionalidade[i];
    }
}

void setCarro(Carro *c, char modelo[], float motor, Marca marca){
    for(int i = 0; i < TAM; i++){
        c -> modelo[i] = modelo[i];
    }
    c -> motor = motor;
    c -> marca = marca;
}

void printCarro(Carro c){
    printf("%s\n", c.modelo);
    printf("%.2f\n", c.motor);
    printf("%s\n", c.marca.marca);
    printf("%s\n", c.marca.nacionalidade);
}

void main(){
    Marca ford, vw;
    setMarca(&ford, "Ford", "EUA");
    setMarca(&vw, "Vw", "Alemanha");
    Carro gol;
    setCarro(&gol, "Gol", 1.0, vw);
    printCarro(gol);
}