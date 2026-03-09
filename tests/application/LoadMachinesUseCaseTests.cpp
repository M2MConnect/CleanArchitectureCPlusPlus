#include "application/usecases/LoadMachinesUseCase.hpp"

#include <cassert>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace {

class TestLogger final : public application::ports::ILogger {
public:
    void log(const application::ports::LogLevel, std::string message) override {
        messages.push_back(std::move(message));
    }

    std::vector<std::string> messages;
};

class SuccessRepository final : public domain::repositories::IMachineRepository {
public:
    std::vector<domain::entities::Machine> listMachines() const override {
        return {
            domain::entities::Machine("M-1", "Robot Arm", domain::entities::MachineStatus::Running, "Hall A"),
            domain::entities::Machine("M-2", "Packing Station", domain::entities::MachineStatus::Idle, "Hall B")
        };
    }
};

class ThrowingRepository final : public domain::repositories::IMachineRepository {
public:
    std::vector<domain::entities::Machine> listMachines() const override {
        throw std::runtime_error("database unavailable");
    }
};

} // namespace

int main() {
    {
        TestLogger logger;
        SuccessRepository repository;

        const application::usecases::LoadMachinesUseCase useCase(repository, logger);
        const auto result = useCase.execute();

        assert(result.hasValue());
        assert(result.value().size() == 2);
        assert(!logger.messages.empty());
    }

    {
        TestLogger logger;
        ThrowingRepository repository;

        const application::usecases::LoadMachinesUseCase useCase(repository, logger);
        const auto result = useCase.execute();

        assert(!result.hasValue());
        assert(result.error() == "Could not load machines");
        assert(!logger.messages.empty());
    }

    return 0;
}
