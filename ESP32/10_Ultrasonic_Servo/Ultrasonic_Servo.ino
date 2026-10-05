#include <ESP32Servo.h>
#define TRIG_PIN 5
#define ECHO_PIN 18
#define SERVO_PIN 19
Servo myServo;
void setup(){ Serial.begin(115200); pinMode(TRIG_PIN,OUTPUT); pinMode(ECHO_PIN,INPUT); myServo.attach(SERVO_PIN); }
void loop(){ digitalWrite(TRIG_PIN,LOW); delayMicroseconds(2); digitalWrite(TRIG_PIN,HIGH); delayMicroseconds(10); digitalWrite(TRIG_PIN,LOW); long d=pulseIn(ECHO_PIN,HIGH,30000); float cm=d*0.0343/2; if(cm>0 && cm<20) myServo.write(90); else myServo.write(0); Serial.println(cm); delay(100); }
