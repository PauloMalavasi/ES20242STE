#include <stdio.h>

int main(){
	
	int matriz[3][3];
	int x, y;
	
	for(x = 0; x < 3; x++){
		for(y = 0; y < 3; y++){
			printf("Digite o numero %d - %d: ", x + 1, y + 1);
			scanf("%d", &matriz[x][y]);
		}
	}
	for(x = 0; x < 3; x++){
		printf("%d\n", matriz[x][0]);
}
	printf("\n");
	for(x = 0; x < 3; x++){
		printf("%d\n", matriz[0][x]);
}
	return 0;
}
