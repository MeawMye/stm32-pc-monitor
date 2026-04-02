import psutil
import serial
import time


def get_system_status():
    cpu = int(psutil.cpu_percent(interval=0.5))
    ram = int(psutil.virtual_memory().percent)
    return cpu, ram

def build_packet(cpu, ram):
    return f"$CPU:{cpu},RAM:{ram}#"


ser = serial.Serial("COM3", 115200)

while True:
    cpu, ram = get_system_status()
    packet = build_packet(cpu, ram)
    ser.write(packet.encode())
    print(packet)
    time.sleep(5)

