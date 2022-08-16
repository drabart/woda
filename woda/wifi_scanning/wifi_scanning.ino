#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop()
{
  Serial.print("Scan start ... ");
  int n = WiFi.scanNetworks();
  Serial.print(n);
  Serial.println(" network(s) found");
  for (int i = 0; i < n; i++)
  {
    Serial.printf("SSID: %s, STRENGTH: %ddBm\n", WiFi.SSID(i), WiFi.RSSI(i));
  }
  Serial.println();

  delay(5000);
}
