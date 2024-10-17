#include <stdio.h>
#include <string.h>

//inverter texto de tras pra frente

int main (){
	
	char text[100], invert[100];
	int x, i = 0;
	
	printf("Digite um texto: ");
	scanf(" %s", text);
	
	int total = strlen(text) - 1;
	
	for(x = total; x >= 0 ; x--){
		invert[i] = text[x];
		i++;
	}	
		printf("%s", invert);
	
	
	return 0;
}
