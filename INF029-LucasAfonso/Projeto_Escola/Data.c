#include "Aluno.h"
#include "Professor.h"

int validar_data(Data data_nascimento, int quantidade_aluno);
int validar_data_professor(Data_professor data_nascimento_professor);

int validar_data(Data data_nascimento, int incluir_aluno, int quantidade_aluno){

  if(data_nascimento.dia[quantidade_aluno] < 1 || data_nascimento[quantidade_aluno].dia > 31){
    printf("Erro no cadastro de data");
  }
  if(data_nascimento[quantidade_aluno].mes < 1 || data_nascimento[quantidade_aluno].mes > 12){
    printf("Erro no cadastro de data");
  }
  if(data_nascimento.ano[quantidade_aluno] > 2022){
    printf("Erro no cadastro de data");
  }

  if((data_nascimento[quantidade_aluno].mes == 4 || data_nascimento[quantidade_aluno].mes == 6 || data_nascimento[quantidade_aluno].mes == 9 || data_nascimento[quantidade_aluno].mes == 11) && data_nascimento[quantidade_aluno].dia > 30){
    printf("Erro no cadastro de data");
  }

  if(data_nascimento[quantidade_aluno].mes == 2){
    if(bissexto(data_nascimento[quantidade_aluno].ano) && data_nascimento[quantidade_aluno].dia > 29){
      printf("Erro no cadastro de data");
    }
    else if(data_nascimento[quantidade_aluno].dia > 28){
      printf("Erro no cadastro de data");
    }
  }

  return 1;
}

int validar_data_professor(Data_professor data_nascimento_professor){
	
	if(data_nascimento_professor.diaP < 1 || data_nascimento_professor.diaP > 31){
    printf("Erro no cadastro de data");
  }
  if(data_nascimento_professor.mesP < 1 || data_nascimento_professor.mesP > 12){
    printf("Erro no cadastro de data");
  }
  if(data_nascimento_professor.anoP > 2022){
    printf("Erro no cadastro de data");
  }

  if((data_nascimento_professor.mesP == 4 || data_nascimento_professor.mesP == 6 || data_nascimento_professor.mesP == 9 || data_nascimento_professor.mesP == 11) && data_nascimento_professor.diaP > 30){
    printf("Erro no cadastro de data");
  }

  if(data_nascimento_professor.mesP == 2){
    if(bissexto(data_nascimento_professor.anoP) && data_nascimento_professor.diaP > 29){
      printf("Erro no cadastro de data");
    }
    else if(data_nascimento_professor.diaP > 28){
      printf("Erro no cadastro de data");
    }
  }

  return 2;
}

int bissexto(int ano){

  return 0;
}