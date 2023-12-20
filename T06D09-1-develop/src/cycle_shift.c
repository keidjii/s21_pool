#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length, int *c);
void output(int *buffer, int length);
void sdvig(int *buffer, int length, int n, int *numbers);

int main() {
    int n, c, data[NMAX], nums[NMAX];
    if (input(data, &n, &c) != -1) {
        sdvig(data, n, c, nums);
        output(nums, n);
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n, int *c) {
    if (scanf("%d", n) != 1 || *n < 0 || *n > 10) *n = -1;
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1 || getchar() > 32) {
            *n = -1;
            break;
        }
    }
    if (scanf("%d", c) != 1) *n = -1;
    return *n;
}

void output(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        if (p == a + n - 1)
            printf("%d", *p);
        else
            printf("%d ", *p);
    }
}

void sdvig(int *buffer, int length, int c, int *numbers) {
    int temp[length];
    for (int i = 0; i < length; i++) {
        temp[i] = (i + length + c % length) % length;
    }
    for (int i = 0; i < length; i++) numbers[i] = buffer[temp[i]];
}