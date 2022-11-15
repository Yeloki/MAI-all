#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#define MM_IN_INCH 25.4

enum ParserState {
///
///         123456789.12345689in
/// space-^ ^~~~~~~~^^^~~~~~~^^^ ^-space
///           first  | second ||
///                  |        |n
///                 dot       i
  first,
  dot,
  second,
  char_i,
  char_n,
  space
};

struct Inch {
  char *num;
  size_t size;
  int is_int;
  int is_final;
};

double GetDoubleFromInch(struct Inch *inch) {
  double res = 0;
  int second = 0;
  for (int i = 0; i < inch->size - 2; i++) {
    if (!second && inch->num[i] != '.')
      res = res * 10 + (inch->num[i] - '0');
    else {
      second++;
      res += (inch->num[i] - '0') / pow(10, second);
    }
  }
  return res;
}

int64_t GetInt64FromInch(struct Inch *inch) {
  int64_t res = 0;
  for (int i = 0; i < inch->size - 2; i++)
    res = res * 10 + (inch->num[i] - '0');
  return res;
}

int IsSpace(int c) {
  return c == ' ' || c == '\n' || c == '\t' || c == EOF || c == ',';
}
void AddCharToInch(struct Inch *inch, int c) {
  inch->size++;
  if (inch->num == NULL)
    inch->num = malloc(sizeof(char) * 2);
  else
    inch->num = realloc(inch->num, sizeof(char) * (inch->size + 1));
  inch->num[inch->size - 1] = (char) c;
  inch->num[inch->size] = '\000';
  inch->is_int = (inch->is_int ? c != '.' : 0);
}

void Init(struct Inch *inch) {
  inch->num = NULL;
  inch->size = 0;
  inch->is_int = 1;
  inch->is_final = 0;
}

void ResetInch(struct Inch *inch) {
  free(inch->num);
  inch->size = 0;
  inch->is_int = 1;
  inch->num = NULL;
  inch->is_final = 0;
}

void Finalize(struct Inch *inch) {
  inch->is_final = 1;
}

void CalculateAndPrint(struct Inch *inch) {
  if (!inch->is_final)
    return;
  double res;
  if (inch->is_int)
     res = (double)GetInt64FromInch(inch) * MM_IN_INCH;
  else
    res = GetDoubleFromInch(inch) * MM_IN_INCH;
  printf("%fmm", res);
  ResetInch(inch);
}

void PrintUnfinishedInch(struct Inch *inch) {
  if (inch->size == 0)
    return;
  printf("%s", inch->num);
  ResetInch(inch);
}

int main() {
  int c;
  int last_c = EOF;
  struct Inch inch;
  Init(&inch);
  enum ParserState state = first;
  do {
    c = getchar();
    switch (state) {
      case first: {
        if (isdigit(c) && inch.size > 0 || isdigit(c) && IsSpace(last_c)) {
          AddCharToInch(&inch, c);
        } else if (c == '.' && inch.size > 0) {
          state = dot;
          AddCharToInch(&inch, c);
        } else if (c == 'i' && inch.size > 0) {
          state = char_i;
          AddCharToInch(&inch, c);
        } else {
          PrintUnfinishedInch(&inch);
          printf("%c", c);
          state = first;
        }
        break;
      }
      case dot: {
        if (isdigit(c)) {
          AddCharToInch(&inch, c);
          state = second;
        } else {
          PrintUnfinishedInch(&inch);
          printf("%c", c);
          state = first;
        }
        break;
      }
      case second: {
        if (isdigit(c)) {
          AddCharToInch(&inch, c);
        } else if (c == 'i') {
          state = char_i;
          AddCharToInch(&inch, c);
        } else {
          PrintUnfinishedInch(&inch);
          printf("%c", c);
          state = first;
        }
        break;
      }
      case char_i: {
        if (c == 'n') {
          AddCharToInch(&inch, c);
          state = char_n;
        } else {
          PrintUnfinishedInch(&inch);
          printf("%c", c);
          state = first;
        }
        break;
      }
      case char_n: {
        if (IsSpace(c) || c == '.') {
          state = space;
          Finalize(&inch);
        } else {
          PrintUnfinishedInch(&inch);
          printf("%c", c);
          state = first;
        }
        break;
      }
      case space: {
        CalculateAndPrint(&inch);
        state = first;
        printf("%c", c);
        break;
      }
    }
    last_c = c;
  } while (c != '*');
  return 0;

}
