#include "Traducteur.hpp"

Traducteur::Traducteur(){};

void Traducteur::traducteurmillis(String text) {   //Convertit en clignotement le message morse
  for (int i = 0; i < text.length();i++) {
    if (text[i]=='.'){
      temps = millis();
      while ((millis()- temps) < 500){
        digitalWrite(LED_BUILTIN, HIGH);
      }
      while ((millis()-temps) < 1000){
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
    else if (text[i]=='-'){
      temps = millis();
      while ((millis()- temps) < 1000){
        digitalWrite(LED_BUILTIN, HIGH);
      }
      while ((millis()-temps) < 2000){
        digitalWrite(LED_BUILTIN, LOW);
      }
    } 
  }
}