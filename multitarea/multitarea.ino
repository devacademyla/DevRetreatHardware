/*Implementación de un sistema multitarea
Metodología:
Loop infinito
Llamado consecutivo de tareas (funciones "run")
Cambio de contexto por interrupción
*/

#include "led.h"
#include "led2.h"
#include "adc.h"

void setup(){
  Serial.begin(9600);
  // tareaInit();
  ledBegin(13);
  led2Begin(3);
  adcBegin(0);
}

void loop(){
  // tareaRun();
  ledRun();
  led2Run();
}

void serialEvent(){
  switch(Serial.read()){
    case 'A':
      ledOn();
      break;
    case 'B':
      ledOff();
      break;
    case 'C':
      getAdc();
      break;
    case '1':
      led2SetDutyCicle(10);
      led2On();
      break;
    case '2':
      led2SetDutyCicle(50);
      led2On();
      break;
    case '3':
      led2SetDutyCicle(100);
      led2On();
      break;
    default:
      break;
  }
}
