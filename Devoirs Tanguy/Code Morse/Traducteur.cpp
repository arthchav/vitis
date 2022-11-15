#include "Traducteur.h"
#include "LettreMorse.h"

Traducteur::Traducteur(){};


void Traducteur::ConversionBinaire(const char* morse){

  taillebinaire = 1;
    
  for(int i = 0; true; i++) {

    if(morse[i] == '.'){clignotements(point, sizeof(point));} // Ajoute a la liste le point

    if(morse[i] == '-'){clignotements(trait, sizeof(trait));} // Ajoute a la liste le trait

    if(morse[i] == NULL){break;} 
  }

}


void Traducteur::clignotements(bool liste[], int taille){

  for(int i = 0; i < taille; i++){
    
    Binaire[taillebinaire+i] = liste[i]; // Ajoute le code binaire de la lettre à la liste
  }

  taillebinaire += taille; // Agrandit la taille de la liste

}