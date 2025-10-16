#include "dsalib/math/add.h"

int unsafe_add(int a, int b) {
    return a + b;
}

int safe_add(int a, int b) {
    int sum = a + b;
    if (a > 0 && b > 0 && sum < 0) {
        printf("Error: integer overflow\n");
        return 0;
    }
    if (a < 0 && b < 0 && sum > 0) {
        printf("Error: integer underflow\n");
        return 0;
    }
    return sum;
}
