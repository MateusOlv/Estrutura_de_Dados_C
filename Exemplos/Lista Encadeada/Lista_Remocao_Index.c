#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct Ponto{
	float x;
	float y;
	struct Ponto *prox; // Aponta para a pr�xima struct 
};

typedef struct Ponto ponto;

ponto *lista_pontos; // Aponta para o primeiro elemento da lista 

int length = 0; // Tamanho da lista

void addIndex(float x, float y, int index){
	ponto *p = (ponto*) malloc(sizeof(ponto));
	p->x = x;
	p->y = y;
	
	if(index > length){ // Garante que a posi��o informada n�o ultrapasse o tamanho da lista
		printf("Posi��o inv�lida!!\n"); 
	} 
	else{
		if(index == 0){ // Inser��o na 1� posi��o
			p->prox = lista_pontos; // Passa o primeiro elemento para a pr�xima posi��o 
			lista_pontos = p; // Novo elemento passa a ser o 1�
		}
		else{
			ponto *lista_aux = lista_pontos; // Lista auxiliar para n�o perder a refer�cia do primeiro elemento
			int i = 0;
			while(i != index-1){ // Vai at� o elemento da posi��o anterior para que ele possa apontar para o novo elemento 
				lista_aux = lista_aux->prox;
				i++;
			}
			p->prox = lista_aux->prox; // Aponta para o antigo elemento da posi��o que reber� a nova struct
			lista_aux->prox = p; // Elemento anterior passa a apontar para o novo elemento
		}
		length++; // Incrementa a vari�vel que corresponde ao tamanho da lista 
	}
}

void removeIndex(int index){
	if(index > length || length == 0){
		printf("Posi��o inv�lida ou lista vazia!\n");
	} else{
		if(index == 0){
			lista_pontos = lista_pontos->prox; // Se o index for o elemento da primeira posi��o, lista_pontos apontar� para o seu pr�prio prox, que � o segundo elemento  
		} else{
			ponto *lista_aux = lista_pontos; // Lista auxiliar
			int i = 0;
			while(i != index-1){ // Percorre a lista at� chegar um elemento antes do index
				lista_aux = lista_aux->prox;
				i++;
			}
			lista_aux->prox = lista_aux->prox->prox; // Faz o elemento anterior ao index apontar para o elemento posterior ao index
		}
		length--;
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
	
	removeIndex(0);
	removeIndex(1);
	
		
	ponto *aux_lista = lista_pontos;
	imprimir(aux_lista);
	
	return 0;
}
