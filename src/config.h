#pragma once
#include <optional>
#include <string>

struct AppConfig {
    int precision = 6;
    bool verbose = false;
    std::optional<std::string> input_file;
};

AppConfig load_config_from_env();