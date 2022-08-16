#include <CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(0, 4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(0, INPUT);
  pinMode(4, OUTPUT);
}

int r;

void loop() {
  r = sensor.capacitiveSensor(30);
  Serial.println(r);
  delay(100);
}
