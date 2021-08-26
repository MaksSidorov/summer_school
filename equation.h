#ifndef EQUATION_EQUATION_H
#define EQUATION_EQUATION_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

#ifdef MEOW
    #define printf(...)
#endif


double check_zero(double);
int linear_eq(double, double, double[]);
int square_eq(double, double, double, double[]);
int eq_solver(double, double, double, double[]);
void run_tests(void);

#endif // EQUATION_EQUATION_H