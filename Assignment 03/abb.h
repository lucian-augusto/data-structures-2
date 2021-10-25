/* =============================================================================
 * Struct Definitions
 * ========================================================================== */
typedef struct arvore {
  int info;
  struct arvore *esq;
  struct arvore *dir;
} Arvore;

/* =============================================================================
 * Function Prototypes
 * ========================================================================== */
int ancestral(Arvore *a, int e1, int e2);
int buscar(Arvore *a, int v);
void imprime_decrescente(Arvore *a);
Arvore *inserir(Arvore *a, int v);
int maior_ramo(Arvore *a);
int max(Arvore *a);
int min(Arvore *a);
void pre_order(Arvore *a);
Arvore *remover(Arvore *a, int v);
