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

int main(){
	
	nodo *root = create(5);
	
	add(root, 2);
	add(root, 1);
	add(root, 4);
	add(root, 8);
	
	
	imprimir(root);
	return 0;
}
