#include <Wire.h>

void setup() {
  Wire.begin(); // inicializar la comunicación I2C
}

void loop() {
  Wire.beginTransmission(0x12); // Dirección del dispositivo Python
  Wire.write(0x01); // enviar un byte de datos
  Wire.endTransmission(); // terminar la transmisión
  delay(1000); // esperar un segundo antes de enviar el siguiente dato
}
