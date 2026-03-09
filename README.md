# ModernQtArchitecture

A modern foundation for a professional Qt 6 desktop application using Clean Architecture, MVVM, and C++23.

## Architecture

- `domain`: Pure C++ domain model and domain ports.
- `application`: Use cases, result type, and abstracted ports such as logging.
- `infrastructure`: Concrete adapters (in-memory repository, console logger).
- `presentation`: Qt-based view models and models for QML.
- `app`: Composition root, Qt application startup, and QML UI.
- `tests`: Unit tests for domain and application.

Dependency direction: `app -> presentation -> application -> domain` and `app -> infrastructure -> (application/domain)`.

## Prerequisites

- Visual Studio 2022 (with C++ Desktop Development)
- Qt 6.10.2 (MSVC 2022 64-bit)
- CMake 3.27+

Set `CMAKE_PREFIX_PATH` to your Qt installation, for example:

```powershell
$env:CMAKE_PREFIX_PATH="C:/Qt/6.10.2/msvc2022_64"
```

## Build with Visual Studio (Presets)

```powershell
cmake --preset vs2022-x64
cmake --build --preset vs2022-x64-debug
```

## Run tests

```powershell
ctest --preset vs2022-x64-debug-tests
```

## Run the app

```powershell
./out/build/vs2022-x64/Debug/mqa_app.exe
```

Alternatively, open the folder directly in Visual Studio. The CMake presets are detected automatically.
