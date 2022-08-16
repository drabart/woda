void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2000);

  pinMode(D1, OUTPUT);
  pinMode(D4, OUTPUT);
  // 3v d2 rozłączone
}

void loop() {
  digitalWrite(D1, LOW);
  digitalWrite(D4, LOW);
  delay(5000);
  digitalWrite(D1, HIGH);
  digitalWrite(D4, HIGH);
  delay(5000);
}
