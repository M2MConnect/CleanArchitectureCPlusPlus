#pragma once

#include "application/common/Result.hpp"
#include "application/ports/ILogger.hpp"
#include "domain/entities/Machine.hpp"
#include "domain/repositories/IMachineRepository.hpp"

#include <string>
#include <vector>

namespace application::usecases {

class LoadMachinesUseCase {
public:
    LoadMachinesUseCase(const domain::repositories::IMachineRepository& machineRepository,
                        application::ports::ILogger& logger);

    [[nodiscard]] application::common::Result<std::vector<domain::entities::Machine>, std::string> execute() const;

private:
    const domain::repositories::IMachineRepository& machineRepository_;
    application::ports::ILogger& logger_;
};

} // namespace application::usecases
