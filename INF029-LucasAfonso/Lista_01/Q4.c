#include <stdio.h>

int ler3Numeros(int num[2]){
	
	int i;
	
	for(i = 0; i < 3; i++){
		printf("Digite abaixo o numero:\n");
	    scanf("%d", &num[i]);
	}
	
	for(i = 0; i < 2; i++){
	    return num[i];	
	}
}

int main(){
	
	int n[2], nums[2];
	int i;
	
	ler3Numeros(n);
	
	for(i = 0; i <= 2; i++){
		nums[i] = n[i];
		printf("\nOs numeros sao: %d\n", nums[i]);
	}
}