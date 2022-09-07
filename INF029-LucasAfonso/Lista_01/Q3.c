#include <stdio.h>

int fatorial(int n){
	
	int fat, i;
	
	if(n < 0){
		return 1;
	}
	
	for(fat = 1; n > 1; n = n - 1){
    fat = fat * n;
}
    
    return fat;
}

int main(){
	
	int num, resultado;
	
	printf("Digite o numero abaixo:\n");
	scanf("%d", &num);
	
	resultado = fatorial(num);
	
	if(resultado == 1){
		printf("Nao e possivel realizar o fatorial");
	}
	
	else{
	printf("O fatorial é: %d", resultado);
}
}
