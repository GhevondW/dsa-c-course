#include "dsalib/search/binary_search.h"
#include <limits.h>
#include <stddef.h>

size_t dsalib_lower_bound(const int* arr, size_t size, int target) {
    if (!arr || size == 0) return 0;       // per tests
    size_t lo = 0, hi = size;              // [lo, hi)
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo; // in [0..size]
}

int dsalib_binary_search(const int* arr, size_t size, int target) {
    if (!arr || size == 0) return -1;
    size_t lo = 0, hi = size;              // search in [lo, hi)
    while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        int v = arr[mid];
        if (v == target) return (int)mid;
        if (v < target) lo = mid + 1;
        else hi = mid;
    }
    return -1;
}

int dsalib_binary_search_recursive(const int* arr, int left, int right, int target) {
    if (!arr || left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target)
        return dsalib_binary_search_recursive(arr, mid + 1, right, target);
    else
        return dsalib_binary_search_recursive(arr, left, mid - 1, target);
}
