#include <stdio.h>
#include <stdlib.h>

#define NMAX 100
int nyam(int *n, int *m);
int opsh(int *op);

int Static_input(int *a, int n, int m);
void Static_output(int *a, int n, int m);

int **Din1(int n, int m);
int **Din2(int n, int m);
int **Din3(int n, int m);

int Input1(int **a, int n, int m);
void Output1(int **a, int n, int m);

int main() {
    int op;
    int n, m;
    if (opsh(&op) && nyam(&n, &m)) {
        if (op == 1) {
            int data[n][m];
            if (Static_input(&data[0][0], n, m))
                Static_output(&data[0][0], n, m);
            else
                printf("n/a");
        } else if (op == 2) {
            int **data = Din1(n, m);
            if (Input1(data, n, m)) {
                Output1(data, n, m);
                for (int i = 0; i < n; i++) free(data[i]);
                free(data);
            } else
                printf("n/a");
        } else if (op == 3) {
            int **data = Din2(n, m);
            if (Input1(data, n, m)) {
                Output1(data, n, m);
                free(data);
            } else
                printf("n/a");
        } else {
            int **data = Din3(n, m);
            if (Input1(data, n, m)) {
                Output1(data, n, m);
                free(data);
            } else
                printf("n/a");
        }
        return 0;
    } else
        printf("n/a");
}

int opsh(int *op) {
    if (scanf("%d", op) != 1 || *op <= 0 || *op > 4) *op = 0;
    return *op;
}

int nyam(int *n, int *m) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) *n = 0;
    if (scanf("%d", m) != 1 || *m <= 0 || *m > NMAX) *n = 0;
    return *n;
}

int Static_input(int *a, int n, int m) {
    int fl = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (scanf("%d", a + i * m + j) != 1 || getchar() > 32) {
                fl = 0;
                break;
            }
        }
    return fl;
}

void Static_output(int *a, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j == m - 1)
                printf("%d\n", *(a + i * m + j));
            else
                printf("%d ", *(a + i * m + j));
        }
}

int **Din1(int n, int m) {
    int **point_arr = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) point_arr[i] = malloc(m * sizeof(int));
    return point_arr;
}

int **Din2(int n, int m) {
    int **point_arr = malloc(n * m * sizeof(int) + n * sizeof(int *));
    int *point = (int *)(point_arr + n);

    for (int i = 0; i < n; i++) point_arr[i] = point + m * i;

    return point_arr;
}

int **Din3(int n, int m) {
    int **point_arr = malloc(n * sizeof(int *));
    int *point = malloc(n * m * sizeof(int));
    for (int i = 0; i < n; i++) point_arr[i] = point + m * i;
    free(point);
    return point_arr;
}

int Input1(int **a, int n, int m) {
    int fl = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &a[i][j]) != 1 || getchar() > 32) {
                fl = 0;
                break;
            }
        }
    return fl;
}

void Output1(int **a, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if ((j == m - 1) && (i != n - 1))
                printf("%d\n", a[i][j]);
            else if ((j == m - 1) && (i == n - 1))
                printf("%d", a[i][j]);
            else
                printf("%d ", a[i][j]);
        }
}
