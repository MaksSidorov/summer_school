#include "equation.h"

void run_test(double a, double b, double c, int true_number_solutions, double x1, double x2) {
    static int number_of_test = 1;
    double output_solutions[] = {x1, x2};
    int output_number_solutions = equation_solver(a, b, c, output_solutions);
    if (output_number_solutions != true_number_solutions) {
        printf("Wrong number of solutions on test number %d\n", number_of_test);
        printf("Values: a - %.3lf, b - %.3lf, c - %.3lf, "
               "output number of solutions - %d, true number of solutions %d\n", a,
               b, c, output_number_solutions, true_number_solutions);
        number_of_test++;
        return;
    }
    else if (!double_equality(x1, output_solutions[0]) || !double_equality(x2, output_solutions[1])) {
        printf("Wrong solutions on test number %d\n", number_of_test);
        printf("Values: a - %.3lf, b - %.3lf, c - %.3lf, "
               "output solutions %lf, %lf true solutions %.3lf, %.3lf\n", a,
               b, c, output_solutions[0], output_solutions[1], x1, x2);
        number_of_test++;
        return;
    }
    printf("test number %d passed\n", number_of_test);
    number_of_test++;
}

void run_all_tests() {
    //           a    b     c     true_num_sol   x1     x2
    run_test( 0, 0, 0, -1, 0, 0); // Все 0
    run_test( 1, 0, 0, 1, 0, 0); // Два корня совпадают
    run_test( 0, 0, -5, 0, 0, 0); // Нет решений
    run_test(-1, 4, -5, 0, 0, 0); // Нет решений
    run_test( 1, 4, -5, 2, -5, 1); // Есть 2 решения
    run_test(-1, 5, 6, 2, 6, -1); // Есть 2 решения
    run_test( 0, 5, 4, 1, -0.8, 0); // Есть 1 решение
    run_test( 1, -4, 4, 1, 2, 0); // Есть 1 решение
}
