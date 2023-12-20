#include "data_stat.h"

#include <math.h>
// день 8 search

double max(double *data, int n) {
    double max = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max) max = data[i];
    }
    return max;
}

double min(double *data, int n) {
    double min = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min) min = data[i];
    }
    return min;
}

double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += data[i] / n;
    return sum;
}

double variance(double *data, int n) {
    double m = mean(data, n);
    double sum = 0;
    for (int i = 0; i < n; i++) sum += pow(data[i] - m, 2);
    sum = sum / n;
    return sum;
}

void sort(double *data, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (data[j] > data[j + 1]) swap(&data[j], &data[j + 1]);
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}
