#include <stdio.h>

int is_vowel(char c) {
  for (int i = 0; i < 12; ++i)
    if ("aAeEiIoOuUyY"[i] == c)
      return 1;
  return 0;
}

int get_vowel_from_0(char c) {
  for (int i = 0; i < 12; ++i)
    if ("aeiouyAEIOUY"[i] == c)
      return i % 6;
  return -1;
}

int is_char(char c) {
  return 65 <= c && c <= 90 || 97 <= c && c <= 122;
}

int main() {
  int v[6] = {0, 0, 0, 0, 0, 0};
  char c;
  int cntr = 0;
  while ((c = getchar()) != EOF || c == '-') {
    if (!is_char(c)) {
      int flag = 0;
      for (int i = 0; i < 6; ++i) {
        if (v[i] >= 1) {
          ++flag;
        }
        v[i] = 0;
      }
      if (flag == 1)
        ++cntr;
    } else {
      if (is_vowel(c))
        ++v[get_vowel_from_0(c)];
    }
  }
  printf(cntr ? "YES" : "NO");

  return 0;
}
