#include <stdio.h>
#include <math.h>

double func1(double x) {
  return sqrt(1 - x) - tan(x);
}
double func2(double x) {
  return 3 * x - 14 + exp(x) - exp(-x);
}
struct tip {
  int i;
  double r;
  int c;
};
//изменненая функция для метода итераций
double g(double f(double), double x, double h) {
  return x - h * f(x);
}
//машинное эпсилон
double eps() {
  double x = 1;
  while (x / 2 + 1 > 1) {
    x /= 2;
  }
  return x;
}
double e;
//первая производная функции
double derivative11(double f(double), double x) {
  return (f(x + 0.01) - f(x - 0.01)) / (0.02);
}
//вторая производная функции
double derivative12(double f(double), double x) {
  return (f(x + 0.01) - 2 * f(x) + f(x - 0.01)) / (0.0001);
}

//максимальное значение производной функции на заданном отрезке [a,b]
double max_derivative(double f(double), double a, double b) {
  return fmax(fmax(derivative11(f, a), derivative11(f, b)), derivative11(f, (a + b) / 2));
}
//метод дихотомии
struct tip dihotomia(double f(double), double a, double b) {
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
  struct tip r = {s, (a + b) / 2, 1};
  return r;
}
//метод ньютона
struct tip newton(double f(double), double a, double b) {
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
  struct tip r = {s, x1, o};
  return r;
}
//метод итераций
struct tip iteration(double f(double), double a, double b) {
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
  struct tip r = {s, x1, o};
  return r;
}
int main() {
  e = eps();
  struct tip r = dihotomia(func2, 1, 3), a = newton(func2, 1, 3), b = iteration(func2, 1, 3);
  printf("------------------------------------------------------------------------\n");
  printf("|  Function    |     Dihotomia   |      Newton    |      Iteration     |\n");
  printf("------------------------------------------------------------------------\n");
  printf("|      1       |   ");
  if (r.c)
    printf("%.4lf (%d)   |", r.r, r.i);
  else
    printf("  Ne shoditsya  |");
  if (a.c)
    printf("  %.4lf (%d)    |", a.r, a.i);
  else
    printf("  Ne shoditsya  |");
  if (b.c)
    printf("     %.4lf (%d)    |\n", b.r, b.i);
  else
    printf("    Ne shoditsya    |\n");
  printf("------------------------------------------------------------------------\n");
  r = dihotomia(func1, 0, 1), a = newton(func1, 0, 1), b = iteration(func1, 0, 1);
  printf("|      2       |   ");
  if (r.c)
    printf("%.4lf (%d)   |", r.r, r.i);
  else
    printf("  Ne shoditsya  |");
  if (a.c)
    printf("  %.4lf (%d)    |", a.r, a.i);
  else
    printf(("  Ne shoditsya  |"));
  if (b.c)
    printf("     %.4lf (%d)    |\n", b.r, b.i);
  else
    printf(("    Ne shoditsya    |\n"));
  //printf("|      2       |   %.4lf (%d)    |   %.4lf (%d)   |   %.4lf (%d)       |\n",r.r,r.i,a.r,a.i,b.r,b.i);
  printf("------------------------------------------------------------------------\n");

  return 0;
}
