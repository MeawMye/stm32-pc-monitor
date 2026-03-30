import serial
import time

ser = serial.Serial("COM3", 115200)

while True:
    msg = "$CPU:35,RAM:60#"
    ser.write(msg.encode())
    print("sent:", msg)
    time.sleep(1)