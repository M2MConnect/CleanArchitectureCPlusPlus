#pragma once

#include <string>

namespace application::ports {

enum class LogLevel {
    Debug,
    Info,
    Warning,
    Error
};

class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void log(LogLevel level, std::string message) = 0;
};

} // namespace application::ports
