#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define DEBUG

#define IN D1

WidgetBridge bridge1(V1);

int value = 0;
unsigned long bef = 0;
char auth[] = "nv6H9BGPnzvbpj-v7B4S36mUgpNYKJM8";
const char *ssid = "UPC5671009";
const char *pass = "r5wxdspekybX";

//BlynkTimer timer;

BLYNK_CONNECTED() {
  bridge1.setAuthToken("M3rBu8l0qpH84HDZhQJX4UfloGh-Bu5n");
}

void setup() {
  #ifdef DEBUG
    Serial.begin(115200);
    Serial.setTimeout(2000);
  
    while(!Serial) { }
  #endif

  Blynk.begin(auth, ssid, pass);
  //timer.setInterval(100L, Write);
  
  //ESP.deepSleep(max((unsigned long)1000000, 10 * 1000000 - (millis() - bef) * 1000) );
  
}

void loop() 
{
  Blynk.run();
  int v = digitalRead(IN);
  Serial.println(v);
  //timer.run();
  delay(500);
}
