# 05 Composition Root und Dependency Injection

## Grundprinzip

Alle Abhaengigkeiten werden zentral im Composition Root erzeugt und ueber Konstruktoren injiziert.

## Verdrahtung

`CompositionRoot` erstellt in dieser Reihenfolge:

1. `ConsoleLogger`
2. `InMemoryMachineRepository`
3. `LoadMachinesUseCase`
4. `MachineListViewModel`

## Warum das wichtig ist

- klare Ersetzbarkeit von Implementierungen
- bessere Testbarkeit
- keine globalen Zustandsobjekte
- keine Service-Locator-Logik

## Ownership

- `std::unique_ptr` fuer alle Komponenten
- Lebensdauer wird im `CompositionRoot` zentral kontrolliert
