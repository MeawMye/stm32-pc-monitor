## STM32 PC Monitor

Real-time PC monitoring system using STM32F769I-DISCO and FreeRTOS.

### Architecture

PC (Python) → UART → STM32 → LCD

### Features

- Real-time CPU / RAM usage display
- Network traffic monitoring (KB/s)
- Graph visualization with history buffer
- FreeRTOS-based task structure
- UART interrupt + packet parsing

### Data Format

$CPU:35,RAM:62,NET:120#

### Data Flow

UART ISR → Comm Task → Parser → System Status → UI Task → LCD

### Implementation Details

- Python (psutil) for system data collection
- UART interrupt-based communication
- Queue/Signal-based RTOS structure
- Ring buffer for graph history
- Dynamic scaling for network graph

### Status

- CPU / RAM monitoring ✔
- NET monitoring ✔
- Graph visualization ✔
- UI implementation ✔

### Future Work

- Connection status (Connected / Disconnected)
- CPU temperature monitoring
- UI improvements
