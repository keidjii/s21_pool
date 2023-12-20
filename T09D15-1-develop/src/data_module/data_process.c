#include "data_process.h"

#include <math.h>

#include "../data_libs/data_stat.h"

int normalization(double *d, int n) {
    int result = 1;
    double max_value = max(d, n);
    double min_value = min(d, n);
    double size = max_value - min_value;
    if (fabs(size) > EPS) {
        if (size == 0) {
            result = 0;
        } else {
            for (int i = 0; i < n; i++) {
                d[i] = d[i] / size - min_value / size;
                result = 1;
            }
        }
    } else {
        result = 0;
    }
    return result;
}
