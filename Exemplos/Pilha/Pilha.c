#include <stdio.h>
#include <stdlib.h>

struct Prato{
	char cor;
	struct Prato *prox;
};

typedef struct Prato prato;

prato *pilha;

void add(char cor){
	prato *p = (prato*) malloc(sizeof(prato));
	p->cor = cor;
	p->prox = pilha; // Aponta o novo elemento para o primeiro elemento da fila
	pilha = p; // O novo elemento se torna o primeiro
}

void rem(){
	if(pilha == NULL){
		printf("Pilha vazia!");
	} else pilha = pilha->prox; 
}

void imprime(prato *p){
	if(p != NULL){
		printf("Cor do prato: %c\n", p->cor);
		imprime(p->prox);
	}
}

int main(){
	
	add('b');
	add('g');
	add('r');
	add('p');
	
	prato *pilhaAux = pilha;
	imprime(pilhaAux);
	
	rem(pilha);
	
	printf("-----------------------\n");
	pilhaAux = pilha;
	imprime(pilhaAux);
	
	return 0;
}
