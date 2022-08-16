#include "user_interface.h"

void setup() {
  Serial.begin(115200);
  Serial.println();

  
}

void loop() {
  extern os_timer_t *timer_list;
  timer_list = nullptr;
  uint32_t sleep_time_in_ms = 10000;
  wifi_set_opmode(NULL_MODE);
  delay(50);
  wifi_fpm_set_sleep_type(LIGHT_SLEEP_T);
  delay(50);
  wifi_fpm_open();
  Serial.println("hi1");
  delay(50);
  wifi_fpm_do_sleep(sleep_time_in_ms *1000 );
  
  delay(sleep_time_in_ms + 10);
  
  Serial.println("hi3");
  
}
