const int GAS_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(GAS_PIN);

  Serial.println(gasValue);

  delay(500);
}
