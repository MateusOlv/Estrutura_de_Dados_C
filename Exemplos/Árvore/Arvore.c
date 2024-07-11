#include <stdlib.h>
#include <stdio.h>

struct Nodo{
	int valor;
	struct Nodo *esq;
	struct Nodo *dir;
};

typedef struct Nodo nodo;

nodo* create(int valor){
	nodo *n = malloc(sizeof(nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

void imprimir(nodo *n){
	if(n==NULL) return;
	imprimir(n->esq);// se a função 'imprimir' for chamada antes do printf a árvore será exibida em ordem crescente (eixo X)
	printf("%d\n", n->valor);
	//imprimir(n->esq); --> Se a função 'imprimir' for chamada aq a árvore será exibida na ordem de inserção (eixo Y) 
	imprimir(n->dir);
}

void add(nodo *n, int valor){
	if(valor < n->valor){
		if(n->esq == NULL) n->esq = create(valor);
		else add(n->esq, valor);
	} else{
		if(n->dir == NULL) n->dir = create(valor);
		else add(n->dir, valor);
	}
}

void rem(nodo *n, int valor){
	nodo *filho = n;
	nodo *pai;
	
	do{
		pai = filho;
		if(valor < filho->valor) filho = filho->esq;
		else if(valor > filho->valor) filho = filho->dir;
	}while(filho != NULL && filho->valor != valor);
	
	if(filho != NULL){
		if(filho->esq == NULL && filho->dir == NULL){ //Caso 1: Nodo não tem filhos
			if(pai->esq == filho) pai->esq = NULL;
			if(pai->dir == filho) pai->dir = NULL;
		}
		
		if(filho->esq != NULL && filho->dir == NULL){ //Caso 2: Nodo filho tem um filho à esquerda
			if(pai->esq == filho) pai->esq = filho->esq;
			if(pai->dir == filho) pai->dir = filho->esq;
		}
		
		if(filho->esq == NULL && filho->dir != NULL){ //Caso 2: Nodo filho tem um filho à direita
			if(pai->esq == filho) pai->esq = filho->dir;
			if(pai->dir == filho) pai->dir = filho->dir;
		}
		
		if(filho->esq != NULL && filho->dir != NULL){ //Caso 3: Nodo tem dois filhos
			if(filho->esq->dir == NULL){
				filho->valor = filho->esq->valor;
			} else{
				nodo *p = filho->esq;
				nodo *aux = p;
				while(p->dir != NULL){
					aux = p;
					p = p->dir;
				}
				aux->dir = NULL;
				filho->valor = p->valor;
			}
		}
	}	
}

int main(){
	
	nodo *root = create(5);
	
	add(root, 3);
	add(root, 1);
	add(root, 4);
	add(root, 2);
	add(root, 8);
	
	rem(root, 3);
	
	imprimir(root);
	return 0;
}
