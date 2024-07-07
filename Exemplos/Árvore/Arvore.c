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

int main(){
	
	nodo *nodo5 = create(5);
	nodo *nodo2 = create(2);
	nodo *nodo1 = create(1);
	nodo *nodo8 = create(8);
	nodo *nodo4 = create(4);
	
	nodo5->esq = nodo2;
	nodo2->esq = nodo1;
	nodo5->dir = nodo8;
	nodo2->dir = nodo4;
	
	imprimir(nodo5);
	return 0;
}
