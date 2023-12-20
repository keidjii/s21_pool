#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) { return putchar(ch); }

void print_log(char (*print_char)(char), char* message) {
    time_t current_time;
    struct tm* timeinfo;
    time(&current_time);
    timeinfo = localtime(&current_time);

    char time_str[9];
    strftime(time_str, sizeof(time_str), "%H:%M:%S", timeinfo);

    char log[6] = Log_prefix;

    for (int i = 0; i < 9; i++) print_char(log[i]);

    print_char(' ');

    for (int i = 0; i < 9; i++) print_char(time_str[i]);

    print_char(' ');

    char* p = message;
    while (*p != '\0') {
        print_char(*p);
        p++;
    }
}