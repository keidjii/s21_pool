
#include <stdio.h>
#include <stdlib.h>

#define ERROR_FILE_OPEN -3
struct my_struct read_record_from_file(FILE *pfile, int index);
int get_records_count_in_file(FILE *pfile);
int get_file_size_in_bytes(FILE *pfile);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index);

void sort(FILE *f);
int input(char **str);
void print_file(FILE *f);
void print_menu(FILE *file);
int write_file(FILE *file);

FILE *read_file();
struct my_struct {
    int year;
    int moth;
    int day;
    int hour;
    int min;
    int sec;
    int stat;
    int code;
};

int main() {
    print_menu(NULL);
    return 0;
}

void print_menu(FILE *file) {
    if (file == NULL) file = read_file();

    if (file != NULL) {
        char ch = getchar();
        switch (ch) {
            case '0': {
                print_file(file);
                break;
            }
            case '1': {
                sort(file);
                print_file(file);
                break;
            }
            case '2': {
                if (write_file(file))
                    print_file(file);
                else
                    break;
            }
            default: {
                printf("n/a");
                fclose(file);
            }
        }
    }
}

FILE *read_file() {
    char *buf = NULL;
    FILE *file;
    input(&buf);
    if ((file = fopen(buf, "r+b")) == NULL) {
        {
            free(buf);
            buf = NULL;
            printf("n/a2");
        }
    }
    return file;
}

void print_file(FILE *f) {
    printf("heh");
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
int write_file(FILE *file) {
    int size = get_records_count_in_file(file);
    const struct my_struct str_inp = {0};
    int fl = 0;

    if (scanf("%d", &str_inp.year) == 1 && str_inp.year > 1900) fl++;
    if (scanf("%d", &str_inp.moth) == 1 && str_inp.moth >= 1 && str_inp.moth < +12) fl++;
    if (scanf("%d", &str_inp.day) == 1 && str_inp.day >= 1 && str_inp.day <= 31) fl++;
    if (scanf("%d", &str_inp.hour) == 1 && str_inp.hour >= 0 && str_inp.hour <= 23) fl++;
    if (scanf("%d", &str_inp.min) == 1 && str_inp.min >= 0 && str_inp.min <= 59) fl++;
    if (scanf("%d", &str_inp.sec) == 1 && str_inp.sec >= 0 && str_inp.sec <= 59) fl++;
    if (scanf("%d", &str_inp.stat) == 1 && (str_inp.stat == 0 || str_inp.stat == 1)) fl++;
    if (scanf("%d", &str_inp.code) == 1 && str_inp.code >= 0) fl++;

    if (fl == 8)
        write_record_in_file(file, &str_inp, size);
    else
        printf("n/a");

    return (fl == 8);
}

void sort(FILE *f) {
    int k;
    struct my_struct a1, a2;
    int n = get_records_count_in_file(f);
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            k = 0;
            a1 = read_record_from_file(f, j);
            a2 = read_record_from_file(f, j + 1);
            if (a1.year != a2.year) {
                k = a1.year > a2.year ? 1 : 0;
            } else if (a1.moth != a2.moth) {
                k = a1.moth > a2.moth ? 1 : 0;
            } else if (a1.day != a2.day) {
                k = a1.day > a2.day ? 1 : 0;
            } else if (a1.year != a2.hour) {
                k = a1.hour > a2.hour ? 1 : 0;
            } else if (a1.min != a2.min) {
                k = a1.min > a2.min ? 1 : 0;
            } else if (a1.sec != a2.sec) {
                k = a1.sec > a2.sec ? 1 : 0;
            }
            if (k) {
                swap_records_in_file(f, j, j + 1);
            }
        }
}

int input(char **str) {
    *str = (char *)malloc(16 * sizeof(char));
    int size = 16;
    int count = 0;
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
    (*str)[count] = '\0';
    int result;
    if (count) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

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
