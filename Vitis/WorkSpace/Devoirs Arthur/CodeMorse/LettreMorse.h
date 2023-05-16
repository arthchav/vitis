#include "Arduino.h"

class Traducteur
{

public:
    // Les fonctions en public qui seront utilisées dans les autres fichiers

    void outils_traducteur(String phrase); // Fonction princiaple pour traduire 
    bool tempo(bool Etat_LED, int Delta_T); // Fonction qui retourne Vrai ou Faux en fonction du temps écoulé 

private:
    // On commence par déclarer nos variables :

    const char taille[1] = "._"; // Ce petit tableau va nous permettre de faire la différence entre . et _
    long Time_0 = 0;    // On va utiliser cette variable pour initialiser le temps

    // Puis nos fonctions :

    void imprimer(int i); // Allume ou non la LED

    // La matrice contenant les données :

    String MatriceTrad[37][2] = {

        {" ",""},  {"a","._"},  {"b","_..."}, {"c","_._."}, {"d","_.."},  {"e","."},  {"f",".._."}, {"g","__."},  {"h","...."}, {"i",".."}, 
         {"j",".___"}, {"k","_._"},  {"l","._.."}, {"m","__"}, {"n","_."}, {"o","___"},  {"p",".__."},  {"q","__._"},  {"r","._."},  {"s","..."},  
         {"t","_"},  {"u",".._"},  {"v","..._"}, {"w",".__"},  {"x","_.._"}, {"y","_.__"}, {"z","__.."}, {"0","_____"}, {"1",".____"},  
         {"2","..___"},  {"3","...__"},  {"4","...._"},  {"5","....."},  {"6","_...."},  {"7","__..."},  {"8","___.."},  {"9","____."},
    };
};
