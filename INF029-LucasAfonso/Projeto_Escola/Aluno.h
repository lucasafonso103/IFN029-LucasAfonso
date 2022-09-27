typedef struct dma {
	char data_completa[11];
  	int dia;
  	int mes;
	int ano; 
}Data;

typedef struct aluno{
    int matricula;
    char nome[50];
    char sexo;
    Data data_nascimento;
    char cpf[15];
}Aluno;