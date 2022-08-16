// Include the AccelStepper Library
#include <AccelStepper.h>

// Define step constant
#define FULLSTEP 4
#define READ_PIN 7

// Creates an instance
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
AccelStepper myStepper(FULLSTEP, 8, 10, 9, 11);

bool is_turn = 0;

void setup() {
  // set the maximum speed, acceleration factor,
  // initial speed and the target position
  myStepper.setMaxSpeed(1000.0);
  myStepper.setAcceleration(100.0);
  myStepper.setSpeed(200);
  myStepper.moveTo(2*2038);

  pinMode(READ_PIN, INPUT);
}

void loop() {
  is_turn = digitalRead(READ_PIN);
  if(is_turn)
  {
    // Change direction once the motor reaches target position
    if (myStepper.distanceToGo() == 0) 
      myStepper.moveTo(-myStepper.currentPosition());
  
    // Move the motor one step
    myStepper.run();
  }
}
