#pragma once 

#include <frc/XboxController.h>
#include <ctre/Phoenix.h>
#include <units/time.h>

struct DrivebaseConfig {
  WPI_TalonSRX *leftMotor1;
  WPI_TalonSRX *leftMotor2;
  WPI_TalonSRX *leftMotor3;
  WPI_TalonSRX *rightMotor1;
  WPI_TalonSRX *rightMotor2;
  WPI_TalonSRX *rightMotor3;
};

class Drivebase {
 public: 
  Drivebase(frc::XboxController &driver, DrivebaseConfig &drivebaseConfig);
 
  void TeleopOnUpdate(units::second_t dt);
  void AutoOnUpdate(units::second_t dt);
  void TestOnUpdate(units::second_t dt);

 private: 
  frc::XboxController &_driver;
  DrivebaseConfig &_drivebaseConfig;

  double leftSpeed, rightSpeed;
  double maxSpeed = 0.6;
};