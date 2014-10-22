// led.cpp
#include "led.h"

// Definición de estados
#define LED_ESTADO_WAIT  0
#define LED_ESTADO_ON    1
#define LED_ESTADO_OFF   2

// parámetros
byte ledPin;
byte ledEstado;

void ledBegin(byte arg_pin){
  ledPin = arg_pin;
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  
  // IMPORTANTE: inicializar la variable de estado
  ledEstado = LED_ESTADO_WAIT;
}

// Máquina de estados
void ledRun(void){
  switch(ledEstado){
    case LED_ESTADO_WAIT:
      break;
    case LED_ESTADO_ON:
      // algoritmo de la funcionalidad
      digitalWrite(ledPin,HIGH);
      ledEstado = LED_ESTADO_WAIT;
      break;
    case LED_ESTADO_OFF:
      // algoritmo de la funcionalidad
      digitalWrite(ledPin,LOW);
      ledEstado = LED_ESTADO_WAIT;
      break;
    default:
      // 
      break;
  }  
}

void ledOn(void){
  ledEstado = LED_ESTADO_ON;
}

void ledOff(void){
  ledEstado = LED_ESTADO_OFF;
}
