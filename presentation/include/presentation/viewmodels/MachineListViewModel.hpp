#pragma once

#include "application/usecases/LoadMachinesUseCase.hpp"
#include "presentation/models/MachineListModel.hpp"

#include <QObject>
#include <QString>

namespace presentation::viewmodels {

class MachineListViewModel final : public QObject {
    Q_OBJECT
    Q_PROPERTY(presentation::models::MachineListModel* machineModel READ machineModel CONSTANT)
    Q_PROPERTY(QString selectedMachineId READ selectedMachineId NOTIFY selectedMachineChanged)
    Q_PROPERTY(QString selectedMachineName READ selectedMachineName NOTIFY selectedMachineChanged)
    Q_PROPERTY(QString selectedMachineStatus READ selectedMachineStatus NOTIFY selectedMachineChanged)
    Q_PROPERTY(QString selectedMachineLocation READ selectedMachineLocation NOTIFY selectedMachineChanged)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorMessageChanged)

public:
    explicit MachineListViewModel(application::usecases::LoadMachinesUseCase& loadMachinesUseCase, QObject* parent = nullptr);

    [[nodiscard]] presentation::models::MachineListModel* machineModel() noexcept;

    [[nodiscard]] QString selectedMachineId() const;
    [[nodiscard]] QString selectedMachineName() const;
    [[nodiscard]] QString selectedMachineStatus() const;
    [[nodiscard]] QString selectedMachineLocation() const;
    [[nodiscard]] QString errorMessage() const;

    Q_INVOKABLE void loadMachines();
    Q_INVOKABLE void selectMachine(int index);

signals:
    void selectedMachineChanged();
    void errorMessageChanged();

private:
    void clearSelection();

    application::usecases::LoadMachinesUseCase& loadMachinesUseCase_;
    presentation::models::MachineListModel model_;
    QString selectedMachineId_;
    QString selectedMachineName_;
    QString selectedMachineStatus_;
    QString selectedMachineLocation_;
    QString errorMessage_;
};

} // namespace presentation::viewmodels
