#include "Drivebase.h"

Drivebase::Drivebase(frc::XboxController &driver, DrivebaseConfig &drivebaseConfig) : 
  _driver(driver), _drivebaseConfig(drivebaseConfig) {}

void Drivebase::TeleopOnUpdate(units::second_t dt) {
  if ((_driver.GetLeftY() > 0.05)) {
    leftSpeed = _driver.GetLeftY();
  } else if ((_driver.GetLeftY() < -0.05)) {
    leftSpeed = _driver.GetLeftY();
  } else {
    leftSpeed = 0;
  }

  if ((_driver.GetRightY() > 0.05)) {
    rightSpeed = _driver.GetRightY();
  } else if ((_driver.GetRightY() < -0.05)) {
    rightSpeed = _driver.GetRightY();
  } else {
    rightSpeed = 0;
  }

  leftSpeed *= maxSpeed;
  rightSpeed *= maxSpeed;

  _drivebaseConfig.leftMotor1->Set(leftSpeed); 
  _drivebaseConfig.leftMotor2->Set(leftSpeed); 
  _drivebaseConfig.leftMotor3->Set(leftSpeed);

  _drivebaseConfig.rightMotor1->Set(-rightSpeed);
  _drivebaseConfig.rightMotor2->Set(-rightSpeed);
  _drivebaseConfig.rightMotor3->Set(-rightSpeed);
}

void Drivebase::AutoOnUpdate(units::second_t dt) {

}

void Drivebase::TestOnUpdate(units::second_t dt) {

}