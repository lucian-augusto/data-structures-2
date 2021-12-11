#include <stdio.h>

void build_max_heap(int V[], int size);
int getLeft(int i, int size);
int getRight(int i, int size);
void heap_sort(int V[], int size);
void imprimir(int V[], int size);
void max_heapify(int V[], int size, int i);
int pai(int i);
void trocar(int V[], int a, int b);

int getLeft(int i, int size) {
  int left = (i * 2) + 1;
  return left < size ? left : -1;
}

int getRight(int i, int size) {
  int right = (i * 2) + 2;
  return right < size ? right : -1;
}

int pai(int i) { return (i - 1) / 2; }

void trocar(int V[], int a, int b) {
  int aux = V[a];
  V[a] = V[b];
  V[b] = aux;
}

void imprimir(int V[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", V[i]);
  }
  printf("\n");
}

void max_heapify(int V[], int size, int i) {
  int leftIndex = getLeft(i, size);
  int rightIndex = getRight(i, size);
  int highestIndex;

  highestIndex = (leftIndex >= 0 && V[leftIndex] > V[i]) ? leftIndex : i;

  if (rightIndex >= 0 && V[rightIndex] > V[highestIndex]) {
    highestIndex = rightIndex;
  }
  if (highestIndex != i) {
    trocar(V, i, highestIndex);
    max_heapify(V, size, highestIndex);
  }
}

void build_max_heap(int V[], int size) {
  int limit = (size / 2) - 1;
  int i;
  for (i = limit; i >= 0; i--) {
    max_heapify(V, size, i);
  }
}

void heap_sort(int V[], int size) {
  build_max_heap(V, size);
  int i;
  for (i = size - 1; i > 0; i--) {
    trocar(V, 0, i);
    size = i;
    max_heapify(V, size, 0);
  }
}

int main() {
  int i;
  int size = 10;
  int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

  printf("Vetor inicial : ");
  imprimir(V, size);

  heap_sort(V, size);

  printf("Vetor ordenado: ");
  imprimir(V, size);

  return 0;
}
