#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

static units::second_t lastPeriodic;

void Robot::RobotInit() {
  lastPeriodic = static_cast<double>(frc::RobotController::GetFPGATime()) / 1000000 * 1_s;

  intake = new Intake(robotMap.codriver, robotMap.intake.intakeMotor);
  robotMap.intake.intakeMotor.SetInverted(true);

  shooter = new Shooter(robotMap.codriver, robotMap.shooter.shooterMotor, robotMap.shooter.shooterMotor2, robotMap.shooter.shooterEncoder);

  drivebase = new Drivebase(robotMap.driver, robotMap.drivebase.config);
}
void Robot::RobotPeriodic() {
  auto dt = static_cast<double>(frc::RobotController::GetFPGATime()) / 1000000 * 1_s - lastPeriodic;
  lastPeriodic = static_cast<double>(frc::RobotController::GetFPGATime()) / 1000000 * 1_s;

  std::cout << "ENCODER: " << robotMap.shooter.shooterEncoder.GetDistance() << std::endl;
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {
  auto dt = static_cast<double>(frc::RobotController::GetFPGATime()) / 1000000 * 1_s - lastPeriodic;

  intake->AutoOnUpdate(dt);
  shooter->AutoOnUpdate(dt);
  drivebase->AutoOnUpdate(dt);
}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  auto dt = static_cast<double>(frc::RobotController::GetFPGATime()) / 1000000 * 1_s - lastPeriodic;

  intake->TeleopOnUpdate(dt);
  shooter->TeleopOnUpdate(dt);
  drivebase->TeleopOnUpdate(dt);
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {
  auto dt = static_cast<double>(frc::RobotController::GetFPGATime()) / 1000000 * 1_s - lastPeriodic;

  intake->TestOnUpdate(dt);
  shooter->TestOnUpdate(dt);
  drivebase->TestOnUpdate(dt);
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
