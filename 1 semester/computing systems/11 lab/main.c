#include <stdio.h>
#include <math.h>

void printValue(int v) {
  if (v == 17) {
    printf("Seventeen\n");
    return;
  }
  switch (v / 10) {
    case 2:printf("Twenty");
      break;
    case 3:printf("Thirty");
      break;
    case 4:printf("Forty");
      break;
    case 5:printf("Fifty");
      break;
    case 6:printf("Sixty");
      break;
    case 7:printf("Seventy");
      break;
  }
  switch (v % 10) {
    case 0:printf("\n");
      break;
    case 1:printf(" one\n");
      break;
    case 2:printf(" two\n");
      break;
    case 3:printf(" three\n");
      break;
    case 4:printf(" four\n");
      break;
    case 5:printf(" five\n");
      break;
    case 6:printf(" six\n");
      break;
    case 7:printf(" seven\n");
      break;
  }
}

int checkNum(int n) {
  if (abs(n) < 17)
    return 0;
  if (abs(n) / 10 < 1 || abs(n) / 10 > 7)
    return 0;
  if (abs(n) % 10 > 7)
    return 0;
  return 1;
}

int main() {
  int n = 0;
  printf("Type -1 to exit\n\n");
  while (1) {
    scanf("%d", &n);
    if (n == -1)
      break;
    if (checkNum(n))
      printValue(abs(n));
    else
      printf("Wrong value, try again:\n\n");
  }
  return 0;
}
