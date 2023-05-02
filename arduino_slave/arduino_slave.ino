#include <Wire.h>

#define SLAVE_ADDRESS 0x04

byte data = 0;

void setup() {
  Serial.begin(9600); // Inicializar el puerto serial
  Wire.begin(SLAVE_ADDRESS); // Inicializar la comunicación I2C como esclavo
  Wire.onRequest(requestEvent); // Definir la función para enviar datos por el bus I2C
  Wire.onReceive(receiveEvent); // Definir la función para recibir datos por el bus I2C
}

void loop() {
  delay(100);
}

void requestEvent() {
  Wire.write(data); // Enviar datos por el bus I2C
}

void receiveEvent(int byteCount) {
  if (Wire.available() > 0) {
    data = Wire.read(); // Leer datos recibidos por el bus I2C
    Serial.print("Dato recibido: ");
    Serial.println(data);
  }
}
