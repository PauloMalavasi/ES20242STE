#include <stdio.h>
#include <string.h>

int main (){
	char text[50];
	int i = 0;
	
	printf("Digite um texto: ");
	gets(text);
	
	i = strlen(text);
	
	printf("%d", i);
	
	return 0;
}
