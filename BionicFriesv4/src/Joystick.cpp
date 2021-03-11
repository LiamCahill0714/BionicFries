#include "vex.h"
using namespace vex;

//get joystick values
double getJoystick(int axis){
  if (axis == 1){
    return Controller1.Axis1.value();
  }
  else if (axis == 2){
    return Controller1.Axis2.value();
  }
  else if (axis == 3){
    return Controller1.Axis3.value();
  }
  else if (axis == 4){
    return Controller1.Axis4.value();
  }
  else{
    return 0;
  }
}

//get button values
int getController(int buttonNumber){
  if (buttonNumber == 1){
    if (Controller1.ButtonR1.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 2){
    if (Controller1.ButtonR2.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 3){
    if (Controller1.ButtonL1.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 4){
    if (Controller1.ButtonL2.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 5){
    if (Controller1.ButtonA.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 6){
    if (Controller1.ButtonB.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 7){
    if (Controller1.ButtonY.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 8){
    if (Controller1.ButtonX.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 9){
    if (Controller1.ButtonUp.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 10){
    if (Controller1.ButtonDown.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 11){
    if (Controller1.ButtonLeft.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else if (buttonNumber == 12){
    if (Controller1.ButtonRight.pressing()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }

}