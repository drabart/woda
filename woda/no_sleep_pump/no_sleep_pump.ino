#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define DEBUG

bool button_pressed = 0, blynk_pressed = 0;
char auth[] = "nv6H9BGPnzvbpj-v7B4S36mUgpNYKJM8";
const char *ssid = "UPC5671009";
const char *pass = "r5wxdspekybX";

BLYNK_CONNECTED() {
  Blynk.syncAll();
}

BLYNK_WRITE(V1)
{
  blynk_pressed = param.asInt();
#ifdef DEBUG
  Serial.print("Blynk is: ");
  Serial.println(blynk_pressed ? "on" : "off");
#endif
}

void setup() {
  pinMode(D2, INPUT);
  pinMode(D1, OUTPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(D1, HIGH);
  digitalWrite(D4, HIGH);
  
#ifdef DEBUG
  Serial.begin(115200);
  Serial.setTimeout(2000);

  while(!Serial) { }
#endif

  Blynk.begin(auth, ssid, pass);

  digitalWrite(D4, LOW);
  delay(200);
  digitalWrite(D4, HIGH);
  delay(200);
  digitalWrite(D4, LOW);
  delay(200);
  digitalWrite(D4, HIGH);
  delay(200);
  digitalWrite(D4, LOW);
  delay(200);
  digitalWrite(D4, HIGH);
}

void loop()
{
  Blynk.run();

  button_pressed = !digitalRead(D2);
  
  if(button_pressed || blynk_pressed)
  {
    
#ifdef DEBUG
  Serial.println("Started pumping");
#endif
    
    digitalWrite(D1, LOW);
    
    while(button_pressed || blynk_pressed)
    {
      delay(100);
      button_pressed = !digitalRead(D2);
      Blynk.run();
    }

    digitalWrite(D1, HIGH);

#ifdef DEBUG
  Serial.println("Finished pumping");
#endif
  }

  delay(100);
}
