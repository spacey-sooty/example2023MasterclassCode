#pragma once 

#include <ctre/phoenix.h>
#include <frc/XboxController.h>
#include <frc/DutyCycleEncoder.h>

#include "Drivebase.h"

struct RobotMap {
  frc::XboxController driver{0};
  frc::XboxController codriver{1};

  struct Intake {
    WPI_VictorSPX intakeMotor{11};
  }; Intake intake;

  struct Shooter {
    WPI_TalonSRX shooterMotor{4};
    WPI_TalonSRX shooterMotor2{12};

    frc::DutyCycleEncoder shooterEncoder{1};
  }; Shooter shooter;

  struct Drivebase {
    WPI_TalonSRX leftMotor1{7};
    WPI_TalonSRX leftMotor2{3};
    WPI_TalonSRX leftMotor3{16};

    WPI_TalonSRX rightMotor1{5};
    WPI_TalonSRX rightMotor2{6};
    WPI_TalonSRX rightMotor3{1};
    DrivebaseConfig config {
      &leftMotor1, &leftMotor2, &leftMotor3,
      &rightMotor1, &rightMotor2, &rightMotor3
    };
  }; Drivebase drivebase;
};