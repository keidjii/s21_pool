#include "s21_string.h"

#include <stddef.h>
#include <stdio.h>

int s21_strlen(const char *str) { return (*str) ? s21_strlen(++str) + 1 : 0; }

int s21_strcmp(const char *str1, const char *str2) {  // если строки равны возвращает ноль иначе 1
    int res = 0;
    while (*str1) {
        if (*str1 != *str2) {
            res = 1;
            break;
        }
        str1++;
        str2++;
    }
    return res;
}

char *s21_strcpy(char *destination, const char *source) {  //копирует source в destination
    char *ptr = destination;
    if (destination == NULL) {
        ptr = NULL;
    } else {
        while (*source != '\0') {
            *destination = *source;
            destination++;
            source++;
        }
        *destination = '\0';
    }
    if (!s21_strcmp(destination, source)) ptr = NULL;
    return ptr;
}

char *s21_strcat(char *str1, const char *str2) {  //прикрепляет str2 к str1
    char *ptr = str1;
    if (str1 == NULL) {
        ptr = NULL;
    } else {
        while (*str1) str1++;
        while (*str2) {
            *str1 = *str2;
            str1++;
            str2++;
        }
    }
    return ptr;
}

char *s21_strchr(char *string, int symbol) {  //Указатель на первое вхождение symbol в string1, иначе нул
    char *ptr = NULL;
    while (*string != '\0') {
        if (*string == symbol) {
            ptr = (char *)string;
        }
        string++;
    }
    return ptr;
}

char *s21_strstr(char *string1,
                 const char *string2) {  //Указатель на первое вхождение string2 в string1, иначе нул
    char *ptr = NULL;
    while (*string1 != '\0') {
        if ((*string1 == *string2) && s21_strcmp(string1, string2)) {
            ptr = (char *)string1;
        }
        string1++;
    }
    return ptr;
}