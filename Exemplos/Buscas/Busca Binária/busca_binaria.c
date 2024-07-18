#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale (LC_ALL, "Portuguese, Brazil");
	int v[100];

	int i;
	for(i = 0 ; i < 100 ; i++) v[i] = i+1;
	
	int num = 100;
	
	int comparacoes = 0;
	
	int continuar = 1;
	
	int ini = 0; 
	int fim = 99;
	
	while(continuar == 1){
		comparacoes++;
	
		int pivo = (ini + fim) / 2;
	
		if(v[pivo] == num){
			printf("Elemento encontrado!\n");
			continuar = 0;
		}
		else{
			if(num > v[pivo]){
				ini = pivo + 1;
			}
			else{
				fim = pivo - 1;
			}
		}
		
		if(fim < ini){
			printf("Elemento n�o encontrado!\n");
			continuar = 0;
		}
	}
	
	printf("Compara��es: %d", comparacoes);
	
	return 0;
}
