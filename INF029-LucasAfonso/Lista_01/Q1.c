#include <stdio.h>

int soma(int n1, int n2){
	
	int soma;
	
	soma = n1 + n2;
	
	return soma;
}

int main(){
	
	int num1, num2, resultado;
	
	printf("Digite abaixo o primeiro numero que deseja somar:\n");
	scanf("%d", &num1);
	printf("Digite abaixo o segundo numero que deseja somar:\n");
	scanf("%d", &num2);
	
	resultado = soma(num1, num2);
	
	printf("\nA soma dos numeros e: %d", resultado);
}