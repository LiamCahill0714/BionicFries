#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FLWheel              motor         13              
// TLWheel              motor         8               
// BLWheel              motor         20              
// FRWheel              motor         19              
// TRWheel              motor         6               
// BRWheel              motor         17              
// Lift                 motor         1               
// Intake               motor         5               
// LiftLimit            bumper        A               
// Controller1          controller                    
// InertialSensor       inertial      3               
// ---- END VEXCODE CONFIGURED DEVICES ----
using namespace vex;

competition Competition;

void pre_auton(void) {
  vexcodeInit();
  Brain.Screen.drawRectangle(1, 1, 10000, 10000, blue);
  wait(2000, msec);
  Brain.Screen.drawRectangle(1, 1, 10000, 10000, purple);
  Controller1.rumble(".");
}

void autonomous(void) {
  //purpleAuto();
  //redAuto();
  //blueAuto();
  //skillsAuto();
  greenAuto();
}

void usercontrol(void) {
  vex::task driveControlTask(driveJoystick);
  vex::task liftControlTask(liftJoystick);
  vex::task intakeControlTask(intakeJoystick);
}

int main() {
  //Competition.disabled(pre_auton);
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    printf("\nGYRO: %f", getInertialYaw());
    wait(100, msec);
  }
}