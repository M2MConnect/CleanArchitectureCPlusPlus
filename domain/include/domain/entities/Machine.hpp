#pragma once

#include <optional>
#include <string>

namespace domain::entities {

enum class MachineStatus {
    Idle,
    Running,
    Maintenance,
    Error
};

class Machine {
public:
    Machine(std::string id, std::string name, MachineStatus status, std::optional<std::string> location);

    [[nodiscard]] const std::string& id() const noexcept;
    [[nodiscard]] const std::string& name() const noexcept;
    [[nodiscard]] MachineStatus status() const noexcept;
    [[nodiscard]] const std::optional<std::string>& location() const noexcept;

private:
    std::string id_;
    std::string name_;
    MachineStatus status_;
    std::optional<std::string> location_;
};

[[nodiscard]] std::string toString(MachineStatus status);

} // namespace domain::entities
