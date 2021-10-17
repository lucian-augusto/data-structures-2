
typedef struct arvore {
  char info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

Arvore *cria_arv_vazia(void);

Arvore *constroi_arv(char c, Arvore *e, Arvore *d);

int verifica_arv_vazia(Arvore *a);

void arv_libera(Arvore *a);

//========= Exercício 1 - pré-ordem ====
void preOrderTraversal(Arvore *a);

//========= Exercício 1 - in-ordem ====
void inOrderTraversal(Arvore *a);

//========= Exercício 1 - pós-ordem ====
void postOrderTraversal(Arvore *a);

//========= Exercício 2 - pertence ====
int pertence_arv(Arvore *a, char c);

//========= Exercício 3 - conta nós ====
int conta_nos(Arvore *a);

//========= Exercício 4 - calcula altura ====
int calcula_altura_arvore(Arvore *a);

//========= Exercício 5 - conta nós folha ====
int conta_nos_folha(Arvore *a);
