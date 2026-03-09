#include "infrastructure/logging/ConsoleLogger.hpp"

#include <iostream>

namespace infrastructure::logging {

namespace {

const char* toText(const application::ports::LogLevel level) {
    switch (level) {
    case application::ports::LogLevel::Debug:
        return "DEBUG";
    case application::ports::LogLevel::Info:
        return "INFO";
    case application::ports::LogLevel::Warning:
        return "WARN";
    case application::ports::LogLevel::Error:
        return "ERROR";
    }
    return "UNKNOWN";
}

} // namespace

void ConsoleLogger::log(const application::ports::LogLevel level, std::string message) {
    std::cout << "[" << toText(level) << "] " << message << '\n';
}

} // namespace infrastructure::logging
