// equation.h
#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>

class Equation {
public:
    double a, b, c;

    Equation(double a, double b, double c) : a(a), b(b), c(c) {}

    friend std::istream& operator>>(std::istream& in, Equation& eq);
};

#endif // EQUATION_H
