// solver.h
#ifndef SOLVER_H
#define SOLVER_H

#include "equation.h"
#include <tuple>

class Solver
{
public:
    // В возвращаеммом кортеже первые два числа - корни уровнения,
    // третье - флаг количества уравнений:
    // 0 - корней нет
    // 1 - 1 корень
    // 2 - 2 корня
    // 3 - бесконечное число корней
    static std::tuple<double, double, uint> solve(const Equation &eq);
};

#endif // SOLVER_H
