/* =============================================================================
 * Libraries
 * ========================================================================== */
#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* =============================================================================
 * Internal Helper Functions Prototypes Header
 * ========================================================================== */
Arvore *createNode(int value);
Arvore *createAndFillBSTInIncrementalOrder(int numberOfElements);
Arvore *createAndFillBSTInRandomOrder(int numberOfElements);
int isEmptyNode(Arvore *a);
int isLeafNode(Arvore *a);
int isParentNode(Arvore *a, int v1, int v2);
void removeElementWithTwoChildren(Arvore *a, int v);
void switchNodeContent(Arvore *a1, Arvore *a2);

/* =============================================================================
 * Binary Search Tree Creation/Destruction Functions
 * ========================================================================== */
Arvore *cria_arvore_vazia(void) { return NULL; }

void arvore_libera(Arvore *a) {
  if (a != NULL) {
    arvore_libera(a->esq);
    arvore_libera(a->dir);
    free(a);
  }
}

/* =============================================================================
 * Assignment 03 Functions
 * ========================================================================== */

//========= Q1 - inserir
Arvore *inserir(Arvore *a, int v) {
  if (isEmptyNode(a)) {
    a = createNode(v);

  } else if (v < a->info) {
    a->esq = inserir(a->esq, v);

  } else {
    a->dir = inserir(a->dir, v);
  }

  return a;
}

//========= Q1 - remover
Arvore *remover(Arvore *a, int v) {
  if (isEmptyNode(a)) {
    return NULL;
  }

  if (v < a->info) {
    a->esq = remover(a->esq, v);

  } else if (v > a->info) {
    a->dir = remover(a->dir, v);

  } else {
    if (isLeafNode(a)) {
      free(a);
      a = NULL;
    } else if (a->dir == NULL) {
      Arvore *aux = a;
      a = a->esq;
      free(aux);
    } else if (a->esq == NULL) {
      Arvore *aux = a;
      a = a->dir;
      free(aux);
    } else {
      removeElementWithTwoChildren(a, v);
    }
  }

  return a;
}

//========= Q1 - busca
int buscar(Arvore *a, int v) {
  if (isEmptyNode(a)) {
    return 0;
  }

  if (v < a->info) {
    return buscar(a->esq, v);
  }

  if (v > a->info) {
    return buscar(a->dir, v);
  }

  return 1;
}

//========= Q2 - min =====
int min(Arvore *a) {
  if (isEmptyNode(a)) {
    printf("Empty Binary Search Tree");
    return -1;
  }

  Arvore *aux = a;
  while (aux->esq != NULL) {
    aux = aux->esq;
  }

  return aux->info;
}

//========= Q2 - max =====
int max(Arvore *a) {
  if (isEmptyNode(a)) {
    printf("Empty Binary Search Tree");
    return -1;
  }

  Arvore *aux = a;
  while (aux->dir != NULL) {
    aux = aux->dir;
  }

  return aux->info;
}

//========= Q5 - imprime_decrescente =====
void imprime_decrescente(Arvore *a) {
  if (!isEmptyNode(a)) {
    imprime_decrescente(a->dir);
    printf("%d ", a->info);
    imprime_decrescente(a->esq);
  }
}

//========= Q6 - maior_ramo =====
int maior_ramo(Arvore *a) {
  if (!isEmptyNode(a)) {
    int highestValue = maior_ramo(a->esq);
    int newCandidate = maior_ramo(a->dir);

    if (newCandidate > highestValue) {
      highestValue = newCandidate;
    }

    return highestValue + a->info;
  }
  return 0;
}

//========= Q7 - ancestral =====
int ancestral(Arvore *a, int e1, int e2) {
  if (isEmptyNode(a)) {
    return -1;
  }

  if (!buscar(a, e1)) {
    printf("%d não está na árvore.\n", e1);
    return -1;
  }

  if (!buscar(a, e2)) {
    printf("%d não está na árvore.\n", e2);
    return -1;
  }

  if (isParentNode(a, e1, e2)) {
    return a->info;
  }

  if (a->info > e1) {
    return ancestral(a->esq, e1, e2);
  }

  return ancestral(a->dir, e1, e2);
}

void pre_order(Arvore *a) {
  if (a != NULL) {
    printf("%d ", a->info);
    pre_order(a->esq);
    pre_order(a->dir);
  }
}

/* =============================================================================
 * Main Function
 * ========================================================================== */
int main() {
  clock_t start, end;
  double elapsedTime;
  int i;

  // Creating Binary Search Tree to test the functions.
  printf("======= - Exercício 1 - =======");
  Arvore *a = cria_arvore_vazia();

  // Exercise 1 - Insertion
  a = inserir(a, 50);
  a = inserir(a, 30);
  a = inserir(a, 90);
  a = inserir(a, 20);
  a = inserir(a, 40);
  a = inserir(a, 95);
  a = inserir(a, 10);
  a = inserir(a, 35);
  a = inserir(a, 45);
  printf("\n");
  pre_order(a);
  printf("\n");

  // Exercise 1 - Removal
  a = remover(a, 30);
  printf("\n");
  pre_order(a);
  printf("\n");

  // Exercise 1 - Search
  printf("Searching for 30: %d\n", buscar(a, 30));
  printf("Searching for 35: %d\n", buscar(a, 35));

  // Exercise 2 - min
  printf("======= - Exercício 2 - =======\n");
  printf("Menor valor presente na árvore: %d\n", min(a));
  // Exercise 2 - Max
  printf("Maior valor presente na arvore: %d\n", max(a));

  // ====== Q3 ====
  printf("======= - Exercício 3 - =======\n");
  int numberOfElements = 100000;
  printf("Preenchendo a árvore com %d elementos ordenados...\n",
         numberOfElements);
  start = clock();
  Arvore *bigTree = createAndFillBSTInIncrementalOrder(numberOfElements);
  end = clock();
  elapsedTime = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Árvore preenchida em %f segundos.\n", elapsedTime);

  printf("Iniciando Busca...\n");
  start = clock();
  int found = buscar(bigTree, numberOfElements);
  end = clock();
  printf("Busca finalizada.\n");
  elapsedTime = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Encoutrou: %d - Tempo: %f segundos.\n", found, elapsedTime);

  //====== Q4 ====
  printf("======= - Exercício 4 - =======\n");
  printf("Preenchendo a árvore com %d elementos aleatórios...\n",
         numberOfElements);
  start = clock();
  Arvore *bigRandomTree = createAndFillBSTInRandomOrder(numberOfElements);
  end = clock();
  elapsedTime = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Árvore preenchida em %f segundos.\n", elapsedTime);

  start = clock();
  printf("Iniciando Busca...\n");
  found = buscar(bigRandomTree, numberOfElements);
  end = clock();
  printf("Busca finalizada.\n");
  elapsedTime = (end - start) / (double)CLOCKS_PER_SEC;
  printf("Encoutrou: %d - Tempo: %f segundos.\n", found, elapsedTime);

  // Exercise 5
  printf("======= - Exercício 5 - =======\n");
  imprime_decrescente(a);

  // Exercise 6
  printf("\n======= - Exercício 6 - =======\n");
  printf("O valor do maior ramo é: %d\n", maior_ramo(a));

  // Exercise 7
  printf("======= - Exercício 7 - =======\n");
  int n1 = 10;
  int n2 = 45;
  printf("%d é o ancestral comum de %d e %d", ancestral(a, n1, n2), n1, n2);

  arvore_libera(a);
  /* arvore_libera(bigTree); */
  /* arvore_libera(bigRandomTree); */

  return 0;
}

/* =============================================================================
 * Internal Helper Functions Implementations
 * ========================================================================== */
Arvore *createNode(int value) {
  Arvore *node = (Arvore *)malloc(sizeof(Arvore));
  node->info = value;
  node->esq = NULL;
  node->dir = NULL;

  return node;
}

Arvore *createAndFillBSTInIncrementalOrder(int numberOfElements) {
  Arvore *a = cria_arvore_vazia();

  int i;
  for (i = 0; i < numberOfElements; i++) {
    a = inserir(a, i);
  }

  return a;
}

Arvore *createAndFillBSTInRandomOrder(int numberOfElements) {
  srand(time(NULL));
  Arvore *a = cria_arvore_vazia();

  int i;
  for (i = 0; i < numberOfElements; i++) {
    int randomNumber = rand() % numberOfElements;
    a = inserir(a, randomNumber);
  }

  return a;
}

int isEmptyNode(Arvore *a) { return a == NULL; }

int isLeafNode(Arvore *a) { return isEmptyNode(a->esq) && isEmptyNode(a->dir); }

int isParentNode(Arvore *a, int v1, int v2) {
  return (a->info < v1 && a->info > v2) || (a->info < v2 && a->info > v1);
}

void removeElementWithTwoChildren(Arvore *a, int v) {
  Arvore *aux = a->esq;

  while (aux->dir != NULL) {
    aux = aux->dir;
  }

  switchNodeContent(a, aux);
  a->esq = remover(a->esq, v);
}

void switchNodeContent(Arvore *a1, Arvore *a2) {
  int aux = a1->info;
  a1->info = a2->info;
  a2->info = aux;
}
