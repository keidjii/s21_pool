/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10
int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n, data[NMAX], nums[NMAX];
    if (input(data, &n) != -1) {
        int numb = sum_numbers(data, n);
        if (numb) {
            printf("%d\n", numb);
            int n1 = find_numbers(data, n, numb, nums);
            output(nums, n1);
        } else
            printf("n/a");
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > 10) *n = -1;
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
            printf("%d", *p);
        else
            printf("%d ", *p);
    }
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;
    for (int i = 0; i < length; i++)
        if (buffer[i] == 0)
            continue;
        else if (number % buffer[i] == 0) {
            numbers[j] = buffer[i];
            j++;
        }
    return j;
}
