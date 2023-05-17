
#include "Traducteur.hpp"
#include "LettreMorse.hpp"

LettreMorse Lm;
Traducteur Tr;

void setup() { 

  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

if (Serial.available()){
      Lm.mot = Serial.readString();
      Lm.ConversionMorse();
      Tr.traducteurdelay(Lm.morse);
}

}