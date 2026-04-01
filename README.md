## STM32 PC Monitor

Real-time PC monitoring device using STM32 and FreeRTOS

### Architecture

PC → UART → STM32 → LCD

### Data Flow

UART ISR → Comm Task → Queue → Data Task → UI Task

### Features

- UART communication
- Packet parsing
- FreeRTOS-based task structure

---
260330
PC-side test script for sending system status packets to STM32 over UART.

Example:
$CPU:35,RAM:60#

Run(in cmd):
python send.py

- pip install -r requirments.txt
---
260331

RTOS Integration
: Before applying FreeRTOS,packet processing was handled directly in the main loop
after the UART interrupt set a packet-ready flag.

Before:
UART ISR -> packet_ready flag -> main loop -> ParsePacket() -> PrintStatus()

*After enabling FreeRTOS, the packet handling flow was moved from the main loop to a dedicated communication task.*

After:
UART ISR -> packet_ready flag -> CommTask -> ParsePacket() -> PrintStatus()

This change separated interrupt-level reception from packet processing logic and made the structure closer to an RTOS-based communication pipeline.
----
260401
RTOS Signal-Based Communication
:The initial implementation used a polling mechanism with a shared flag(packet_ready) to trigger packet  processing.

After:
UART ISR -> osSignalSet() -> CommTask(blocked on osSignalWait) -> ParsePacket()

This change elimenates unnecessary polling and allows the task to remain blocked until a packet is fully received, improving efficiency and responsiveness.

