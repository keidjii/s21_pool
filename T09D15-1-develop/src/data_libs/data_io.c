#include <stdio.h>
#include <stdlib.h>

int input(double *d, int n) {
    int fl = 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &d[i]) != 1) {
            fl = 0;
            break;
        }
    }
    return fl;
}

void output(double *d, int n) {
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%.2lf", d[i]);
        else
            printf("%.2lf ", d[i]);
    }
}
