#include <stdio.h>

int sum(int a, int b);
int razn(int a, int b);
int proizv(int a, int b);
int cha(int a, int b);

int main() {
    int a, b;
    char c;

    if (scanf("%d %d%c", &a, &b, &c) == 3 && c == '\n') {
        // a = (int)a;
        // b = (int)b;
        printf("%d ", sum(a, b));
        printf("%d ", razn(a, b));
        printf("%d ", proizv(a, b));
        if (b != 0)
            printf("%d ", cha(a, b));
        else
            printf("n/a");
    } else
        printf("n/a");
    return 0;
}

int sum(int a, int b) { return a + b; }

int razn(int a, int b) { return a - b; }

int proizv(int a, int b) { return a * b; }

int cha(int a, int b) { return a / b; }