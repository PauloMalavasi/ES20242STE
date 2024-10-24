#include <stdio.h>
#include <string.h>

int main (){
	
	
	char nome[50], snome[50];
	
	printf("Digite o nome: ");
	gets(nome);
	printf("Digite o segundo nome: ");
	gets(snome);
	

	if(strcmp(nome, snome) < 0){
		printf("%s %s", nome, snome);
	} else{
		printf("%s %s", snome, nome);
	}
	
	
	
	return 0;
}
