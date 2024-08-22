#include <stdio.h>
double soma(double n1,double n2);
double sub(double n1,double n2);
double mult(double n1,double n2);
double div(double n1,double n2);
double med(double n1,double n2);
int main (){
	double valor1, valor2;
	char op;
	printf("Escolha uma operacao:\n+ adicao\n- subtracao\n/ divsao\n* multiplicacao\nM a media da soma de 2 numeros\n");
	scanf("%c",&op);
	printf("Digite o primeiro numero: ");
	scanf("%lf",&valor1);
	printf("Digite o segundo numero: ");
	scanf("%lf",&valor2);
	if(op == '+'){
		printf(" soma é: %.1f",soma(valor1,valor2));
	}else if(op == '-'){
		printf("A subtracacao é: %.1f",sub(valor1,valor2));
	}else if(op == '/'){
		printf("A divisao é: %.1f",div(valor1,valor2));
	}else if(op == '*'){
		printf("A multiplicacao é: %.1f",mult(valor1,valor2));
	}else if(op == 'M'){
		printf("A media é: %.1f",med(valor1,valor2));
	}
	return 0;
}  
double sub(double n1,double n2){
	 
	return n1 - n2;
}
double soma(double n1,double n2){
	
	return n1 + n2;
	
}
double mult(double n1,double n2){
	
	  return n1 * n2;
}
double div(double n1,double n2){
	
	  return n1 / n2;
}
double med(double n1,double n2){
	
	  return (n1 + n2)/2;
}
