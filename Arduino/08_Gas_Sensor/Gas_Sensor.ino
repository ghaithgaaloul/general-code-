#define GAS_PIN A0
void setup(){ Serial.begin(9600); }
void loop(){ int gasValue=analogRead(GAS_PIN); Serial.println(gasValue); delay(500); }
// Raw MQ readings are not calibrated ppm.
