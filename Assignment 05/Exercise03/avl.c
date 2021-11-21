#include "avl.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int isAlphabeticallyBigger(char *str1, char *str2);

/*Função que devolve o maior entre dois números inteiros!*/
int maior(int esq, int dir) { return (esq > dir ? esq : dir); }

/*----------------------*/
int altura(Arvore *a) { return a != NULL ? a->altura : -1; }

int atualizar_altura(Arvore *a) {
  return maior(altura(a->esq), altura(a->dir)) + 1;
}

/*----------------------*/
int balanceamento(Arvore *a) { return altura(a->dir) - altura(a->esq); }

/*----------------------*/
Arvore *rotacao_simples_esq(Arvore *a) {
  Arvore *rotated = a->dir;
  a->dir = rotated->esq;
  rotated->esq = a;

  a->altura = atualizar_altura(a);
  rotated->altura = atualizar_altura(rotated);

  return rotated;
}

/*----------------------*/
Arvore *rotacao_simples_dir(Arvore *a) {
  Arvore *rotated = a->esq;
  a->esq = rotated->dir;
  rotated->dir = a;

  a->altura = atualizar_altura(a);
  rotated->altura = atualizar_altura(rotated);

  return rotated;
}

/*----------------------*/
Arvore *rotacao_dupla_esq(Arvore *a) {
  a->dir = rotacao_simples_dir(a->dir);
  return rotacao_simples_esq(a);
}

/*----------------------*/
Arvore *rotacao_dupla_dir(Arvore *a) {
  a->esq = rotacao_simples_esq(a->esq);
  return rotacao_simples_dir(a);
}

/*----------------------*/
Arvore *atualizar_fb_dir(Arvore *a) {
  a->altura = atualizar_altura(a);

  if (balanceamento(a) >= 2) {
    if (balanceamento(a->dir) >= 0) {
      a = rotacao_simples_esq(a);
    } else {
      a = rotacao_dupla_esq(a);
    }
  }

  return a;
}

/*----------------------*/
Arvore *atualizar_fb_esq(Arvore *a) {
  a->altura = atualizar_altura(a);

  if (balanceamento(a) <= -2) {
    if (balanceamento(a->esq) <= 0) {
      a = rotacao_simples_dir(a);
    } else {
      a = rotacao_dupla_dir(a);
    }
  }

  return a;
}

/*----------------------*/
Arvore *inserir(Arvore *a, char *chave) {
  if (a == NULL) {
    a = (Arvore *)malloc(sizeof(Arvore));
    a->chave = chave;
    a->altura = 0;
    a->esq = NULL;
    a->dir = NULL;
  } else if (isAlphabeticallyBigger(chave, a->chave)) {
    a->dir = inserir(a->dir, chave);
    a = atualizar_fb_dir(a);
  } else {
    a->esq = inserir(a->esq, chave);
    a = atualizar_fb_esq(a);
  }

  return a;
}

/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore *remover(Arvore *a, char *chave) {
  if (a == NULL) {
    return NULL;
  } else {
    if (chave < a->chave) {
      a->esq = remover(a->esq, chave);
      a = atualizar_fb_dir(a);
    } else if (chave > a->chave) {
      a->dir = remover(a->dir, chave);
      a = atualizar_fb_esq(a);
    } else {
      if ((a->esq == NULL) && (a->dir == NULL)) {
        free(a);
        a = NULL;
      } else if (a->esq == NULL) {
        No *tmp = a;
        a = a->dir;
        free(tmp);
      } else if (a->dir == NULL) {
        No *tmp = a;
        a = a->esq;
        free(tmp);
      } else {
        No *tmp = a->esq;
        while (tmp->dir != NULL) {
          tmp = tmp->dir;
        }
        a->chave = tmp->chave;
        tmp->chave = chave;
        a->esq = remover(a->esq, chave);
        a = atualizar_fb_dir(a);
      }
    }
    return a;
  }
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso
 * in-ordem!*/
void imprimir_in_order(Arvore *a, int nivel) {
  if (a != NULL) {
    int i;
    for (i = 0; i < nivel; i++) {
      printf("      ");
    }
    printf("Chave: %s (altura: %d, fb: %+d) no nível: %d\n", a->chave,
           a->altura, balanceamento(a), nivel);
    imprimir_in_order(a->esq, nivel + 1);
    imprimir_in_order(a->dir, nivel + 1);
  }
}

int isAlphabeticallyBigger(char *str1, char *str2) {
  int limit = maior(strlen(str1), strlen(str2));
  int i;

  for (i = 0; i < limit; i++) {
    if (str1[0] == '\0') {
      return 0;
    }

    if (str2[0] == '\0') {
      return 1;
    }

    if (tolower(str1[i]) > tolower(str2[i])) {
      return 1;
    }

    if (tolower(str1[i]) < tolower(str2[i])) {
      return 0;
    }
  }

  return 0;
}
