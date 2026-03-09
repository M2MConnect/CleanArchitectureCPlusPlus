# ModernQtArchitecture

Modernes Grundgeruest fuer eine professionelle Qt-6-Desktop-Anwendung mit Clean Architecture, MVVM und C++20.

## Architektur

- `domain`: Reines C++ Domain-Modell und Domain-Ports.
- `application`: Use Cases, Result-Typ und abstrahierte Ports wie Logging.
- `infrastructure`: Konkrete Adapter (In-Memory Repository, Console Logger).
- `presentation`: Qt-basierte ViewModels und Models fuer QML.
- `app`: Composition Root, Qt Application Start und QML UI.
- `tests`: Unit-Tests fuer Domain und Application.

Abhaengigkeitsrichtung: `app -> presentation -> application -> domain` und `app -> infrastructure -> (application/domain)`.

## Voraussetzungen

- Visual Studio 2022 (mit C++ Desktop Development)
- Qt 6.5+ (Core, Gui, Qml, Quick)
- CMake 3.27+

Setzen Sie `CMAKE_PREFIX_PATH` auf Ihre Qt-Installation, zum Beispiel:

```powershell
$env:CMAKE_PREFIX_PATH="C:/Qt/6.7.2/msvc2022_64"
```

## Build mit Visual Studio (Presets)

```powershell
cmake --preset vs2022-x64
cmake --build --preset vs2022-x64-debug
```

## Tests ausfuehren

```powershell
ctest --preset vs2022-x64-debug-tests
```

## Starten

```powershell
./out/build/vs2022-x64/Debug/mqa_app.exe
```

Alternativ kann der Ordner direkt in Visual Studio geoeffnet werden. Die CMake-Presets werden automatisch erkannt.
