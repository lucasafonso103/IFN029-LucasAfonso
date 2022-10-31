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
    int fat = 6;
    int i;  

        if (x<= 1)
            {   
                fat = 1; 
            }
            else
            { 
                for (i = 2; i <= x ; i++)
                    fat = fat * i; 
            }
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

typedef struct DQ
{
    int iDia;
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

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
	}else 
		dq.valido = 0;
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else
		dq.valido = 0;

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
    return dq;
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
int q1(char *data)
{
    int datavalida = 1;
    char dia[3], mes[3], ano[5]; 
    int tam, i, k, j = 0, contBarra=0;

    for(tam=0;data[tam]!='\0';tam++){ 
    }

    for (k=0; k < tam; k++){
        if (data[k]=='/')
            contBarra++;
        if (contBarra>2)
            return 0;        
        if(data[k]!='/' && data[k]!='0' && data[k]!='1' && data[k]!='2' && data[k]!='3' && 
           data[k]!='4' && data[k]!='5' && data[k]!='6' && data[k]!='7' && data[k]!='8' && 
           data[k]!='9')
           return 0;

   } 
    dia[0]='\0';
    mes[0]='\0';
    ano[0]='\0';

    for (i=0;  data[i]!='/'; i++)
        dia[i] = data[i];
    for (i=i+1;  data[i]!='/'; i++){
        mes[j] = data[i];
        j++;
    }
    j=0;
    
    for (i=i+1; i <= tam; i++ ){
        ano[j]=data[i];
        j++;
    }

     int iDia = atoi(dia);
    int iMes = atoi(mes);
    int iAno = atoi(ano);
    int fDia = atoi(dia);
    int fMes = atoi(mes);
    int fAno = atoi(ano);

     if(iAno<=99){
        iAno=iAno + 2000;
    }
    if ( (iDia>0 && iDia<=31) && (iMes>0 && iMes<=12) && ( iAno >= 0) ){
    if ( (iDia == 29 && iMes == 2) && ( (iAno % 4) == 0) ) { //verifica se o ano e bissexto
                return 1;
            }
            if (iDia <= 28 && iMes == 2) {//verifica o mes de feveireiro
                return 1;
            }
            if ((iDia <= 30) && (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11)) {//verifica os meses de 30 dias
                return 1;
            }
            if ((iDia <=31) && (iMes == 1 || iMes == 3 || iMes == 5 || iMes == 7 || iMes ==8 || iMes == 10 || iMes == 12)) {//verifica os meses de 31 dias
                return 1;
            }
            else
            {
                return 0;
            }
      }

   

    //quebrar a string data em strings sDia, sMes, sAno

    //DataQuebrada dataQuebrada = quebraData(data);
    //if (dataQuebrada.valido == 0) return 0;

    //converter sDia, sMes e sAno em inteiros (ex: atoi)

    //criar as variáveis iDia, iMes, iAno
    //int iAno = atoi(dataQuebrada.sAno);

    //printf("%s\n", data);

    if (datavalida)
        return 1;
    else
        return 0;



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{
    //inicial 16/04/2002 16/04/2002 16/05/2002
    //final   15/05/2002 16/05/2002 15/06/2002
    //         29 dias   30 (1 mês)   30 dias

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        return 2;

    if (q1(datafinal) == 0)
        return 3;


    DataQuebrada dqInicial = quebraData(datainicial);
    DataQuebrada dqFim = quebraData(datafinal);

    if (dqInicial.iAno > dqFim.iAno)
        return 4;
        
        
    else 
        if (dqInicial.iAno == dqFim.iAno)
            if (dqInicial.iMes > dqFim.iMes)
             return 4;
                   
        else 
        	if (dqInicial.iMes == dqFim.iMes)
            		if (dqInicial.iDia > dqFim.iDia)
             			   return 4;
        
        
    nDias = dqFim.iDia - dqInicial.iDia ;
    nMeses =dqFim.iAno - dqInicial.iAno;
    nAnos = dqFim.iMes - dqInicial.iMes ;

 if (nDias < 0) {
        nMeses--;
        if (iMes == 1 || iMes == 3 || iMes == 5 || iMes == 7 || iMes == 8 || iMes== 10 || iMes == 12) {
            nDias += 31;
        } else if (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11) {
            nDias =nDias + 30;
        }    
        else if(iMes==2 && ( (iAno / 4) == 0) ){
            nDias=nDias+29;
        }
        else if(iMes=2){
            nDias=nDias+28;
        }
 }
        if(nMeses < 0){
        nMeses=nMeses+12;
        nAnos--;
 }
    
    /*mantenha o código abaixo, para salvar os dados  
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
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
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;
    int i,tam=0 , qtdCaracter=0 ;
   
    for(tam=0;texto[tam]!= '\0';tam++){};
                                
        if (isCaseSensitive == 1){
            for(i=0; i<tam; i++){
                if (texto[i] == c)
                    qtdCaracter++;
            }
        }
        else{                                             
            if (c >= 65 && c <= 90){                        
                for(i=0; i<tam; i++){             
                    if (texto[i] == c || texto[i] == c+32)  
                        qtdCaracter++;
                }
            }else if (c >= 97 && c <= 122){                 
                for(i=0; i<tam; i++){
                    if (texto[i] == c || texto[i] == c-32)
                        qtdCaracter++;
                } 
            }   
        } 
    return qtdOcorrencias;
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
    int qtdOcorrencias = -1;
    int tamTexto,tamBusca,inicial,i,j,x=0,d;
    
    for(i=0;i<strTexto[i]!='\0';i++){}
        tamTexto=i;
    for(j=0;strBusca[j]!='\0';j++){}
        tamBusca=j;

    if(tamTexto<tamBusca){
        qtdOcorrencias=0;  
    }

    for ( i = 0; x = 0 , strTexto[i] != '\0'; i ++) {
        if (strTexto[i] == strBusca[x]) {
            if (x == 0) 
                inicial = i;
                x ++;
        }
        else x = 0;
        
        if (strBusca[x] == '\0') {
          qtdOcorrencias ++;
            if (x < 30) {
                posicoes[d] = inicial + 1;
                posicoes[d+1] = i + 1;
                x = 0;
                d = d +2;
            } 
        else break;
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
int invert=0,invert1=0, invert2=0,invert3=0,i=0,rest=0,rest1=0,rest2=0,rest3=0;
    
    if (num <10){ 
        num=num*1;
    }
    
    if (num>=10 && num<100){
        
            rest=num%10;
            invert=num/10;
            num=rest*10+ invert;
    }
        
    if(num>=100 && num<1000){
          
            rest=num%100;
            invert=num/100;
            rest1=rest%10;
            invert1=rest/10;
            num=rest1*100 + invert1*10 + invert;
    }
    if (num>=1000 && num<10000){

            rest=num%1000;
            invert=num/1000;
            rest1=rest%100;
            invert1=rest/100;
            rest2=rest1%10;
            invert2=rest1/10;
            num=rest2*1000 + invert2*100 + invert1*10 + invert;

    }
    if (num>=10000 && num<100000){

            rest=num%10000;
            invert=num/10000;
            rest1=rest%1000;
            invert1=rest/1000;
            rest2=rest1%100;
            invert2=rest1/100;
            rest3=rest2%10;
            invert3=rest2/10;
            num=rest3*10000 + invert3*1000 + invert2*100 + invert1*10 +invert;

    }
    return num;
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

int q6(int numerobase, int numerobusca){
    {
    int aux, aux1; 
    int qtdOcorrencias = 0; 
    int tam = 1;

    aux = numerobusca;
        
        while (aux != 0){
            
            tam = tam * 10;
            aux = aux/ 10;
    }

    aux = numerobase;

        while (aux != 0){
            if (aux % tam == numerobusca){

                qtdOcorrencias++;
                aux = aux/tam;
    }   
        else
                aux =aux/10;
    }
    
    return qtdOcorrencias;
}

void usarData(char *datar, int *usarDia, int *usarMes, int *usarAno)
{
   
    char dia[3], mes[3], ano[5]; 
    int tam, i, k, j = 0, contBarra=0;
    
    // quebra a data
    for (i=0;  datar[i]!='/'; i++)
        dia[i] = datar[i];
    
    for (i=i+1;  datar[i]!='/'; i++)
    {
        mes[j] = datar[i];
        j++;
    }
   

    j=0;
    
    for (i=i+1; i <= tam; i++ )
    {
        ano[j]=datar[i];
        j++;
    }
    
    // Converte dia mes e ano em inteiros    
    int intDia = *usarDia = atoi(dia);
    int intMes = *usarMes = atoi(mes);
    int intAno = *usarAno = atoi(ano);
}
} 
}