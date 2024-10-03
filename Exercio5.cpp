#include <stdio.h>
  int main(){
  	float alt,med;
  	int alu;
  	printf("Digite a quantidade de alunos da sala: ");
  	scanf("%d", &alu);
  	
  	for (int c = 1; c <= alu; c++){
  		printf("Digite a altura dos alunos: ");
  		scanf("%f", &alt);
  		med += alt;
	  }
  	printf("A media de altura da sala e: %.2f", med/alu);
  	
  	return 0;
 }
