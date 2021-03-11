#include "vex.h"
using namespace vex;

void setIntake(int dir, double speed){
  Intake.spin(fwd, 0.12*speed*dir, volt);
}