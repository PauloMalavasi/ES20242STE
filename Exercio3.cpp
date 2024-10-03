#include <stdio.h>
 int main(){
 	float x, med;
 	int cont = 0;
 	
 	do{
 		printf("Digite um numero: ");
 		scanf("%f", &x);
 		med += x;
 		cont++;
	} while (cont < 5);
 	    printf("A media e : %.2f", med/5);
    return 0;
 }
