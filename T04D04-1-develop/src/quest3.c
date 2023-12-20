#include <math.h>
#include <stdio.h>

int fib(int n);

int main() {
  int a;
  char c;
  if (scanf("%d%c", &a, &c) == 2 && c == '\n')
    if (a > 0) {
      a = fib(a);
      printf("%d", a);
    } else {
      a = fabs(a);
      a = pow(-1, a + 1) * fib(a);
      printf("%d", a);
    }

  else
    printf("n/a");
  return 0;
}

int fib(int n) {
  if (n == 1 || n == 2)
    return 1;
  else
    n = fib(n - 1) + fib(n - 2);
  return n;
}