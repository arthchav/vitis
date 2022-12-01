#include "Traducteur.hpp"

Traducteur::Traducteur(){};

/**
 * @brief Fonction qui traduit le code Morse en LED
 * 
 * @param morse
 */

void Traducteur::traducteurmillis(String text) {   //Convertit en clignotement le message morse
  for (int i = 0; i < text.length();i++) {    //Boucle qui parcourt le message morse
    if (text[i]=='.'){
      temps = millis();   //on récupère le temps en millisecondes
      while ((millis()- temps) < 500){      //tant que le temps en millisecondes est inférieur à 500 on allume la LED 
        digitalWrite(LED_BUILTIN, HIGH);    
      }
      while ((millis()-temps) < 1000){        //tant que le temps en millisecondes est inférieur à 1000 on éteint la LED
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
    else if (text[i]=='-'){
      temps = millis();   //on récupère le temps en millisecondes
      while ((millis()- temps) < 1000){   //tant que le temps en millisecondes est inférieur à 1000 on allume la LED
        digitalWrite(LED_BUILTIN, HIGH);
      }
      while ((millis()-temps) < 2000){    //tant que le temps en millisecondes est inférieur à 2000 on éteint la LED
        digitalWrite(LED_BUILTIN, LOW);
      }
    } 
  }
}