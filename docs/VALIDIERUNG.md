# Prüfplan und bekannte Grenzen

## Im Quelltext beobachtet

- `RTC_Alarm_init()` setzt den Alarm relativ zum aktuellen Zähler einmalig um 10 Zählwerte weiter.
- `alarm_callback()` ist leer; ein periodisches Nachsetzen des Alarms ist dort nicht implementiert.
- `RTC_Init()` wird nur bei High-Pegel an PB2 aufgerufen. Verhalten beim ersten Start und bei bereits initialisierter Backup-Domäne prüfen.
- RTC-Wartefunktionen verwenden `uwTick`; nach Abschaltung von SysTick kann ein tickbasierter Timeout nicht normal fortschreiten.
- Der Timer-Callback der Motoransteuerung enthält selbst `WFI`; Verhalten im Interrupt bei aktivem SLEEPDEEP prüfen.
- RTC-Synchronisation, geteilte Zählerlesezugriffe, Alarmflanke und Rückgabewerte müssen am Zielsystem überprüft werden.

## Mess- und Funktionsplan

| Test | Zu dokumentieren | Ergebnis |
|---|---|---|
| Erststart und Warmstart | PB2-Pegel, RTC-Konfiguration, Backup-Zustand | Offen |
| Erster RTC-Alarm | Tatsächliche Aufwachquelle und Ablauf | Offen |
| Mindestens zehn Sleep/Wake-Zyklen | Erneutes Alarmsetzen, Motorablauf, Systemtakt | Offen |
| Aktiv-/STOP-Verbrauch | Spannung, Messpunkt, Debugger-/LED-Zustand, Messgerät | Offen |
| Takt nach Aufwachen | Gemessene Frequenz und Timerverhalten | Offen |
| Motorpulszahl und Richtung | Messung an den realen Treibersignalen | Offen |
| Fehlender Quarz / fehlender Alarm | Definierter Fehlerpfad ohne endloses Warten | Offen |

Keine Verbrauchswerte oder Hardwaretests in diesem Paket nachgewiesen. Build-Ergebnisse stehen separat in BUILD_STATUS.txt.
