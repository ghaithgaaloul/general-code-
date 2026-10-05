#include <ESP32Servo.h>

const int TRIG_PIN = 5;
const int ECHO_PIN = 18;
const int SERVO_PIN = 19;

Servo myServo;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myServo.attach(SERVO_PIN);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distanceCm = duration * 0.0343 / 2;

  if (distanceCm > 0 && distanceCm < 20) {
    myServo.write(90);
  } else {
    myServo.write(0);
  }

  Serial.println(distanceCm);

  delay(100);
}
