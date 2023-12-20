/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/
#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n, double mean, double variance);
int even(int a);
double mean(int *a, int n);
double variance(int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != -1) {
        output(data, n, mean(data, n), variance(n));
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    if ((scanf("%d", n) != 1) || *n < 0 || *n > 30) *n = -1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1 || getchar() > 32) {
            *n = -1;
            break;
        }
    }
    return *n;
}

void output(int *a, int n, double mean, double variance) {
    int fl = 1;
    for (int *p = a; p - a < n; p++) {
        if (even(*p) && *p >= mean && *p <= mean + 3 * sqrt(variance) && *p != 0) {
            printf("%d", *p);
            fl = 0;
            break;
        }
    }
    if (fl) printf("%d", 0);
}

int even(int a) {
    int rez = 0;
    if (a % 2 == 0) rez = 1;
    return rez;
}

double mean(int *a, int n) { return (double)(*a + *(a + n - 1)) / 2; }
double variance(int n) { return ((double)(n * n - 1) / 12); }