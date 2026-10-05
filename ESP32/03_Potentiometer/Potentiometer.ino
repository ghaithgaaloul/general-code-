const int POT_PIN = 34;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(POT_PIN);

  Serial.print("Potentiometer = ");
  Serial.println(value);

  delay(200);
}
