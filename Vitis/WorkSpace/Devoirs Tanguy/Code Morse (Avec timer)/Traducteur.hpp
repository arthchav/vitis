#ifndef TRADUCTEUR_H
#define TRADUCTEUR_H

#include "Arduino.h"

class Traducteur   //Une fonction qui permet de prendre un mot et de le convertir en clignotement
{

  private:
    String morse;
    int temps;
    

  public:
    Traducteur();
    void traducteurmillis(String text);


};

#endif