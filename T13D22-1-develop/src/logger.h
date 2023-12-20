#ifndef LOGGER_H
#define LOGGER_H
#include "log_levels.h"

FILE *log_init(char *file);
int logcat(FILE *log_file, char *message, enum log_level level, const char *filename);
int log_close(FILE *log_file);

#endif