// Program 2: Entradas y salidas digitales

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
  estado = digitalRead(pinSwitch);
  digitalWrite(pinLed,estado);
}
