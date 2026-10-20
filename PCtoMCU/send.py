import psutil
import serial
import time
import argparse
from serial.tools import list_ports


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


def find_port():
    ports = list(list_ports.comports())
    for p in ports:
        if "stlink" in (p.description or "").lower() or "stmicroelectronics" in (p.manufacturer or "").lower():
            return p.device
    if len(ports) == 1:
        return ports[0].device
    return None


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-p", "--port", help="serial port (e.g. COM5). auto-detect if omitted")
    parser.add_argument("-b", "--baud", type=int, default=115200)
    parser.add_argument("-i", "--interval", type=float, default=1.0, help="send period in seconds (min ~0.5)")
    args = parser.parse_args()

    port = args.port or find_port()
    if port is None:
        print("COM port not found. Available ports:")
        for p in list_ports.comports():
            print(f"  {p.device}: {p.description}")
        print("Use: python send.py --port COMx")
        return

    print(f"Using {port}")
    with serial.Serial(port, args.baud) as ser:
        while True:
            cpu, ram, net = get_system_status()
            packet = build_packet(cpu, ram, net)
            ser.write(packet.encode())
            print(packet)
            time.sleep(max(0, args.interval - 0.5))


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        pass