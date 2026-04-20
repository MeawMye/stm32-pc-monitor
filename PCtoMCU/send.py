import psutil
import serial
import time


prev_net_total = None
prev_time = None


def get_system_status():
    global prev_net_total
    global prev_time

    cpu = int(psutil.cpu_percent(interval=0.5))
    ram = int(psutil.virtual_memory().percent)

    net_io = psutil.net_io_counters()
    current_total = net_io.bytes_sent + net_io.bytes_recv
    current_time = time.time()

    if prev_net_total is None or prev_time is None:
        net = 0
    else:
        delta_bytes = current_total - prev_net_total
        delta_time = current_time - prev_time

        if delta_time > 0:
            net = int((delta_bytes / 1024) / delta_time)   # KB/s
        else:
            net = 0

    prev_net_total = current_total
    prev_time = current_time

    return cpu, ram, net


def build_packet(cpu, ram, net):
    return f"$CPU:{cpu},RAM:{ram},NET:{net}#"


ser = serial.Serial("COM3", 115200)

while True:
    cpu, ram, net = get_system_status()
    packet = build_packet(cpu, ram, net)
    ser.write(packet.encode())
    print(packet)
    time.sleep(5)