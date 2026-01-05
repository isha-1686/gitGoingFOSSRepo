#include "calculator.h"
#include "config.h"
#include "logging.h"
#include <iostream>
#include <iomanip>
#include <string>

static void print_usage() {
    std::cout << "Usage: calc <op> <args...>\n"
              << "Ops: add a b | sub a b | mul a b | div a b | sqr a | sqrt a | pow a b\n"
              << "Env flags: CALC_PRECISION, CALC_VERBOSE=1, CALC_INPUT=<file>\n";
}

int main(int argc, char* argv[]) {
    AppConfig cfg = load_config_from_env();
    CalcOptions opts{cfg.precision, cfg.verbose};
    Calculator calc{opts};
    std::cout << std::fixed << std::setprecision(opts.precision);

    if (argc < 3) { print_usage(); return 1; }
    std::string op = argv[1];

    auto argd = [&](int i) {
        if (i >= argc) throw std::runtime_error("missing argument");
        return std::stod(argv[i]);
    };

    try {
        if (op == "add")      std::cout << calc.add(argd(2), argd(3)) << "\n";
        else if (op == "sub") std::cout << calc.sub(argd(2), argd(3)) << "\n";
        else if (op == "mul") std::cout << calc.mul(argd(2), argd(3)) << "\n";
        else if (op == "div") std::cout << calc.div(argd(2), argd(3)) << "\n";
        else if (op == "sqr") std::cout << calc.sqr(argd(2)) << "\n";
        else if (op == "sqrt")std::cout << calc.sqrt_safe(argd(2)) << "\n";
        else if (op == "pow") std::cout << calc.pow(argd(2), argd(3)) << "\n";
        else { print_usage(); return 2; }
    } catch (const std::exception& ex) {
        log_error(ex.what());
        return 3;
    }
    return 0;
}
