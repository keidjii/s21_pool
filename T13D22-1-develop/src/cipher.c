#include <dirent.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LOG_MACROS
#include "log_levels.h"
#include "logger.h"
#endif

void print_menu(char *filename);
int input(char **str);
char *read_file();
void write_file(char *filename);

void crypto(int n, char *filename);
void dircheck(char *dirname, int n);
void shifer();

int main() {
    setlocale(LC_ALL, "Russian");
    print_menu(NULL);

    return 0;
}

void print_menu(char *filename) {
    char ch = getchar();

    if (ch == '1') {
        free(filename);
        filename = read_file();
        if (filename != NULL) {
            printf("\n");
            print_menu(filename);
        } else {
            printf("n/a\n");
        }

    } else if (ch == '2')
        if (filename != NULL) {
            write_file(filename);
            printf("\n");
            print_menu(filename);
        } else
            printf("n/a\n");

    else if (ch == '3') {
        { shifer(); }
    } else if (ch == '-') {
        if (getchar() == '1') free(filename);

    } else {
        free(filename);
        printf("n/a");
    }
}

char *read_file() {  //чтение файла
    char *buf;
    input(&buf);
#ifdef LOG_MACROS
    char *filename = strdup(buf);
    FILE *log_file = log_init("files.log");
#endif
    char c;
    FILE *file;
    char *fp = buf;
    if ((file = fopen(fp, "r")) == NULL) {
        {
            free(buf);
            buf = NULL;
        }
    } else {
#ifdef LOG_MACROS
        logcat(log_file, "файл открыли для чтения", info, filename);
#endif
#ifdef LOG_MACROS
        log_close(log_file);
        free(filename);
#endif
        while (fscanf(file, "%c", &c) != EOF) {
            printf("%c", c);
        }
    }
    printf("\n");
    fclose(file);
    return buf;
}

void write_file(char *filenm) {  //запись строки в файл
    char *buf;
    input(&buf);
#ifdef LOG_MACROS
    char *filename = strdup(filenm);
    FILE *log_file = log_init("files.log");
#endif

    FILE *file;
    char *fp = filenm;

    if ((file = fopen(fp, "a")) == NULL) {
        free(filenm);
        printf("n/a");
    } else {
#ifdef LOG_MACROS
        logcat(log_file, "файл открыли чтобы поменять", trace, filename);
#endif
        fprintf(file, "\n");
        fprintf(file, buf);
#ifdef LOG_MACROS
        logcat(log_file, "в файл добавили строку", trace, filename);
#endif
#ifdef LOG_MACROS
        log_close(log_file);
        free(filename);
#endif
        fclose(file);
    }

    free(buf);
}

int input(char **str) {
    *str = (char *)malloc(16 * sizeof(char));
    int size = 16;
    int count = 0;
    char curr = getchar();
    scanf("%c", &curr);
    while (curr != '\n') {
        count++;
        if (count >= size) {
            size *= 2;
            *str = realloc(*str, size * sizeof(char));
        }
        (*str)[count - 1] = curr;
        scanf("%c", &curr);
    }
    if (size == count) {
        *str = realloc(*str, ++count * sizeof(char));
    }
    (*str)[count] = '\0';
    int result;
    if (count) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void shifer() {  //главнаяшифровка
    char *dirname;
    input(&dirname);
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a3");
    } else {
        dircheck(dirname, n);
    }
    free(dirname);
}

void dircheck(char *dirname, int n) {  //поиск сишек ашек в директории+шифровка
    char *buf = NULL;
    char *buf1 = NULL;
    DIR *dir;

    if ((dir = opendir(dirname)) != NULL) {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            char *c = entry->d_name;
            if (strstr(c, ".c")) {
                buf = (char *)malloc(sizeof(dirname) + sizeof(c) + sizeof(char));
                strcat(buf, dirname);
                strcat(buf, "/");
                strcat(buf, c);
                crypto(n, buf);
            } else if (strstr(c, ".h")) {
                buf1 = (char *)malloc(sizeof(dirname) + sizeof(c) + sizeof(char));
                strcat(buf1, dirname);
                strcat(buf1, "/");
                strcat(buf1, c);
                FILE *file1;
                char *fp1 = buf1;
                if ((file1 = fopen(fp1, "w")) == NULL)
                    printf("n/a");
                else
                    fclose(file1);
            }
        }
#ifdef LOG_MACROS
        char *filename = strdup(buf);
        FILE *log_file = log_init("files.log");
        logcat(log_file, "файл открыли чтобы поменять", trace, filename);
        logcat(log_file, "файл очистили", warning, filename);
        log_close(log_file);
        free(filename);
#endif
        free(buf);
        free(buf1);
        closedir(dir);
    } else
        printf("n/a");
}

void crypto(int n, char *filename) {  //шифр цезаря
#ifdef LOG_MACROS
    char *filename1 = strdup(filename);
#endif
#ifdef LOG_MACROS
    FILE *log_file = log_init("files.log");
#endif
    FILE *file1;
    FILE *tempFile = tmpfile();
    char *fp1 = filename;
    if ((file1 = fopen(fp1, "r+")) == NULL || tempFile == NULL)
        printf("n/a");
    else {
#ifdef LOG_MACROS
        logcat(log_file, "файл открыли чтобы поменять", trace, filename1);
#endif
        char c;
        c = getc(file1);
        while (!feof(file1)) {
            int flag = 0;
            if (c >= 'A' && c <= 'Z') {
                c = c + (n % 26);
                if (c > 'Z') c = 'A' + (c - 'Z') - 1;
                fprintf(tempFile, "%c", c);
                flag = 1;
            }
            if (c >= 'a' && c <= 'z') {
                c = c + (n % 26);
                if (c > 'z') c = 'a' + (c - 'z') - 1;
                fprintf(tempFile, "%c", c);
                flag = 1;
            }
            if (!flag) fprintf(tempFile, "%c", c);
            c = getc(file1);
        }
        rewind(tempFile);
        rewind(file1);
        while ((c = fgetc(tempFile)) != EOF) {
            fputc(c, file1);
        }
#ifdef LOG_MACROS
        logcat(log_file, "файл зашифровали", trace, filename1);
        log_close(log_file);
        free(filename1);
#endif
        fclose(file1);
        fclose(tempFile);
    }
}
