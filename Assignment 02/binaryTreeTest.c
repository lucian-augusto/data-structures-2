#include "arvore.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  // Creating the binary tree
  Arvore *a = constroi_arv(
      'a',
      constroi_arv('b', cria_arv_vazia(),
                   constroi_arv('d', cria_arv_vazia(), cria_arv_vazia())),
      constroi_arv('c', constroi_arv('e', cria_arv_vazia(), cria_arv_vazia()),
                   constroi_arv('f', cria_arv_vazia(), cria_arv_vazia())));

  char desiredChar = 'a';

  // Testing Exercise 1's Functions:
  printf("Exercício 1:");
  printf("\nPré-Ordem: ");
  preOrderTraversal(a);

  printf("\nIn-Ordem: ");
  inOrderTraversal(a);

  printf("\nPós-Ordem: ");
  postOrderTraversal(a);

  // Testing Exercise 2's Function:
  printf("\nExercício 2:");
  printf("\nÁrvore contém o caractere %c? %d", desiredChar,
         pertence_arv(a, desiredChar));

  // Testing Exercise 3's Function
  printf("\nExercício 3:");
  printf("\nNúmero de nós presentes na árvore: %d", conta_nos(a));

  // Testing Exercise 4's Function:
  printf("\nExercício 4:");
  printf("\nAltura da árvore: %d", calcula_altura_arvore(a));

  // Testing Exercise 5's Function:
  printf("\nExercício 5:");
  printf("\nNúmero de nós folha: %d", conta_nos_folha(a));

  // Freeing the binary tree
  arv_libera(a);
  return 0;
}
