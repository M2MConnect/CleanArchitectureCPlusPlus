#pragma once

#include "application/ports/ILogger.hpp"

namespace infrastructure::logging {

class ConsoleLogger final : public application::ports::ILogger {
public:
    void log(application::ports::LogLevel level, std::string message) override;
};

} // namespace infrastructure::logging
