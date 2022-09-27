#include <stdio.h>
#include <string.h>

#include "Aluno.h"
#include "Escola.h"
#include "Professor.h"
#include "Disciplina.h"

int menu();

int main(){
	
	Aluno aluno;
	Aluno incluir_aluno[TAM];
    int quantidade_aluno = 0;
    
    Professor professor;
	Professor incluir_professor[TAM];
    int quantidade_professor = 0;
    
    Disciplina disciplina;
    Disciplina incluir_disciplina[TAM];
    int quantidade_disciplina = 0;
	
	int opcao;
	int sair = 0;
	
	while(!sair){
		
		opcao = menu();
		
		switch(opcao){
		
			case 0:{
				printf("Saindo do progama\n");
				sair = 1;
				break;
			}
			case 1:{
				main_aluno(incluir_aluno, quantidade_aluno);
				quantidade_aluno++;
				break;
			}
			case 2:{
				main_professor(incluir_professor, quantidade_professor);
				quantidade_professor++;
				break;
			}
			case 3:{
				main_disciplina(incluir_disciplina, quantidade_disciplina);
				quantidade_disciplina++;
				break;
			}
			default:{
	      	printf("opcao invalida\n");
	      }	
		}
	}
	
	return 1;
}

int menu(){

	int opcao;
	
	printf("MENU ESCOLA\n\n");

	printf("Digite a opcao:\n");
	printf("0 - Sair\n");
	printf("1 - Gerenciar Aluno\n");
	printf("2 - Gerenciar Professor\n");
	printf("3 - Gerenciar Disciplina\n");
	printf("DIGITE ABAIXO A OPCAO:\n");
	scanf("%d",&opcao);

	return opcao;

}