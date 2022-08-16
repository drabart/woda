#include "user_interface.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "nv6H9BGPnzvbpj-v7B4S36mUgpNYKJM8";
const char *ssid = "UPC5671009";
const char *pass = "r5wxdspekybX";

/*
void fpm_wakup_cb_func(void) {
  Serial.println("Light sleep is over, either because timeout or external interrupt");
  Serial.flush();
}
*/

bool isUpOnServer;

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(2000);

  Blynk.begin(auth, ssid, pass);

  pinMode(D1, OUTPUT);
  pinMode(D4, OUTPUT);

  { // LIGHT SLEEP stuff
    // for timer-based light sleep to work, the os timers need to be disconnected
    extern os_timer_t *timer_list;
    timer_list = nullptr;
    
    // enable light sleep
    wifi_fpm_set_sleep_type(LIGHT_SLEEP_T);
    wifi_fpm_open();
    
    // wifi_fpm_set_wakeup_cb(fpm_wakup_cb_func);
    
    // optional: register one or more wake-up interrupts. the chip
    // will wake from whichever (timeout or interrupt) occurs earlier
    gpio_pin_wakeup_enable(D2, GPIO_PIN_INTR_LOLEVEL);
  }
  
}

void light_sleep()
{
  //Blynk.disconnect();
  //wifi_station_disconnect();
  
  delay(50);
  
  // sleep for 10 seconds
  long sleepTimeMilliSeconds = 10e3;
  // light sleep function requires microseconds
  wifi_fpm_do_sleep(sleepTimeMilliSeconds * 1000);
  
  // timed light sleep is only entered when the sleep command is
  // followed by a delay() that is at least 1ms longer than the sleep
  delay(sleepTimeMilliSeconds + 100);
}

BLYNK_WRITE(V1)
{
  isUpOnServer = param.asInt();
}

void loop()
{
  digitalWrite(D4, LOW);
  
  Serial.println("Going to sleep now");

  light_sleep();

  Serial.println("Woke up");

  digitalWrite(D4, HIGH);

  bool val;

  val = digitalRead(D2);

  if(val) // manual press
  {
    Serial.println("Is held");

    digitalWrite(D1, HIGH);
    while(!val);
    {
        delay(100);
        val = digitalRead(D2);
    }
    digitalWrite(D1, LOW);
    
    Serial.println("Finished holding");

  }
  else
  {
    Serial.println("Started connecting to Blynk");
    
    if (Blynk.connected())
    {  
      Blynk.run();  
    }
    else
    {
      Blynk.connect();
    }

    Blynk.syncVirtual(V1);

    Serial.println("Connected and synced");

    if(isUpOnServer)
    {

      digitalWrite(D1, HIGH);
    
      while(isUpOnServer)
      {
        delay(100);
        Blynk.run();
      }
      
      digitalWrite(D1, LOW);

    }

    Serial.println("Button off");
    
  }
  
}
