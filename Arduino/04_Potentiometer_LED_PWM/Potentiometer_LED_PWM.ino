#define POT_PIN A0
#define LED_PIN 9
void setup(){ pinMode(LED_PIN,OUTPUT); Serial.begin(9600); }
void loop(){ int v=analogRead(POT_PIN); int b=map(v,0,1023,0,255); analogWrite(LED_PIN,b); Serial.println(b); delay(20); }
