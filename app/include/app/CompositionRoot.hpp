#pragma once

#include "application/ports/ILogger.hpp"
#include "application/usecases/LoadMachinesUseCase.hpp"
#include "domain/repositories/IMachineRepository.hpp"
#include "presentation/viewmodels/MachineListViewModel.hpp"

#include <memory>

namespace app {

class CompositionRoot {
public:
    CompositionRoot();

    [[nodiscard]] presentation::viewmodels::MachineListViewModel* machineListViewModel() const noexcept;

private:
    std::unique_ptr<application::ports::ILogger> logger_;
    std::unique_ptr<domain::repositories::IMachineRepository> machineRepository_;
    std::unique_ptr<application::usecases::LoadMachinesUseCase> loadMachinesUseCase_;
    std::unique_ptr<presentation::viewmodels::MachineListViewModel> machineListViewModel_;
};

} // namespace app
