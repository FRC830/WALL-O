/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
//   Talon L1{PWM_L1};
// 	Talon L2{PWM_L2};
// 	Talon L3{PWM_L3};
// 	Talon R1{PWM_R1};
// 	Talon R2{PWM_R2};
// 	Talon R3{PWM_R3};
// 	SpeedControllerGroup Left{L1, L2, L3};
// 	SpeedControllerGroup Right{R1, R2, R3};
// 	DifferentialDrive drive {Left, Right};
}

void Robot::RobotPeriodic() {
}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
