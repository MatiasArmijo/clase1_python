#include <Wire.h>

String inputString = "";         // Cadena de texto para guardar la cadena recibida por I2C
bool stringComplete = false;     // Bandera booleana

int led = 13;
int direccion=31; //Dirección asignada al ARduino. Asegúrate de que utilices esta dirección en el código de la Raspberry Pi
 
void setup() {
  pinMode(led, OUTPUT);
  Wire.begin(direccion);        // Nos unimos al bus i2c bus con la dirección asignada
  Wire.onReceive(receiveEvent); // Registramos el evento de recepción de datos
  Serial.begin(9600);
  inputString.reserve(200);
}
 
void loop() {
  
  if (stringComplete) {
    Serial.println("Cadena recibida completa");
    inputString.remove(0,1);//Removemos 1 carácter. El caracter con index 0, caracter adicional sin utilidad que está mandando Raspberry Pi
    
    if (inputString.equals("off") ){
      digitalWrite(13,0);
      Serial.println("Apagado");
    }
    else if (inputString.equals("on") ){
      digitalWrite(13,1);
      Serial.println("Encendido");
    }

    Serial.println(" ");
    inputString = "";
    stringComplete = false;
  }
  
}
 
void receiveEvent(int howMany) {
  

  while(Wire.available()>0) // Mientras tengamos caracteres en el buffer
  {
    char inChar = (char)Wire.read();
    Serial.print(inChar); 
    if (inChar == '\n') {
      stringComplete = true;
    }
    else{
      inputString += inChar;
    }
  }
  
}
