#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Disciplina.h"
#include "Escola.h"

int codigo_disciplina();
int menu_disciplina();
int inserir_disciplina(Disciplina incluir_disciplina[], int quantidade_disciplina);
int posicao_disciplina();

static int codigo = 3000;

int codigo_disciplina(){
    codigo++;
    return codigo;
}

int menu_disciplina(){
	
	Disciplina disciplina;

	int opcao;

  printf("\nMENU DISCIPLINA\n\n");
	printf("Digite a opcao:\n");
	printf("0 - Voltar\n");
	printf("1 - Incluir disciplina\n");
	printf("2 - Editar disciplina\n");
	printf("3 - Excluir disciplina\n");
	printf("4 - Listar disciplina\n");
	printf("5 - Listar disciplina com alunos e o professor\n");
	printf("DIGITE ABAIXO A OPCAO:\n");
	scanf("%d", &opcao);

	return opcao;

}

int main_disciplina(Disciplina incluir_disciplina[], int quantidade_disciplina){
	
	int sair = 0;
	int opcao;
	int retorno_disciplina;
	
	while(!sair){
		
		opcao = menu_disciplina();
		
		switch(opcao){
		
			case 0:{
				sair = 1;
				break;
			}
			case 1:{
				retorno_disciplina = inserir_disciplina(incluir_disciplina, quantidade_disciplina);
				if(retorno_disciplina == -1){
                    printf("Cadastro da disciplina realizado com sucesso\n");
					quantidade_disciplina++;
				}
            break;
            }
			case 2:{
				printf("Editar disciplina");
				break;
			}
			case 3:{
				printf("Excluir disciplina");
				break;
			}
			case 4:{
				printf("Listar disciplina");
				break;
			}
			case 5:{
				printf("Listar disciplina com alunos e o professor");
				break;
			default:{
	      	printf("opcao invalida\n");
		}
	}
}
}
}

int inserir_disciplina(Disciplina incluir_disciplina[], int quantidade_disciplina){
	
	printf("\nCADASTRANDO DISCIPLINA\n");
	getchar();
	printf("\nDigite o nome da disciplina abaixo:\n");
	fgets(incluir_disciplina[quantidade_disciplina].nomeD, 50, stdin);
	size_t ln = strlen(incluir_disciplina[quantidade_disciplina].nomeD) - 1;
    if (incluir_disciplina[quantidade_disciplina].nomeD[ln] == '\n'){
      incluir_disciplina[quantidade_disciplina].nomeD[ln] = '\0';
    }
    
    incluir_disciplina[quantidade_disciplina].codigo = codigo_disciplina();
    printf("\nO codigo da disciplina e:\n%d\n\n", incluir_disciplina[quantidade_disciplina].codigo);
    
    return -1;
}

int posicao_disciplina(Disciplina incluir_disciplina[], int quantidade_disciplina){
	
	int i;
    for (i = 0; i < quantidade_disciplina; i++){
        if (incluir_disciplina[i].codigo == codigo){
        	return -1;
		}
    }
    return -6;

}