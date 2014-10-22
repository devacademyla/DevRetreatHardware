// Programa 3: Estructura condicional

// Declaraciones
int pinLed = 13;
int pinSwitch = 2;
int estado;
// Configuración
void setup(){
  pinMode(pinLed,OUTPUT); // Salida digital
  pinMode(pinSwitch,INPUT);  // Entrada digital
}

void loop(){
  if(digitalRead(pinSwitch)){
    // VERDADERO
    digitalWrite(pinLed,HIGH);
  }else{
    // FALSO
    digitalWrite(pinLed,LOW);
  }
}
