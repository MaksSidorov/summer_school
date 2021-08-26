//! @mainpage
//! - main.c

#include "equation.h"


//!
//! Функция принимает на вход коэффициенты a, b, c квадратного уравнения.
//! Пишет количество решений и сами корни
int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Wrong input values");
        return 0;
    }

    double solutions[] = {0, 0};
    int number_solutions = eq_solver(a, b, c, solutions);

    switch (number_solutions) {
        case -1:
            printf("Infinity");
            break;
        case 1:
            printf("One solution %.3lf", solutions[0]);
            break;
        case 2:
            printf("Two solution %.3lf, %.3lf", solutions[0], solutions[1]);
            break;
        case 0:
            printf("No solutions");
            break;
        default:
            printf("Wrong number of solutions");
    }

    return 0;
}

