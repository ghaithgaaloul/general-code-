#include <WiFi.h>

const char* SSID = "ESP32_Receiver";
const char* PASSWORD = "12345678";

WiFiServer server(3333);

void setup() {
  Serial.begin(115200);

  // Create Wi-Fi network
  WiFi.softAP(SSID, PASSWORD);

  // Start server
  server.begin();

  Serial.println("WiFi started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Client connected");

    while (client.connected()) {

      if (client.available()) {

        String data = client.readStringUntil('\n');

        Serial.print("Received data: ");
        Serial.println(data);
      }
    }

    client.stop();
    Serial.println("Client disconnected");
  }
}
