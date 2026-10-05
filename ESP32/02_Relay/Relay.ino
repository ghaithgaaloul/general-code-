#define RELAY_PIN 23
void setup(){ pinMode(RELAY_PIN, OUTPUT); }
void loop(){ digitalWrite(RELAY_PIN,HIGH); delay(2000); digitalWrite(RELAY_PIN,LOW); delay(2000); }
// Some relay modules are active LOW.
