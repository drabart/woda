void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2000);

  while(!Serial) { }
  
  // Deep sleep mode until RESET pin is connected to a LOW signal (for example pushbutton or magnetic reed switch)
  //Serial.println("I'm awake, but I'm going into deep sleep mode until RESET pin is connected to a LOW signal");
  //ESP.deepSleep(0); 
}

void loop() 
{
  Serial.println("I'm awake, but I'm going into deep sleep mode for 30 seconds");
  ESP.deepSleep(30e6); 
}
