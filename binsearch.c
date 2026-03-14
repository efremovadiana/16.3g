#include "binsearch.h"

int bin_search(const void *array, size_t size, size_t count,
               const void *el, cmp_t cmp) {
    if (count == 0 || array == NULL || el == NULL || cmp == NULL) {
        return 0;
    }


    const char *base = (const char *)array;
    const char *left = base;
    const char *right = base + (count - 1) * size;

    while (left <= right) {
        size_t mid_index = (right - left) / (2 * size);
        const char *mid = left + mid_index * size;

        int cmp_result = cmp(el, mid);

        if (cmp_result == 0) {
            return 1;
        } else if (cmp_result < 0) {
            right = mid - size;
        } else {
            left = mid + size;
        }
    }

    return 0;
}
