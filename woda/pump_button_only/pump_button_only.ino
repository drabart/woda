// #define DEBUG

bool button_pressed = 0;

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
  button_pressed = !digitalRead(D2);
  
  if(button_pressed)
  {
    
#ifdef DEBUG
  Serial.println("Started pumping");
#endif
    
    digitalWrite(D1, LOW);
    
    while(button_pressed)
    {
      delay(100);
      button_pressed = !digitalRead(D2);
    }

    digitalWrite(D1, HIGH);

#ifdef DEBUG
  Serial.println("Finished pumping");
#endif
  }

  delay(100);
}
