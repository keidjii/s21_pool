#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H

#define INPUT(TYPE, FORMAT)                               \
    int input(TYPE *d, int n) {                           \
        for (int i = 0; i < n; i++) scanf(FORMAT, &d[i]); \
        return 1;                                         \
    }

#define OUTPUT(TYPE, FORMAT)              \
    void output(TYPE *d, int n) {         \
        for (int i = 0; i < n; i++)       \
            if (i == n - 1)               \
                printf(FORMAT, d[i]);     \
            else                          \
                printf(FORMAT " ", d[i]); \
    }

#endif