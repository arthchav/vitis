#include "LettreMorse.hpp"      //on inclut la classe LettreMorse

LettreMorse::LettreMorse(){};       //constructeur de la classe LettreMorse

/**
 * @brief Fonction qui convertit une lettre en son équivalent en Morse
 * 
 * @param mot
 */

void LettreMorse::ConversionMorse(){

  Serial.println("Ecris le mot que tu veux traduire:\n");       //on demande à l'utilisateur d'écrire le mot qu'il veut traduire
  Serial.println(mot);      //on affiche le mot entré par l'utilisateur

  Serial.println("La traduction est:\n");       //on affiche un message à l'utilisateur

  for (int i = 0; i < mot.length(); i++){       //boucle qui parcourt le mot entré par l'utilisateur
      switch (mot[i]){                              
      case 'a':
          morse += ".-";
          break;
      case 'b':
          morse += "-...";
          break;
      case 'c':
          morse += "-.-.";
          break;
      case 'd':
         morse += "-..";
          break;
      case 'e':
          morse += ".";
          break;
      case 'f':
          morse += "..-.";
          break;
      case 'g':
          morse += "--.";
          break;
      case 'h':
          morse += "....";
          break;
      case 'i':
          morse += "..";
          break;
      case 'j':
          morse += ".---";
          break;
      case 'k':
         morse += "-.-";
         break;
      case 'l':
         morse += ".-..";
          break;
     case 'm':
         morse += "--";
          break;
      case 'n':
          morse += "-.";
          break;
      case 'o':
         morse += "---";
         break;
      case 'p':
         morse += ".--.";
         break;
      case 'q':
         morse += "--.-";
         break;
      case 'r':
         morse += ".-.";
         break;
     case 's':
         morse += "...";
         break;
      case 't':
         morse += "-";
          break;
      case 'u':
          morse += "..-";
          break;
      case 'v':
          morse += "...-";
          break;
      case 'w':
          morse += ".--";
         break;
      case 'x':
          morse += "-..-";
          break;
      case 'y':
          morse += "-.--";
         break;
      case 'z':
         morse += "--..";
         break;
      case ' ':
          morse += "......." ;
          break;
      default:
          morse += "";
          break;
      }
      morse += "...";
  }

  Serial.println(morse);        //affichage de la traduction en morse
}