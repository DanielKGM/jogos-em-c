//Letreco simples em C, por Daniel Campos Galdez Monteiro. Inspirado no jogo 'LETRECO'

#include <stdio.h>
#include "config.h"

enum status {VITORIOSO,DERROTADO}status;

int conferir(char tentativa[],char resposta[]){
  int i,k,contador; //contador de letras acertadas
  char resultado[QNT_CARACTERES];
  printf("\n>>\t[-]: \t");
  //imprimir tentativa
  for(i=0;i<QNT_CARACTERES;i++){
    printf("%c",tentativa[i]);
    printf(" ");
  }
  //criar a lista de resultado da analise padrão
  for(i=0;i<QNT_CARACTERES;i++){
    resultado[i]='_';
  }
  contador=0;
  //alterar a lista de resultado da analise
  for(i=0;i<QNT_CARACTERES;i++){
    if (resposta[i]==tentativa[i]){
      resultado[i]=resposta[i];
      contador++;
    } else {
      for(k=0;k<QNT_CARACTERES;k++){
        if((resposta[k]!=tentativa[k])&&(resposta[i]==tentativa[k])){
          resultado[k]='^';
          tentativa[k]="$";
          break;
        }
      }
    }
  }

  //conferir se todas as letras foram acertadas
  if (contador==QNT_CARACTERES){
    return VITORIOSO;
  } else { //imprimir o resultado
    printf("\n>>\t[-]: \t");
    for(i=0;i<QNT_CARACTERES;i++){
      printf("%c",resultado[i]);
      printf(" ");
    }
  }
  return DERROTADO;
}

int main(void){
  char tentativa[QNT_CARACTERES]={'_'};
  char resposta[QNT_CARACTERES]=RESPOSTA;
  int  tentativas=TENTATIVAS,i=0,caracteres=0;
  status=DERROTADO;

  //mensagem de boas vindas
  printf(BOASVINDAS);
  
  while(tentativas!=0){
    //resetar acumuladores,etc
    caracteres=0;
    i=0;
    if (status==VITORIOSO){
      break;
    }
    //recolher tentativa n
    printf(">\t\a[%i]: ",tentativas);
    scanf("%s\0",tentativa);
    //colocar tentativa em CAPSLOCK
    while(tentativa[i]!='\0') {
      if((tentativa[i]>='a') && (tentativa[i]<='z')){
        tentativa[i] = tentativa[i] - 32;
      }
      i++;
      caracteres++;
    }
    //conferir se a quantidade de caracteres está certa
    if(caracteres!=QNT_CARACTERES){
      printf("- \t[x]: ");
      for(i=1;i<QNT_CARACTERES+1;i++){
        printf("-");
      }
    } else { //conferir a tentativa
      status=conferir(tentativa,resposta);
      tentativas--;
    }
    printf("\n\n");
  }
  //resultado ao final do jogo
  switch(status){
    case DERROTADO:
      printf("\t[-]: Suas tentativas acabaram. Resposta: %s\n",RESPOSTA);
    break;
    case VITORIOSO:
      printf("\t[!]: Você venceu após %i tentativa(s)!\n",TENTATIVAS-tentativas);
    break;
  }
  return 0;
}