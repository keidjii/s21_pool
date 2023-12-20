#include <stdio.h>

int findmax(int a, int b);

int main() {
    int a, b;
    char c;

    if (scanf("%d %d%c", &a, &b, &c) == 3 && c == '\n') {
        printf("%d", findmax(a, b));
    } else
        printf("n/a");
    return 0;
}

int findmax(int a, int b) {
    int max = a;
    if (b > a) max = b;
    return max;
}