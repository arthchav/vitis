#include <Arduino.h>
#include "LettreMorse.h"
#include "Traducteur.h"

const int blinkSpeed = 200;
int mot;

LettreMorse LM;
Traducteur Tr;


void setup() {

  Serial.begin(9600);

}


void loop() {

  if (Serial.available() > 0) {
    
    mot = Serial.read();

    LM.ConversionMorse(mot);

    Tr.ConversionBinaire(LM.morse); 
    Serial.println(LM.morse);

    for(int i = 0; i < Tr.taillebinaire; i++){
      delay(blinkSpeed);
      digitalWrite(LED_BUILTIN, Tr.taillebinaire[i]); // Affiche l'état de la LED indiqué dans la trame temporelle finale.
    }

    delay(blinkSpeed*2); // Pause entre chaque LED
  }
}