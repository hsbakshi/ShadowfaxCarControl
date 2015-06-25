#include "shadowfax_carcontrol.h"

namespace Shadowfax {

static const int MOTOR_TURN_90_DEGREE_TIME_MS = 900;
static const double MOTOR_SPEED_PER_SECOND = 0.22;

CarControl::CarControl() {
    CarControl(4, 3, 1, 2);
}

CarControl::CarControl(
        int motorLeftForward,
        int motorRightForward,
        int motorLeftBack,
        int motorRightBack) {
    afms = Adafruit_MotorShield();
    motorSpeedPerSecond = MOTOR_SPEED_PER_SECOND;
    motorTurnTimeMs = MOTOR_TURN_90_DEGREE_TIME_MS;
    motorLF = afms.getMotor(motorLeftForward);
    motorLB = afms.getMotor(motorLeftBack);
    motorRF = afms.getMotor(motorRightForward);
    motorRB = afms.getMotor(motorRightBack);
}

void CarControl::setMotorSpeedMetersPerSecond(double speed) {
 motorSpeedPerSecond = speed;
}

void CarControl::setMotorTurnTimeMs(int turnTime90degree) {
  motorTurnTimeMs = turnTime90degree;
}

void CarControl::begin() {
  afms.begin();  // create with the default frequency 1.6KHz

  // Motor speed range is 0 to 255
  motorLF->setSpeed(200);
  motorLB->setSpeed(200);
  motorRF->setSpeed(200);
  motorRB->setSpeed(200);
}

void CarControl::car_forward() const {
  motorRF->run(FORWARD);
  motorLF->run(FORWARD);
  motorRB->run(FORWARD);
  motorLB->run(FORWARD);
}

void CarControl::car_backward() const {
  motorRF->run(BACKWARD);
  motorLF->run(BACKWARD);
  motorRB->run(BACKWARD);
  motorLB->run(BACKWARD);
}

void CarControl::car_left() const {
  motorLF->run(BACKWARD);
  motorLB->run(BACKWARD);
  motorRF->run(FORWARD);
  motorRB->run(FORWARD);
}

void CarControl::car_right() const {
  motorLF->run(FORWARD);
  motorLB->run(FORWARD);
  motorRF->run(BACKWARD);
  motorRB->run(BACKWARD);
}

void CarControl::turnLeft() const {
    car_left();
    delay(motorTurnTimeMs);
}
void CarControl::turnRight() const {
    car_right();
    delay(motorTurnTimeMs);
}

void CarControl::turnLeftByDegrees(double angleInDegrees) const {
    car_left();
    delay(motorTurnTimeMs * angleInDegrees / 90.0);
}

void CarControl::turnRightByDegrees(double angleInDegrees) const {
    car_right();
    delay(motorTurnTimeMs * angleInDegrees / 90.0);
}

void CarControl::forwardDistance(double meters) const {
    car_forward();
    delay(1000.0 * meters / motorSpeedPerSecond);
}
void CarControl::backwardDistance(double meters) const {
    car_backward();
    delay(1000.0 * meters / motorSpeedPerSecond);
}
}
