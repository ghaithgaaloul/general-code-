#include <ESP32Servo.h>
#define POT_PIN 34
#define SERVO_PIN 18
Servo myServo;
void setup(){ Serial.begin(115200); myServo.attach(SERVO_PIN); }
void loop(){ int v=analogRead(POT_PIN); int angle=map(v,0,4095,0,180); myServo.write(angle); Serial.println(angle); delay(20); }
