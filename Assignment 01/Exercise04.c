#include <stdio.h>

int alg1(int n) {
  int i;
  int s = 0;
  for (i = 1; i <= n; i++) {
    s = s + i;
  }
  return s;
}

int alg2(int n) {
  int i, j;
  int s = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      s = s + 1;
    }
  }
  return s;
}

int alg3(int n) { return n * (n + 1) / 2; }

int main(int argc, char *argv[]) {

  int n = 3;

  printf("%d", alg1(n));
  printf("\n");
  printf("%d", alg2(n));
  printf("\n");
  printf("%d", alg3(n));

  return 0;
}
