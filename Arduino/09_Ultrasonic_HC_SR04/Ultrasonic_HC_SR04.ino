#define TRIG_PIN 9
#define ECHO_PIN 10
void setup(){ Serial.begin(9600); pinMode(TRIG_PIN,OUTPUT); pinMode(ECHO_PIN,INPUT); }
void loop(){ digitalWrite(TRIG_PIN,LOW); delayMicroseconds(2); digitalWrite(TRIG_PIN,HIGH); delayMicroseconds(10); digitalWrite(TRIG_PIN,LOW); long d=pulseIn(ECHO_PIN,HIGH); float cm=d*0.0343/2; Serial.println(cm); delay(200); }
