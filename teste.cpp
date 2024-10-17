#include <stdio.h>
#include <string.h>

int main(){
	
	char mens[50], mensAlter[50];
	int i, t;
	printf("Digite uma frase: ");
	scanf(" %s", mens);
	
	t = strlen(mens);
	for(i = 0; i <= t; i++){
		
		char carac = mens[i];
		
		if(carac == 'a' || carac == 'A'){
			mensAlter[i] = 'w';
		}
		if(carac == 'e' || carac == 'E'){
			mensAlter[i] = 't';
	    }
	    if(carac == 'i' || carac == 'I'){
			mensAlter[i] = 'z';
	    }
	    if(carac == 'o' || carac == 'O'){
			mensAlter[i] = 'x';
	    }
	    if(carac == 'u' || carac == 'U'){
			mensAlter[i] = 'y';
	    }
	}
	    printf(" %s", mensAlter);
	    
	    return 0;
		
	}
	
