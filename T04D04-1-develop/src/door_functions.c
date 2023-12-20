#include <math.h>
#include <stdio.h>

double Verz(double x);
double Lemn(double x);
double Gip(double x);

int main() {

  double pi = M_PI;
  double abs;

  for (int i = 0; i < 42; i++) {
    abs = -pi + 2 * pi / 41 * i;
    if ((sqrt(1 + 4 * pow(abs, 2)) - pow(abs, 2) - 1) < 0) {
      printf("%lf|%lf| - |%lf\n", abs, Verz(abs), Gip(abs));
    } else {
      printf("%lf|%lf|%lf|%lf\n", abs, Verz(abs), Lemn(abs), Gip(abs));
    }
  }
  return 0;
}

double Verz(double x) { return 1 / (1 + x); }

double Lemn(double x) {
  // if ((sqrt(1+4*pow(x,2))-pow(x,2)-1)<0) return 0; else
  return sqrt(sqrt(1 + 4 * pow(x, 2)) - pow(x, 2) - 1);
}
double Gip(double x) { return 1 / pow(x, 2); }