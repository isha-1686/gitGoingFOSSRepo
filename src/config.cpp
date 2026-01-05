#include "config.h"
#include <cstdlib>
#include <string>

static std::optional<std::string> getenv_opt(const char* key) {
    if (const char* v = std::getenv(key)) return std::string(v);
    return std::nullopt;
}

AppConfig load_config_from_env() {
    AppConfig cfg;
    if (auto p = getenv_opt("CALC_PRECISION")) {
        try { cfg.precision = std::stoi(*p); } catch (...) {}
    }
    if (auto v = getenv_opt("CALC_VERBOSE")) {
        if (*v == "1" || *v == "true") cfg.verbose = true;
    }
    if (auto f = getenv_opt("CALC_INPUT")) cfg.input_file = *f;
    return cfg;
}