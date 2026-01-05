#include "calculator.h"
#include "logging.h"
#include <cmath>
#include <format>

Calculator::Calculator(CalcOptions opts) : opts_(opts) {}

void Calculator::trace(const std::string& msg) const {
    if (opts_.verbose) log_info(msg);
}

double Calculator::add(double a, double b) const {
    trace(std::format("add({}, {})", a, b));
    return a + b;
}

double Calculator::sub(double a, double b) const {
    trace(std::format("sub({}, {})", a, b));
    return a - b;
}

double Calculator::mul(double a, double b) const {
    trace(std::format("mul({}, {})", a, b));
    return a * b;
}

double Calculator::div(double a, double b) const {
    if (b == 0.0) throw std::runtime_error("division by zero");
    trace(std::format("div({}, {})", a, b));
    return a / b;
}

double Calculator::sqr(double a) const {
    trace(std::format("sqr({})", a));
    return a * a;
}

double Calculator::pow(double a, double b) const {
    trace(std::format("pow({}, {})", a, b));
    return std::pow(a, b);
}

double Calculator::sqrt_safe(double a) const {
    if (a < 0.0) throw std::runtime_error("negative input for sqrt");
    trace(std::format("sqrt({})", a));
    return std::sqrt(a);
}