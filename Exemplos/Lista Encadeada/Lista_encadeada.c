#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

struct Ponto{
	float x;
	float y;
	struct Ponto *prox; // Aponta para a próxima struct 
};

typedef struct Ponto ponto;

ponto *lista_pontos; // Aponta para o primeiro elemento da lista 

void add (float x, float y){
	ponto *p = (ponto*) malloc(sizeof(ponto));
	p->x = x;
	p->y = y;
	p->prox = lista_pontos;
	lista_pontos = p;
}

void imprimir (){
	ponto *aux_lista = lista_pontos;
	while(aux_lista != NULL) {
		printf("\n%.1f - %.1f", aux_lista->x, aux_lista->y);
		aux_lista = aux_lista->prox;
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");	
	
	add(2, 8);
	add(3, 6);
	add(5, 1);
	add(7, 1);

	imprimir();
	
	return 0;
}
