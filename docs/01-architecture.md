# 01 Architektur

## Zielbild

Die Anwendung folgt Clean Architecture mit MVVM im Presentation Layer.

## Schichten

- `domain`
  - Reines C++20
  - Keine Qt-Abhaengigkeit
  - Entitaeten und fachliche Ports
- `application`
  - Use Cases und anwendungsweite Ports
  - Kennt Domain, aber keine konkreten Infrastrukturklassen
- `infrastructure`
  - Adapter, die Ports aus `domain`/`application` implementieren
- `presentation`
  - Qt/QML-nahe Modelle und ViewModels
  - UI-nahe Datenaufbereitung
- `app`
  - Composition Root
  - Startpunkt (`main.cpp`)
  - Zentrale Verdrahtung
- `tests`
  - Unit Tests fuer Domain und Application

## Abhaengigkeitsrichtung

- Hauptfluss: `app -> presentation -> application -> domain`
- Infrastruktur: `app -> infrastructure -> (application/domain)`

## Architekturregeln im Code

- Keine Singletons
- Constructor Dependency Injection
- Klare Ownership mit `std::unique_ptr`
- Keine zyklischen Abhaengigkeiten
- QML ohne Businesslogik
