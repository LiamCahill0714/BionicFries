#include "vex.h"
using namespace vex;

double liftSpeed = 100;
double liftStop = 1;

int liftJoystick(){
  while (1){
    if (getLift() < 150){
      liftSpeed = 75;
    }
    else{
      liftSpeed = 100;
    }
    if (LiftLimit.pressing()){
      liftStop = 0;
      liftReset();
    }
    else{
      liftStop = 1;
    }
    if (getController(BTNL1)){
      setLift(UP, 100);
    }
    else if (getController(BTNL2)){
      setLift(DOWN, liftSpeed*liftStop);
    }
    else{
      if (LiftLimit.pressing()){
        liftCoast();
      }
      else{
        liftBrake();
      }
    }
  }
  return 1;
}
