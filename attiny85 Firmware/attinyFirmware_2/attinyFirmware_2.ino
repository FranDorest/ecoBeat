#include <SoftwareSerial.h>

#define DEBOUNCE 10                       //ms minimos entre interrupciones para evitar rebotes

bool interruptEnabled = true;
bool isSending = false;

unsigned long pulseCount = 0;             //Numero de pulsos en 1 minuto
unsigned long lastTime = 0;
unsigned long interruptTime = 0;          // Diferencia de tiempo entre el ultimo envio y la comprobacion
unsigned long currentTime = 0;

SoftwareSerial atSerial(3,4);             //Comunicacion serie con ESP8266

void setup(){

  atSerial.begin(9600);                   // Comunicacion serie a 9600 baudios
  
  pinMode(0, OUTPUT);                     // Led de confirmacion de interrupcion
  pinMode(1, OUTPUT);                     // Pin de interrupcion al ESP8266
  

  attachInterrupt(0, onPulse, FALLING);   // Interrupcion en pin 2 (int 0) 
  atSerial.println("vivo");
}

void loop(){
  
  if(millis() - interruptTime >= DEBOUNCE && !interruptEnabled){  //activamos interrupciones 10ms despues 
    interrupts();                                                 //de cada interrupcion para evitar rebotes.
    interruptEnabled = true;
  }
  
  if (millis() < lastTime){
    currentTime = lastTime + millis();
    
  }
  else{
    currentTime = millis;
  }
  
  if(currentTime - lastTime >= 60000){
    isSending = true;
    lastTime = millis();
    atSerial.println(pulseCount);
    pulseCount = 0;
    isSending = false;
  }
}


void onPulse(){// Rutina de interrupcion
  interruptTime = millis(); 
  noInterrupts();
  interruptEnabled = false;
  pulseCount ++;
  digitalWrite(0, !digitalRead(0));
  atSerial.println("pulso");
}

