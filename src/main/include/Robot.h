#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <units/time.h>
#include <frc/RobotController.h>

#include "Intake.h"
#include "Shooter.h"
#include "RobotMap.h"
#include "Drivebase.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  RobotMap robotMap;
  Intake *intake;
  Shooter *shooter;
  Drivebase *drivebase;
};

