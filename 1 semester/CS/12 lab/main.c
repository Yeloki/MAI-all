#include <stdio.h>

int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < 32; ++i) {
      int d = (n >> i) & 1;
      if (d)
        ++cnt1;
      else
        ++cnt0;
    }
    printf((cnt1 == cnt0 ? "True\n" : "False\n"));
  }
  return 0;
}
