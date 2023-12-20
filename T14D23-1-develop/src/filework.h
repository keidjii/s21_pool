#ifndef FILEWORK_H
#define FILEWORK_H
#include <stdio.h>
#include <stdlib.h>

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

struct my_struct read_record_from_file(FILE *pfile, int index);
int get_records_count_in_file(FILE *pfile);
int get_file_size_in_bytes(FILE *pfile);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
void write_record_in_file(FILE *pfile, const struct my_struct *record_to_write, int index);
FILE *read_file();
int input(char **str);
void print_file(FILE *f);

#endif
