# ADR-0003: Zentrale Composition Root und Constructor DI

- Status: Accepted
- Datum: 2026-03-06

## Kontext

Abhaengigkeiten sollen transparent, austauschbar und testbar sein. Globale Zustandsmuster sollen vermieden werden.

## Entscheidung

- `app/CompositionRoot` erstellt und verdrahtet alle konkreten Implementierungen
- Abhaengigkeiten werden ueber Konstruktoren injiziert
- Ownership liegt in `std::unique_ptr`
- Keine Singletons und kein Service Locator

## Konsequenzen

- Lebensdauer und Wiring sind explizit
- Mocking/Fakes in Tests werden einfacher
- Instanzierung ist konzentriert an einer Stelle
