# 🚗 Seat Heater Control System – Real-Time Embedded Project

This project implements a real-time **Seat Heater Control System** for the driver and passenger seats in a vehicle, built on the **Tiva C (TM4C123GH6PM)** microcontroller using **FreeRTOS**. The system simulates temperature sensing, heating control, diagnostics, and real-time communication using LEDs, buttons, UART, and more.

---

## 🧩 Project Overview

Each seat includes:
- **Control Button**: Toggles heating levels (Off → Low → Medium → High → Off...).
- **Temperature Sensor**: Reads the current seat temperature (via ADC).
- **Heating Element**: Controlled using simulated intensity (via colored LEDs).
- **Shared Display**: Outputs current status over UART.
- **Diagnostic LED**: Alerts on sensor malfunction (Red LED).

### Heating Levels:
- **Off**: No heating
- **Low**: 25°C target
- **Medium**: 30°C target
- **High**: 35°C target

Heater intensity adapts automatically:
- **High**: ΔT ≥ 10°C (Cyan LED)
- **Medium**: 5°C ≤ ΔT < 10°C (Blue LED)
- **Low**: 2°C ≤ ΔT < 5°C (Green LED)
- **Off**: ΔT < 2°C or overshoot

---

## ⚙️ System Features

- 🌡️ **Dynamic Temperature Control** with ±2°C tolerance
- 🚨 **Diagnostics Handling** (sensor range: 5°C – 40°C)
- 💾 **Non-Volatile Memory (To Be Done)** for:
  - Last heating level
  - Diagnostic logs
- 📊 **Runtime Measurements**:
  - Task execution time
  - CPU load
  - Resource lock times (with GPTM)

---

## 🧪 Testing Scenario

1. Passenger sets heating to **High** at 10°C
2. Heater runs at **High** intensity (cyan)
3. At 25°C → **Medium** (blue)
4. At 30°C → **Low** (green)
5. At ≥35°C → Heater **Off**
6. At 33°C → Heater reactivates at **Low**
7. Data sent via **UART**
8. Out-of-range temperature → **Error LED On**, control disabled

---

## 🔧 Hardware Components

| Component              | Description                             |
|------------------------|-----------------------------------------|
| Tiva C (TM4C123GH6PM)  | Microcontroller                         |
| Potentiometer (LM35)   | Simulated temperature sensor            |
| LEDs                   | Heater intensity (green, blue, cyan), Error (red) |
| Push Buttons           | Heating level control (console & steering) |
| UART                   | Output temperature, heating state, errors |

---

## 🧠 FreeRTOS Tasks Overview

| Task Name                | Type       | Description                              |
|--------------------------|------------|------------------------------------------|
| Temperature Reader       | Periodic   | Reads and filters temperature input      |
| Heater Controller        | Event-based| Controls LED intensity based on ΔT       |
| UART Display             | Periodic   | Sends system status via UART             |
| Button Handler           | Interrupt  | Handles heating level control inputs     |
| Diagnostics Monitor      | Event-based| Logs failures and sensor issues          |
| NVM Logger (To Be Done)  | Periodic   | Stores data in non-volatile memory       |

---

