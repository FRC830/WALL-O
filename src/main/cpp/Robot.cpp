/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/BuiltInWidgets.h>

using namespace frc;
void makeSlider(std::string name, double defaultV, double max=255) {
    wpi::StringMap<std::shared_ptr<nt::Value>> properties{
        std::make_pair("min", nt::Value::MakeDouble(0)),
        std::make_pair("max", nt::Value::MakeDouble(max))
    };
    Shuffleboard::GetTab("WALL-O")
    .Add(name, defaultV)
    .WithWidget(BuiltInWidgets::kNumberSlider)
    .WithProperties(properties);
}

void Robot::RobotInit() {
    makeSlider("lowerBoundH", 15, 179);
    makeSlider("lowerBoundS", 100);
    makeSlider("lowerBoundV", 130);
    makeSlider("upperBoundH", 60, 179);
    makeSlider("upperBoundS", 255);
    makeSlider("upperBoundV", 255);
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}


void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
    double rawX = fabs(pilot.GetX(LEFT)) < DEADZONE_THRESHOLD ? 0 : pilot.GetX(LEFT);
    double rawY = fabs(pilot.GetY(LEFT)) < DEADZONE_THRESHOLD ? 0 : pilot.GetY(LEFT);
    double turn = fabs(pilot.GetX(RIGHT)) < DEADZONE_THRESHOLD ? 0 : pilot.GetX(RIGHT);
    
    // double / int > DOUBLE
    
    double centerX = frc::SmartDashboard::GetNumber("centerX", 160);
    if (pilot.GetAButton()) {
        double distance = centerX - 160;
        double speed = (distance / 160) * .5;
        frc::SmartDashboard::PutNumber("Speed",speed);
        drive.DriveCartesian(speed, -rawY, turn);
    } else {
      	drive.DriveCartesian(rawX, -rawY, turn);
    }
}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
