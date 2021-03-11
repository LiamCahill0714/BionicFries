using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FLWheel;
extern motor TLWheel;
extern motor BLWheel;
extern motor FRWheel;
extern motor TRWheel;
extern motor BRWheel;
extern motor Lift;
extern motor Intake;
extern bumper LiftLimit;
extern controller Controller1;
extern inertial InertialSensor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );