/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

/* =============================================================================
 * Function Prototype Header
 * ========================================================================== */
int isLeafNode(Arvore *a);
int max(int n1, int n2);
void printNodeElement(Arvore *a);

/* =============================================================================
 * Function Implementations
 * ========================================================================== */
Arvore *cria_arv_vazia(void) { return NULL; }

Arvore *constroi_arv(char c, Arvore *e, Arvore *d) {
  Arvore *no = (Arvore *)malloc(sizeof(Arvore));
  no->info = c;
  no->esq = e;
  no->dir = d;
  return no;
}

int verifica_arv_vazia(Arvore *a) { return (a == NULL); }

void arv_libera(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);
  }
}

//========= Exercício 1 - pré-ordem ====
void preOrderTraversal(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    printNodeElement(a);
    preOrderTraversal(a->esq);
    preOrderTraversal(a->dir);
  }
}

//========= Exercício 1 - in-ordem ====
void inOrderTraversal(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    inOrderTraversal(a->esq);
    printNodeElement(a);
    inOrderTraversal(a->dir);
  }
}

//========= Exercício 1 - pós-ordem ====
void postOrderTraversal(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    postOrderTraversal(a->esq);
    postOrderTraversal(a->dir);
    printNodeElement(a);
  }
}

//========= Exercício 2 - pertence ====
int pertence_arv(Arvore *a, char c) {
  int containsDesidedInfo = 0;
  if (!verifica_arv_vazia(a)) {
    if (c == a->info) {
      return 1;
    }
    containsDesidedInfo += pertence_arv(a->esq, c);
    containsDesidedInfo += pertence_arv(a->dir, c);
  }
  return containsDesidedInfo;
}

//========= Exercício 3 - conta nós ====
int conta_nos(Arvore *a) {
  int nodeCounter = 0;
  if (!verifica_arv_vazia(a)) {
    nodeCounter++;
    nodeCounter += conta_nos(a->esq);
    nodeCounter += conta_nos(a->dir);
  }
  return nodeCounter;
}

//========= Exercício 4 - calcula altura ====
int calcula_altura_arvore(Arvore *a) {
  if (!verifica_arv_vazia(a)) {
    return max(calcula_altura_arvore(a->esq), calcula_altura_arvore(a->dir)) +
           1;
  }
  return -1;
}

//========= Exercício 5 - conta nós folha ====
int conta_nos_folha(Arvore *a) {
  int leafNodes = 0;
  if (!verifica_arv_vazia(a)) {
    if (isLeafNode(a)) {
      leafNodes++;
    } else {
      leafNodes += conta_nos_folha(a->esq) + conta_nos_folha(a->dir);
    }
  }

  return leafNodes;
}

// Helper functions
int isLeafNode(Arvore *a) {
  return verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir) ? 1 : 0;
}
int max(int n1, int n2) { return n1 > n2 ? n1 : n2; }
void printNodeElement(Arvore *a) { printf("%c", a->info); }
