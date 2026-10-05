#include <Servo.h>
Servo myServo;
void setup(){ myServo.attach(9); }
void loop(){ for(int a=0;a<=180;a++){myServo.write(a);delay(15);} for(int a=180;a>=0;a--){myServo.write(a);delay(15);} }
