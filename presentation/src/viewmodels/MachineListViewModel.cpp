#include "presentation/viewmodels/MachineListViewModel.hpp"

#include "domain/entities/Machine.hpp"

#include <QVector>

#include <string>

namespace presentation::viewmodels {

namespace {

QString toQString(const std::string& value) {
    return QString::fromStdString(value);
}

} // namespace

MachineListViewModel::MachineListViewModel(application::usecases::LoadMachinesUseCase& loadMachinesUseCase, QObject* parent)
    : QObject(parent),
      loadMachinesUseCase_(loadMachinesUseCase),
      model_(this) {
}

presentation::models::MachineListModel* MachineListViewModel::machineModel() noexcept {
    return &model_;
}

QString MachineListViewModel::selectedMachineId() const {
    return selectedMachineId_;
}

QString MachineListViewModel::selectedMachineName() const {
    return selectedMachineName_;
}

QString MachineListViewModel::selectedMachineStatus() const {
    return selectedMachineStatus_;
}

QString MachineListViewModel::selectedMachineLocation() const {
    return selectedMachineLocation_;
}

QString MachineListViewModel::errorMessage() const {
    return errorMessage_;
}

void MachineListViewModel::loadMachines() {
    const auto result = loadMachinesUseCase_.execute();
    if (!result.hasValue()) {
        model_.setMachines({});
        clearSelection();
        errorMessage_ = toQString(result.error());
        emit errorMessageChanged();
        return;
    }

    QVector<presentation::models::MachineItem> items;
    const auto& machines = result.value();
    items.reserve(static_cast<int>(machines.size()));

    for (const auto& machine : machines) {
        items.push_back({
            toQString(machine.id()),
            toQString(machine.name()),
            toQString(domain::entities::toString(machine.status())),
            machine.location().has_value() ? toQString(*machine.location()) : QStringLiteral("n/a")
        });
    }

    model_.setMachines(std::move(items));
    errorMessage_.clear();
    emit errorMessageChanged();

    if (model_.rowCount() > 0) {
        selectMachine(0);
    } else {
        clearSelection();
    }
}

void MachineListViewModel::selectMachine(const int index) {
    const auto* machine = model_.machineAt(index);
    if (machine == nullptr) {
        clearSelection();
        return;
    }

    selectedMachineId_ = machine->id;
    selectedMachineName_ = machine->name;
    selectedMachineStatus_ = machine->status;
    selectedMachineLocation_ = machine->location;
    emit selectedMachineChanged();
}

void MachineListViewModel::clearSelection() {
    selectedMachineId_.clear();
    selectedMachineName_.clear();
    selectedMachineStatus_.clear();
    selectedMachineLocation_.clear();
    emit selectedMachineChanged();
}

} // namespace presentation::viewmodels
