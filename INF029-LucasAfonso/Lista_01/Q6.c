#include <stdio.h>

int ler3letras(char letras[2]){
	
	int i;
	
	for(i = 0; i < 3; i++){
		printf("Digite abaixo a letra:\n");
	    scanf("%s", &letras[i]);
	}
	
	for(i = 0; i < 3; i++){
		return letras[i];
	}
}

int main(){
	
	char let[2];
	char aux[2];
	int i;
	
	ler3letras(aux);
	
	for(i = 0; i < 3; i++){
		let[i] = aux[i];
		printf("\nLetra digitada:\n%c", let[i]);
	}
}