#include "vex.h"
using namespace vex;

int driveJoystick(){
  while (1){
    FLWheel.setStopping(coast);
    TLWheel.setStopping(coast);
    BLWheel.setStopping(coast);
    FRWheel.setStopping(coast);
    TRWheel.setStopping(coast);
    BRWheel.setStopping(coast);
    setDrive(getJoystick(LEFT_AXIS_Y), getJoystick(RIGHT_AXIS_Y));
    wait(10, msec);
  }
  return 1;
}
int driveJoystickArcade(){
  while (1){
    FLWheel.setStopping(hold);
    TLWheel.setStopping(hold);
    BLWheel.setStopping(hold);
    FRWheel.setStopping(hold);
    TRWheel.setStopping(hold);
    BRWheel.setStopping(hold);
    setDrive(((getJoystick(LEFT_AXIS_Y)) - (getJoystick(RIGHT_AXIS_X)*-1)), ((getJoystick(LEFT_AXIS_Y)) - (getJoystick(RIGHT_AXIS_X))));
    wait(10, msec);
  }
  return 1;
}