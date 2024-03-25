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
		printf("%.1f, %.1f", aux_lista->x, aux_lista->y);
		aux_lista = aux_lista->prox;
	}
}

int main(){
	float a , b;
	char parar;
	
	setlocale(LC_ALL, "Portuguese");	
	
	while(parar != 'N' || parar != 'n'){
		printf("Digite dois números:\n");
		scanf("%f", &a);
		fflush(stdin);
		scanf("%f", &b);
		
		imprimir();
		
		printf("Deseja continuar?\nDigite 'N' para parar ou qualquer tecla para continuar!");
		fflush(stdin);
		scanf("%c", &parar);
		
		system("cls");
	}
	
	return 0;
}
