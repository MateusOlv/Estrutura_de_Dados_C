#include<stdlib.h>
#include<stdio.h>
#include<locale.h>

int v[10] = {4,8,6,12,34,65,50,10,90,100};

int main(){
	setlocale(LC_ALL, "Portuguese");
	int num = 50;
	int i;
	
	for(i = 0 ; i < 10 ; i++){
		if(v[i] == num) printf("Número encontrado na %dª posição \n", i+1);
	}	
}
