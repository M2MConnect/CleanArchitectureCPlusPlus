# 04 QML UI und MVVM

## QML-Dateien

- `app/qml/Main.qml`
- `app/qml/views/MachineListView.qml`
- `app/qml/components/DetailField.qml`
- `app/qml/styles/Theme.qml`

## UI-Aufbau

- `Main.qml`
  - ApplicationWindow
  - Hintergrund + Container
  - bindet `Views.MachineListView`
- `MachineListView.qml`
  - linke Seite: Maschinenliste
  - rechte Seite: Detailbereich
- `DetailField.qml`
  - wiederverwendbares Detailfeld fuer Label/Wert
- `Theme.qml`
  - zentrale Farbdefinitionen als Singleton-QML-Objekt

## MVVM-Rollen

- View (QML): Darstellung + User-Interaktion
- ViewModel (`MachineListViewModel`): UI-Logik, State, Commands
- Model (`MachineListModel`): Listendaten fuer Delegates

## Wichtige Bindings

Das QML bindet direkt an Q_PROPERTYs aus dem ViewModel:

- `machineModel`
- `selectedMachineId`
- `selectedMachineName`
- `selectedMachineStatus`
- `selectedMachineLocation`
- `errorMessage`

## Kein Business in QML

- Keine Repository- oder UseCase-Aufrufe direkt aus QML
- QML ruft nur ViewModel-Methoden wie `loadMachines()` und `selectMachine(...)`
