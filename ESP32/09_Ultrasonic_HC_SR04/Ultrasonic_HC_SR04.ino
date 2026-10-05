#define TRIG_PIN 5
#define ECHO_PIN 18
void setup(){ Serial.begin(115200); pinMode(TRIG_PIN,OUTPUT); pinMode(ECHO_PIN,INPUT); }
void loop(){ digitalWrite(TRIG_PIN,LOW); delayMicroseconds(2); digitalWrite(TRIG_PIN,HIGH); delayMicroseconds(10); digitalWrite(TRIG_PIN,LOW); long d=pulseIn(ECHO_PIN,HIGH,30000); float cm=d*0.0343/2; Serial.println(cm); delay(200); }
// Protect ECHO if the HC-SR04 output is 5 V.
