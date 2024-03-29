#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    double *data = NULL;
    int n;
    if (scanf("%d", &n) != 1 || n <= 0)
        printf("n/a");
    else {
        data = (double *)calloc((n), sizeof(double));
        if (input(data, n)) {
            if (normalization(data, n)) {
                output(data, n);
            } else {
                printf("ERROR");
            }
        } else {
            printf("n/a");
        }
        free(data);
        data = NULL;
    }
    return 0;
}
