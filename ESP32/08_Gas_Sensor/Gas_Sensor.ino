const int GAS_PIN = 34;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int gasValue = analogRead(GAS_PIN);

  Serial.println(gasValue);

  delay(500);
}
