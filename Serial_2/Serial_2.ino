// Funciones
// Declaraciones
// Prototipo de funciones
void ledBegin(int arg_pin);  
void ledOn(void);
void ledOff(void);
int ledPin;

byte data; // 0 255

// Configuración
void setup(){
  Serial.begin(9600);
  ledBegin(13);
  
}

void loop(){
}

// Desarrollo de las funciones
void ledBegin(int arg_pin){
  ledPin = arg_pin;
  
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
}

// Funcion de encendido del Led
void ledOn(void){
  digitalWrite(ledPin,HIGH);
}

// Funcion de apagado del Led
void ledOff(void){
  digitalWrite(ledPin,LOW);
}

// Funciones asíncronas
void serialEvent(){
  data = Serial.read();
  // Serial.println(data);
  
  switch(data){
    case 'A':
      ledOn();
     break;
    case 'B':
      ledOff();
     break;
    default:
     break; 
  }
}

