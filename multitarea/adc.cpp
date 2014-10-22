#include "adc.h"

#define  ADC_ESTADO_WAIT  0
#define  ADC_ESTADO_CONVIERTE  1
#define  ADC_ESTADO_ENVIA      2

// parametro
byte adcPin;
float voltaje;
byte adcEstado;

void adcBegin(byte arg_pin){
  adcPin = arg_pin;
  adcEstado =  ADC_ESTADO_WAIT;
}

void adcRun(void){
  switch(adcEstado){
    case ADC_ESTADO_WAIT:
      break;
    case ADC_ESTADO_CONVIERTE:
      voltaje = (float)(analogRead(adcPin)*5.0)/1023;
      
      adcEstado = ADC_ESTADO_ENVIA;
      break;
    case ADC_ESTADO_ENVIA:
      Serial.print("V= ");
      Serial.print(voltaje);
      Serial.println(" v");
      
      adcEstado = ADC_ESTADO_WAIT;
      break;
    default:
      break;
  }
}

void getAdc(void){
  adcEstado = ADC_ESTADO_CONVIERTE;
}
