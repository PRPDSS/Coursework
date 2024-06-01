// solver.cpp
#include "solver.h"
#include <cmath>
#include <tuple>

std::tuple<double, double, bool> Solver::solve(const Equation& eq) {
    double a = eq.a;
    double b = eq.b;
    double c = eq.c;

    if (a == 0) {
        if (b == 0) {
            return std::make_tuple(0, 0, false); // Не уравнение
        } else {
            // Линейное уравнение: bx + c = 0
            double root = -c / b;
            return std::make_tuple(root, root, true);
        }
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return std::make_tuple(0, 0, false); // Нет действительных корней
    }

    double q;
    if (b > 0) {
        q = -0.5 * (b + std::sqrt(discriminant));
    } else {
        q = -0.5 * (b - std::sqrt(discriminant));
    }

    double root1 = q / a;
    double root2 = c / q;

    if (root1 > root2) {
        std::swap(root1, root2);
    }

    return std::make_tuple(root1, root2, true);
}
