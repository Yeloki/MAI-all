#include <stdio.h>
#include "foo.h"
int main() {
  printf("Hello, world");
  foo(22);
  return 0;
}


int foo(int a) {
return a * 5;
}
