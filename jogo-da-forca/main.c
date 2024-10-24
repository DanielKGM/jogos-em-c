#include <stdio.h>

#define RESPOSTA "paralelogramo"
#define TAMANHORESPOSTA 13
char jogada[TAMANHORESPOSTA];
enum status { VENCEU, PERDEU, ACERTOU };

int conferir(char tentativa, int *pvidas) {
  // declaração
  char resposta[] = RESPOSTA;
  int i;
  int letra_encontrada = 0;

  for (i = 0; i < TAMANHORESPOSTA; i++) {
    if (tentativa == resposta[i]) {
      jogada[i] = tentativa;
      letra_encontrada = 1; // Letra foi encontrada na resposta
    }
  }

  if (!letra_encontrada) {
    (*pvidas)--; // Decrementa vidas se a letra não estiver na resposta
  }

  // Conferir se todas as letras foram adivinhadas
  for (i = 0; i < TAMANHORESPOSTA; i++) {
    if (jogada[i] == '_') {
      return PERDEU; // A resposta não foi completamente adivinhada
    }
  }

  return VENCEU; // Todas as letras foram adivinhadas
}

int main(void) {
  // declarações
  int vidas = 6;
  int *pvidas = &vidas;
  char tentativa[2]; // Modificado para armazenar apenas um caractere
  enum status status = PERDEU;

  // resetar_jogada
  for (int i = 0; i < TAMANHORESPOSTA; i++) {
    jogada[i] = '_';
  }

  // jogo
  while (vidas > 0) {
    // recolher tentativa
    printf("[%i]: Insira uma letra: ", vidas);
    scanf(" %c", tentativa); // Ler um único caractere

    // atualizar resultado
    status = conferir(tentativa[0], pvidas);

    // imprimir resultado
    printf("\n\t\t");
    for (int i = 0; i < TAMANHORESPOSTA; i++) {
      printf("%c ", jogada[i]);
    }
    printf("\n\n");

    // Verifica se venceu
    if (status == VENCEU) {
      break;
    }
  }

  // fim de jogo
  if (status == VENCEU) {
    printf("[-]: Você venceu sobrando %i vida(s) ", 6 - vidas);
  } else {
    printf("[x]: Perdeu! A resposta era: %s.\n", RESPOSTA);
  }

  return 0;
}
