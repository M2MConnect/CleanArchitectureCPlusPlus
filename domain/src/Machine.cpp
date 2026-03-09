#include "domain/entities/Machine.hpp"

#include <stdexcept>
#include <utility>

namespace domain::entities {

Machine::Machine(std::string id, std::string name, MachineStatus status, std::optional<std::string> location)
    : id_(std::move(id)),
      name_(std::move(name)),
      status_(status),
      location_(std::move(location)) {
    if (id_.empty()) {
        throw std::invalid_argument("Machine id must not be empty");
    }
    if (name_.empty()) {
        throw std::invalid_argument("Machine name must not be empty");
    }
}

const std::string& Machine::id() const noexcept {
    return id_;
}

const std::string& Machine::name() const noexcept {
    return name_;
}

MachineStatus Machine::status() const noexcept {
    return status_;
}

const std::optional<std::string>& Machine::location() const noexcept {
    return location_;
}

std::string toString(MachineStatus status) {
    switch (status) {
    case MachineStatus::Idle:
        return "Idle";
    case MachineStatus::Running:
        return "Running";
    case MachineStatus::Maintenance:
        return "Maintenance";
    case MachineStatus::Error:
        return "Error";
    }
    return "Unknown";
}

} // namespace domain::entities
