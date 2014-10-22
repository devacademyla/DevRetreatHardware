// programa 3: Comunicación Serial

// Declaraciones

// Configuración
void setup(){
  Serial.begin(9600);  // Inicializando el puerto serial a 9600 baudios (bits/sec)
}
// Loop infinito
void loop(){
  Serial.println("Hola Mundo!");  // Cadena de bytes enviados por el puerto serial
  
  delay(1000);  // Retardo de 1 segundo
}
