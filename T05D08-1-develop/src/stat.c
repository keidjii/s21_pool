#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) != -1) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(n));
    } else
        printf("n/a");
    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n < 0 || *n > 10) *n = -1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1 || getchar() > 32) {
            *n = -1;
            break;
        }
    }
    return *n;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p == a + n - 1)
            printf("%d\n", *p);
        else
            printf("%d ", *p);
    }
}

int max(int *a, int n) {
    int max = *a;

    for (int *p = a; p - a < n; p++)
        if (*p > max) max = *p;

    return max;
}

int min(int *a, int n) {
    int min = *a;
    for (int *p = a; p - a < n; p++)
        if (*p < min) min = *p;
    return min;
}

double mean(int *a, int n) { return (double)(*a + *(a + n - 1)) / 2; }

double variance(int n) { return ((double)(n * n - 1) / 12); }

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %lf %lf", max_v, min_v, mean_v, variance_v);
}