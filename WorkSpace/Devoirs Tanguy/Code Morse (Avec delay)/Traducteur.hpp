#ifndef TRADUCTEUR_H
#define TRADUCTEUR_H

#include "Arduino.h"

class Traducteur   //Une classe qui permet de prendre un mot et de le convertir en clignotement
{

private:
    String morse;


public:
    Traducteur();
    void point();
    void trait();
    void traducteurdelay(String text);


};

#endif