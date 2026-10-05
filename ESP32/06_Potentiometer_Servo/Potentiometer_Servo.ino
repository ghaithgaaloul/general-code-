#include <ESP32Servo.h>

const int POT_PIN = 34;
const int SERVO_PIN = 18;

Servo myServo;

void setup() {
  Serial.begin(115200);
  myServo.attach(SERVO_PIN);
}

void loop() {
  int value = analogRead(POT_PIN);
  int angle = map(value, 0, 4095, 0, 180);

  myServo.write(angle);
  Serial.println(angle);

  delay(20);
}
