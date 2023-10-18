



#define dir_g 32
#define pwm_g 2
#define dir_d 33
#define pwm_d 3
#define dir_b 12
#define pwm_b 5


int speed = 0;
int roll = 0.0;
int pitch = 0.0;
char direction = 'S';

void setup() {
  pinMode(dir_g, OUTPUT);
  pinMode(pwm_g, OUTPUT);
  pinMode(dir_d, OUTPUT);
  pinMode(pwm_d, OUTPUT);
  pinMode(dir_b, OUTPUT);
  pinMode(pwm_b, OUTPUT);

  // Configuration de la liaison Bluetooth
  Serial1.begin(9600);
  Serial.begin(9600);

  // Initialise les pins à l'état bas
  digitalWrite(dir_g, LOW);
  analogWrite(pwm_g, 0);
  digitalWrite(dir_d, LOW);
  analogWrite(pwm_d, 0);
  digitalWrite(dir_b, LOW);
  analogWrite(pwm_b, 0);
}

void loop() {


  if (Serial1.available()) {
    char c = Serial1.read();
    //Serial.print(c);

  
    

      if (c == 'V') {
      speed = Serial1.parseInt();
      Serial.print("new speed : "); 
      Serial.print(speed); 
      analogWrite(pwm_g, speed);
      analogWrite(pwm_d, speed);
      }

    else if (c == 'P') {
      pitch = Serial1.parseInt();
      Serial.print("new pitch : ");
      Serial.println(pitch);

    }

    else if (c == 'W') {
      roll = Serial1.parseInt();
      Serial.print("new roll : ");
      Serial.println(roll);

    }

    float absRoll = abs(roll);
  float absPitch = abs(pitch);

  if (absRoll > absPitch) {
    if (roll > 0) {
      direction = 'R'; // Droite
    } else if (roll < 0) {
      direction = 'L'; // Gauche
    }
  } else {
    if (pitch > 0) {
      direction = 'U'; // Avancer
    } else if (pitch < 0) {
      direction = 'D'; // Reculer
    }
  }


if (direction == 'D') {
      digitalWrite(dir_g, HIGH);
      digitalWrite(dir_d, HIGH);
      analogWrite(pwm_g, speed);
      analogWrite(pwm_d, speed);

    } else if (direction  == 'U') {
      digitalWrite(dir_g, LOW);
      digitalWrite(dir_d, LOW);
      analogWrite(pwm_g, speed);
      analogWrite(pwm_d, speed);

    } else if (direction  == 'R') {
      digitalWrite(dir_g, LOW);
      digitalWrite(dir_d, HIGH);
      analogWrite(pwm_g, speed);
      analogWrite(pwm_d, speed);

    } else if (direction  == 'L') {
      digitalWrite(dir_g, HIGH);
      digitalWrite(dir_d, LOW);
      analogWrite(pwm_g, speed);
      analogWrite(pwm_d, speed);
    }
    

    else if (c == 'B') {
      digitalWrite(dir_b, LOW);
      analogWrite(pwm_b, 255);
      Serial.println("bas");
    } else if (c == 'H') {
      digitalWrite(dir_b, HIGH);
      analogWrite(pwm_b, 255);
      Serial.println("haut");
    

    
    
    }
    }
  }
  

