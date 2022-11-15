#ifndef LETTRE_H
#define LETTRE_H

class LettreMorse{ //permet de convertir les lettres en morses
    private:

    public:
        LettreMorse();
        void ConversionMorse(int lettre); //Convertie la lettre en morse
        const char* morse; //Enregistre la traduction en morse

}; 

#endif