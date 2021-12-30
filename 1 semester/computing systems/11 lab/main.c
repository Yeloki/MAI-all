#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

enum states {
  yes,
  no
};

int space(int c) {
  return c == ' ' || c == '\n' || c == '\t' || c == EOF || c == ',';
}

void printValue(int v) {
  v = abs(v);
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

void build_int(int *p_int, int c) {
  (*p_int) = (*p_int) * 10 + (c - '0');
}

int main() {
  int c;
  enum states state = yes;
  int num = 0;
  int sign = 0;
  do {
    c = getchar();
    switch (state) {
      case yes: {
        if (space(c)) {
          if (num && checkNum(num) && sign < 2)
            printValue(num);
          state = yes;
          num = 0, sign = 0;
        } else if ((isdigit(c) || c == '+' || c == '-') && sign < 2) {
          state = yes;
          if (isdigit(c))
            build_int(&num, c);
          else
            ++sign;
        } else {
          state = no;
        }
        break;
      }
      case no: {
        sign = 0;
        num = 0;
        if (space(c))
          state = yes;
        break;
      }
    }

  } while (c != EOF);
  return 0;
}
