#include "Traducteur.hpp"   //on inclut la classe Traducteur
#include "LettreMorse.hpp"    //on inclut la classe LettreMorse

LettreMorse Lm;   //création d'un objet de type LettreMorse
Traducteur Tr;    //création d'un objet de type Traducteur

void setup() { 

  Serial.begin(9600);   //initialisation du port série
  pinMode(LED_BUILTIN, OUTPUT);   //initialisation de la LED
}

void loop() {

if (Serial.available()){  //si le moniteur série reçoit un caractère
      Lm.mot = Serial.readString(); //on lit la lettre entrée par l'utilisateur
      Lm.ConversionMorse();   //exécutuion de la fonction ConversionMorse
      Tr.traducteurmillis(Lm.morse);  //exécution de la fonction traducteurmillis
}

}