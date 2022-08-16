#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define DEBUG
//#define BLYNK_DEBUG

char auth[] = "M3rBu8l0qpH84HDZhQJX4UfloGh-Bu5n";
const char *ssid = "UPC5671009";
const char *pass = "r5wxdspekybX";

bool override_on = 0;
int value = 0;
int bp = -1;

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
}

BLYNK_WRITE(V1)
{
  if(!override_on)
  {
    if(value > 512 && param.asInt())
    {
      override_on = 1;
    }
    else
    {
      override_on = 0;
    }
  }
  else
  {
    if(param.asInt())
    {
      override_on = 1;
    }
    else
    {
      override_on = 0;
    }
  }
}

BLYNK_WRITE(V2)
{
  value = param.asInt();
  Serial.print(value);
}

void setup() {
  #ifdef DEBUG
    Serial.begin(115200);
    Serial.setTimeout(2000);

    while(!Serial) { }
  #endif

  Blynk.begin(auth, ssid, pass);

  pinMode(14, OUTPUT);
  digitalWrite(14, LOW);
}

void loop() {
  Blynk.run();
  if(override_on)
  {
    if(bp != 0)
    {
      digitalWrite(14, HIGH);
      Serial.print(0);
    }
     bp = 0;
  }
  else
  {
    if(value > 512)
    {
      if(bp != 1)
      {
        digitalWrite(14, LOW);
        Blynk.virtualWrite(V1, LOW);
        Serial.print(1);
      }
      bp = 1;
    }
    else
    {
      if(bp != 2)
      {
        digitalWrite(14, HIGH);
        Blynk.virtualWrite(V1, HIGH);
        Serial.print(2);
      }
      bp = 2;
    }
  }
}
