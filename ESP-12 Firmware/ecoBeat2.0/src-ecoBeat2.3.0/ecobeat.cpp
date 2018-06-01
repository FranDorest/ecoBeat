/*
 * -------------------------------------------------------------------
 * ATTiny Serial to Emoncms gateway
 * -------------------------------------------------------------------
 * */

#include "emonesp.h"
#include "input.h"
#include <SoftwareSerial.h>
#include "wifi.h"

SoftwareSerial tinySerial(D2, D1);

double potencia = 0;
double energia = 0;

unsigned int lastSend;
unsigned int currTime;
unsigned int delta_pulsos = 0;
unsigned int pulsos_actual = 0;
unsigned int pulsos_anterior = 0;

void tiny_setup(int br_tiny){
  tinySerial.begin(br_tiny);
}

extern bool getTinyString(String& data){

  if(tinySerial.available()){
    lastSend = currTime;
    currTime = millis();
    char inputBuffer[50];

    String tinyString = tinySerial.readStringUntil('\n');
    pulsos_actual = tinyString.toInt();
    delta_pulsos = pulsos_actual - pulsos_anterior;
    calcValores(delta_pulsos);
    //.----------------
    sprintf(inputBuffer, "Potencia:%d,Energia:%d,%d:ip", potencia, energia, ipadress);
    gotData = true;
  }

  return gotData;
}

void calcValores(unsigned int _delta_pulsos){

    if(_delta_pulsos <= 0){
      potencia = 0.00;
      energia = pulsos_actual;
    }
    else{
      potencia = 3600000/((currTime-lastSend)/delta_pulsos);
      energia = pulsos_actual;
      pulsos_anterior = pulsos_actual;
    }
  }
}

