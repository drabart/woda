#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "nv6H9BGPnzvbpj-v7B4S36mUgpNYKJM8";
const char *ssid = "UPC5671009";
const char *pass = "r5wxdspekybX";

void setup() {
  Serial.begin(115200);
  pinMode(D1, OUTPUT);
  pinMode(D2, INPUT);
}

void loop() {
  Serial.println(digitalRead(D2));
  digitalWrite(D1, HIGH);
  delay(1000);
  digitalWrite(D1, LOW);
  delay(1100);
}
