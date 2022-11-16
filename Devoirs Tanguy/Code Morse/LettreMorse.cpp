#include "LettreMorse.h"

LettreMorse::LettreMorse(){};

void LettreMorse::ConversionMorse(int lettre){

  switch (lettre){
    case 'a':
        morse = ".-";
        break;
    case 'b':
        morse = "-...";
        break;
    case 'c':
        morse = "-.-.";
        break;
    case 'd':
        morse = "-..";
        break;
    case 'e':
        morse = ".";
        break;
    case 'f':
        morse = "..-.";
        break;
    case 'g':
        morse = "--.";
        break;
    case 'h':
        morse = "....";
        break;
    case 'i':
        morse = "..";
        break;
    case 'j':
        morse = ".---";
        break;
    case 'k':
        morse = "-.-";
        break;
    case 'l':
        morse = ".-..";
        break;
    case 'm':
        morse = "--";
        break;
    case 'n':
        morse = "-.";
        break;
    case 'o':
        morse = "---";
        break;
    case 'p':
        morse = ".--.";
        break;
    case 'q':
        morse = "--.-";
        break;
    case 'r':
        morse = ".-.";
        break;
    case 's':
        morse = "...";
        break;
    case 't':
        morse = "-";
        break;
    case 'u':
        morse = "..-";
        break;
    case 'v':
        morse = "...-";
        break;
    case 'w':
        morse = ".--";
        break;
    case 'x':
        morse = "-..-";
        break;
    case 'y':
        morse = "-.--";
        break;
    case 'z':
        morse = "--..";
        break;
    default:
        morse = "";
        break;
    }
}