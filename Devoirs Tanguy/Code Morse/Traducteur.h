#ifndef TRADUCTEUR_H_
#define TRADUCTEUR_H_

class Traducteur {  // Convertit le morse en clignotement
    public:
        Traducteur();
        void ConversionBinaire(const char* morse); // Convertie le morse en une liste binaire(0 ou 1 pour le clignotement de la led)
        bool Binaire[20] = {0}; // Liste après la conversion
        int taillebinaire = 1; // Taille de la liste
    private:
        void clignotements(bool liste[], int taille); // Liste les clignotements Long et court
        bool point[2] = {1, 0};
        bool trait[4] = {1, 1, 1, 0};
};

#endif