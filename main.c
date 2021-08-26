//! @mainpage
//! - main.c

#include "equation.h"

//!
//! Функция принимает на вход коэффициенты a, b, c квадратного уравнения.
//! Пишет количество решений и сами корни
int main() {

    #ifndef NDEBUG_MODE
    run_all_tests();
    #endif

    double a = NAN;
    double b = NAN;
    double c = NAN;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Wrong input values");
        return WRONG_INPUT_ERROR;
    }

    double solutions[] = {NAN, NAN};
    int number_solutions = equation_solver(a, b, c, solutions);

    write_number_solutions(number_solutions, solutions);

    return 0;
}

void write_number_solutions(int number_solutions, double solutions[]) {

    assert (solutions != NULL);

    switch (number_solutions) {
        case INFINITY_SOLUTIONS:
            printf("Infinity");
            break;
        case ONE_SOLUTION:
            printf("One solution %.3lf", solutions[0]);
            break;
        case TWO_SOLUTIONS:
            printf("Two solution %.3lf, %.3lf", solutions[0], solutions[1]);
            break;
        case NO_SOLUTIONS:
            printf("No solutions");
            break;
        default:
            printf("Wrong number of solutions");
            break;
    }
}
