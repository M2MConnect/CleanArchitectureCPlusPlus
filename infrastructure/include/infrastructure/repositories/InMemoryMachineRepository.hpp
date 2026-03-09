#pragma once

#include "domain/repositories/IMachineRepository.hpp"

namespace infrastructure::repositories {

class InMemoryMachineRepository final : public domain::repositories::IMachineRepository {
public:
    [[nodiscard]] std::vector<domain::entities::Machine> listMachines() const override;
};

} // namespace infrastructure::repositories
