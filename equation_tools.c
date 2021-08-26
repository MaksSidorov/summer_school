#include "equation.h"

//!
//! Функция решает линейное уравнение.
//! Возвращает количество решений или -1, если их бесконечно много. Записывает в solutions корень.
//! \param [in] b
//! \param [in] c
//! \param [out] solutions
//! \return Количесвто корней
int linear_eq(double b, double c, double solutions[]) {

    assert (isfinite (b));
    assert (isfinite (c));

    if (!check_zero(b)) {
        if (!check_zero(c)) {
            return -1;
        }

        else {
            return 0;
        }
    }

    else {
        solutions[0] = (-c) / b;

        return 1;
    }
}

//!
//! Решает квадратное уравнение при a != 0. Возвращает количество кореней и записывает их в solutions.
//! \param [in] a
//! \param [in] b
//! \param [in] c
//! \param [out] solutions
//! \return Количесвто корней
int square_eq(double a, double b, double c, double solutions[]) {

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    double d = b * b - 4 * a * c;

    if (!check_zero(d)) {
        solutions[0] = check_zero((-b) / (2 * a));

        return 1;
    }

    else if (d > 0) {
        double d_sqrt = sqrt(d);

        solutions[0] = check_zero((-b - d_sqrt) / (2 * a));
        solutions[1] = check_zero((-b + d_sqrt) / (2 * a));

        return 2;
    }

    else {
        return 0;
    }

}

//!
//! Проверяет является ли число 0, с учетом погрешноности.
//! \param [in] val
//! \return 0, если число в рамках погрешности. В противном случае само число
double check_zero(double val) {
    if (fabs(val) <= 0.0001) {
        return 0;
    }
    return val;
}

//!
//! Функция разделяет уравнение на линейное и квадратное.
//! Возвращает количество корней или -1, в случае бесконечного количесва. Корни записываются в solutions.
//! \param [in] a
//! \param [in] b
//! \param [in] c
//! \param [out] solutions
//! \return Количесвто корней
int eq_solver(double a, double b, double c, double solutions[]) {

    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    if (!check_zero(a)) {
        return linear_eq(b, c, solutions);
    }

    else {
        return square_eq(a, b, c, solutions);
    }
}