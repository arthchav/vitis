// Variables utiles dans la suite du code

long duree;   // durée de l'echo ultrason   
int distance; // variable qui stock la distance ultrason 

int V_avant=20; // Valeur à partir de laquelle le robot avance 
int V_arriere=19; //Valeur à partir de laquelle le robot recul 

// On commence par nommé chaque borne pour un code lisible :

#define borneENA 10 // On associe la borne "ENA" du L298N à la pin D10 de l'arduino
#define borneENB 5  // On associe la borne "ENB" du L298N à la pin D5 de l'arduino

#define PinDROITE_avant 7  // fait avancer le côté droit (borne IN3 du pont en H)
#define PinDROITE_recule 6 // fait reculer le côté droit (borne IN4 du pont en H)
#define PinGAUCHE_avant 9  // fait avancer le côté gauche (borne IN1 du pont en H)
#define PinGAUCHE_recule 8 // fait reculer le côté gauche (borne IN2 du pont en H)

#define echoPin        12       // Echo    (réception ultrason)
#define trigPin        11       // Trigger (emission ultrason)

#define PinCapteurIR1   52       // OUT du capteur IR 1 (Gauche)
#define PinCapteurIR2   53       // OUT du capteur IR 2 (Droite)



void setup() {

pinMode(trigPin, OUTPUT); // Configuration du port du Trigger comme une SORTIE
pinMode(echoPin, INPUT);  // Configuration du port de l'Echo  comme une ENTREE

// Configuration de toutes les pins de l'Arduino en "sortie" (car elles attaquent les entrées du module L298N)
  pinMode(borneENA, OUTPUT);
  pinMode (PinGAUCHE_avant , OUTPUT);
  pinMode (PinGAUCHE_recule, OUTPUT);
  pinMode (PinDROITE_avant , OUTPUT);
  pinMode (PinDROITE_recule, OUTPUT);
  pinMode(borneENB, OUTPUT);

  pinMode(A1, INPUT); // Pour la vitesse avec le potentiometre 

  Serial.begin(9600); // Démarrage de la communication série

// IR :
  pinMode (PinCapteurIR1, INPUT);
  pinMode (PinCapteurIR2, INPUT);

}

void loop() {


  // Émission d'un signal de durée 10 microsecondes
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Écoute de l'écho 
  duree = pulseIn(echoPin, HIGH);

  // Calcul de la distance
  distance = duree*0.034/2;

// Reception des données des capteurs IR : 

int CapteurIR1 = digitalRead(PinCapteurIR1);
int CapteurIR2 = digitalRead(PinCapteurIR2);

// On regarde si il y a un obstacle à Gauche puis à Droite 

if (CapteurIR1 == 0) { // Obstacle à gauche donc tourne à droite
  droite();
  return;
}
if (CapteurIR2 == 0) { // Obstacle à droite donc tourne à gauche  
  gauche();
  return;
}

// Le robot avance constament sauf si il y a un obstacle devant

if (distance > V_avant){
  avant(); // On configurer les pins en mode "avant"
  lancerRotationMoteurPont(); // Puis on lance les moteurs ) la vitesse du potentiomètre 
}  
 else if (distance < V_arriere){
    arriere(); // On configurer les pins en mode "arrière"
    lancerRotationMoteurPont(); // Puis on lance les moteurs ) la vitesse du potentiomètre 
  }   
  
  else {
      stop_moteur(); // Lorque l'on est entre les distances de marche avant et arrière pour que le robot s'arrête devant l'obstacle 
}

 


}

void avant() {
    // Configuration du L298N en "marche avant", pour le moteur connecté au pont B. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN3, HIGH);                 // L'entrée IN3 doit être au niveau haut
  digitalWrite(borneIN4, LOW);                  // L'entrée IN4 doit être au niveau bas
  
   //Configuration du L298N en "marche avant", pour le moteur connecté au pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN1, HIGH);                 // L'entrée IN1 doit être au niveau haut
  digitalWrite(borneIN2, LOW);                  // L'entrée IN2 doit être au niveau bas

  
}

void arriere() {
  // Puis on configure le L298N en "marche arrière", pour le moteur câblé sur le pont B. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN3, LOW);                  // L'entrée IN3 doit être au niveau bas
  digitalWrite(borneIN4, HIGH);                 // L'entrée IN4 doit être au niveau haut

  // Puis on configure le L298N en "marche arrière", pour le moteur câblé sur le pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN1, LOW);                  // L'entrée IN1 doit être au niveau bas
  digitalWrite(borneIN2, HIGH);                 // L'entrée IN2 doit être au niveau haut

  
}

void gauche()
{

    digitalWrite(PinGAUCHE_avant, LOW);
    digitalWrite(PinGAUCHE_recule, HIGH);
    digitalWrite(PinDROITE_avant, HIGH);
    digitalWrite(PinDROITE_recule, LOW);
}

void droite()
{

    digitalWrite(PinGAUCHE_avant, HIGH);
    digitalWrite(PinGAUCHE_recule, LOW);
    digitalWrite(PinDROITE_avant, LOW);
    digitalWrite(PinDROITE_recule, HIGH);
}

void lancerRotationMoteurPont() {

    int vitesse = analogRead(A1);  // lit la valeur du potentiomètre

    vitesse = map(vitesse, 0, 1023, 0, 255); // Convertie linéairement la valeur entre 0 et 255


    analogWrite(borneENB, vitesse); // Lance les moteurs 
    analogWrite(borneENA, vitesse);     

}

void stop_moteur() {

  analogWrite(borneENB, 0); //Stop les moteurs 
  analogWrite(borneENA, 0);       

}
