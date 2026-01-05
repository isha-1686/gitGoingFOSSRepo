#include "logging.h"
#include <iostream>
#include <chrono>
#include <format>

static std::string now() {
    using namespace std::chrono;
    auto t = system_clock::now();
    auto tt = system_clock::to_time_t(t);
    std::tm tm{};
#if defined(_WIN32)
    localtime_s(&tm, &tt);
#else
    localtime_r(&tt, &tm);
#endif
    char buf[32];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
    return std::string(buf);
}

void log_info(const std::string& msg) {
    std::cerr << "[INFO " << now() << "] " << msg << "\n";
}
void log_error(const std::string& msg) {
    std::cerr << "[ERROR " << now() << "] " << msg << "\n";
}