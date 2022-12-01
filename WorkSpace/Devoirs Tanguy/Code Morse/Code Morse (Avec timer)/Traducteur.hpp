#ifndef TRADUCTEUR_H
#define TRADUCTEUR_H

#include "Arduino.h"    //on inclut la bibliothèque Arduino.h

class Traducteur   //Une fonction qui permet de prendre un mot et de le convertir en clignotement
{

  private:
    String morse;   //attribut de la classe Traducteur
    int temps;    //attribut de la classe Traducteur
    

  public:
    Traducteur();   //constructeur de la classe Traducteur
    void traducteurmillis(String text);   //fonction qui traduit le code Morse en LED


};

#endif