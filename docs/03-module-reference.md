# 03 Modulreferenz

## Domain

### `Machine`

Dateien:

- `domain/include/domain/entities/Machine.hpp`
- `domain/src/Machine.cpp`

Inhalt:

- Entitaet mit Feldern `id`, `name`, `status`, `location`
- Gueltigkeitspruefung im Konstruktor (id/name nicht leer)
- `MachineStatus` Enum
- `toString(MachineStatus)` fuer textuelle Darstellung

### `IMachineRepository`

Datei:

- `domain/include/domain/repositories/IMachineRepository.hpp`

Inhalt:

- Port fuer Maschinenzugriff
- API: `listMachines() -> std::vector<Machine>`

## Application

### `Result<TValue, TError>`

Datei:

- `application/include/application/common/Result.hpp`

Inhalt:

- einfacher Erfolg/Fehler-Container
- `success(...)`, `failure(...)`, `hasValue()`, `value()`, `error()`

### `ILogger`

Datei:

- `application/include/application/ports/ILogger.hpp`

Inhalt:

- abstrakte Logging-Schnittstelle
- LogLevel: `Debug`, `Info`, `Warning`, `Error`

### `LoadMachinesUseCase`

Dateien:

- `application/include/application/usecases/LoadMachinesUseCase.hpp`
- `application/src/LoadMachinesUseCase.cpp`

Inhalt:

- nutzt `IMachineRepository` + `ILogger`
- laedt Maschinen
- Fehlerbehandlung per `Result<..., std::string>`

## Infrastructure

### `InMemoryMachineRepository`

Dateien:

- `infrastructure/include/infrastructure/repositories/InMemoryMachineRepository.hpp`
- `infrastructure/src/repositories/InMemoryMachineRepository.cpp`

Inhalt:

- liefert vordefinierte Maschinendaten

### `ConsoleLogger`

Dateien:

- `infrastructure/include/infrastructure/logging/ConsoleLogger.hpp`
- `infrastructure/src/logging/ConsoleLogger.cpp`

Inhalt:

- implementiert `ILogger`
- schreibt Logeintraege nach `std::cout`

## Presentation

### `MachineListModel` (QAbstractListModel)

Dateien:

- `presentation/include/presentation/models/MachineListModel.hpp`
- `presentation/src/models/MachineListModel.cpp`

Inhalt:

- ListModel fuer QML
- Rollen: `machineId`, `name`, `status`, `location`

### `MachineListViewModel` (QObject)

Dateien:

- `presentation/include/presentation/viewmodels/MachineListViewModel.hpp`
- `presentation/src/viewmodels/MachineListViewModel.cpp`

Inhalt:

- laedt Daten via Use Case
- konvertiert Domain-Daten in QML-taugliche Daten
- verwaltet Selektion und Fehlermeldung
- zentrale Q_PROPERTYs fuer UI-Bindings

## App

### Composition Root

Dateien:

- `app/include/app/CompositionRoot.hpp`
- `app/src/CompositionRoot.cpp`

Inhalt:

- erstellt konkrete Implementierungen
- verdrahtet Logger, Repository, UseCase, ViewModel

### Einstiegspunkt

Datei:

- `app/src/main.cpp`

Inhalt:

- startet `QGuiApplication`
- setzt `machineListViewModel` als Context Property
- laedt `qrc:/ModernQtArchitecture/qml/Main.qml`
