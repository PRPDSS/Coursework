// solver.cpp
#include "solver.h"
#include <cmath>
#include <tuple>

std::tuple<double, double, uint> Solver::solve(const Equation &eq) {
    double a = eq.a;
    double b = eq.b;
    double c = eq.c;

    if (a == 0) {
        if (b == 0) {
            return std::make_tuple(0, 0, c == 0? 3 : 0); // c = 0?
        } else {
            // Линейное уравнение: bx + c = 0
            double root = -c / b;
            if (!root) root = 0;
            return std::make_tuple(root, root, 1);
        }
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return std::make_tuple(0, 0, 0); // Нет действительных корней
    if (discriminant == 0)
        return std::make_tuple(-b / (2 * a), 0, 1); // Один корень

    discriminant = sqrt(discriminant);
    double root1 = (-b - discriminant) / (2 * a);
    double root2 = (-b + discriminant) / (2 * a);

    if (root1 > root2) {
        std::swap(root1, root2);
    }

    return std::make_tuple(root1, root2, 2);
}
