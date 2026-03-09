# 00 Getting Started in 5 Minuten

## 1) Voraussetzungen pruefen

- Visual Studio 2022 installiert
- Qt 6.10.2 mit `msvc2022_64` installiert
- Projekt liegt unter `C:\Users\Martin.Mueller\Desktop\FirstCPlusPlus`

Schnelltest fuer Qt:

```powershell
Test-Path "C:\Qt\6.10.2\msvc2022_64\lib\cmake\Qt6\Qt6Config.cmake"
```

Erwartung: `True`.

## 2) Projekt in Visual Studio oeffnen

- Visual Studio starten
- `Datei -> Ordner oeffnen...`
- `C:\Users\Martin.Mueller\Desktop\FirstCPlusPlus` waehlen

## 3) CMake konfigurieren

- Preset `vs2022-x64` auswaehlen
- `Projekt -> Cache loeschen und neu generieren`

## 4) Build und Start

- `Projekt -> Alle erstellen`
- Startup Item: `mqa_app`
- Mit `F5` starten

## 5) Tests laufen lassen

```powershell
& "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" --build --preset vs2022-x64-debug --target mqa_domain_tests mqa_application_tests
& "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\ctest.exe" --preset vs2022-x64-debug-tests --output-on-failure
```

## Ergebnis

Wenn alles korrekt eingerichtet ist:

- Anwendung startet und zeigt Maschinenliste + Details
- Domain/Application Tests laufen erfolgreich
