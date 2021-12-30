#include <stdio.h>

void scanM(int n, int m[n][n]) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &m[i][j]);
}

void printM(int n, int m[n][n]) {
  int x = 0, y = n - 1;
  int state = 2;
  for (int i = 0; i < n * n; ++i) {
    printf("%d ", m[y][x]);
    if (state == 1) {
      if (x == n - 1) {
        --y;
        state = 2;
      } else if (y == n - 1) {
        ++x;
        state = 2;
      } else {
        ++x;
        ++y;
      }
    } else {
      if (y == 0) {
        state = 1;
        ++x;
      } else if (x == 0) {
        --y;
        state = 1;
      } else {
        --x;
        --y;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int m[n][n];
  scanM(n, m);
  printM(n, m);
  return 0;
}
