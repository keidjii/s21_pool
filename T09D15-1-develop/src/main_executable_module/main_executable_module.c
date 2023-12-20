#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef MACRO
#include "../data_libs/data_io_macro.h"
INPUT(double, "%lf");
OUTPUT(double, "%.2lf");

#else
#include "../data_libs/data_io.h"
#endif

#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

int main() {
    double *data = NULL;
    int n;
    printf("LOAD DATA...\n");
    if (scanf("%d", &n) != 1 || n <= 0)
        printf("n/a");
    else {
        data = (double *)calloc((n), sizeof(double));
        if (input(data, n)) {
            printf("RAW DATA:\n\t");
            output(data, n);
            printf("\nNORMALIZED DATA:\n\t");
            if (normalization(data, n)) {
                output(data, n);
                printf("\nSORTED NORMALIZED DATA:\n\t");
                sort(data, n);
                output(data, n);
                printf("\nFINAL DECISION:\n\t");
                if (make_decision(data, n))
                    printf("YES");
                else
                    printf("NO");

                free(data);
                data = NULL;
            } else {
                printf("ERROR");
            }

        } else {
            printf("n/a");
        }
    }
    free(data);
    data = NULL;
    return 0;
}
