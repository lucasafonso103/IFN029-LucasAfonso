#include <stdio.h>

typedef struct{
	
	int num1;
	int num2;
	int num3;
	int num4;
} Numeros;

Numeros ler4Numeros();
void imprimirNum(Numeros imprimirnum);

int main(){
	
	Numeros printNum;
	
	printNum = ler4Numeros();
	
	imprimirNum(printNum);
}

Numeros ler4Numeros(){
	
	Numeros numeros;
	
	printf("Digite o numero abaixo:\n");
	scanf("%d", &numeros.num1);
	printf("Digite o numero abaixo:\n");
	scanf("%d", &numeros.num2);
	printf("Digite o numero abaixo:\n");
	scanf("%d", &numeros.num3);
	printf("Digite o numero abaixo:\n");
	scanf("%d", &numeros.num4);
	
	return numeros;
}

void imprimirNum(Numeros print){
	
	printf("O numero e: %d\n", print.num1);
	printf("O numero e: %d\n", print.num2);
	printf("O numero e: %d\n", print.num3);
	printf("O numero e: %d\n", print.num4);
}