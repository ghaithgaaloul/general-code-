const int POT_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(POT_PIN);

  Serial.print("Potentiometer = ");
  Serial.println(value);

  delay(200);
}
