// Funciones
// Declaraciones
// Prototipo de funciones
void ledBegin(int arg_pin);  
void ledOn(void);
void ledOff(void);
int ledPin;

void setup(){

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
