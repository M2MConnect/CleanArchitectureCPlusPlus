# ADR-0002: MVVM mit QML und ViewModel als UI-Grenze

- Status: Accepted
- Datum: 2026-03-06

## Kontext

Die Anwendung nutzt Qt Quick/QML. Businesslogik darf nicht in der UI landen.

## Entscheidung

- QML ist reine Darstellung und Interaktion
- `MachineListViewModel` kapselt UI-Logik und State
- `MachineListModel` stellt Listendaten als `QAbstractListModel` bereit
- Fachliche Logik bleibt im Use Case (`LoadMachinesUseCase`)

## Konsequenzen

- Klare Trennung zwischen Darstellung und Fachlichkeit
- Bessere Wartbarkeit und Testbarkeit
- Etwas mehr Boilerplate zwischen Domain-Objekten und UI-Daten
