#include <stdio.h>
#include <stdlib.h>

struct Ponto{
	float x;
	float y;	
};

typedef struct Ponto ponto;

int main(){
	ponto *p = (ponto*) malloc(sizeof(ponto));
/* (ponto*) -> Conversão da Struct Ponto para o ponteiro
	malloc -> Aloca dinamicamente na memória Heap
	sizeof -> Define o tamanho
*/
	p->x = 1;
	p->y = 5;
	
	printf("Ponto X = %.2f \nPonto Y = %.2f", p->x, p->y);
	
	return 0;
}
