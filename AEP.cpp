#include <stdio.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <locale.h>

//AEP 11/11/2024

//Inclusão de novos Usuários
//Alteração de Usuários
//Exclusão de Usuários 
//Listagem de Usuários

	char nomeUsuario[50], senhaUsuario[75];
	
//Criptografia
	int y;
void criptografia(char *crip){
	for(y = 0; y < strlen(crip); y++){
		crip[y] = crip[y] - 5;
	}
}

//Adicionar

void incluirUsuario(){
	FILE *arquivo;
	arquivo = fopen("PastaUsuarios.txt", "a");
	
	if(arquivo == NULL){
		printf("Erro no Arquivo!");
		return ;
	}
	printf("Digite seu nome: ");
	scanf("%s", nomeUsuario);

	printf("A senha deve conter\n- Minímo de 8 digitos\n- Com letras Maisculas e Minusculas\n- Números\n- E com pelo menos 1 caracter especial\n");
	
	int senhaValida = 0;
	char senhatemp[75];
	
	while (!senhaValida) {
        printf("Digite sua senha: ");
        scanf("%s", senhatemp);
        
        int cmai = 0, cmin = 0, cnum = 0, cespc = 0, compr = 0;
        compr = strlen(senhatemp);
        
        if (compr < 8) {
            continue;
        }
        
        for (int i = 0; i < compr; i++) {
            if (isupper(senhatemp[i])) cmai = 1;
            else if (islower(senhatemp[i])) cmin = 1;
            else if (isdigit(senhatemp[i])) cnum = 1;
            else if (ispunct(senhatemp[i])) cespc = 1;
        }
        
        if (cmai && cmin && cnum && cespc) {
            senhaValida = 1;
            strcpy(senhaUsuario, senhatemp);
        } else {
            printf("Formato inválido!\n");
        }
    }
		
	criptografia(senhaUsuario);
	
	fprintf(arquivo, "%s, %s\n", nomeUsuario, senhaUsuario);
	fclose(arquivo);
	
	printf("Usuario salvo com Sucesso!");
	
}

//Listar

void listarUsuarios(){
	FILE *arquivo;
	arquivo = fopen("PastaUsuarios.txt", "r");
	
	if(arquivo == NULL){
		printf("Erro no Arquivo!");
		return ;
	}
	char linha[256];
	
	while (fgets(linha, sizeof(linha), arquivo) != NULL){
		char *nome = strtok(linha, ",");
		
		if(nome != NULL){
			
        printf("%s\n", linha);
        
		}

	}
	fclose(arquivo);

}

//Excluir
void excluirUsuario(){
	FILE *arquivo, *arqTemp;
	arquivo = fopen("PastaUsuarios.txt", "r");
	arqTemp = fopen("ArqTempExcUsu.txt", "w");
	
	if(arquivo == NULL || arqTemp == NULL){
		printf("Erro no Arquivo!");
		return;
	}
	
	char deletUsuario[40];
	char linha_2[256];        
    char nomeUsuario[40];   
    int user;
	
	printf("Digite o nome do usuario que deseja excluir: ");
	scanf("%s", deletUsuario);
	
	while(fgets(linha_2, sizeof(linha_2), arquivo) != NULL){
		 sscanf(linha_2, "%[^,]", nomeUsuario);
		
		if(strcmp(nomeUsuario, deletUsuario) != 0){
            fprintf(arqTemp, "%s", linha_2);
        } else{
           	user = 1;  
        }
	}
	
	fclose(arquivo);
    fclose(arqTemp);
	
	if (user){
        remove("PastaUsuarios.txt");
        rename("ArqTempExcUsu.txt", "PastaUsuarios.txt");  
        printf("Usuário '%s' foi excluído!", deletUsuario);
    } else{
        remove("ArqTempExcUsu.txt");
        printf("Usuário '%s' não encontrado", deletUsuario);
    }
}

//Alterar Usuarios

void alterarUsuario() {
    FILE *arquivo, *arqTemp;
    arquivo = fopen("PastaUsuarios.txt", "r");
    arqTemp = fopen("ArqAltUsuaios.txt", "w");
    
    if (arquivo == NULL || arqTemp == NULL) {
        printf("Erro no Arquivo!");
        return;
    }
    
    char altUsuario[40];
    char linha_3[256];
    int user = 0;
    
    printf("Digite o nome do usuário que deseja alterar: ");
    scanf("%s", altUsuario);
    
    while (fgets(linha_3, sizeof(linha_3), arquivo) != NULL){
    	
        char nAtual[50], sAtual[75];
        sscanf(linha_3, "%[^,], %s", nAtual, sAtual);
        
        if (strcmp(nAtual, altUsuario) != 0){
            fprintf(arqTemp, linha_3); 
        } else {
            user = 1;
            printf("Digite o novo nome: ");
            scanf("%s", nomeUsuario);
            
            printf("Digite a nova senha: ");
            char newSenha[75];
            scanf("%s", newSenha);
            
            criptografia(newSenha);
            
            fprintf(arqTemp, "%s, %s\n", nomeUsuario, newSenha);
        }
    }
    
    fclose(arquivo);
    fclose(arqTemp);
    
    if (user) {
        remove("PastaUsuarios.txt");
        rename("ArqAltUsuaios.txt", "PastaUsuarios.txt");  
        printf("Usuário %s alterado!\n", altUsuario);
    } else {
        remove("ArqAltUsuaios.txt");
        printf("%s não encontrado !\n", altUsuario);
    }
}

	

int main() {
	system("color 8");
	setlocale(LC_ALL, "Portuguese");
	
    int op = 0;

    do {
        printf("\n1 - Incluir Usuario\n2 - Listar Usuarios\n3 - Alterar Usuario\n4 - Excluir Usuario\n5 - Fechar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                incluirUsuario();
                break;
            case 2:
                listarUsuarios();
                break;
            case 3:
               alterarUsuario();
                break;
            case 4:
                excluirUsuario();
                break;
            case 5:
                printf("...");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (op != 5);
	
    return 0;
}

