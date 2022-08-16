void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

}

void loop() {
  digitalWrite(D1, HIGH);
  digitalWrite(D3, LOW);
  delay(500);
  digitalWrite(D2, HIGH);
  digitalWrite(D1, LOW);
  delay(500);
  digitalWrite(D3, HIGH);
  digitalWrite(D2, LOW);
  delay(500);
}
