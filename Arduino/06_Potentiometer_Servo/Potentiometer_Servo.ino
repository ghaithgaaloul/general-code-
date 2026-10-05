#include <Servo.h>
Servo myServo;
void setup(){ Serial.begin(9600); myServo.attach(9); }
void loop(){ int v=analogRead(A0); int angle=map(v,0,1023,0,180); myServo.write(angle); Serial.println(angle); delay(20); }
