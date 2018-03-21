#include <SoftwareSerial.h>

bool interruptEnabled = true;

unsigned long pulseCount = 0;                      //Numero de pulsos en 1 minuto
unsigned long lastTime = 0;
unsigned long interruptTime = 0;          // Diferencia de tiempo entre el ultimo envio y la comprobacion

SoftwareSerial atSerial(3,4);             //Comunicacion serie con ESP8266

void setup(){

  atSerial.begin(9600);                   // Comunicacion serie a 9600 baudios
  
  pinMode(0, OUTPUT);                     // Led de confirmacion de interrupcion
  pinMode(1, OUTPUT);                     // Pin de interrupcion al ESP8266

  attachInterrupt(0, onPulse, FALLING);   // Interrupcion en pin 2 (int 0) 
}

void loop(){
  
  if(millis() - interruptTime >= 10 && !interruptEnabled){  //activamos interrupciones 10ms despues 
    interrupts();                                           //de cada interrupcion para evitar rebotes.
    interruptEnabled = true;
  }

  if(millis() - lastTime >= 60000){
    lastTime = millis();
    atSerial.println(pulseCount);
    pulseCount = 0;
  }
}


void onPulse(){// Rutina de interrupcion
  interruptTime = millis(); 
  noInterrupts();
  interruptEnabled = false;
  pulseCount ++;
  digitalWrite(0, !digitalRead(0));
}

