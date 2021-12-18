#include <stdio.h>

void scanM(int n, int m[n][n]) {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      scanf("%d", &m[i][j]);
}

void printM(int n, int m[n][n]) {
  int x = 0, y = 0, d = 0;
  int max_x = n - 1, max_y = n - 1, min_x = 0, min_y = 1;
  int st = 0;
  while (d < n * n) {
    printf("%d ", m[y][x]);
    switch (st) {
      case 0:++x;
        break;
      case 1:++y;
        break;
      case 2:--x;
        break;
      case 3:--y;
        break;
    }
    if (x == max_x && st == 0) {
      st = 1;
      --max_x;
    } else if (y == max_y && st == 1) {
      st = 2;
      --max_y;
    } else if (x == min_x && st == 2) {
      st = 3;
      ++min_x;
    } else if (y == min_y && st == 3) {
      st = 0;
      ++min_y;
    }
    ++d;
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
