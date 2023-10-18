#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;
unsigned long lastMillis = 0;
float gyroX = 0.0;
float gyroY = 0.0;
float gyroZ = 0.0;
float accelX = 0.0;
float accelY = 0.0;
float accelZ = 0.0;

void setup() {
  Serial.begin(115200);
  if (!mpu.begin()) {
    while (1) {
      delay(10);
    }
  }
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - lastMillis >= 10) { // Envoyer des données toutes les 10 ms
    lastMillis = currentMillis;

    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // Gyro data
    gyroX = g.gyro.x;
    gyroY = g.gyro.y;
    gyroZ = g.gyro.z;

    //Acceleration data
    accelX = a.acceleration.x;
    accelY = a.acceleration.y;
    accelZ = a.acceleration.z;

    // Print data
    Serial.print(gyroX);
    Serial.print(",");
    Serial.print(gyroY);
    Serial.print(",");
    Serial.print(gyroZ);
    Serial.print(",");
    Serial.print(accelX);
    Serial.print(",");
    Serial.print(accelY);
    Serial.print(",");
    Serial.println(accelZ);
  }
}
