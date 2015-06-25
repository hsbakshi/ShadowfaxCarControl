#include <shadowfax_carcontrol.h>

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <shadowfax_carcontrol.h>

Shadowfax::CarControl carControl(4, 3, 1, 2);

void setup() {
  carControl.begin();
}//close setup


void loop() {
 // basic moves
  carControl.forwardDistance(0.2);
  carControl.turnLeftByDegrees(30.);
  carControl.turnRightByDegrees(30.);
  carControl.forwardDistance(0.2);
  carControl.backwardDistance(0.4);
}//close loop


