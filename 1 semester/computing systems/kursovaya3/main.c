#include <stdio.h>
#include <math.h>

double calculateSlug(double x, int i) {
  long int prop = (long int) pow(3, i + 1);
  return (-(prop + 2) * pow(x, i)) / prop;
}

double func(double x) {
  return (3 * x - 5) / (x * x - 4 * x + 3);
}

int main() {
  double e = 1;
  while (e / 2 + 1 > 1) {
    e /= 2;
  }

  printf("machine's epsilon = %.2lfe-16\n", e * pow(10, 16));
  int n;
  printf("enter n =");
  scanf("%d", &n);
  printf("/---------------------------------------------------------------------------------------\\\n");
  printf("|argument|     series  sum      |    function value   |iteration|       difference      |\n");
  printf("|--------|----------------------|---------------------|---------|-----------------------|\n");
  double a = 0.0, b = 0.5;
  double x = 0.0;
  for (int i = 0; i <= n; i++) {
    double slag, taylor = 0;
    int s = 0, l = 0;
    do {
      slag = calculateSlug(x, l);
      taylor += slag;
      l++;
      s++;
    } while (fabs(slag) > e);
    printf("|  %.3lf ", x);
    {
      double q = func(x);
      printf("| %.16lf\t| %.16lf |   %d   \t|      %e \t|\n", taylor, q, s, taylor - q);
      x += (b - a) / n;
    }
  }
  printf("\\---------------------------------------------------------------------------------------/\n");
  return 0;
}
