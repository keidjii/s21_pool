#include <stdio.h>
#include <stdlib.h>

#include "filework.h"
int check_range(struct my_struct data, int year, int month, int day);

int main() {
    char *buf = NULL;
    FILE *file;
    input(&buf);
    if ((file = fopen(buf, "r+b")) == NULL) {
        {
            free(buf);
            buf = NULL;
            file = NULL;
            printf("n/a");
        }
    }

    FILE *tempFile = tmpfile();

    if (file != NULL) {
        int size = get_records_count_in_file(file);
        int a1, b, c, e, f, g;

        if (scanf("%d.%d.%d", &a1, &b, &c) == 3 && scanf("%d.%d.%d", &e, &f, &g) == 3) {
            struct my_struct data_beg = {c, b, a1, 0, 0, 0, 0, 0};
            struct my_struct data_end = {g, f, e, 0, 0, 0, 0, 0};
            int j = 0;
            for (int i = 0; i < size; i++) {
                struct my_struct a = read_record_from_file(file, i);

                if (!check_range(a, data_beg.year, data_beg.moth, data_beg.day) ||
                    check_range(a, data_end.year, data_end.moth, data_end.day)) {
                    write_record_in_file(tempFile, &a, j);
                    j++;
                }
            }
        } else
            printf("n/a");
        fclose(file);
    }

    if ((file = fopen(buf, "w+b")) == NULL) {
        {
            free(buf);
            buf = NULL;
            file = NULL;
            printf("n/a");
        }
    }

    if (file != NULL) {
        char c;
        rewind(file);
        rewind(tempFile);
        while ((c = fgetc(tempFile)) != EOF) {
            fputc(c, file);
        }

        print_file(file);

        fclose(file);
    }

    fclose(tempFile);
    return 0;
}


int check_range(struct my_struct data, int year, int month, int day) {
    int result = 1;
    if (data.year < year) result = 0;
    if (data.year > year) result = 1;
    if (data.year == year) {
        if (data.moth < month) result = 0;
        if (data.moth > month) result = 1;
        if (data.moth == month) {
            if (data.day < day) result = 0;
            if (data.day > day) result = 1;
            if (data.day == day) result = 0;
        }
    }
    return result;
}