// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Lucas de Araújo Afonso
//  email: lucasaafonso103@gmail.com
//  Matrícula: 20201160030
//  Semestre: 2022.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "LucasAfonso20201160030.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <stdbool.h> 
#include <math.h>

/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	
	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	
	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}

int potencia (int base, int exp){

  int aux=1;
  
  if (exp == 0)
    return 1;
  
  else{
    
    while (exp > 0){
      aux= aux * base;
      exp--;
    } 
    return aux;
  }
}

vetor numeroTovetor (int numerobase){
  int i=0, n;
  vetor vetor1;

  if (numerobase<10)
    vetor1.numero[0]= numerobase;

  else{
    while (numerobase >=10){
      n= numerobase%10;
      vetor1.numero[i]= n;
      numerobase= numerobase/10;
      i++;
      if (numerobase<10)
        vetor1.numero[i]= numerobase;
    }
  }

  vetor1.tamanho= i;
  
  return vetor1;
}

  
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int q1(char data[])
{
  DataQuebrada dtq;
  
  dtq = quebraData(data);
  
  if (dtq.valido == 0) 
    return 0;

  int ano = dtq.iAno, mes = dtq.iMes, dia = dtq.iDia; 
  int validador, valid_ano = 0, valid_mes = 0, valid_dia = 0;
  int mes_31 = 0, mes_30 = 0, mes_29 = 0, mes_28 = 0;
  bool ano_bissexto;
  
  if (ano >= 1 && ano <= 2022){
    valid_ano = 1;
    if ((ano%4 == 0 && ano % 100 == 0 && ano && ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0))
        ano_bissexto= true;

    else 
        ano_bissexto= false;
  }
    
  if (mes >= 1 && mes <= 12)
    valid_mes = 1;

  if (valid_mes == 1 && dia >= 1 && dia <= 31){
     
    switch (mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      mes_31= 1;
    break;

    case 4:
    case 6:
    case 9:
    case 11:
      mes_30= 1;
    break;
    
    case 2: {        
      if (ano_bissexto== true && dia<=29)
        mes_29= 1;

      if (ano_bissexto== false && dia<=28)
        mes_28= 1;        
    } 
    break;
      
    }  
    
  if (dia<=31 && mes_31==1)
    valid_dia= 1;

  if (dia<=30 && mes_30==1)
    valid_dia= 1; 

  if (dia<=29 && mes_29==1)
    valid_dia= 1; 

  if (dia<=28 && mes_28==1)
    valid_dia= 1; 
  
  }

  if (valid_ano + valid_mes+ valid_dia==3)
    return validador=1;

  else
    return validador=0;
  
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

  DiasMesesAnos dmaInicio, dmaFinal, dmaResultado;
  DataQuebrada dtqInicio, dtqFinal;
    
  if (q1(datainicial) == 0){
    dmaResultado.retorno = 2;
    return dmaResultado;
  }
  else if (q1(datafinal) == 0){
    dmaResultado.retorno = 3;
    return dmaResultado;
  }
  
  else{
    dtqInicio= quebraData(datainicial);
    dtqFinal= quebraData(datafinal);

    dmaInicio.qtdDias= dtqInicio.iDia; 
    dmaInicio.qtdMeses= dtqInicio.iMes;
    dmaInicio.qtdAnos= dtqInicio.iAno;

    dmaFinal.qtdDias= dtqFinal.iDia; 
    dmaFinal.qtdMeses= dtqFinal.iMes;
    dmaFinal.qtdAnos= dtqFinal.iAno;
   
    if (dmaInicio.qtdAnos > dmaFinal.qtdAnos){
      dmaResultado.retorno = 4;
      return dmaResultado;
    }
  
    else if (dmaInicio.qtdAnos == dmaFinal.qtdAnos && dmaInicio.qtdMeses > dmaFinal.qtdMeses){
      dmaResultado.retorno = 4;
      return dmaResultado;
    }

    else if (dmaInicio.qtdAnos == dmaFinal.qtdAnos && dmaInicio.qtdMeses == dmaFinal.qtdMeses && dmaInicio.qtdDias > dmaFinal.qtdDias){
      dmaResultado.retorno = 4;
      return dmaResultado;
    }
    
    else{

      dmaResultado.qtdAnos= dmaFinal.qtdAnos - dmaInicio.qtdAnos;
      dmaResultado.qtdMeses= dmaFinal.qtdMeses - dmaInicio.qtdMeses;
      dmaResultado.qtdDias= dmaFinal.qtdDias - dmaInicio.qtdDias;
      dmaResultado.retorno= 1;
           
      return dmaResultado;
    }

  } 
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char letra, int isCaseSensitive)
{
  int tam=0, qtdOcorrencias=0, i, maiusculo=0, minusculo=0;
  
  while (texto[tam]!= '\0'){
    tam++;
  }

  if (isCaseSensitive==1){
    for (i=0; i<=tam; i++){
      if (texto[i]== letra)
        qtdOcorrencias++;
    }
  }

  else{
    if (letra >=65 && letra <=90){
      for (i=0; i<=tam; i++){
        if ((texto[i]== letra) || (texto[i]== letra + 32))
          qtdOcorrencias++;  
      }
    }

    if (letra>=97 && letra<=122){
      for (i=0; i<=tam; i++){
        if ((texto[i]== letra) || (texto[i]== letra - 32))
          qtdOcorrencias++;  
      }
    }
  }

  return  qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias=0, tam_busca, i, j, h=0, aux1, aux2, index;
  
  for (tam_busca=0; strBusca[tam_busca]!='\0'; tam_busca++);
  
  for(j=0, aux2= 1; strTexto[j]!='\0'; j++){
    if (strTexto[j]==strBusca[0]){
      aux1= j+1;
      index= aux1;
      for (i=1; i< tam_busca; i++){
        if (strTexto[aux1]==strBusca[i]){
          aux2++;
          aux1++;
        }
        else
          break;
        }
      }
    
    if (aux2 ==tam_busca){
      qtdOcorrencias++;
      posicoes[h]= index;
      //printf("p1. %d - ", posicoes[h]);
      h++;
      posicoes[h]= index + tam_busca;
      //printf("p2. %d\n-----------",posicoes[h]);
      h++;
      }
    }
      
return qtdOcorrencias;
} 
     

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
*/ 

int q5(int num)
{
  int i, p, resto, num_invert=0, pot, aux;
  int vetor [100];
 
    
  if (num<10)
    return num;

  else{
    for (i= 0; num>=10; i++){
      resto= num%10;
      vetor[i]= resto;
      num= num/10;
      if (num<10)
        vetor[i+1]= num;      
    }
    
    aux= i;
         
    for (p=0; p<=aux; p++){
      pot = potencia (10, i);
      num_invert= ((vetor[p] * pot)  + num_invert);
      i--;
    } 
      
    return num_invert;    
  }

}


/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
*/ 

int q6(int numerobase, int numerobusca)
{
  int i, j, aux1, aux2=0, qtdOcorrencias=0;
  vetor vetorbase, vetorbusca;

  vetorbase= numeroTovetor(numerobase);
  vetorbusca= numeroTovetor (numerobusca);

  for(j=0; j<=vetorbase.tamanho; j++){
    if (vetorbase.numero[j]==vetorbusca.numero[0]){
      if (vetorbusca.tamanho==0)
        qtdOcorrencias++;
    
      else{
        aux1= j+1;
        for (i=1; i<=vetorbusca.tamanho; i++){
          if (vetorbase.numero[aux1]==vetorbusca.numero[i])
              aux2++;
          aux1++;
          //break;
        }
        if (aux2==vetorbusca.tamanho)
          qtdOcorrencias++;
        
      }
    }    
  } 
     
  return qtdOcorrencias;
}
