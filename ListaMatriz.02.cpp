#include <stdio.h>

int main(){
	
	char nome[10][50];
	char sobrenome[10][50];
	int x, y;
	
	for(x = 0; x < 10; x++){
		printf("Digite o %d nome: ", x + 1);
		gets(nome[x]);
	}
	for(x = 0; x < 10; x++){
		printf("Digite o %d sobrenome: ", x + 1);
		gets(sobrenome[x]);
	}
	printf("\n");
	
	for(x = 0; x < 10; x++){
		printf("%s %s\n", nome[x], sobrenome[x]);
		}
	
	return 0;
}
