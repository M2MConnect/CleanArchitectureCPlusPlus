#include "app/CompositionRoot.hpp"

#include "infrastructure/logging/ConsoleLogger.hpp"
#include "infrastructure/repositories/InMemoryMachineRepository.hpp"

namespace app {

CompositionRoot::CompositionRoot() {
    logger_ = std::make_unique<infrastructure::logging::ConsoleLogger>();
    machineRepository_ = std::make_unique<infrastructure::repositories::InMemoryMachineRepository>();
    loadMachinesUseCase_ =
        std::make_unique<application::usecases::LoadMachinesUseCase>(*machineRepository_, *logger_);
    machineListViewModel_ =
        std::make_unique<presentation::viewmodels::MachineListViewModel>(*loadMachinesUseCase_);
}

presentation::viewmodels::MachineListViewModel* CompositionRoot::machineListViewModel() const noexcept {
    return machineListViewModel_.get();
}

} // namespace app
