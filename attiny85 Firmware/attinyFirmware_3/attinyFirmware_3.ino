#include <SoftwareSerial.h>

#define DEBOUNCE 10                     //ms minimos entre interrupciones para evitar rebotes

bool interruptEnabled = true;

unsigned long pulseCount = 0;             //Suma de Pulsos
unsigned long pulseAnterior = 0;          //pulsos anterior para calcular pulsos por minuto
unsigned long lastTime = 0;               // Diferencia de tiempo entre el ultimo envio y la comprobacion
unsigned long interruptTime = 0;          //Tiempo en el que se inicia la interrupcion
unsigned long long currentTime = 0;            //guarda el valor de millis()

SoftwareSerial atSerial(4,3);             //Comunicacion serie con ESP8266

void setup(){

  atSerial.begin(115200);                   // Comunicacion serie a 115200 baudios
  
  pinMode(0, OUTPUT);                     // Led de confirmacion de interrupcion
  pinMode(1, OUTPUT);                     // Pin de interrupcion al ESP8266

  attachInterrupt(0, onPulse, FALLING);   // Interrupcion en pin 2 (int 0) 
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
    currentTime = millis();
  }
  
  if(currentTime - lastTime >= 60000){
    lastTime = millis();
    atSerial.print("imp_total:");
    atSerial.print(pulseCount);
    atSerial.print(",imp_min:");
    atSerial.println(pulseCount - pulseAnterior);
    pulseAnterior = pulseCount;
  }
}


void onPulse(){// Rutina de interrupcion
  noInterrupts();
  interruptTime = millis(); 
  interruptEnabled = false;
  pulseCount ++;
  digitalWrite(0, !digitalRead(0));
}


