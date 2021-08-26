#include "equation.h"

void run_eq_solver_tests() {


}

void run_check_zero_tests() {
    double test_valus[15] = {0, 0.000001, 23, -44, -0.00001, 67, 1000000, 0, 0.01, 0.1};
    double test_answers[15] = {0, 0, 23, -44, 0, 67, 1000000, 0, 0.01, 0.1};
    for (int i = 0; i < 15; i++) {
        double func_ouput = check_zero(test_valus[i]);
        if (func_ouput != test_answers[i]) {
            printf("Wrong result from fucntion check_zero!");
            printf("Value: %lf function output - %lf true output - %lf", test_valus[i], func_ouput, test_answers[i]);
            return;
        }
    }
    printf("check_zero - OK");
}

void run_square_eq_tests() {
    double test_values[9][3] = {{1, 0, 0}, {3, 5, 4}, {-1, 5, 6}, {-1, -1, -1}, {1, -2, 1},
                                {1, 4, -5}, {0.1, 73}, {0.01, -0.9}, {1.2, 4.5}};
    int test_number_sol[9] = {1, 0, 2, 0, 1, 2};
    double test_answer[9][2] = {{1, 0}, {0, 0}, {6, -1}, {0, 0}, {1, 0}};
}

void run_linear_eq_tests() {
    double test_values[9][2] = {{0, 0}, {5, 4}, {-1, 5}, {-1, -1}, {34, 78},
                                 {56, -45}, {0.1, 73}, {0.01, -0.9}, {1.2, 4.5}};
    int test_number_sol[9] = {-1, 1, 1, 1, 1, 1, 1, 1, 1};
    double test_answer[9] = {0, -0.8, 5, 1, -39.0/17, 45.0/56, -730, 9, -3.75};
    for (int i = 0; i < 9; i++) {
        double test_sol[] = {};
        int test_n = linear_eq(test_values[i][0], test_values[i][1], test_sol);
        if (test_n != test_number_sol[i]) {
            printf("Wrong number of solutions from func linear_eq!");
            printf("Values: b - %lf, c - %lf, output number"
                   " of solutions - %d, true number of solutions - %d", test_values[i][0],
                   test_values[i][1], test_n, test_number_sol[i]);
            return;
        }

        else if (test_answer[i] != test_sol[0]) {
            printf("Wrong solutions from func linear_eq!");
            printf("Values: b - %lf, c - %lf, output number"
                   " of solution - %lf, true number of solution - %lf", test_values[i][0],
                   test_values[i][1], test_sol[0], test_answer[i]);
            return;
        }
    }
    printf("linear_eq - OK");
}

void run_all_tests() {
    run_eq_solver_tests();
    run_check_zero_tests();
    run_square_eq_tests();
    run_linear_eq_tests();
}


