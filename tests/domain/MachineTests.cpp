#include "domain/entities/Machine.hpp"

#include <cassert>
#include <optional>
#include <stdexcept>

int main() {
    using domain::entities::Machine;
    using domain::entities::MachineStatus;

    const Machine machine("M-5000", "Laser Cutter", MachineStatus::Running, "Hall X");
    assert(machine.id() == "M-5000");
    assert(machine.name() == "Laser Cutter");
    assert(machine.status() == MachineStatus::Running);
    assert(machine.location().has_value());
    assert(*machine.location() == "Hall X");

    assert(domain::entities::toString(MachineStatus::Idle) == "Idle");
    assert(domain::entities::toString(MachineStatus::Error) == "Error");

    bool didThrowForInvalidData = false;
    try {
        const Machine invalidMachine("", "Invalid", MachineStatus::Idle, std::nullopt);
        (void)invalidMachine;
    } catch (const std::invalid_argument&) {
        didThrowForInvalidData = true;
    }

    assert(didThrowForInvalidData);
    return 0;
}
