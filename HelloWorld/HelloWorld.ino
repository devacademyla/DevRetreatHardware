// Hola mundo !!
// 

// Declaraciones
int pinLed = 13;
int tiempo = 100; // Tiempo en milisegundos

// Configuración Inicial
void setup(){
  // Configurar el pin 13 como salida
  pinMode(pinLed,OUTPUT);
  digitalWrite(pinLed,LOW); // Estado inicial: Apagado
}
// Loop infinito / algoritmo principal
void loop(){
  digitalWrite(pinLed,LOW);  // LED OFF
  delay(tiempo);             // tiempo apagado
  digitalWrite(pinLed,HIGH); // LED ON
  delay(tiempo);            // Tiempo encendido
}
// Funciones asíncronas
