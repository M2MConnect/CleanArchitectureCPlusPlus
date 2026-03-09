#include "infrastructure/repositories/InMemoryMachineRepository.hpp"

namespace infrastructure::repositories {

std::vector<domain::entities::Machine> InMemoryMachineRepository::listMachines() const {
    return {
        domain::entities::Machine("M-1001", "Fraser CNC Alpha", domain::entities::MachineStatus::Running, "Hall A"),
        domain::entities::Machine("M-1002", "Kuka Welding Cell", domain::entities::MachineStatus::Idle, "Hall B"),
        domain::entities::Machine("M-1003", "Packaging Line Delta", domain::entities::MachineStatus::Maintenance,
                                  "Hall C")
    };
}

} // namespace infrastructure::repositories
