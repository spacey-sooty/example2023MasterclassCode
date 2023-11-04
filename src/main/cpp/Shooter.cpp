#include "Shooter.h"

Shooter::Shooter(frc::XboxController &codriver, WPI_TalonSRX &shooterMotor, WPI_TalonSRX &shooterMotor1, frc::DutyCycleEncoder &shooterEncoder) :
  _codriver(codriver), _shooterMotor(shooterMotor), _shooterMotor1(shooterMotor1), _shooterEncoder(shooterEncoder) {}

void Shooter::TeleopOnUpdate(units::second_t dt) {

  
  switch (_state) {
  case ShooterStates::kIdle:
    {
      output = 0;

      if (_codriver.GetLeftTriggerAxis() > 0.05) {
        _state = ShooterStates::kSpinup;
      }
    }
    break;
  case ShooterStates::kSpinup:
    {
      if (_codriver.GetLeftTriggerAxis() > 0.05) {
        goal = _codriver.GetLeftTriggerAxis() * maxSpeed;
      } else {
        goal = 0_deg_per_s;
        _state = ShooterStates::kIdle;
      }
      auto speed = ((_shooterEncoder.GetDistance() * 360_deg) * dt);
      std::cout << "encoder distance: " << _shooterEncoder.GetDistance() << std::endl;
      output = pid.Calculate((double)speed, (double)goal);
    }
    break;
  case ShooterStates::kShoot:
    {

    }
    break;
  default:
    std::cout << "Shooter state error" << std::endl;
    break;
  }

  _shooterMotor.Set(output);
  _shooterMotor1.Set(-output);
}

void Shooter::AutoOnUpdate(units::second_t dt) {

}

void Shooter::TestOnUpdate(units::second_t dt) {

}