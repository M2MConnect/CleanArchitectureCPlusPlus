#include "application/usecases/LoadMachinesUseCase.hpp"

#include <exception>

namespace application::usecases {

LoadMachinesUseCase::LoadMachinesUseCase(const domain::repositories::IMachineRepository& machineRepository,
                                         application::ports::ILogger& logger)
    : machineRepository_(machineRepository),
      logger_(logger) {
}

application::common::Result<std::vector<domain::entities::Machine>, std::string> LoadMachinesUseCase::execute() const {
    logger_.log(application::ports::LogLevel::Info, "LoadMachinesUseCase started");

    try {
        const auto machines = machineRepository_.listMachines();
        logger_.log(application::ports::LogLevel::Info,
                    "LoadMachinesUseCase finished successfully with " + std::to_string(machines.size()) + " machines");
        return application::common::Result<std::vector<domain::entities::Machine>, std::string>::success(machines);
    } catch (const std::exception& ex) {
        logger_.log(application::ports::LogLevel::Error,
                    std::string("LoadMachinesUseCase failed with exception: ") + ex.what());
        return application::common::Result<std::vector<domain::entities::Machine>, std::string>::failure(
            "Could not load machines");
    } catch (...) {
        logger_.log(application::ports::LogLevel::Error, "LoadMachinesUseCase failed with unknown error");
        return application::common::Result<std::vector<domain::entities::Machine>, std::string>::failure(
            "Could not load machines");
    }
}

} // namespace application::usecases
