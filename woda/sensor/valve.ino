#define DEBUG Debug

#define Ana_Pin A0

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "nv6H9BGPnzvbpj-v7B4S36mUgpNYKJM8";
char ssid[] = "UPC5671009";
char pass[] = "r5wxdspekybX";

int value = 0;

void setup()
{
  #ifdef DEBUG
    Serial.begin(115200);
  #endif

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  value = analogRead(Ana_Pin);
  Serial.print(value);
  Blynk.run();
  Blynk.virtualWrite(V1, value);
  delay(1000);
}
