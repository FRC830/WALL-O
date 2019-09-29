/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/smartdashboard/SendableChooser.h>
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>
#include <rev/SparkMax.h>

class Robot : public frc::TimedRobot {
public:
    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;
    // pins
    const int PIN_LF = 3;
    const int PIN_LB = 1;
    const int PIN_RB = 6;
    const int PIN_RF = 5;
    const int PIN_NEOBRUSHLESS = 2;
    // motors    
    WPI_TalonSRX LB{PIN_LB};
    WPI_TalonSRX RB{PIN_RB};
    WPI_VictorSPX LF{PIN_LF};
    WPI_VictorSPX RF{PIN_RF};
    frc::MecanumDrive drive {LF, LB, RF, RB};
    rev::SparkMax SPARKTEST{PIN_NEOBRUSHLESS};
    // controls
    frc::XboxController pilot{0};
    static const frc::GenericHID::JoystickHand LEFT = frc::GenericHID::kLeftHand;
    static const frc::GenericHID::JoystickHand RIGHT = frc::GenericHID::kRightHand; 
    // a cameraserver
    static constexpr double DEADZONE_THRESHOLD = 0.1;
 private:
  
};
