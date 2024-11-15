#include <stdio.h>

int main(){
	
	int matriz[4][4];
	int x, y;
	
	for(x = 0; x < 4; x++){
		for(y = 0; y < 4; y++){
			printf("Digite o numero %d - %d: ", x + 1, y + 1);
			scanf("%d", &matriz[x][y]);
		}
	}
	for(x = 0; x < 4; x++){
		printf("%d\n", matriz[x][x]);
}

	return 0;
}
