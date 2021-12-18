#include <stdio.h>

void scanM(int n, int m[n][n]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &m[i][j]);
    }
  }
}

void printM(int n, int m[n][n]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void moveRows(int n, int m[n][n], int steps) {
  steps = steps % n;
  if (steps == 0)
    return;

  int new_m[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      new_m[i][j] = m[(n + i - steps) % n][j];
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      m[i][j] = new_m[i][j];
}

void moveColumns(int n, int m[n][n], int steps) {
  steps = steps % n;
  if (steps == 0)
    return;

  int new_m[n][n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      new_m[i][j] = m[i][(n + j - steps) % n];
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      m[i][j] = new_m[i][j];
}

int main() {
  int n;
  scanf("%d", &n);
  int m[n][n];
  scanM(n, m);
  moveRows(n, m, 1);
//  moveColumns(n,m,1);
  printM(n, m);
  return 0;
}