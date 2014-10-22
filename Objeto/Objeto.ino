// Funciones
// Declaraciones
// Clase led
class LED{
  public:
    void begin(byte arg_pin);
    void on(void);
    void off(void);
  private:
    byte estado;
    byte pin;
};

byte data; // 0 255
LED hb;  // declaración de objeto hb de la clase LED

LED led2;
LED led3;
// Configuración
void setup(){
  Serial.begin(9600);

  hb.begin(13);
}

void loop(){
}

// Desarrollo de las funciones
void LED::begin(byte arg_pin){
  pin = arg_pin;
  pinMode(pin,OUTPUT);
  digitalWrite(pin,LOW);
}

// Funcion de encendido del Led
void LED::on(void){
  digitalWrite(pin,HIGH);
}

// Funcion de apagado del Led
void LED::off(void){
  digitalWrite(pin,LOW);
}

// Funciones asíncronas
void serialEvent(){
  data = Serial.read();
  // Serial.println(data);
  switch(data){
    case 'A':
      hb.on();
      /*
      llamado a la clase LED
      llamado a la funcion on de la clase LED
      variable pin Led
      llamado a digitalWrite
      ...
      ...
      ...
      */
     break;
    case 'B':
      hb.off();
     break;
    default:
     break; 
  }
}

