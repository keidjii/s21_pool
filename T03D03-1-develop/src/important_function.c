#include <math.h>
#include <stdio.h>

double form(double x);

int main() {
    double a;
    char c;

    if (scanf("%lf%c", &a, &c) == 2 && c == '\n') {
        printf("%.1lf", form(a));
        // form(a);
    } else
        printf("n/a");
    return 0;
}

double form(double x) {
    double y;
    double a, b, c;
    /*y = 7e-3 * x^4 + ((22.8 * x^⅓ - 1e3) * x + 3) / (x * x / 2) - x * (10 + x)^(2/x) - 1.01. */
    /*y = 7e-3 * x^4 + ((22.8 * x^⅓ - 1e3) * x + 3) / (x * x / 2) - x * (10 + x)^(2/x) - 1.01. */
    a = ((22.8 * pow(x, (double)(1/3)) - 1e3) * x + 3);
    b = (x * x / 2);
    c = x *pow( 10 + x, (double)(2/x));
    y = 7e-3 * pow(x, 4) + a / b - c - 1.01;
    return y;
}