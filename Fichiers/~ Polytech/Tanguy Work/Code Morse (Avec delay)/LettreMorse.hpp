#ifndef LETTREMORSE_H
#define LETTREMORSE_H

#include "Arduino.h"

class LettreMorse{   //cette classe sert à modéliser une lettre et son équivalent en Morse

  private:
    

  public:
    LettreMorse();
    String mot;
    String morse;
    void ConversionMorse();
};

#endif