#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}data;

typedef struct{
	int id;
    char nome[21];
    char sexo;
    char cpf[15];
    data nascimento;
}cliente;

cliente cadastrar_cliente();
int validar_nome(char validar_nome[]);
int validar_sexo(char validar_sexo);
int validar_cpf(char validar_cpf[]);
int validar_data(data nascimento);
int bissexto(int ano);

int main(){

  cliente cadastro;

  cadastro = cadastrar_cliente();
  
  if(cadastro.id <= 0){

  if(cadastro.id == -1){
    printf("Erro no cadastro do nome");
  }
  else if(cadastro.sexo == -2){
    printf("Erro no cadastro do CPF");
  }
}
}
  else{
    printf("\n\nCliente cadastrado com sucesso:\n");
    printf("\nNome do cliente:\n%s", cadastro.nome);
    printf("\nSexo do cliente:\n%c", cadastro.sexo);
    printf("\nCPF do cliente:\n%s", cadastro.cpf);
    printf("\nData de nascimento do cliente:\n%d/%d/%d", cadastro.nascimento.dia, cadastro.nascimento.mes, cadastro.nascimento.ano);
  }
}

cliente cadastrar_cliente(){

  cliente cadastrar;
  int erro;
  cadastrar.id = -1;
  
  char espaco;

  printf("Insira o nome do cliente abaixo:\n");
  gets(cadastrar.nome);
  erro = validar_nome(cadastrar.nome);
  
  if(erro == 1)
  	cadastrar.nome = -1;
  	return cadastrar;
  
  
  else{
  printf("\nInsira o sexo do cliente abaixo:\n");
  scanf("%c", &cadastrar.cpf);
  return cadastrar;
}

  
  printf("\nInsira o cpf do cliente abaixo:\n");
  gets(cadastrar.sexo);
  scanf("%c", &espaco);

  printf("\nInsira o dia de nascimento do cliente abaixo:\n");
  scanf("%d", &cadastrar.nascimento.dia);
  printf("Insira o mes de nascimento do cliente abaixo:\n");
  scanf("%d", &cadastrar.nascimento.mes);
  printf("Insira o ano de nascimento do cliente abaixo:\n");
  scanf("%d", &cadastrar.nascimento.ano);

  return cadastrar;
}

int validar_nome(char validar_nome[]){

  int caracteres = 0;
  int validar = 0;
  int erro = 0;

  while (validar_nome[caracteres] != '\0'){
    caracteres++;
  }

if(caracteres > 21){
    erro = 1;
}

return erro;
}

int validar_sexo(char validar_sexo){

  int erro = 0;

  if (validar_sexo == 'M' || validar_sexo == 'F'){
    erro = 1;
    }

  return erro;
}

int validar_cpf(char validar_cpf[]){

  int caracteres = 0;
  int erro = 0;

  while(validar_cpf[caracteres] != '\0'){
    caracteres++;
  }

  if(caracteres < 14){
    erro = 1;
  }

  return erro;
}

int validar_data(data nascimento){

  if(nascimento.dia < 1 || nascimento.dia > 31){
    printf("Erro no cadastro de data");
  }
  if(nascimento.mes < 1 || nascimento.mes > 12){
    printf("Erro no cadastro de data");
  }
  if(nascimento.ano > 2022){
    printf("Erro no cadastro de data");
  }

  if((nascimento.mes == 4 || nascimento.mes == 6 || nascimento.mes == 9 || nascimento.mes == 11) && nascimento.dia > 30){
    printf("Erro no cadastro de data");
  }

  if(nascimento.mes == 2){
    if(bissexto(nascimento.ano) && nascimento.dia > 29){
      printf("Erro no cadastro de data");
    }
    else if(nascimento.dia > 28){
      printf("Erro no cadastro de data");
    }
  }

  return 1;
}

int bissexto(int ano){

  return 0;
}