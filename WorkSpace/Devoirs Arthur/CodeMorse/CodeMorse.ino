#include "LettreMorse.h"

Traducteur MOT; // Crée l'objet MOT pour utiliser la fonction outils_traducteur() dans le .ino

Traducteur wait; //Crée l'objet wait pour utiliser la fonction tempo() dans le .ino

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  MOT.outils_traducteur("Hello Rob !"); // <--- Remplacez par le texte désiré !

  while (wait.tempo(false, 10000))
    ; // On marque une pause avant de répéter la phrase
}
