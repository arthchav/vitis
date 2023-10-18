import processing.serial.*;

Serial arduinoPort;
float angleX = 0.0;
float angleY = 0.0;
float angleZ = 0.0;

float g = 9.81;

float gyroThreshold = 0.1; // Seuil pour déterminer le mouvement

float gyroXOffset = 0.0;   // Valeur initiale du gyro X
float gyroYOffset = 0.0;   // Valeur initiale du gyro Y
float gyroZOffset = 0.0;   // Valeur initiale du gyro Z

void setup() {
  size(1000, 800, P3D);
  arduinoPort = new Serial(this, "COM7", 115200); 
  arduinoPort.clear(); 

}

void draw() {
  background (127, 221, 76);
  fill(0); // Color
  textSize(60); // Size
  text("Accelerometer and Gyrometer", 150, 100); // Position

  while (arduinoPort.available() > 0) {
    String data = arduinoPort.readStringUntil('\n');
    if (data != null) {
      data = data.trim();
      String[] values = split(data, ',');
      if (values.length == 6) {
        float gyroX = float(values[0]) - gyroXOffset;
        float gyroY = float(values[1]) - gyroYOffset;
        float gyroZ = float(values[2]) - gyroZOffset;
        float accelX = float(values[3]);
        float accelY = float(values[4]);
        float accelZ = float(values[5]);

        // Vérifier si les valeurs gyroscopiques sont supérieures au seuil
        if (abs(gyroX) > gyroThreshold || abs(gyroY) > gyroThreshold || abs(gyroZ) > gyroThreshold) {
          // Ajustez la vitesse de rotation pour un mouvement plus rapide
          angleX += gyroX * 0.01;
          angleY += gyroY * 0.01;
          angleZ += gyroZ * 0.01;
        }
       // Faire la moyenne entre le gyro et l'accéléromètre 
         angleX  = angleX/2 + asin(accelX / g);
         angleY  = angleY/2 + atan(accelY / accelZ);
       
       
       
      }
    }
  }

  translate(width / 2, height / 2, 0);
  rotateX(angleX); // Utiliser angleX pour la rotation autour de l'axe X
  rotateY(angleY); // Utiliser angleY pour la rotation autour de l'axe Y
  rotateZ(angleZ); // Utiliser angleZ pour la rotation autour de l'axe Z
  
  fill (200, 173, 127); // Définir une couleur marron clair pour la forme (couleur RVB)
  box(200);
  
  fill(0); // Couleur du texte (noir)
  textSize(45); // Taille du texte
  text("Vitis", -40, 10, 110); // Écrire "Vitis" sur la boîte
}
