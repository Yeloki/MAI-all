#include <stdio.h>
#include <ctype.h>
#define VOWELS (1u<<('a' - 'a') | 1u <<('e'-'a') | 1u <<('i'-'a') | 1u <<('o'-'a') | 1u <<('u'-'a') | 1u <<('y'-'a'))

unsigned int to_set(char c) {
  c = (char) tolower(c);
  return ('a' <= c && c <= 'z') ? (1u << (c - 'a')) : 0;
}

int main() {
//  int v[6] = {0, 0, 0, 0, 0, 0};
  unsigned int v = 0;
  char c;
  int result = 0;
  while (scanf("%c", &c) != EOF) {
    if (isspace(c)) {
      int counter = 0;
      v = v & VOWELS;
      for (char x = 'a'; x <= 'z'; ++x)
        if ((v & to_set(x)) != 0)
          ++counter;
      result += ((counter == 1) ? 1 : 0);
    } else {
      v |= to_set(c);
    }
  }
  printf(result ? "YES" : "NO");

  return 0;
}
