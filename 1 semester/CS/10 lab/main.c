//
// Created by yeloki on 08.12.2021.
//

#include <stdio.h>
#define int64_t long long

int64_t fact(int64_t a) {
  if (a == 1)
    return 1;
  return a * fact(a - 1);
}

int64_t fib(int64_t c) {
  int64_t a = 1, b = 0;
  for (int64_t i = 0; i < c; ++i) {
    b = a + b;
    a = b - a;
  }
  return b;
}

void compare(int64_t a, int64_t b) {
  if (a > b)
    printf("A is greater than B\n");
  else if (a < b)
    printf("A is less than B\n");
  else
    printf("A equals B\n");
}

int main() {
  for (int i = 1; i < 20; ++i)
    compare(fib(i), fact(i));
  return 0;
}