#include "LettreMorse.h"


// Selon la règle de Samuel Morse :

int unite_ms = 300; // C'est notre repère de temps, 1 unité de temps = 200 ms
int point = 1;      // "."
int trait = 3;      // "_" ici un trait vaut donc 3 unités de temps 
int espace = 7;     // " "
int inter_symb= 1; // Entre les points et traits 
int inter_cara= 3; // Entre les lettres 


// On écrit la fonction qui va traduire :

void Traducteur::outils_traducteur(String phrase)
{

  phrase.toLowerCase();                                 // Evite de rejouter les majuscules dans la matrice (car convertit en minuscule)
  Time_0 = millis();                                    // On photographie la clock comme 0

  for (int cara = 0; cara < phrase.length(); cara++)    // On prend un caractère
  { 
    for (int i = 0; i < 37; i++)                        // Puis on prend un élément de la Matrice
    { 
      if (phrase[cara] == MatriceTrad[i][0].charAt(0))  // Et on vérifie si le caractère vaut l'élément de la matrice (que le convertie avec .chartAt(index) )
      { 
        imprimer(i);                                    // On imprime la lettre avec la LED Arduino et on passe au caractère suivant avec break 
        break;
      }
    }
  }
}


// Voici la fontion qui va nous permettre de faire clignoter la LED :

void Traducteur::imprimer(int i)
{
  
  if (i == 0)                                 // Si la lettre est un espace
  {
    while (tempo(false, espace * unite_ms));  // On attend (LED éteint) le temps d'un espace
  }

  else
  {
    for (int k = 0; k < MatriceTrad[i][1].length(); k++)
    {
      if (MatriceTrad[i][1][k] == taille[0])            // Si la lettre est un point
      {
        while (tempo(true, point * unite_ms));          // On attend (LED allumée) le temps d'un point
        while (tempo(false, inter_symb * unite_ms));    // On attend (LED éteinte) le temps d'un point
      }
      else                                              // Si la lettre est un trait
      {
        while (tempo(true, trait * unite_ms));          // On attend (LED allumée) le temps d'un trait
        while (tempo(false, inter_symb * unite_ms));    // On attend (LED éteinte) le temps d'un point
      }
    }
    
    while (tempo(false, inter_cara * unite_ms));        // On attend (LED éteinte) entre les lettres
  }
}



// Remplace l'ancien delay() par tempo() :

bool Traducteur::tempo(bool Etat_LED, int Delta_T)
{
  digitalWrite(13, Etat_LED);                 // Eclaire ou non la LED

  if (millis() - Time_0 >= Delta_T)           // Si le temps écoulé est supérieur au délai voulu
  {
    Time_0 = millis();                        // On réinitialise le temps
    return false;                             // et  on retourne Faux 
  }

  else
  {
    return true;                              // Sinon on retourne Vrai 
  }
  
}

