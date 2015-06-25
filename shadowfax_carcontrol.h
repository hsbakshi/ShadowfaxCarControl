#ifndef SHADOWFAX_CARCONTROL_H
#define SHADOWFAX_CARCONTROL_H
/**
 * ShadowFax CarControl class allows you to control a 4 wheel drive robot
 *  using the Adafruit motor shield.
 * Along with this library, you also need the Adafruit_MotorShield library.
 *
 * This library assumes a default turning speed for the car and a default
 *  moving speed.
 * You may have to calibrate your car and override these parameters
 *  using the setMotorSpeedMetersPerSecond and setMotorTurnTimeMs functions.
 */
#include "Arduino.h"
#include <Adafruit_MotorShield.h>

namespace Shadowfax {

class CarControl {

public:
    CarControl(); // Assumes DFRobot Pirate 4wd setup. (4, 3, 1, 2)

    CarControl(int motorLeftForward,
               int motorRightForward,
               int motorLeftBack,
               int motorRightBack); // Motor positions

    void setMotorSpeedMetersPerSecond(double speed);
    void setMotorTurnTimeMs(int turnTime90degree);
    
    void begin(); // call in setup()

    void turnLeft() const; // 90 degrees
    void turnRight() const; // 90 degrees

    void turnLeftByDegrees(double angleInDegrees) const;
    void turnRightByDegrees(double angleInDegrees) const;
    void forwardDistance(double meters) const;
    void backwardDistance(double meters) const;

private:
    double motorSpeedPerSecond;
    double motorTurnTimeMs;
    Adafruit_DCMotor* motorLF;
    Adafruit_DCMotor* motorRF;
    Adafruit_DCMotor* motorLB;
    Adafruit_DCMotor* motorRB;
    Adafruit_MotorShield afms;

    void car_left() const;
    void car_right() const;
    void car_forward() const;
    void car_backward() const;

};
}
#endif

