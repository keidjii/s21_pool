#include <stdio.h>

int ocr(double x, double y);

int main() {
    double a, b;
    char c;

    if (scanf("%lf%lf%c", &a, &b, &c) == 3 && c == '\n') {
        if (ocr(a, b))
            printf("GOTCHA");
        else
            printf("MISS");

    } else
        printf("n/a");
    return 0;
}

int ocr(double x, double y) { return ((x*x + y*y) < 25); }