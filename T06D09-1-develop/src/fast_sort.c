#include <stdio.h>
#define NMAX 10

int input(int *a, int n);
void output(int *a, int n);
void qsort(int *a, int n);
void pirsort(int *a, int n);

int main() {
    int n = NMAX, data[NMAX];
    if (input(data, n)) {
        pirsort(data, n);
        output(data, n);
        printf("\n");
        qsort(data, n);
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

void qsort(int *mas, int size) {
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsort(mas, j + 1);
    }
    if (i < size) {
        qsort(&mas[i], size - i);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void pirsort(int *a, int n) {
    int sh = 0, b = 0;
    while (1) {
        b = 0;
        for (int i = 0; i < n; ++i) {
            if (2 * i + 2 + sh < n) {
                if (a[i + sh] > a[2 * i + 1 + sh] || a[i + sh] > a[2 * i + 2 + sh]) {
                    if (a[2 * i + 1 + sh] < a[2 * i + 2 + sh]) {
                        swap(&a[i + sh], &a[2 * i + 1 + sh]);
                        b = 1;
                    } else if (a[2 * i + 2 + sh] < a[2 * i + 1 + sh]) {
                        swap(&a[i + sh], &a[2 * i + 2 + sh]);
                        b = 1;
                    }
                }
            } else if (2 * i + 1 + sh < n) {
                if (a[i + sh] > a[2 * i + 1 + sh]) {
                    swap(&a[i + sh], &a[2 * i + 1 + sh]);
                    b = 1;
                }
            }
        }
        if (!b) sh++;
        if (sh + 2 == n) break;
    }
}
