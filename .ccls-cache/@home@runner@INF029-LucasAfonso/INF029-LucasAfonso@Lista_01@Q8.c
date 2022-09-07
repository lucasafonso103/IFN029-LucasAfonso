#include <stdio.h>

int cadastrarCliente(char nome[31], char dataNascimento[12], char cpf[17], char sexo[2]){
	
	printf("Digite o nome abaixo:\n");
	fgets(nome, 31, stdin);
	printf("Digite a data de nascimento abaixo:\n");
	fgets(dataNascimento, 12, stdin);
	printf("Digite o cpf abaixo:\n");
	fgets(cpf, 17, stdin);
	printf("Digite o sexo abaixo:\n");
	fgets(sexo, 2, stdin);
	
	return nome[31];
	return dataNascimento[12];
	return cpf[17];
	return sexo[2];
	
}

int main(){
	
	char nom[31];
	char dat[12];
	char cpf[17];
	char sex[2];
	char aux1[31], aux2[12], aux3[17], aux4[2];
	int i;
	
	cadastrarCliente(aux1, aux2, aux3, aux4);
	
	for(i = 0; i < 30; i++){
		nom[i] = aux1[i];
		dat[i] = aux2[i];
		cpf[i] = aux3[i];
		sex[i] = aux4[i];
	}
	
	printf("\nO nome do cliente e:\n%s", nom);
	printf("\nA data de nascimento do cliente e:\n%s", dat);
	printf("\nO CPF do cliente e:\n%s", cpf);
	printf("\nO sexo do cliente e:\n%s", sex);
	
}