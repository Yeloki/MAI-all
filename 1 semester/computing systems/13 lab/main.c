#include <stdio.h>

int get_from_0(char c) {
  int t = c / 100;
  if (65 >= t && t <= 90)
    return t - 65;
  if (97 >= t && t <= 122)
    return t - 97;
  return -1;
}

int main() {
  int v[28];
  char c;
  while ((c = getchar()) != EOF) {
    if (get_from_0(c) == -1)
      continue;
    ++v[get_from_0(c)];
  }
  for (int i = 0; i < 28; ++i) {
    if (v[i] > 1) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
  return 0;
}
