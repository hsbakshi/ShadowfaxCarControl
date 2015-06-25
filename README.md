# ShadowfaxCarControl
Car control library for Arduino-based autonomous robots
  using Adafruit motor shield v2.

ShadowfaxCarControl library allows you to control your 4-wheel drive
  robot with a small piece of code.
  
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
