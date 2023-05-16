// On commence par nommé chaque borne pour un code lisible :

#define borneENA 10 // On associe la borne "ENA" du L298N à la pin D10 de l'arduino
#define borneENB 5  // On associe la borne "ENB" du L298N à la pin D5 de l'arduino

#define PinDROITE_avant 7  // fait avancer le côté droit (borne IN3 du pont en H)
#define PinDROITE_recule 6 // fait reculer le côté droit (borne IN4 du pont en H)
#define PinGAUCHE_avant 9  // fait avancer le côté gauche (borne IN1 du pont en H)
#define PinGAUCHE_recule 8 // fait reculer le côté gauche (borne IN2 du pont en H)


void setup()
{

    // Configuration de toutes les pins de l'Arduino en "sortie" (car elles attaquent les entrées du module L298N)
    pinMode(borneENA, OUTPUT);
    pinMode(borneENB, OUTPUT);

    pinMode(PinGAUCHE_avant, OUTPUT);
    pinMode(PinGAUCHE_recule, OUTPUT);
    pinMode(PinDROITE_avant, OUTPUT);
    pinMode(PinDROITE_recule, OUTPUT);

    Serial.begin(9600); // Démarrage de la communication série
    Serial1.begin(9600); // Démarrage de la communication du cerveau 1 de l'aruduino Mega

}

char etat; // Nouvelle variable qui contient les dernières communication Bluetooth 

void loop()

{

etat=(Serial1.read()); // On récupère l'information Bluetooth 


  if (etat=='H')
  {
    avant();
    }

  else if (etat=='B')
  {
    arriere();
    }

  else if (etat=='G')
  {
    gauche();
    }

  else if (etat=='D')
  {
    droite(); 
    }

  else if (etat=='S')
  {
    stop_moteur();
    }

}



void avant()
{

    // Le fait d'utiliser analogWrite fait que l'on peut utiliser une puissance personalisé, ici on utilise 200/256 de puissance.     
    analogWrite(borneENB, 200);
    analogWrite(borneENA, 200);

    // Configuration du L298N en "marche avant", pour le moteur connecté au pont B. Selon sa table de vérité, il faut que :
    digitalWrite(borneIN3, HIGH); // L'entrée IN3 doit être au niveau haut
    digitalWrite(borneIN4, LOW);  // L'entrée IN4 doit être au niveau bas

    // Configuration du L298N en "marche avant", pour le moteur connecté au pont A. Selon sa table de vérité, il faut que :
    digitalWrite(borneIN1, HIGH); // L'entrée IN1 doit être au niveau haut
    digitalWrite(borneIN2, LOW);  // L'entrée IN2 doit être au niveau bas
}

void arriere()
{
    // Le fait d'utiliser analogWrite fait que l'on peut utiliser une puissance personalisé, ici on utilise 200/256 de puissance. 
    analogWrite(borneENB, 200);
    analogWrite(borneENA, 200);

    // Puis on configure le L298N en "marche arrière", pour le moteur câblé sur le pont B. Selon sa table de vérité, il faut que :
    digitalWrite(borneIN3, LOW);  // L'entrée IN3 doit être au niveau bas
    digitalWrite(borneIN4, HIGH); // L'entrée IN4 doit être au niveau haut

    // Puis on configure le L298N en "marche arrière", pour le moteur câblé sur le pont A. Selon sa table de vérité, il faut que :
    digitalWrite(borneIN1, LOW);  // L'entrée IN1 doit être au niveau bas
    digitalWrite(borneIN2, HIGH); // L'entrée IN2 doit être au niveau haut
}

void gauche()
{
    // Le fait d'utiliser analogWrite fait que l'on peut utiliser une puissance personalisé, ici on utilise 200/256 de puissance. 
    analogWrite(borneENB, 200);
    analogWrite(borneENA, 200);

    digitalWrite(PinGAUCHE_avant, LOW);
    digitalWrite(PinGAUCHE_recule, HIGH);
    digitalWrite(PinDROITE_avant, HIGH);
    digitalWrite(PinDROITE_recule, LOW);
}

void droite()
{
    // Le fait d'utiliser analogWrite fait que l'on peut utiliser une puissance personalisé, ici on utilise 200/256 de puissance. 
    analogWrite(borneENB, 200);
    analogWrite(borneENA, 200);

    digitalWrite(PinGAUCHE_avant, HIGH);
    digitalWrite(PinGAUCHE_recule, LOW);
    digitalWrite(PinDROITE_avant, LOW);
    digitalWrite(PinDROITE_recule, HIGH);
}

void stop_moteur()
{

    // Le fait d'utiliser analogWrite fait que l'on peut utiliser une puissance personalisé, mais ici un DigitalWrite aurait fonctionner puisque l'on applique 0.
    analogWrite(borneENB, 0);
    analogWrite(borneENA, 0);
}
