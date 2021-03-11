#include "vex.h"
using namespace vex;

void redAuto(){
  //deploy
  setIntake(INTAKE, 100);
  setLift(UP, 100);
  wait(100, msec);
  setLift(DOWN, 100);
  wait(100, msec);
  setLift(DOWN, 20);
  wait(100, msec);
  goP(FORWARD, 75, 23, 10, 0.1);
  //face goal one
  wait(200, msec);
  turnInertial(LEFT, 100, -132.5, -132.5, 4);
  wait(100, msec);
  //drive to goal one
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  goP(FORWARD, 87.5, 35, 20, 0.1);
  //score ball one
  wait(300, msec);
  setIntake(OUTTAKE, 100);
  wait(650, msec);
  setIntake(INTAKE, 100);
  //back out from goal one
  wait(300, msec);
  goP(BACKWARD, 85, 20, 16, 0.1);
  wait(100, msec);
  setLift(DOWN, 100);
  wait(100, msec);
  turnInertial(RIGHT, 100, -112.5, -120, 4);
  wait(100, msec);
  goP(BACKWARD, 100, 55, 35, 0.1);
  wait(100, msec);
  turnInertial(LEFT, 100, -180, -165, 4);
  wait(100, msec);
  goP(BACKWARD, 80, 16, 6, 0.1);
  wait(100, msec);
  turnInertial(LEFT, 100, -235, -200, 4);
  wait(100, msec);
  setLift(UP, 100);
  goP(FORWARD, 90, 85, 25, 0.1);
  wait(100, msec);
  setIntake(OUTTAKE, 100);
  wait(100, msec);
  goP(BACKWARD, 90, 25, 10, 0.1);

}




void purpleAuto(){
  //deploy
  setIntake(INTAKE, 100);
  setLift(UP, 100);
  wait(100, msec);
  setLift(DOWN, 100);
  wait(100, msec);
  setLift(DOWN, 20);
  wait(100, msec);
  goP(FORWARD, 75, 23, 10, 0.1);
  //face goal one
  wait(100, msec);
  turnInertial(LEFT, 100, -132.5, -132.5, 4);
  wait(100, msec);
  //drive to goal one
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  goP(FORWARD, 87.5, 35, 20, 0.1);
  //score ball one
  wait(100, msec);
  //back out from goal one
  wait(200, msec);
  goP(BACKWARD, 85, 20, 16, 0.1);
  wait(100, msec);
  setLift(DOWN, 100);
  wait(100, msec);
  turnInertial(RIGHT, 100, -112.5, -120, 4);
  wait(100, msec);
  goP(BACKWARD, 100, 58, 35, 0.1);
  wait(100, msec);
  turnInertial(LEFT, 100, -180, -165, 4);
  wait(100, msec);
  setLift(UP, 100);
  wait(300, msec);
  goP(FORWARD, 100, 32.7, 15, 4);
  wait(100, msec);
  setIntake(OUTTAKE, 100);
  wait(650, msec);
  setIntake(INTAKE, 100);
  wait(100, msec);
  goP(BACKWARD, 100, 49, 20, 4);
  wait(100, msec);
  turnInertial(LEFT, 100, -235, -200, 4);
  wait(100, msec);
  setLift(UP, 100);
  goP(FORWARD, 100, 85, 25, 0.1);
}














void blueAuto(){
  goP(FORWARD, 100, 20, 16, 1);
  turnInertial(LEFT, 90, -720, -710, 1);
  //goP(FORWARD, 100, 20, 16, 1);
  //turnInertial(LEFT, 100, -120, -100, 7);
  //goP(FORWARD, 100, 5, 4, 0.1);
  //turnInertial(RIGHT, 100, 30, 22, 7);
}


void skillsAuto(){
  //deploy
  setLift(DOWN, 25);
  setIntake(INTAKE, 100);
  //pick up ball one
  wait(100, msec);
  goP(FORWARD, 100, 23, 15, 0.1);
  //face goal one
  wait(200, msec);
  turnInertial(LEFT, 100, -132.5, -132.5, 4);
  wait(200, msec);
  //drive to goal one
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  goP(FORWARD, 100, 33, 26, 0.1);
  //score ball one
  wait(200, msec);
  setIntake(OUTTAKE, 100);
  wait(625, msec);
  setIntake(INTAKE, 100);
  //back out from goal one
  wait(300, msec);
  goP(BACKWARD, 100, 20, 12, 0.1);
  wait(100, msec);
  setLift(DOWN, 100);
  wait(100, msec);
  turnInertial(RIGHT, 100, -2, -2, 4);
  wait(100, msec);
  //pick up ball two
  setLift(DOWN, 15);
  wait(100, msec);
  goP(FORWARD, 100, 55.5, 39.5, 0.1);
  //aim at goal two
  wait(100, msec);
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  turnInertial(LEFT, 75, -90, -90, 4);
  //drive to goal two
  wait(100, msec);
  goP(FORWARD, 100, 12.5, 5.5, 0.1);
  //score ball two
  wait(200, msec);
  setIntake(OUTTAKE, 100);
  wait(1000, msec);
  //back out from goal two
  goP(BACKWARD, 100, 21, 17, 0.1);
  setLift(DOWN, 100);
  wait(100, msec);
  while (Lift.velocity(pct) < -10){
    wait(1, msec);
  }
  //face ball three
  turnInertial(RIGHT, 100, -1, -1, 4);
  setLift(DOWN, 15);
  setIntake(INTAKE, 100);
  wait(200, msec);
  goP(FORWARD, 100, 55, 30, 0.1);
  wait(200, msec);
  goP(BACKWARD, 100, 18, 15, 0.1);
  //face goal three
  wait(200, msec);
  turnInertial(LEFT, 100, -40, -40, 4);
  wait(200, msec);
  //drive to goal three
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  goP(FORWARD, 100, 38, 17, 0.1);
  wait(200, msec);
  //score ball three
  setIntake(OUTTAKE, 100);
  wait(1000, msec);
  //back out from goal three
  goP(BACKWARD, 80, 17, 14, 0.1);
  wait(100, msec);
  //pick up ball four
  turnInertial(RIGHT, 100, 111, 111, 4);
  setIntake(INTAKE, 100);
  wait(300, msec);
  setLift(DOWN, 100);
  wait(100, msec);
  while (Lift.velocity(pct) < -10){
    wait(1, msec);
  }
  setLift(DOWN, 15);
  wait(200, msec);
  goP(FORWARD, 100, 61, 55, 0.1);
  wait(200, msec);
  //face goal four
  turnInertial(LEFT, 35, -1, -1, 4);
  wait(100, msec);
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  //drive to goal four
  goP(FORWARD, 100, 34, 26, 0.5);
  wait(100, msec);
  //score ball four
  setIntake(OUTTAKE, 100);
  wait(500, msec);
  setIntake(INTAKE, 100);
  //back out from goal four
  wait(100, msec);
  goP(BACKWARD, 100, 22, 14, 0.1);
  wait(100, msec);
  //pick up ball five
  setLift(DOWN, 100);
  wait(100, msec);
  turnInertial(RIGHT, 50, 90, 80, 4);
  wait(100, msec);
  goP(FORWARD, 100, 60, 20, 0.1);
  wait(100, msec);
  goP(BACKWARD, 100, 21.4, 15, 0.1);
  wait(100, msec);
  turnInertial(LEFT, 35, 40, 45, 4);
  //drive to goal five
  wait(100, msec);
  setLift(UP, 100);
  wait(100, msec);
  goP(FORWARD, 47.5, 33.2, 10, 0.1);
  //score ball five
  wait(100, msec);
  setIntake(OUTTAKE, 100);
  wait(650, msec);
  setIntake(INTAKE, 100);
  //back out from goal five
  wait(100, msec);
  goP(BACKWARD, 47.5, 18, 12, 0.1);
  setLift(DOWN, 100);
  wait(100, msec);
  turnInertial(RIGHT, 50, 182.5, 180, 4);
  wait(100, msec);
  //pick up ball six
  setLift(DOWN, 15);
  wait(100, msec);
  goP(FORWARD, 62.5, 50, 35, 0.1);
  //aim at goal six
  wait(100, msec);
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  turnInertial(LEFT, 50, 90, 95, 4);
  //drive to goal six
  wait(100, msec);
  goTime(50, 50, 1500);
  //score ball six
  wait(100, msec);
  setIntake(OUTTAKE, 100);
  wait(750, msec);
  //face ball for center
  goP(BACKWARD, 75, 18.5, 5, 0.1);
  wait(100, msec);
  setLift(DOWN, 100);
  wait(300, msec);
  turnInertial(LEFT, 25, -90, 0, 4);
  setIntake(INTAKE, 100);
  wait(100, msec);
  goP(FORWARD, 75, 15, 7.5, 0.1);
  wait(100, msec);
  setLift(UP, 100);
  //descore center goal
  turnInertial(RIGHT, 100, -75, -75, 2.5);
  wait(100, msec);
  goP(FORWARD, 100, 34, 10, 0.1);
  wait(200, msec);
  goP(BACKWARD, 75, 10, 5, 0.1);
  wait(100, msec);
  turnInertial(LEFT, 100, -90, -85, 2.5);
  wait(100, msec);
  //score center goal
  goTime(100, 100, 1500);
  wait(100, msec);
  setIntake(OUTTAKE, 100);
}



void greenAuto(){
  //deploy
  setLift(DOWN, 25);
  setIntake(INTAKE, 100);
  //pick up ball one
  wait(100, msec);
  goP(FORWARD, 100, 23, 15, 0.1);
  //face goal one
  wait(200, msec);
  turnInertial(LEFT, 100, -132.5, -132.5, 4);
  wait(200, msec);
  //drive to goal one
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  goP(FORWARD, 100, 33, 26, 0.1);
  //score ball one
  wait(200, msec);
  setIntake(OUTTAKE, 100);
  wait(600, msec);
  setIntake(INTAKE, 100);
  //back out from goal one
  wait(300, msec);
  goP(BACKWARD, 100, 20, 12, 0.1);
  wait(100, msec);
  setLift(DOWN, 100);
  wait(100, msec);
  turnInertial(RIGHT, 100, -2, -2, 4);
  wait(100, msec);
  //pick up ball two
  setLift(DOWN, 15);
  wait(100, msec);
  goP(FORWARD, 100, 55.5, 39.5, 0.1);
  //aim at goal two
  wait(100, msec);
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  turnInertial(LEFT, 75, -90, -90, 4);
  //drive to goal two
  wait(100, msec);
  goP(FORWARD, 100, 12.5, 5.5, 0.1);
  //score ball two
  wait(200, msec);
  setIntake(OUTTAKE, 100);
  wait(1000, msec);
  //back out from goal two
  goP(BACKWARD, 100, 21, 17, 0.1);
  setLift(DOWN, 100);
  wait(100, msec);
  while (Lift.velocity(pct) < -10){
    wait(1, msec);
  }
  //face ball three
  turnInertial(RIGHT, 100, -1, -1, 4);
  setLift(DOWN, 15);
  setIntake(INTAKE, 100);
  wait(200, msec);
  goP(FORWARD, 100, 55, 30, 0.1);
  wait(200, msec);
  goP(BACKWARD, 100, 18, 15, 0.1);
  //face goal three
  wait(200, msec);
  turnInertial(LEFT, 100, -40, -40, 4);
  wait(200, msec);
  //drive to goal three
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  goP(FORWARD, 100, 38, 17, 0.1);
  wait(200, msec);
  //score ball three
  setIntake(OUTTAKE, 100);
  wait(1000, msec);
  //back out from goal three
  goP(BACKWARD, 80, 17, 14, 0.1);
  wait(100, msec);
  //pick up ball four
  turnInertial(RIGHT, 100, 111, 111, 4);
  setIntake(INTAKE, 100);
  wait(300, msec);
  setLift(DOWN, 100);
  wait(100, msec);
  while (Lift.velocity(pct) < -10){
    wait(1, msec);
  }
  setLift(DOWN, 15);
  wait(200, msec);
  goP(FORWARD, 100, 59, 50, 0.1);
  wait(200, msec);
  //face goal four
  turnInertial(LEFT, 75, -1, -1, 4);
  wait(100, msec);
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  //drive to goal four
  goP(FORWARD, 100, 34, 26, 1);
  wait(100, msec);
  //score ball four
  setIntake(OUTTAKE, 100);
  wait(500, msec);
  setIntake(INTAKE, 100);
  //back out from goal four
  wait(100, msec);
  goP(BACKWARD, 100, 22, 14, 1);
  wait(100, msec);
  //pick up ball five
  setLift(DOWN, 100);
  wait(100, msec);
  turnInertial(RIGHT, 75, 90, 80, 4);
  wait(100, msec);
  goP(FORWARD, 100, 60, 20, 0.1);
  wait(100, msec);
  goP(BACKWARD, 100, 21.4, 15, 0.1);
  wait(100, msec);
  turnInertial(LEFT, 75, 40, 45, 4);
  //drive to goal five
  wait(100, msec);
  setLift(UP, 100);
  wait(100, msec);
  goP(FORWARD, 75, 33.2, 10, 0.1);
  //score ball five
  wait(100, msec);
  setIntake(OUTTAKE, 100);
  wait(650, msec);
  setIntake(INTAKE, 100);
  //back out from goal five
  wait(100, msec);
  goP(BACKWARD, 75, 18, 12, 0.1);
  setLift(DOWN, 100);
  wait(100, msec);
  turnInertial(RIGHT, 50, 182.5, 180, 4);
  wait(100, msec);
  //pick up ball six
  setLift(DOWN, 15);
  wait(100, msec);
  goP(FORWARD, 80, 49, 35, 0.1);
  //aim at goal six
  wait(100, msec);
  setLift(UP, 100);
  wait(100, msec);
  while (Lift.velocity(pct) > 10){
    wait(1, msec);
  }
  liftBrake();
  wait(200, msec);
  turnInertial(LEFT, 75, 100, 100, 4);
  //drive to goal six
  wait(100, msec);
  goTime(50, 50, 750);
  //score ball six
  wait(100, msec);
  setIntake(OUTTAKE, 100);
  wait(600, msec);
  turnInertial(LEFT, 75, 90, 95, 6);
  //face ball for center
  wait(100, msec);
  goP(BACKWARD, 75, 18.5, 5, 0.1);
  wait(200, msec);
  setLift(DOWN, 100);
  wait(400, msec);
  turnInertial(LEFT, 80, -90, 0, 4);
  setIntake(INTAKE, 100);
  wait(100, msec);
  goP(FORWARD, 75, 15, 7.5, 0.1);
  wait(100, msec);
  setLift(UP, 100);
  //descore center goal
  turnInertial(RIGHT, 100, -80, -85, 2.5);
  wait(100, msec);
  goTime(100, 100, 800);
  wait(200, msec);
  goP(BACKWARD, 100, 12, 5, 0.1);
  wait(100, msec);
  turnInertial(LEFT, 100, -90, -85, 2.5);
  wait(100, msec);
  //score center goal
  goTime(100, 100, 1000);
  setIntake(OUTTAKE, 100);
  wait(550, msec);
  goP(BACKWARD, 80, 37.2, 20, 0.1);
  wait(100, msec);
  setLift(DOWN, 100);
  wait(100, msec);
  turnInertial(LEFT, 100, -180, -135, 2.5);
  setIntake(INTAKE, 100);
  wait(100, msec);
  goP(FORWARD, 80, 50, 28.8, 0.1);
  wait(50, msec);
  setLift(UP, 100);
  wait(50, msec);
  turnInertial(LEFT, 100, -235, -200, 2.5);
  wait(100, msec);
  goTime(100, 100, 1000);
  setIntake(OUTTAKE, 100);
}