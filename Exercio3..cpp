#include <stdio.h>
#include <string.h>

int main (){
	char nome[] = "Paulo ", sobrenome[] = "Malavasi";
	
	strcat(nome, sobrenome);
	
	printf(" %s", nome);
	

	return 0;
}
