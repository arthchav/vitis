#include "Traducteur.hpp"

Traducteur::Traducteur(){};


void Traducteur::trait() {    //Clignotement led long pour un trait
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void Traducteur::point() {   //Clignotement led court pour un point
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void Traducteur::traducteurdelay(String text) {   //Convertit en clignotement le message morse
  for (int i = 0; i < text.length(); i++) {
    if (text[i] == '.') {
      point();
    }
    else if (text[i] == '-'){
      trait();
    }
  }
}