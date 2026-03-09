# 07 Troubleshooting

## Qt6 nicht gefunden (find_package)

Fehlerbild:

- `Could not find a package configuration file provided by "Qt6"`

Loesung:

- `Qt 6.10.2 -> MSVC 2022 64-bit` installieren
- `CMAKE_PREFIX_PATH` auf `C:/Qt/6.10.2/msvc2022_64` setzen

## Q_OBJECT Linkerfehler (unresolved externals)

Fehlerbild:

- `metaObject`, `qt_metacall`, Signal-Symbole fehlen

Loesung:

- betroffene Header als Target-Sources aufnehmen
- `AUTOMOC` fuer Target aktivieren

## DLL fehlt zur Laufzeit (`0xc0000135`)

Fehlerbild:

- Abbruch beim Start, fehlende Qt-DLLs

Loesung:

- `windeployqt` nach Build ausfuehren (im Projekt bereits automatisiert)

## QML-Datei oder Typ nicht gefunden

Fehlerbilder:

- `Main.qml: No such file or directory`
- `MachineListView is not a type`

Loesung:

- korrekten QRC-Pfad verwenden: `qrc:/ModernQtArchitecture/qml/Main.qml`
- in QML relative Imports fuer lokale Komponenten nutzen (`import "views" as Views` etc.)

## ctest/cmake nicht im PATH

Fehlerbild:

- PowerShell kennt `cmake`/`ctest` nicht

Loesung:

- Visual Studio Developer PowerShell nutzen
- oder VS-CMake-Binaries per vollem Pfad aufrufen
