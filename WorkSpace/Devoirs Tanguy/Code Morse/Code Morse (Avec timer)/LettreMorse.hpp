#ifndef LETTREMORSE_H
#define LETTREMORSE_H   

#include "Arduino.h"    //on inclut la bibliothèque Arduino.h   

class LettreMorse{   //cette classe sert à modéliser une lettre et son équivalent en Morse

  private:
    

  public:   
    LettreMorse();    //constructeur de la classe LettreMorse
    String mot;    //attribut de la classe LettreMorse
    String morse;   //attribut de la classe LettreMorse
    void ConversionMorse();   //méthode de la classe LettreMorse
};

#endif