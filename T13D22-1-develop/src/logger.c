

#include "logger.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "log_levels.h"

FILE *log_init(char *file) {
    FILE *file_log = fopen(file, "a+");
    return file_log;
}

int logcat(FILE *log_file, char *message, enum log_level level, const char *filename) {
    char final_log[1000];
    char log_level[8];
    if (level == 0) {
        strcpy(log_level, "DEBUG");
    } else if (level == 1) {
        strcpy(log_level, "TRACE");
    } else if (level == 2) {
        strcpy(log_level, "INFO");
    } else if (level == 3) {
        strcpy(log_level, "WARNING");
    } else if (level == 4) {
        strcpy(log_level, "ERROR");
    }
    char time_message[11];
    time_t t = time(NULL);
    struct tm *tim = localtime(&t);
    sprintf(time_message, " %02d:%02d:%02d ", tim->tm_hour, tim->tm_min, tim->tm_sec);
    strcpy(final_log, log_level);
    strcat(final_log, " ");
    strcat(final_log, filename);
    strcat(final_log, " ");
    strcat(final_log, time_message);
    strcat(final_log, message);
    strcat(final_log, "\0");
    fprintf(log_file, "%s\n", final_log);
    return 0;
}

int log_close(FILE *log_file) { return fclose(log_file); }
