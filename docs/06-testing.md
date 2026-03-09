# 06 Tests

## Struktur

- `tests/domain/MachineTests.cpp`
- `tests/application/LoadMachinesUseCaseTests.cpp`

## Abgedeckte Faelle

### Domain-Tests

- gueltige Machine-Erstellung
- Status-String-Mapping
- Exception bei unguelter Eingabe

### Application-Tests

- Erfolgsfall mit Test-Repository
- Fehlerfall mit Exception-werfendem Repository
- Logging wird aufgerufen

## Testausfuehrung

Zuerst Testtargets bauen, dann ctest ausfuehren.

```powershell
& "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" --build --preset vs2022-x64-debug --target mqa_domain_tests mqa_application_tests
& "C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\ctest.exe" --preset vs2022-x64-debug-tests --output-on-failure
```
