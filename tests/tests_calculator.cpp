#include "calculator.h"
#include <cassert>
#include <cmath>
#include <iostream>

int main() {
    Calculator c;
    assert(c.add(2,3) == 5);
    assert(c.sub(5,2) == 3);
    assert(c.mul(2,4) == 8);
    assert(std::abs(c.div(9,3) - 3.0) < 1e-9);
    try { c.div(1,0); assert(false); } catch (...) {}
    try { c.sqrt_safe(-1); assert(false); } catch (...) {}
    assert(std::abs(c.pow(2,3) - 8.0) < 1e-9);
    assert(std::abs(c.sqr(5) - 25.0) < 1e-9);
    std::cout << "ok\n";
    return 0;
}