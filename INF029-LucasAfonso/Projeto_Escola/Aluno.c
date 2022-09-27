#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Aluno.h"
#include "Escola.h"

int matricula_aluno();
int menu_aluno();
int inserir_aluno(Aluno incluir_aluno[], int quantidade_aluno);
void listar_alunos(Aluno incluir_aluno[], int quantidade_aluno);
int posicao_aluno(Aluno incluir_aluno[], int quantidade_aluno, int matricula);
int excluir_aluno(Aluno incluir_aluno[], int quantidade_aluno);
int atualizar_aluno(Aluno incluir_aluno[], int quantidade_aluno);

static int matricula_atual = 1000;

int matricula_aluno(){
    matricula_atual++;
    return matricula_atual;
}

int menu_aluno(){
	
	Aluno aluno;

	int opcao;

  printf("\nMENU ALUNO\n\n");
	printf("Digite a opcao:\n");
	printf("0 - Voltar\n");
	printf("1 - Incluir aluno\n");
	printf("2 - Atualizar aluno\n");
	printf("3 - Excluir aluno\n");
	printf("4 - Listar alunos\n");
	printf("DIGITE ABAIXO A OPCAO:\n");
	scanf("%d", &opcao);

	return opcao;

}

int main_aluno(Aluno incluir_aluno[], int quantidade_aluno){
	
	int sair = 0;
	int opcao;
	int retorno;
	
	while(!sair){
		
		opcao = menu_aluno();
		
		switch(opcao){
		
			case 0:{
				sair = 1;
				break;
			}
			case 1:{
				retorno = inserir_aluno(incluir_aluno, quantidade_aluno);
				if(retorno == -1){
                    printf("Cadastro do aluno realizado com sucesso\n");
					quantidade_aluno++;
				}
                else{
                    switch(retorno){
                        case -2:{
                            printf("Erro no cadastro do sexo do aluno");
                            break;
                        }
                    }
                }
            break;
            }
			case 2:{
				retorno = atualizar_aluno(incluir_aluno, quantidade_aluno);
                if(retorno == -3){
                    printf("Aluno não encontrado");
                }
                else if(retorno == -4){
                    printf("Aluno atualizado com sucesso\n");
                }
                else if(retorno == -5){
        	        printf("Novo sexo do aluno invalido\n");
		        }
				break;
			}
			case 3:{
				retorno = excluir_aluno(incluir_aluno, quantidade_aluno);
				if(retorno == -3){
					printf("Aluno nao encontrado");
				}
				else{
					printf("Aluno excluido com sucesso");
					quantidade_aluno--;
				}
				break;
			}
			case 4:{
				listar_alunos(incluir_aluno, quantidade_aluno);
				break;
			}
			default:{
	      	printf("opcao invalida\n");
		}
	}
}
}


int inserir_aluno(Aluno incluir_aluno[], int quantidade_aluno){
	
	printf("\nCADASTRANDO ALUNO\n");
	getchar();
	printf("\nDigite o nome do aluno abaixo:\n");
	fgets(incluir_aluno[quantidade_aluno].nome, 50, stdin);
	size_t ln = strlen(incluir_aluno[quantidade_aluno].nome) - 1;
    if (incluir_aluno[quantidade_aluno].nome[ln] == '\n'){
        incluir_aluno[quantidade_aluno].nome[ln] = '\0';
    }

	
	printf("\nDigite o sexo do aluno abaixo como F ou M:\n");
	scanf("%c", &incluir_aluno[quantidade_aluno].sexo);
    incluir_aluno[quantidade_aluno].sexo = toupper(incluir_aluno[quantidade_aluno].sexo);
    if (incluir_aluno[quantidade_aluno].sexo != 'M' && incluir_aluno[quantidade_aluno].sexo != 'F')
    if (incluir_aluno[quantidade_aluno].sexo != 'M' && incluir_aluno[quantidade_aluno].sexo != 'F'){
          return -2;
    }
	
	printf("\nDigite o dia de nascimento:\n");
    scanf("%d", &incluir_aluno[quantidade_aluno].data_nascimento.dia);
    printf("Digite o mes de nascimento:\n");
    scanf("%d", &incluir_aluno[quantidade_aluno].data_nascimento.mes);
    printf("Digite o ano de nascimento:\n");
    scanf("%d", &incluir_aluno[quantidade_aluno].data_nascimento.ano);
    getchar();
    
    printf("\nDigite o CPF do aluno abaixo:\n");
    fgets(incluir_aluno[quantidade_aluno].cpf, 15, stdin);
    ln = strlen(incluir_aluno[quantidade_aluno].cpf) - 1;
    if (incluir_aluno[quantidade_aluno].cpf[ln] == '\n'){
      incluir_aluno[quantidade_aluno].cpf[ln] = '\0';
    }
        
    printf("\n");
    
    incluir_aluno[quantidade_aluno].matricula = matricula_aluno();
    printf("A matricula do aluno e:\n%d\n\n", incluir_aluno[quantidade_aluno].matricula);
    
    return -1;
}

void listar_alunos(Aluno incluir_aluno[], int quantidade_aluno){
	
	printf("ALUNOS LISTADOS:\n");
	
	int i;
	
	for(i = 0; i < quantidade_aluno; i++){
		printf("\nMatricula do aluno:\n%d", incluir_aluno[i].matricula);
        printf("\nNome do aluno:\n%s", incluir_aluno[i].nome);
        printf("\nSexo do aluno:\n%c", incluir_aluno[i].sexo);
        printf("\nData Nascimento do aluno:\n%d/%d/%d", incluir_aluno[i].data_nascimento.dia, incluir_aluno[i].data_nascimento.mes, incluir_aluno[i].data_nascimento.ano);
        printf("\nCPF do aluno:\n%s\n", incluir_aluno[i].cpf);
        printf("\n");
	}
}

int posicao_aluno(Aluno incluir_aluno[], int quantidade_aluno, int matricula){
	
	int i;
    for (i = 0; i < quantidade_aluno; i++){
        if (incluir_aluno[i].matricula == matricula){
        	return i;
		}
    }
    return -6;

}

int excluir_aluno(Aluno incluir_aluno[], int quantidade_aluno){
	
	listar_alunos(incluir_aluno, quantidade_aluno);
	
	int matricula;
	int posicao;
	int i;
	
	printf("Digite a matricula do aluno:\n");
	scanf("%d", &matricula);
	printf("\n");
	
	posicao = posicao_aluno(incluir_aluno, quantidade_aluno, matricula);
	
	if(posicao == -3){
		printf("Aluno não encontrato");
	}
	else{
		for (i = posicao; i < quantidade_aluno; i++){
            incluir_aluno[i] = incluir_aluno[i + 1];
        }
        return -7;
    }   
}

int atualizar_aluno(Aluno incluir_aluno[], int quantidade_aluno){
	
	listar_alunos(incluir_aluno, quantidade_aluno);
	
	int matricula;
	int posicao;
	int i;
	
	Aluno novo_aluno;
	
	printf("Digite a matricula do aluno:\n");
	scanf("%d", &matricula);
	
	posicao = posicao_aluno(incluir_aluno, quantidade_aluno, matricula);
	
	if(posicao == -6){
		printf("Aluno não encontrato");
	}
	else{
		getchar();
		printf("Digte o novo nome do aluno:\n");
		fgets(novo_aluno.nome, 50, stdin);
		size_t ln = strlen(novo_aluno.nome) - 1;
		if (novo_aluno.nome[ln] == '\n'){
			novo_aluno.nome[ln] = '\0';
		}
		printf("Digite o novo sexo do aluno:\n");
        scanf("%c", &novo_aluno.sexo);
        novo_aluno.sexo = toupper(novo_aluno.sexo);
        if (novo_aluno.sexo != 'M' && novo_aluno.sexo != 'F'){
            return -5;
        }
        printf("\nDigite o dia de nascimento:\n");
        scanf("%d", &novo_aluno.data_nascimento.dia);
        printf("Digite o mês de nascimento:\n");
        scanf("%d", &novo_aluno.data_nascimento.mes);
        printf("Digite o ano de nascimento:\n");
        scanf("%d", &novo_aluno.data_nascimento.ano);
        getchar();
        
        printf("\nDigite o CPF:\n");
        fgets(novo_aluno.cpf, 15, stdin);
        ln = strlen(novo_aluno.cpf) - 1;
        if (novo_aluno.cpf[ln] == '\n'){
        	novo_aluno.cpf[ln] = '\0';
		}

        printf("\n");
        
        novo_aluno.matricula = incluir_aluno[posicao].matricula;
        incluir_aluno[posicao] = novo_aluno;
        
        return -4;
	}
}