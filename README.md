# STM32 PC Monitor

Real-time PC monitoring device using STM32 and FreeRTOS

### Architecture

PC → UART → STM32 → LCD

### Data Flow

UART ISR → Comm Task → Queue → Data Task → UI Task

### Features

- UART communication
- Packet parsing
- FreeRTOS-based task structure

### Status

✔ UART communication implemented  
✔ Packet parsing implemented  

🚧 RTOS task structure in planning  
🚧 LCD UI not implemented yet  

---
- 260330
PC-side test script for sending system status packets to STM32 over UART.

Example:
$CPU:35,RAM:60#

Run(in cmd):
python send.py

- pip install -r requirments.txt
