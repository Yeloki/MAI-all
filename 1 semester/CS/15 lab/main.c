#include <stdio.h>

void scanM(int n, int m[n * n]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &m[i * n + j]);
    }
  }
}

void printM(int n, int m[n * n]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d ", m[i * n + j]);
    }
    printf("\n");
  }
  printf("\n");
}

void moveRows(int n, int m[n * n], int steps) {
  steps = steps % (n * n);
  if (steps == 0)
    return;

  int new_m[n * n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      new_m[i * n + j] = m[(n * n + i * n + j - steps) % (n * n)];
    }
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      m[i * n + j] = new_m[i * n + j];
}

int main() {
  int n;
  scanf("%d", &n);
  int m[n * n];
  scanM(n, m);
  moveRows(n, m, 106);
  printM(n, m);
  return 0;
}