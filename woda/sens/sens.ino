#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG Serial
//#define BLYNK_LOG Serial
#define DEBUG
//#define ANALOG_PIN A0

WidgetBridge bridge1(V1);

int value = 0;
unsigned long bef = 0;
char auth[] = "nv6H9BGPnzvbpj-v7B4S36mUgpNYKJM8";
const char *ssid = "UPC5671009";
const char *pass = "r5wxdspekybX";

BlynkTimer timer;

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
  timer.setInterval(10L, Write);

  value = analogRead(ANALOG_PIN);
  #ifdef DEBUG
    Serial.println(value);
  #endif

  Blynk.run();
  //timer.run();

  Blynk.virtualWrite(V2, value);
  bridge1.virtualWrite(V2, value);

  Serial.print(Blynk.connected());
  
  delay(500);

  Serial.print(Blynk.connected());
  
  #ifdef DEBUG
    Serial.print("Ended in: ");
    Serial.print(millis() - bef);
    Serial.print("\n");
  #endif
  
  ESP.deepSleep(max((unsigned long)1000000, 10 * 1000000 - (millis() - bef) * 1000) );
  
}

void loop() 
{
  
}
