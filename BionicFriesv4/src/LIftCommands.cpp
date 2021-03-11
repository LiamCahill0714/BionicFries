#include "vex.h"
using namespace vex;

//Lift encoder functions
double getLift(){
  return Lift.rotation(deg);
}
void liftReset(){
  Lift.resetRotation();
}

//get lift heat
double getHeatLift(){
  return Lift.temperature(pct);
}

//set lift
void setLift(int dir, double speed){
  Lift.spin(fwd, 0.12*speed*dir, volt);
}

//stop lift
void liftBrake(){
  Lift.stop(hold);
}
void liftCoast(){
  Lift.stop(coast);
}