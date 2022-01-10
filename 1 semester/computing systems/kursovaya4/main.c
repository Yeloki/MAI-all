#include <stdio.h>
#include <math.h>

double func1(double x) {
  return x * x - log(1 + x) - 3;
}

double func2(double x) {
  return 2 * x * sin(x) - cos(x);
}

struct fun_result {
  int i;
  double r;
  int c;
};

// changed fun for iteration method
double g(double f(double), double x, double h) {
  return x - h * f(x);
}

double eps() {
  double x = 1;
  while (x / 2 + 1 > 1) {
    x /= 2;
  }
  return x;
}
double e;

//first der
double derivative11(double f(double), double x) {
  return (f(x + 0.01) - f(x - 0.01)) / (0.02);
}

//second der
double derivative12(double f(double), double x) {
  return (f(x + 0.01) - 2 * f(x) + f(x - 0.01)) / (0.0001);
}

//max val of der on [a,b]
double max_derivative(double f(double), double a, double b) {
  return fmax(fmax(derivative11(f, a), derivative11(f, b)), derivative11(f, (a + b) / 2));
}

struct fun_result dihotomia(double f(double), double a, double b) {
  //double e=eps();
  int s = 0;
  while ((fabs(a - b) >= e * 10000) && (s < 100)) {
    if (f(a) * f((a + b) / 2) > 0) {
      a = (a + b) / 2;
    } else {
      b = (a + b) / 2;
    }
    s++;
  }
  struct fun_result r = {s, (a + b) / 2, 1};
  return r;
}

struct fun_result newton(double f(double), double a, double b) {
  int s = 0, o = 1;
  //double e=eps();
  double x0 = (a + b) / 2, x1 = x0 - (f(x0) / derivative11(f, x0));
  while ((fabs(x0 - x1) > e * 10000) && (s < 100)) {
    if (fabs(f(x0) * derivative12(f, x0)) >= pow(derivative11(f, x0), 2)) {
      o = 0;
      break;
    } else {
      x0 = x1;
      x1 = x0 - (f(x0) / derivative11(f, x0));
      s++;
    }
  }
  struct fun_result r = {s, x1, o};
  return r;
}

//метод итераций
struct fun_result iteration(double f(double), double a, double b) {
  int s = 0, o = 1;
  //double e=eps();
  double h = 1 / max_derivative(f, a, b);
  double x0 = (a + b) / 2, x1 = g(f, x0, h);
  // derivative(f,x0,h) это производная для функции g(x)

  while ((fabs(x1 - x0) >= e * 10000) && (s < 100)) {
    if (fabs(1 - h * derivative11(f, x0)) >= 1) {
      o = 0;
      break;
    } else {
      x0 = x1;
      x1 = g(f, x0, h);
      s++;
    }
  }
  struct fun_result r = {s, x1, o};
  return r;
}

int main() {
  e = eps();
  double a1 = 2, b1 = 3, a2 = 0.4, b2 = 1;
  struct fun_result d = dihotomia(func1, a1, b1), n = newton(func1, a1, b1), i = iteration(func1, a1, b1);
  printf("/----------------------------------------------------------------------\\\n");
  printf("|  Function    |     Dihotomia   |      Newton    |      Iteration     |\n");
  printf("|--------------|-----------------|----------------|--------------------|\n");
  printf("|      1       |   ");
  if (d.c)
    printf("%.4lf (%d)   |", d.r, d.i);
  else
    printf("Doesn't converge|");
  if (n.c)
    printf("  %.4lf (%d)    |", n.r, n.i);
  else
    printf("Doesn't converge|");
  if (i.c)
    printf("     %.4lf (%d)    |\n", i.r, i.i);
  else
    printf("  Doesn't converge  |\n");
  printf("|--------------|-----------------|----------------|--------------------|\n");
  d = dihotomia(func2, a2, b2);
  n = newton(func2, a2, b2);
  i = iteration(func2, a2, b2);
  printf("|      2       |   ");
  if (d.c)
    printf("%.4lf (%d)   |", d.r, d.i);
  else
    printf(("Doesn't converge|"));
  if (n.c)
    printf("  %.4lf (%d)    |", n.r, n.i);
  else
    printf(("Doesn't converge|"));
  if (i.c)
    printf("     %.4lf (%d)    |\n", i.r, i.i);
  else
    printf(("  Doesn't converge  |\n"));
  //printf("|      2       |   %.4lf (%d)    |   %.4lf (%d)   |   %.4lf (%d)       |\n",d.d,d.i,n.d,n.i,i.d,i.i);
  printf("\\----------------------------------------------------------------------/\n");

  return 0;
}
