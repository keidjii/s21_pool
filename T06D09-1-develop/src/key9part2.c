#include <stdio.h>

#define LEN 100

void sum(int *buff1, int *buff2, int *result, int result_length);
void sub(int *buff1, int *buff2, int *result, int result_length);
void mined(int *a, int n);
int input(int *data, int *len);
void output(int *a, int n);
void sdvig(int *buffer, int length, int c);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

int main() {
    int n = LEN, n1, n2;
    int data1[n], data2[n], fin[n];
    mined(data1, n);
    mined(data2, n);
    if (input(data1, &n1) != -1 && input(data2, &n2) != -1) {
        sdvig(data1, n, n1);
        sdvig(data2, n, n2);
        sum(data1, data2, fin, n);

        printf("\n");
        if (n2 <= n1) {
            sub(data1, data2, fin, n);
            if (*fin == 0)
                output(fin, n);
            else
                printf("n/a");
        } else
            printf("n/a");

    } else
        printf("n/a");

    return 0;
}

void mined(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = 0;
    }
}

int input(int *data, int *len) {
    int fl = 1;
    *len = 1;
    for (int *p = data; p - data < LEN; p++) {
        if (scanf("%d", p) != 1 || *p > 9) {
            fl = 0;
            break;
        } else if (getchar() != '\n') {
            *len = *len + 1;
        } else
            break;
    }
    return fl;
}

void output(int *a, int n) {
    int fl = 0;
    for (int *p = a; p - a < n; p++) {
        if (fl == 0 && *p == 0)
            continue;
        else
            fl++;

        if (p == a + n - 1)
            printf("%d", *p);
        else
            printf("%d ", *p);
    }
}

void sdvig(int *buffer, int length, int c) {
    int temp[length];
    int data[length];
    for (int i = 0; i < length; i++) {
        temp[i] = (i + length + c % length) % length;
    }
    for (int i = 0; i < length; i++) {
        data[i] = buffer[temp[i]];
    }
    for (int i = 0; i < length; i++) {
        buffer[i] = data[i];
    }
}

void sum(int *buff1, int *buff2, int *result, int result_length) {
    int add = 0;
    for (int i = result_length - 1; i >= 0; i--) {
        int a = buff1[i] + buff2[i] + add;
        if (a > 9) {
            a = a - 10;
            add = 1;
        } else
            add = 0;
        result[i] = a;
    }
}
void sub(int *buff1, int *buff2, int *result, int result_length) {
    int add = 0;
    for (int i = result_length - 1; i >= 0; i--) {
        int a = buff1[i] - buff2[i] - add;
        if (a < 0) {
            a = a + 10;
            add = 1;
        } else
            add = 0;
        result[i] = a;
    }
}