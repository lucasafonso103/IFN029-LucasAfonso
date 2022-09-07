#include <stdio.h>

int ler3palavras(char palavra1[31], char palavra2[31], char palavra3[31]){
	
	printf("Digite a palavra abaixo:\n");
	fgets(palavra1, 31, stdin);
	printf("Digite a palavra abaixo:\n");
	fgets(palavra2, 31, stdin);
	printf("Digite a palavra abaixo:\n");
	fgets(palavra3, 31, stdin);
	
	return palavra1[31];
	return palavra2[31];
	return palavra3[31];
	
}

int main(){
	
	char let1[31];
	char let2[31];
	char let3[31];
	char aux1[31], aux2[31], aux3[31];
	int i;
	
	ler3palavras(aux1, aux2, aux3);
	
	for(i = 0; i < 30; i++){
		let1[i] = aux1[i];
		let2[i] = aux2[i];
		let3[i] = aux3[i];
	}
	
	printf("\nA palavra digitada e: %s", let1);
	printf("\nA palavra digitada e: %s", let2);
	printf("\nA palavra digitada e: %s", let3);
	
}