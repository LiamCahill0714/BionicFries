#include "vex.h"
using namespace vex;

int intakeJoystick(){
  while(1){
    if (getController(BTNR1)){
      setIntake(OUTTAKE, 100);
    }
    else if (getController(BTNR2)){
      setIntake(INTAKE, 100);
    }
    else{
      //setIntake(INTAKE, 25);
      Intake.stop(hold);
    }
  }
  return 1;
}