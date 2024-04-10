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

void addFirst (float x, float y){
	ponto *p = (ponto*) malloc(sizeof(ponto));
	p->x = x;
	p->y = y;
	p->prox = lista_pontos;
	lista_pontos = p;
}

void addLast (float x, float y){
	ponto *p = (ponto*) malloc(sizeof(ponto));
	p->x = x;
	p->y = y;
	p->prox = NULL;
	if(lista_pontos == NULL){
		lista_pontos = p;
	} else{
		ponto *lista_aux = lista_pontos;
		while(lista_aux->prox != NULL){
			lista_aux = lista_aux->prox;
		}
		lista_aux->prox = p;
	}
}

void imprimir (ponto *p){
	if(p != NULL) {
		printf("Ponto(x = %.1f)(y = %.1f)\n", p->x, p->y);
		imprimir(p->prox);
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");	
	
	addLast(4,3);
	addLast(9,8);
	addFirst(2, 8);
	addFirst(3, 6);
	
	ponto *aux_lista = lista_pontos;
	imprimir(aux_lista);
	
	return 0;
}
