# 02 Build und Start

## Voraussetzungen

- Visual Studio 2022
- CMake 3.27+
- Qt 6.10.2 mit `msvc2022_64`

## CMake Preset

Das Preset `vs2022-x64` ist in `CMakePresets.json` hinterlegt.

Wichtige Variable:

- `CMAKE_PREFIX_PATH = C:/Qt/6.10.2/msvc2022_64`

## Build in Visual Studio

1. Ordner `C:\Users\Martin.Mueller\Desktop\FirstCPlusPlus` oeffnen
2. CMake Cache neu generieren
3. `Alle erstellen`
4. Startup Item `mqa_app` auswaehlen
5. Starten mit `F5`

## Build via CLI

Wenn `cmake`/`ctest` nicht im PATH sind, Visual Studio CMake-Binaries direkt aufrufen.

Beispiel Build:

```powershell
& "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" --build --preset vs2022-x64-debug
```

## Qt Deployment unter Windows

In `app/CMakeLists.txt` wird nach dem Build automatisch `windeployqt` ausgefuehrt.
Damit werden benoetigte Qt-DLLs und Plugins neben `mqa_app.exe` abgelegt.
