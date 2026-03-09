# 08 Erweiterung Richtung GPU/OpenCL

## Aktueller Stand

- UI (Qt Quick/QML) ist bereits GPU-beschleunigt fuer Rendering.
- Fachliche Berechnungen laufen aktuell CPU-basiert.

## Clean-Architecture-konforme Erweiterung

Empfohlene Struktur fuer Compute-Erweiterung:

- `application`
  - neues Port-Interface, z. B. `IComputeEngine`
- `infrastructure`
  - `CpuComputeEngine`
  - optional `OpenClComputeEngine` oder `CudaComputeEngine`
- `app`
  - konkrete Auswahl und Verdrahtung im Composition Root

## OpenCL kurz

- Standard fuer parallele Berechnungen auf GPU/CPU
- herstelleruebergreifend
- mehr Setup-Aufwand als reine CPU-Implementierung

## Betriebsregel

- Berechnungen nie im UI-Thread ausfuehren
- fuer lange Tasks Worker-Thread/Task-System nutzen
