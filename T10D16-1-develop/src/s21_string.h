#ifndef S21_STRING_H
#define S21_STRING_H

int s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *destination, const char *source);
char *s21_strcat(char *destptr, const char *srcptr);
char *s21_strchr(char *string, int symbol);
char *s21_strstr(char *string1, const char *string2);
#endif