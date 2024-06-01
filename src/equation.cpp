// equation.cpp
#include "equation.h"

std::istream& operator>>(std::istream& in, Equation& eq) {
    in >> eq.a >> eq.b >> eq.c;
    return in;
}
