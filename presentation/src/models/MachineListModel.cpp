#include "presentation/models/MachineListModel.hpp"

#include <utility>

namespace presentation::models {

MachineListModel::MachineListModel(QObject* parent)
    : QAbstractListModel(parent) {
}

int MachineListModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return items_.size();
}

QVariant MachineListModel::data(const QModelIndex& index, const int role) const {
    if (!index.isValid() || index.row() < 0 || index.row() >= items_.size()) {
        return {};
    }

    const auto& machine = items_.at(index.row());
    switch (role) {
    case IdRole:
        return machine.id;
    case NameRole:
        return machine.name;
    case StatusRole:
        return machine.status;
    case LocationRole:
        return machine.location;
    default:
        return {};
    }
}

QHash<int, QByteArray> MachineListModel::roleNames() const {
    return {
        {IdRole, "machineId"},
        {NameRole, "name"},
        {StatusRole, "status"},
        {LocationRole, "location"}
    };
}

void MachineListModel::setMachines(QVector<MachineItem> items) {
    beginResetModel();
    items_ = std::move(items);
    endResetModel();
}

const MachineItem* MachineListModel::machineAt(const int index) const {
    if (index < 0 || index >= items_.size()) {
        return nullptr;
    }
    return &items_.at(index);
}

} // namespace presentation::models
