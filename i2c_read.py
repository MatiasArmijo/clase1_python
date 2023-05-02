import smbus

bus = smbus.SMBus(1) # Establecer conexión I2C en el bus 1
address = 0x04 # Dirección del Arduino

while True:
    data = bus.read_byte(address) # Leer un byte de datos del Arduino
    print("Dato recibido: ", data)