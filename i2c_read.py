import smbus
import time

device_address = 0x04

bus = smbus.SMBus(1)

def read_data():
  data = bus.read_byte(device_address)
  print("Dato recibido:", data)

def send_data(data):
  bus.write_byte(device_address, data)
  print("Dato enviado:", data)

while True:
  send_data(42) # Enviar un valor de 42 por el bus I2C
  time.sleep(1)
  read_data() # Leer el valor recibido por el bus I2C
  time.sleep(1)
