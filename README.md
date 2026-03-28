# STM32 PC Monitor

Real-time PC monitoring device using STM32 and FreeRTOS

## Architecture

PC → UART → STM32 → LCD

## Data Flow

UART ISR → Comm Task → Queue → Data Task → UI Task

## Features

- UART communication
- Packet parsing
- FreeRTOS-based task structure

## Status

✔ UART communication implemented  
✔ Packet parsing implemented  

🚧 RTOS task structure in planning  
🚧 LCD UI not implemented yet  
