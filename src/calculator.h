#pragma once
#include <stdexcept>
#include <string>

struct CalcOptions {
    int precision = 6;
    bool verbose = false;
};

class Calculator {
public:
    explicit Calculator(CalcOptions opts = {});
    double add(double a, double b) const;
    double sub(double a, double b) const;
    double mul(double a, double b) const;
    double div(double a, double b) const; // throws on div-by-zero
    double sqr(double a) const;
    double pow(double a, double b) const;
    double sqrt_safe(double a) const; // throws on negative

private:
    CalcOptions opts_;
    void trace(const std::string& msg) const;
};