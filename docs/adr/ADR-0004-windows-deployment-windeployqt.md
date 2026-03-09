# ADR-0004: Windows Deployment via windeployqt im Build

- Status: Accepted
- Datum: 2026-03-06

## Kontext

Beim Start auf Windows fehlten Qt-DLLs/Plugins (`0xc0000135`). Manuelles Deployment ist fehleranfaellig.

## Entscheidung

- `app/CMakeLists.txt` fuehrt `windeployqt` als `POST_BUILD` fuer `mqa_app` aus
- QML-Verzeichnis wird via `--qmldir` angegeben

## Konsequenzen

- Start der App in lokalem Build-Output ist robuster
- Weniger manuelle Schritte nach dem Build
- Build dauert etwas laenger
