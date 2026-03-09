#pragma once

#include <QAbstractListModel>
#include <QByteArray>
#include <QHash>
#include <QModelIndex>
#include <QString>
#include <QVariant>
#include <QVector>

namespace presentation::models {

struct MachineItem {
    QString id;
    QString name;
    QString status;
    QString location;
};

class MachineListModel final : public QAbstractListModel {
    Q_OBJECT

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        StatusRole,
        LocationRole
    };

    explicit MachineListModel(QObject* parent = nullptr);

    [[nodiscard]] int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    [[nodiscard]] QVariant data(const QModelIndex& index, int role) const override;
    [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

    void setMachines(QVector<MachineItem> items);
    [[nodiscard]] const MachineItem* machineAt(int index) const;

private:
    QVector<MachineItem> items_;
};

} // namespace presentation::models
