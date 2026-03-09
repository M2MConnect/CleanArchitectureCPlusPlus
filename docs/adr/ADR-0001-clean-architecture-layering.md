# ADR-0001: Clean Architecture Layering

- Status: Accepted
- Datum: 2026-03-06

## Kontext

Das Projekt soll langfristig wartbar und erweiterbar sein, mit klaren Verantwortungen je Schicht.

## Entscheidung

Wir strukturieren strikt in:

- `domain`
- `application`
- `infrastructure`
- `presentation`
- `app`
- `tests`

Abhaengigkeiten zeigen nur nach innen.

## Konsequenzen

- Gute Testbarkeit der Kernlogik
- Austauschbarkeit von Infrastrukturadaptern
- Anfangs mehr Strukturaufwand, spaeter deutlich weniger Entropie
