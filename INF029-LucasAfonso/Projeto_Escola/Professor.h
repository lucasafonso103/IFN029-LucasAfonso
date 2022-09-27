typedef struct dma_p {
	char data_completa_professor[11];
  	int diaP;
  	int mesP;
	int anoP; 
}Data_professor; 

typedef struct professor{
    int matricula_professor;
    char nome_professor[50];
    char sexo_professor;
    Data_professor data_nascimento_professor;
    char cpf_professor[15];
}Professor;