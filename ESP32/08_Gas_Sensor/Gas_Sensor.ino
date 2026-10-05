#define GAS_PIN 34
void setup(){ Serial.begin(115200); }
void loop(){ int gasValue=analogRead(GAS_PIN); Serial.println(gasValue); delay(500); }
// Verify the sensor output voltage before connecting it to the ESP32 ADC.
// Raw MQ readings are not calibrated ppm.
