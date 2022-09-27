#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Professor.h"
#include "Escola.h"

int matricula_professor();
int menu_professor();
int inserir_professor(Professor incluir_professor[], int quantidade_professor);
void listar_professores(Professor incluir_professor[], int quantidade_professor);
int posicao_professor(Professor incluir_professor[], int quantidade_professor, int matricula_professor);
int excluir_professor(Professor incluir_professor[], int quantidade_professor);
int atualizar_professor(Professor incluir_professor[], int quantidade_professor);

static int matricula_atual_professor = 2000;

int matricula_professor(){
    matricula_atual_professor++;
    return matricula_atual_professor;
}

int menu_professor(){
	
	Professor professor;

	int opcao;

  printf("\nMENU PROFESSOR\n\n");
	printf("Digite a opcao:\n");
	printf("0 - Voltar\n");
	printf("1 - Incluir professor\n");
	printf("2 - Atualizar professor\n");
	printf("3 - Excluir professor\n");
	printf("4 - Listar professor\n");
	printf("DIGITE ABAIXO A OPCAO:\n");
	scanf("%d", &opcao);

	return opcao;

}

int main_professor(Professor incluir_professor[], int quantidade_professor){
	
	int sair = 0;
	int opcao;
	int retorno_professor;
	
	while(!sair){
		
		opcao = menu_professor();
		
		switch(opcao){
		
			case 0:{
				sair = 1;
				break;
			}
			case 1:{
				retorno_professor = inserir_professor(incluir_professor, quantidade_professor);
				if(retorno_professor == -1){
                    printf("Cadastro do professor realizado com sucesso\n");
					quantidade_professor++;
				}
                else{
                    switch(retorno_professor){
                        case -2:{
                            printf("Erro no cadastro do sexo do professor");
                            break;
                        }
                    }
                }
            break;
            }
			case 2:{
				retorno_professor = atualizar_professor(incluir_professor, quantidade_professor);
                if(retorno_professor == -3){
                    printf("Professor não encontrado");
                }
                else if(retorno_professor == -4){
                    printf("Professor atualizado com sucesso\n");
                }
                else if(retorno_professor == -5){
        	        printf("Novo sexo do professor invalido\n");
		        }
				break;
			}
			case 3:{
				retorno_professor = excluir_professor(incluir_professor, quantidade_professor);
				if(retorno_professor == -3){
					printf("Professor nao encontrado");
				}
				else{
					printf("Professor excluido com sucesso");
					quantidade_professor--;
				}
				break;
			}
			case 4:{
				listar_professores(incluir_professor, quantidade_professor);
				break;
			}
			default:{
	      	printf("opcao invalida\n");
		}
	}
}
}


int inserir_professor(Professor incluir_professor[], int quantidade_professor){
	
	printf("\nCADASTRANDO PROFESSOR\n");
	getchar();
	printf("\nDigite o nome do professor abaixo:\n");
	fgets(incluir_professor[quantidade_professor].nome_professor, 50, stdin);
	size_t ln = strlen(incluir_professor[quantidade_professor].nome_professor) - 1;
    if (incluir_professor[quantidade_professor].nome_professor[ln] == '\n'){
        incluir_professor[quantidade_professor].nome_professor[ln] = '\0';
    }

	
	printf("\nDigite o sexo do professor abaixo como F ou M:\n");
	scanf("%c", &incluir_professor[quantidade_professor].sexo_professor);
    incluir_professor[quantidade_professor].sexo_professor = toupper(incluir_professor[quantidade_professor].sexo_professor);
    if (incluir_professor[quantidade_professor].sexo_professor != 'M' && incluir_professor[quantidade_professor].sexo_professor != 'F')
    if (incluir_professor[quantidade_professor].sexo_professor != 'M' && incluir_professor[quantidade_professor].sexo_professor != 'F'){
          return -2;
    }
	
	printf("\nDigite o dia de nascimento:\n");
    scanf("%d", &incluir_professor[quantidade_professor].data_nascimento_professor.diaP);
    printf("Digite o mes de nascimento:\n");
    scanf("%d", &incluir_professor[quantidade_professor].data_nascimento_professor.mesP);
    printf("Digite o ano de nascimento:\n");
    scanf("%d", &incluir_professor[quantidade_professor].data_nascimento_professor.anoP);
    getchar();
    
    printf("\nDigite o CPF do professor abaixo:\n");
    fgets(incluir_professor[quantidade_professor].cpf_professor, 15, stdin);
    ln = strlen(incluir_professor[quantidade_professor].cpf_professor) - 1;
    if (incluir_professor[quantidade_professor].cpf_professor[ln] == '\n'){
      incluir_professor[quantidade_professor].cpf_professor[ln] = '\0';
    }
        
    printf("\n");
    
    incluir_professor[quantidade_professor].matricula_professor = matricula_professor();
    printf("A matricula do professor e:\n%d\n\n", incluir_professor[quantidade_professor].matricula_professor);
    
    return -1;
}

void listar_professores(Professor incluir_professor[], int quantidade_professor){
	
	printf("PROFESSORES LISTADOS:\n");
	
	int i;
	
	for(i = 0; i < quantidade_professor; i++){
		printf("\nMatricula do professor:\n%d", incluir_professor[i].matricula_professor);
        printf("\nNome do professor:\n%s", incluir_professor[i].nome_professor);
        printf("\nSexo do professor:\n%c", incluir_professor[i].sexo_professor);
        printf("\nData Nascimento do professor:\n%d/%d/%d", incluir_professor[i].data_nascimento_professor.diaP, incluir_professor[i].data_nascimento_professor.mesP, incluir_professor[i].data_nascimento_professor.anoP);
        printf("\nCPF do professor:\n%s\n", incluir_professor[i].cpf_professor);
        printf("\n");
	}
}

int posicao_professor(Professor incluir_professor[], int quantidade_professor, int matricula_professor){
	
	int i;
    for (i = 0; i < quantidade_professor; i++){
        if (incluir_professor[i].matricula_professor == matricula_professor){
        	return i;
		}
    }
    return -6;

}

int excluir_professor(Professor incluir_professor[], int quantidade_professor){
	
	listar_professores(incluir_professor, quantidade_professor);
	
	int matricula_professor;
	int posicao;
	int i;
	
	printf("Digite a matricula do professor:\n");
	scanf("%d", &matricula_professor);
	printf("\n");
	
	posicao = posicao_professor(incluir_professor, quantidade_professor, matricula_professor);
	
	if(posicao == -3){
		printf("Professor não encontrato");
	}
	else{
		for (i = posicao; i < quantidade_professor; i++){
            incluir_professor[i] = incluir_professor[i + 1];
        }
        return -7;
    }   
}

int atualizar_professor(Professor incluir_professor[], int quantidade_professor){
	
	listar_professores(incluir_professor, quantidade_professor);
	
	int matricula_professor;
	int posicao;
	int i;
	
	Professor novo_professor;
	
	printf("Digite a matricula do professor:\n");
	scanf("%d", &matricula_professor);
	
	posicao = posicao_professor(incluir_professor, quantidade_professor, matricula_professor);
	
	if(posicao == -6){
		printf("Professor não encontrato");
	}
	else{
		getchar();
		printf("Digte o novo nome do professor:\n");
		fgets(novo_professor.nome_professor, 50, stdin);
		size_t ln = strlen(novo_professor.nome_professor) - 1;
		if (novo_professor.nome_professor[ln] == '\n'){
			novo_professor.nome_professor[ln] = '\0';
		}
		printf("Digite o novo sexo do professor:\n");
        scanf("%c", &novo_professor.sexo_professor);
        novo_professor.sexo_professor = toupper(novo_professor.sexo_professor);
        if (novo_professor.sexo_professor != 'M' && novo_professor.sexo_professor != 'F'){
            return -5;
        }
        printf("\nDigite o dia de nascimento:\n");
        scanf("%d", &novo_professor.data_nascimento_professor.diaP);
        printf("Digite o mês de nascimento:\n");
        scanf("%d", &novo_professor.data_nascimento_professor.mesP);
        printf("Digite o ano de nascimento:\n");
        scanf("%d", &novo_professor.data_nascimento_professor.anoP);
        getchar();
        
        printf("\nDigite o CPF:\n");
        fgets(novo_professor.cpf_professor, 15, stdin);
        ln = strlen(novo_professor.cpf_professor) - 1;
        if (novo_professor.cpf_professor[ln] == '\n'){
        	novo_professor.cpf_professor[ln] = '\0';
		}

        printf("\n");
        
        novo_professor.matricula_professor = incluir_professor[posicao].matricula_professor;
        incluir_professor[posicao] = novo_professor;
        
        return -4;
	}
}