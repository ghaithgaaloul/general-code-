// Beginner ESP32 adaptation of the Arduino exercise.
#define POT_PIN 34
#define LED_PIN 2
void setup(){ pinMode(LED_PIN,OUTPUT); Serial.begin(115200); }
void loop(){ int v=analogRead(POT_PIN); int b=map(v,0,4095,0,255); analogWrite(LED_PIN,b); Serial.println(b); delay(20); }
