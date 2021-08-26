#include "equation.h"

int double_equality(double first, double second) {
    if (fabs(first - second) < DOUBLE_ERROR) {
        return 1;
    }
    return 0;
}

double check_zero(double val) {

    assert (isfinite (val));

    if (double_equality(val, 0)) {
        return 0;
    }
    return val;
}