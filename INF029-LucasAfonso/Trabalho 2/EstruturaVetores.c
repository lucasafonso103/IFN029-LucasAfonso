#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

estrutura_principal vetorPrincipal[TAM];

void ordenarVetor (int vetor[], int tamanho);
No* criarElemento(int valor);

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

  int retorno = 0;
  int p= posicao-1;

  // se posição é um valor válido {entre 1 e 10}
  if (posicao > 10 || posicao < 1)
    retorno = POSICAO_INVALIDA;
  
  else if (vetorPrincipal[p].presenca_aux == 1)
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    
  // o tamanho ser muito grande
  else if (tamanho > 20)
    retorno = SEM_ESPACO_DE_MEMORIA;
 
  // o tamanho nao pode ser menor que 1
  else if (tamanho < 1)
    retorno = TAMANHO_INVALIDO;
    
  // deu tudo certo, crie
  else{
  vetorPrincipal[p].presenca_aux= 1;
  vetorPrincipal[p].tam_aux= tamanho;
  vetorPrincipal[p].estrutura_aux= (int *) malloc(tamanho*sizeof(int));
  retorno = SUCESSO;   
  }

  return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    //int retorno = 0;
    int p= posicao - 1;
    int ultimo;
   
    if (posicao<1 || posicao > TAM)
      return POSICAO_INVALIDA;
  
    if (vetorPrincipal[p].presenca_aux == 0)
      return SEM_ESTRUTURA_AUXILIAR;
  
    if (vetorPrincipal[p].qtd_aux == vetorPrincipal[p].tam_aux)
      return SEM_ESPACO;
  
    else {
    ultimo = vetorPrincipal[p].qtd_aux;
    vetorPrincipal[p].estrutura_aux[ultimo] = valor;
    vetorPrincipal[p].qtd_aux++;
    return SUCESSO;  
      }     
  
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  int retorno = 0;
  int p= posicao -1;
  
  if (posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

  if (vetorPrincipal[p].presenca_aux == 0)
    return SEM_ESTRUTURA_AUXILIAR;

  if (vetorPrincipal[p].presenca_aux == 1 && vetorPrincipal[p].qtd_aux == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  
  vetorPrincipal[p].qtd_aux--; 
  return SUCESSO;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  int retorno = 0;
  int p= posicao -1;
  int i=0, j=0, verificador=0;
  
  if (posicao<1 || posicao > TAM)
    return POSICAO_INVALIDA;
    
  if (vetorPrincipal[p].presenca_aux == 0)
    return SEM_ESTRUTURA_AUXILIAR;

  if (vetorPrincipal[p].presenca_aux == 1 && vetorPrincipal[p].qtd_aux == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  for (i= 0; i < posicao; i++) {
    if (valor == vetorPrincipal[p].estrutura_aux[i]) {
      verificador = 1;
      if ((i+1) == vetorPrincipal[p].qtd_aux){  
        vetorPrincipal[p].qtd_aux--;
      }

      else{
        vetorPrincipal[p].qtd_aux--;
        for(j= i; j<vetorPrincipal[p].qtd_aux; j++){
          vetorPrincipal[p].estrutura_aux[j]= vetorPrincipal[p].estrutura_aux[j+1];    
        } 
      } 
    }
  }

  if (verificador == 1)  
    return SUCESSO;

  else
    return NUMERO_INEXISTENTE;

}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = 0;
  int p= posicao-1;
  int i;
  int auxiliar= 0;

  if (posicao<1 || posicao > TAM)
    return POSICAO_INVALIDA;

  if (vetorPrincipal[p].presenca_aux==0)
    return SEM_ESTRUTURA_AUXILIAR;

  if (vetorPrincipal[p].presenca_aux==1 && vetorPrincipal[p].qtd_aux== 0)
    return ESTRUTURA_AUXILIAR_VAZIA;
  
  for (i=0; i<vetorPrincipal[p].qtd_aux; i++)
    vetorAux[i]= vetorPrincipal[p].estrutura_aux[i];
  
  return SUCESSO;   
  
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno =0;
  int p= posicao -1;
  int auxiliar=0;
  int i;
  
  if (posicao<1 || posicao > TAM)
    return POSICAO_INVALIDA;

  if (vetorPrincipal[p].presenca_aux==0)
    return SEM_ESTRUTURA_AUXILIAR;

    
  if (vetorPrincipal[p].presenca_aux==1 && vetorPrincipal[p].qtd_aux== 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  
  for (i= 0; i< vetorPrincipal[p].qtd_aux; i++)
    vetorAux[i]= vetorPrincipal[p].estrutura_aux[i];
       
  ordenarVetor (vetorAux, vetorPrincipal[p].qtd_aux);
    return SUCESSO;

}

void ordenarVetor (int vetor[], int tamanho){
  
  int i, j, temp;
    
  for (i = 0; i < tamanho; i++) {
        for (j = i; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
  
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int retorno = 0;
  int verificador = 0;
  int aux=0;
  int i, p;
  
  //if (vetorAux[0]/1 != vetorAux[0])
    //return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  
  for (p= 0; p<TAM; p++){
    if (vetorPrincipal[p].presenca_aux==0 || vetorPrincipal[p].qtd_aux== 0)
      verificador++;
    
    else{
      for (i=0; i< vetorPrincipal[p].qtd_aux; i++){
        vetorAux[aux]= vetorPrincipal[p].estrutura_aux[i];
        aux++;  
      }
      
    }
  }

  if (verificador==TAM)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

  else  
    return SUCESSO;

  return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
  int retorno =0;
  int auxiliar=0;
  int j, i, k, t=0;
  
  for (j= 0; j<TAM; j++){
    if (vetorPrincipal[j].presenca_aux==0 || vetorPrincipal[j].qtd_aux== 0)
      auxiliar++;
    }

  if (auxiliar == (TAM-1))
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  
  else{
    
      for(k= 0; k< TAM; k++){
        if (vetorPrincipal[k].presenca_aux== 1 && vetorPrincipal[k].qtd_aux > 0){
          for (i= 0; i< vetorPrincipal[k].qtd_aux; i++){
            vetorAux[t]= vetorPrincipal[k].estrutura_aux[i];
            t++; 
            
          }
            
        }

      }
  
    ordenarVetor (vetorAux, t);
    
    return SUCESSO;  
  }

}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/

//---->>>DUVIDAS!!!!!!! Como saber se deu erro na alocação?
//https://wagnergaspar.com/como-aumentar-o-tamanho-de-um-vetor-com-a-funcao-realloc/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
  int retorno = 0;
  int p= posicao-1;
  int new_tam;

  if (posicao<1 || posicao > TAM)
    return POSICAO_INVALIDA;

  if (vetorPrincipal[p].presenca_aux==0)
    return SEM_ESTRUTURA_AUXILIAR;

  new_tam= vetorPrincipal[p].tam_aux + novoTamanho;
  
  if (new_tam < 1)
    return NOVO_TAMANHO_INVALIDO;

  if (new_tam > 0 && vetorPrincipal[p].presenca_aux==1){
    //vetorPrincipal[p].estrutura_aux= realloc (vetorPrincipal[p].estrutura_aux, new_tam)
    vetorPrincipal[p].estrutura_aux = (int *)realloc(vetorPrincipal[p].estrutura_aux, new_tam * sizeof (int));
    
    if (vetorPrincipal[p].estrutura_aux == NULL)
      return SEM_ESPACO_DE_MEMORIA;

    else{
      vetorPrincipal[p].tam_aux= new_tam;
      
      if (vetorPrincipal[p].qtd_aux > new_tam)
        vetorPrincipal[p].qtd_aux= new_tam;
      
      return SUCESSO;
    }
  }
  
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

  int retorno = 0;
  int p= posicao-1;
  int i;

  if (posicao<1 || posicao > TAM)
    return POSICAO_INVALIDA;

  if (vetorPrincipal[p].presenca_aux==0)
    return SEM_ESTRUTURA_AUXILIAR;

  
  if (vetorPrincipal[p].qtd_aux== 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  
  if (vetorPrincipal[p].qtd_aux>0)
    return vetorPrincipal[p].qtd_aux;   
 
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote

*/
No *montarListaEncadeadaComCabecote()
{
  No *novo = (No *)malloc(sizeof(No));
  novo->prox = NULL;
	if(novo == NULL){
        return NULL;
	}
  
  return novo;

}

No* criarElemento(int valor){
	No *novo = (No *)malloc(sizeof(No));
	if(novo == NULL){
        printf("Falta Memoria\n");
        exit(1);
	}
	novo->conteudo = valor;
	novo->prox = NULL;
	return novo;
}


/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  No* tmp;
  No* novo;
  int i;
  
	//ele indicou que essa estutura teria tamanho 10 no mainTeste.C
  for (i=0; i<10; i++){
    
    No* novo = criarElemento(vetorAux[i]);
    
	  if(inicio->prox == NULL){
  		inicio->prox = novo;
  	}
  	else{
  		tmp = inicio->prox;
  
  		while(tmp->prox != NULL)
  			tmp = tmp->prox;
  
  		tmp->prox = novo;
  	} 
  }  
}



/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
  No* atual = *inicio;
	No* tmp;

	while(atual != NULL){
		tmp = atual->prox;
		free(atual);
		atual = tmp;
	}
}


/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
  int x;
  
  for(x=0; x<TAM; x++) {
    vetorPrincipal[x].presenca_aux=0;
    vetorPrincipal[x].tam_aux=0;
    vetorPrincipal[x].qtd_aux= 0;
    vetorPrincipal[x].estrutura_aux= NULL;  
  }
  
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
  int x;
  
  for(x=0; x<TAM; x++) 
    free (vetorPrincipal[x].estrutura_aux);  
    
}
