#ifndef EQUATION_EQUATION_H
#define EQUATION_EQUATION_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

//!
//! отключение тестирования
#define NDEBUG_MODE

//!
//! Выключить все printf
#ifdef MEOW
    #define printf(...)
#endif

#define DOUBLE_ERROR 0.0001

enum NUM_OF_SOL {
    ONE_SOLUTION       = 1,
    TWO_SOLUTIONS      = 2,
    NO_SOLUTIONS       = 0,
    INFINITY_SOLUTIONS = -1
};
enum ERRORS {
    WRONG_INPUT_ERROR = 1
};

//!
//! Сравнение двух чисел типа double
//! \param [in] first
//! \param [in] second
//! \return 1, если числа равны в рамках погрешности, иначе 0
int double_equality(double first, double second);
//!
//! Проверяет является ли число 0, с учетом погрешноности.
//! \param [in] val
//! \return 0, если число в рамках погрешности. В противном случае само число
double check_zero(double val);
//!
//! Функция решает линейное уравнение.
//! Возвращает количество решений или -1, если их бесконечно много. Записывает в solutions корень.
//! \param [in] k
//! \param [in] b
//! \param [out] solutions
//! \return Количесвто корней
int linear_equation(double k, double b , double solutions[]);
//!
//! Решает квадратное уравнение при a != 0. Возвращает количество кореней и записывает их в solutions.
//! \param [in] a
//! \param [in] b
//! \param [in] c
//! \param [out] solutions
//! \return Количесвто корней
int square_equation(double a, double b, double c, double solutions[]);
//!
//! Функция разделяет уравнение на линейное и квадратное.
//! Возвращает количество корней или -1, в случае бесконечного количесва. Корни записываются в solutions.
//! \param [in] a
//! \param [in] b
//! \param [in] c
//! \param [out] solutions
//! \return Количесвто корней
int equation_solver(double a, double b, double c, double solutions[]);
//!
//!Функция запускает тесты
void run_all_tests(void);
//!
//! Функия выводит количество корней и сами корни, при их наличии.
//! \param [in] number_solutions
//! \param [in] solutions
void write_number_solutions(int number_solutions, double solutions[]);

#endif // EQUATION_EQUATION_H