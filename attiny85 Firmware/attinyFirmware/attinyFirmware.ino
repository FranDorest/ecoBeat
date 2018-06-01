#include <SoftwareSerial.h>

SoftwareSerial atSerial(3,4); //Comunicacion serie con ESP8266 
long pulseCount = 0; //Numero de pulsos en 1 minuto
unsigned long lastTime = 0; 
unsigned long sendTime = 0; // Diferencia de tiempo entre el ultimo envio y la comprobacion

void setup(){
  atSerial.begin(9600); // Comunicacion serie a 115200 baudios
  pinMode(0, OUTPUT); // Led de confirmacion de interrupcion
  pinMode(1, OUTPUT); // Pin de interrupcion al ESP8266

  attachInterrupt(0, onPulse, RISING); // Interrupcion en pin 2 (int 0) 
}

void loop(){
}


void onPulse(){ // Rutina de interrupcion
  pulseCount ++;
  digitalWrite(0, !digitalRead(0));

  //enviamos la lectura una vez recibimos el pulso
  lastTime = millis();
  
  if(lastTime - sendTime >= 60000){ //Enviamos la cantidad de pulsos cada 60000 milisegundos (60segundos)
    noInterrupts();
    sendTime = lastTime;
    atSerial.println(pulseCount);
    pulseCount = 0;
    interrupts();
  }
}

