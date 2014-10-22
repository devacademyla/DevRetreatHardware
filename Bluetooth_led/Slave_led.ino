#define RxD 1
#define TxD 0

#define PINLED 13

#define LEDON()     digitalWrite(PINLED, HIGH)
#define LEDOFF()    digitalWrite(PINLED, LOW)

#define DEBUG_ENABLED  1

// Prototipo de las funciones
void setupBlueToothConnection(void);  // ¿Qué hace la función?
char recvChar;  // Byte recibido

void setup(){
    pinMode(PINLED, OUTPUT);
    LEDOFF();  // Inicialización del LED
    
    setupBlueToothConnection();
}

void loop(){

}

void serialEvent(){
  //check if there's any data sent from the remote bluetooth shield
  recvChar = Serial.read();
  
  switch(recvChar){
    case '0':
      LEDON();
      break;
    case '1':
      LEDOFF();
      break;
    default:
      break;
  }
}

// Función de configuración del Shield Diente Azul
void setupBlueToothConnection()
{
    Serial.begin(38400);                           // Establece la velocidad de transmición de bits para comunicarse con el Bluetooth    Serial.print("\r\n+STWMOD=0\r\n");             // set the bluetooth work in slave mode
    Serial.print("\r\n+STNA=DienteAzul\r\n");      // Establece el nombre del terminal Blueetooth "DienteAzul"
    Serial.print("\r\n+STOAUT=1\r\n");             // Permitimos la paridad
    Serial.print("\r\n+STAUTO=0\r\n");             // Autoconección
    delay(2000);                                   // This delay is required.
    Serial.print("\r\n+INQ=1\r\n");                // Permite que el terminal blueetooth sea visible
    delay(2000);                                   // This delay is required.
    Serial.flush();
}
