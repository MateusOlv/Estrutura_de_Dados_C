#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
	int senha;
	struct Pessoa *prox;
};

typedef struct Pessoa pessoa;

pessoa *fila;

void add(int senha){
	pessoa *p = (pessoa*) malloc(sizeof(pessoa));
	p->senha = senha;
	p->prox = NULL;

	if(fila == NULL){
		fila = p;	// Se for o primeiro elemento
	} else{
		pessoa *fila_aux = fila;
		while(fila_aux->prox != NULL){ // Se não for o primeiro elemento, a fila será percorrida até achar o último elemento
			fila_aux = fila_aux->prox;
		}
		fila_aux->prox = p; // O prox do último elemento recebe o elemento novo
	}
} 

void rem(){
	if(fila == NULL){
		printf("Fila vazia!");	
	} else {
		fila = fila->prox;
	}
}


void imprime(pessoa *f){
	if(f !=NULL) {
		printf("\nSenha da pessoa: %d", f->senha);
		imprime(f->prox);	
	}
}

int main(){
	add(8);
	add(9);
	add(10);
	add(11);
	
	pessoa *fila_aux = fila;
	imprime(fila_aux);
	
	rem();
	rem();
	
	printf("\n");
	fila_aux = fila;
	imprime(fila_aux);
	
	return 0;
}
