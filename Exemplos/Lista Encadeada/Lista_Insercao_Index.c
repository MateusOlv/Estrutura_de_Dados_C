#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct Ponto{
	float x;
	float y;
	struct Ponto *prox; // Aponta para a próxima struct 
};

typedef struct Ponto ponto;

ponto *lista_pontos; // Aponta para o primeiro elemento da lista 

int lenght = 0; // Tamanho da lista

void addIndex(float x, float y, int index){
	ponto *p = (ponto*) malloc(sizeof(ponto));
	p->x = x;
	p->y = y;
	
	if(index > lenght){ // Garante que a posição informada não ultrapasse o tamanho da lista
		printf("Posição inválida!!"); 
	} 
	else{
		if(index == 0){ // Inserção na 1ª posição
			p->prox = lista_pontos; // Passa o primeiro elemento para a próxima posição 
			lista_pontos = p; // Novo elemento passa a ser o 1º
		}
		else{
			ponto *lista_aux = lista_pontos; // Lista auxiliar para não perder a referêcia do primeiro elemento
			int i = 0;
			while(i != index-1){ // Vai até o elemento da posição anterior para que ele possa apontar para o novo elemento 
				lista_aux = lista_aux->prox;
				i++;
			}
			p->prox = lista_aux->prox; // Aponta para o antigo elemento da posição que reberá a nova struct
			lista_aux->prox = p; // Elemento anterior passa a apontar para o novo elemento
		}
		lenght++; // Incrementa a variável que corresponde ao tamanho da lista 
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
	
	addIndex(1,4,0);
	addIndex(3,9,1);
	addIndex(7,2,2);
	addIndex(4,5,1);
	addIndex(12,17,0);
	
		
	ponto *aux_lista = lista_pontos;
	imprimir(aux_lista);
	
	return 0;
}
