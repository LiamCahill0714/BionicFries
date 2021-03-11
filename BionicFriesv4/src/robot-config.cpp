#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FLWheel = motor(PORT13, ratio6_1, true);
motor TLWheel = motor(PORT8, ratio6_1, true);
motor BLWheel = motor(PORT20, ratio6_1, true);
motor FRWheel = motor(PORT19, ratio6_1, false);
motor TRWheel = motor(PORT6, ratio6_1, false);
motor BRWheel = motor(PORT17, ratio6_1, false);
motor Lift = motor(PORT1, ratio18_1, false);
motor Intake = motor(PORT5, ratio18_1, false);
bumper LiftLimit = bumper(Brain.ThreeWirePort.A);
controller Controller1 = controller(primary);
inertial InertialSensor = inertial(PORT3);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}