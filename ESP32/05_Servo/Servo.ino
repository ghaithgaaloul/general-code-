#include <ESP32Servo.h>
#define SERVO_PIN 18
Servo myServo;
void setup(){ myServo.attach(SERVO_PIN); }
void loop(){ for(int a=0;a<=180;a++){myServo.write(a);delay(15);} for(int a=180;a>=0;a--){myServo.write(a);delay(15);} }
