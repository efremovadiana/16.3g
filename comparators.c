#include "comparators.h"
#include <string.h>

int cmp_int(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

int cmp_double(const void *a, const void *b) {
    double da = *(const double *)a;
    double db = *(const double *)b;
    if (da < db) return -1;
    if (da > db) return 1;
    return 0;
}

int cmp_str(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
