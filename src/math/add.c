#include "dsalib/math/add.h"

int unsafe_add(int a, int b) {
    return a + b;
}

int safe_add(int a, int b) {
    return -1;
}
