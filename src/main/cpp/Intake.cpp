#include "Intake.h"

Intake::Intake(frc::XboxController &codriver, WPI_VictorSPX &intakeMotor) : 
  _codriver(codriver), _intakeMotor(intakeMotor) {}

void Intake::TeleopOnUpdate(units::second_t dt) {
  switch (_state) {
    case IntakeStates::kIdle:
    {
      _speed = 0;

      if (_codriver.GetLeftY() > 0.05 || _codriver.GetLeftY() < -0.05) {
        _state = IntakeStates::kIntaking;
      } else if (_codriver.GetRightY() > 0.05 || _codriver.GetRightY() < -0.05) {
        _state = IntakeStates::kEject;
      }
    }
      break;
    case IntakeStates::kIntaking:
    {
      if (_codriver.GetLeftY() > 0.05 || _codriver.GetLeftY() < -0.05) {
        _speed = _codriver.GetLeftY();
      } else {
        _state = IntakeStates::kIdle;
      }
    }
      break;
    case IntakeStates::kHold:

      break;
    case IntakeStates::kHandover:

      break;
    case IntakeStates::kEject:
      {
        if (_codriver.GetRightY() > 0.05 || _codriver.GetRightY() < -0.05) {
          _speed = _codriver.GetRightY();
        } else {
          _state = IntakeStates::kIdle;
        }
      }
      break;
    default:
      std::cout << "Error intake teleop state out of bounds" << std::endl;
      break;
  }

  _intakeMotor.Set(_speed);
}

void Intake::AutoOnUpdate(units::second_t dt) {
}

void Intake::TestOnUpdate(units::second_t dt) {
}


