#include "avl.h"
#include <stdio.h>

int main() {

  Arvore *AVL = NULL;

  // Inserting keys
  AVL = inserir(AVL, 'Q');
  AVL = inserir(AVL, 'Z');
  AVL = inserir(AVL, 'B');
  AVL = inserir(AVL, 'Y');
  AVL = inserir(AVL, 'T');
  AVL = inserir(AVL, 'M');
  AVL = inserir(AVL, 'E');
  AVL = inserir(AVL, 'W');
  AVL = inserir(AVL, 'X');
  AVL = inserir(AVL, 'S');
  AVL = inserir(AVL, 'F');
  AVL = inserir(AVL, 'G');
  AVL = inserir(AVL, 'A');
  AVL = inserir(AVL, 'H');
  AVL = inserir(AVL, 'N');
  AVL = inserir(AVL, 'O');
  AVL = inserir(AVL, 'P');
  AVL = inserir(AVL, 'R');

  // Printitng AVL after insertions
  printf("AVL após todas as inserções:\n");
  imprimir_in_order(AVL, 0);

  // Removing Keys
  AVL = remover(AVL, 'A');
  AVL = remover(AVL, 'H');
  AVL = remover(AVL, 'E');
  AVL = remover(AVL, 'W');
  AVL = remover(AVL, 'G');
  AVL = remover(AVL, 'N');
  AVL = remover(AVL, 'P');
  AVL = remover(AVL, 'O');

  // Printitng AVL after deletions
  printf("\nAVL após todas as remoções:\n");
  imprimir_in_order(AVL, 0);

  return 0;
}
