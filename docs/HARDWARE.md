# Hardware-Grundlage

Kein geprüfter Schaltplan vorhanden. Angaben aus dem Anwendungscode:

| Funktion | Erkennbarer Anschluss / Einstellung |
|---|---|
| Zielcontroller | STM32F103C8Tx laut IDE-Projekt |
| RTC-Neuinitialisierung | PB2 wird beim Start abgefragt; High führt zu `RTC_Init()` |
| Motor-Timersignale | PB4 / PB5, TIM3-Remapping im Treiber |
| Systemtakt | Funktion für 72 MHz; tatsächlichen externen Takt bestätigen |
| RTC-Takt | LSE-Konfiguration im RTC-Code; tatsächlichen Quarz bestätigen |

PB4/PB5 sind nicht ohne Prüfung mit einem Motor zu verbinden. Die Signalzuordnung am real verwendeten Treiber, Versorgung, Masse und Debug-Pinbelegung müssen anhand des tatsächlichen Aufbaus dokumentiert werden. SWD-/JTAG-Einstellungen und das Remapping sind im Code/Board abzugleichen.

Für Verbrauchsmessungen müssen Messpunkt, Versorgung, angeschlossene LEDs, Debugger und Motorversorgung dokumentiert sein. Sonst sind Werte verschiedener Aufbauten nicht vergleichbar.
