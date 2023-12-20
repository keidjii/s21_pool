#include "filework.h"

#include <stdio.h>
#include <string.h>

struct my_struct read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);
    struct my_struct record;
    fread(&record, sizeof(struct my_struct), 1, pfile);
    rewind(pfile);
    return record;
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) {
    return get_file_size_in_bytes(pfile) / sizeof(struct my_struct);
}

void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index) {
    int offset = index * sizeof(struct my_struct);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(struct my_struct), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    struct my_struct record1 = read_record_from_file(pfile, record_index1);
    struct my_struct record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

FILE *read_file() {
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
    free(buf);
    return file;
}

int input(char **str) {
    *str = (char *)malloc(16 * sizeof(char));
    int size = 16;
    (*str)[0] = '.';
    (*str)[1] = '.';
    (*str)[2] = '/';
    int count = 3;
    char curr;
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
    int result;
    if (count) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

void print_file(FILE *f) {
    int size = get_records_count_in_file(f);
    struct my_struct heh[size];
    for (int i = 0; i < size; i++) {
        heh[i] = read_record_from_file(f, i);
        printf("%d ", heh[i].year);
        printf("%d ", heh[i].moth);
        printf("%d ", heh[i].day);
        printf("%d ", heh[i].hour);
        printf("%d ", heh[i].min);
        printf("%d ", heh[i].sec);
        printf("%d ", heh[i].stat);
        printf("%d\n", heh[i].code);
    }
}