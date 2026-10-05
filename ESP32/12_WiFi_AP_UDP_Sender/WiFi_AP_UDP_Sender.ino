#include <WiFi.h>
#include <WiFiUdp.h>

const char* SSID = "ESP32_Data";
const char* PASSWORD = "12345678";

WiFiUDP udp;

const int PORT = 3333;

void setup() {
  Serial.begin(115200);

  WiFi.softAP(SSID, PASSWORD);

  udp.begin(PORT);

  Serial.println("WiFi started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  int data = 100;

  udp.beginPacket("192.168.4.255", PORT);
  udp.print(data);
  udp.endPacket();

  Serial.print("Sent: ");
  Serial.println(data);

  delay(1000);
}
