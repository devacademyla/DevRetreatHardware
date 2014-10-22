// led.cpp
#include "led2.h"

// Definición de estados
#define LED2_ESTADO_WAIT  0
#define LED2_ESTADO_ON    1
#define LED2_ESTADO_ON    1
#define LED2_ESTADO_OFF   2

// parámetros
byte led2Pin;
byte led2DutyCicle;
byte led2DutyCicleFinal;
signed int delta;

// variables
unsigned int contador; // 0 32 000
#define CNT_MAX 1000

byte led2Estado;

void led2Begin(byte arg_pin){
  led2Pin = arg_pin;
  pinMode(led2Pin,OUTPUT);
  digitalWrite(led2Pin,LOW);
  
  // IMPORTANTE: inicializar la variable de estado
  led2Estado = LED2_ESTADO_WAIT;
  led2DutyCicle = 0;
}

// Máquina de estados
void led2Run(void){
  switch(led2Estado){
    case LED2_ESTADO_WAIT:
      break;
    case LED2_ESTADO_ON:
      contador++;
      // algoritmo de la funcionalidad
      if(contador>=CNT_MAX){
        led2DutyCicle = led2DutyCicle + delta;
        analogWrite(led2Pin,led2DutyCicle);
        if(led2DutyCicle == led2DutyCicleFinal){
          led2Estado = LED2_ESTADO_WAIT;  
        }
        contador=0;
      }
      break;
    case LED2_ESTADO_OFF:
      // algoritmo de la funcionalidad
      analogWrite(led2Pin,0);
      led2Estado = LED2_ESTADO_WAIT;
      break;
    default:
      // 
      break;
  }  
}

void led2On(void){
  led2Estado = LED2_ESTADO_ON;
}

void led2Off(void){
  led2Estado = LED2_ESTADO_OFF;
}


void led2SetDutyCicle(byte arg_dutycicle){
  // Duty cicle = 0% a 100%
  // analogWrite = 0 255
  // led2DutyCicle = map(arg_dutycicle,0,100,0,255);
  led2DutyCicleFinal = map(arg_dutycicle,0,100,0,255);
  delta = led2DutyCicleFinal -led2DutyCicle;
  if(delta > 0) delta = 1;
  if(delta < 0) delta = -1;
}
