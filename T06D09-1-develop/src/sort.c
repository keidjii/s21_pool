#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);
void swap(int *a, int *b);

int main() {
    int n = NMAX, data[NMAX];
    if (input(data, n)) {
        sort(data, n);
        output(data, n);
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int n) {
    int fl = 1;
    for (int *p = a; p - a < n; p++)
        if (scanf("%d", p) != 1 || getchar() > 32) {
            fl = 0;
            break;
        }
    return fl;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p == a + n - 1)
            printf("%d", *p);
        else
            printf("%d ", *p);
    }
}

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int *p = a; p - a < n - i - 1; p++)
            if (*(p) > *(p + 1)) swap(p, p + 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}