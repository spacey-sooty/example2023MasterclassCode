#pragma once

#include <iostream>

#include <frc/XboxController.h>
#include <ctre/phoenix.h>
#include <units/time.h>

enum class IntakeStates {
  kIdle, 
  kIntaking,
  kHold,
  kHandover,
  kEject
};

class Intake {
 public: 
  Intake(frc::XboxController &codriver, WPI_VictorSPX &intakeMotor);

  void TeleopOnUpdate(units::second_t dt);
  void AutoOnUpdate(units::second_t dt);
  void TestOnUpdate(units::second_t dt);

 private: 
  frc::XboxController &_codriver;
  WPI_VictorSPX &_intakeMotor;

  IntakeStates _state = IntakeStates::kIdle;
  double _speed = 0;
};


