# ShadowfaxCarControl
*CarControl for Arduino based autonomous robots using Adafruit motor shield

ShadowfaxCarControl library allows you to control a 4-wheel drive robot
  using the Adafruit motor shield V2.
  
Along with this library, you also need the Adafruit_MotorShield library:
  https://github.com/adafruit/Adafruit_Motor_Shield_V2_Library
  
Here is a basic demo: https://www.youtube.com/watch?v=9s2WafxPRE0

Sample Arduino sketch:
```
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <shadowfax_carcontrol.h>

Shadowfax::CarControl carControl;

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
```
