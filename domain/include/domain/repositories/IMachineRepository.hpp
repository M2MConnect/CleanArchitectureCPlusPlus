#pragma once

#include "domain/entities/Machine.hpp"

#include <vector>

namespace domain::repositories {

class IMachineRepository {
public:
    virtual ~IMachineRepository() = default;
    [[nodiscard]] virtual std::vector<domain::entities::Machine> listMachines() const = 0;
};

} // namespace domain::repositories
