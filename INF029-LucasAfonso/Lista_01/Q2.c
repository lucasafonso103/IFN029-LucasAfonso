#include <stdio.h>

int subtrai(int n1, int n2, int n3){
	
	int subtrai;
	
	subtrai = n1 - n2 - n2;
	
	return subtrai;
}

int main(){
	
	int num1, num2, num3, resultado;
	
	printf("Digite o primeiro numero abaixo:\n");
	scanf("%d", &num1);
	printf("Digite o segundo numero abaixo:\n");
	scanf("%d", &num2);
	printf("Digite o terceiro numero abaixo:\n");
	scanf("%d", &num3);
	
	resultado = subtrai(num1, num2, num3);
	
	printf("A subtracao e: %d", resultado);
}