// solver.h
#ifndef SOLVER_H
#define SOLVER_H

#include "equation.h"
#include <tuple>

class Solver {
public:
    static std::tuple<double, double, bool> solve(const Equation& eq);
};

#endif // SOLVER_H
