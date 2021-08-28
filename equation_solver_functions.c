#include "equation.h"

int linear_equation(double k, double b, double solutions[]) {

    assert (isfinite (k));
    assert (isfinite (b));
    assert (solutions != NULL);

    if (!check_zero(k)) {
        if (!check_zero(b)) {
            return INFINITY_SOLUTIONS;
        }
        else {
            return NO_SOLUTIONS;
        }
    }
    else {
        solutions[0] = (-b) / k;

        return ONE_SOLUTION;
    }
}

int square_equation(double a, double b, double c, double solutions[]) {

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));
    assert (solutions != NULL);

    if (!check_zero(a)) {
        return linear_equation(b, c, solutions);
    }

    if (c == 0) {
        solutions[1] = 0;
        int linear_solutions = linear_equation(a, b, solutions);
        if (linear_solutions != ONE_SOLUTION ||
            (linear_solutions == ONE_SOLUTION && solutions[0] == solutions[1])) {
            solutions[0] = 0;
            return ONE_SOLUTION;
        }
        else {
            return TWO_SOLUTIONS;
        }
    }

    double discriminant = b * b - 4 * a * c;

    if (!check_zero(discriminant)) {
        solutions[0] = check_zero((-b) / (2 * a));

        return ONE_SOLUTION;
    }

    else if (discriminant > 0) {
        double discriminant_sqrt = sqrt(discriminant);

        solutions[0] = check_zero((-b - discriminant_sqrt) / (2 * a));
        solutions[1] = check_zero((-b + discriminant_sqrt) / (2 * a));

        if (double_equality(solutions[0], solutions[1])) {
            return ONE_SOLUTION;
        }

        return TWO_SOLUTIONS;
    }
    else {
        return NO_SOLUTIONS;
    }

}
