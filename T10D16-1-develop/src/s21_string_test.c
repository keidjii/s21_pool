#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test() {  //возвращает количество элементов в строке
    char *test1 = "hehehe", *test2 = "f", *test3 = "";
    int rez1 = 6, rez2 = 1, rez3 = 0;
    int d = 0;

    d = s21_strlen(test1);
    printf("%s|%d\n", test1, d);
    if (d == rez1)
        printf("SUCCESS\n");
    else
        printf("FAIL");

    d = s21_strlen(test2);
    printf("%s|%d\n", test2, d);
    if (d == rez2)
        printf("SUCCESS\n");
    else
        printf("FAIL");

    d = s21_strlen(test3);
    printf("%s|%d\n", test3, d);
    if (d == rez3)
        printf("SUCCESS\n");
    else
        printf("FAIL");
}

void s21_strcmp_test() {  //возвращет ноль если строки равны
    char *test1 = "hehehe", *test2 = "pu", *test3 = "hehehe", *test4 = "pu";
    int res = 0;

    res = s21_strcmp(test1, test2);
    printf("%s|%s|%d\n", test1, test2, res);
    if (res == 1)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    res = s21_strcmp(test3, test4);
    printf("%s|%s|%d\n", test3, test4, res);
    if (res == 1)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    res = s21_strcmp(test1, test3);
    printf("%s|%s|%d\n", test1, test3, res);
    if (res == 0)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    res = s21_strcmp(test2, test4);
    printf("%s|%s|%d\n", test2, test4, res);
    if (res == 0)
        printf("SUCCESS");
    else
        printf("FAIL");
}

void s21_strcpy_test() {  //копирует второй аргумент в первый, возвращает NULL если не вышло(
    char *test1 = "hehehe", *test2 = "333", *test3 = "";

    char *destination = malloc(s21_strlen(test1) * sizeof(char));
    s21_strcpy(destination, test1);
    printf("%s|%s\n", test1, destination);
    if (!s21_strcmp(test1, destination))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    free(destination);

    destination = malloc(s21_strlen(test2) * sizeof(char));
    s21_strcpy(destination, test2);
    printf("%s|%s\n", test2, destination);
    if (!s21_strcmp(test2, destination))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    free(destination);

    destination = malloc(s21_strlen(test3) * sizeof(char));
    s21_strcpy(destination, test3);
    printf("%s|%s\n", test3, destination);
    if (!s21_strcmp(test3, destination))
        printf("SUCCESS");
    else {
        printf("FAIL");
    }
    free(destination);
}

void s21_strcat_test() {  //прикреплят второй аргумент к первому
    char *test0 = "When i was ", *test1 = "a young boy", *test2 = " my father", *test3 = "";
    char *str = malloc(sizeof(char));
    char *res0 = "When i was ";

    str = (char *)realloc(str, (s21_strlen(str) + s21_strlen(test0)) * sizeof(char));
    s21_strcat(str, test0);
    printf("%s|%s|\n", " ", test0);
    if (!s21_strcmp(res0, str))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char *res1 = "When i was a young boy";
    str = (char *)realloc(str, (s21_strlen(str) + s21_strlen(test1)) * sizeof(char));
    s21_strcat(str, test1);
    printf("%s|%s|%s\n", test0, test1, str);
    if (!s21_strcmp(res1, str))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char *res2 = "When i was a young boy my father";
    str = (char *)realloc(str, (s21_strlen(str) + s21_strlen(test2)) * sizeof(char));
    s21_strcat(str, test2);
    printf("%s|%s|%s\n", res1, test2, str);
    if (!s21_strcmp(res2, str))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    char *res3 = "When i was a young boy my father";
    str = (char *)realloc(str, (s21_strlen(str) + s21_strlen(test3)) * sizeof(char));
    s21_strcat(str, test3);
    printf("%s|%s|%s\n", res2, test3, str);
    if (!s21_strcmp(res3, str))
        printf("SUCCESS");
    else
        printf("FAIL");

    free(str);
}

void s21_strchr_test() {  //возвращает указатель на первое вхождение символа в строку, иначе null
    char *test1 = "yo! ", *test2 = "how do you do ", *test3 = "fellow kids", *test4 = " ";
    char *res;

    res = s21_strchr(test1, '!');
    printf("%s|%c\n", test1, '!');
    if (*res == '!')
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    res = s21_strchr(test2, 'd');
    printf("%s|%c\n", test2, 'd');
    if (*res == 'd')
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("%s|%c\n", test3, 'd');
    if (s21_strchr(test4, 'd') == NULL) {
        printf("SUCCESS\n");
    } else
        printf("FAIL\n");

    printf("%s|%c\n", test4, 'd');
    if (s21_strchr(test4, 'd') == NULL)
        printf("SUCCESS");
    else
        printf("FAIL");
}

void s21_strstr_test() {  //возвращает указатель на первое вхождение cтроки в строку, иначе null
    char *test1 = "Blin klass", *test2 = "Blin", *test3 = "way", *test4 = "o";

    printf("%s|%s\n", test1, test2);
    if (s21_strstr(test1, test2))
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("%s|%s\n", test3, test4);
    if (s21_strstr(test3, test4) == NULL)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("%s|%s\n", test1, test4);
    if (s21_strstr(test3, test4) == NULL)
        printf("SUCCESS");
    else
        printf("FAIL");
}

int main() {
#ifdef STRLEN
    s21_strlen_test();
#elif STRCMP
    s21_strcmp_test();
#elif STRCPY
    s21_strcpy_test();
#elif STRCAT
    s21_strcat_test();
#elif STRCHR
    s21_strchr_test();
#elif STRSTR
    s21_strstr_test();
#endif
    return 0;
}