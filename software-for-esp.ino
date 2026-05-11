#include <ESP8266WiFi.h>

const char* ssid     = "YourSSID";
const char* password = "YourWiFiPassword";

WiFiServer telnetServer(23);
WiFiClient client;

void setup() {
  Serial.begin(115200, SERIAL_8N1, SERIAL_FULL, 1, true);
  Serial.swap();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(100);

  telnetServer.begin();

  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, LOW);  delay(200);
    digitalWrite(LED_BUILTIN, HIGH); delay(200);
  }
}

void loop() {
  if (!client || !client.connected())
    client = telnetServer.accept();

  if (client) {
    while (client.available()) Serial.write(client.read());
    while (Serial.available()) client.write(Serial.read());
  }
}
