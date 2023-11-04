#pragma once

#include <iostream>
#include <frc/XboxController.h>
#include <units/time.h>
#include <ctre/phoenix.h>
#include <frc/DutyCycleEncoder.h>
#include <frc2/command/PIDCommand.h>
#include <units/angular_velocity.h>
#include <units/voltage.h>
#include <units/angular_acceleration.h>

enum class ShooterStates {
  kIdle, 
  kSpinup,
  kShoot,
};

class Shooter {
 public: 
  Shooter(frc::XboxController &codriver, WPI_TalonSRX &shooterMotor, WPI_TalonSRX &shooterMotor1, frc::DutyCycleEncoder &shooterEncoder);

  void TeleopOnUpdate(units::second_t dt);
  void AutoOnUpdate(units::second_t dt);
  void TestOnUpdate(units::second_t dt);

 private: 
  frc::XboxController &_codriver;
  WPI_TalonSRX &_shooterMotor;
  WPI_TalonSRX &_shooterMotor1;
  frc::DutyCycleEncoder &_shooterEncoder;

  ShooterStates _state = ShooterStates::kIdle;

  frc2::PIDController pid{0.005, 0.01, 0.0005};

  units::degrees_per_second_t goal;
  units::degrees_per_second_t maxSpeed = 5_deg_per_s;
  double output = 0;
};

