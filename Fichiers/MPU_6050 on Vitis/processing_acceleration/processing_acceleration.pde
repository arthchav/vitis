import processing.serial.*;

Serial arduinoPort;
float anglesX = 0;
float anglesY = 0;
float g = 9.81; // Accélération due à la gravité en m/s^2

void setup() {
  size(1000, 800, P3D);
  arduinoPort = new Serial(this, "COM7", 115200); 
  arduinoPort.clear(); 

}

void draw() {
  background (127, 221, 76);
  fill(0); // Color
  textSize(60); // Size
  text("Accelerometer", 310, 100); // Position
  
  while (arduinoPort.available() > 0) {
    String data = arduinoPort.readStringUntil('\n');
    if (data != null) {
      data = data.trim();
      String[] values = split(data, ',');
      if (values.length == 6) {
        float accelX = float(values[3]);
        float accelY = float(values[4]);
        float accelZ = float(values[5]);
        
        anglesX = asin(accelX / g);
        anglesY = atan(accelY / accelZ);
      }
    }
  }
  
  translate(width / 2, height / 2, 0);
  rotateX(anglesX);
  rotateY(anglesY);
  box(100);
  
    fill (200, 173, 127); // Définir une couleur marron clair pour la forme (couleur RVB)
  box(200);
  
  fill(0); // Couleur du texte (noir)
  textSize(45); // Taille du texte
  text("Vitis", -40, 10, 110); // Écrire "Vitis" sur la boîte
}
