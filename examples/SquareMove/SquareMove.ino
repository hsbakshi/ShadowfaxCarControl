#include <shadowfax_carcontrol.h>

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <shadowfax_carcontrol.h>

Shadowfax::CarControl carControl(4, 3, 1, 2);

void setup() {
  carControl.begin();
}//close setup


void loop() {
  // move in a square
  carControl.forwardDistance(0.2);
  carControl.turnLeft();
  
  carControl.forwardDistance(0.2);
  carControl.turnLeft();
  
  carControl.forwardDistance(0.2);
  carControl.turnLeft();
  
  carControl.forwardDistance(0.2);
  carControl.turnLeft();
}//close loop


